// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// Do not include this header directly: use crypto_tls.h instead.

#ifndef BOTAN_BOOST_TLS_H
#define BOTAN_BOOST_TLS_H

/// @file botan_boost_tls.h Botan boost ASIO implementation of the TLS API.

#if defined(WITH_BOTAN) && defined(HAVE_BOTAN_ASIO_STREAM_H)

#include <asiolink/asio_wrapper.h>
#include <asiolink/io_asio_socket.h>
#include <asiolink/io_service.h>
#include <asiolink/common_tls.h>
#include <exceptions/exceptions.h>

#include <asiolink/botan_boost_wrapper.h>
#include <botan/asio_stream.h>

namespace isc {
namespace asiolink {

/// @brief Translate TLS role into implementation.
inline Botan::TLS::Connection_Side roleToImpl(TlsRole role) {
    if (role == TlsRole::SERVER) {
        return (Botan::TLS::Connection_Side::SERVER);
    } else {
        return (Botan::TLS::Connection_Side::CLIENT);
    }
}

/// @brief Forward declaration of Botan TLS context.
class TlsContextImpl;

/// @brief Botan boost ASIO TLS context.
class TlsContext : public TlsContextBase {
public:

    /// @brief Destructor.
    virtual ~TlsContext() { }

    /// @brief Create a fresh context.
    ///
    /// @param role The TLS role client or server.
    explicit TlsContext(TlsRole role);

    /// @brief Return the underlying context.
    Botan::TLS::Context getContext();

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

    /// @brief Configure.
    ///
    /// @param context The TLS context to configure.
    /// @param role The TLS role client or server.
    /// @param ca_file The certificate file or directory name.
    /// @param cert_file The certificate file name.
    /// @param key_file The private key file name.
    /// @param cert_required True if peer certificates are required,
    /// false if they are optional.
    static void configure(TlsContextPtr& context,
                          TlsRole role,
                          const std::string& ca_file,
                          const std::string& cert_file,
                          const std::string& key_file,
                          bool cert_required);

protected:
    /// @brief Cached cert_required value.
    bool cert_required_;

    /// @brief Botan TLS context.
    std::unique_ptr<TlsContextImpl> context_;
};

/// @brief The type of underlying TLS streams.
typedef Botan::TLS::Stream<boost::asio::ip::tcp::socket> TlsStreamImpl;

/// @brief The type of X509 certificates.
typedef Botan::X509_Certificate TlsCertificate;

/// @brief TlsStreamBase constructor.
///
/// @tparam Callback The type of callbacks.
/// @tparam TlsStreamImpl The type of underlying TLS streams.
/// @tparam TlsCertificate The type of X509 certificates.
/// @param service I/O Service object used to manage the stream.
/// @param context Pointer to the TLS context.
/// @note The caller must not provide a null pointer to the TLS context.
template <typename Callback, typename TlsStreamImpl, typename TlsCertificate>
TlsStreamBase<Callback, TlsStreamImpl, TlsCertificate>::
TlsStreamBase(IOService& service, TlsContextPtr context)
    : TlsStreamImpl(service.get_io_service(), context->getContext()),
      role_(context->getRole()) {
}

/// @brief Botan boost ASIO TLS stream.
///
/// @tparam callback The callback.
template <typename Callback>
class TlsStream : public TlsStreamBase<Callback, TlsStreamImpl, TlsCertificate> {
public:

    /// @brief Type of the base.
    typedef TlsStreamBase<Callback, TlsStreamImpl, TlsCertificate> Base;

    /// @brief Constructor.
    ///
    /// @param service I/O Service object used to manage the stream.
    /// @param context Pointer to the TLS context.
    /// @note The caller must not provide a null pointer to the TLS context.
    TlsStream(IOService& service, TlsContextPtr context)
        : Base(service, context) {
    }

    /// @brief Destructor.
    virtual ~TlsStream() { }

    /// @brief TLS Handshake.
    ///
    /// @param callback Callback object.
    virtual void handshake(Callback& callback) {
        Base::async_handshake(roleToImpl(Base::getRole()), callback);
    }

    /// @brief TLS shutdown.
    ///
    /// @param callback Callback object.
    virtual void shutdown(Callback& callback) {
        Base::async_shutdown(callback);
    }

    /// @brief Clear the SSL object.
    ///
    /// @note The idea to reuse a TCP connection for a fresh TLS is at
    /// least arguable.
    /// @throw @c isc::NotImplemented
    virtual void clear() {
        isc_throw(NotImplemented,
                  "Botan TLS does not support the clear operation");
    }

    /// @brief Return the peer certificate.
    ///
    /// @note The native_handle() method is used so it can't be made const.
    /// @note Do not forget to free it when no longer used.
    virtual TlsCertificate* getPeerCert() {
        /// @todo
        return (0);
    }

    /// @brief Return the commonName part of the subjectName of
    /// the peer certificate.
    ///
    /// First commonName when there are more than one, in UTF-8.
    ///
    /// @return The commonName part of the subjectName or the empty string.
    virtual std::string getSubject() {
        /// @todo
        return ("");
    }

    /// @brief Return the commonName part of the issuerName of
    /// the peer certificate.
    ///
    /// First commonName when there are more than one, in UTF-8.
    ///
    /// @return The commonName part of the issuerName or the empty string.
    virtual std::string getIssuer() {
        /// @todo
        return ("");
    }
};

} // namespace asiolink
} // namespace isc

#endif // WITH_BOTAN && HAVE_BOTAN_ASIO_STREAM_H

#endif // BOTAN_BOOST_TLS_H
