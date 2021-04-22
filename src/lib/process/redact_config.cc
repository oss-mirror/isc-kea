// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <process/redact_config.h>

/// @note This file implements a hairy algorithm to do a little or no
/// transform on a data structure with no side effect and maximum sharing.
/// The original version was in CAML (ancestor of OCaml) using a local
/// exception so this C++ version is pretty different but the base idea
/// is still the same.
///
/// Consider values a, b, ... from the space A. When a value is modified
/// let add a star on it so you have the original / sharable value a and
/// the modified / copied a*.
/// The idea is to extend this to base data structures. Let take the pair
/// as the example: (a, b) can be transformed into 4 cases:
///  - unchanged / shared: (a, b)
///  - first modified / copied: (a*, b)*
///  - second modified / copied: (a, b*)*
///  - both members modified / copied: (a*, b*)*
/// The key point is the addition of the star at the end of the pair when
/// the whole pair was modified / copied / not sharable.
/// This can be extended to lists, maps, etc. The final result of the
/// transform on the tree t is either t or t*.
///
/// The last point is in the coding of the A + A* space. Both the original
/// Caml code and the C++ code below uses the fact that it is not required
/// to implement the A space part: the value to return is the argument.
/// So the recursive function implementing the transform in a tree walk
/// has to return the modified / copied value or the fact that the
/// argument can be shared: the CAML code raises a local exception named
/// shared, this C++ code returns the null element pointer to code this fact.

using namespace isc::data;
using namespace std;

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
        isc_throw(isc::BadValue, "redact got a null pointer");
    }

    // Redact lists.
    if (elem->getType() == Element::list) {
        ElementPtr result = Element::createList();
        bool redacted = false;
        for (ElementPtr item : elem->listValue()) {
            ElementPtr copy = redact(follow, item);
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
        ElementPtr result = Element::createMap();
        bool redacted = false;
        for (auto kv : elem->mapValue()) {
            const string& key = kv.first;
            size_t keylen = key.size();
            ConstElementPtr value = kv.second;

            // The following keys are meant to be matched:
            // "basic-auth-password", "password", "secret".
            if (((keylen >= 8) &&
                 (key.compare(keylen - 8, string::npos, "password") == 0)) ||
                ((keylen >= 6) &&
                 (key.compare(keylen - 6, string::npos, "secret") == 0))) {
                // Handle passwords and secrets.
                redacted = true;
                result->set(key, Element::create(std::string("*****")));
            } else if (key == "user-context") {
                // Skip user contexts.
                result->set(key, value);
            } else if (key == "parameters") {
                // Follow hook parameters.
                ConstElementPtr copy = redact({ }, value);
                if (copy) {
                    redacted = true;
                    result->set(key, copy);
                } else {
                    result->set(key, value);
                }
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

namespace isc {
namespace process {

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
