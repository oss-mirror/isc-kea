// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#ifdef WITH_OPENSSL

#include <asiolink/crypto_tls.h>
#include <asiolink/openssl_tls.h>

using namespace boost::asio;
using namespace boost::asio::ssl;
using namespace boost::system;
using namespace isc::cryptolink;

namespace isc {
namespace asiolink {

OpenSslTlsContext::OpenSslTlsContext(TlsRole role)
    : TlsContext(role), cert_required_(true), context_(context::method::tls) {
}

OpenSslTlsContext&
OpenSslTlsContext::clone() {
    SSL_CTX_up_ref(context_.native_handle());
    return (*this);
}

void
OpenSslTlsContext::setCertRequired(bool cert_required) {
    cert_required_ = cert_required;
    error_code ec;
    int mode = verify_peer | verify_fail_if_no_peer_cert;
    if (!cert_required_) {
        mode = verify_none;
    }
    context_.set_verify_mode(mode, ec);
    if (ec) {
        isc_throw(LibraryError, ec.message());
    }
}

bool
OpenSslTlsContext::getCertRequired() const {
    return (cert_required_);
}

void
OpenSslTlsContext::loadCaFile(const std::string& ca_file) {
    error_code ec;
    context_.load_verify_file(ca_file, ec);
    if (ec) {
        isc_throw(LibraryError, ec.message());
    }
}

void
OpenSslTlsContext::loadCaPath(const std::string& ca_path) {
    error_code ec;
    context_.add_verify_path(ca_path, ec);
    if (ec) {
        isc_throw(LibraryError, ec.message());
    }
}

void
OpenSslTlsContext::loadCertFile(const std::string& cert_file) {
    error_code ec;
    context_.use_certificate_chain_file(cert_file, ec);
    if (ec) {
        isc_throw(LibraryError, ec.message());
    }
}

void
OpenSslTlsContext::loadKeyFile(const std::string& key_file) {
    error_code ec;
    context_.use_private_key_file(key_file, context::file_format::pem, ec);
    if (ec) {
        isc_throw(LibraryError, ec.message());
    }
}

} // namespace asiolink
} // namespace isc

#endif // WITH_OPENSSL
