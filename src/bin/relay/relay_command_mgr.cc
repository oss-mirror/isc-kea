// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <relay/relay_cfg_mgr.h>
#include <relay/relay_command_mgr.h>
#include <relay/relay_controller.h>
#include <relay/relay_log.h>
#include <relay/relay_process.h>
#include <asiolink/asio_wrapper.h>
#include <asiolink/io_service.h>
#include <asiolink/unix_domain_socket.h>
#include <cc/command_interpreter.h>
#include <cc/data.h>
#include <cc/json_feed.h>
#include <config/client_connection.h>
#include <config/timeouts.h>
#include <boost/pointer_cast.hpp>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace isc::asiolink;
using namespace isc::config;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::process;

namespace isc {
namespace relay {

RelayCommandMgr&
RelayCommandMgr::instance() {
    static RelayCommandMgr command_mgr;
    return (command_mgr);
}

RelayCommandMgr::RelayCommandMgr()
    : HookedCommandMgr() {
}

isc::data::ConstElementPtr
RelayCommandMgr::processCommand(const isc::data::ConstElementPtr& cmd) {
    ConstElementPtr answer = HookedCommandMgr::processCommand(cmd);

    // Responses from the Kea Relay must be always wrapped
    // in a list because in general they contain responses from
    // multiple daemons.
    if (answer->getType() == Element::list) {
        return (answer);
    }
    ElementPtr answer_list = Element::createList();
    answer_list->add(boost::const_pointer_cast<Element>(answer));

    return (answer_list);
}

ConstElementPtr
RelayCommandMgr::handleCommand(const std::string& cmd_name,
                                   const isc::data::ConstElementPtr& params,
                                   const isc::data::ConstElementPtr& original_cmd) {

    // It is frequent user error to not include the 'service' parameter in
    // the commands that should be forwarded to Kea servers. If the command
    // lacks this parameter the CA will try to process it and often fail
    // because it is not supported by the CA. In the future we may want to
    // make this parameter mandatory. For now, we're going to improve the
    // situation by clearly explaining to the controlling client that the
    // command is not supported by the CA, but it is possible that he may
    // achieve what he wants by providing the 'service' parameter.

    // Our interface is very restrictive so we walk around this by const
    // casting the returned pointer. It is certainly easier to do than
    // changing the whole data interface.
    ElementPtr answer = boost::const_pointer_cast<Element>
        (HookedCommandMgr::handleCommand(cmd_name, params, original_cmd));

    try {
        // Check what error code was returned by the handler.
        int rcode = 0;
        ConstElementPtr text = parseAnswer(rcode, answer);
    } catch (...) {
        // Exceptions are not really possible assuming that the BaseCommandMgr
        // creates the response correctly.
    }

    // Before the command is forwarded we check if there are any hooks libraries
    // which would process the command.
    if (HookedCommandMgr::delegateCommandToHookLibrary(cmd_name, params, original_cmd,
                                                       answer)) {
        // The command has been processed by hooks library. Return the result.
        return (answer);
    }

    return (answer);
}

} // end of namespace isc::agent
} // end of namespace isc
