#!/bin/bash

set -ex

VERSION=$(php -r 'list($a, $b, $c) = explode(".",phpversion()); echo $a.".".$b;')
BASEDIR=/app

cd ${BASEDIR}/arbitraryphp

zephir build


if [ ! -e ${BASEDIR}/lib/${VERSION} ]; then
    mkdir -p ${BASEDIR}/lib/${VERSION}
fi

cp ext/modules/arbitraryphp.so ${BASEDIR}/lib/${VERSION}/

zephir fullclean