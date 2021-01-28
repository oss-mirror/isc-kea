// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef CMD_RESPONSE_CREATOR_FACTORY_H
#define CMD_RESPONSE_CREATOR_FACTORY_H

#include <config/cmd_response_creator.h>
#include <http/response_creator_factory.h>

namespace isc {
namespace config {

/// @brief HTTP response creator factory for an API listener
///
/// @param emulate_agent_response if true results for normal command
/// outcomes are wrapped in Element::list.  This emulates responses
/// generated by kea-ctrl-agent.  The value is passed into the
/// CmdResponseCreator when created. Defaults to true.
///
/// See the documentation of the @ref isc::http::HttpResponseCreatorFactory
/// for the details how the response factory object is used by the
/// @ref isc::http::HttpListener.
///
/// This class always returns the same instance of the
/// @ref CmdResponseCreator which @ref isc::http::HttpListener and
/// @ref isc::http::HttpConnection classes use to generate HTTP response
/// messages which comply with the formats required by the Control Agent.
class CmdResponseCreatorFactory : public http::HttpResponseCreatorFactory {
public:

    /// @brief Constructor.
    ///
    /// Creates sole instance of the @ref CmdResponseCreator object
    /// returned by the @ref CmdResponseCreatorFactory::create.
    ///
    /// @param emulate_agent_response if true, responses for normal
    /// command outcomes are guaranteed to be wrapped in an Element::list.
    /// This emulates how kea-ctrl-agent forms responses.  Defaults to true.
    CmdResponseCreatorFactory(bool emulate_agent_response = true)
        : sole_creator_(new CmdResponseCreator(emulate_agent_response)) {
    }

    /// @brief Returns an instance of the @ref CmdResponseCreator which
    /// is used by HTTP server to generate responses to commands.
    ///
    /// @return Pointer to the @ref CmdResponseCreator object.
    virtual http::HttpResponseCreatorPtr create() const {
        return (sole_creator_);
    }

private:

    /// @brief Instance of the @ref CmdResponseCreator returned.
    http::HttpResponseCreatorPtr sole_creator_;
};

} // end of namespace isc::config
} // end of namespace isc

#endif