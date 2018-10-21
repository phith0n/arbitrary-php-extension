#!/bin/bash

set -ex

for tag in '7.2' '7.1' '7.0' '5.6' '5.5' '5.4'
do
    docker run -it --rm --name uu -v /root/arbitrary-php:/app tuwen/zephir:${tag} bash /app/build-ext.sh
done