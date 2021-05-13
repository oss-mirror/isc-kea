// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef RELAY_COMMAND_MGR_H
#define RELAY_COMMAND_MGR_H

#include <config/hooked_command_mgr.h>
#include <exceptions/exceptions.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace isc {
namespace relay {

/// @brief Exception thrown when an error occurred during control command
/// forwarding.
class CommandForwardingError : public Exception {
public:
    CommandForwardingError(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) { };
};

/// @brief Command Manager for Relay.
///
/// This is an implementation of the Command Manager within Relay.
/// In addition to the standard capabilities of the @ref HookedCommandMgr
/// it is also intended to forward commands to the respective Kea servers
/// when the command is not supported directly by the Relay.
///
/// The @ref RelayCommandMgr is implemented as a singleton. The commands
/// are registered using @c RelayCommandMgr::instance().registerCommand().
/// The @ref RelayResponseCreator uses the sole instance of the Command
/// Manager to handle incoming commands.
class RelayCommandMgr : public config::HookedCommandMgr,
                            public boost::noncopyable {
public:

    /// @brief Returns sole instance of the Command Manager.
    static RelayCommandMgr& instance();

    /// @brief Triggers command processing.
    ///
    /// This method overrides the @c BaseCommandMgr::processCommand to ensure
    /// that the response is always wrapped in a list. The base implementation
    /// returns a response map. Kea Relay forwards commands to multiple
    /// daemons behind it and thus it must return a list of responses from
    /// respective daemons. If an error occurs during command processing the
    /// error response must also be wrapped in a list because caller expects
    /// that CA always returns a list.
    ///
    /// This method is an entry point for dealing with a command. Internally
    /// it calls @c RelayCommandMgr::handleCommand.
    ///
    /// @param cmd Pointer to the data element representing command in JSON
    /// format.
    /// @return Pointer to the response.
    virtual isc::data::ConstElementPtr
    processCommand(const isc::data::ConstElementPtr& cmd);

    /// @brief Handles the command having a given name and arguments.
    ///
    /// This method extends the base implementation with the ability to forward
    /// commands to Kea servers.
    ///
    /// If the received command doesn't include 'service' parameter or this
    /// parameter is blank, the command is first handled by the attached hooks
    /// libraries, and if still unhandled, the Relay itself.
    ///
    /// If the non-blank 'service' parameter has been specified the hooks
    /// are executed. If the hooks process the command the result is returned
    /// to the controlling client. Otherwise, the command is forwarded to each
    /// Kea server listed in the 'service' parameter.
    ///
    /// @param cmd_name Command name.
    /// @param params Command arguments.
    /// @param original_cmd Original command being processed.
    ///
    /// @return Pointer to the const data element representing a list of
    /// responses to the command. If the command has been handled by the CA,
    /// this list includes one response.
    virtual isc::data::ConstElementPtr
    handleCommand(const std::string& cmd_name,
                  const isc::data::ConstElementPtr& params,
                  const isc::data::ConstElementPtr& original_cmd);

private:

    /// @brief Private constructor.
    ///
    /// The instance should be created using @ref RelayCommandMgr::instance,
    /// thus the constructor is private.
    RelayCommandMgr();

};

} // end of namespace isc::relay
} // end of namespace isc

#endif
