// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file dhcp6_parser.h
 ** Define the isc::dhcp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_PARSER6_DHCP6_PARSER_H_INCLUDED
# define YY_PARSER6_DHCP6_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 17 "dhcp6_parser.yy"

#include <string>
#include <cc/data.h>
#include <dhcp/option.h>
#include <boost/lexical_cast.hpp>
#include <dhcp6/parser_context_decl.h>

using namespace isc::dhcp;
using namespace isc::data;
using namespace std;

#line 61 "dhcp6_parser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef PARSER6_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER6_DEBUG 1
#  else
#   define PARSER6_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER6_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER6_DEBUG */

#line 14 "dhcp6_parser.yy"
namespace isc { namespace dhcp {
#line 204 "dhcp6_parser.h"




  /// A Bison parser.
  class Dhcp6Parser
  {
  public:
#ifndef PARSER6_STYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // value
      // map_value
      // ddns_replace_client_name_value
      // db_type
      // hr_mode
      // duid_type
      // ncr_protocol_value
      char dummy1[sizeof (ElementPtr)];

      // "boolean"
      char dummy2[sizeof (bool)];

      // "floating point"
      char dummy3[sizeof (double)];

      // "integer"
      char dummy4[sizeof (int64_t)];

      // "constant string"
      char dummy5[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef PARSER6_STYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_PARSER6_EMPTY = -2,
    TOKEN_END = 0,                 // "end of file"
    TOKEN_PARSER6_error = 256,     // error
    TOKEN_PARSER6_UNDEF = 257,     // "invalid token"
    TOKEN_COMMA = 258,             // ","
    TOKEN_COLON = 259,             // ":"
    TOKEN_LSQUARE_BRACKET = 260,   // "["
    TOKEN_RSQUARE_BRACKET = 261,   // "]"
    TOKEN_LCURLY_BRACKET = 262,    // "{"
    TOKEN_RCURLY_BRACKET = 263,    // "}"
    TOKEN_NULL_TYPE = 264,         // "null"
    TOKEN_DHCP6 = 265,             // "Dhcp6"
    TOKEN_DATA_DIRECTORY = 266,    // "data-directory"
    TOKEN_CONFIG_CONTROL = 267,    // "config-control"
    TOKEN_CONFIG_DATABASES = 268,  // "config-databases"
    TOKEN_CONFIG_FETCH_WAIT_TIME = 269, // "config-fetch-wait-time"
    TOKEN_INTERFACES_CONFIG = 270, // "interfaces-config"
    TOKEN_INTERFACES = 271,        // "interfaces"
    TOKEN_RE_DETECT = 272,         // "re-detect"
    TOKEN_LEASE_DATABASE = 273,    // "lease-database"
    TOKEN_HOSTS_DATABASE = 274,    // "hosts-database"
    TOKEN_HOSTS_DATABASES = 275,   // "hosts-databases"
    TOKEN_TYPE = 276,              // "type"
    TOKEN_MEMFILE = 277,           // "memfile"
    TOKEN_MYSQL = 278,             // "mysql"
    TOKEN_POSTGRESQL = 279,        // "postgresql"
    TOKEN_CQL = 280,               // "cql"
    TOKEN_USER = 281,              // "user"
    TOKEN_PASSWORD = 282,          // "password"
    TOKEN_HOST = 283,              // "host"
    TOKEN_PORT = 284,              // "port"
    TOKEN_PERSIST = 285,           // "persist"
    TOKEN_LFC_INTERVAL = 286,      // "lfc-interval"
    TOKEN_READONLY = 287,          // "readonly"
    TOKEN_CONNECT_TIMEOUT = 288,   // "connect-timeout"
    TOKEN_CONTACT_POINTS = 289,    // "contact-points"
    TOKEN_MAX_RECONNECT_TRIES = 290, // "max-reconnect-tries"
    TOKEN_RECONNECT_WAIT_TIME = 291, // "reconnect-wait-time"
    TOKEN_KEYSPACE = 292,          // "keyspace"
    TOKEN_CONSISTENCY = 293,       // "consistency"
    TOKEN_SERIAL_CONSISTENCY = 294, // "serial-consistency"
    TOKEN_REQUEST_TIMEOUT = 295,   // "request-timeout"
    TOKEN_TCP_KEEPALIVE = 296,     // "tcp-keepalive"
    TOKEN_TCP_NODELAY = 297,       // "tcp-nodelay"
    TOKEN_MAX_ROW_ERRORS = 298,    // "max-row-errors"
    TOKEN_PREFERRED_LIFETIME = 299, // "preferred-lifetime"
    TOKEN_MIN_PREFERRED_LIFETIME = 300, // "min-preferred-lifetime"
    TOKEN_MAX_PREFERRED_LIFETIME = 301, // "max-preferred-lifetime"
    TOKEN_VALID_LIFETIME = 302,    // "valid-lifetime"
    TOKEN_MIN_VALID_LIFETIME = 303, // "min-valid-lifetime"
    TOKEN_MAX_VALID_LIFETIME = 304, // "max-valid-lifetime"
    TOKEN_RENEW_TIMER = 305,       // "renew-timer"
    TOKEN_REBIND_TIMER = 306,      // "rebind-timer"
    TOKEN_CALCULATE_TEE_TIMES = 307, // "calculate-tee-times"
    TOKEN_T1_PERCENT = 308,        // "t1-percent"
    TOKEN_T2_PERCENT = 309,        // "t2-percent"
    TOKEN_CACHE_THRESHOLD = 310,   // "cache-threshold"
    TOKEN_CACHE_MAX_AGE = 311,     // "cache-max-age"
    TOKEN_DECLINE_PROBATION_PERIOD = 312, // "decline-probation-period"
    TOKEN_SERVER_TAG = 313,        // "server-tag"
    TOKEN_STATISTIC_DEFAULT_SAMPLE_COUNT = 314, // "statistic-default-sample-count"
    TOKEN_STATISTIC_DEFAULT_SAMPLE_AGE = 315, // "statistic-default-sample-age"
    TOKEN_DDNS_SEND_UPDATES = 316, // "ddns-send-updates"
    TOKEN_DDNS_OVERRIDE_NO_UPDATE = 317, // "ddns-override-no-update"
    TOKEN_DDNS_OVERRIDE_CLIENT_UPDATE = 318, // "ddns-override-client-update"
    TOKEN_DDNS_REPLACE_CLIENT_NAME = 319, // "ddns-replace-client-name"
    TOKEN_DDNS_GENERATED_PREFIX = 320, // "ddns-generated-prefix"
    TOKEN_DDNS_QUALIFYING_SUFFIX = 321, // "ddns-qualifying-suffix"
    TOKEN_STORE_EXTENDED_INFO = 322, // "store-extended-info"
    TOKEN_SUBNET6 = 323,           // "subnet6"
    TOKEN_OPTION_DEF = 324,        // "option-def"
    TOKEN_OPTION_DATA = 325,       // "option-data"
    TOKEN_NAME = 326,              // "name"
    TOKEN_DATA = 327,              // "data"
    TOKEN_CODE = 328,              // "code"
    TOKEN_SPACE = 329,             // "space"
    TOKEN_CSV_FORMAT = 330,        // "csv-format"
    TOKEN_ALWAYS_SEND = 331,       // "always-send"
    TOKEN_RECORD_TYPES = 332,      // "record-types"
    TOKEN_ENCAPSULATE = 333,       // "encapsulate"
    TOKEN_ARRAY = 334,             // "array"
    TOKEN_POOLS = 335,             // "pools"
    TOKEN_POOL = 336,              // "pool"
    TOKEN_PD_POOLS = 337,          // "pd-pools"
    TOKEN_PREFIX = 338,            // "prefix"
    TOKEN_PREFIX_LEN = 339,        // "prefix-len"
    TOKEN_EXCLUDED_PREFIX = 340,   // "excluded-prefix"
    TOKEN_EXCLUDED_PREFIX_LEN = 341, // "excluded-prefix-len"
    TOKEN_DELEGATED_LEN = 342,     // "delegated-len"
    TOKEN_USER_CONTEXT = 343,      // "user-context"
    TOKEN_COMMENT = 344,           // "comment"
    TOKEN_SUBNET = 345,            // "subnet"
    TOKEN_INTERFACE = 346,         // "interface"
    TOKEN_INTERFACE_ID = 347,      // "interface-id"
    TOKEN_ID = 348,                // "id"
    TOKEN_RAPID_COMMIT = 349,      // "rapid-commit"
    TOKEN_RESERVATION_MODE = 350,  // "reservation-mode"
    TOKEN_DISABLED = 351,          // "disabled"
    TOKEN_OUT_OF_POOL = 352,       // "out-of-pool"
    TOKEN_GLOBAL = 353,            // "global"
    TOKEN_ALL = 354,               // "all"
    TOKEN_SHARED_NETWORKS = 355,   // "shared-networks"
    TOKEN_MAC_SOURCES = 356,       // "mac-sources"
    TOKEN_RELAY_SUPPLIED_OPTIONS = 357, // "relay-supplied-options"
    TOKEN_HOST_RESERVATION_IDENTIFIERS = 358, // "host-reservation-identifiers"
    TOKEN_SANITY_CHECKS = 359,     // "sanity-checks"
    TOKEN_LEASE_CHECKS = 360,      // "lease-checks"
    TOKEN_CLIENT_CLASSES = 361,    // "client-classes"
    TOKEN_REQUIRE_CLIENT_CLASSES = 362, // "require-client-classes"
    TOKEN_TEST = 363,              // "test"
    TOKEN_ONLY_IF_REQUIRED = 364,  // "only-if-required"
    TOKEN_CLIENT_CLASS = 365,      // "client-class"
    TOKEN_RESERVATIONS = 366,      // "reservations"
    TOKEN_IP_ADDRESSES = 367,      // "ip-addresses"
    TOKEN_PREFIXES = 368,          // "prefixes"
    TOKEN_DUID = 369,              // "duid"
    TOKEN_HW_ADDRESS = 370,        // "hw-address"
    TOKEN_HOSTNAME = 371,          // "hostname"
    TOKEN_FLEX_ID = 372,           // "flex-id"
    TOKEN_RELAY = 373,             // "relay"
    TOKEN_IP_ADDRESS = 374,        // "ip-address"
    TOKEN_HOOKS_LIBRARIES = 375,   // "hooks-libraries"
    TOKEN_LIBRARY = 376,           // "library"
    TOKEN_PARAMETERS = 377,        // "parameters"
    TOKEN_EXPIRED_LEASES_PROCESSING = 378, // "expired-leases-processing"
    TOKEN_RECLAIM_TIMER_WAIT_TIME = 379, // "reclaim-timer-wait-time"
    TOKEN_FLUSH_RECLAIMED_TIMER_WAIT_TIME = 380, // "flush-reclaimed-timer-wait-time"
    TOKEN_HOLD_RECLAIMED_TIME = 381, // "hold-reclaimed-time"
    TOKEN_MAX_RECLAIM_LEASES = 382, // "max-reclaim-leases"
    TOKEN_MAX_RECLAIM_TIME = 383,  // "max-reclaim-time"
    TOKEN_UNWARNED_RECLAIM_CYCLES = 384, // "unwarned-reclaim-cycles"
    TOKEN_SERVER_ID = 385,         // "server-id"
    TOKEN_LLT = 386,               // "LLT"
    TOKEN_EN = 387,                // "EN"
    TOKEN_LL = 388,                // "LL"
    TOKEN_IDENTIFIER = 389,        // "identifier"
    TOKEN_HTYPE = 390,             // "htype"
    TOKEN_TIME = 391,              // "time"
    TOKEN_ENTERPRISE_ID = 392,     // "enterprise-id"
    TOKEN_DHCP4O6_PORT = 393,      // "dhcp4o6-port"
    TOKEN_DHCP_MULTI_THREADING = 394, // "multi-threading"
    TOKEN_ENABLE_MULTI_THREADING = 395, // "enable-multi-threading"
    TOKEN_THREAD_POOL_SIZE = 396,  // "thread-pool-size"
    TOKEN_PACKET_QUEUE_SIZE = 397, // "packet-queue-size"
    TOKEN_CONTROL_SOCKET = 398,    // "control-socket"
    TOKEN_SOCKET_TYPE = 399,       // "socket-type"
    TOKEN_SOCKET_NAME = 400,       // "socket-name"
    TOKEN_DHCP_QUEUE_CONTROL = 401, // "dhcp-queue-control"
    TOKEN_ENABLE_QUEUE = 402,      // "enable-queue"
    TOKEN_QUEUE_TYPE = 403,        // "queue-type"
    TOKEN_CAPACITY = 404,          // "capacity"
    TOKEN_DHCP_DDNS = 405,         // "dhcp-ddns"
    TOKEN_ENABLE_UPDATES = 406,    // "enable-updates"
    TOKEN_QUALIFYING_SUFFIX = 407, // "qualifying-suffix"
    TOKEN_SERVER_IP = 408,         // "server-ip"
    TOKEN_SERVER_PORT = 409,       // "server-port"
    TOKEN_SENDER_IP = 410,         // "sender-ip"
    TOKEN_SENDER_PORT = 411,       // "sender-port"
    TOKEN_MAX_QUEUE_SIZE = 412,    // "max-queue-size"
    TOKEN_NCR_PROTOCOL = 413,      // "ncr-protocol"
    TOKEN_NCR_FORMAT = 414,        // "ncr-format"
    TOKEN_OVERRIDE_NO_UPDATE = 415, // "override-no-update"
    TOKEN_OVERRIDE_CLIENT_UPDATE = 416, // "override-client-update"
    TOKEN_REPLACE_CLIENT_NAME = 417, // "replace-client-name"
    TOKEN_GENERATED_PREFIX = 418,  // "generated-prefix"
    TOKEN_UDP = 419,               // "UDP"
    TOKEN_TCP = 420,               // "TCP"
    TOKEN_JSON = 421,              // "JSON"
    TOKEN_WHEN_PRESENT = 422,      // "when-present"
    TOKEN_NEVER = 423,             // "never"
    TOKEN_ALWAYS = 424,            // "always"
    TOKEN_WHEN_NOT_PRESENT = 425,  // "when-not-present"
    TOKEN_HOSTNAME_CHAR_SET = 426, // "hostname-char-set"
    TOKEN_HOSTNAME_CHAR_REPLACEMENT = 427, // "hostname-char-replacement"
    TOKEN_LOGGERS = 428,           // "loggers"
    TOKEN_OUTPUT_OPTIONS = 429,    // "output_options"
    TOKEN_OUTPUT = 430,            // "output"
    TOKEN_DEBUGLEVEL = 431,        // "debuglevel"
    TOKEN_SEVERITY = 432,          // "severity"
    TOKEN_FLUSH = 433,             // "flush"
    TOKEN_MAXSIZE = 434,           // "maxsize"
    TOKEN_MAXVER = 435,            // "maxver"
    TOKEN_PATTERN = 436,           // "pattern"
    TOKEN_TOPLEVEL_JSON = 437,     // TOPLEVEL_JSON
    TOKEN_TOPLEVEL_DHCP6 = 438,    // TOPLEVEL_DHCP6
    TOKEN_SUB_DHCP6 = 439,         // SUB_DHCP6
    TOKEN_SUB_INTERFACES6 = 440,   // SUB_INTERFACES6
    TOKEN_SUB_SUBNET6 = 441,       // SUB_SUBNET6
    TOKEN_SUB_POOL6 = 442,         // SUB_POOL6
    TOKEN_SUB_PD_POOL = 443,       // SUB_PD_POOL
    TOKEN_SUB_RESERVATION = 444,   // SUB_RESERVATION
    TOKEN_SUB_OPTION_DEFS = 445,   // SUB_OPTION_DEFS
    TOKEN_SUB_OPTION_DEF = 446,    // SUB_OPTION_DEF
    TOKEN_SUB_OPTION_DATA = 447,   // SUB_OPTION_DATA
    TOKEN_SUB_HOOKS_LIBRARY = 448, // SUB_HOOKS_LIBRARY
    TOKEN_SUB_DHCP_DDNS = 449,     // SUB_DHCP_DDNS
    TOKEN_SUB_CONFIG_CONTROL = 450, // SUB_CONFIG_CONTROL
    TOKEN_STRING = 451,            // "constant string"
    TOKEN_INTEGER = 452,           // "integer"
    TOKEN_FLOAT = 453,             // "floating point"
    TOKEN_BOOLEAN = 454            // "boolean"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 200, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_COMMA = 3,                             // ","
        S_COLON = 4,                             // ":"
        S_LSQUARE_BRACKET = 5,                   // "["
        S_RSQUARE_BRACKET = 6,                   // "]"
        S_LCURLY_BRACKET = 7,                    // "{"
        S_RCURLY_BRACKET = 8,                    // "}"
        S_NULL_TYPE = 9,                         // "null"
        S_DHCP6 = 10,                            // "Dhcp6"
        S_DATA_DIRECTORY = 11,                   // "data-directory"
        S_CONFIG_CONTROL = 12,                   // "config-control"
        S_CONFIG_DATABASES = 13,                 // "config-databases"
        S_CONFIG_FETCH_WAIT_TIME = 14,           // "config-fetch-wait-time"
        S_INTERFACES_CONFIG = 15,                // "interfaces-config"
        S_INTERFACES = 16,                       // "interfaces"
        S_RE_DETECT = 17,                        // "re-detect"
        S_LEASE_DATABASE = 18,                   // "lease-database"
        S_HOSTS_DATABASE = 19,                   // "hosts-database"
        S_HOSTS_DATABASES = 20,                  // "hosts-databases"
        S_TYPE = 21,                             // "type"
        S_MEMFILE = 22,                          // "memfile"
        S_MYSQL = 23,                            // "mysql"
        S_POSTGRESQL = 24,                       // "postgresql"
        S_CQL = 25,                              // "cql"
        S_USER = 26,                             // "user"
        S_PASSWORD = 27,                         // "password"
        S_HOST = 28,                             // "host"
        S_PORT = 29,                             // "port"
        S_PERSIST = 30,                          // "persist"
        S_LFC_INTERVAL = 31,                     // "lfc-interval"
        S_READONLY = 32,                         // "readonly"
        S_CONNECT_TIMEOUT = 33,                  // "connect-timeout"
        S_CONTACT_POINTS = 34,                   // "contact-points"
        S_MAX_RECONNECT_TRIES = 35,              // "max-reconnect-tries"
        S_RECONNECT_WAIT_TIME = 36,              // "reconnect-wait-time"
        S_KEYSPACE = 37,                         // "keyspace"
        S_CONSISTENCY = 38,                      // "consistency"
        S_SERIAL_CONSISTENCY = 39,               // "serial-consistency"
        S_REQUEST_TIMEOUT = 40,                  // "request-timeout"
        S_TCP_KEEPALIVE = 41,                    // "tcp-keepalive"
        S_TCP_NODELAY = 42,                      // "tcp-nodelay"
        S_MAX_ROW_ERRORS = 43,                   // "max-row-errors"
        S_PREFERRED_LIFETIME = 44,               // "preferred-lifetime"
        S_MIN_PREFERRED_LIFETIME = 45,           // "min-preferred-lifetime"
        S_MAX_PREFERRED_LIFETIME = 46,           // "max-preferred-lifetime"
        S_VALID_LIFETIME = 47,                   // "valid-lifetime"
        S_MIN_VALID_LIFETIME = 48,               // "min-valid-lifetime"
        S_MAX_VALID_LIFETIME = 49,               // "max-valid-lifetime"
        S_RENEW_TIMER = 50,                      // "renew-timer"
        S_REBIND_TIMER = 51,                     // "rebind-timer"
        S_CALCULATE_TEE_TIMES = 52,              // "calculate-tee-times"
        S_T1_PERCENT = 53,                       // "t1-percent"
        S_T2_PERCENT = 54,                       // "t2-percent"
        S_CACHE_THRESHOLD = 55,                  // "cache-threshold"
        S_CACHE_MAX_AGE = 56,                    // "cache-max-age"
        S_DECLINE_PROBATION_PERIOD = 57,         // "decline-probation-period"
        S_SERVER_TAG = 58,                       // "server-tag"
        S_STATISTIC_DEFAULT_SAMPLE_COUNT = 59,   // "statistic-default-sample-count"
        S_STATISTIC_DEFAULT_SAMPLE_AGE = 60,     // "statistic-default-sample-age"
        S_DDNS_SEND_UPDATES = 61,                // "ddns-send-updates"
        S_DDNS_OVERRIDE_NO_UPDATE = 62,          // "ddns-override-no-update"
        S_DDNS_OVERRIDE_CLIENT_UPDATE = 63,      // "ddns-override-client-update"
        S_DDNS_REPLACE_CLIENT_NAME = 64,         // "ddns-replace-client-name"
        S_DDNS_GENERATED_PREFIX = 65,            // "ddns-generated-prefix"
        S_DDNS_QUALIFYING_SUFFIX = 66,           // "ddns-qualifying-suffix"
        S_STORE_EXTENDED_INFO = 67,              // "store-extended-info"
        S_SUBNET6 = 68,                          // "subnet6"
        S_OPTION_DEF = 69,                       // "option-def"
        S_OPTION_DATA = 70,                      // "option-data"
        S_NAME = 71,                             // "name"
        S_DATA = 72,                             // "data"
        S_CODE = 73,                             // "code"
        S_SPACE = 74,                            // "space"
        S_CSV_FORMAT = 75,                       // "csv-format"
        S_ALWAYS_SEND = 76,                      // "always-send"
        S_RECORD_TYPES = 77,                     // "record-types"
        S_ENCAPSULATE = 78,                      // "encapsulate"
        S_ARRAY = 79,                            // "array"
        S_POOLS = 80,                            // "pools"
        S_POOL = 81,                             // "pool"
        S_PD_POOLS = 82,                         // "pd-pools"
        S_PREFIX = 83,                           // "prefix"
        S_PREFIX_LEN = 84,                       // "prefix-len"
        S_EXCLUDED_PREFIX = 85,                  // "excluded-prefix"
        S_EXCLUDED_PREFIX_LEN = 86,              // "excluded-prefix-len"
        S_DELEGATED_LEN = 87,                    // "delegated-len"
        S_USER_CONTEXT = 88,                     // "user-context"
        S_COMMENT = 89,                          // "comment"
        S_SUBNET = 90,                           // "subnet"
        S_INTERFACE = 91,                        // "interface"
        S_INTERFACE_ID = 92,                     // "interface-id"
        S_ID = 93,                               // "id"
        S_RAPID_COMMIT = 94,                     // "rapid-commit"
        S_RESERVATION_MODE = 95,                 // "reservation-mode"
        S_DISABLED = 96,                         // "disabled"
        S_OUT_OF_POOL = 97,                      // "out-of-pool"
        S_GLOBAL = 98,                           // "global"
        S_ALL = 99,                              // "all"
        S_SHARED_NETWORKS = 100,                 // "shared-networks"
        S_MAC_SOURCES = 101,                     // "mac-sources"
        S_RELAY_SUPPLIED_OPTIONS = 102,          // "relay-supplied-options"
        S_HOST_RESERVATION_IDENTIFIERS = 103,    // "host-reservation-identifiers"
        S_SANITY_CHECKS = 104,                   // "sanity-checks"
        S_LEASE_CHECKS = 105,                    // "lease-checks"
        S_CLIENT_CLASSES = 106,                  // "client-classes"
        S_REQUIRE_CLIENT_CLASSES = 107,          // "require-client-classes"
        S_TEST = 108,                            // "test"
        S_ONLY_IF_REQUIRED = 109,                // "only-if-required"
        S_CLIENT_CLASS = 110,                    // "client-class"
        S_RESERVATIONS = 111,                    // "reservations"
        S_IP_ADDRESSES = 112,                    // "ip-addresses"
        S_PREFIXES = 113,                        // "prefixes"
        S_DUID = 114,                            // "duid"
        S_HW_ADDRESS = 115,                      // "hw-address"
        S_HOSTNAME = 116,                        // "hostname"
        S_FLEX_ID = 117,                         // "flex-id"
        S_RELAY = 118,                           // "relay"
        S_IP_ADDRESS = 119,                      // "ip-address"
        S_HOOKS_LIBRARIES = 120,                 // "hooks-libraries"
        S_LIBRARY = 121,                         // "library"
        S_PARAMETERS = 122,                      // "parameters"
        S_EXPIRED_LEASES_PROCESSING = 123,       // "expired-leases-processing"
        S_RECLAIM_TIMER_WAIT_TIME = 124,         // "reclaim-timer-wait-time"
        S_FLUSH_RECLAIMED_TIMER_WAIT_TIME = 125, // "flush-reclaimed-timer-wait-time"
        S_HOLD_RECLAIMED_TIME = 126,             // "hold-reclaimed-time"
        S_MAX_RECLAIM_LEASES = 127,              // "max-reclaim-leases"
        S_MAX_RECLAIM_TIME = 128,                // "max-reclaim-time"
        S_UNWARNED_RECLAIM_CYCLES = 129,         // "unwarned-reclaim-cycles"
        S_SERVER_ID = 130,                       // "server-id"
        S_LLT = 131,                             // "LLT"
        S_EN = 132,                              // "EN"
        S_LL = 133,                              // "LL"
        S_IDENTIFIER = 134,                      // "identifier"
        S_HTYPE = 135,                           // "htype"
        S_TIME = 136,                            // "time"
        S_ENTERPRISE_ID = 137,                   // "enterprise-id"
        S_DHCP4O6_PORT = 138,                    // "dhcp4o6-port"
        S_DHCP_MULTI_THREADING = 139,            // "multi-threading"
        S_ENABLE_MULTI_THREADING = 140,          // "enable-multi-threading"
        S_THREAD_POOL_SIZE = 141,                // "thread-pool-size"
        S_PACKET_QUEUE_SIZE = 142,               // "packet-queue-size"
        S_CONTROL_SOCKET = 143,                  // "control-socket"
        S_SOCKET_TYPE = 144,                     // "socket-type"
        S_SOCKET_NAME = 145,                     // "socket-name"
        S_DHCP_QUEUE_CONTROL = 146,              // "dhcp-queue-control"
        S_ENABLE_QUEUE = 147,                    // "enable-queue"
        S_QUEUE_TYPE = 148,                      // "queue-type"
        S_CAPACITY = 149,                        // "capacity"
        S_DHCP_DDNS = 150,                       // "dhcp-ddns"
        S_ENABLE_UPDATES = 151,                  // "enable-updates"
        S_QUALIFYING_SUFFIX = 152,               // "qualifying-suffix"
        S_SERVER_IP = 153,                       // "server-ip"
        S_SERVER_PORT = 154,                     // "server-port"
        S_SENDER_IP = 155,                       // "sender-ip"
        S_SENDER_PORT = 156,                     // "sender-port"
        S_MAX_QUEUE_SIZE = 157,                  // "max-queue-size"
        S_NCR_PROTOCOL = 158,                    // "ncr-protocol"
        S_NCR_FORMAT = 159,                      // "ncr-format"
        S_OVERRIDE_NO_UPDATE = 160,              // "override-no-update"
        S_OVERRIDE_CLIENT_UPDATE = 161,          // "override-client-update"
        S_REPLACE_CLIENT_NAME = 162,             // "replace-client-name"
        S_GENERATED_PREFIX = 163,                // "generated-prefix"
        S_UDP = 164,                             // "UDP"
        S_TCP = 165,                             // "TCP"
        S_JSON = 166,                            // "JSON"
        S_WHEN_PRESENT = 167,                    // "when-present"
        S_NEVER = 168,                           // "never"
        S_ALWAYS = 169,                          // "always"
        S_WHEN_NOT_PRESENT = 170,                // "when-not-present"
        S_HOSTNAME_CHAR_SET = 171,               // "hostname-char-set"
        S_HOSTNAME_CHAR_REPLACEMENT = 172,       // "hostname-char-replacement"
        S_LOGGERS = 173,                         // "loggers"
        S_OUTPUT_OPTIONS = 174,                  // "output_options"
        S_OUTPUT = 175,                          // "output"
        S_DEBUGLEVEL = 176,                      // "debuglevel"
        S_SEVERITY = 177,                        // "severity"
        S_FLUSH = 178,                           // "flush"
        S_MAXSIZE = 179,                         // "maxsize"
        S_MAXVER = 180,                          // "maxver"
        S_PATTERN = 181,                         // "pattern"
        S_TOPLEVEL_JSON = 182,                   // TOPLEVEL_JSON
        S_TOPLEVEL_DHCP6 = 183,                  // TOPLEVEL_DHCP6
        S_SUB_DHCP6 = 184,                       // SUB_DHCP6
        S_SUB_INTERFACES6 = 185,                 // SUB_INTERFACES6
        S_SUB_SUBNET6 = 186,                     // SUB_SUBNET6
        S_SUB_POOL6 = 187,                       // SUB_POOL6
        S_SUB_PD_POOL = 188,                     // SUB_PD_POOL
        S_SUB_RESERVATION = 189,                 // SUB_RESERVATION
        S_SUB_OPTION_DEFS = 190,                 // SUB_OPTION_DEFS
        S_SUB_OPTION_DEF = 191,                  // SUB_OPTION_DEF
        S_SUB_OPTION_DATA = 192,                 // SUB_OPTION_DATA
        S_SUB_HOOKS_LIBRARY = 193,               // SUB_HOOKS_LIBRARY
        S_SUB_DHCP_DDNS = 194,                   // SUB_DHCP_DDNS
        S_SUB_CONFIG_CONTROL = 195,              // SUB_CONFIG_CONTROL
        S_STRING = 196,                          // "constant string"
        S_INTEGER = 197,                         // "integer"
        S_FLOAT = 198,                           // "floating point"
        S_BOOLEAN = 199,                         // "boolean"
        S_YYACCEPT = 200,                        // $accept
        S_start = 201,                           // start
        S_202_1 = 202,                           // $@1
        S_203_2 = 203,                           // $@2
        S_204_3 = 204,                           // $@3
        S_205_4 = 205,                           // $@4
        S_206_5 = 206,                           // $@5
        S_207_6 = 207,                           // $@6
        S_208_7 = 208,                           // $@7
        S_209_8 = 209,                           // $@8
        S_210_9 = 210,                           // $@9
        S_211_10 = 211,                          // $@10
        S_212_11 = 212,                          // $@11
        S_213_12 = 213,                          // $@12
        S_214_13 = 214,                          // $@13
        S_215_14 = 215,                          // $@14
        S_value = 216,                           // value
        S_sub_json = 217,                        // sub_json
        S_map2 = 218,                            // map2
        S_219_15 = 219,                          // $@15
        S_map_value = 220,                       // map_value
        S_map_content = 221,                     // map_content
        S_not_empty_map = 222,                   // not_empty_map
        S_list_generic = 223,                    // list_generic
        S_224_16 = 224,                          // $@16
        S_list_content = 225,                    // list_content
        S_not_empty_list = 226,                  // not_empty_list
        S_list_strings = 227,                    // list_strings
        S_228_17 = 228,                          // $@17
        S_list_strings_content = 229,            // list_strings_content
        S_not_empty_list_strings = 230,          // not_empty_list_strings
        S_unknown_map_entry = 231,               // unknown_map_entry
        S_syntax_map = 232,                      // syntax_map
        S_233_18 = 233,                          // $@18
        S_global_object = 234,                   // global_object
        S_235_19 = 235,                          // $@19
        S_sub_dhcp6 = 236,                       // sub_dhcp6
        S_237_20 = 237,                          // $@20
        S_global_params = 238,                   // global_params
        S_global_param = 239,                    // global_param
        S_data_directory = 240,                  // data_directory
        S_241_21 = 241,                          // $@21
        S_preferred_lifetime = 242,              // preferred_lifetime
        S_min_preferred_lifetime = 243,          // min_preferred_lifetime
        S_max_preferred_lifetime = 244,          // max_preferred_lifetime
        S_valid_lifetime = 245,                  // valid_lifetime
        S_min_valid_lifetime = 246,              // min_valid_lifetime
        S_max_valid_lifetime = 247,              // max_valid_lifetime
        S_renew_timer = 248,                     // renew_timer
        S_rebind_timer = 249,                    // rebind_timer
        S_calculate_tee_times = 250,             // calculate_tee_times
        S_t1_percent = 251,                      // t1_percent
        S_t2_percent = 252,                      // t2_percent
        S_cache_threshold = 253,                 // cache_threshold
        S_cache_max_age = 254,                   // cache_max_age
        S_decline_probation_period = 255,        // decline_probation_period
        S_ddns_send_updates = 256,               // ddns_send_updates
        S_ddns_override_no_update = 257,         // ddns_override_no_update
        S_ddns_override_client_update = 258,     // ddns_override_client_update
        S_ddns_replace_client_name = 259,        // ddns_replace_client_name
        S_260_22 = 260,                          // $@22
        S_ddns_replace_client_name_value = 261,  // ddns_replace_client_name_value
        S_ddns_generated_prefix = 262,           // ddns_generated_prefix
        S_263_23 = 263,                          // $@23
        S_ddns_qualifying_suffix = 264,          // ddns_qualifying_suffix
        S_265_24 = 265,                          // $@24
        S_hostname_char_set = 266,               // hostname_char_set
        S_267_25 = 267,                          // $@25
        S_hostname_char_replacement = 268,       // hostname_char_replacement
        S_269_26 = 269,                          // $@26
        S_store_extended_info = 270,             // store_extended_info
        S_statistic_default_sample_count = 271,  // statistic_default_sample_count
        S_statistic_default_sample_age = 272,    // statistic_default_sample_age
        S_server_tag = 273,                      // server_tag
        S_274_27 = 274,                          // $@27
        S_interfaces_config = 275,               // interfaces_config
        S_276_28 = 276,                          // $@28
        S_sub_interfaces6 = 277,                 // sub_interfaces6
        S_278_29 = 278,                          // $@29
        S_interfaces_config_params = 279,        // interfaces_config_params
        S_interfaces_config_param = 280,         // interfaces_config_param
        S_interfaces_list = 281,                 // interfaces_list
        S_282_30 = 282,                          // $@30
        S_re_detect = 283,                       // re_detect
        S_lease_database = 284,                  // lease_database
        S_285_31 = 285,                          // $@31
        S_hosts_database = 286,                  // hosts_database
        S_287_32 = 287,                          // $@32
        S_hosts_databases = 288,                 // hosts_databases
        S_289_33 = 289,                          // $@33
        S_database_list = 290,                   // database_list
        S_not_empty_database_list = 291,         // not_empty_database_list
        S_database = 292,                        // database
        S_293_34 = 293,                          // $@34
        S_database_map_params = 294,             // database_map_params
        S_database_map_param = 295,              // database_map_param
        S_database_type = 296,                   // database_type
        S_297_35 = 297,                          // $@35
        S_db_type = 298,                         // db_type
        S_user = 299,                            // user
        S_300_36 = 300,                          // $@36
        S_password = 301,                        // password
        S_302_37 = 302,                          // $@37
        S_host = 303,                            // host
        S_304_38 = 304,                          // $@38
        S_port = 305,                            // port
        S_name = 306,                            // name
        S_307_39 = 307,                          // $@39
        S_persist = 308,                         // persist
        S_lfc_interval = 309,                    // lfc_interval
        S_readonly = 310,                        // readonly
        S_connect_timeout = 311,                 // connect_timeout
        S_reconnect_wait_time = 312,             // reconnect_wait_time
        S_max_row_errors = 313,                  // max_row_errors
        S_request_timeout = 314,                 // request_timeout
        S_tcp_keepalive = 315,                   // tcp_keepalive
        S_tcp_nodelay = 316,                     // tcp_nodelay
        S_contact_points = 317,                  // contact_points
        S_318_40 = 318,                          // $@40
        S_max_reconnect_tries = 319,             // max_reconnect_tries
        S_keyspace = 320,                        // keyspace
        S_321_41 = 321,                          // $@41
        S_consistency = 322,                     // consistency
        S_323_42 = 323,                          // $@42
        S_serial_consistency = 324,              // serial_consistency
        S_325_43 = 325,                          // $@43
        S_sanity_checks = 326,                   // sanity_checks
        S_327_44 = 327,                          // $@44
        S_sanity_checks_params = 328,            // sanity_checks_params
        S_sanity_checks_param = 329,             // sanity_checks_param
        S_lease_checks = 330,                    // lease_checks
        S_331_45 = 331,                          // $@45
        S_mac_sources = 332,                     // mac_sources
        S_333_46 = 333,                          // $@46
        S_mac_sources_list = 334,                // mac_sources_list
        S_mac_sources_value = 335,               // mac_sources_value
        S_duid_id = 336,                         // duid_id
        S_string_id = 337,                       // string_id
        S_host_reservation_identifiers = 338,    // host_reservation_identifiers
        S_339_47 = 339,                          // $@47
        S_host_reservation_identifiers_list = 340, // host_reservation_identifiers_list
        S_host_reservation_identifier = 341,     // host_reservation_identifier
        S_hw_address_id = 342,                   // hw_address_id
        S_flex_id = 343,                         // flex_id
        S_relay_supplied_options = 344,          // relay_supplied_options
        S_345_48 = 345,                          // $@48
        S_dhcp_multi_threading = 346,            // dhcp_multi_threading
        S_347_49 = 347,                          // $@49
        S_multi_threading_params = 348,          // multi_threading_params
        S_multi_threading_param = 349,           // multi_threading_param
        S_enable_multi_threading = 350,          // enable_multi_threading
        S_thread_pool_size = 351,                // thread_pool_size
        S_packet_queue_size = 352,               // packet_queue_size
        S_hooks_libraries = 353,                 // hooks_libraries
        S_354_50 = 354,                          // $@50
        S_hooks_libraries_list = 355,            // hooks_libraries_list
        S_not_empty_hooks_libraries_list = 356,  // not_empty_hooks_libraries_list
        S_hooks_library = 357,                   // hooks_library
        S_358_51 = 358,                          // $@51
        S_sub_hooks_library = 359,               // sub_hooks_library
        S_360_52 = 360,                          // $@52
        S_hooks_params = 361,                    // hooks_params
        S_hooks_param = 362,                     // hooks_param
        S_library = 363,                         // library
        S_364_53 = 364,                          // $@53
        S_parameters = 365,                      // parameters
        S_366_54 = 366,                          // $@54
        S_expired_leases_processing = 367,       // expired_leases_processing
        S_368_55 = 368,                          // $@55
        S_expired_leases_params = 369,           // expired_leases_params
        S_expired_leases_param = 370,            // expired_leases_param
        S_reclaim_timer_wait_time = 371,         // reclaim_timer_wait_time
        S_flush_reclaimed_timer_wait_time = 372, // flush_reclaimed_timer_wait_time
        S_hold_reclaimed_time = 373,             // hold_reclaimed_time
        S_max_reclaim_leases = 374,              // max_reclaim_leases
        S_max_reclaim_time = 375,                // max_reclaim_time
        S_unwarned_reclaim_cycles = 376,         // unwarned_reclaim_cycles
        S_subnet6_list = 377,                    // subnet6_list
        S_378_56 = 378,                          // $@56
        S_subnet6_list_content = 379,            // subnet6_list_content
        S_not_empty_subnet6_list = 380,          // not_empty_subnet6_list
        S_subnet6 = 381,                         // subnet6
        S_382_57 = 382,                          // $@57
        S_sub_subnet6 = 383,                     // sub_subnet6
        S_384_58 = 384,                          // $@58
        S_subnet6_params = 385,                  // subnet6_params
        S_subnet6_param = 386,                   // subnet6_param
        S_subnet = 387,                          // subnet
        S_388_59 = 388,                          // $@59
        S_interface = 389,                       // interface
        S_390_60 = 390,                          // $@60
        S_interface_id = 391,                    // interface_id
        S_392_61 = 392,                          // $@61
        S_client_class = 393,                    // client_class
        S_394_62 = 394,                          // $@62
        S_require_client_classes = 395,          // require_client_classes
        S_396_63 = 396,                          // $@63
        S_reservation_mode = 397,                // reservation_mode
        S_398_64 = 398,                          // $@64
        S_hr_mode = 399,                         // hr_mode
        S_id = 400,                              // id
        S_rapid_commit = 401,                    // rapid_commit
        S_shared_networks = 402,                 // shared_networks
        S_403_65 = 403,                          // $@65
        S_shared_networks_content = 404,         // shared_networks_content
        S_shared_networks_list = 405,            // shared_networks_list
        S_shared_network = 406,                  // shared_network
        S_407_66 = 407,                          // $@66
        S_shared_network_params = 408,           // shared_network_params
        S_shared_network_param = 409,            // shared_network_param
        S_option_def_list = 410,                 // option_def_list
        S_411_67 = 411,                          // $@67
        S_sub_option_def_list = 412,             // sub_option_def_list
        S_413_68 = 413,                          // $@68
        S_option_def_list_content = 414,         // option_def_list_content
        S_not_empty_option_def_list = 415,       // not_empty_option_def_list
        S_option_def_entry = 416,                // option_def_entry
        S_417_69 = 417,                          // $@69
        S_sub_option_def = 418,                  // sub_option_def
        S_419_70 = 419,                          // $@70
        S_option_def_params = 420,               // option_def_params
        S_not_empty_option_def_params = 421,     // not_empty_option_def_params
        S_option_def_param = 422,                // option_def_param
        S_option_def_name = 423,                 // option_def_name
        S_code = 424,                            // code
        S_option_def_code = 425,                 // option_def_code
        S_option_def_type = 426,                 // option_def_type
        S_427_71 = 427,                          // $@71
        S_option_def_record_types = 428,         // option_def_record_types
        S_429_72 = 429,                          // $@72
        S_space = 430,                           // space
        S_431_73 = 431,                          // $@73
        S_option_def_space = 432,                // option_def_space
        S_option_def_encapsulate = 433,          // option_def_encapsulate
        S_434_74 = 434,                          // $@74
        S_option_def_array = 435,                // option_def_array
        S_option_data_list = 436,                // option_data_list
        S_437_75 = 437,                          // $@75
        S_option_data_list_content = 438,        // option_data_list_content
        S_not_empty_option_data_list = 439,      // not_empty_option_data_list
        S_option_data_entry = 440,               // option_data_entry
        S_441_76 = 441,                          // $@76
        S_sub_option_data = 442,                 // sub_option_data
        S_443_77 = 443,                          // $@77
        S_option_data_params = 444,              // option_data_params
        S_not_empty_option_data_params = 445,    // not_empty_option_data_params
        S_option_data_param = 446,               // option_data_param
        S_option_data_name = 447,                // option_data_name
        S_option_data_data = 448,                // option_data_data
        S_449_78 = 449,                          // $@78
        S_option_data_code = 450,                // option_data_code
        S_option_data_space = 451,               // option_data_space
        S_option_data_csv_format = 452,          // option_data_csv_format
        S_option_data_always_send = 453,         // option_data_always_send
        S_pools_list = 454,                      // pools_list
        S_455_79 = 455,                          // $@79
        S_pools_list_content = 456,              // pools_list_content
        S_not_empty_pools_list = 457,            // not_empty_pools_list
        S_pool_list_entry = 458,                 // pool_list_entry
        S_459_80 = 459,                          // $@80
        S_sub_pool6 = 460,                       // sub_pool6
        S_461_81 = 461,                          // $@81
        S_pool_params = 462,                     // pool_params
        S_pool_param = 463,                      // pool_param
        S_pool_entry = 464,                      // pool_entry
        S_465_82 = 465,                          // $@82
        S_user_context = 466,                    // user_context
        S_467_83 = 467,                          // $@83
        S_comment = 468,                         // comment
        S_469_84 = 469,                          // $@84
        S_pd_pools_list = 470,                   // pd_pools_list
        S_471_85 = 471,                          // $@85
        S_pd_pools_list_content = 472,           // pd_pools_list_content
        S_not_empty_pd_pools_list = 473,         // not_empty_pd_pools_list
        S_pd_pool_entry = 474,                   // pd_pool_entry
        S_475_86 = 475,                          // $@86
        S_sub_pd_pool = 476,                     // sub_pd_pool
        S_477_87 = 477,                          // $@87
        S_pd_pool_params = 478,                  // pd_pool_params
        S_pd_pool_param = 479,                   // pd_pool_param
        S_pd_prefix = 480,                       // pd_prefix
        S_481_88 = 481,                          // $@88
        S_pd_prefix_len = 482,                   // pd_prefix_len
        S_excluded_prefix = 483,                 // excluded_prefix
        S_484_89 = 484,                          // $@89
        S_excluded_prefix_len = 485,             // excluded_prefix_len
        S_pd_delegated_len = 486,                // pd_delegated_len
        S_reservations = 487,                    // reservations
        S_488_90 = 488,                          // $@90
        S_reservations_list = 489,               // reservations_list
        S_not_empty_reservations_list = 490,     // not_empty_reservations_list
        S_reservation = 491,                     // reservation
        S_492_91 = 492,                          // $@91
        S_sub_reservation = 493,                 // sub_reservation
        S_494_92 = 494,                          // $@92
        S_reservation_params = 495,              // reservation_params
        S_not_empty_reservation_params = 496,    // not_empty_reservation_params
        S_reservation_param = 497,               // reservation_param
        S_ip_addresses = 498,                    // ip_addresses
        S_499_93 = 499,                          // $@93
        S_prefixes = 500,                        // prefixes
        S_501_94 = 501,                          // $@94
        S_duid = 502,                            // duid
        S_503_95 = 503,                          // $@95
        S_hw_address = 504,                      // hw_address
        S_505_96 = 505,                          // $@96
        S_hostname = 506,                        // hostname
        S_507_97 = 507,                          // $@97
        S_flex_id_value = 508,                   // flex_id_value
        S_509_98 = 509,                          // $@98
        S_reservation_client_classes = 510,      // reservation_client_classes
        S_511_99 = 511,                          // $@99
        S_relay = 512,                           // relay
        S_513_100 = 513,                         // $@100
        S_relay_map = 514,                       // relay_map
        S_ip_address = 515,                      // ip_address
        S_516_101 = 516,                         // $@101
        S_client_classes = 517,                  // client_classes
        S_518_102 = 518,                         // $@102
        S_client_classes_list = 519,             // client_classes_list
        S_client_class_entry = 520,              // client_class_entry
        S_521_103 = 521,                         // $@103
        S_client_class_params = 522,             // client_class_params
        S_not_empty_client_class_params = 523,   // not_empty_client_class_params
        S_client_class_param = 524,              // client_class_param
        S_client_class_name = 525,               // client_class_name
        S_client_class_test = 526,               // client_class_test
        S_527_104 = 527,                         // $@104
        S_only_if_required = 528,                // only_if_required
        S_server_id = 529,                       // server_id
        S_530_105 = 530,                         // $@105
        S_server_id_params = 531,                // server_id_params
        S_server_id_param = 532,                 // server_id_param
        S_server_id_type = 533,                  // server_id_type
        S_534_106 = 534,                         // $@106
        S_duid_type = 535,                       // duid_type
        S_htype = 536,                           // htype
        S_identifier = 537,                      // identifier
        S_538_107 = 538,                         // $@107
        S_time = 539,                            // time
        S_enterprise_id = 540,                   // enterprise_id
        S_dhcp4o6_port = 541,                    // dhcp4o6_port
        S_control_socket = 542,                  // control_socket
        S_543_108 = 543,                         // $@108
        S_control_socket_params = 544,           // control_socket_params
        S_control_socket_param = 545,            // control_socket_param
        S_socket_type = 546,                     // socket_type
        S_547_109 = 547,                         // $@109
        S_socket_name = 548,                     // socket_name
        S_549_110 = 549,                         // $@110
        S_dhcp_queue_control = 550,              // dhcp_queue_control
        S_551_111 = 551,                         // $@111
        S_queue_control_params = 552,            // queue_control_params
        S_queue_control_param = 553,             // queue_control_param
        S_enable_queue = 554,                    // enable_queue
        S_queue_type = 555,                      // queue_type
        S_556_112 = 556,                         // $@112
        S_capacity = 557,                        // capacity
        S_arbitrary_map_entry = 558,             // arbitrary_map_entry
        S_559_113 = 559,                         // $@113
        S_dhcp_ddns = 560,                       // dhcp_ddns
        S_561_114 = 561,                         // $@114
        S_sub_dhcp_ddns = 562,                   // sub_dhcp_ddns
        S_563_115 = 563,                         // $@115
        S_dhcp_ddns_params = 564,                // dhcp_ddns_params
        S_dhcp_ddns_param = 565,                 // dhcp_ddns_param
        S_enable_updates = 566,                  // enable_updates
        S_dep_qualifying_suffix = 567,           // dep_qualifying_suffix
        S_568_116 = 568,                         // $@116
        S_server_ip = 569,                       // server_ip
        S_570_117 = 570,                         // $@117
        S_server_port = 571,                     // server_port
        S_sender_ip = 572,                       // sender_ip
        S_573_118 = 573,                         // $@118
        S_sender_port = 574,                     // sender_port
        S_max_queue_size = 575,                  // max_queue_size
        S_ncr_protocol = 576,                    // ncr_protocol
        S_577_119 = 577,                         // $@119
        S_ncr_protocol_value = 578,              // ncr_protocol_value
        S_ncr_format = 579,                      // ncr_format
        S_580_120 = 580,                         // $@120
        S_dep_override_no_update = 581,          // dep_override_no_update
        S_dep_override_client_update = 582,      // dep_override_client_update
        S_dep_replace_client_name = 583,         // dep_replace_client_name
        S_584_121 = 584,                         // $@121
        S_dep_generated_prefix = 585,            // dep_generated_prefix
        S_586_122 = 586,                         // $@122
        S_dep_hostname_char_set = 587,           // dep_hostname_char_set
        S_588_123 = 588,                         // $@123
        S_dep_hostname_char_replacement = 589,   // dep_hostname_char_replacement
        S_590_124 = 590,                         // $@124
        S_config_control = 591,                  // config_control
        S_592_125 = 592,                         // $@125
        S_sub_config_control = 593,              // sub_config_control
        S_594_126 = 594,                         // $@126
        S_config_control_params = 595,           // config_control_params
        S_config_control_param = 596,            // config_control_param
        S_config_databases = 597,                // config_databases
        S_598_127 = 598,                         // $@127
        S_config_fetch_wait_time = 599,          // config_fetch_wait_time
        S_loggers = 600,                         // loggers
        S_601_128 = 601,                         // $@128
        S_loggers_entries = 602,                 // loggers_entries
        S_logger_entry = 603,                    // logger_entry
        S_604_129 = 604,                         // $@129
        S_logger_params = 605,                   // logger_params
        S_logger_param = 606,                    // logger_param
        S_debuglevel = 607,                      // debuglevel
        S_severity = 608,                        // severity
        S_609_130 = 609,                         // $@130
        S_output_options_list = 610,             // output_options_list
        S_611_131 = 611,                         // $@131
        S_output_options_list_content = 612,     // output_options_list_content
        S_output_entry = 613,                    // output_entry
        S_614_132 = 614,                         // $@132
        S_output_params_list = 615,              // output_params_list
        S_output_params = 616,                   // output_params
        S_output = 617,                          // output
        S_618_133 = 618,                         // $@133
        S_flush = 619,                           // flush
        S_maxsize = 620,                         // maxsize
        S_maxver = 621,                          // maxver
        S_pattern = 622,                         // pattern
        S_623_134 = 623                          // $@134
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (std::move (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ElementPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ElementPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int64_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int64_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.template destroy< ElementPtr > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.template destroy< double > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Dhcp6Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_PARSER6_error || tok == token::TOKEN_PARSER6_UNDEF || tok == token::TOKEN_COMMA || tok == token::TOKEN_COLON || tok == token::TOKEN_LSQUARE_BRACKET || tok == token::TOKEN_RSQUARE_BRACKET || tok == token::TOKEN_LCURLY_BRACKET || tok == token::TOKEN_RCURLY_BRACKET || tok == token::TOKEN_NULL_TYPE || tok == token::TOKEN_DHCP6 || tok == token::TOKEN_DATA_DIRECTORY || tok == token::TOKEN_CONFIG_CONTROL || tok == token::TOKEN_CONFIG_DATABASES || tok == token::TOKEN_CONFIG_FETCH_WAIT_TIME || tok == token::TOKEN_INTERFACES_CONFIG || tok == token::TOKEN_INTERFACES || tok == token::TOKEN_RE_DETECT || tok == token::TOKEN_LEASE_DATABASE || tok == token::TOKEN_HOSTS_DATABASE || tok == token::TOKEN_HOSTS_DATABASES || tok == token::TOKEN_TYPE || tok == token::TOKEN_MEMFILE || tok == token::TOKEN_MYSQL || tok == token::TOKEN_POSTGRESQL || tok == token::TOKEN_CQL || tok == token::TOKEN_USER || tok == token::TOKEN_PASSWORD || tok == token::TOKEN_HOST || tok == token::TOKEN_PORT || tok == token::TOKEN_PERSIST || tok == token::TOKEN_LFC_INTERVAL || tok == token::TOKEN_READONLY || tok == token::TOKEN_CONNECT_TIMEOUT || tok == token::TOKEN_CONTACT_POINTS || tok == token::TOKEN_MAX_RECONNECT_TRIES || tok == token::TOKEN_RECONNECT_WAIT_TIME || tok == token::TOKEN_KEYSPACE || tok == token::TOKEN_CONSISTENCY || tok == token::TOKEN_SERIAL_CONSISTENCY || tok == token::TOKEN_REQUEST_TIMEOUT || tok == token::TOKEN_TCP_KEEPALIVE || tok == token::TOKEN_TCP_NODELAY || tok == token::TOKEN_MAX_ROW_ERRORS || tok == token::TOKEN_PREFERRED_LIFETIME || tok == token::TOKEN_MIN_PREFERRED_LIFETIME || tok == token::TOKEN_MAX_PREFERRED_LIFETIME || tok == token::TOKEN_VALID_LIFETIME || tok == token::TOKEN_MIN_VALID_LIFETIME || tok == token::TOKEN_MAX_VALID_LIFETIME || tok == token::TOKEN_RENEW_TIMER || tok == token::TOKEN_REBIND_TIMER || tok == token::TOKEN_CALCULATE_TEE_TIMES || tok == token::TOKEN_T1_PERCENT || tok == token::TOKEN_T2_PERCENT || tok == token::TOKEN_CACHE_THRESHOLD || tok == token::TOKEN_CACHE_MAX_AGE || tok == token::TOKEN_DECLINE_PROBATION_PERIOD || tok == token::TOKEN_SERVER_TAG || tok == token::TOKEN_STATISTIC_DEFAULT_SAMPLE_COUNT || tok == token::TOKEN_STATISTIC_DEFAULT_SAMPLE_AGE || tok == token::TOKEN_DDNS_SEND_UPDATES || tok == token::TOKEN_DDNS_OVERRIDE_NO_UPDATE || tok == token::TOKEN_DDNS_OVERRIDE_CLIENT_UPDATE || tok == token::TOKEN_DDNS_REPLACE_CLIENT_NAME || tok == token::TOKEN_DDNS_GENERATED_PREFIX || tok == token::TOKEN_DDNS_QUALIFYING_SUFFIX || tok == token::TOKEN_STORE_EXTENDED_INFO || tok == token::TOKEN_SUBNET6 || tok == token::TOKEN_OPTION_DEF || tok == token::TOKEN_OPTION_DATA || tok == token::TOKEN_NAME || tok == token::TOKEN_DATA || tok == token::TOKEN_CODE || tok == token::TOKEN_SPACE || tok == token::TOKEN_CSV_FORMAT || tok == token::TOKEN_ALWAYS_SEND || tok == token::TOKEN_RECORD_TYPES || tok == token::TOKEN_ENCAPSULATE || tok == token::TOKEN_ARRAY || tok == token::TOKEN_POOLS || tok == token::TOKEN_POOL || tok == token::TOKEN_PD_POOLS || tok == token::TOKEN_PREFIX || tok == token::TOKEN_PREFIX_LEN || tok == token::TOKEN_EXCLUDED_PREFIX || tok == token::TOKEN_EXCLUDED_PREFIX_LEN || tok == token::TOKEN_DELEGATED_LEN || tok == token::TOKEN_USER_CONTEXT || tok == token::TOKEN_COMMENT || tok == token::TOKEN_SUBNET || tok == token::TOKEN_INTERFACE || tok == token::TOKEN_INTERFACE_ID || tok == token::TOKEN_ID || tok == token::TOKEN_RAPID_COMMIT || tok == token::TOKEN_RESERVATION_MODE || tok == token::TOKEN_DISABLED || tok == token::TOKEN_OUT_OF_POOL || tok == token::TOKEN_GLOBAL || tok == token::TOKEN_ALL || tok == token::TOKEN_SHARED_NETWORKS || tok == token::TOKEN_MAC_SOURCES || tok == token::TOKEN_RELAY_SUPPLIED_OPTIONS || tok == token::TOKEN_HOST_RESERVATION_IDENTIFIERS || tok == token::TOKEN_SANITY_CHECKS || tok == token::TOKEN_LEASE_CHECKS || tok == token::TOKEN_CLIENT_CLASSES || tok == token::TOKEN_REQUIRE_CLIENT_CLASSES || tok == token::TOKEN_TEST || tok == token::TOKEN_ONLY_IF_REQUIRED || tok == token::TOKEN_CLIENT_CLASS || tok == token::TOKEN_RESERVATIONS || tok == token::TOKEN_IP_ADDRESSES || tok == token::TOKEN_PREFIXES || tok == token::TOKEN_DUID || tok == token::TOKEN_HW_ADDRESS || tok == token::TOKEN_HOSTNAME || tok == token::TOKEN_FLEX_ID || tok == token::TOKEN_RELAY || tok == token::TOKEN_IP_ADDRESS || tok == token::TOKEN_HOOKS_LIBRARIES || tok == token::TOKEN_LIBRARY || tok == token::TOKEN_PARAMETERS || tok == token::TOKEN_EXPIRED_LEASES_PROCESSING || tok == token::TOKEN_RECLAIM_TIMER_WAIT_TIME || tok == token::TOKEN_FLUSH_RECLAIMED_TIMER_WAIT_TIME || tok == token::TOKEN_HOLD_RECLAIMED_TIME || tok == token::TOKEN_MAX_RECLAIM_LEASES || tok == token::TOKEN_MAX_RECLAIM_TIME || tok == token::TOKEN_UNWARNED_RECLAIM_CYCLES || tok == token::TOKEN_SERVER_ID || tok == token::TOKEN_LLT || tok == token::TOKEN_EN || tok == token::TOKEN_LL || tok == token::TOKEN_IDENTIFIER || tok == token::TOKEN_HTYPE || tok == token::TOKEN_TIME || tok == token::TOKEN_ENTERPRISE_ID || tok == token::TOKEN_DHCP4O6_PORT || tok == token::TOKEN_DHCP_MULTI_THREADING || tok == token::TOKEN_ENABLE_MULTI_THREADING || tok == token::TOKEN_THREAD_POOL_SIZE || tok == token::TOKEN_PACKET_QUEUE_SIZE || tok == token::TOKEN_CONTROL_SOCKET || tok == token::TOKEN_SOCKET_TYPE || tok == token::TOKEN_SOCKET_NAME || tok == token::TOKEN_DHCP_QUEUE_CONTROL || tok == token::TOKEN_ENABLE_QUEUE || tok == token::TOKEN_QUEUE_TYPE || tok == token::TOKEN_CAPACITY || tok == token::TOKEN_DHCP_DDNS || tok == token::TOKEN_ENABLE_UPDATES || tok == token::TOKEN_QUALIFYING_SUFFIX || tok == token::TOKEN_SERVER_IP || tok == token::TOKEN_SERVER_PORT || tok == token::TOKEN_SENDER_IP || tok == token::TOKEN_SENDER_PORT || tok == token::TOKEN_MAX_QUEUE_SIZE || tok == token::TOKEN_NCR_PROTOCOL || tok == token::TOKEN_NCR_FORMAT || tok == token::TOKEN_OVERRIDE_NO_UPDATE || tok == token::TOKEN_OVERRIDE_CLIENT_UPDATE || tok == token::TOKEN_REPLACE_CLIENT_NAME || tok == token::TOKEN_GENERATED_PREFIX || tok == token::TOKEN_UDP || tok == token::TOKEN_TCP || tok == token::TOKEN_JSON || tok == token::TOKEN_WHEN_PRESENT || tok == token::TOKEN_NEVER || tok == token::TOKEN_ALWAYS || tok == token::TOKEN_WHEN_NOT_PRESENT || tok == token::TOKEN_HOSTNAME_CHAR_SET || tok == token::TOKEN_HOSTNAME_CHAR_REPLACEMENT || tok == token::TOKEN_LOGGERS || tok == token::TOKEN_OUTPUT_OPTIONS || tok == token::TOKEN_OUTPUT || tok == token::TOKEN_DEBUGLEVEL || tok == token::TOKEN_SEVERITY || tok == token::TOKEN_FLUSH || tok == token::TOKEN_MAXSIZE || tok == token::TOKEN_MAXVER || tok == token::TOKEN_PATTERN || tok == token::TOKEN_TOPLEVEL_JSON || tok == token::TOKEN_TOPLEVEL_DHCP6 || tok == token::TOKEN_SUB_DHCP6 || tok == token::TOKEN_SUB_INTERFACES6 || tok == token::TOKEN_SUB_SUBNET6 || tok == token::TOKEN_SUB_POOL6 || tok == token::TOKEN_SUB_PD_POOL || tok == token::TOKEN_SUB_RESERVATION || tok == token::TOKEN_SUB_OPTION_DEFS || tok == token::TOKEN_SUB_OPTION_DEF || tok == token::TOKEN_SUB_OPTION_DATA || tok == token::TOKEN_SUB_HOOKS_LIBRARY || tok == token::TOKEN_SUB_DHCP_DDNS || tok == token::TOKEN_SUB_CONFIG_CONTROL);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_PARSER6_error || tok == token::TOKEN_PARSER6_UNDEF || tok == token::TOKEN_COMMA || tok == token::TOKEN_COLON || tok == token::TOKEN_LSQUARE_BRACKET || tok == token::TOKEN_RSQUARE_BRACKET || tok == token::TOKEN_LCURLY_BRACKET || tok == token::TOKEN_RCURLY_BRACKET || tok == token::TOKEN_NULL_TYPE || tok == token::TOKEN_DHCP6 || tok == token::TOKEN_DATA_DIRECTORY || tok == token::TOKEN_CONFIG_CONTROL || tok == token::TOKEN_CONFIG_DATABASES || tok == token::TOKEN_CONFIG_FETCH_WAIT_TIME || tok == token::TOKEN_INTERFACES_CONFIG || tok == token::TOKEN_INTERFACES || tok == token::TOKEN_RE_DETECT || tok == token::TOKEN_LEASE_DATABASE || tok == token::TOKEN_HOSTS_DATABASE || tok == token::TOKEN_HOSTS_DATABASES || tok == token::TOKEN_TYPE || tok == token::TOKEN_MEMFILE || tok == token::TOKEN_MYSQL || tok == token::TOKEN_POSTGRESQL || tok == token::TOKEN_CQL || tok == token::TOKEN_USER || tok == token::TOKEN_PASSWORD || tok == token::TOKEN_HOST || tok == token::TOKEN_PORT || tok == token::TOKEN_PERSIST || tok == token::TOKEN_LFC_INTERVAL || tok == token::TOKEN_READONLY || tok == token::TOKEN_CONNECT_TIMEOUT || tok == token::TOKEN_CONTACT_POINTS || tok == token::TOKEN_MAX_RECONNECT_TRIES || tok == token::TOKEN_RECONNECT_WAIT_TIME || tok == token::TOKEN_KEYSPACE || tok == token::TOKEN_CONSISTENCY || tok == token::TOKEN_SERIAL_CONSISTENCY || tok == token::TOKEN_REQUEST_TIMEOUT || tok == token::TOKEN_TCP_KEEPALIVE || tok == token::TOKEN_TCP_NODELAY || tok == token::TOKEN_MAX_ROW_ERRORS || tok == token::TOKEN_PREFERRED_LIFETIME || tok == token::TOKEN_MIN_PREFERRED_LIFETIME || tok == token::TOKEN_MAX_PREFERRED_LIFETIME || tok == token::TOKEN_VALID_LIFETIME || tok == token::TOKEN_MIN_VALID_LIFETIME || tok == token::TOKEN_MAX_VALID_LIFETIME || tok == token::TOKEN_RENEW_TIMER || tok == token::TOKEN_REBIND_TIMER || tok == token::TOKEN_CALCULATE_TEE_TIMES || tok == token::TOKEN_T1_PERCENT || tok == token::TOKEN_T2_PERCENT || tok == token::TOKEN_CACHE_THRESHOLD || tok == token::TOKEN_CACHE_MAX_AGE || tok == token::TOKEN_DECLINE_PROBATION_PERIOD || tok == token::TOKEN_SERVER_TAG || tok == token::TOKEN_STATISTIC_DEFAULT_SAMPLE_COUNT || tok == token::TOKEN_STATISTIC_DEFAULT_SAMPLE_AGE || tok == token::TOKEN_DDNS_SEND_UPDATES || tok == token::TOKEN_DDNS_OVERRIDE_NO_UPDATE || tok == token::TOKEN_DDNS_OVERRIDE_CLIENT_UPDATE || tok == token::TOKEN_DDNS_REPLACE_CLIENT_NAME || tok == token::TOKEN_DDNS_GENERATED_PREFIX || tok == token::TOKEN_DDNS_QUALIFYING_SUFFIX || tok == token::TOKEN_STORE_EXTENDED_INFO || tok == token::TOKEN_SUBNET6 || tok == token::TOKEN_OPTION_DEF || tok == token::TOKEN_OPTION_DATA || tok == token::TOKEN_NAME || tok == token::TOKEN_DATA || tok == token::TOKEN_CODE || tok == token::TOKEN_SPACE || tok == token::TOKEN_CSV_FORMAT || tok == token::TOKEN_ALWAYS_SEND || tok == token::TOKEN_RECORD_TYPES || tok == token::TOKEN_ENCAPSULATE || tok == token::TOKEN_ARRAY || tok == token::TOKEN_POOLS || tok == token::TOKEN_POOL || tok == token::TOKEN_PD_POOLS || tok == token::TOKEN_PREFIX || tok == token::TOKEN_PREFIX_LEN || tok == token::TOKEN_EXCLUDED_PREFIX || tok == token::TOKEN_EXCLUDED_PREFIX_LEN || tok == token::TOKEN_DELEGATED_LEN || tok == token::TOKEN_USER_CONTEXT || tok == token::TOKEN_COMMENT || tok == token::TOKEN_SUBNET || tok == token::TOKEN_INTERFACE || tok == token::TOKEN_INTERFACE_ID || tok == token::TOKEN_ID || tok == token::TOKEN_RAPID_COMMIT || tok == token::TOKEN_RESERVATION_MODE || tok == token::TOKEN_DISABLED || tok == token::TOKEN_OUT_OF_POOL || tok == token::TOKEN_GLOBAL || tok == token::TOKEN_ALL || tok == token::TOKEN_SHARED_NETWORKS || tok == token::TOKEN_MAC_SOURCES || tok == token::TOKEN_RELAY_SUPPLIED_OPTIONS || tok == token::TOKEN_HOST_RESERVATION_IDENTIFIERS || tok == token::TOKEN_SANITY_CHECKS || tok == token::TOKEN_LEASE_CHECKS || tok == token::TOKEN_CLIENT_CLASSES || tok == token::TOKEN_REQUIRE_CLIENT_CLASSES || tok == token::TOKEN_TEST || tok == token::TOKEN_ONLY_IF_REQUIRED || tok == token::TOKEN_CLIENT_CLASS || tok == token::TOKEN_RESERVATIONS || tok == token::TOKEN_IP_ADDRESSES || tok == token::TOKEN_PREFIXES || tok == token::TOKEN_DUID || tok == token::TOKEN_HW_ADDRESS || tok == token::TOKEN_HOSTNAME || tok == token::TOKEN_FLEX_ID || tok == token::TOKEN_RELAY || tok == token::TOKEN_IP_ADDRESS || tok == token::TOKEN_HOOKS_LIBRARIES || tok == token::TOKEN_LIBRARY || tok == token::TOKEN_PARAMETERS || tok == token::TOKEN_EXPIRED_LEASES_PROCESSING || tok == token::TOKEN_RECLAIM_TIMER_WAIT_TIME || tok == token::TOKEN_FLUSH_RECLAIMED_TIMER_WAIT_TIME || tok == token::TOKEN_HOLD_RECLAIMED_TIME || tok == token::TOKEN_MAX_RECLAIM_LEASES || tok == token::TOKEN_MAX_RECLAIM_TIME || tok == token::TOKEN_UNWARNED_RECLAIM_CYCLES || tok == token::TOKEN_SERVER_ID || tok == token::TOKEN_LLT || tok == token::TOKEN_EN || tok == token::TOKEN_LL || tok == token::TOKEN_IDENTIFIER || tok == token::TOKEN_HTYPE || tok == token::TOKEN_TIME || tok == token::TOKEN_ENTERPRISE_ID || tok == token::TOKEN_DHCP4O6_PORT || tok == token::TOKEN_DHCP_MULTI_THREADING || tok == token::TOKEN_ENABLE_MULTI_THREADING || tok == token::TOKEN_THREAD_POOL_SIZE || tok == token::TOKEN_PACKET_QUEUE_SIZE || tok == token::TOKEN_CONTROL_SOCKET || tok == token::TOKEN_SOCKET_TYPE || tok == token::TOKEN_SOCKET_NAME || tok == token::TOKEN_DHCP_QUEUE_CONTROL || tok == token::TOKEN_ENABLE_QUEUE || tok == token::TOKEN_QUEUE_TYPE || tok == token::TOKEN_CAPACITY || tok == token::TOKEN_DHCP_DDNS || tok == token::TOKEN_ENABLE_UPDATES || tok == token::TOKEN_QUALIFYING_SUFFIX || tok == token::TOKEN_SERVER_IP || tok == token::TOKEN_SERVER_PORT || tok == token::TOKEN_SENDER_IP || tok == token::TOKEN_SENDER_PORT || tok == token::TOKEN_MAX_QUEUE_SIZE || tok == token::TOKEN_NCR_PROTOCOL || tok == token::TOKEN_NCR_FORMAT || tok == token::TOKEN_OVERRIDE_NO_UPDATE || tok == token::TOKEN_OVERRIDE_CLIENT_UPDATE || tok == token::TOKEN_REPLACE_CLIENT_NAME || tok == token::TOKEN_GENERATED_PREFIX || tok == token::TOKEN_UDP || tok == token::TOKEN_TCP || tok == token::TOKEN_JSON || tok == token::TOKEN_WHEN_PRESENT || tok == token::TOKEN_NEVER || tok == token::TOKEN_ALWAYS || tok == token::TOKEN_WHEN_NOT_PRESENT || tok == token::TOKEN_HOSTNAME_CHAR_SET || tok == token::TOKEN_HOSTNAME_CHAR_REPLACEMENT || tok == token::TOKEN_LOGGERS || tok == token::TOKEN_OUTPUT_OPTIONS || tok == token::TOKEN_OUTPUT || tok == token::TOKEN_DEBUGLEVEL || tok == token::TOKEN_SEVERITY || tok == token::TOKEN_FLUSH || tok == token::TOKEN_MAXSIZE || tok == token::TOKEN_MAXVER || tok == token::TOKEN_PATTERN || tok == token::TOKEN_TOPLEVEL_JSON || tok == token::TOKEN_TOPLEVEL_DHCP6 || tok == token::TOKEN_SUB_DHCP6 || tok == token::TOKEN_SUB_INTERFACES6 || tok == token::TOKEN_SUB_SUBNET6 || tok == token::TOKEN_SUB_POOL6 || tok == token::TOKEN_SUB_PD_POOL || tok == token::TOKEN_SUB_RESERVATION || tok == token::TOKEN_SUB_OPTION_DEFS || tok == token::TOKEN_SUB_OPTION_DEF || tok == token::TOKEN_SUB_OPTION_DATA || tok == token::TOKEN_SUB_HOOKS_LIBRARY || tok == token::TOKEN_SUB_DHCP_DDNS || tok == token::TOKEN_SUB_CONFIG_CONTROL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int64_t v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_INTEGER);
      }
#else
      symbol_type (int tok, const int64_t& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_INTEGER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_STRING);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_STRING);
      }
#endif
    };

    /// Build a parser object.
    Dhcp6Parser (isc::dhcp::Parser6Context& ctx_yyarg);
    virtual ~Dhcp6Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Dhcp6Parser (const Dhcp6Parser&) = delete;
    /// Non copyable.
    Dhcp6Parser& operator= (const Dhcp6Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if PARSER6_DEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOKEN_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOKEN_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARSER6_error (location_type l)
      {
        return symbol_type (token::TOKEN_PARSER6_error, std::move (l));
      }
#else
      static
      symbol_type
      make_PARSER6_error (const location_type& l)
      {
        return symbol_type (token::TOKEN_PARSER6_error, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARSER6_UNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_PARSER6_UNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_PARSER6_UNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_PARSER6_UNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOKEN_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::TOKEN_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::TOKEN_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSQUARE_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_LSQUARE_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LSQUARE_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_LSQUARE_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSQUARE_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_RSQUARE_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RSQUARE_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_RSQUARE_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCURLY_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_LCURLY_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LCURLY_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_LCURLY_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCURLY_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_RCURLY_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RCURLY_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_RCURLY_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NULL_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_NULL_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_NULL_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_NULL_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP6 (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP6, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DATA_DIRECTORY (location_type l)
      {
        return symbol_type (token::TOKEN_DATA_DIRECTORY, std::move (l));
      }
#else
      static
      symbol_type
      make_DATA_DIRECTORY (const location_type& l)
      {
        return symbol_type (token::TOKEN_DATA_DIRECTORY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONFIG_CONTROL (location_type l)
      {
        return symbol_type (token::TOKEN_CONFIG_CONTROL, std::move (l));
      }
#else
      static
      symbol_type
      make_CONFIG_CONTROL (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONFIG_CONTROL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONFIG_DATABASES (location_type l)
      {
        return symbol_type (token::TOKEN_CONFIG_DATABASES, std::move (l));
      }
#else
      static
      symbol_type
      make_CONFIG_DATABASES (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONFIG_DATABASES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONFIG_FETCH_WAIT_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_CONFIG_FETCH_WAIT_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_CONFIG_FETCH_WAIT_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONFIG_FETCH_WAIT_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACES_CONFIG (location_type l)
      {
        return symbol_type (token::TOKEN_INTERFACES_CONFIG, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERFACES_CONFIG (const location_type& l)
      {
        return symbol_type (token::TOKEN_INTERFACES_CONFIG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACES (location_type l)
      {
        return symbol_type (token::TOKEN_INTERFACES, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERFACES (const location_type& l)
      {
        return symbol_type (token::TOKEN_INTERFACES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RE_DETECT (location_type l)
      {
        return symbol_type (token::TOKEN_RE_DETECT, std::move (l));
      }
#else
      static
      symbol_type
      make_RE_DETECT (const location_type& l)
      {
        return symbol_type (token::TOKEN_RE_DETECT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEASE_DATABASE (location_type l)
      {
        return symbol_type (token::TOKEN_LEASE_DATABASE, std::move (l));
      }
#else
      static
      symbol_type
      make_LEASE_DATABASE (const location_type& l)
      {
        return symbol_type (token::TOKEN_LEASE_DATABASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTS_DATABASE (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTS_DATABASE, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTS_DATABASE (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTS_DATABASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTS_DATABASES (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTS_DATABASES, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTS_DATABASES (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTS_DATABASES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEMFILE (location_type l)
      {
        return symbol_type (token::TOKEN_MEMFILE, std::move (l));
      }
#else
      static
      symbol_type
      make_MEMFILE (const location_type& l)
      {
        return symbol_type (token::TOKEN_MEMFILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MYSQL (location_type l)
      {
        return symbol_type (token::TOKEN_MYSQL, std::move (l));
      }
#else
      static
      symbol_type
      make_MYSQL (const location_type& l)
      {
        return symbol_type (token::TOKEN_MYSQL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POSTGRESQL (location_type l)
      {
        return symbol_type (token::TOKEN_POSTGRESQL, std::move (l));
      }
#else
      static
      symbol_type
      make_POSTGRESQL (const location_type& l)
      {
        return symbol_type (token::TOKEN_POSTGRESQL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CQL (location_type l)
      {
        return symbol_type (token::TOKEN_CQL, std::move (l));
      }
#else
      static
      symbol_type
      make_CQL (const location_type& l)
      {
        return symbol_type (token::TOKEN_CQL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER (location_type l)
      {
        return symbol_type (token::TOKEN_USER, std::move (l));
      }
#else
      static
      symbol_type
      make_USER (const location_type& l)
      {
        return symbol_type (token::TOKEN_USER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PASSWORD (location_type l)
      {
        return symbol_type (token::TOKEN_PASSWORD, std::move (l));
      }
#else
      static
      symbol_type
      make_PASSWORD (const location_type& l)
      {
        return symbol_type (token::TOKEN_PASSWORD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOST (location_type l)
      {
        return symbol_type (token::TOKEN_HOST, std::move (l));
      }
#else
      static
      symbol_type
      make_HOST (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PORT (location_type l)
      {
        return symbol_type (token::TOKEN_PORT, std::move (l));
      }
#else
      static
      symbol_type
      make_PORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_PORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERSIST (location_type l)
      {
        return symbol_type (token::TOKEN_PERSIST, std::move (l));
      }
#else
      static
      symbol_type
      make_PERSIST (const location_type& l)
      {
        return symbol_type (token::TOKEN_PERSIST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LFC_INTERVAL (location_type l)
      {
        return symbol_type (token::TOKEN_LFC_INTERVAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LFC_INTERVAL (const location_type& l)
      {
        return symbol_type (token::TOKEN_LFC_INTERVAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READONLY (location_type l)
      {
        return symbol_type (token::TOKEN_READONLY, std::move (l));
      }
#else
      static
      symbol_type
      make_READONLY (const location_type& l)
      {
        return symbol_type (token::TOKEN_READONLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONNECT_TIMEOUT (location_type l)
      {
        return symbol_type (token::TOKEN_CONNECT_TIMEOUT, std::move (l));
      }
#else
      static
      symbol_type
      make_CONNECT_TIMEOUT (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONNECT_TIMEOUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTACT_POINTS (location_type l)
      {
        return symbol_type (token::TOKEN_CONTACT_POINTS, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTACT_POINTS (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONTACT_POINTS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_RECONNECT_TRIES (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_RECONNECT_TRIES, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_RECONNECT_TRIES (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_RECONNECT_TRIES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECONNECT_WAIT_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_RECONNECT_WAIT_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_RECONNECT_WAIT_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_RECONNECT_WAIT_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KEYSPACE (location_type l)
      {
        return symbol_type (token::TOKEN_KEYSPACE, std::move (l));
      }
#else
      static
      symbol_type
      make_KEYSPACE (const location_type& l)
      {
        return symbol_type (token::TOKEN_KEYSPACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSISTENCY (location_type l)
      {
        return symbol_type (token::TOKEN_CONSISTENCY, std::move (l));
      }
#else
      static
      symbol_type
      make_CONSISTENCY (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONSISTENCY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SERIAL_CONSISTENCY (location_type l)
      {
        return symbol_type (token::TOKEN_SERIAL_CONSISTENCY, std::move (l));
      }
#else
      static
      symbol_type
      make_SERIAL_CONSISTENCY (const location_type& l)
      {
        return symbol_type (token::TOKEN_SERIAL_CONSISTENCY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REQUEST_TIMEOUT (location_type l)
      {
        return symbol_type (token::TOKEN_REQUEST_TIMEOUT, std::move (l));
      }
#else
      static
      symbol_type
      make_REQUEST_TIMEOUT (const location_type& l)
      {
        return symbol_type (token::TOKEN_REQUEST_TIMEOUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCP_KEEPALIVE (location_type l)
      {
        return symbol_type (token::TOKEN_TCP_KEEPALIVE, std::move (l));
      }
#else
      static
      symbol_type
      make_TCP_KEEPALIVE (const location_type& l)
      {
        return symbol_type (token::TOKEN_TCP_KEEPALIVE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCP_NODELAY (location_type l)
      {
        return symbol_type (token::TOKEN_TCP_NODELAY, std::move (l));
      }
#else
      static
      symbol_type
      make_TCP_NODELAY (const location_type& l)
      {
        return symbol_type (token::TOKEN_TCP_NODELAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ROW_ERRORS (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_ROW_ERRORS, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_ROW_ERRORS (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_ROW_ERRORS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFERRED_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_PREFERRED_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFERRED_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_PREFERRED_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_PREFERRED_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_MIN_PREFERRED_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN_PREFERRED_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_MIN_PREFERRED_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_PREFERRED_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_PREFERRED_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_PREFERRED_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_PREFERRED_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VALID_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_VALID_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_VALID_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_VALID_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_VALID_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_MIN_VALID_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN_VALID_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_MIN_VALID_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_VALID_LIFETIME (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_VALID_LIFETIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_VALID_LIFETIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_VALID_LIFETIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RENEW_TIMER (location_type l)
      {
        return symbol_type (token::TOKEN_RENEW_TIMER, std::move (l));
      }
#else
      static
      symbol_type
      make_RENEW_TIMER (const location_type& l)
      {
        return symbol_type (token::TOKEN_RENEW_TIMER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REBIND_TIMER (location_type l)
      {
        return symbol_type (token::TOKEN_REBIND_TIMER, std::move (l));
      }
#else
      static
      symbol_type
      make_REBIND_TIMER (const location_type& l)
      {
        return symbol_type (token::TOKEN_REBIND_TIMER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALCULATE_TEE_TIMES (location_type l)
      {
        return symbol_type (token::TOKEN_CALCULATE_TEE_TIMES, std::move (l));
      }
#else
      static
      symbol_type
      make_CALCULATE_TEE_TIMES (const location_type& l)
      {
        return symbol_type (token::TOKEN_CALCULATE_TEE_TIMES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T1_PERCENT (location_type l)
      {
        return symbol_type (token::TOKEN_T1_PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_T1_PERCENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_T1_PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T2_PERCENT (location_type l)
      {
        return symbol_type (token::TOKEN_T2_PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_T2_PERCENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_T2_PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CACHE_THRESHOLD (location_type l)
      {
        return symbol_type (token::TOKEN_CACHE_THRESHOLD, std::move (l));
      }
#else
      static
      symbol_type
      make_CACHE_THRESHOLD (const location_type& l)
      {
        return symbol_type (token::TOKEN_CACHE_THRESHOLD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CACHE_MAX_AGE (location_type l)
      {
        return symbol_type (token::TOKEN_CACHE_MAX_AGE, std::move (l));
      }
#else
      static
      symbol_type
      make_CACHE_MAX_AGE (const location_type& l)
      {
        return symbol_type (token::TOKEN_CACHE_MAX_AGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECLINE_PROBATION_PERIOD (location_type l)
      {
        return symbol_type (token::TOKEN_DECLINE_PROBATION_PERIOD, std::move (l));
      }
#else
      static
      symbol_type
      make_DECLINE_PROBATION_PERIOD (const location_type& l)
      {
        return symbol_type (token::TOKEN_DECLINE_PROBATION_PERIOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SERVER_TAG (location_type l)
      {
        return symbol_type (token::TOKEN_SERVER_TAG, std::move (l));
      }
#else
      static
      symbol_type
      make_SERVER_TAG (const location_type& l)
      {
        return symbol_type (token::TOKEN_SERVER_TAG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATISTIC_DEFAULT_SAMPLE_COUNT (location_type l)
      {
        return symbol_type (token::TOKEN_STATISTIC_DEFAULT_SAMPLE_COUNT, std::move (l));
      }
#else
      static
      symbol_type
      make_STATISTIC_DEFAULT_SAMPLE_COUNT (const location_type& l)
      {
        return symbol_type (token::TOKEN_STATISTIC_DEFAULT_SAMPLE_COUNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATISTIC_DEFAULT_SAMPLE_AGE (location_type l)
      {
        return symbol_type (token::TOKEN_STATISTIC_DEFAULT_SAMPLE_AGE, std::move (l));
      }
#else
      static
      symbol_type
      make_STATISTIC_DEFAULT_SAMPLE_AGE (const location_type& l)
      {
        return symbol_type (token::TOKEN_STATISTIC_DEFAULT_SAMPLE_AGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_SEND_UPDATES (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_SEND_UPDATES, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_SEND_UPDATES (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_SEND_UPDATES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_OVERRIDE_NO_UPDATE (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_OVERRIDE_NO_UPDATE, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_OVERRIDE_NO_UPDATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_OVERRIDE_NO_UPDATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_OVERRIDE_CLIENT_UPDATE (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_OVERRIDE_CLIENT_UPDATE, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_OVERRIDE_CLIENT_UPDATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_OVERRIDE_CLIENT_UPDATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_REPLACE_CLIENT_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_REPLACE_CLIENT_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_REPLACE_CLIENT_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_REPLACE_CLIENT_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_GENERATED_PREFIX (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_GENERATED_PREFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_GENERATED_PREFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_GENERATED_PREFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_QUALIFYING_SUFFIX (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_QUALIFYING_SUFFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_QUALIFYING_SUFFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_QUALIFYING_SUFFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STORE_EXTENDED_INFO (location_type l)
      {
        return symbol_type (token::TOKEN_STORE_EXTENDED_INFO, std::move (l));
      }
#else
      static
      symbol_type
      make_STORE_EXTENDED_INFO (const location_type& l)
      {
        return symbol_type (token::TOKEN_STORE_EXTENDED_INFO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBNET6 (location_type l)
      {
        return symbol_type (token::TOKEN_SUBNET6, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBNET6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUBNET6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPTION_DEF (location_type l)
      {
        return symbol_type (token::TOKEN_OPTION_DEF, std::move (l));
      }
#else
      static
      symbol_type
      make_OPTION_DEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_OPTION_DEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPTION_DATA (location_type l)
      {
        return symbol_type (token::TOKEN_OPTION_DATA, std::move (l));
      }
#else
      static
      symbol_type
      make_OPTION_DATA (const location_type& l)
      {
        return symbol_type (token::TOKEN_OPTION_DATA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DATA (location_type l)
      {
        return symbol_type (token::TOKEN_DATA, std::move (l));
      }
#else
      static
      symbol_type
      make_DATA (const location_type& l)
      {
        return symbol_type (token::TOKEN_DATA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CODE (location_type l)
      {
        return symbol_type (token::TOKEN_CODE, std::move (l));
      }
#else
      static
      symbol_type
      make_CODE (const location_type& l)
      {
        return symbol_type (token::TOKEN_CODE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPACE (location_type l)
      {
        return symbol_type (token::TOKEN_SPACE, std::move (l));
      }
#else
      static
      symbol_type
      make_SPACE (const location_type& l)
      {
        return symbol_type (token::TOKEN_SPACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CSV_FORMAT (location_type l)
      {
        return symbol_type (token::TOKEN_CSV_FORMAT, std::move (l));
      }
#else
      static
      symbol_type
      make_CSV_FORMAT (const location_type& l)
      {
        return symbol_type (token::TOKEN_CSV_FORMAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALWAYS_SEND (location_type l)
      {
        return symbol_type (token::TOKEN_ALWAYS_SEND, std::move (l));
      }
#else
      static
      symbol_type
      make_ALWAYS_SEND (const location_type& l)
      {
        return symbol_type (token::TOKEN_ALWAYS_SEND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECORD_TYPES (location_type l)
      {
        return symbol_type (token::TOKEN_RECORD_TYPES, std::move (l));
      }
#else
      static
      symbol_type
      make_RECORD_TYPES (const location_type& l)
      {
        return symbol_type (token::TOKEN_RECORD_TYPES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENCAPSULATE (location_type l)
      {
        return symbol_type (token::TOKEN_ENCAPSULATE, std::move (l));
      }
#else
      static
      symbol_type
      make_ENCAPSULATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_ENCAPSULATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POOLS (location_type l)
      {
        return symbol_type (token::TOKEN_POOLS, std::move (l));
      }
#else
      static
      symbol_type
      make_POOLS (const location_type& l)
      {
        return symbol_type (token::TOKEN_POOLS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POOL (location_type l)
      {
        return symbol_type (token::TOKEN_POOL, std::move (l));
      }
#else
      static
      symbol_type
      make_POOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_POOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PD_POOLS (location_type l)
      {
        return symbol_type (token::TOKEN_PD_POOLS, std::move (l));
      }
#else
      static
      symbol_type
      make_PD_POOLS (const location_type& l)
      {
        return symbol_type (token::TOKEN_PD_POOLS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIX (location_type l)
      {
        return symbol_type (token::TOKEN_PREFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_PREFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIX_LEN (location_type l)
      {
        return symbol_type (token::TOKEN_PREFIX_LEN, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIX_LEN (const location_type& l)
      {
        return symbol_type (token::TOKEN_PREFIX_LEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLUDED_PREFIX (location_type l)
      {
        return symbol_type (token::TOKEN_EXCLUDED_PREFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLUDED_PREFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_EXCLUDED_PREFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLUDED_PREFIX_LEN (location_type l)
      {
        return symbol_type (token::TOKEN_EXCLUDED_PREFIX_LEN, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLUDED_PREFIX_LEN (const location_type& l)
      {
        return symbol_type (token::TOKEN_EXCLUDED_PREFIX_LEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELEGATED_LEN (location_type l)
      {
        return symbol_type (token::TOKEN_DELEGATED_LEN, std::move (l));
      }
#else
      static
      symbol_type
      make_DELEGATED_LEN (const location_type& l)
      {
        return symbol_type (token::TOKEN_DELEGATED_LEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER_CONTEXT (location_type l)
      {
        return symbol_type (token::TOKEN_USER_CONTEXT, std::move (l));
      }
#else
      static
      symbol_type
      make_USER_CONTEXT (const location_type& l)
      {
        return symbol_type (token::TOKEN_USER_CONTEXT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (location_type l)
      {
        return symbol_type (token::TOKEN_COMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBNET (location_type l)
      {
        return symbol_type (token::TOKEN_SUBNET, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBNET (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUBNET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACE (location_type l)
      {
        return symbol_type (token::TOKEN_INTERFACE, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERFACE (const location_type& l)
      {
        return symbol_type (token::TOKEN_INTERFACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACE_ID (location_type l)
      {
        return symbol_type (token::TOKEN_INTERFACE_ID, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERFACE_ID (const location_type& l)
      {
        return symbol_type (token::TOKEN_INTERFACE_ID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (location_type l)
      {
        return symbol_type (token::TOKEN_ID, std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const location_type& l)
      {
        return symbol_type (token::TOKEN_ID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAPID_COMMIT (location_type l)
      {
        return symbol_type (token::TOKEN_RAPID_COMMIT, std::move (l));
      }
#else
      static
      symbol_type
      make_RAPID_COMMIT (const location_type& l)
      {
        return symbol_type (token::TOKEN_RAPID_COMMIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESERVATION_MODE (location_type l)
      {
        return symbol_type (token::TOKEN_RESERVATION_MODE, std::move (l));
      }
#else
      static
      symbol_type
      make_RESERVATION_MODE (const location_type& l)
      {
        return symbol_type (token::TOKEN_RESERVATION_MODE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DISABLED (location_type l)
      {
        return symbol_type (token::TOKEN_DISABLED, std::move (l));
      }
#else
      static
      symbol_type
      make_DISABLED (const location_type& l)
      {
        return symbol_type (token::TOKEN_DISABLED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT_OF_POOL (location_type l)
      {
        return symbol_type (token::TOKEN_OUT_OF_POOL, std::move (l));
      }
#else
      static
      symbol_type
      make_OUT_OF_POOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_OUT_OF_POOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GLOBAL (location_type l)
      {
        return symbol_type (token::TOKEN_GLOBAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GLOBAL (const location_type& l)
      {
        return symbol_type (token::TOKEN_GLOBAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALL (location_type l)
      {
        return symbol_type (token::TOKEN_ALL, std::move (l));
      }
#else
      static
      symbol_type
      make_ALL (const location_type& l)
      {
        return symbol_type (token::TOKEN_ALL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHARED_NETWORKS (location_type l)
      {
        return symbol_type (token::TOKEN_SHARED_NETWORKS, std::move (l));
      }
#else
      static
      symbol_type
      make_SHARED_NETWORKS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SHARED_NETWORKS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAC_SOURCES (location_type l)
      {
        return symbol_type (token::TOKEN_MAC_SOURCES, std::move (l));
      }
#else
      static
      symbol_type
      make_MAC_SOURCES (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAC_SOURCES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELAY_SUPPLIED_OPTIONS (location_type l)
      {
        return symbol_type (token::TOKEN_RELAY_SUPPLIED_OPTIONS, std::move (l));
      }
#else
      static
      symbol_type
      make_RELAY_SUPPLIED_OPTIONS (const location_type& l)
      {
        return symbol_type (token::TOKEN_RELAY_SUPPLIED_OPTIONS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOST_RESERVATION_IDENTIFIERS (location_type l)
      {
        return symbol_type (token::TOKEN_HOST_RESERVATION_IDENTIFIERS, std::move (l));
      }
#else
      static
      symbol_type
      make_HOST_RESERVATION_IDENTIFIERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOST_RESERVATION_IDENTIFIERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SANITY_CHECKS (location_type l)
      {
        return symbol_type (token::TOKEN_SANITY_CHECKS, std::move (l));
      }
#else
      static
      symbol_type
      make_SANITY_CHECKS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SANITY_CHECKS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEASE_CHECKS (location_type l)
      {
        return symbol_type (token::TOKEN_LEASE_CHECKS, std::move (l));
      }
#else
      static
      symbol_type
      make_LEASE_CHECKS (const location_type& l)
      {
        return symbol_type (token::TOKEN_LEASE_CHECKS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLIENT_CLASSES (location_type l)
      {
        return symbol_type (token::TOKEN_CLIENT_CLASSES, std::move (l));
      }
#else
      static
      symbol_type
      make_CLIENT_CLASSES (const location_type& l)
      {
        return symbol_type (token::TOKEN_CLIENT_CLASSES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REQUIRE_CLIENT_CLASSES (location_type l)
      {
        return symbol_type (token::TOKEN_REQUIRE_CLIENT_CLASSES, std::move (l));
      }
#else
      static
      symbol_type
      make_REQUIRE_CLIENT_CLASSES (const location_type& l)
      {
        return symbol_type (token::TOKEN_REQUIRE_CLIENT_CLASSES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEST (location_type l)
      {
        return symbol_type (token::TOKEN_TEST, std::move (l));
      }
#else
      static
      symbol_type
      make_TEST (const location_type& l)
      {
        return symbol_type (token::TOKEN_TEST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ONLY_IF_REQUIRED (location_type l)
      {
        return symbol_type (token::TOKEN_ONLY_IF_REQUIRED, std::move (l));
      }
#else
      static
      symbol_type
      make_ONLY_IF_REQUIRED (const location_type& l)
      {
        return symbol_type (token::TOKEN_ONLY_IF_REQUIRED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLIENT_CLASS (location_type l)
      {
        return symbol_type (token::TOKEN_CLIENT_CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLIENT_CLASS (const location_type& l)
      {
        return symbol_type (token::TOKEN_CLIENT_CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESERVATIONS (location_type l)
      {
        return symbol_type (token::TOKEN_RESERVATIONS, std::move (l));
      }
#else
      static
      symbol_type
      make_RESERVATIONS (const location_type& l)
      {
        return symbol_type (token::TOKEN_RESERVATIONS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IP_ADDRESSES (location_type l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESSES, std::move (l));
      }
#else
      static
      symbol_type
      make_IP_ADDRESSES (const location_type& l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESSES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREFIXES (location_type l)
      {
        return symbol_type (token::TOKEN_PREFIXES, std::move (l));
      }
#else
      static
      symbol_type
      make_PREFIXES (const location_type& l)
      {
        return symbol_type (token::TOKEN_PREFIXES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DUID (location_type l)
      {
        return symbol_type (token::TOKEN_DUID, std::move (l));
      }
#else
      static
      symbol_type
      make_DUID (const location_type& l)
      {
        return symbol_type (token::TOKEN_DUID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HW_ADDRESS (location_type l)
      {
        return symbol_type (token::TOKEN_HW_ADDRESS, std::move (l));
      }
#else
      static
      symbol_type
      make_HW_ADDRESS (const location_type& l)
      {
        return symbol_type (token::TOKEN_HW_ADDRESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTNAME (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTNAME, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTNAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTNAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLEX_ID (location_type l)
      {
        return symbol_type (token::TOKEN_FLEX_ID, std::move (l));
      }
#else
      static
      symbol_type
      make_FLEX_ID (const location_type& l)
      {
        return symbol_type (token::TOKEN_FLEX_ID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELAY (location_type l)
      {
        return symbol_type (token::TOKEN_RELAY, std::move (l));
      }
#else
      static
      symbol_type
      make_RELAY (const location_type& l)
      {
        return symbol_type (token::TOKEN_RELAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IP_ADDRESS (location_type l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESS, std::move (l));
      }
#else
      static
      symbol_type
      make_IP_ADDRESS (const location_type& l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOOKS_LIBRARIES (location_type l)
      {
        return symbol_type (token::TOKEN_HOOKS_LIBRARIES, std::move (l));
      }
#else
      static
      symbol_type
      make_HOOKS_LIBRARIES (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOOKS_LIBRARIES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIBRARY (location_type l)
      {
        return symbol_type (token::TOKEN_LIBRARY, std::move (l));
      }
#else
      static
      symbol_type
      make_LIBRARY (const location_type& l)
      {
        return symbol_type (token::TOKEN_LIBRARY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARAMETERS (location_type l)
      {
        return symbol_type (token::TOKEN_PARAMETERS, std::move (l));
      }
#else
      static
      symbol_type
      make_PARAMETERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_PARAMETERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPIRED_LEASES_PROCESSING (location_type l)
      {
        return symbol_type (token::TOKEN_EXPIRED_LEASES_PROCESSING, std::move (l));
      }
#else
      static
      symbol_type
      make_EXPIRED_LEASES_PROCESSING (const location_type& l)
      {
        return symbol_type (token::TOKEN_EXPIRED_LEASES_PROCESSING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECLAIM_TIMER_WAIT_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_RECLAIM_TIMER_WAIT_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_RECLAIM_TIMER_WAIT_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_RECLAIM_TIMER_WAIT_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLUSH_RECLAIMED_TIMER_WAIT_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_FLUSH_RECLAIMED_TIMER_WAIT_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_FLUSH_RECLAIMED_TIMER_WAIT_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_FLUSH_RECLAIMED_TIMER_WAIT_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOLD_RECLAIMED_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_HOLD_RECLAIMED_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_HOLD_RECLAIMED_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOLD_RECLAIMED_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_RECLAIM_LEASES (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_RECLAIM_LEASES, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_RECLAIM_LEASES (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_RECLAIM_LEASES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_RECLAIM_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_RECLAIM_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_RECLAIM_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_RECLAIM_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNWARNED_RECLAIM_CYCLES (location_type l)
      {
        return symbol_type (token::TOKEN_UNWARNED_RECLAIM_CYCLES, std::move (l));
      }
#else
      static
      symbol_type
      make_UNWARNED_RECLAIM_CYCLES (const location_type& l)
      {
        return symbol_type (token::TOKEN_UNWARNED_RECLAIM_CYCLES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SERVER_ID (location_type l)
      {
        return symbol_type (token::TOKEN_SERVER_ID, std::move (l));
      }
#else
      static
      symbol_type
      make_SERVER_ID (const location_type& l)
      {
        return symbol_type (token::TOKEN_SERVER_ID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LLT (location_type l)
      {
        return symbol_type (token::TOKEN_LLT, std::move (l));
      }
#else
      static
      symbol_type
      make_LLT (const location_type& l)
      {
        return symbol_type (token::TOKEN_LLT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EN (location_type l)
      {
        return symbol_type (token::TOKEN_EN, std::move (l));
      }
#else
      static
      symbol_type
      make_EN (const location_type& l)
      {
        return symbol_type (token::TOKEN_EN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LL (location_type l)
      {
        return symbol_type (token::TOKEN_LL, std::move (l));
      }
#else
      static
      symbol_type
      make_LL (const location_type& l)
      {
        return symbol_type (token::TOKEN_LL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (location_type l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const location_type& l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HTYPE (location_type l)
      {
        return symbol_type (token::TOKEN_HTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_HTYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_HTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIME (location_type l)
      {
        return symbol_type (token::TOKEN_TIME, std::move (l));
      }
#else
      static
      symbol_type
      make_TIME (const location_type& l)
      {
        return symbol_type (token::TOKEN_TIME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENTERPRISE_ID (location_type l)
      {
        return symbol_type (token::TOKEN_ENTERPRISE_ID, std::move (l));
      }
#else
      static
      symbol_type
      make_ENTERPRISE_ID (const location_type& l)
      {
        return symbol_type (token::TOKEN_ENTERPRISE_ID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP4O6_PORT (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP4O6_PORT, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP4O6_PORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP4O6_PORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP_MULTI_THREADING (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP_MULTI_THREADING, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP_MULTI_THREADING (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP_MULTI_THREADING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENABLE_MULTI_THREADING (location_type l)
      {
        return symbol_type (token::TOKEN_ENABLE_MULTI_THREADING, std::move (l));
      }
#else
      static
      symbol_type
      make_ENABLE_MULTI_THREADING (const location_type& l)
      {
        return symbol_type (token::TOKEN_ENABLE_MULTI_THREADING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THREAD_POOL_SIZE (location_type l)
      {
        return symbol_type (token::TOKEN_THREAD_POOL_SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_THREAD_POOL_SIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_THREAD_POOL_SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PACKET_QUEUE_SIZE (location_type l)
      {
        return symbol_type (token::TOKEN_PACKET_QUEUE_SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_PACKET_QUEUE_SIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_PACKET_QUEUE_SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTROL_SOCKET (location_type l)
      {
        return symbol_type (token::TOKEN_CONTROL_SOCKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTROL_SOCKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONTROL_SOCKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOCKET_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_SOCKET_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SOCKET_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_SOCKET_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOCKET_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_SOCKET_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_SOCKET_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_SOCKET_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP_QUEUE_CONTROL (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP_QUEUE_CONTROL, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP_QUEUE_CONTROL (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP_QUEUE_CONTROL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENABLE_QUEUE (location_type l)
      {
        return symbol_type (token::TOKEN_ENABLE_QUEUE, std::move (l));
      }
#else
      static
      symbol_type
      make_ENABLE_QUEUE (const location_type& l)
      {
        return symbol_type (token::TOKEN_ENABLE_QUEUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUEUE_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_QUEUE_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_QUEUE_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_QUEUE_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAPACITY (location_type l)
      {
        return symbol_type (token::TOKEN_CAPACITY, std::move (l));
      }
#else
      static
      symbol_type
      make_CAPACITY (const location_type& l)
      {
        return symbol_type (token::TOKEN_CAPACITY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP_DDNS (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP_DDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP_DDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP_DDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENABLE_UPDATES (location_type l)
      {
        return symbol_type (token::TOKEN_ENABLE_UPDATES, std::move (l));
      }
#else
      static
      symbol_type
      make_ENABLE_UPDATES (const location_type& l)
      {
        return symbol_type (token::TOKEN_ENABLE_UPDATES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUALIFYING_SUFFIX (location_type l)
      {
        return symbol_type (token::TOKEN_QUALIFYING_SUFFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_QUALIFYING_SUFFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_QUALIFYING_SUFFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SERVER_IP (location_type l)
      {
        return symbol_type (token::TOKEN_SERVER_IP, std::move (l));
      }
#else
      static
      symbol_type
      make_SERVER_IP (const location_type& l)
      {
        return symbol_type (token::TOKEN_SERVER_IP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SERVER_PORT (location_type l)
      {
        return symbol_type (token::TOKEN_SERVER_PORT, std::move (l));
      }
#else
      static
      symbol_type
      make_SERVER_PORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_SERVER_PORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SENDER_IP (location_type l)
      {
        return symbol_type (token::TOKEN_SENDER_IP, std::move (l));
      }
#else
      static
      symbol_type
      make_SENDER_IP (const location_type& l)
      {
        return symbol_type (token::TOKEN_SENDER_IP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SENDER_PORT (location_type l)
      {
        return symbol_type (token::TOKEN_SENDER_PORT, std::move (l));
      }
#else
      static
      symbol_type
      make_SENDER_PORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_SENDER_PORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_QUEUE_SIZE (location_type l)
      {
        return symbol_type (token::TOKEN_MAX_QUEUE_SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX_QUEUE_SIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAX_QUEUE_SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NCR_PROTOCOL (location_type l)
      {
        return symbol_type (token::TOKEN_NCR_PROTOCOL, std::move (l));
      }
#else
      static
      symbol_type
      make_NCR_PROTOCOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_NCR_PROTOCOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NCR_FORMAT (location_type l)
      {
        return symbol_type (token::TOKEN_NCR_FORMAT, std::move (l));
      }
#else
      static
      symbol_type
      make_NCR_FORMAT (const location_type& l)
      {
        return symbol_type (token::TOKEN_NCR_FORMAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDE_NO_UPDATE (location_type l)
      {
        return symbol_type (token::TOKEN_OVERRIDE_NO_UPDATE, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDE_NO_UPDATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_OVERRIDE_NO_UPDATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDE_CLIENT_UPDATE (location_type l)
      {
        return symbol_type (token::TOKEN_OVERRIDE_CLIENT_UPDATE, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDE_CLIENT_UPDATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_OVERRIDE_CLIENT_UPDATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPLACE_CLIENT_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_REPLACE_CLIENT_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_REPLACE_CLIENT_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_REPLACE_CLIENT_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GENERATED_PREFIX (location_type l)
      {
        return symbol_type (token::TOKEN_GENERATED_PREFIX, std::move (l));
      }
#else
      static
      symbol_type
      make_GENERATED_PREFIX (const location_type& l)
      {
        return symbol_type (token::TOKEN_GENERATED_PREFIX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UDP (location_type l)
      {
        return symbol_type (token::TOKEN_UDP, std::move (l));
      }
#else
      static
      symbol_type
      make_UDP (const location_type& l)
      {
        return symbol_type (token::TOKEN_UDP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCP (location_type l)
      {
        return symbol_type (token::TOKEN_TCP, std::move (l));
      }
#else
      static
      symbol_type
      make_TCP (const location_type& l)
      {
        return symbol_type (token::TOKEN_TCP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_JSON (location_type l)
      {
        return symbol_type (token::TOKEN_JSON, std::move (l));
      }
#else
      static
      symbol_type
      make_JSON (const location_type& l)
      {
        return symbol_type (token::TOKEN_JSON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHEN_PRESENT (location_type l)
      {
        return symbol_type (token::TOKEN_WHEN_PRESENT, std::move (l));
      }
#else
      static
      symbol_type
      make_WHEN_PRESENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_WHEN_PRESENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEVER (location_type l)
      {
        return symbol_type (token::TOKEN_NEVER, std::move (l));
      }
#else
      static
      symbol_type
      make_NEVER (const location_type& l)
      {
        return symbol_type (token::TOKEN_NEVER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALWAYS (location_type l)
      {
        return symbol_type (token::TOKEN_ALWAYS, std::move (l));
      }
#else
      static
      symbol_type
      make_ALWAYS (const location_type& l)
      {
        return symbol_type (token::TOKEN_ALWAYS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHEN_NOT_PRESENT (location_type l)
      {
        return symbol_type (token::TOKEN_WHEN_NOT_PRESENT, std::move (l));
      }
#else
      static
      symbol_type
      make_WHEN_NOT_PRESENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_WHEN_NOT_PRESENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTNAME_CHAR_SET (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTNAME_CHAR_SET, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTNAME_CHAR_SET (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTNAME_CHAR_SET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTNAME_CHAR_REPLACEMENT (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTNAME_CHAR_REPLACEMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTNAME_CHAR_REPLACEMENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTNAME_CHAR_REPLACEMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGGERS (location_type l)
      {
        return symbol_type (token::TOKEN_LOGGERS, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGGERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_LOGGERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_OPTIONS (location_type l)
      {
        return symbol_type (token::TOKEN_OUTPUT_OPTIONS, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_OPTIONS (const location_type& l)
      {
        return symbol_type (token::TOKEN_OUTPUT_OPTIONS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT (location_type l)
      {
        return symbol_type (token::TOKEN_OUTPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT (const location_type& l)
      {
        return symbol_type (token::TOKEN_OUTPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEBUGLEVEL (location_type l)
      {
        return symbol_type (token::TOKEN_DEBUGLEVEL, std::move (l));
      }
#else
      static
      symbol_type
      make_DEBUGLEVEL (const location_type& l)
      {
        return symbol_type (token::TOKEN_DEBUGLEVEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEVERITY (location_type l)
      {
        return symbol_type (token::TOKEN_SEVERITY, std::move (l));
      }
#else
      static
      symbol_type
      make_SEVERITY (const location_type& l)
      {
        return symbol_type (token::TOKEN_SEVERITY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLUSH (location_type l)
      {
        return symbol_type (token::TOKEN_FLUSH, std::move (l));
      }
#else
      static
      symbol_type
      make_FLUSH (const location_type& l)
      {
        return symbol_type (token::TOKEN_FLUSH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAXSIZE (location_type l)
      {
        return symbol_type (token::TOKEN_MAXSIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_MAXSIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAXSIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAXVER (location_type l)
      {
        return symbol_type (token::TOKEN_MAXVER, std::move (l));
      }
#else
      static
      symbol_type
      make_MAXVER (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAXVER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATTERN (location_type l)
      {
        return symbol_type (token::TOKEN_PATTERN, std::move (l));
      }
#else
      static
      symbol_type
      make_PATTERN (const location_type& l)
      {
        return symbol_type (token::TOKEN_PATTERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPLEVEL_JSON (location_type l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_JSON, std::move (l));
      }
#else
      static
      symbol_type
      make_TOPLEVEL_JSON (const location_type& l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_JSON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPLEVEL_DHCP6 (location_type l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_DHCP6, std::move (l));
      }
#else
      static
      symbol_type
      make_TOPLEVEL_DHCP6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_DHCP6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DHCP6 (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DHCP6, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DHCP6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DHCP6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_INTERFACES6 (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_INTERFACES6, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_INTERFACES6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_INTERFACES6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_SUBNET6 (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_SUBNET6, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_SUBNET6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_SUBNET6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_POOL6 (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_POOL6, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_POOL6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_POOL6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_PD_POOL (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_PD_POOL, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_PD_POOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_PD_POOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_RESERVATION (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_RESERVATION, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_RESERVATION (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_RESERVATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_OPTION_DEFS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DEFS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_OPTION_DEFS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DEFS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_OPTION_DEF (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DEF, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_OPTION_DEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_OPTION_DATA (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DATA, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_OPTION_DATA (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_OPTION_DATA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_HOOKS_LIBRARY (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_HOOKS_LIBRARY, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_HOOKS_LIBRARY (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_HOOKS_LIBRARY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DHCP_DDNS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DHCP_DDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DHCP_DDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DHCP_DDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_CONFIG_CONTROL (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_CONFIG_CONTROL, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_CONFIG_CONTROL (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_CONFIG_CONTROL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (int64_t v, location_type l)
      {
        return symbol_type (token::TOKEN_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const int64_t& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (double v, location_type l)
      {
        return symbol_type (token::TOKEN_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const double& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (bool v, location_type l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, v, l);
      }
#endif


    class context
    {
    public:
      context (const Dhcp6Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Dhcp6Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Dhcp6Parser (const Dhcp6Parser&);
    /// Non copyable.
    Dhcp6Parser& operator= (const Dhcp6Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const short yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const short yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if PARSER6_DEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1231,     ///< Last index in yytable_.
      yynnts_ = 424,  ///< Number of nonterminal symbols.
      yyfinal_ = 30 ///< Termination state number.
    };


    // User arguments.
    isc::dhcp::Parser6Context& ctx;

  };

  inline
  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const unsigned char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199
    };
    // Last valid token kind.
    const int code_max = 454;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  Dhcp6Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.copy< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Dhcp6Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Dhcp6Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Dhcp6Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Dhcp6Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Dhcp6Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Dhcp6Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Dhcp6Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Dhcp6Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 14 "dhcp6_parser.yy"
} } // isc::dhcp
#line 5287 "dhcp6_parser.h"




#endif // !YY_PARSER6_DHCP6_PARSER_H_INCLUDED
