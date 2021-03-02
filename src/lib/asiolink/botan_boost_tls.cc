// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

/// @file botan_boost_tls.cc Botan boost ASIO implementation of the TLS API.

#if defined(WITH_BOTAN) && defined(HAVE_BOTAN_ASIO_STREAM_H)

#include <asiolink/asio_wrapper.h>
#include <asiolink/crypto_tls.h>

#include <botan/auto_rng.h>

namespace isc {
namespace asiolink {

// Class of Kea credential managers.
class KeaCredentialsManager : public Botan::Credentials_Manager {
public:
    // Constructor.
    KeaCredentialsManager() {
    }

    // Destructor.
    virtual ~KeaCredentialsManager() {
    }
};

// Class of Kea policy.
// Use Strict_Policy?
class KeaPolicy : public Botan::TLS::Default_Policy {
public:
    // Constructor.
    KeaPolicy() {
    }

    // Destructor.
    virtual ~KeaPolicy() {
    }
};

// Class of Botan TLS context implementations.
class TlsContextImpl {
public:
    // Constructor.
    TlsContextImpl() : cred_mgr_(), rng_(), sess_mgr_(), policy_() {
    }

    // Destructor.
    virtual ~TlsContextImpl() {
    }

    // Credentials Manager.
    KeaCredentialsManager cred_mgr_;

    // Random Number Generator.
    Botan::AutoSeeded_RNG rng_;

    // Session Manager.
    Botan::TLS::Session_Manager_Noop sess_mgr_;

    KeaPolicy policy_;
};

TlsContext::TlsContext(TlsRole role)
    : TlsContextBase(role), cert_required_(true),
      context_(new TlsContextImpl()) {
}

Botan::TLS::Context
TlsContext::getContext() {
    return (Botan::TLS::Context(context_->cred_mgr_,
                                context_->rng_,
                                context_->sess_mgr_,
                                context_->policy_));
}

void
TlsContext::setCertRequired(bool cert_required) {
    cert_required_ = cert_required;
    // Todo
}

bool
TlsContext::getCertRequired() const {
    return (cert_required_);
}

void
TlsContext::loadCaFile(const std::string&) {
    // Todo.
}

void
TlsContext::loadCaPath(const std::string&) {
    isc_throw(NotImplemented, "loadCaPath is not implemented by Botan");
}

void
TlsContext::loadCertFile(const std::string&) {
    // Todo.
}

void
TlsContext::loadKeyFile(const std::string&) {
    // Todo.
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

#endif // WITH_BOTAN && HAVE_BOTAN_ASIO_STREAM_H
