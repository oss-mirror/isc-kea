//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <boost/asio.hpp>
#include <botan/asio_stream.h>

using boost::asio::ip::tcp;
using std::placeholders::_1;
using std::placeholders::_2;

enum { max_length = 1024 };

class client
{
public:
  client(boost::asio::io_service& io_context,
      Botan::TLS::Context& context,
      const tcp::resolver::results_type& endpoints)
    : socket_(io_context, context)
  {
    connect(endpoints);
  }

private:
  void connect(const tcp::resolver::results_type& endpoints)
  {
    boost::asio::async_connect(socket_.lowest_layer(), endpoints,
        [this](const boost::system::error_code& error,
          const tcp::endpoint& /*endpoint*/)
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

#if 0
int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: client <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_context;

    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(argv[1], argv[2]);

    Botan::TLS::Context ctx;

    client c(io_context, ctx, endpoints);

    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
#endif
