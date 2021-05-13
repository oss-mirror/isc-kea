SHTESTS =
# The test of dynamic reconfiguration based on signals will work only
# if we are using file based configuration approach.
SHTESTS += relay_process_tests.sh

noinst_SCRIPTS = relay_process_tests.sh

EXTRA_DIST  = relay_process_tests.sh.in
EXTRA_DIST += testdata/get_config.json

# test using command-line arguments, so use check-local target instead of TESTS
check-local:
	for shtest in $(SHTESTS) ; do \
	echo Running test: $$shtest ; \
	export KEA_LOCKFILE_DIR=$(abs_top_builddir); \
	export KEA_PIDFILE_DIR=$(abs_top_builddir); \
	${SHELL} $(abs_builddir)/$$shtest || exit ; \
	done

AM_CPPFLAGS = -I$(top_srcdir)/src/lib -I$(top_builddir)/src/lib
AM_CPPFLAGS += -I$(top_srcdir)/src/bin -I$(top_builddir)/src/bin
AM_CPPFLAGS += $(BOOST_INCLUDES) $(CRYPTO_CFLAGS) $(CRYPTO_INCLUDES)
AM_CPPFLAGS += -DTEST_DATA_BUILDDIR=\"$(abs_top_builddir)/src/bin/relay/tests\"
AM_CPPFLAGS += -DINSTALL_PROG=\"$(abs_top_srcdir)/install-sh\"
AM_CPPFLAGS += -DCFG_EXAMPLES=\"$(abs_top_srcdir)/doc/examples/relay\"
AM_CPPFLAGS += -DSYNTAX_FILE=\"$(abs_srcdir)/../relay_parser.yy\"

CLEANFILES = $(builddir)/interfaces.txt $(builddir)/logger_lockfile

DISTCLEANFILES  = relay_process_tests.sh
AM_CXXFLAGS = $(KEA_CXXFLAGS)

if USE_STATIC_LINK
AM_LDFLAGS = -static
endif

TESTS_ENVIRONMENT = \
        $(LIBTOOL) --mode=execute $(VALGRIND_COMMAND)

TESTS =
if HAVE_GTEST


TESTS += relay_unittests

relay_unittests_SOURCES = relay_unittests.cc

relay_unittests_CPPFLAGS = $(AM_CPPFLAGS) $(GTEST_INCLUDES)
relay_unittests_LDFLAGS = $(AM_LDFLAGS) $(CRYPTO_LDFLAGS) $(GTEST_LDFLAGS)

relay_unittests_LDADD = $(top_builddir)/src/bin/relay/librelay.la
relay_unittests_LDADD += $(top_builddir)/src/lib/process/testutils/libprocesstest.la
relay_unittests_LDADD += $(top_builddir)/src/lib/cfgrpt/libcfgrpt.la
relay_unittests_LDADD += $(top_builddir)/src/lib/process/libkea-process.la
relay_unittests_LDADD += $(top_builddir)/src/lib/config/libkea-cfgclient.la
relay_unittests_LDADD += $(top_builddir)/src/lib/dhcp/libkea-dhcp++.la
relay_unittests_LDADD += $(top_builddir)/src/lib/asiolink/testutils/libasiolinktest.la
relay_unittests_LDADD += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
relay_unittests_LDADD += $(top_builddir)/src/lib/cc/libkea-cc.la
relay_unittests_LDADD += $(top_builddir)/src/lib/hooks/libkea-hooks.la
relay_unittests_LDADD += $(top_builddir)/src/lib/log/libkea-log.la
relay_unittests_LDADD += $(top_builddir)/src/lib/testutils/libkea-testutils.la
relay_unittests_LDADD += $(top_builddir)/src/lib/util/libkea-util.la
relay_unittests_LDADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
relay_unittests_LDADD += $(LOG4CPLUS_LIBS) $(CRYPTO_LIBS)
relay_unittests_LDADD += $(BOOST_LIBS) $(GTEST_LDADD)

endif

noinst_PROGRAMS = $(TESTS)
