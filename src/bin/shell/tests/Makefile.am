PYTESTS = shell_unittest.py
SHTESTS = shell_process_tests.sh basic_auth_tests.sh
noinst_SCRIPTS = $(PYTESTS) $(SHTESTS)

DISTCLEANFILES = basic_auth_tests.sh shell_process_tests.sh shell_unittest.py

# test using command-line arguments, so use check-local target instead of TESTS
check-local: check-shell check-python

check-python:
	@for pytest in $(PYTESTS) ; do \
	echo Running python test: $$pytest ; \
	chmod +x $(abs_builddir)/$$pytest ; \
	PYTHONPATH=$(PYTHONPATH):$(abs_top_srcdir)/src/bin/shell @PYTHON@ $(abs_builddir)/$$pytest || exit ; \
	done

check-shell:
	@for shtest in $(SHTESTS) ; do \
	echo Running shell test: $$shtest ; \
	export KEA_LOCKFILE_DIR=$(abs_top_builddir); \
	export KEA_PIDFILE_DIR=$(abs_top_builddir); \
	export PYTHONPATH=$(PYTHONPATH):$(abs_top_srcdir)/src/bin/shell; \
	${SHELL} $(abs_builddir)/$$shtest || exit ; \
	done

CLEANDIRS = __pycache__

clean-local:
	rm -rf $(CLEANDIRS)

#EXTRA_DIST  =
#EXTRA_DIST += ca/0c7eedb9.0
#EXTRA_DIST += ca/3071e5ff.0
#EXTRA_DIST += ca/ad950210.0
#EXTRA_DIST += ca/d3d11a5f.0
#EXTRA_DIST += ca/doc
#EXTRA_DIST += ca/ext-addr-conf.cnf
#EXTRA_DIST += ca/ext-conf.cnf
#EXTRA_DIST += ca/kea-ca.crt
#EXTRA_DIST += ca/kea-ca.key
#EXTRA_DIST += ca/kea-client.crt
#EXTRA_DIST += ca/kea-client.csr
#EXTRA_DIST += ca/kea-client.key
#EXTRA_DIST += ca/kea-client.p12
#EXTRA_DIST += ca/kea-server-addr.crt
#EXTRA_DIST += ca/kea-server-addr.csr
#EXTRA_DIST += ca/kea-server.crt
#EXTRA_DIST += ca/kea-server.csr
#EXTRA_DIST += ca/kea-server.key
#EXTRA_DIST += ca/server-addr-conf.cnf
#EXTRA_DIST += ca/server-conf.cnf
