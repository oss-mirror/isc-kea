// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// Do not include this header directly: use crypto_tls.h instead.

#ifndef BOTAN_BOOST_WRAPPER_H
#define BOTAN_BOOST_WRAPPER_H

/// @file botan_boost_wrapper.h Botan boost ASIO wrapper.

#if defined(WITH_BOTAN) && defined(HAVE_BOTAN_ASIO_STREAM_H)

/// The error classes do not define virtual destructors.
/// This workaround is taken from the boost header.

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include <botan/asio_error.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#endif // WITH_BOTAN && HAVE_BOTAN_ASIO_STREAM_H

#endif // BOTAN_BOOST_WRAPPER_H
