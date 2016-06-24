// Copyright (C) 2016 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <dhcp/libdhcp++.h>
#include <dhcp/option.h>
#include <dhcp/option_definition.h>
#include <dhcp/option_space.h>
#include <dhcpsrv/cfg_option.h>
#include <dhcpsrv/dhcpsrv_log.h>
#include <dhcpsrv/pgsql_host_data_source.h>
#include <dhcpsrv/db_exceptions.h>
#include <util/buffer.h>
#include <util/optional_value.h>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/pointer_cast.hpp>
#include <boost/static_assert.hpp>

#include <stdint.h>
#include <string>

using namespace isc;
using namespace isc::asiolink;
using namespace isc::dhcp;
using namespace isc::util;
using namespace std;

namespace {

#if 0 // TKM
/// @brief Maximum size of an IPv6 address represented as a text string.
///
/// This is 32 hexadecimal characters written in 8 groups of four, plus seven
/// colon separators.
const size_t ADDRESS6_TEXT_MAX_LEN = 39;

/// @brief Maximum length of classes stored in a dhcp4/6_client_classes
/// columns.
const size_t CLIENT_CLASSES_MAX_LEN = 255;

/// @brief Maximum length of the hostname stored in DNS.
///
/// This length is restricted by the length of the domain-name carried
/// in the Client FQDN %Option (see RFC4702 and RFC4704).
const size_t HOSTNAME_MAX_LEN = 255;
#endif

/// @brief Maximum length of option value.
const size_t OPTION_VALUE_MAX_LEN = 4096;

#if 0
/// @brief Maximum length of option value specified in textual format.
const size_t OPTION_FORMATTED_VALUE_MAX_LEN = 8192;

/// @brief Maximum length of option space name.
const size_t OPTION_SPACE_MAX_LEN = 128;
#endif

/// @brief Numeric value representing last supported identifier.
///
/// This value is used to validate whether the identifier type stored in
/// a database is within bounds. of supported identifiers.
const uint8_t MAX_IDENTIFIER_TYPE = static_cast<uint8_t>(Host::IDENT_CIRCUIT_ID);

/// @brief Maximum length of DHCP identifier value.
const size_t DHCP_IDENTIFIER_MAX_LEN = 128;

/// @brief This class provides mechanisms for sending and retrieving
/// information from the 'hosts' table.
///
/// This class is used to insert and retrieve entries from the 'hosts' table.
/// The queries used with this class do not retrieve IPv6 reservations or
/// options associated with a host to minimize impact on performance. Other
/// classes derived from @ref PgSqlHostExchange should be used to retrieve
/// information about IPv6 reservations and options.
class PgSqlHostExchange : public PgSqlExchange {
private:

    /// @brief Column numbers for each column in the hosts table.
    /// These are used for both retrieving data and for looking up
    /// column labels for logging.  Note that their numeric order
    /// MUST match that of the column order in the hosts table.
    static const int HOST_ID_COL = 0;
    static const int DHCP_IDENTIFIER_COL = 1;
    static const int DHCP_IDENTIFIER_TYPE_COL = 2;
    static const int DHCP4_SUBNET_ID_COL = 3;
    static const int DHCP6_SUBNET_ID_COL = 4;
    static const int IPV4_ADDRESS_COL = 5;
    static const int HOSTNAME_COL = 6;
    static const int DHCP4_CLIENT_CLASSES_COL = 7;
    static const int DHCP6_CLIENT_CLASSES_COL = 8;
    /// @brief Number of columns returned for SELECT queries send by this class.
    static const size_t HOST_COLUMNS = 9;

public:

    /// @brief Constructor
    ///
    /// @param additional_columns_num This value is set by the derived classes
    /// to indicate how many additional columns will be returned by SELECT
    /// queries performed by the derived class. This constructor will allocate
    /// resources for these columns, e.g. binding table, error indicators.
    PgSqlHostExchange(const size_t additional_columns_num = 0)
        : PgSqlExchange(HOST_COLUMNS + additional_columns_num) {
        // Set the column names for use by this class. This only comprises
        // names used by the PgSqlHostExchange class. Derived classes will
        // need to set names for the columns they use.  Currenty these are
        // only used for logging purposes.
        columns_[HOST_ID_COL] = "host_id";
        columns_[DHCP_IDENTIFIER_COL] = "dhcp_identifier";
        columns_[DHCP_IDENTIFIER_TYPE_COL] = "dhcp_identifier_type";
        columns_[DHCP4_SUBNET_ID_COL] = "dhcp4_subnet_id";
        columns_[DHCP6_SUBNET_ID_COL] = "dhcp6_subnet_id";
        columns_[IPV4_ADDRESS_COL] = "ipv4_address";
        columns_[HOSTNAME_COL] = "hostname";
        columns_[DHCP4_CLIENT_CLASSES_COL] = "dhcp4_client_classes";
        columns_[DHCP6_CLIENT_CLASSES_COL] = "dhcp6_client_classes";

        BOOST_STATIC_ASSERT(8 < HOST_COLUMNS);
    };

    /// @brief Virtual destructor.
    virtual ~PgSqlHostExchange() {
    }

    /// @brief Reinitializes state information
    /// 
    /// This function should be called in between statement executions.
    /// Deriving classes should be to sure to reinitialize any stateful
    /// values that control statement result processing.
    virtual void clear() {
        host_.reset();
    };

    /// @brief Returns index of the first uninitialized column name.
    ///
    /// This method is called by the derived classes to determine which
    /// column indexes are available for the derived classes within a
    /// binding array, error array and column names. This method
    /// determines the first available index by searching the first
    /// empty value within the columns_ vector. Previously we relied on
    /// the fixed values set for each class, but this was hard to maintain
    /// when new columns were added to the SELECT queries. It required
    /// modifying indexes in all derived classes.
    ///
    /// Derived classes must call this method in their constructors and
    /// use returned value as an index for the first column used by the
    /// derived class and increment this value for each subsequent column.
    size_t findAvailColumn() const {
        std::vector<std::string>::const_iterator empty_column =
            std::find(columns_.begin(), columns_.end(), std::string());
        return (std::distance(columns_.begin(), empty_column));
    }

    /// @brief Returns value of host id in the given row.
    ///
    /// This method is used to "look ahead" at the host_id in a row
    /// without having to call retrieveHost() 
    HostID getHostId(const PgSqlResult& r, int row) { 
        HostID host_id;
        getColumnValue(r, row, HOST_ID_COL, host_id);
        return (host_id);
    }

    /// @brief Populate a bind array from a host
    ///
    /// Constructs a PsqlBindArray for sending data stored in a Host object
    /// to the database.
    ///
    /// @param host Host object to be added to the database.
    ///        None of the fields in the host reservation are modified -
    ///        the host data is only read.
    ///
    /// @return pointer to newly constructed bind_array containing the
    /// bound values extracted from host
    ///
    /// @throw DbOperationError if bind_array cannot be populated.
    PsqlBindArrayPtr
    createBindForSend(const HostPtr& host) {
        if (!host) {
            isc_throw(BadValue, "createBindForSend:: host object is NULL");
        }

        // Store the host to ensure bound values remain in scope
        host_ = host;

        // Bind the host data to the array
        PsqlBindArrayPtr bind_array(new PsqlBindArray());
        try {
            // host_id : is auto_incremented skip it

            // dhcp_identifier : BYTEA NOT NULL
            bind_array->add(host->getIdentifier());

            // dhcp_identifier_type : SMALLINT NOT NULL
            bind_array->add(host->getIdentifierType());

            // dhcp4_subnet_id : INT NULL
            bind_array->add(host->getIPv4SubnetID());

            // dhcp6_subnet_id : INT NULL
            bind_array->add(host->getIPv6SubnetID());

            // ipv4_address : BIGINT NULL
            bind_array->add(host->getIPv4Reservation());

            // hostname : VARCHAR(255) NULL
            bind_array->bindString(host->getHostname());

            // dhcp4_client_classes : VARCHAR(255) NULL
            // Override default separator to not include space after comma.
            bind_array->bindString(host->getClientClasses4().toText(","));

            // dhcp6_client_classes : VARCHAR(255) NULL
            bind_array->bindString(host->getClientClasses6().toText(","));
        } catch (const std::exception& ex) {
            host_.reset();
            isc_throw(DbOperationError,
                      "Could not create bind array from Host: "
                      << host->getHostname() << ", reason: " << ex.what());
        }

        return (bind_array);
    };

    /// @brief Processes one row of data fetched from a database.
    ///
    /// The processed data must contain host id, which uniquely identifies a
    /// host. This method creates a host and inserts it to the hosts collection
    /// only if the last inserted host has a different host id. This prevents
    /// adding duplicated hosts to the collection, assuming that processed
    /// rows are primarily ordered by host id column.
    ///
    /// This method must be overriden in the derived classes to also
    /// retrieve IPv6 reservations and DHCP options associated with a host.
    ///
    /// @param [out] hosts Collection of hosts to which a new host created
    ///        from the processed data should be inserted.
    virtual void processRowData(ConstHostCollection& hosts, 
                                    const PgSqlResult& r, int row) {
        // Peek at the host id , so we can skip it if we already have it
        // This lets us avoid constructing a copy of host for each
        // of its sub-rows (options, etc...)
        HostID host_id;
        getColumnValue(r, row, HOST_ID_COL, host_id);

        // Add new host only if there are no hosts or the host id of the
        // most recently added host is different than the host id of the
        // currently processed host.
        if (hosts.empty() || host_id != hosts.back()->getHostId()) {
            HostPtr host = retrieveHost(r, row);
            hosts.push_back(host);
        }
    }

    /// @brief Creates a Host object from a given row in a result set.
    ///
    /// @param r result set containing one or rows from the hosts table
    /// @param row row number within the result set from to create the Lease4
    /// object.
    /// @param peeked_host_id if the caller has peeked ahead at the row's
    /// host_id, it can be passed in here to avoid fetching from the row
    /// a second time.
    ///
    /// @return HostPtr to the newly created Host object
    /// @throw DbOperationError if the host cannot be created.
    HostPtr retrieveHost(const PgSqlResult& r, int row, 
        const HostID& peeked_host_id = 0) {
       
        // If the caller peeked ahead at the host_id use that, otherwise
        // read it from the row. 
        HostID host_id = peeked_host_id;
        if (peeked_host_id) {
            host_id = peeked_host_id;
        }
        else {
            getColumnValue(r, row, HOST_ID_COL, host_id);
        }

        // dhcp_identifier : BYTEA NOT NULL
        uint8_t identifier_value[DHCP_IDENTIFIER_MAX_LEN];
        size_t identifier_len;
        convertFromBytea(r, row, DHCP_IDENTIFIER_COL, identifier_value,
                             sizeof(identifier_value), identifier_len);

        // dhcp_identifier_type : SMALLINT NOT NULL
        uint8_t type;
        getColumnValue(r, row, DHCP_IDENTIFIER_TYPE_COL, type);
        if (type > MAX_IDENTIFIER_TYPE) {
            isc_throw(BadValue, "invalid dhcp identifier type returned: "
                      << static_cast<int>(type));
        }

        Host::IdentifierType identifier_type =
            static_cast<Host::IdentifierType>(type);

        // dhcp4_subnet_id : INT NULL
        uint32_t subnet_id;
        getColumnValue(r, row, DHCP4_SUBNET_ID_COL, subnet_id);
        SubnetID dhcp4_subnet_id = static_cast<SubnetID>(subnet_id);

        // dhcp6_subnet_id : INT NULL
        getColumnValue(r, row, DHCP6_SUBNET_ID_COL, subnet_id);
        SubnetID dhcp6_subnet_id = static_cast<SubnetID>(subnet_id);

        // ipv4_address : BIGINT NULL
        uint32_t addr4;
        getColumnValue(r, row, IPV4_ADDRESS_COL, addr4);
        isc::asiolink::IOAddress ipv4_reservation(addr4);

        // hostname : VARCHAR(255) NULL
        std::string hostname;
        getColumnValue(r, row, HOSTNAME_COL, hostname);

        // dhcp4_client_classes : VARCHAR(255) NULL
        std::string dhcp4_client_classes;
        getColumnValue(r, row, DHCP4_CLIENT_CLASSES_COL, dhcp4_client_classes);

        // dhcp6_client_classes : VARCHAR(255) NULL
        std::string dhcp6_client_classes;
        getColumnValue(r, row, DHCP6_CLIENT_CLASSES_COL, dhcp6_client_classes);

        HostPtr host;
        try {
            host.reset(new Host(identifier_value, identifier_len,
                                identifier_type, dhcp4_subnet_id,
                                dhcp6_subnet_id, ipv4_reservation, hostname,
                                dhcp4_client_classes, dhcp6_client_classes));

            host->setHostId(host_id);
        } catch (const isc::Exception& ex) {
            isc_throw(DbOperationError, "Could not create host: " << ex.what());
        }

        return(host);
    };

protected:
    /// Pointer to Host object holding information to be inserted into
    /// Hosts table.  This is used to retain scope.
    HostPtr host_;
};


/// @brief Extends base exchange class with ability to retrieve DHCP options
/// from the 'dhcp4_options' and 'dhcp6_options' tables.
///
/// This class provides means to retrieve both DHCPv4 and DHCPv6 options
/// along with the host information. It is not used to retrieve IPv6
/// reservations. The following types of queries are supported:
/// - SELECT ? FROM hosts LEFT JOIN dhcp4_options LEFT JOIN dhcp6_options ...
/// - SELECT ? FROM hosts LEFT JOIN dhcp4_options ...
/// - SELECT ? FROM hosts LEFT JOIN dhcp6_options ...
class PgSqlHostWithOptionsExchange : public PgSqlHostExchange {
private:

    /// @brief Number of columns holding DHCPv4  or DHCPv6 option information.
    static const size_t OPTION_COLUMNS = 6;

    /// @brief Receives DHCPv4 or DHCPv6 options information from the
    /// dhcp4_options or dhcp6_options tables respectively.
    ///
    /// The PgSqlHostWithOptionsExchange class holds two respective instances
    /// of this class, one for receiving DHCPv4 options, one for receiving
    /// DHCPv6 options.
    ///
    /// The following are the basic functions of this class:
    /// - bind class members to specific columns in MySQL binding tables,
    /// - set DHCP options specific column names,
    /// - create instances of options retrieved from the database.
    ///
    /// The reason for isolating those functions in a separate C++ class is
    /// to prevent code duplication for handling DHCPv4 and DHCPv6 options.
    class OptionProcessor {
    public:

        /// @brief Constructor.
        ///
        /// @param universe V4 or V6. The type of the options' instances
        /// created by this class depends on this parameter.
        /// @param start_column Index of the first column to be used by this
        /// class.
        OptionProcessor(const Option::Universe& universe,
                        const size_t start_column)
        : universe_(universe), start_column_(start_column), 
          option_id_index_(start_column), code_index_(start_column_ + 1),
          value_index_(start_column_ + 2),
          formatted_value_index_(start_column_ + 3),
          space_index_(start_column_ + 4),
          persistent_index_(start_column_ + 5),
          most_recent_option_id_(0) {
        }

        /// @brief Reintializes state information
        ///
        /// This function should be called prior to processing a fetched
        /// set of options.
        void clear() {
            most_recent_option_id_ = 0;
        }

        /// @brief Creates instance of the currently processed option.
        ///
        /// This method detects if the currently processed option is a new
        /// instance. It makes it determination by comparing the identifier
        /// of the currently processed option, with the most recently processed
        /// option. If the current value is greater than the id of the recently
        /// processed option it is assumed that the processed row holds new
        /// option information. In such case the option instance is created and
        /// inserted into the configuration passed as argument.
        ///
        /// @param cfg Pointer to the configuration object into which new
        /// option instances should be inserted.
        void retrieveOption(const CfgOptionPtr& cfg, const PgSqlResult& r, 
                            int row) {
            if (PgSqlExchange::isColumnNull(r, row, option_id_index_)) {
                return;
            }

            // option_id: INT NOT NULL
            uint64_t option_id;
            PgSqlExchange::getColumnValue(r, row, option_id_index_, option_id);

            // option_id may be zero if dhcp4_options or dhcp6_options table
            // doesn't contain any options for the particular host. Also, the
            // current option id must be greater than id if the most recent
            // option because options are ordered by option id. Otherwise
            // we assume that this is already processed option.
            if (!option_id || (most_recent_option_id_ >= option_id)) {
                return;
            }

            // Remember current option id as the most recent processed one. We
            // will be comparing it with option ids in subsequent rows.
            most_recent_option_id_ = option_id;

            // code: SMALLINT NOT NULL
            uint16_t code;
            PgSqlExchange::getColumnValue(r, row, code_index_, code);

            // value: BYTEA NOT NULL
            uint8_t value[OPTION_VALUE_MAX_LEN];
            size_t value_len;
            PgSqlExchange::convertFromBytea(r, row, value_index_, value, 
                                            sizeof(value), value_len);

            // formatted_value: TEXT
            // @todo Should we attempt to enforce max value of 8K?
            // If so, we should declare this VARCHAR[8K] in the table 
            std::string formatted_value;
            PgSqlExchange::getColumnValue(r, row, formatted_value_index_,
                                          formatted_value);

            // space: VARCHAR(128)
            std::string space;
            PgSqlExchange::getColumnValue(r, row, space_index_, space);

            // persistent: BOOL default false
            bool persistent;
            PgSqlExchange::getColumnValue(r, row, persistent_index_,
                                          persistent);

            // Options are held in a binary or textual format in the database.
            // This is similar to having an option specified in a server
            // configuration file. Such option is converted to appropriate C++
            // class, using option definition. Thus, we need to find the
            // option definition for this option code and option space.

            // If the option space is a standard DHCPv4 or DHCPv6 option space,
            // this is most likely a standard option, for which we have a
            // definition created within libdhcp++.
            OptionDefinitionPtr def;
            if ((space == DHCP4_OPTION_SPACE) ||
                (space == DHCP6_OPTION_SPACE)) {
                def = LibDHCP::getOptionDef(universe_, code);
            }

            // Otherwise, we may check if this an option encapsulated within the
            // vendor space.
            if (!def && (space != DHCP4_OPTION_SPACE) &&
                (space != DHCP6_OPTION_SPACE)) {
                uint32_t vendor_id = LibDHCP::optionSpaceToVendorId(space);
                if (vendor_id > 0) {
                    def = LibDHCP::getVendorOptionDef(universe_, vendor_id,
                                                      code);
                }
            }

            // In all other cases, we use runtime option definitions, which
            // should be also registered within the libdhcp++.
            if (!def) {
                def = LibDHCP::getRuntimeOptionDef(space, code);
            }

            OptionPtr option;

            if (!def) {
                // If no definition found, we use generic option type.
                OptionBuffer buf(value, value + value_len);
                option.reset(new Option(universe_, code, buf.begin(),
                                        buf.end()));
            } else {
                // The option value may be specified in textual or binary format
                // in the database. If formatted_value is empty, the binary
                // format is used. Depending on the format we use a different
                // variant of the optionFactory function.
                if (formatted_value.empty()) {
                    OptionBuffer buf(value, value + value_len);
                    option = def->optionFactory(universe_, code, buf.begin(),
                                                buf.end());
                } else {
                    // Spit the value specified in comma separated values
                    // format.
                    std::vector<std::string> split_vec;
                    boost::split(split_vec, formatted_value, 
                                 boost::is_any_of(","));
                    option = def->optionFactory(universe_, code, split_vec);
                }
            }

            OptionDescriptor desc(option, persistent, formatted_value);
            cfg->add(desc, space);
        }

        /// @brief Specify column names.
        ///
        /// @param [out] columns Reference to a vector holding names of option
        /// specific columns.
        void setColumnNames(std::vector<std::string>& columns) {
            columns[option_id_index_] = "option_id";
            columns[code_index_] = "code";
            columns[value_index_] = "value";
            columns[formatted_value_index_] = "formatted_value";
            columns[space_index_] = "space";
            columns[persistent_index_] = "persistent";
        }

    private:
        /// @brief Universe: V4 or V6.
        Option::Universe universe_;

        /// @brief Index of first column used by this class.
        size_t start_column_;

        //@}

        /// @name Indexes of the specific columns
        //@{
        /// @brief Option id
        size_t option_id_index_;

        /// @brief Code
        size_t code_index_;

        /// @brief Value
        size_t value_index_;

        /// @brief Formatted value
        size_t formatted_value_index_;

        /// @brief Space
        size_t space_index_;

        /// @brief Persistent
        size_t persistent_index_;
        //@}

        /// @brief Option id for last processed row.
        uint64_t most_recent_option_id_;
    };

    /// @brief Pointer to the @ref OptionProcessor class.
    typedef boost::shared_ptr<OptionProcessor> OptionProcessorPtr;

public:

    /// @brief DHCP option types to be fetched from the database.
    ///
    /// Supported types are:
    /// - Only DHCPv4 options,
    /// - Only DHCPv6 options,
    /// - Both DHCPv4 and DHCPv6 options.
    enum FetchedOptions {
        DHCP4_ONLY,
        DHCP6_ONLY,
        DHCP4_AND_DHCP6
    };

    /// @brief Constructor.
    ///
    /// @param fetched_options Specifies if DHCPv4, DHCPv6 or both should
    /// be fetched from the database for a host.
    /// @param additional_columns_num Number of additional columns for which
    /// resources should be allocated, e.g. binding table, column names etc.
    /// This parameter should be set to a non zero value by derived classes to
    /// allocate resources for the columns supported by derived classes.
    PgSqlHostWithOptionsExchange(const FetchedOptions& fetched_options,
                                 const size_t additional_columns_num = 0)
        : PgSqlHostExchange(getRequiredColumnsNum(fetched_options)
                            + additional_columns_num),
          opt_proc4_(), opt_proc6_() {

        // Create option processor for DHCPv4 options, if required.
        if ((fetched_options == DHCP4_ONLY) ||
            (fetched_options == DHCP4_AND_DHCP6)) {
            opt_proc4_.reset(new OptionProcessor(Option::V4,
                                                 findAvailColumn()));
            opt_proc4_->setColumnNames(columns_);
        }

        // Create option processor for DHCPv6 options, if required.
        if ((fetched_options == DHCP6_ONLY) ||
            (fetched_options == DHCP4_AND_DHCP6)) {
            opt_proc6_.reset(new OptionProcessor(Option::V6,
                                                 findAvailColumn()));
            opt_proc6_->setColumnNames(columns_);
        }
    }

    /// @brief Reinitializes state information
    /// 
    /// This function should be called in between statement executions.
    /// Deriving classes should be to sure to reinitialize any stateful
    /// values that control statement result processing.
    virtual void clear() {
        PgSqlHostExchange::clear();
        if (opt_proc4_) {
            opt_proc4_->clear();
        }

        if (opt_proc6_) {
            opt_proc6_->clear();
        }
    }

    /// @brief Processes the current row.
    ///
    /// The processed row includes both host information and DHCP option
    /// information. Because used SELECT query use LEFT JOIN clause, the
    /// some rows contain duplicated host or options entries. This method
    /// detects duplicated information and discards such entries.
    ///
    /// @param [out] hosts Container holding parsed hosts and options.
    virtual void processRowData(ConstHostCollection& hosts, 
                                const PgSqlResult& r, int row) {
        HostPtr current_host;
        if (hosts.empty()) {
            current_host = retrieveHost(r, row);
            hosts.push_back(current_host);
        } else {
            // Peek at the host id so we can skip it if we already have
            // this host.  This lets us avoid retrieving the host needlessly
            // for each of its sub-rows (options, etc...)
            HostID row_host_id = getHostId(r, row);
            current_host = boost::const_pointer_cast<Host>(hosts.back());
            if (row_host_id > current_host->getHostId()) {
                current_host = retrieveHost(r, row, row_host_id);
                hosts.push_back(current_host);
            }
        }


        // Parse DHCPv4 options if required to do so.
        if (opt_proc4_) {
            CfgOptionPtr cfg = current_host->getCfgOption4();
            opt_proc4_->retrieveOption(cfg, r, row);
        }

        // Parse DHCPv6 options if required to do so.
        if (opt_proc6_) {
            CfgOptionPtr cfg = current_host->getCfgOption6();
            opt_proc6_->retrieveOption(cfg, r, row);
        }
    }

private:

    /// @brief Returns a number of columns required to retrieve option data.
    ///
    /// Depending if we need DHCPv4/DHCPv6 options only, or both DHCPv4 and
    /// DHCPv6 a different number of columns is required in the binding array.
    /// This method returns the number of required columns, according to the
    /// value of @c fetched_columns passed in the constructor.
    ///
    /// @param fetched_columns A value which specifies whether DHCPv4, DHCPv6 or
    /// both types of options should be retrieved.
    ///
    /// @return Number of required columns.
    static size_t getRequiredColumnsNum(const FetchedOptions& fetched_options) {
        return (fetched_options == DHCP4_AND_DHCP6 ? 2 * OPTION_COLUMNS :
                OPTION_COLUMNS);
    }

    /// @brief Pointer to DHCPv4 options processor.
    ///
    /// If this object is NULL, the DHCPv4 options are not fetched.
    OptionProcessorPtr opt_proc4_;

    /// @brief Pointer to DHCPv6 options processor.
    ///
    /// If this object is NULL, the DHCPv6 options are not fetched.
    OptionProcessorPtr opt_proc6_;
};

/// @brief This class provides mechanisms for sending and retrieving
/// host information, DHCPv4 options, DHCPv6 options and IPv6 reservations.
///
/// This class extends the @ref PgSqlHostWithOptionsExchange class with the
/// mechanisms to retrieve IPv6 reservations. This class is used in sitations
/// when it is desired to retrieve DHCPv6 specific information about the host
/// (DHCPv6 options and reservations), or entire information about the host
/// (DHCPv4 options, DHCPv6 options and reservations). The following are the
/// queries used with this class:
/// - SELECT ? FROM hosts LEFT JOIN dhcp4_options LEFT JOIN dhcp6_options
///   LEFT JOIN ipv6_reservations ...
/// - SELECT ? FROM hosts LEFT JOIN dhcp6_options LEFT JOIN ipv6_reservations ..
class PgSqlHostIPv6Exchange : public PgSqlHostWithOptionsExchange {
private:

    /// @brief Number of columns holding IPv6 reservation information.
    static const size_t RESERVATION_COLUMNS = 5;

public:

    /// @brief Constructor.
    ///
    /// Apart from initializing the base class data structures it also
    /// initializes values representing IPv6 reservation information.
    PgSqlHostIPv6Exchange(const FetchedOptions& fetched_options)
        : PgSqlHostWithOptionsExchange(fetched_options, RESERVATION_COLUMNS),
          reservation_id_index_(findAvailColumn()),
          address_index_(reservation_id_index_ + 1),
          prefix_len_index_(reservation_id_index_ + 2),
          type_index_(reservation_id_index_ + 3),
          iaid_index_(reservation_id_index_ + 4),
          most_recent_reservation_id_(0) {

        // Provide names of additional columns returned by the queries.
        columns_[reservation_id_index_] = "reservation_id";
        columns_[address_index_] = "address";
        columns_[prefix_len_index_] = "prefix_len";
        columns_[type_index_] = "type";
        columns_[iaid_index_] = "dhcp6_iaid";

    //    BOOST_STATIC_ASSERT(5 < RESERVATION_COLUMNS);
    }

    /// @brief Reinitializes state information
    /// 
    /// This function should be called in between statement executions.
    /// Deriving classes should be to sure to reinitialize any stateful
    /// values that control statement result processing.
    void clear() {
        PgSqlHostWithOptionsExchange::clear();
        most_recent_reservation_id_ = 0;
    }

    /// @brief Returns reservation id from the row.
    ///
    /// @return Reservation id or 0 if no reservation data is fetched.
    uint64_t getReservationId(const PgSqlResult& r, int row) const {
        uint64_t resv_id = 0;
        if (!isColumnNull(r, row, reservation_id_index_)) {
            getColumnValue(r, row, reservation_id_index_, resv_id);
        }
        
        return (resv_id);
    };

    /// @brief Creates IPv6 reservation from the data contained in the
    /// currently processed row.
    ///
    /// Called after the MYSQL_BIND array created by createBindForReceive().
    ///
    /// @return IPv6Resrv object (containing IPv6 address or prefix reservation)
    IPv6Resrv retrieveReservation(const PgSqlResult& r, int row) {
        // Set the IPv6 Reservation type (0 = IA_NA, 2 = IA_PD)
        IPv6Resrv::Type resv_type;
        uint16_t tmp;
        getColumnValue(r, row, type_index_, tmp);

        switch (tmp) {
        case 0:
            resv_type = IPv6Resrv::TYPE_NA;
            break;

        case 2:
            resv_type = IPv6Resrv::TYPE_PD;
            break;

        default:
            isc_throw(BadValue,
                      "invalid IPv6 reservation type returned: "
                      << tmp << ". Only 0 or 2 are allowed.");
        }

        isc::asiolink::IOAddress address(getIPv6Value(r, row, address_index_));

        uint16_t prefix_len;        
        getColumnValue(r, row, prefix_len_index_, prefix_len);

        IPv6Resrv reservation(resv_type, IOAddress(address), prefix_len);
        return (reservation);
    };

    /// @brief Processes one row of data fetched from a database.
    ///
    /// The processed data must contain host id, which uniquely identifies a
    /// host. This method creates a host and inserts it to the hosts collection
    /// only if the last inserted host has a different host id. This prevents
    /// adding duplicated hosts to the collection, assuming that processed
    /// rows are primarily ordered by host id column.
    ///
    /// Depending on the value of the @c fetched_options specified in the
    /// constructor, this method also parses options returned as a result
    /// of SELECT queries.
    ///
    /// For any returned row which contains IPv6 reservation information it
    /// checks if the reservation is not a duplicate of previously parsed
    /// reservation and appends the IPv6Resrv object into the host object
    /// if the parsed row contains new reservation information.
    ///
    /// @param [out] hosts Collection of hosts to which a new host created
    ///        from the processed data should be inserted.
    virtual void processRowData(ConstHostCollection& hosts,
                                const PgSqlResult& r, int row) {
        // Call parent class to fetch host information and options.
        PgSqlHostWithOptionsExchange::processRowData(hosts, r, row);

        uint64_t reservation_id = getReservationId(r, row);
        if (!reservation_id) {
            return;
        }

        if (hosts.empty()) {
            isc_throw(Unexpected, "no host information while retrieving"
                      " IPv6 reservation");
        }
        HostPtr host = boost::const_pointer_cast<Host>(hosts.back());

        // If we're dealing with a new reservation, let's add it to the
        // host.
        if (reservation_id > most_recent_reservation_id_) {
            most_recent_reservation_id_ = reservation_id;

            if (most_recent_reservation_id_ > 0) {
                host->addReservation(retrieveReservation(r, row));
            }
        }
    }

private:
    /// @name Indexes of columns holding information about IPv6 reservations.
    //@{
    /// @brief Index of reservation_id column.
    size_t reservation_id_index_;

    /// @brief Index of address column.
    size_t address_index_;

    /// @brief Index of prefix_len column.
    size_t prefix_len_index_;

    /// @brief Index of type column.
    size_t type_index_;

    /// @brief Index of IAID column.
    size_t iaid_index_;

    //@}

    /// @brief Reservation id for last processed row.
    uint64_t most_recent_reservation_id_;

};

/// @brief This class is used for storing IPv6 reservations in a MySQL database.
///
/// This class is only used to insert IPv6 reservations into the
/// ipv6_reservations table. It is not used to retrieve IPv6 reservations. To
/// retrieve IPv6 reservation the @ref PgSqlIPv6HostExchange class should be
/// used instead.
///
/// When a new IPv6 reservation is inserted into the database, an appropriate
/// host must be defined in the hosts table. An attempt to insert IPv6
/// reservation for non-existing host will result in failure.
class PgSqlIPv6ReservationExchange : public PgSqlExchange {
private:

    /// @brief Set number of columns for ipv6_reservation table.
    static const size_t RESRV_COLUMNS = 6;

public:

    /// @brief Constructor
    ///
    /// Initialize class members representing a single IPv6 reservation.
    PgSqlIPv6ReservationExchange()
        : PgSqlExchange(RESRV_COLUMNS), 
          resv_(IPv6Resrv::TYPE_NA, asiolink::IOAddress("::"), 128) {
        // Set the column names (for error messages)
        columns_[0] = "host_id";
        columns_[1] = "address";
        columns_[2] = "prefix_len";
        columns_[3] = "type";
        columns_[4] = "dhcp6_iaid";
        BOOST_STATIC_ASSERT(4 < RESRV_COLUMNS);
    }

    /// @brief Populate a bind array representing an IPv6 reservation
    ///
    /// Constructs a PsqlBindArray for an IPv6 reservation to the database.
    ///
    /// @param resv The IPv6 reservation to be added to the database.
    ///        None of the fields in the reservation are modified -
    /// @param host_id ID of the host to which this reservation belongs.
    ///
    /// @return pointer to newly constructed bind_array containing the
    /// bound values extracted the IPv6 reservation
    ///
    /// @throw DbOperationError if bind_array cannot be populated.
    PsqlBindArrayPtr createBindForSend(const IPv6Resrv& resv, 
                                       const HostID& host_id) {
        // Store the values to ensure they remain valid.
        // Technically we don't need this, as currently all the values
        // are converted to strings and stored by the bind array.
        resv_ = resv;

        PsqlBindArrayPtr bind_array(new PsqlBindArray());

        try {
            // address VARCHAR(39) NOT NULL
            bind_array->add(resv.getPrefix());

            // prefix_len: SMALLINT NOT NULL
            bind_array->add(resv.getPrefixLen());

            // type: SMALLINT NOT NULL
            // See lease6_types for values (0 = IA_NA, 1 = IA_TA, 2 = IA_PD)
            uint16_t type = resv.getType() == IPv6Resrv::TYPE_NA ? 0 : 2;
            bind_array->add(type);

            // dhcp6_iaid: INT UNSIGNED
            /// @todo: We don't support iaid in the IPv6Resrv yet.
            bind_array->addNull();

            // host_id: BIGINT NOT NULL
            bind_array->add(host_id);
        } catch (const std::exception& ex) {
            isc_throw(DbOperationError,
                      "Could not create bind array from IPv6 Reservation: "
                      << resv_.toText() << ", reason: " << ex.what());
        }

        return (bind_array);
    }

private:
    /// @brief Object holding reservation being sent to the database.
    IPv6Resrv resv_;
};

/// @brief This class is used for inserting options into a database.
///
/// This class supports inserting both DHCPv4 and DHCPv6 options.

class PgSqlOptionExchange : public PgSqlExchange {
private:

    static const int OPTION_ID_COL = 0;
    static const int CODE_COL = 1;
    static const int VALUE_COL = 2;
    static const int FORMATTED_VALUE_COL = 3;
    static const int SPACE_COL = 4;
    static const int PERSISTENT_COL = 5;
    static const int DHCP_CLIENT_CLASS_COL = 6;
    static const int DHCP_SUBNET_ID_COL = 7;
    static const int HOST_ID_COL = 8;
    static const int SCOPE_ID_COL = 9;

    /// @brief Number of columns in the tables holding options.
    static const size_t OPTION_COLUMNS = 10;

public:

    /// @brief Constructor.
    PgSqlOptionExchange()
        : PgSqlExchange(OPTION_COLUMNS) {
        columns_[OPTION_ID_COL] = "option_id";
        columns_[CODE_COL] = "code";
        columns_[VALUE_COL] = "value";
        columns_[FORMATTED_VALUE_COL] = "formatted_value";
        columns_[SPACE_COL] = "space";
        columns_[PERSISTENT_COL] = "persistent";
        columns_[DHCP_CLIENT_CLASS_COL] = "dhcp_client_class";
        columns_[DHCP_SUBNET_ID_COL] = "dhcp_subnet_id";
        columns_[HOST_ID_COL] = "host_id";
        columns_[SCOPE_ID_COL] = "scope_id";

        BOOST_STATIC_ASSERT(8 < OPTION_COLUMNS);
    }

    /// @brief Creates binding array to insert option data into database.
    ///
    /// @return Vector of MYSQL_BIND object representing an option.
    PsqlBindArrayPtr
    createBindForSend(const OptionDescriptor& opt_desc,
                      const std::string& opt_space,
                      const OptionalValue<SubnetID>& subnet_id,
                      const HostID& host_id) {

        // Hold pointer to the option to make sure it remains valid until
        // we complete a query.
        option_ = opt_desc.option_;

        PsqlBindArrayPtr bind_array(new PsqlBindArray());

        try {
            // option_id: is auto_incremented so skip it

            // code: SMALLINT UNSIGNED NOT NULL
            bind_array->add(option_->getType());

            // value: BYTEA NULL
            if (opt_desc.formatted_value_.empty() &&
                (opt_desc.option_->len() > opt_desc.option_->getHeaderLen())) {
                // The formatted_value is empty and the option value is
                // non-empty so we need to prepare on-wire format for the
                // option and store it in the database as a BYTEA.
                OutputBuffer buf(opt_desc.option_->len());
                opt_desc.option_->pack(buf);
                const char* buf_ptr = static_cast<const char*>(buf.getData());
                value_.assign(buf_ptr + opt_desc.option_->getHeaderLen(),
                              buf_ptr + buf.getLength());
                value_len_ = value_.size();
                bind_array->add(value_);
            } else {
                // No value or formatted_value specified. In this case, the
                // value BYTEA should be NULL.
                bind_array->addNull(PsqlBindArray::BINARY_FMT);
            }

            // formatted_value: TEXT NULL,
            if (opt_desc.formatted_value_.empty()) {
                bind_array->addNull();
            } else { 
                bind_array->bindString(opt_desc.formatted_value_);
            }

            // space: VARCHAR(128) NULL
            if (opt_space.empty()) {
                bind_array->addNull();
            } else {
                bind_array->bindString(opt_space);
            }

            // persistent: BOOLEAN DEFAULT false
            bind_array->add(opt_desc.persistent_);

            // dhcp_client_class: VARCHAR(128) NULL
            /// @todo Assign actual value to client class string.
            /// once option level client class is supported
            bind_array->addNull();

            // dhcp_subnet_id: INT NULL
            if (subnet_id.isSpecified()) {
                uint32_t subnet_id = subnet_id;
                bind_array->add(subnet_id);
            } else {
                bind_array->addNull();
            }

            // host_id: INT  - in this case it should never be 0
            bind_array->add(host_id);
        } catch (const std::exception& ex) {
            isc_throw(DbOperationError,
                      "Could not create bind array for inserting DHCP "
                      "option: " << option_->toText() << ", reason: "
                      << ex.what());
        }

        return (bind_array);
    }

private:

    /// @brief Option value as binary.
    std::vector<uint8_t> value_;

    /// @brief Option value length.
    size_t value_len_;

    /// @brief Pointer to currently parsed option.
    OptionPtr option_;
};

} // end of anonymous namespace


namespace isc {
namespace dhcp {

/// @brief Implementation of the @ref PgSqlHostDataSource.
class PgSqlHostDataSourceImpl {
public:

    /// @brief Statement Tags
    ///
    /// The contents of the enum are indexes into the list of SQL statements
    enum StatementIndex {
        INSERT_HOST,            // Insert new host to collection
        INSERT_V6_RESRV,        // Insert v6 reservation
        INSERT_V4_OPTION,       // Insert DHCPv4 option
        INSERT_V6_OPTION,       // Insert DHCPv6 option
        GET_HOST_DHCPID,        // Gets hosts by host identifier
        GET_HOST_ADDR,          // Gets hosts by IPv4 address
        GET_HOST_SUBID4_DHCPID, // Gets host by IPv4 SubnetID, HW address/DUID
        GET_HOST_SUBID6_DHCPID, // Gets host by IPv6 SubnetID, HW address/DUID
        GET_HOST_SUBID_ADDR,    // Gets host by IPv4 SubnetID and IPv4 address
        GET_HOST_PREFIX,        // Gets host by IPv6 prefix
        GET_VERSION,            // Obtain version number
        NUM_STATEMENTS          // Number of statements
    };

    /// @brief Constructor.
    ///
    /// This constructor opens database connection and initializes prepared
    /// statements used in the queries.
    PgSqlHostDataSourceImpl(const PgSqlConnection::ParameterMap& parameters);

    /// @brief Destructor.
    ~PgSqlHostDataSourceImpl();

    /// @brief Executes statements which insert a row into one of the tables.
    ///
    /// @param stindex Index of a statement being executed.
    /// @param bind Vector of MYSQL_BIND objects to be used when making the
    /// query.
    /// @param return_last_id flag indicating whether or not the insert
    /// returns the primary key of from the row inserted via " RETURNING
    /// <primary key> as pid" clause on the INSERT statement.  The RETURNING
    /// clause causes the INSERT to return a result set that should consist
    /// of a single row with one column, the value of the primary key.
    /// Defaults to false.
    ///
    /// @returns 0 if return_last_id is false, otherwise it returns the
    /// the value in the result set in the first col of the first row.
    ///
    /// @throw isc::dhcp::DuplicateEntry Database throws duplicate entry error
    uint64_t addStatement(PgSqlHostDataSourceImpl::StatementIndex stindex,
                          PsqlBindArrayPtr& bind,
                          const bool return_last_id = false);

    /// @brief Inserts IPv6 Reservation into ipv6_reservation table.
    ///
    /// @param resv IPv6 Reservation to be added
    /// @param id ID of a host owning this reservation
    void addResv(const IPv6Resrv& resv, const HostID& id);

    /// @brief Inserts a single DHCP option into the database.
    ///
    /// @param stindex Index of a statement being executed.
    /// @param opt_desc Option descriptor holding information about an option
    /// to be inserted into the database.
    /// @param opt_space Option space name.
    /// @param subnet_id Subnet identifier.
    /// @param host_id Host identifier.
    void addOption(const PgSqlHostDataSourceImpl::StatementIndex& stindex,
                   const OptionDescriptor& opt_desc,
                   const std::string& opt_space,
                   const OptionalValue<SubnetID>& subnet_id,
                   const HostID& host_id);

    /// @brief Inserts multiple options into the database.
    ///
    /// @param stindex Index of a statement being executed.
    /// @param options_cfg An object holding a collection of options to be
    /// inserted into the database.
    /// @param host_id Host identifier retrieved using @c mysql_insert_id.
    void addOptions(const StatementIndex& stindex, 
                    const ConstCfgOptionPtr& options_cfg,
                    const uint64_t host_id);

    /// @brief Creates collection of @ref Host objects with associated
    /// information such as IPv6 reservations and/or DHCP options.
    ///
    /// This method performs a query which returns host information from
    /// the 'hosts' table. The query may also use LEFT JOIN clause to
    /// retrieve information from other tables, e.g. ipv6_reservations,
    /// dhcp4_options and dhcp6_options.
    /// Whether IPv6 reservations and/or options are assigned to the
    /// @ref Host objects depends on the type of the exchange object.
    ///
    /// @param stindex Statement index.
    /// @param bind Pointer to an array of MySQL bindings.
    /// @param exchange Pointer to the exchange object used for the
    /// particular query.
    /// @param [out] result Reference to the collection of hosts returned.
    /// @param single A boolean value indicating if a single host is
    /// expected to be returned, or multiple hosts.
    void getHostCollection(StatementIndex stindex, PsqlBindArrayPtr bind,
                           boost::shared_ptr<PgSqlHostExchange> exchange,
                           ConstHostCollection& result, bool single) const;

    /// @brief Retrieves a host by subnet and client's unique identifier.
    ///
    /// This method is used by both PgSqlHostDataSource::get4 and
    /// PgSqlHostDataSource::get6 methods.
    ///
    /// @param subnet_id Subnet identifier.
    /// @param identifier_type Identifier type.
    /// @param identifier_begin Pointer to a begining of a buffer containing
    /// an identifier.
    /// @param identifier_len Identifier length.
    /// @param stindex Statement index.
    /// @param exchange Pointer to the exchange object used for the
    /// particular query.
    ///
    /// @return Pointer to const instance of Host or null pointer if
    /// no host found.
    ConstHostPtr getHost(const SubnetID& subnet_id,
                         const Host::IdentifierType& identifier_type,
                         const uint8_t* identifier_begin,
                         const size_t identifier_len,
                         StatementIndex stindex,
                         boost::shared_ptr<PgSqlHostExchange> exchange) const;


    /// @brief Returns PostgreSQL schema version of the open database
    ///
    /// @return Version number stored in the database, as a pair of unsigned
    ///         integers. "first" is the major version number, "second" the
    ///         minor number.
    ///
    /// @throw isc::dhcp::DbOperationError An operation on the open database
    ///        has failed.
    std::pair<uint32_t, uint32_t> getVersion() const;

    /// @brief Pointer to the object representing an exchange which
    /// can be used to retrieve hosts and DHCPv4 options.
    boost::shared_ptr<PgSqlHostWithOptionsExchange> host_exchange_;

    /// @brief Pointer to an object representing an exchange which can
    /// be used to retrieve hosts, DHCPv6 options and IPv6 reservations.
    boost::shared_ptr<PgSqlHostIPv6Exchange> host_ipv6_exchange_;

    /// @brief Pointer to an object representing an exchange which can
    /// be used to retrieve hosts, DHCPv4 and DHCPv6 options, and
    /// IPv6 reservations using a single query.
    boost::shared_ptr<PgSqlHostIPv6Exchange> host_ipv46_exchange_;

    /// @brief Pointer to an object representing an exchange which can
    /// be used to insert new IPv6 reservation.
    boost::shared_ptr<PgSqlIPv6ReservationExchange> host_ipv6_reservation_exchange_;

    /// @brief Pointer to an object representing an exchange which can
    /// be used to insert DHCPv4 or DHCPv6 option into dhcp4_options
    /// or dhcp6_options table.
    boost::shared_ptr<PgSqlOptionExchange> host_option_exchange_;

    /// @brief MySQL connection
    PgSqlConnection conn_;

};

/// @brief Prepared MySQL statements used by the backend to insert and
/// retrieve hosts from the database.
PgSqlTaggedStatement tagged_statements[] = {
    // Inserts a host into the 'hosts' table. Returns the inserted host id.
    {8, // PgSqlHostDataSourceImpl::INSERT_HOST,
     { OID_BYTEA, OID_INT2,
       OID_INT4, OID_INT4, OID_INT8, OID_VARCHAR,
       OID_VARCHAR, OID_VARCHAR }, 
     "insert_host",
     "INSERT INTO hosts(dhcp_identifier, dhcp_identifier_type, "
     "  dhcp4_subnet_id, dhcp6_subnet_id, ipv4_address, hostname, "
     "  dhcp4_client_classes, dhcp6_client_classes) "
     "VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING host_id"
    },

    // Inserts a single IPv6 reservation into 'reservations' table.
    {5, //PgSqlHostDataSourceImpl::INSERT_V6_RESRV,
     { OID_VARCHAR, OID_INT2, OID_INT4, OID_INT4, OID_INT4 },
     "insert_v6_resrv",
     "INSERT INTO ipv6_reservations(address, prefix_len, type, "
     "  dhcp6_iaid, host_id) "
     "VALUES ($1, $2, $3, $4, $5)"
    },

    // Inserts a single DHCPv4 option into 'dhcp4_options' table.
    // Using fixed scope_id = 3, which associates an option with host.
    {8, // PgSqlHostDataSourceImpl::INSERT_V4_OPTION,
     { OID_INT2, OID_BYTEA, OID_TEXT, OID_VARCHAR, 
       OID_BOOL, OID_VARCHAR, OID_INT4, OID_INT8, OID_INT2}, 
     "insert_v4_option",
     "INSERT INTO dhcp4_options(code, value, formatted_value, space, "
     "  persistent, dhcp_client_class, dhcp4_subnet_id, host_id, scope_id) "
     "VALUES ($1, $2, $3, $4, $5, $6, $7, $8, 3)"
    },

    // Inserts a single DHCPv6 option into 'dhcp6_options' table.
    // Using fixed scope_id = 3, which associates an option with host.
    {8, // PgSqlHostDataSourceImpl::INSERT_V6_OPTION,
     { OID_INT2, OID_BYTEA, OID_TEXT, OID_VARCHAR, 
       OID_BOOL, OID_VARCHAR, OID_INT4, OID_INT8, OID_INT2}, 
     "insert_v6_option",
     "INSERT INTO dhcp6_options(code, value, formatted_value, space, "
     "  persistent, dhcp_client_class, dhcp6_subnet_id, host_id, scope_id) "
     "VALUES ($1, $2, $3, $4, $5, $6, $7, $8, 3)"
    },

    // Retrieves host information, IPv6 reservations and both DHCPv4 and
    // DHCPv6 options associated with the host. The LEFT JOIN clause is used
    // to retrieve information from 4 different tables using a single query.
    // Hence, this query returns multiple rows for a single host.
    {2, // PgSqlHostDataSourceImpl::GET_HOST_DHCPID,
     { OID_BYTEA, OID_INT2 },
     "get_host_dhcpid",
     "SELECT h.host_id, h.dhcp_identifier, h.dhcp_identifier_type, "
     "  h.dhcp4_subnet_id, h.dhcp6_subnet_id, h.ipv4_address, "
     "  h.hostname, h.dhcp4_client_classes, h.dhcp6_client_classes, "
     "  o4.option_id, o4.code, o4.value, o4.formatted_value, o4.space, "
     "  o4.persistent, "
     "  o6.option_id, o6.code, o6.value, o6.formatted_value, o6.space, "
     "  o6.persistent, "
     "  r.reservation_id, r.address, r.prefix_len, r.type, r.dhcp6_iaid "
     "FROM hosts AS h "
     "LEFT JOIN dhcp4_options AS o4 ON h.host_id = o4.host_id "
     "LEFT JOIN dhcp6_options AS o6 ON h.host_id = o6.host_id "
     "LEFT JOIN ipv6_reservations AS r ON h.host_id = r.host_id "
     "WHERE dhcp_identifier = $1 AND dhcp_identifier_type = $2 "
     "ORDER BY h.host_id, o4.option_id, o6.option_id, r.reservation_id"
    },

    // Retrieves host information along with the DHCPv4 options associated with
    // it. Left joining the dhcp4_options table results in multiple rows being
    // returned for the same host. The host is retrieved by IPv4 address.
    { 1, // PgSqlHostDataSourceImpl::GET_HOST_ADDR,
     { OID_INT8 }, "get_host_addr",
     "SELECT h.host_id, h.dhcp_identifier, h.dhcp_identifier_type, "
     "  h.dhcp4_subnet_id, h.dhcp6_subnet_id, h.ipv4_address, h.hostname, "
     "  h.dhcp4_client_classes, h.dhcp6_client_classes, o.option_id, o.code, "
     "  o.value, o.formatted_value, o.space, o.persistent "
     "FROM hosts AS h "
     "LEFT JOIN dhcp4_options AS o ON h.host_id = o.host_id "
     "WHERE ipv4_address = $1 "
     "ORDER BY h.host_id, o.option_id"
    },

    // Retrieves host information and DHCPv4 options using subnet identifier
    // and client's identifier. Left joining the dhcp4_options table results in
    // multiple rows being returned for the same host.
    { 3, //PgSqlHostDataSourceImpl::GET_HOST_SUBID4_DHCPID,
     { OID_INT4, OID_INT2, OID_BYTEA }, 
     "get_host_subid4_dhcpid",
     "SELECT h.host_id, h.dhcp_identifier, h.dhcp_identifier_type, "
     "  h.dhcp4_subnet_id, h.dhcp6_subnet_id, h.ipv4_address, h.hostname, "
     "  h.dhcp4_client_classes, h.dhcp6_client_classes, o.option_id, o.code, " 
     "  o.value, o.formatted_value, o.space, o.persistent "
     "FROM hosts AS h "
     "LEFT JOIN dhcp4_options AS o ON h.host_id = o.host_id "
     "WHERE h.dhcp4_subnet_id = $1 AND h.dhcp_identifier_type = $2 "
     "   AND h.dhcp_identifier = $3 "
     "ORDER BY h.host_id, o.option_id"
    },

    // Retrieves host information, IPv6 reservations and DHCPv6 options
    // associated with a host. The number of rows returned is a multiplication
    // of number of IPv6 reservations and DHCPv6 options.
    {3, //PgSqlHostDataSourceImpl::GET_HOST_SUBID6_DHCPID,
     { OID_INT4, OID_INT2, OID_BYTEA },
     "get_host_subid6_dhcpid",
     "SELECT h.host_id, h.dhcp_identifier, "
     "  h.dhcp_identifier_type, h.dhcp4_subnet_id, "
     "  h.dhcp6_subnet_id, h.ipv4_address, h.hostname, "
     "  h.dhcp4_client_classes, h.dhcp6_client_classes, "
     "  o.option_id, o.code, o.value, o.formatted_value, o.space, "
     "  o.persistent, "
     "  r.reservation_id, r.address, r.prefix_len, r.type, r.dhcp6_iaid "
     "FROM hosts AS h "
     "LEFT JOIN dhcp6_options AS o ON h.host_id = o.host_id "
     "LEFT JOIN ipv6_reservations AS r ON h.host_id = r.host_id "
     "WHERE h.dhcp6_subnet_id = $1 AND h.dhcp_identifier_type = $2 "
     " AND h.dhcp_identifier = $3 "
     "ORDER BY h.host_id, o.option_id, r.reservation_id"
    },

    // Retrieves host information and DHCPv4 options for the host using subnet
    // identifier and IPv4 reservation. Left joining the dhcp4_options table
    // results in multiple rows being returned for the host. The number of
    // rows depends on the number of options defined for the host.
    { 2,  //PgSqlHostDataSourceImpl::GET_HOST_SUBID_ADDR,
     { OID_INT4, OID_INT8 },
     "get_host_subid_addr",
     "SELECT h.host_id, h.dhcp_identifier, h.dhcp_identifier_type, "
     "  h.dhcp4_subnet_id, h.dhcp6_subnet_id, h.ipv4_address, h.hostname, "
     "  h.dhcp4_client_classes, h.dhcp6_client_classes, o.option_id, o.code, "
     "  o.value, o.formatted_value, o.space, o.persistent "
     "FROM hosts AS h "
     "LEFT JOIN dhcp4_options AS o ON h.host_id = o.host_id "
     "WHERE h.dhcp4_subnet_id = $1 AND h.ipv4_address = $2 "
     "ORDER BY h.host_id, o.option_id"
    },

    // Retrieves host information, IPv6 reservations and DHCPv6 options
    // associated with a host using prefix and prefix length. This query
    // returns host information for a single host. However, multiple rows
    // are returned due to left joining IPv6 reservations and DHCPv6 options.
    // The number of rows returned is multiplication of number of existing
    // IPv6 reservations and DHCPv6 options.
    {2, // PgSqlHostDataSourceImpl::GET_HOST_PREFIX,
     { OID_VARCHAR, OID_INT2 },
     "get_host_prefix",
     "SELECT h.host_id, h.dhcp_identifier, "
     "  h.dhcp_identifier_type, h.dhcp4_subnet_id, "
     "  h.dhcp6_subnet_id, h.ipv4_address, h.hostname, "
     "  h.dhcp4_client_classes, h.dhcp6_client_classes, "
     "  o.option_id, o.code, o.value, o.formatted_value, o.space, "
     "  o.persistent, "
     "  r.reservation_id, r.address, r.prefix_len, r.type, "
     "  r.dhcp6_iaid "
     "FROM hosts AS h "
     "LEFT JOIN dhcp6_options AS o ON h.host_id = o.host_id "
     "LEFT JOIN ipv6_reservations AS r ON h.host_id = r.host_id "
     "WHERE h.host_id = "
     "  (SELECT host_id FROM ipv6_reservations "
     "   WHERE address = $1 AND prefix_len = $2) "
     "ORDER BY h.host_id, o.option_id, r.reservation_id"
    },

    // Retrieves MySQL schema version.
    { 0, //PgSqlHostDataSourceImpl::GET_VERSION,
     { OID_NONE },
     "get_version",
     "SELECT version, minor FROM schema_version"
    },

    // Marks the end of the statements table.
    {0, { 0 }, NULL, NULL}
};

PgSqlHostDataSourceImpl::
PgSqlHostDataSourceImpl(const PgSqlConnection::ParameterMap& parameters)
    : host_exchange_(new PgSqlHostWithOptionsExchange(PgSqlHostWithOptionsExchange::DHCP4_ONLY)),
      host_ipv6_exchange_(new PgSqlHostIPv6Exchange(PgSqlHostWithOptionsExchange::DHCP6_ONLY)),
      host_ipv46_exchange_(new PgSqlHostIPv6Exchange(PgSqlHostWithOptionsExchange::
                                                     DHCP4_AND_DHCP6)),
      host_ipv6_reservation_exchange_(new PgSqlIPv6ReservationExchange()),
      host_option_exchange_(new PgSqlOptionExchange()),
      conn_(parameters) {

    // Open the database.
    conn_.openDatabase();

    int i = 0;
    for( ; tagged_statements[i].text != NULL ; ++i) {
        conn_.prepareStatement(tagged_statements[i]);
    }

    // Just in case somebody foo-barred things
    if (i != NUM_STATEMENTS) {
        isc_throw(DbOpenError, "Number of statements prepared: " << i
                  << " does not match expected count:" << NUM_STATEMENTS);
    }
}

PgSqlHostDataSourceImpl::~PgSqlHostDataSourceImpl() {
}

uint64_t
PgSqlHostDataSourceImpl::addStatement(StatementIndex stindex,
                                      PsqlBindArrayPtr& bind_array,
                                      const bool return_last_id) {
    uint64_t last_id = 0;
    PgSqlResult r(PQexecPrepared(conn_, tagged_statements[stindex].name,
                                 tagged_statements[stindex].nbparams,
                                 &bind_array->values_[0],
                                 &bind_array->lengths_[0],
                                 &bind_array->formats_[0], 0));

    int s = PQresultStatus(r);

    if (s != PGRES_COMMAND_OK) {
        // Failure: check for the special case of duplicate entry.  If this is
        // the case, we return false to indicate that the row was not added.
        // Otherwise we throw an exception.
        if (conn_.compareError(r, PgSqlConnection::DUPLICATE_KEY)) {
            isc_throw(DuplicateEntry, "Database duplicate entry error");
        }

        conn_.checkStatementError(r, tagged_statements[stindex]);
    }

    if (return_last_id) {
        PgSqlExchange::getColumnValue(r, 0, 0, last_id);
    }

    return (last_id);

}

void
PgSqlHostDataSourceImpl::addResv(const IPv6Resrv& resv,
                                 const HostID& id) {
    PsqlBindArrayPtr bind_array;
    bind_array = host_ipv6_reservation_exchange_->createBindForSend(resv, id);
    addStatement(INSERT_V6_RESRV, bind_array);
}

void
PgSqlHostDataSourceImpl::addOption(const StatementIndex& stindex,
                                   const OptionDescriptor& opt_desc,
                                   const std::string& opt_space,
                                   const OptionalValue<SubnetID>& subnet_id,
                                   const HostID& id) {
    PsqlBindArrayPtr bind_array;
    bind_array = host_option_exchange_->createBindForSend(opt_desc, opt_space,
                                                          subnet_id, id);
    addStatement(stindex, bind_array);
}

void
PgSqlHostDataSourceImpl::addOptions(const StatementIndex& stindex,
                                    const ConstCfgOptionPtr& options_cfg,
                                    const uint64_t host_id) {
    // Get option space names and vendor space names and combine them within a
    // single list.
    std::list<std::string> option_spaces = options_cfg->getOptionSpaceNames();
    std::list<std::string> vendor_spaces = options_cfg->getVendorIdsSpaceNames();
    option_spaces.insert(option_spaces.end(), vendor_spaces.begin(),
                         vendor_spaces.end());

    // For each option space retrieve all options and insert them into the
    // database.
    for (std::list<std::string>::const_iterator space = option_spaces.begin();
         space != option_spaces.end(); ++space) {
        OptionContainerPtr options = options_cfg->getAll(*space);
        if (options && !options->empty()) {
            for (OptionContainer::const_iterator opt = options->begin();
                 opt != options->end(); ++opt) {
                addOption(stindex, *opt, *space, OptionalValue<SubnetID>(),
                          host_id);
            }
        }
    }
}

void
PgSqlHostDataSourceImpl::
getHostCollection(StatementIndex stindex, PsqlBindArrayPtr bind_array,
                  boost::shared_ptr<PgSqlHostExchange> exchange,
                  ConstHostCollection& result, bool single) const {

    exchange->clear();
    PgSqlResult r(PQexecPrepared(conn_, tagged_statements[stindex].name,
                                 tagged_statements[stindex].nbparams,
                                 &bind_array->values_[0],
                                 &bind_array->lengths_[0],
                                 &bind_array->formats_[0], 0));

    conn_.checkStatementError(r, tagged_statements[stindex]);

    int rows = PQntuples(r);
    for(int row = 0; row < rows; ++row) {
        exchange->processRowData(result, r, row);

        if (single && result.size() > 1) {
            isc_throw(MultipleRecords, "multiple records were found in the "
                      "database where only one was expected for query "
                      << tagged_statements[stindex].name);
        }
    }
}

ConstHostPtr
PgSqlHostDataSourceImpl::
getHost(const SubnetID& subnet_id,
        const Host::IdentifierType& identifier_type,
        const uint8_t* identifier_begin,
        const size_t identifier_len,
        StatementIndex stindex,
        boost::shared_ptr<PgSqlHostExchange> exchange) const {

    // Set up the WHERE clause value
    PsqlBindArrayPtr bind_array(new PsqlBindArray());

    // Add the subnet id.
    bind_array->add(subnet_id);

    // Add the Identifier type.
    bind_array->add(static_cast<uint8_t>(identifier_type));

    // Add the identifier value.
    bind_array->add(identifier_begin, identifier_len);

    ConstHostCollection collection;
    getHostCollection(stindex, bind_array, exchange, collection, true);

    // Return single record if present, else clear the host.
    ConstHostPtr result;
    if (!collection.empty())
        result = *collection.begin();

    return (result);
}

std::pair<uint32_t, uint32_t> PgSqlHostDataSourceImpl::getVersion() const {
    LOG_DEBUG(dhcpsrv_logger, DHCPSRV_DBG_TRACE_DETAIL,
              DHCPSRV_PGSQL_HOST_DB_GET_VERSION);

    PgSqlResult r(PQexecPrepared(conn_, "get_version", 0, NULL, NULL, NULL, 0));
    conn_.checkStatementError(r, tagged_statements[GET_VERSION]);

    istringstream tmp;
    uint32_t version;
    tmp.str(PQgetvalue(r, 0, 0));
    tmp >> version;
    tmp.str("");
    tmp.clear();

    uint32_t minor;
    tmp.str(PQgetvalue(r, 0, 1));
    tmp >> minor;

    return (std::make_pair<uint32_t, uint32_t>(version, minor));
}

/*********** PgSqlHostDataSource *********************/


PgSqlHostDataSource::
PgSqlHostDataSource(const PgSqlConnection::ParameterMap& parameters)
    : impl_(new PgSqlHostDataSourceImpl(parameters)) {
}

PgSqlHostDataSource::~PgSqlHostDataSource() {
    delete impl_;
}

void
PgSqlHostDataSource::add(const HostPtr& host) {
    // Initiate PostgreSQL transaction as we will have to make multiple queries
    // to insert host information into multiple tables. If that fails on
    // any stage, the transaction will be rolled back by the destructor of
    // the PgSqlTransaction class.
    PgSqlTransaction transaction(impl_->conn_);

    // Create the MYSQL_BIND array for the host
    PsqlBindArrayPtr bind_array = impl_->host_exchange_->createBindForSend(host);

    // ... and insert the host.
    uint32_t host_id = impl_->addStatement(PgSqlHostDataSourceImpl::INSERT_HOST,
                                           bind_array, true);

    // @todo TKM take this out
    std::cout << "id of new host: " << host_id << std::endl;

    // Insert DHCPv4 options.
    ConstCfgOptionPtr cfg_option4 = host->getCfgOption4();
    if (cfg_option4) {
        impl_->addOptions(PgSqlHostDataSourceImpl::INSERT_V4_OPTION,
                          cfg_option4, host_id);
    }

    // Insert DHCPv6 options.
    ConstCfgOptionPtr cfg_option6 = host->getCfgOption6();
    if (cfg_option6) {
        impl_->addOptions(PgSqlHostDataSourceImpl::INSERT_V6_OPTION,
                          cfg_option6, host_id);
    }

    // Insert IPv6 reservations.
    IPv6ResrvRange v6resv = host->getIPv6Reservations();
    if (std::distance(v6resv.first, v6resv.second) > 0) {
        for (IPv6ResrvIterator resv = v6resv.first; resv != v6resv.second;
             ++resv) {
            impl_->addResv(resv->second, host_id);
        }
    }

    // Everything went fine, so explicitly commit the transaction.
    transaction.commit();
}

ConstHostCollection
PgSqlHostDataSource::getAll(const HWAddrPtr& hwaddr,
                            const DuidPtr& duid) const {

    if (duid){
        return (getAll(Host::IDENT_DUID, &duid->getDuid()[0],
                       duid->getDuid().size()));

    } else if (hwaddr) {
        return (getAll(Host::IDENT_HWADDR,
                       &hwaddr->hwaddr_[0],
                       hwaddr->hwaddr_.size()));
    }

    return (ConstHostCollection());
}

ConstHostCollection
PgSqlHostDataSource::getAll(const Host::IdentifierType& identifier_type,
                            const uint8_t* identifier_begin,
                            const size_t identifier_len) const {
    // Set up the WHERE clause value
    PsqlBindArrayPtr bind_array(new PsqlBindArray());

    // Identifier value.
    bind_array->add(identifier_begin, identifier_len);

    // Identifier type.
    bind_array->add(static_cast<uint8_t>(identifier_type));

    ConstHostCollection result;
    impl_->getHostCollection(PgSqlHostDataSourceImpl::GET_HOST_DHCPID,
                             bind_array, impl_->host_ipv46_exchange_,
                             result, false);
    return (result);
}

ConstHostCollection
PgSqlHostDataSource::getAll4(const asiolink::IOAddress& address) const {

    // Set up the WHERE clause value
    PsqlBindArrayPtr bind_array(new PsqlBindArray());

    // v4 Reservation address 
    bind_array->add(address);

    ConstHostCollection result;
    impl_->getHostCollection(PgSqlHostDataSourceImpl::GET_HOST_ADDR, bind_array,
                             impl_->host_exchange_, result, false);

    return (result);
}

ConstHostPtr
PgSqlHostDataSource::get4(const SubnetID& subnet_id, const HWAddrPtr& hwaddr,
                          const DuidPtr& duid) const {

    /// @todo: Rethink the logic in BaseHostDataSource::get4(subnet, hwaddr, duid)
    if (hwaddr && duid) {
        isc_throw(BadValue, "MySQL host data source get4() called with both"
                  " hwaddr and duid, only one of them is allowed");
    }
    if (!hwaddr && !duid) {
        isc_throw(BadValue, "MySQL host data source get4() called with "
                  "neither hwaddr or duid specified, one of them is required");
    }

    // Choosing one of the identifiers
    if (hwaddr) {
        return (get4(subnet_id, Host::IDENT_HWADDR, &hwaddr->hwaddr_[0],
                     hwaddr->hwaddr_.size()));

    } else if (duid) {
        return (get4(subnet_id, Host::IDENT_DUID, &duid->getDuid()[0],
                     duid->getDuid().size()));
    }

    return (ConstHostPtr());
}

ConstHostPtr
PgSqlHostDataSource::get4(const SubnetID& subnet_id,
                          const Host::IdentifierType& identifier_type,
                          const uint8_t* identifier_begin,
                          const size_t identifier_len) const {

    return (impl_->getHost(subnet_id, identifier_type, identifier_begin,
                           identifier_len,
                           PgSqlHostDataSourceImpl::GET_HOST_SUBID4_DHCPID,
                           impl_->host_exchange_));
}

ConstHostPtr
PgSqlHostDataSource::get4(const SubnetID& subnet_id,
                          const asiolink::IOAddress& address) const {
    // Set up the WHERE clause value
    PsqlBindArrayPtr bind_array(new PsqlBindArray());

    // Add the subnet id
    bind_array->add(subnet_id);

    // Add the address
    bind_array->add(address);

    ConstHostCollection collection;
    impl_->getHostCollection(PgSqlHostDataSourceImpl::GET_HOST_SUBID_ADDR,
                             bind_array, impl_->host_exchange_, collection,
                             true);

    // Return single record if present, else clear the host.
    ConstHostPtr result;
    if (!collection.empty())
        result = *collection.begin();

    return (result);
}

ConstHostPtr
PgSqlHostDataSource::get6(const SubnetID& subnet_id, const DuidPtr& duid,
                          const HWAddrPtr& hwaddr) const {

    /// @todo: Rethink the logic in BaseHostDataSource::get6(subnet, hwaddr, duid)
    if (hwaddr && duid) {
        isc_throw(BadValue, "MySQL host data source get6() called with both"
                  " hwaddr and duid, only one of them is allowed");
    }
    if (!hwaddr && !duid) {
        isc_throw(BadValue, "MySQL host data source get6() called with "
                  "neither hwaddr or duid specified, one of them is required");
    }

    // Choosing one of the identifiers
    if (hwaddr) {
        return (get6(subnet_id, Host::IDENT_HWADDR, &hwaddr->hwaddr_[0],
                     hwaddr->hwaddr_.size()));
    } else if (duid) {
        return (get6(subnet_id, Host::IDENT_DUID, &duid->getDuid()[0],
                     duid->getDuid().size()));
    }

    return (ConstHostPtr());
}

ConstHostPtr
PgSqlHostDataSource::get6(const SubnetID& subnet_id,
                          const Host::IdentifierType& identifier_type,
                          const uint8_t* identifier_begin,
                          const size_t identifier_len) const {

    return (impl_->getHost(subnet_id, identifier_type, identifier_begin,
                   identifier_len, PgSqlHostDataSourceImpl::GET_HOST_SUBID6_DHCPID,
                   impl_->host_ipv6_exchange_));
}

ConstHostPtr
PgSqlHostDataSource::get6(const asiolink::IOAddress& prefix,
                          const uint8_t prefix_len) const {
    // Set up the WHERE clause value
    PsqlBindArrayPtr bind_array(new PsqlBindArray());

    // Add the prefix 
    bind_array->add(prefix);

    // Add the prefix length
    bind_array->add(prefix_len);

    ConstHostCollection collection;
    impl_->getHostCollection(PgSqlHostDataSourceImpl::GET_HOST_PREFIX,
                             bind_array, impl_->host_ipv6_exchange_,
                             collection, true);

    // Return single record if present, else clear the host.
    ConstHostPtr result;
    if (!collection.empty()) {
        result = *collection.begin();
    }

    return (result);
}

// Miscellaneous database methods.

std::string PgSqlHostDataSource::getName() const {
    std::string name = "";
    try {
        name = impl_->conn_.getParameter("name");
    } catch (...) {
        // Return an empty name
    }
    return (name);
}

std::string PgSqlHostDataSource::getDescription() const {
    return (std::string("Host data source that stores host information"
                        "in PostgreSQL database"));
}

std::pair<uint32_t, uint32_t> PgSqlHostDataSource::getVersion() const {
    return(impl_->getVersion());
}

#if 0
// Do we really need these ?
void
PgSqlHostDataSource::commit() {
    impl_->conn_.commit();
}


void
PgSqlHostDataSource::rollback() {
    impl_->conn_.rollback();
}
#endif


}; // end of isc::dhcp namespace
}; // end of isc namespace
