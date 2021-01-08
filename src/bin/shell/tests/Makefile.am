# Python tests
PYTESTS = shell_unittest.py

# Shell tests
SHTESTS  =
SHTESTS += basic_auth_tests.sh
SHTESTS += shell_process_tests.sh
if CA_TLS_TEST
SHTESTS += tls_ca_process_tests.sh
endif

# Don't install tests.
noinst_SCRIPTS = $(PYTESTS) $(SHTESTS)

# Test files are created by `./configure` so only clean them when running
# `make distclean`, but not on `make clean`.
DISTCLEANFILES = $(PYTESTS) $(SHTESTS)

CLEANDIRS = __pycache__

# Run tests on `make check`.
check_SCRIPTS = $(SHTESTS)
TESTS = $(SHTESTS)
