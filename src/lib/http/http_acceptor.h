// Copyright (C) 2017-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef HTTP_ACCEPTOR_H
#define HTTP_ACCEPTOR_H

#include <asiolink/tls_acceptor.h>
#include <boost/system/system_error.hpp>
#include <functional>

namespace isc {
namespace http {

/// @brief Type of the callback for the TLS acceptor used in this library.
typedef std::function<void(const boost::system::error_code&)>
HttpAcceptorCallback;

/// @brief Type of the TLS acceptor used in this library.
typedef asiolink::TLSAcceptor<HttpAcceptorCallback> HttpAcceptor;

} // end of namespace isc::http
} // end of namespace isc

#endif
