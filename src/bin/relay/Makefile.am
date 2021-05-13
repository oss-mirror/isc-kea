SUBDIRS = . tests

AM_CPPFLAGS = -I$(top_srcdir)/src/lib -I$(top_builddir)/src/lib
AM_CPPFLAGS += -I$(top_srcdir)/src/bin -I$(top_builddir)/src/bin
AM_CPPFLAGS += $(BOOST_INCLUDES) $(CRYPTO_CFLAGS) $(CRYPTO_INCLUDES)
AM_CXXFLAGS = $(KEA_CXXFLAGS)

if USE_STATIC_LINK
AM_LDFLAGS = -static
endif

CLEANFILES  = *.gcno *.gcda

EXTRA_DIST = relay.dox relay_hooks.dox


# convenience archive

noinst_LTLIBRARIES = librelay.la

librelay_la_SOURCES  = relay_parser.cc relay_parser.h
librelay_la_SOURCES += relay_lexer.cc
librelay_la_SOURCES += relay_cfg_mgr.cc relay_cfg_mgr.h
librelay_la_SOURCES += relay_controller.cc relay_controller.h
librelay_la_SOURCES += relay_command_mgr.cc relay_command_mgr.h
librelay_la_SOURCES += relay_log.cc relay_log.h
librelay_la_SOURCES += relay_process.cc relay_process.h
librelay_la_SOURCES += simple_parser.cc simple_parser.h
librelay_la_SOURCES += parser_context.cc parser_context.h parser_context_decl.h
librelay_la_SOURCES += relay_lexer.ll location.hh position.hh stack.hh
librelay_la_SOURCES += relay_messages.h relay_messages.cc
EXTRA_DIST += relay_messages.mes
EXTRA_DIST += relay_lexer.ll
EXTRA_DIST += relay_parser.yy

sbin_PROGRAMS = kea-relay

kea_relay_SOURCES = main.cc

kea_relay_LDADD  = librelay.la
kea_relay_LDADD += $(top_builddir)/src/lib/cfgrpt/libcfgrpt.la
kea_relay_LDADD += $(top_builddir)/src/lib/process/libkea-process.la
kea_relay_LDADD += $(top_builddir)/src/lib/config/libkea-cfgclient.la
kea_relay_LDADD += $(top_builddir)/src/lib/dhcp/libkea-dhcp++.la
kea_relay_LDADD += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
kea_relay_LDADD += $(top_builddir)/src/lib/cc/libkea-cc.la
kea_relay_LDADD += $(top_builddir)/src/lib/cryptolink/libkea-cryptolink.la
kea_relay_LDADD += $(top_builddir)/src/lib/hooks/libkea-hooks.la
kea_relay_LDADD += $(top_builddir)/src/lib/log/libkea-log.la
kea_relay_LDADD += $(top_builddir)/src/lib/util/libkea-util.la
kea_relay_LDADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
kea_relay_LDADD += $(LOG4CPLUS_LIBS) $(CRYPTO_LIBS) $(BOOST_LIBS)

kea_relay_LDFLAGS = $(AM_LDFLAGS) $(CRYPTO_LDFLAGS)

# If we want to get rid of all generated messages files, we need to use
# make maintainer-clean. The proper way to introduce custom commands for
# that operation is to define maintainer-clean-local target. However,
# make maintainer-clean also removes Makefile, so running configure script
# is required.  To make it easy to rebuild messages without going through
# reconfigure, a new target messages-clean has been added.
maintainer-clean-local:
	rm -f relay_messages.h relay_messages.cc

# To regenerate messages files, one can do:
#
# make messages-clean
# make messages
#
# This is needed only when a .mes file is modified.
messages-clean: maintainer-clean-local

if GENERATE_MESSAGES

# Define rule to build logging source files from message file
messages: relay_messages.h relay_messages.cc
	@echo Message files regenerated

relay_messages.h relay_messages.cc: relay_messages.mes
	$(top_builddir)/src/lib/log/compiler/kea-msg-compiler $(top_srcdir)/src/bin/relay/relay_messages.mes

else

messages relay_messages.h relay_messages.cc:
	@echo Messages generation disabled. Configure with --enable-generate-messages to enable it.

endif

if GENERATE_PARSER

# Generate parser first.
all-recursive: relay_lexer.cc location.hh position.hh stack.hh relay_parser.cc relay_parser.h

parser: relay_lexer.cc location.hh position.hh stack.hh relay_parser.cc relay_parser.h
	@echo "Flex/bison files regenerated"

# --- Flex/Bison stuff below --------------------------------------------------
# When debugging grammar issues, it's useful to add -v to bison parameters.
# bison will generate parser.output file that explains the whole grammar.
# It can be used to manually follow what's going on in the parser.
# This is especially useful if yydebug_ is set to 1 as that variable
# will cause parser to print out its internal state.
# Call flex with -s to check that the default rule can be suppressed
# Call bison with -W to get warnings like unmarked empty rules
# Note C++11 deprecated register still used by flex < 2.6.0
location.hh position.hh stack.hh relay_parser.cc relay_parser.h: relay_parser.yy
	$(YACC) --defines=relay_parser.h --report=all --report-file=relay_parser.report -o relay_parser.cc relay_parser.yy

relay_lexer.cc: relay_lexer.ll
	$(LEX) --prefix relay_ -o relay_lexer.cc relay_lexer.ll

else

parser location.hh position.hh stack.hh relay_parser.cc relay_parser.h relay_lexer.cc:
	@echo Parser generation disabled. Configure with --enable-generate-parser to enable it.

endif
