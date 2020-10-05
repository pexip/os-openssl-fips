#!/usr/bin/env sh

set -e

FIPS_MODULE_URL=https://github.com/oracle/solaris-openssl-fips/releases/download/v1.0/OpenSSL_2.0.13_OracleFIPS_1.0.tar.gz
FIPS_MODULE_SOURCEDIR=OracleFIPS_1.0
FIPS_MODULE_TARBALL=OpenSSL_2.0.13_OracleFIPS_1.0.tar.gz
FIPS_INSTALL_LOCATION=/usr/local/ssl/fips-2.0

OS_RELEASE=$(lsb_release -ds | sed -e 's/^\([A-Za-z]\+ [0-9]\+\.[0-9]\+\).*$/\1/')

EXPECTED_HMAC_SHA1=ef8f7a91979cad14d033d8803a89fdf925102a30

[ "${EXPECTED_HMAC_SHA1}" = "$(openssl sha1 -hmac etaonrishdlcupfm ${FIPS_MODULE_TARBALL} | cut -d' ' -f2)" ] || exit 1
[ -w ${FIPS_INSTALL_LOCATION} ] || sudo install --directory --mode=0777 ${FIPS_INSTALL_LOCATION}
tar -zxf ${FIPS_MODULE_TARBALL}
(cd ${FIPS_MODULE_SOURCEDIR} && ./config && make && make install)
rm -fr ${FIPS_MODULE_SOURCEDIR}
mkdir output
mv ${FIPS_INSTALL_LOCATION}/* output
sudo rm -fr ${FIPS_INSTALL_LOCATION}
cat <<EOF >output/Testament
This FIPS 140-2 validated cryptographic module (Certificate #3503)
was built at $(date) on ${OS_RELEASE} running on $(uname -m) using
gcc $(gcc --version | head -n1 | cut -d' ' -f4).

It was built from the unmodified contents of ${FIPS_MODULE_TARBALL} as
downloaded from ${FIPS_MODULE_URL}
and identified by the HMAC-SHA-1 digest ${EXPECTED_HMAC_SHA1}.

The module was unpacked and built using the commands specified in
the Security Policy document:

    tar -zxf ${FIPS_MODULE_TARBALL}
    ./config
    make
    make install

No other build-time options were specified.

The resulting binary cryptographic module carries the HMAC-SHA-1 digest
$(cut -d' ' -f2 <output/lib/fipscanister.o.sha1).
EOF
