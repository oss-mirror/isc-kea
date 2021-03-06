
.. _gss-tsig:

GSS-TSIG
========

.. _gss-tsig-overview:


.. note::

   The GSS-TSIG feature is considered experimental. It is possible to perform
   the key exchanges and sign the DNS updates using GSS-TSIG, but some error
   handling and fallback scenarios are not covered yet. Use with caution.

GSS-TSIG Overview
-----------------

Kea provides a support for DNS updates, which can be protected using
Transaction Signatures (or TSIG). This protection is often adequate.
However some systems, in particular Active Directory (AD) on Microsoft
Windows systems, chose to adopt more complex GSS-TSIG approach that offers
additional capabilities as using negotiated dynamic keys.

Kea provides the support of GSS-TSIG to protect DNS updates sent by
the Kea DHCP-DDNS (aka D2) server in a premium hook, called `gss_tsig`.

.. note::

    This library is still in the experimental phase and is not recommended
    nor supported for use in production. Use with care!

The GSS-TSIG is defined in `RFC 3645 <https://tools.ietf.org/html/rfc3645>`__.
The GSS-TSIG protocol itself is an implementation of generic GSS-API v2
services, defined in `RFC 2743 <https://tools.ietf.org/html/rfc2743>`__.

Many protocols are involved in this mechanism:

 - Kerberos 5 `RFC 4120 <https://tools.ietf.org/html/rfc4120>`__ which
   provides the security framework;
 - GSS-API (Generic Security Services Application Program Interface)
   `RFC 2743 <https://tools.ietf.org/html/rfc2743>`__ for the API,
   `RFC 2744 <https://tools.ietf.org/html/rfc2743>`__ for C bindings and
   `RFC 4121 <https://tools.ietf.org/html/rfc4121>`__ for the application
   to Kerberos 5;
 - SPNEGO (Simple and Protected GSS-API Negotiation Mechanism)
   `RFC 4178 <https://tools.ietf.org/html/rfc4178>`__ for the negotiation;
 - DNS update `RFC 2136 <https://tools.ietf.org/html/rfc2136>`__;
 - TSIG (Secret Key Transaction Authentication for DNS)
   `RFC 8945 <https://tools.ietf.org/html/rfc8945>`__ which
   protects DNS exchanges;
 - Secure Domain Name System (DNS) Dynamic Update
   `RFC 3007 <https://tools.ietf.org/html/rfc3007>`__ which is the
   application of TSIG to the DNS update protection;
 - TKEY (Secret Key Establishment for DNS)
   `RFC 2930 <https://tools.ietf.org/html/rfc2930>`__ which establishes
   secret keys for TSIG by transmitting crypto payloads between DNS
   parties;
 - GSS-TSIG `RFC 3645 <https://tools.ietf.org/html/rfc3645>`__ which
   is the application of GSS-API to TSIG.

To summarize, GSS-API for Kerberos 5 with SPNEGO and TKEY are used to
negotiate a security context between the Kea D2 server and a DNS server:

.. figure:: ../uml/tkey.*

The security context is then used by GSS-TSIG to protect updates:

.. figure:: ../uml/update.*

The Kea implementation of GSS-TSIG uses a GSS-API for Kerberos 5 with
SPNEGO library.  Two implementations meet this criteria: MIT Kerberos
5 and Heimdal.

.. _gss-tsig-install:

GSS-TSIG Compilation
--------------------

The following procedure was tested on Ubuntu 20.10 and 21.04. Similar
approach can be applied to other systems.

1.  Obtain the kea sources and premium packages, extract kea sources,
    then extract premium packages into `premium/` directory within Kea
    source tree.

2. Run autoreconf:

.. code-block:: console

    autoreconf -i

3. Make sure ``./configure --help`` shows the ``--with-gssapi`` option.

4. Install either MIT (``libkrb5-dev``) or Heimdal (``heimdal-dev``) library,
   for instance:

.. code-block:: console

    sudo apt install libkrb5-dev

5. Run configure with the ``--with-gssapi`` option:

.. code-block:: console

    ./configure --with-gssapi

.. note:

    It is ``--with-gssapi`` (without dash between gss and api) to keep
    consistency with BIND 9 option.

The ``--with-gssapi`` requires ``krb5-config`` tool to be present. This
tool is provided by both MIT Kerberos 5 and Heimdal, on some systems
where both Kerberos 5 and Heimdal are installed it is a symbolic link
to one of them. If it's not in your standard location, you may specify
it with ``--with-gssapi=/path/to/krb5-config``. It is strongly recommended
to use default installation locations as provided by packages.

The ``./configure`` script should complete with a successful GSS-API
detection, similar to this:

::

    GSS-API support:
      GSSAPI_CFLAGS:         -isystem /usr/include/mit-krb5
      GSSAPI_LIBS:           -L/usr/lib/x86_64-linux-gnu/mit-krb5 -Wl,-Bsymbolic-functions -Wl,-z,relro -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err

6.  Compile as usual ``make -jX`` where X is the number of CPU cores
    available.

7.  After compilation, the gss_tsig hook is available in the
    ``premium/src/hooks/d2/gss_tsig`` directory. It can be loaded by
    the DHCP-DDNS (D2) daemon.


The gss_tsig was developed using the MIT Kerberos 5 implementation but
Heimdal is supported too. Note that Heimdal is picky about security
sensitive file permissions and is known to emit an unclear error message.
It is a good idea to keep these files as plain, with one link and no
access for the group or other users.

The krb5-config script should provide an ``--all`` option which
identifies the implementation: in any report about the GSS-TSIG report
please add the result of the ``--all`` option of the krb5-config used
to configure Kea.

.. _gss-tsig-deployment:

GSS-TSIG Deployment
-------------------

Before using GSS-TSIG, a GSS-TSIG capable DNS server, such as BIND 9
or alternatively Microsoft Active Directory, must be deployed. Other
GSS-TSIG capable implementations may work, but were not tested.

Kerberos 5 Setup
~~~~~~~~~~~~~~~~

There are two kinds of key tables (keytab files): the system one used
by servers and client tables used by clients. For Kerberos 5, Kea is a
**client**.

Install the Kerberos 5 client library and kadmin tool:

.. code-block:: console

    sudo apt install krb5-kdc krb5-admin-server

The following examples use the ``EXAMPLE.ORG`` realm to demonstrate required
configuration steps and settings.

The Kerberos 5 client library must be configured (to accept incoming requests)
for the realm ``EXAMPLE.ORG`` by updating the ``krb5.conf`` file
(e.g. on Linux: /etc/krb5.conf):

.. code-block:: ini

    [libdefaults]
        default_realm = EXAMPLE.ORG
        kdc_timesync = 1
        ccache_type = 4
        forwardable = true
        proxiable = true

    [realms]
        EXAMPLE.ORG = {
                kdc = kdc.example.org
                admin_server = kdc.example.org
        }

In addition to the ``krb5.conf`` file, the ``kdc.conf`` file can be used
(e.g. on Linux: /etc/krb5kdc/kdc.conf):

.. code-block:: ini

    [kdcdefaults]
        kdc_ports = 750,88

    [realms]
        EXAMPLE.ORG = {
            database_name = /var/lib/krb5kdc/principal
            admin_keytab = FILE:/etc/krb5kdc/kadm5.keytab
            acl_file = /etc/krb5kdc/kadm5.acl
            key_stash_file = /etc/krb5kdc/stash
            kdc_ports = 750,88
            max_life = 10h 0m 0s
            max_renewable_life = 7d 0h 0m 0s
            master_key_type = des3-hmac-sha1
            #supported_enctypes = aes256-cts:normal aes128-cts:normal
            default_principal_flags = +preauth
        }

The kadmind daemon ACL (Access Control List) must be configured to give
permissions to the DNS client principal to access the Kerberos 5 database.
(e.g. on Linux: /etc/krb5kdc/kadm5.acl):

.. code-block:: ini

    DHCP/admin.example.org@EXAMPLE.ORG       *

The admin password for the default realm must be set:

.. code-block:: console

    krb5_newrealm

The following message will be displayed and you will be required to type
the password for the default realm:

.. code-block:: console

    This script should be run on the master KDC/admin server to initialize
    a Kerberos realm.  It will ask you to type in a master key password.
    This password will be used to generate a key that is stored in
    /etc/krb5kdc/stash.  You should try to remember this password, but it
    is much more important that it be a strong password than that it be
    remembered.  However, if you lose the password and /etc/krb5kdc/stash,
    you cannot decrypt your Kerberos database.
    Loading random data
    Initializing database '/var/lib/krb5kdc/principal' for realm 'EXAMPLE.ORG',
    master key name 'K/M@EXAMPLE.ORG'
    You will be prompted for the database Master Password.
    It is important that you NOT FORGET this password.
    Enter KDC database master key:

You will be required to retype the password:

.. code-block:: console

    Re-enter KDC database master key to verify:

If succesfully applied, the following message will be displayed:

.. code-block:: console

    Now that your realm is set up you may wish to create an administrative
    principal using the addprinc subcommand of the kadmin.local program.
    Then, this principal can be added to /etc/krb5kdc/kadm5.acl so that
    you can use the kadmin program on other computers.  Kerberos admin
    principals usually belong to a single user and end in /admin.  For
    example, if jruser is a Kerberos administrator, then in addition to
    the normal jruser principal, a jruser/admin principal should be
    created.

    Don't forget to set up DNS information so your clients can find your
    KDC and admin servers.  Doing so is documented in the administration
    guide.

Next step consists in creating the principals for the Bind9 DNS server
(the service protected by the GSS-TSIG TKEY) and for the DNS client
(the Kea DDNS server).

The Bind9 DNS server principal (used for authentication) is created the
following way:

.. code-block:: console

    kadmin.local -q "addprinc -randkey DNS/server.example.org"

If succesfully created, the following message will be displayed:

.. code-block:: console

    No policy specified for DNS/server.example.org@EXAMPLE.ORG; defaulting to no policy
    Authenticating as principal root/admin@EXAMPLE.ORG with password.
    Principal "DNS/server.example.org@EXAMPLE.ORG" created.

The DNS client principal (used by the Kea DDNS server) is created the
following way (please choose your own password here):

.. code-block:: console

    kadmin.local -q "addprinc -pw <password> DHCP/admin.example.org"

If succesfully created, the following message will be displayed:

.. code-block:: console

    No policy specified for DHCP/admin.example.org@EXAMPLE.ORG; defaulting to no policy
    Authenticating as principal root/admin@EXAMPLE.ORG with password.
    Principal "DHCP/admin.example.org@EXAMPLE.ORG" created.

The DNS server principal must be exported so that it can be used by the Bind 9
DNS server. Only this principal is required and is is exported to the keytab
file with the name ``dns.keytab``.

.. code-block:: console

    kadmin.local -q "ktadd -k /tmp/dns.keytab DNS/server.example.org"

If succesfully exported, the following message will be displayed:

.. code-block:: console

    Authenticating as principal root/admin@EXAMPLE.ORG with password.
    Entry for principal DNS/server.example.org with kvno 2, encryption type aes256-cts-hmac-sha1-96 added to keytab WRFILE:/tmp/dns.keytab.
    Entry for principal DNS/server.example.org with kvno 2, encryption type aes128-cts-hmac-sha1-96 added to keytab WRFILE:/tmp/dns.keytab.

Finally, the krb5-admin-server must be restarted:

.. code-block:: console

    systemctl restart krb5-admin-server.service

Bind 9 with GSS-TSIG Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The Bind 9 DNS server must be configured to use GSS-TSIG and to use the
previously exported DNS server principal from the keytab file ``dns.keytab``.
Updating the ``named.conf`` file is required:

.. code-block:: console

    options {
        ...
        directory "/var/cache/bind";
        dnssec-validation auto;
        tkey-gssapi-keytab "/etc/bind/dns.keytab";
    };
    zone "example.org" {
        type master;
        file "/var/lib/bind/db.example.org";
        update-policy {
            grant "DHCP/admin.example.org@EXAMPLE.ORG" zonesub any;
        };
    };
    zone "84.102.10.in-addr.arpa" {
        type master;
        file "/etc/bind/db.10";
    };

The zone files should have an entry for the server principal FQDN
``server.example.org``.

The ``/etc/bind/db.10`` file needs to be created or updated:

.. code-block:: console

    ;
    ; BIND reverse data file for local loopback interface
    ;
    $TTL    604800                      ; 1 week
    @       IN      SOA      server.example.org. root.example.org. (
                             2          ; Serial
                             604800     ; Refresh
                             86400      ; Retry
                             2419200    ; Expire
                             604800     ; Negative Cache TTL
                             )
    ;
    @       IN      NS      ns.
    40      IN      PTR     ns.example.org.

The ``/var/lib/bind/db.example.org`` file needs to be created or updated:

.. code-block:: console

    $ORIGIN .
    $TTL                604800             ; 1 week
    example.org         IN SOA  server.example.org. root.example.org. (
                                8          ; serial
                                604800     ; refresh (1 week)
                                86400      ; retry (1 day)
                                2419200    ; expire (4 weeks)
                                604800     ; minimum (1 week)
                                )
                        NS      example.org.
                        A       ${BIND9_IP_ADDR}
                        AAAA    ::1
    $ORIGIN example.org.
    kdc                 A       ${KDC_IP_ADDR}
    server              A       ${BIND9_IP_ADDR}

.. _gss-tsig-using:

Using GSS-TSIG
--------------

There is a number of steps required to enable the GSS-TSIG mechanism:

1. the gss_tsig hook library has to be loaded by the D2 server
2. the GSS-TSIG capable DNS servers have to be specified with their parameters

An excerpt from D2 server is provided below. More examples are available in the
``doc/examples/ddns`` directory in the Kea sources.

.. code-block:: javascript
   :linenos:
   :emphasize-lines: 57-97

    {
    "DhcpDdns": {
        // The following parameters are used to receive NCRs (NameChangeRequests)
        // from the local Kea DHCP server. Make sure your kea-dhcp4 and kea-dhcp6
        // matches this.
        "ip-address": "127.0.0.1",
        "port": 53001,
        "dns-server-timeout" : 1000,

        // Forward zone: secure.example.org. It uses GSS-TSIG. It is served
        // by two DNS servers, which listen for DDNS requests at 192.0.2.1
        // and 192.0.2.2.
        "forward-ddns":
        {
            "ddns-domains":
            [
                // DdnsDomain for zone "secure.example.org."
                {
                    "name": "secure.example.org.",
                    "comment": "DdnsDomain example",
                    "dns-servers":
                    [
                        { // This server has an entry in gss/servers and
                          // thus will use GSS-TSIG.
                            "ip-address": "192.0.2.1"
                        },
                        { // This server also has an entry there, so will
                          // use GSS-TSIG, too.
                            "ip-address": "192.0.2.2"
                        }
                    ]
                }
            ]
        },

        // Reverse zone: we want to update the reverse zone "2.0.192.in-addr.arpa".
        "reverse-ddns":
        {
            "ddns-domains":
            [
                {
                    "name": "2.0.192.in-addr.arpa.",
                    "dns-servers":
                    [
                        {
                            // There is GSS-TSIG definition for this server (see
                            // DhcpDdns/gss-tsig/servers), so it will use
                            // Krb/GSS-TSIG.
                            "ip-address": "192.0.2.1"
                        }
                    ]
                }
            ]
        },

        // Need to add gss-tsig hook here
        "hooks-libraries": [
        {
            "library": "/opt/lib/libdhcp_gss_tsig.so",
            "parameters": {
                // This section governs the GSS-TSIG integration. Each server
                // mentioned in forward-ddns and/or reverse-ddns needs to have
                // an entry here to be able to use GSS-TSIG defaults (optional,
                // if specified they apply to all the GSS-TSIG servers, unless
                // overwritten on specific server level).

                "server-principal": "DNS/server.example.org@EXAMPLE.ORG",
                "client-principal": "DHCP/admin.example.org@EXAMPLE.ORG",
                "client-keytab": "FILE:/etc/krb5.keytab", // toplevel only
                "credentials-cache": "FILE:/etc/ccache", // toplevel only
                "tkey-lifetime": 3600,
                "tkey-protocol": "TCP",

                // The list of GSS-TSIG capable servers
                "servers": [
                    {
                        // First server (identification is required)
                        "id": "server1",
                        "domain-names": [ ], // if not specified or empty, will
                                             // match all domains that want to
                                             // use this IP+port pair
                        "ip-address": "192.0.2.1",
                        "port": 53,
                        "server-principal": "DNS/server1.example.org@EXAMPLE.ORG",
                        "client-principal": "DHCP/admin1.example.org@EXAMPLE.ORG",
                        "tkey-lifetime": 86400, // 24h
                        "tkey-protocol": "TCP"
                    },
                    {
                        // The second server (it has most of the parameters missing
                        // as those are using the defaults specified above)
                        "id": "server2",
                        "ip-address": "192.0.2.2",
                        "port": 5300
                    }
                ]
            }
        }
        ]

        // Additional parameters, such as logging, control socket and
        // others omitted for clarity.
    }

    }

This configuration file contains a number of extra elements.

First, a list of forward and/or reverse domains with related DNS servers
identified by their IP+port pairs is defined. If port is not
specified, the default of 53 is assumed. This is similar to basic mode with no
authentication or authentication done using TSIG keys, with the
exception that static TSIG keys are not referenced by name.

Second, the ``libdhcp_gss_tsig.so`` library has to be specified on the
``hooks-libraries`` list. This hook takes many parameters. The most
important one is `servers`, which is a list of GSS-TSIG capable
servers.  If there are several servers and they share some
characteristics, the values can be specified in `parameters` scope as
defaults. In the example above, the defaults that apply to all servers
unless otherwise specified on per server scope, are defined in lines
63 through 68. The defaults can be skipped if there is only one server
defined or all servers have different values.

The parameters have the following meaning:

- ``client-keytab`` specifies the Kerberos **client** key table.
  For instance, ``FILE:<filename>`` can be used to point to a specific file.
  This parameter can be specified only once, in the parameters scope,
  and is the equivalent of setting the ``KRB5_CLIENT_KTNAME`` environment
  variable.

- ``credentials-cache`` specifies the Kerberos credentials cache.
  For instance ``FILE:<filename>`` can be used to point to a file or
  if using a directory which supports more than one principal
  ``DIR:<directory-path>``.
  This parameter can be specified only once, in the parameters scope,
  and is the equivalent of setting the ``KRB5CCNAME`` environment
  variable.

- ``server-principal`` is the Kerberos principal name of the DNS
  server that will receive updates.  In plain words, this is the
  DNS server's name in the Kerberos system. This parameter is
  mandatory.  It uses the typical Kerberos notation:
  ``<SERVICE-NAME>/<server-domain-name>@<REALM>``.

- ``client-principal`` is the Kerberos principal name of the Kea D2
  service. It is optional. It uses the typical Kerberos notation:
  ``<SERVICE-NAME>/<server-domain-name>@<REALM>``.

- ``tkey-protocol`` determines which protocol is used to establish the
  security context with the DNS servers.  Currently the only supported
  values are TCP (the default) and UDP.

- ``tkey-lifetime`` determines the lifetime of GSS-TSIG keys in the
  TKEY protocol, expressed in seconds. Default value is 3600 (one hour).

- ``user-context`` is an optional parameter (see :ref:`user-context`
  for a general description of user contexts in Kea).

- ``comment`` is allowed but currently ignored.

- ``servers`` specifies the list of DNS servers where GSS-TSIG is enabled.

The server map parameters are:

- ``id`` assigns an identifier to a DNS server. It is used for statistics
  and commands. It is required, must be not empty and unique.

- ``domain-names`` governs the many to one relationship between D2 DNS
  servers and GSS-TSIG DNS servers: for each domain name of this list,
  a D2 DNS server for this domain with the IP address and port is
  looked for. An empty list (the default) means that all domains
  match.

- ``ip-address`` specifies the IP address at which the GSS-TSIG DNS server
  listens for DDNS and TKEY requests. It is a mandatory parameter.

- ``port`` specifies the DNS transport port at which the GSS-TSIG DNS server
  listens for DDNS and TKEY requests. It defaults to 53.

- ``server-principal`` is the Kerberos principal name of the DNS server
  that will receive updates. The server principal parameter per server
  takes precedence. It is a mandatory parameter which must be specified at
  least at the global or the server level.

- ``client-principal`` is the Kerberos principal name of the Kea D2
  service for this DNS server. The client principal parameter per server
  takes precedence. It is an optional parameter i.e. to not specify it at
  both the global and the server level is accepted.

- ``tkey-protocol`` determines which protocol is used to establish the
  security context with the DNS server. The TKEY protocol parameter per
  server takes precedence. Default and supported values are the same as
  for the global level parameter.

- ``tkey-lifetime`` determines the lifetime of GSS-TSIG keys in the
  TKEY protocol for the DNS server. The TKEY lifetime parameter per server
  takes precedence. Default and supported values are the same as for
  the global level parameter.

- ``user-context`` is an optional parameter (see :ref:`user-context`
  for a general description of user contexts in Kea).

- ``comment`` is allowed but currently ignored.

.. _command-gss-tsig:

GSS-TSIG Commands
-----------------

The GSS-TSIG hook library supports some commands.

.. _command-gss-tsig-get-all:

The gss-tsig-get-all Command
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This command lists GSS-TSIG servers and keys.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-get-all"
    }

An example response returning 1 GSS-TSIG servers and 1 keys:

.. code-block:: json

    {
        "result": 0,
        "text": "1 GSS-TSIG servers and 1 keys",
        "arguments": {
            "gss-tsig-servers": [
                {
                    "id": "foo",
                    "ip-address": "192.1.2.3",
                    "port": 53,
                    "server-principal": "DNS/foo.com@FOO.COM",
                    "key-name-suffix": "foo.com.",
                    "tkey-lifetime": 3600,
                    "tkey-protocol": "TCP",
                    "keys": [
                        {
                            "name": "1234.sig-foo.com.",
                            "inception-date": "2021-09-05 12:23:36.281176",
                            "server-id": "foo",
                            "expire-date": "2021-09-05 13:23:36.281176",
                            "status": "not yet ready",
                            "tkey-exchange": true
                        }
                    ]
                },
                {
                    "id": "bar",
                    "ip-address": "192.1.2.4",
                    "port": 53,
                    "server-principal": "DNS/bar.com@FOO.COM",
                    "key-name-suffix": "bar.com.",
                    "tkey-lifetime": 7200,
                    "tkey-protocol": "UDP",
                    "keys": [ ]
                }
            ]
        }
    }

.. _command-gss-tsig-get:

The gss-tsig-get Command
~~~~~~~~~~~~~~~~~~~~~~~~

This command retrieves information about the specified GSS-TSIG server.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-get",
        "arguments": {
            "server-id": "foo"
        }
    }

An example response returning information about server 'foo':

.. code-block:: json

    {
        "result": 0,
        "text": "GSS-TSIG server[foo] found",
        "arguments": {
            "id": "foo",
            "ip-address": "192.1.2.3",
            "port": 53,
            "server-principal": "DNS/foo.com@FOO.COM",
            "key-name-suffix": "foo.com.",
            "tkey-lifetime": 3600,
            "tkey-protocol": "TCP",
            "keys": [
                {
                    "name": "1234.sig-foo.com.",
                    "server-id": "foo",
                    "inception-date": "2021-09-05 12:23:36.281176",
                    "expire-date": "2021-09-05 13:23:36.281176",
                    "status": "not yet ready",
                    "tkey-exchange": true
                }
            ]
        }
    }

.. _command-gss-tsig-list:

The gss-tsig-list Command
~~~~~~~~~~~~~~~~~~~~~~~~~

This command lists GSS-TSIG server IDs and key names.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-list"
    }

An example response returning 2 GSS-TSIG servers and 3 keys:

.. code-block:: json

    {
        "result": 0,
        "text": "2 GSS-TSIG servers and 3 keys",
        "arguments": {
            "gss-tsig-servers": [
                "foo",
                "bar"
            ],
            "gss-tsig-keys": [
                "1234.example.com.",
                "5678.example.com.",
                "43888.example.org."
            ]
        }
    }

.. _command-gss-tsig-key-get:

The gss-tsig-key-get Command
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This command retrieves information about the specified GSS-TSIG key.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-key-get",
        "arguments": {
            "key-name": "1234.sig-foo.com."
        }
    }

An example response returning information about GSS-TSIG key '1234.sig-foo.com.':

.. code-block:: json

    {
        "result": 0,
        "text": "GSS-TSIG key '1234.sig-foo.com.' found",
        "arguments": {
            "name": "1234.sig-foo.com.",
            "server-id": "foo",
            "inception-date": "2021-09-05 12:23:36.281176",
            "expire-date": "2021-09-05 13:23:36.281176",
            "status": "not yet ready",
            "tkey-exchange": true
        }
    }

.. _command-gss-tsig-key-expire:

The gss-tsig-key-expire Command
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This command expires the specified GSS-TSIG key.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-key-expire",
        "arguments": {
            "key-name": "1234.sig-foo.com."
        }
    }

An example response informing about GSS-TSIG key '1234.sig-foo.com.' being expired:

.. code-block:: json

    {
        "result": 0,
        "text": "GSS-TSIG key '1234.sig-foo.com.' expired"
    }

.. _command-gss-tsig-key-del:

The gss-tsig-key-del Command
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This command deletes the specified GSS-TSIG key.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-key-del",
        "arguments": {
            "key-name": "1234.sig-foo.com."
        }
    }

An example response informing about GSS-TSIG key '1234.sig-foo.com.' being deleted:

.. code-block:: json

    {
        "result": 0,
        "text": "GSS-TSIG key '1234.sig-foo.com.' deleted"
    }

.. _command-gss-tsig-purge-all:

The gss-tsig-purge-all Command
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This command removes not usable GSS-TSIG keys.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-purge-all"
    }

An example response informing about 2 GSS-TSIG keys being purged:

.. code-block:: json

    {
        "result": 0,
        "text": "2 purged GSS-TSIG keys"
    }

.. _command-gss-tsig-purge:

The gss-tsig-purge Command
~~~~~~~~~~~~~~~~~~~~~~~~~~

This command removes not usable GSS-TSIG keys for the specified server.

An example command invocation looks like this:

.. code-block:: json

    {
        "command": "gss-tsig-purge",
        "arguments": {
            "server-id": "foo"
        }
    }

An example response informing about 2 GSS-TSIG keys for server 'foo' being purged:

.. code-block:: json

    {
        "result": 0,
        "text": "2 purged keys for GSS-TSIG server[foo]"
    }
