SUBDIRS = .

# Shell tests
SHTESTS = keactrl_tests.sh

# Don't install tests.
noinst_SCRIPTS = $(SHTESTS)

# Test files are created by `./configure` so only clean them when running
# `make distclean`, but not on `make clean`.
DISTCLEANFILES = $(SHTESTS)

# Run tests on `make check`.
check_SCRIPTS = $(SHTESTS)
TESTS = $(SHTESTS)
