// Copyright (C) 2016-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef CTRL_AGENT_CFG_MGR_H
#define CTRL_AGENT_CFG_MGR_H

#include <cc/data.h>
#include <hooks/hooks_config.h>
#include <process/d_cfg_mgr.h>
#include <boost/pointer_cast.hpp>
#include <map>
#include <string>

namespace isc {
namespace relay {

class RelayConfig;
/// @brief Pointer to a configuration context.
typedef boost::shared_ptr<RelayConfig> RelayConfigPtr;

/// @brief Relay Configuration Context.
///
/// Implement the storage container for configuration context.
/// It provides a single enclosure for the storage of configuration parameters
/// and any other Control Agent specific information that needs to be accessible
/// during configuration parsing as well as to the application as a whole.
/// It is derived from the context base class, ConfigBase.
class RelayConfig : public process::ConfigBase {
public:

    /// @brief Default constructor
    RelayConfig();

    /// @brief Creates a clone of this context object.
    ///
    /// Note this method does not do deep copy the information about control sockets.
    /// That data is stored as ConstElementPtr (a shared pointer) to the actual data.
    ///
    /// @return A pointer to the new clone.
    virtual process::ConfigPtr clone() {
        return (process::ConfigPtr(new RelayConfig(*this)));
    }

    /// @brief Returns non-const reference to configured hooks libraries.
    ///
    /// @return non-const reference to configured hooks libraries.
    isc::hooks::HooksConfig& getHooksConfig() {
        return (hooks_config_);
    }

    /// @brief Returns const reference to configured hooks libraries.
    ///
    /// @return const reference to configured hooks libraries.
    const isc::hooks::HooksConfig& getHooksConfig() const {
        return (hooks_config_);
    }

    /// @brief Unparse a configuration object
    ///
    /// Returns an element which must parse into the same object, i.e.
    /// @code
    /// for all valid config C parse(parse(C)->toElement()) == parse(C)
    /// @endcode
    ///
    /// @return a pointer to a configuration which can be parsed into
    /// the initial configuration object
    virtual isc::data::ElementPtr toElement() const;

private:

    /// @brief Private copy constructor
    ///
    /// It is private to forbid anyone outside of this class to make copies.
    /// The only legal way to copy a context is to call @ref clone().
    ///
    /// @param orig the original context to copy from
    RelayConfig(const RelayConfig& orig);

    /// @brief Private assignment operator to avoid potential for slicing.
    ///
    /// @param rhs Context to be assigned.
    RelayConfig& operator=(const RelayConfig& rhs);

    /// @brief Configured hooks libraries.
    isc::hooks::HooksConfig hooks_config_;
};

/// @brief Relay Configuration Manager.
///
/// Provides the mechanisms for managing the Control Agent application's
/// configuration.
class RelayCfgMgr : public process::DCfgMgrBase {
public:

    /// @brief Constructor.
    RelayCfgMgr();

    /// @brief Destructor
    virtual ~RelayCfgMgr();

    /// @brief Convenience method that returns the Control Agent configuration
    /// context.
    ///
    /// @return returns a pointer to the configuration context.
    RelayConfigPtr getRelayConfig() {
        return (boost::dynamic_pointer_cast<RelayConfig>(getContext()));
    }

    /// @brief Returns configuration summary in the textual format.
    ///
    /// @param selection Bitfield which describes the parts of the configuration
    /// to be returned. This parameter is ignored for the Control Agent.
    ///
    /// @return Summary of the configuration in the textual format.
    virtual std::string getConfigSummary(const uint32_t selection);

protected:

    /// @brief Parses configuration of the Control Agent.
    ///
    /// @param config Pointer to a configuration specified for the agent.
    /// @param check_only Boolean flag indicating if this method should
    /// only verify correctness of the provided configuration.
    /// @return Pointer to a result of configuration parsing.
    virtual isc::data::ConstElementPtr
    parse(isc::data::ConstElementPtr config, bool check_only);

    /// @brief Creates a new, blank RelayCfgContext context.
    ///
    ///
    /// This method is used at the beginning of configuration process to
    /// create a fresh, empty copy of a RelayCfgContext. This new context
    /// will be populated during the configuration process and will replace the
    /// existing context provided the configuration process completes without
    /// error.
    ///
    /// @return Returns a ConfigPtr to the new context instance.
    virtual process::ConfigPtr createNewContext();

    /// @brief Redact the configuration.
    ///
    /// This method replaces passwords by asterisks. The agent version
    /// applies authentication clients.
    ///
    /// @param config Pointer to a configuration specified for the agent.
    /// @return unmodified config or a copy of the config where passwords were
    /// replaced by asterisks so can be safely logged to an unprivileged place.
    virtual isc::data::ConstElementPtr
    redactConfig(isc::data::ConstElementPtr config) const;

private:
    /// @brief Redact an element.
    ///
    /// Recursive helper of redactConfig.
    ///
    /// @param elem An element to redact.
    /// @param redacted The reference to redacted flag: true means the result
    /// was redacted so cannot be shared.
    /// @return unmodified element or a copy of the element: in the second
    /// case embedded passwords were replaced by asterisks and the redacted
    /// flag was set to true.
    virtual isc::data::ConstElementPtr
    redactElement(isc::data::ConstElementPtr elem, bool& redacted) const;
};

/// @brief Defines a shared pointer to RelayCfgMgr.
typedef boost::shared_ptr<RelayCfgMgr> RelayCfgMgrPtr;

} // namespace isc::agent
} // namespace isc

#endif // CTRL_AGENT_CFG_MGR_H
