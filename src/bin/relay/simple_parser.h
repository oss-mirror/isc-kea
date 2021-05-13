// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef RELAY_SIMPLE_PARSER_H
#define RELAY_SIMPLE_PARSER_H

#include <cc/simple_parser.h>
#include <relay/relay_cfg_mgr.h>

namespace isc {
namespace relay {

/// @brief SimpleParser specialized for Relay
///
/// This class is a @ref isc::data::SimpleParser dedicated to Relay.
/// In particular, it contains all the default values for the whole
/// agent and for the socket defaults.
///
/// For the actual values, see @file agent/simple_parser.cc
class AgentSimpleParser : public isc::data::SimpleParser {
public:
    /// @brief Sets all defaults for Relay configuration
    ///
    /// This method sets global, option data and option definitions defaults.
    ///
    /// @param global scope to be filled in with defaults.
    /// @return number of default values added
    static size_t setAllDefaults(const isc::data::ElementPtr& global);

    /// @brief Parses the Relay configuration
    ///
    /// @param ctx - parsed information will be stored here
    /// @param config - Element tree structure that holds configuration
    /// @param check_only - if true the configuration is verified only, not applied
    ///
    /// @throw ConfigError if any issues are encountered.
    void parse(const RelayConfigPtr& ctx,
               const isc::data::ConstElementPtr& config,
               bool check_only);

    // see simple_parser.cc for comments for those parameters
    static const isc::data::SimpleDefaults RELAY_DEFAULTS;
};

}
}
#endif
