// Copyright (C) 2016-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <relay/relay_cfg_mgr.h>
#include <relay/relay_log.h>
#include <relay/simple_parser.h>
#include <cc/simple_parser.h>
#include <cc/command_interpreter.h>
#include <exceptions/exceptions.h>

using namespace isc::config;
using namespace isc::dhcp;
using namespace isc::process;
using namespace isc::data;

namespace isc {
namespace relay {

RelayConfig::RelayConfig() {
}

RelayConfig::RelayConfig(const RelayConfig& orig)
    : ConfigBase() {
}

RelayCfgMgr::RelayCfgMgr()
    : DCfgMgrBase(ConfigPtr(new RelayConfig())) {
}

RelayCfgMgr::~RelayCfgMgr() {
}

std::string
RelayCfgMgr::getConfigSummary(const uint32_t /*selection*/) {

    RelayConfigPtr ctx = getRelayConfig();

    std::stringstream s;
    s << "not implemented yet, control sockets: ";

    // Finally, print the hook libraries names
    const isc::hooks::HookLibsCollection libs = ctx->getHooksConfig().get();
    s << ", " << libs.size() << " lib(s):";
    for (auto lib = libs.begin(); lib != libs.end(); ++lib) {
        s << lib->first << " ";
    }

    return (s.str());
}

ConfigPtr
RelayCfgMgr::createNewContext() {
    return (ConfigPtr(new RelayConfig()));
}

ConstElementPtr
RelayCfgMgr::parse(ConstElementPtr config_set, bool check_only) {
    // Do a sanity check first.
    if (!config_set) {
        isc_throw(DhcpConfigError, "Mandatory config parameter not provided");
    }

    RelayConfigPtr ctx = getRelayConfig();

    // Set the defaults
    ElementPtr cfg = boost::const_pointer_cast<Element>(config_set);
    AgentSimpleParser::setAllDefaults(cfg);

    // And parse the configuration.
    ConstElementPtr answer;
    std::string excuse;
    try {
        // Do the actual parsing
        AgentSimpleParser parser;
        parser.parse(ctx, cfg, check_only);
    } catch (const isc::Exception& ex) {
        excuse = ex.what();
        answer = createAnswer(CONTROL_RESULT_ERROR, excuse);
    } catch (...) {
        excuse = "undefined configuration parsing error";
        answer = createAnswer(CONTROL_RESULT_ERROR, excuse);
    }

    // At this stage the answer was created only in case of exception.
    if (answer) {
        if (check_only) {
            LOG_ERROR(relay_logger, RELAY_CONFIG_CHECK_FAIL).arg(excuse);
        } else {
            LOG_ERROR(relay_logger, RELAY_CONFIG_FAIL).arg(excuse);
        }
        return (answer);
    }

    if (check_only) {
        answer = createAnswer(CONTROL_RESULT_SUCCESS,
                              "Configuration check successful");
    } else {
        answer = createAnswer(CONTROL_RESULT_SUCCESS,
                              "Configuration applied successfully.");
    }

    return (answer);
}

ConstElementPtr
RelayCfgMgr::redactConfig(ConstElementPtr config) const {
    bool redacted = false;
    ConstElementPtr result = redactElement(config, redacted);
    if (redacted) {
        return (result);
    }
    return (config);
}

ConstElementPtr
RelayCfgMgr::redactElement(ConstElementPtr elem, bool& redacted) const {
    // From isc::data::copy.
    if (!elem) {
        isc_throw(BadValue, "redactElement got a null pointer");
    }
    // Redact lists.
    if (elem->getType() == Element::list) {
        ElementPtr result = ElementPtr(new ListElement());
        for (auto item : elem->listValue()) {
            // add wants a ElementPtr so use a shallow copy.
            ElementPtr copy = data::copy(redactElement(item, redacted), 0);
            result->add(copy);
        }
        if (redacted) {
            return (result);
        }
        return (elem);
    }
    // Redact maps.
    if (elem->getType() == Element::map) {
        ElementPtr result = ElementPtr(new MapElement());
        for (auto kv : elem->mapValue()) {
            auto key = kv.first;
            auto value = kv.second;

            if (key == "password") {
                // Handle passwords.
                redacted = true;
                result->set(key, Element::create(std::string("*****")));
            } else if ((key == "Control-agent") ||
                       (key == "authentication") ||
                       (key == "clients")) {
                // Handle the arc where are passwords.
                result->set(key, redactElement(value, redacted));
            } else {
                // Default case: no password here.
                result->set(key, value);
            }
        }
        if (redacted) {
            return (result);
        }
        return (elem);
    }
    // Handle other element types.
    return (elem);
}

ElementPtr
RelayConfig::toElement() const {
    ElementPtr ca = ConfigBase::toElement();
    // Set user-context
    contextToElement(ca);

    ca->set("hooks-libraries", hooks_config_.toElement());

    // Set Relay
    ElementPtr result = Element::createMap();
    result->set("Relay", ca);

    return (result);
}

} // namespace isc::agent
} // namespace isc
