// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#ifdef WITH_BOTAN

#include <asiolink/asio_wrapper.h>
#include <asiolink/crypto_tls.h>

namespace isc {
namespace asiolink {

TlsContext::TlsContext(TlsRole role)
    : TlsContextBase(role), cert_required_(true) {
}

void
TlsContext::setCertRequired(bool cert_required) {
    cert_required_ = cert_required;
}

bool
TlsContext::getCertRequired() const {
    return (cert_required_);
}

void
TlsContext::loadCaFile(const std::string&) {
    isc_throw(NotImplemented, "Botan TLS is not yet supported");
}

void
TlsContext::loadCaPath(const std::string&) {
    isc_throw(NotImplemented, "loadCaPath is not implemented by Botan");
}

void
TlsContext::loadCertFile(const std::string&) {
    isc_throw(NotImplemented, "Botan TLS is not yet supported");
}

void
TlsContext::loadKeyFile(const std::string&) {
    isc_throw(NotImplemented, "Botan TLS is not yet supported");
}

void
TlsContext::configure(TlsContextPtr& context,
                      TlsRole role,
                      const std::string& ca_file,
                      const std::string& cert_file,
                      const std::string& key_file,
                      bool cert_required) {
    try {
        context.reset(new TlsContext(role));
        context->loadCaFile(ca_file);
        context->loadCertFile(cert_file);
        context->loadKeyFile(key_file);
        context->setCertRequired(cert_required);
    } catch (...) {
        context.reset();
        throw;
    }
}

} // namespace asiolink
} // namespace isc

#endif // WITH_BOTAN
