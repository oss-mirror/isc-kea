// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <asiolink/asio_wrapper.h>
#include <asiolink/crypto_tls.h>
#include <asiolink/botan_tls.h>
#include <asiolink/openssl_tls.h>
#include <testutils/gtest_utils.h>

#include <gtest/gtest.h>

#include <boost/scoped_ptr.hpp>

#include <string>

using namespace isc::asiolink;
using namespace isc::cryptolink;
using namespace std;

#ifdef HAVE_BOTAN
typedef BotanTlsContext TestTlsContext;
#else
typedef OpenSslTlsContext TestTlsContext;
#endif

// Test if we can get a client context.
TEST(TLSTest, clientContext) {
    boost::scoped_ptr<TestTlsContext> ctx;
    ASSERT_NO_THROW(ctx.reset(new TestTlsContext(TlsRole::CLIENT)));
}

// Test if we can get a server context.
TEST(TLSTest, serverContext) {
    boost::scoped_ptr<TestTlsContext> ctx;
    ASSERT_NO_THROW(ctx.reset(new TestTlsContext(TlsRole::SERVER)));
}

// Test if the cert required flag is handled as expected.
TEST(TLSTest, certRequired) {
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_TRUE(ctx.getCertRequired());
    ASSERT_NO_THROW(ctx.setCertRequired(false));
    EXPECT_FALSE(ctx.getCertRequired());
    ASSERT_NO_THROW(ctx.setCertRequired(true));
    EXPECT_TRUE(ctx.getCertRequired());
}

// Test if the certificate authority can be loaded.
TEST(TLSTest, loadCAFile) {
    string ca(string(TEST_CA_DIR) + "/kea-ca.crt");
    TestTlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCaFile(ca));
}

// Test that no certificate authority gives an error.
TEST(TLSTest, loadNoCA) {
    string ca("/no-such-file");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCaFile(ca), LibraryError,
                     "No such file or directory");
}

#ifdef WITH_OPENSSL
// Test that a directory can be loaded.
TEST(TLSTest, loadCAPath) {
    string ca(TEST_CA_DIR);
    TestTlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCaPath(ca));
}
#endif

// Test that a certificate is wanted.
TEST(TLSTest, loadKeyCA) {
    string ca(string(TEST_CA_DIR) + "/kea-ca.key");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCaFile(ca), LibraryError,
                     "no certificate or crl found");
}

// Test if the end entity certificate can be loaded.
TEST(TLSTest, loadCertFile) {
    string cert(string(TEST_CA_DIR) + "/kea-client.crt");
    TestTlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCertFile(cert));
}

// Test that no end entity certificate gives an error.
TEST(TLSTest, loadNoCertFile) {
    string cert("/no-such-file");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCertFile(cert), LibraryError,
                     "No such file or directory");
}

// Test that a certificate is wanted.
TEST(TLSTest, loadCsrCertFile) {
    string cert(string(TEST_CA_DIR) + "/kea-client.csr");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCertFile(cert), LibraryError,
                     "no start line");
}

// Test if the private key can be loaded.
TEST(TLSTest, loadKeyFile) {
    string key(string(TEST_CA_DIR) + "/kea-client.key");
    TestTlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadKeyFile(key));
}

// Test that no private key gives an error.
TEST(TLSTest, loadNoKeyFile) {
    string key("/no-such-file");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadKeyFile(key), LibraryError,
                     "No such file or directory");
}

// Test that a private key is wanted.
TEST(TLSTest, loadCertKeyFile) {
    string key(string(TEST_CA_DIR) + "/kea-client.crt");
    TestTlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadKeyFile(key), LibraryError,
                     "no start line");
}
