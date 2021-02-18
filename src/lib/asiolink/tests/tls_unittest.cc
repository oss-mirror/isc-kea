// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <asiolink/asio_wrapper.h>
#include <asiolink/io_service.h>
#include <asiolink/crypto_tls.h>
#include <asiolink/botan_tls.h>
#include <asiolink/openssl_tls.h>
#include <asiolink/tcp_endpoint.h>
#include <asiolink/testutils/test_tls.h>
#include <testutils/gtest_utils.h>

#include <boost/scoped_ptr.hpp>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace isc::asiolink;
using namespace isc::cryptolink;
using namespace std;

// Test if we can get a client context.
TEST(TLSTest, clientContext) {
    TlsContextPtr ctx;
    ASSERT_NO_THROW(ctx.reset(new TlsContext(TlsRole::CLIENT)));
}

// Test if we can get a server context.
TEST(TLSTest, serverContext) {
    TlsContextPtr ctx;
    ASSERT_NO_THROW(ctx.reset(new TlsContext(TlsRole::SERVER)));
}

// Test if the cert required flag is handled as expected.
TEST(TLSTest, certRequired) {
    auto check = [] (TlsContext& ctx) -> bool {
#ifdef WITH_BOTAN
        // Implement it.
        return (ctx.getCertRequired());
#else // WITH_OPENSSL
        ::SSL_CTX* ssl_ctx = ctx.getNativeContext();
        if (!ssl_ctx) {
            ADD_FAILURE() << "null SSL_CTX";
            return (false);
        }
        int mode = SSL_CTX_get_verify_mode(ssl_ctx);
        switch (mode) {
        case SSL_VERIFY_NONE:
            return (false);
        case (SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT):
            return (true);
        default:
            ADD_FAILURE() << "unknown ssl_verify_mode: " << mode;
            return (false);
        }
#endif
    };

    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_TRUE(ctx.getCertRequired());
    EXPECT_TRUE(check(ctx));
    ASSERT_NO_THROW(ctx.setCertRequired(false));
    EXPECT_FALSE(ctx.getCertRequired());
    EXPECT_FALSE(check(ctx));
    ASSERT_NO_THROW(ctx.setCertRequired(true));
    EXPECT_TRUE(ctx.getCertRequired());
    EXPECT_TRUE(check(ctx));
}

// Test if the certificate authority can be loaded.
TEST(TLSTest, loadCAFile) {
    string ca(string(TEST_CA_DIR) + "/kea-ca.crt");
    TlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCaFile(ca));
}

// Test that no certificate authority gives an error.
TEST(TLSTest, loadNoCAFile) {
    string ca("/no-such-file");
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCaFile(ca), LibraryError,
                     "No such file or directory");
}

#ifdef WITH_BOTAH
// Test that a directory can't be loaded with Botan.
TEST(TLSTest, loadCAPath) {
    string ca(TEST_CA_DIR);
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW(ctx.loadCaPath(ca), NotImplemented);
}
#else // WITH_OPENSSL
// Test that a directory can be loaded.
TEST(TLSTest, loadCAPath) {
    string ca(TEST_CA_DIR);
    TlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCaPath(ca));
}
#endif

// Test that a certificate is wanted.
TEST(TLSTest, loadKeyCA) {
    string ca(string(TEST_CA_DIR) + "/kea-ca.key");
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCaFile(ca), LibraryError,
                     "no certificate or crl found");
}

// Test if the end entity certificate can be loaded.
TEST(TLSTest, loadCertFile) {
    string cert(string(TEST_CA_DIR) + "/kea-client.crt");
    TlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadCertFile(cert));
}

// Test that no end entity certificate gives an error.
TEST(TLSTest, loadNoCertFile) {
    string cert("/no-such-file");
    TlsContext ctx(TlsRole::CLIENT);
}

// Test that a certificate is wanted.
TEST(TLSTest, loadCsrCertFile) {
    string cert(string(TEST_CA_DIR) + "/kea-client.csr");
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadCertFile(cert), LibraryError,
                     "no start line");
}

// Test if the private key can be loaded.
TEST(TLSTest, loadKeyFile) {
    string key(string(TEST_CA_DIR) + "/kea-client.key");
    TlsContext ctx(TlsRole::CLIENT);
    ASSERT_NO_THROW(ctx.loadKeyFile(key));
}

// Test that no private key gives an error.
TEST(TLSTest, loadNoKeyFile) {
    string key("/no-such-file");
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadKeyFile(key), LibraryError,
                     "No such file or directory");
}

// Test that a private key is wanted.
TEST(TLSTest, loadCertKeyFile) {
    string key(string(TEST_CA_DIR) + "/kea-client.crt");
    TlsContext ctx(TlsRole::CLIENT);
    EXPECT_THROW_MSG(ctx.loadKeyFile(key), LibraryError,
                     "no start line");
}

// Test that the certificate and private key must match.
TEST(TLSTest, loadMismatch) {
    string cert(string(TEST_CA_DIR) + "/kea-server.crt");
    TlsContext ctx(TlsRole::SERVER);
    EXPECT_NO_THROW(ctx.loadCertFile(cert));
    string key(string(TEST_CA_DIR) + "/kea-client.key");
    // In fact OpenSSL checks only RSA key values...
    // The explicit check function is SSL_CTX_check_private_key.
    EXPECT_THROW_MSG(ctx.loadKeyFile(key), LibraryError,
                     "key values mismatch");
}

// Define a callback class.
namespace { // anonymous namespace.
class Callback {
public:
    // Callback function.
    void operator()(const boost::system::error_code& ec) { }
};
} // end of anonymous namespace.

// Test if we can get a stream.
TEST(TLSTest, stream) {
    IOService service;
    TlsContextPtr ctx;
    ASSERT_NO_THROW(ctx.reset(new TlsContext(TlsRole::CLIENT)));
    boost::scoped_ptr<TlsStream<Callback> > st;
    ASSERT_NO_THROW(st.reset(new TlsStream<Callback>(service, ctx)));
}

namespace { // anonymous namespace.
/// @brief Local server address used for testing.
const char SERVER_ADDRESS[] = "127.0.0.1";

/// @brief Local server port used for testing.
const unsigned short SERVER_PORT = 18123;
} // end of anonymous namespace.

// Test what happens when handshake is forgotten.
TEST(TLSTest, noHandshake) {
    IOService service;

    // Server part.
    TlsContextPtr server_ctx;
    test::configServer(server_ctx);
    TlsStream<Callback> server(service, server_ctx);

    // Accept a client.
    tcp::endpoint server_ep(tcp::endpoint(address::from_string(SERVER_ADDRESS),
                                          SERVER_PORT));
    tcp::acceptor acceptor(service.get_io_service(), server_ep);
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    bool accepted(false);
    boost::system::error_code accept_ec;
    acceptor.async_accept(server.lowest_layer(),
        [&accepted, &accept_ec] (const boost::system::error_code& ec) {
            accepted = true;
            accept_ec = ec;
        });

    // Client part.
    TlsContextPtr client_ctx;
    test::configClient(client_ctx);
    TlsStream<Callback> client(service, client_ctx);

    // Connect to.
    bool connected(false);
    boost::system::error_code connect_ec;
    client.lowest_layer().open(tcp::v4());
    client.lowest_layer().async_connect(server_ep,
        [&connected, &connect_ec] (const boost::system::error_code& ec) {
            connected = true;
            connect_ec = ec;
        });

    // Run accept and connect.
    while (!accepted && !connected) {
        service.run_one();
    }

    // Verify the error codes.
    if (accept_ec) {
        FAIL() << "accept error " << accept_ec.value()
               << " '" << accept_ec.message() << "'";
    }
    // Possible EINPROGRESS for the client.
    if (connect_ec && (connect_ec.value() != EINPROGRESS)) {
        FAIL() << "connect error " << connect_ec.value()
               << " '" << connect_ec.message() << "'";
    }

    // Send on the client.
    char send_buf[] = "some text...";
    bool sent(false);
    boost::system::error_code send_ec;
    async_write(client, boost::asio::buffer(send_buf),
        [&sent, &send_ec] (const boost::system::error_code& ec,
                           size_t) {
            sent = true;
            send_ec = ec;
        });
    while (!sent) {
        service.run_one();
    }
    EXPECT_TRUE(send_ec);
    EXPECT_EQ("uninitialized", send_ec.message());

    // Receive on the server.
    vector<char> receive_buf(64);
    bool received(false);
    boost::system::error_code receive_ec;
    server.async_read_some(boost::asio::buffer(receive_buf),
        [&received, &receive_ec] (const boost::system::error_code& ec,
                                  size_t) {
            received = true;
            receive_ec = ec;
        });
    while (!received) {
        service.run_one();
    }
    EXPECT_TRUE(receive_ec);
    EXPECT_EQ("uninitialized", receive_ec.message());

    // Close client and server.
    EXPECT_NO_THROW(client.lowest_layer().close());
    EXPECT_NO_THROW(server.lowest_layer().close());
}
