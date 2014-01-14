#!/usr/bin/env sh

set -e

FIPS_MODULE_NAME=openssl-fips
FIPS_MODULE_VERSION=2.0.5
FIPS_MODULE_SOURCEDIR=${FIPS_MODULE_NAME}-${FIPS_MODULE_VERSION}
FIPS_MODULE_TARBALL=${FIPS_MODULE_SOURCEDIR}.tar.gz
FIPS_INSTALL_LOCATION=/usr/local/ssl/fips-2.0

OS_RELEASE=$(lsb_release -ds | sed -e 's/^\([A-Za-z]\+ [0-9]\+\.[0-9]\+\).*$/\1/')

EXPECTED_HMAC_SHA1=8b44f2a43d098f6858eb1ebe77b73f8f027a9c29

[ "${EXPECTED_HMAC_SHA1}" = "$(openssl sha1 -hmac etaonrishdlcupfm ${FIPS_MODULE_TARBALL} | cut -d' ' -f2)" ] || exit 1
[ -w ${FIPS_INSTALL_LOCATION} ] || sudo install --directory --mode=0777 ${FIPS_INSTALL_LOCATION}
gunzip -c ${FIPS_MODULE_TARBALL} | tar xf -
(cd ${FIPS_MODULE_SOURCEDIR} && ./config && make && make install)
rm -fr ${FIPS_MODULE_SOURCEDIR}
mkdir output
mv ${FIPS_INSTALL_LOCATION}/* output
sudo rm -fr ${FIPS_INSTALL_LOCATION}
cat <<EOF >output/Testament
This FIPS 140-2 validated cryptographic module (Certificate #1747)
was built at $(date) on ${OS_RELEASE} running on $(uname -m) using 
gcc $(gcc --version | head -n1 | cut -d' ' -f4).

It was built from the unmodified contents of ${FIPS_MODULE_TARBALL} as 
received on physical media from the OpenSSL Foundation and identified
by the HMAC-SHA-1 digest ${EXPECTED_HMAC_SHA1}.

The module was unpacked and built using command set U2 as specified in
the Security Policy document:

    gunzip -c ${FIPS_MODULE_TARBALL} | tar xf -
    ./config
    make
    make install

No other build-time options were specified.

The resulting binary cryptographic module carries the HMAC-SHA-1 digest
$(cut -d' ' -f2 <output/lib/fipscanister.o.sha1).
EOF
