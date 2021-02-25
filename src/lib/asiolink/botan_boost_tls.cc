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
<<<<<<< HEAD
#include <botan/certstor_flatfile.h>
#include <botan/data_src.h>
#include <botan/pem.h>
#include <botan/pkcs8.h>

using namespace isc::cryptolink;
=======
>>>>>>> [#1665] Checkpoint

namespace isc {
namespace asiolink {

<<<<<<< HEAD
// Classes of Kea certificate stores.
using KeaCertificateStorePath = Botan::Certificate_Store_In_Memory;
using KeaCertificateStoreFile = Botan::Flatfile_Certificate_Store;

=======
>>>>>>> [#1665] Checkpoint
// Class of Kea credential managers.
class KeaCredentialsManager : public Botan::Credentials_Manager {
public:
    // Constructor.
<<<<<<< HEAD
    KeaCredentialsManager() : store_(), use_stores_(true), certs_(), key_() {
    }

    // Destructor.
    virtual ~KeaCredentialsManager() {
    }

    // CA certificate stores.
    // nullptr means do not require or check peer certificate.
    std::vector<Botan::Certificate_Store*>
    trusted_certificate_authorities(const std::string&,
                                    const std::string&) override {
        std::vector<Botan::Certificate_Store*> result;
        if (use_stores_ && store_) {
            result.push_back(store_.get());
        }
        return (result);
    }

    // Certificate chain.
    std::vector<Botan::X509_Certificate>
    cert_chain(const std::vector<std::string>&,
               const std::string&,
               const std::string&) override {
        return (certs_);
    }

    // Private key.
    Botan::Private_Key*
    private_key_for(const Botan::X509_Certificate&,
                    const std::string&,
                    const std::string&) override {
        return (key_.get());
    }

    // Set the store from a path.
    void setStorePath(const std::string& path) {
        store_.reset(new KeaCertificateStorePath(path));
    }

    // Set the store from a file.
    void setStoreFile(const std::string& file) {
        store_.reset(new KeaCertificateStoreFile(file));
    }

    // Set the use the CA certificate stores flag.
    void setUseStores(bool use_stores) {
        use_stores_ = use_stores;
    }

    // Set the certificate chain.
    void setCertChain(const std::string& file) {
        Botan::DataSource_Stream source(file);
        certs_.clear();
        while (!source.end_of_data()) {
            std::string label;
            std::vector<uint8_t> cert;
            try {
                cert = unlock(Botan::PEM_Code::decode(source, label));
                if ((label != "CERTIFICATE") &&
                    (label != "X509 CERTIFICATE") &&
                    (label != "TRUSTED CERTIFICATE")) {
                    isc_throw(LibraryError, "Expected a certificate, got '"
                              << label << "'");
                }
                certs_.push_back(Botan::X509_Certificate(cert));
            } catch (const std::exception& ex) {
                if (certs_.empty()) {
                    throw;
                }
                // Got one certificate so skipping garbage.
                continue;
            }
        }
        if (certs_.empty()) {
            isc_throw(LibraryError, "Found no certificate?");
        }
    }

    // Set the private key.
    void setPrivateKey(const std::string& file,
                       Botan::RandomNumberGenerator& rng,
                       bool& is_rsa) {
        key_.reset(Botan::PKCS8::load_key(file, rng));
        if (!key_) {
            isc_throw(Unexpected,
                      "Botan::PKCS8::load_key failed but not threw?");
        }
        is_rsa = (key_->algo_name() == "RSA");
    }

    // Pointer to the CA certificate store.
    std::unique_ptr<Botan::Certificate_Store> store_;

    // Use the CA ceertificate store flag.
    bool use_stores_;

    // The certificate chain.
    std::vector<Botan::X509_Certificate> certs_;

    // Pointer to the private key.
    std::unique_ptr<Botan::Private_Key> key_;
=======
    KeaCredentialsManager() {
    }
    
    // Destructor.
    virtual ~KeaCredentialsManager() {
    }
>>>>>>> [#1665] Checkpoint
};

// Class of Kea policy.
// Use Strict_Policy?
class KeaPolicy : public Botan::TLS::Default_Policy {
public:
    // Constructor.
<<<<<<< HEAD
    KeaPolicy() : prefer_rsa_(true) {
=======
    KeaPolicy() {
>>>>>>> [#1665] Checkpoint
    }

    // Destructor.
    virtual ~KeaPolicy() {
    }
<<<<<<< HEAD

    // Allowed signature methods in preference order.
    std::vector<std::string> allowed_signature_methods() const override {
        if (prefer_rsa_) {
            return (AllowedSignatureMethodsRSA);
        } else {
            return (AllowedSignatureMethodsECDSA);
        }
    }

    // Disable OSCP.
    bool require_cert_revocation_info() const override {
        return false;
    }

    // Set the RSA preferred flag.
    void setPrefRSA(bool prefer_rsa) {
        prefer_rsa_ = prefer_rsa;
    }

    // Prefer RSA preferred flag.
    bool prefer_rsa_;

    // Allowed signature methods which prefers RSA.
    static const std::vector<std::string> AllowedSignatureMethodsRSA;

    // Allowed signature methods which prefers ECDSA.
    static const std::vector<std::string> AllowedSignatureMethodsECDSA;
};


// Kea session manager.
using KeaSessionManager = Botan::TLS::Session_Manager_Noop;

// Allowed signature methods which prefers RSA.
const std::vector<std::string>
KeaPolicy::AllowedSignatureMethodsRSA = { "RSA", "DSA", "ECDSA" };

// Allowed signature methods which prefers ECDSA.
const std::vector<std::string>
KeaPolicy::AllowedSignatureMethodsECDSA = { "ECDSA", "RSA", "DSA" };

=======
};

>>>>>>> [#1665] Checkpoint
// Class of Botan TLS context implementations.
class TlsContextImpl {
public:
    // Constructor.
    TlsContextImpl() : cred_mgr_(), rng_(), sess_mgr_(), policy_() {
    }

    // Destructor.
    virtual ~TlsContextImpl() {
    }

<<<<<<< HEAD
    // Set the the peer certificate requirement mode.
    //
    // With Botan this means to provide or not the CA certificate stores.
    virtual void setCertRequired(bool cert_required) {
        try {
            cred_mgr_.setUseStores(cert_required);
        } catch (const std::exception& ex) {
            isc_throw(LibraryError, ex.what());
        }
    }

    // Load the trust anchor aka certificate authority (path).
    virtual void loadCaPath(const std::string& ca_path) {
        try {
            cred_mgr_.setStorePath(ca_path);
        } catch (const std::exception& ex) {
            isc_throw(LibraryError, ex.what());
        }
    }

    // Load the trust anchor aka certificate authority (file).
    virtual void loadCaFile(const std::string& ca_file) {
        try {
            cred_mgr_.setStoreFile(ca_file);
        } catch (const std::exception& ex) {
            isc_throw(LibraryError, ex.what());
        }
    }

    /// @brief Load the certificate file.
    virtual void loadCertFile(const std::string& cert_file) {
        try {
            cred_mgr_.setCertChain(cert_file);
        } catch (const std::exception& ex) {
            isc_throw(LibraryError, ex.what());
        }
    }

    /// @brief Load the private key file.
    ///
    /// As a side effect set the preference for RSA in the policy.
    virtual void loadKeyFile(const std::string& key_file) {
        try {
            bool is_rsa = true;
            cred_mgr_.setPrivateKey(key_file, rng_, is_rsa);
            policy_.setPrefRSA(is_rsa);
        } catch (const std::exception& ex) {
            isc_throw(LibraryError, ex.what());
        }
    }

    // Build the context if not yet done.
    virtual void build() {
        if (context_) {
            return;
        }
        context_.reset(new Botan::TLS::Context(cred_mgr_,
                                               rng_,
                                               sess_mgr_,
                                               policy_));
    }

    virtual Botan::TLS::Context& get() {
        return (*context_);
    }

=======
>>>>>>> [#1665] Checkpoint
    // Credentials Manager.
    KeaCredentialsManager cred_mgr_;

    // Random Number Generator.
    Botan::AutoSeeded_RNG rng_;

    // Session Manager.
<<<<<<< HEAD
    KeaSessionManager sess_mgr_;

    KeaPolicy policy_;

    std::unique_ptr<Botan::TLS::Context> context_;
};

TlsContext::~TlsContext() {
}

TlsContext::TlsContext(TlsRole role)
    : TlsContextBase(role), cert_required_(true),
      impl_(new TlsContextImpl()) {
}

Botan::TLS::Context&
TlsContext::getContext() {
    impl_->build();
    return (impl_->get());
=======
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
>>>>>>> [#1665] Checkpoint
}

void
TlsContext::setCertRequired(bool cert_required) {
<<<<<<< HEAD
    if (!cert_required && (getRole() == TlsRole::CLIENT)) {
        isc_throw(BadValue,
                  "'cert-required' parameter must be true for a TLS client");
    }
    cert_required_ = cert_required;
    impl_->setCertRequired(cert_required_);
=======
    cert_required_ = cert_required;
    // Todo
>>>>>>> [#1665] Checkpoint
}

bool
TlsContext::getCertRequired() const {
    return (cert_required_);
}

void
<<<<<<< HEAD
TlsContext::loadCaFile(const std::string& ca_file) {
    impl_->loadCaFile(ca_file);
}

void
TlsContext::loadCaPath(const std::string& ca_path) {
    impl_->loadCaPath(ca_path);
}

void
TlsContext::loadCertFile(const std::string& cert_file) {
    impl_->loadCertFile(cert_file);
}

void
TlsContext::loadKeyFile(const std::string& key_file) {
    impl_->loadKeyFile(key_file);
=======
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
>>>>>>> [#1665] Checkpoint
}

} // namespace asiolink
} // namespace isc

#endif // WITH_BOTAN && HAVE_BOTAN_ASIO_STREAM_H
