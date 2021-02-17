SUBDIRS = .

AM_CPPFLAGS = -I$(top_builddir)/src/lib -I$(top_srcdir)/src/lib
AM_CPPFLAGS += $(BOOST_INCLUDES) $(CRYPTO_CFLAGS) $(CRYPTO_INCLUDES)
TEST_CA_DIR = $(abs_srcdir)/ca
AM_CPPFLAGS += -DTEST_CA_DIR=\"$(TEST_CA_DIR)\"

AM_CXXFLAGS = $(KEA_CXXFLAGS)

EXTRA_DIST  =
EXTRA_DIST += ca/0c7eedb9.0
EXTRA_DIST += ca/3071e5ff.0
EXTRA_DIST += ca/ad950210.0
EXTRA_DIST += ca/d3d11a5f.0
EXTRA_DIST += ca/doc
EXTRA_DIST += ca/ext-addr-conf.cnf
EXTRA_DIST += ca/ext-conf.cnf
EXTRA_DIST += ca/kea-ca.crt
EXTRA_DIST += ca/kea-ca.key
EXTRA_DIST += ca/kea-client.crt
EXTRA_DIST += ca/kea-client.csr
EXTRA_DIST += ca/kea-client.key
EXTRA_DIST += ca/kea-client.p12
EXTRA_DIST += ca/kea-server-addr.crt
EXTRA_DIST += ca/kea-server-addr.csr
EXTRA_DIST += ca/kea-server.crt
EXTRA_DIST += ca/kea-server.csr
EXTRA_DIST += ca/kea-server.key
EXTRA_DIST += ca/server-addr-conf.cnf
EXTRA_DIST += ca/server-conf.cnf

CLEANFILES = *.gcno *.gcda

if HAVE_GTEST

noinst_LTLIBRARIES = libasiolinktest.la

libasiolinktest_la_SOURCES  = test_server_unix_socket.cc test_server_unix_socket.h
libasiolinktest_la_SOURCES += timed_signal.cc timed_signal.h

libasiolinktest_la_CXXFLAGS = $(AM_CXXFLAGS)
libasiolinktest_la_CPPFLAGS = $(AM_CPPFLAGS) $(GTEST_INCLUDES)
libasiolinktest_la_LDFLAGS  = $(AM_LDFLAGS)

libasiolinktest_la_LIBADD  = $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
libasiolinktest_la_LIBADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
libasiolinktest_la_LIBADD += $(BOOST_LIBS)

endif
