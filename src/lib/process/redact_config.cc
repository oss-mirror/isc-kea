// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <process/redact_config.h>

using namespace isc::data;
using namespace std;

namespace isc {
namespace process {

namespace {

/// @brief Redact recursive function.
///
/// As lists are vectors of ElementPtr and maps are maps of string and
/// ConstElementPtr a template is needed.
///
/// @tparam ElementPtrType Either @c ElementPtr or @c ConstElementPtr,
/// @param follow The set of keywords of subtrees where a password or a
/// secret can be found.
/// @param elem the Element tree structure that describes the configuration.
/// @return Either a copy of the modified element argument or null which
/// means the caller can use / share the not modified element argument
template<typename ElementPtrType>
ElementPtrType redact(const set<string>& follow, ElementPtrType elem) {
    // From isc::data::copy.
    if (!elem) {
        isc_throw(BadValue, "redact got a null pointer");
    }

    // Redact lists.
    if (elem->getType() == Element::list) {
        ElementPtr result = ElementPtr(new ListElement());
        bool redacted = false;
        for (ElementPtr item : elem->listValue()) {
            ElementPtr copy = redact<ElementPtr>(follow, item);
            if (copy) {
                redacted = true;
                result->add(copy);
            } else {
                result->add(item);
            }
        }
        if (redacted) {
            return (result);
        } else {
            return (ElementPtrType());
        }
    }

    // Redact maps.
    if (elem->getType() == Element::map) {
        ElementPtr result = ElementPtr(new MapElement());
        bool redacted = false;
        for (auto kv : elem->mapValue()) {
            const string& key = kv.first;
            ConstElementPtr value = kv.second;

            if ((key == "password") || (key == "secret")) {
                // Handle passwords.
                redacted = true;
                result->set(key, Element::create(std::string("*****")));
            } else if (key == "user-context") {
                // Skip user contexts.
                result->set(key, value);
            } else if (follow.empty() || follow.count(key)) {
                // Handle this subtree where are passwords or secrets.
                ConstElementPtr copy = redact(follow, value);
                if (copy) {
                    redacted = true;
                    result->set(key, copy);
                } else {
                    result->set(key, value);
                }
            } else {
                // Not follow: no passwords and secrets in this subtree.
                result->set(key, value);
            }
        }
        if (redacted) {
            return (result);
        } else {
            return (ElementPtrType());
        }
    }

    // Handle other element types.
    return (ElementPtrType());
}

} // end of anonymous namespace.

ConstElementPtr
redactElem(const set<string>& follow, ConstElementPtr elem) {
    ConstElementPtr copy = redact<ConstElementPtr>(follow, elem);
    if (copy) {
        return (copy);
    } else {
        return (elem);
    }
}

ConstElementPtr
redactGeneric(ConstElementPtr elem) {
    return (redactElem({ }, elem));
}

} // namespace process
} // namespace isc
