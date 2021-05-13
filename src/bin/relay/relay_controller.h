// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef RELAY_CONTROLLER_H
#define RELAY_CONTROLLER_H

#include <relay/relay_process.h>
#include <process/d_controller.h>

namespace isc {
namespace relay {

/// @brief Process Controller for Relay.
///
/// This class is the Control Agent specific derivation of the DControllerBase.
/// It creates and manages an instance of the Control Agent application process,
/// RelayProcess.
class RelayController : public process::DControllerBase {
public:

    /// @brief Static singleton instance method.
    ///
    /// This method returns the base class singleton instance member.
    /// It instantiates the singleton and sets the base class instance
    /// member upon first invocation.
    ///
    /// @return returns the pointer reference to the singleton instance.
    static process::DControllerBasePtr& instance();

    /// @brief Destructor
    virtual ~RelayController();

    /// @brief Returns pointer to an instance of the underlying process object.
    RelayProcessPtr getRelayProcess();

    /// @brief Defines the application name, this is passed into base class
    /// and appears in log statements.
    static const char* relay_app_name_;

    /// @brief Defines the executable name. This is passed into the base class
    /// by convention this should match the executable name.
    static const char* relay_bin_name_;

    /// @brief Parses the configuration file using Agent::ParserContext (bison)
    ///
    /// @param name name of the text file to be parsed
    /// @return Element tree structure representing parsed configuration
    isc::data::ConstElementPtr
    parseFile(const std::string& name);

    /// @brief Register commands.
    void registerCommands();

    /// @brief Deregister commands.
    void deregisterCommands();

private:

    /// @brief Creates an instance of the Control Agent application
    /// process.
    ///
    /// This method is invoked during the process initialization step of
    /// the controller launch.
    ///
    /// @return returns a DProcessBase* to the application process created.
    /// Note the caller is responsible for destructing the process. This
    /// is handled by the base class, which wraps this pointer with a smart
    /// pointer.
    virtual process::DProcessBase* createProcess();

    /// @brief Constructor is declared private to maintain the integrity of
    /// the singleton instance.
    RelayController();
};

// @Defines a shared pointer to RelayController
typedef boost::shared_ptr<RelayController> RelayControllerPtr;

} // namespace isc::relay
} // namespace isc

#endif // RELAY_CONTROLLER_H
