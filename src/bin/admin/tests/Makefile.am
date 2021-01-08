SUBDIRS = data .

# Shell tests
SHTESTS = memfile_tests.sh

if HAVE_MYSQL
SHTESTS += mysql_tests.sh
endif

if HAVE_PGSQL
SHTESTS += pgsql_tests.sh
endif

if HAVE_CQL
SHTESTS += cql_tests.sh
endif

# Don't install tests.
noinst_SCRIPTS = $(SHTESTS)

# Other files that need to be added to the tarball
EXTRA_DIST = dhcpdb_create_1.0.mysql
EXTRA_DIST += dhcpdb_create_1.0.pgsql
EXTRA_DIST += dhcpdb_create_1.0.cql

# Test files are created by `./configure` so only clean them when running
# `make distclean`, but not on `make clean`.
DISTCLEANFILES = $(SHTESTS)

# Run tests on `make check`.
check_SCRIPTS = $(SHTESTS)
TESTS = $(SHTESTS)
