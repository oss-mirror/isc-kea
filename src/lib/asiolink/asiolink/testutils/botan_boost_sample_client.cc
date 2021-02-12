//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <config.h>

#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <boost/asio.hpp>

#include <asiolink/botan_boost_wrapper.h>
#include <botan/asio_stream.h>
#include <botan/pkcs8.h>
#include <botan/auto_rng.h>

inline std::string CA_(const std::string& filename) {
  return (std::string(TEST_CA_DIR) + "/" + filename);
}

using boost::asio::ip::tcp;

enum { max_length = 1024 };

class Client_Certificate_Store : public Botan::Certificate_Store
{
public:
  Client_Certificate_Store()
    : cert_(), certs_()
  {
    cert_.reset(new Botan::X509_Certificate(CA_("kea-ca.crt")));
    certs_.push_back(cert_);
  }

  virtual ~Client_Certificate_Store()
  {
  }

  std::vector<std::shared_ptr<const Botan::X509_Certificate>>
  find_all_certs(const Botan::X509_DN& subject_dn,
                 const std::vector<uint8_t>& key_id) const override
  {
    std::vector<std::shared_ptr<const Botan::X509_Certificate>> result;
    for (auto const& cert : certs_) {
      if (cert->subject_dn() != subject_dn)
      {
        continue;
      }
      if (key_id.size())
      {
        auto const& skid = cert->subject_key_id();
        if (skid.size() && (skid != key_id))
        {
          continue;
        }
      }
      result.push_back(cert);
    }
    return result;
  }

  std::shared_ptr<const Botan::X509_Certificate>
  find_cert_by_pubkey_sha1(const std::vector<uint8_t>&) const override
  {
    // Used by OSCP so useless?
    return nullptr;
  }

  std::shared_ptr<const Botan::X509_Certificate>
  find_cert_by_raw_subject_dn_sha256(const std::vector<uint8_t>&) const override
  {
    // Used by OSCP so useless?
    return nullptr;
  }

  std::vector<Botan::X509_DN> all_subjects() const override
  {
    std::vector<Botan::X509_DN> subjects;
    for (auto const& cert : certs_)
    {
      subjects.push_back(cert->subject_dn());
    }
    return subjects;
  }

  std::shared_ptr<const Botan::X509_Certificate> cert_;
  std::vector<std::shared_ptr<const Botan::X509_Certificate>> certs_;
};

class Client_Credentials_Manager : public Botan::Credentials_Manager
{
public:
  explicit Client_Credentials_Manager(Botan::RandomNumberGenerator& rng)
    : stores_(), certs_(),
      store_(new Client_Certificate_Store),
      cert_(Botan::X509_Certificate(CA_("kea-client.crt"))),
      key_(Botan::PKCS8::load_key(CA_("kea-client.key"), rng))
  {
    stores_.push_back(store_.get());
    certs_.push_back(cert_);
  }

  virtual ~Client_Credentials_Manager()
  {
  }

  std::vector<Botan::Certificate_Store*>
  trusted_certificate_authorities(const std::string&,
                                  const std::string&) override
  {
    return stores_;
  }

  std::vector<Botan::X509_Certificate>
  cert_chain(const std::vector<std::string>&,
             const std::string&,
             const std::string&) override
  {
    return certs_;
  }

  Botan::Private_Key*
  private_key_for(const Botan::X509_Certificate&,
                  const std::string&,
                  const std::string&) override
  {
    return key_.get();
  }

  std::vector<Botan::Certificate_Store*> stores_;
  std::vector<Botan::X509_Certificate> certs_;
  std::shared_ptr<Botan::Certificate_Store> store_;
  Botan::X509_Certificate cert_;
  std::unique_ptr<Botan::Private_Key> key_;
};

using Client_Session_Manager = Botan::TLS::Session_Manager_Noop;

class Client_Policy : public Botan::TLS::Default_Policy {
public:
  virtual ~Client_Policy()
  {
  }

  std::vector<std::string> allowed_signature_methods() const override
  {
    return { "RSA", "ECDSA", "IMPLICIT" };
  }

  bool require_cert_revocation_info() const override
  {
    return false;
  }
};

class client
{
public:
  client(boost::asio::io_service& io_context,
      Botan::TLS::Context& context,
      const tcp::endpoint& endpoint)
    : socket_(io_context, context)
  {
    connect(endpoint);
  }

private:
  void connect(const tcp::endpoint& endpoint)
  {
    socket_.lowest_layer().async_connect(endpoint,
        [this](const boost::system::error_code& error)
        {
          if (!error)
          {
            handshake();
          }
          else
          {
            std::cout << "Connect failed: " << error.message() << "\n";
          }
        });
  }

  void handshake()
  {
    socket_.async_handshake(Botan::TLS::Connection_Side::CLIENT,
        [this](const boost::system::error_code& error)
        {
          if (!error)
          {
            // Print the certificate's subject name.
            const std::vector<Botan::X509_Certificate>& cert_chain =
              socket_.native_handle()->peer_cert_chain();
            for (auto const& cert : cert_chain) {
              const Botan::X509_DN& subject = cert.subject_dn();
              std::cout << "Verified " << subject.to_string() << "\n";
            }

            send_request();
          }
          else
          {
            std::cout << "Handshake failed: " << error.message() << "\n";
          }
        });
  }

  void send_request()
  {
    std::cout << "Enter message: ";
    std::cin.getline(request_, max_length);
    size_t request_length = std::strlen(request_);

    boost::asio::async_write(socket_,
        boost::asio::buffer(request_, request_length),
        [this](const boost::system::error_code& error, std::size_t length)
        {
          if (!error)
          {
            receive_response(length);
          }
          else
          {
            std::cout << "Write failed: " << error.message() << "\n";
          }
        });
  }

  void receive_response(std::size_t length)
  {
    boost::asio::async_read(socket_,
        boost::asio::buffer(reply_, length),
        [this](const boost::system::error_code& error, std::size_t length)
        {
          if (!error)
          {
            std::cout << "Reply: ";
            std::cout.write(reply_, length);
            std::cout << "\n";
          }
          else
          {
            std::cout << "Read failed: " << error.message() << "\n";
          }
        });
  }

  Botan::TLS::Stream<tcp::socket> socket_;
  char request_[max_length];
  char reply_[max_length];
};

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: client <addr> <port>\n";
      return 1;
    }

    boost::asio::io_service io_context;

    using namespace std; // For atoi.
    tcp::endpoint endpoint(
      boost::asio::ip::address::from_string(argv[1]), atoi(argv[2]));
    Botan::AutoSeeded_RNG rng;
    Client_Credentials_Manager creds_mgr(rng);
    Client_Session_Manager sess_mgr;
    Client_Policy policy;
    Botan::TLS::Context ctx(creds_mgr, rng, sess_mgr, policy);

    client c(io_context, ctx, endpoint);

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
