// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef HTTP_TLS_CONTEXT_H
#define HTTP_TLS_CONTEXT_H

#include <boost/asio/ssl/context.hpp>
#include <string>

namespace isc {
namespace http {
namespace test {

/// @brief Adds the CA path to a filename.
///
/// @param filename The base name of the file.
/// @return The full name of the file.
inline std::string CA(const std::string& filename) {
    return (std::string(TEST_CA_DIR) + "/" + filename);
}

/// @brief Setup a server TLS context.
///
/// @param context Reference to the context to setup.
void server_setup(boost::asio::ssl::context& context) {
    context.load_verify_file(CA("kea-ca.crt"));
    context.use_certificate_file(CA("kea-server.crt"),
                                 boost::asio::ssl::context::file_format::pem);
    context.use_private_key_file(CA("kea-server.key"),
                                 boost::asio::ssl::context::file_format::pem);
}

/// @brief Setup a client TLS context.
///
/// @param context Reference to the context to setup.
void client_setup(boost::asio::ssl::context& context) {
    context.load_verify_file(CA("kea-ca.crt"));
    context.use_certificate_file(CA("kea-client.crt"),
                                 boost::asio::ssl::context::file_format::pem);
    context.use_private_key_file(CA("kea-client.key"),
                                 boost::asio::ssl::context::file_format::pem);
}

} // namespace test
} // namespace http
} // namespace isc

#endif
