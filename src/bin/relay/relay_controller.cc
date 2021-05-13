// Copyright (C) 2016-2020 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <relay/relay_controller.h>
#include <relay/relay_process.h>
#include <relay/relay_command_mgr.h>
#include <relay/parser_context.h>
#include <cfgrpt/config_report.h>
#include <functional>

using namespace isc::process;
namespace ph = std::placeholders;

namespace isc {
namespace relay {

/// @brief Defines the application name, this is passed into base class
/// it may be used to locate configuration data and appears in log statement.
const char* RelayController::relay_app_name_ = "Relay";

/// @brief Defines the executable name. This is passed into the base class
const char* RelayController::relay_bin_name_ = "kea-relay";

DControllerBasePtr&
RelayController::instance() {
    // If the instance hasn't been created yet, create it.  Note this method
    // must use the base class singleton instance methods.
    if (!getController()) {
        DControllerBasePtr controller_ptr(new RelayController());
        setController(controller_ptr);
    }

    return (getController());
}

DProcessBase*
RelayController::createProcess() {
    // Instantiate and return an instance of the D2 application process. Note
    // that the process is passed the controller's io_service.
    return (new RelayProcess(getAppName().c_str(), getIOService()));
}

isc::data::ConstElementPtr
RelayController::parseFile(const std::string& name) {
    ParserContext parser;
    return (parser.parseFile(name, ParserContext::PARSER_RELAY));
}

void
RelayController::registerCommands() {
    RelayCommandMgr::instance().registerCommand(BUILD_REPORT_COMMAND,
        std::bind(&DControllerBase::buildReportHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(CONFIG_GET_COMMAND,
        std::bind(&DControllerBase::configGetHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(CONFIG_RELOAD_COMMAND,
        std::bind(&DControllerBase::configReloadHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(CONFIG_SET_COMMAND,
        std::bind(&DControllerBase::configSetHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(CONFIG_TEST_COMMAND,
        std::bind(&DControllerBase::configTestHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(CONFIG_WRITE_COMMAND,
        std::bind(&DControllerBase::configWriteHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(SHUT_DOWN_COMMAND,
        std::bind(&DControllerBase::shutdownHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(STATUS_GET_COMMAND,
        std::bind(&DControllerBase::statusGetHandler, this, ph::_1, ph::_2));

    RelayCommandMgr::instance().registerCommand(VERSION_GET_COMMAND,
        std::bind(&DControllerBase::versionGetHandler, this, ph::_1, ph::_2));
}

void
RelayController::deregisterCommands() {
    RelayCommandMgr::instance().deregisterCommand(BUILD_REPORT_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(CONFIG_GET_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(CONFIG_RELOAD_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(CONFIG_SET_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(CONFIG_TEST_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(CONFIG_WRITE_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(SHUT_DOWN_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(STATUS_GET_COMMAND);
    RelayCommandMgr::instance().deregisterCommand(VERSION_GET_COMMAND);
}

RelayController::RelayController()
    : DControllerBase(relay_app_name_, relay_bin_name_) {
}

RelayController::~RelayController() {
}

RelayProcessPtr
RelayController::getRelayProcess() {
    return (boost::dynamic_pointer_cast<RelayProcess>(getProcess()));
}

// Refer to config_report so it will be embedded in the binary.
const char* const* ca_config_report = isc::detail::config_report;

} // namespace isc::agent
} // namespace isc
