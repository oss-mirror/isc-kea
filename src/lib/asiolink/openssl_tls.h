// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENSSL_TLS_H
#define OPENSSL_TLS_H

#ifdef WITH_OPENSSL

#include <boost/asio/ssl.hpp>

namespace isc {
namespace asiolink {

/// @brief OpenSSL TLS context.
class OpenSslTlsContext : public TlsContext {
public:

    /// @brief Destructor.
    virtual ~OpenSslTlsContext() { }

    /// @brief Create a fresh context.
    ///
    /// @param role The TLS role client or server.
    explicit OpenSslTlsContext(TlsRole role);

    /// @param Clone the context.
    ///
    /// Boost ASIO uses a move constructor which "eats" the context,
    /// this updates the OpenSSL reference count so the object is not freed.
    virtual OpenSslTlsContext& clone();

    /// @brief Set the peer certificate requirement mode.
    ///
    /// @param cert_required True if peer certificates are required,
    /// false if they are optional.
    virtual void setCertRequired(bool cert_required);

    /// @brief Get the peer certificate requirement mode.
    ///
    /// @return True if peer certificates are required, false if they
    /// are optional.
    virtual bool getCertRequired() const;

    /// @brief Load the trust anchor aka certificate authority.
    ///
    /// @param ca_file The certificate file name.
    virtual void loadCaFile(const std::string& ca_file);

    /// @brief Load the trust anchor aka certificate authority.
    ///
    /// @param ca_path The certificate directory name.
    virtual void loadCaPath(const std::string& ca_path);

    /// @brief Load the certificate file.
    ///
    /// @param cert_file The certificate file name.
    virtual void loadCertFile(const std::string& cert_file);

    /// @brief Load the private key file name.
    ///
    /// @param key_file The private key file name.
    virtual void loadKeyFile(const std::string& key_file);

protected:
    /// @brief Cached cert_required value (no get function in OpenSSL).
    bool cert_required_;

    /// @brief Boost ASIO SSL object.
    boost::asio::ssl::context context_;
};

} // namespace asiolink
} // namespace isc

#endif // WITH_OPENSSL

#endif // OPENSSL_TLS_H
