FROM php:5.5

LABEL maintainer="phithon <root@leavesongs.com>"

ARG ZEPHIR_VERSION=0.11.1
ARG ZEPHIR_PARSER_VERSION=1.1.2

ENV PATH=${PATH}:/root/.composer/vendor/bin

RUN set -ex \
    && echo "deb http://ftp.debian.org/debian stretch main " > /etc/apt/sources.list.d/stretch.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends git unzip re2c ca-certificates wget \
    && curl -sL https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer \
    && rm -rf /var/lib/apt/lists/*

RUN set -ex \
    && composer global require phalcon/zephir:${ZEPHIR_VERSION} \
    && composer clearcache -n

RUN set -ex \
    && mkdir -p /usr/share/zephir \
    && curl -sL https://github.com/phalcon/php-zephir-parser/archive/v${ZEPHIR_PARSER_VERSION}.tar.gz \
        | tar xz --strip-components=1 -C /usr/share/zephir \
    && cd /usr/share/zephir \
    && ./install \
    && { \
        echo '[Zephir Parser]'; \
        echo 'extension=zephir_parser.so'; \
    } >> /usr/local/etc/php/conf.d/zephir_parser.ini \
    && { \
        echo '#!/usr/bin/env bash'; \
        echo 'exec "$@"'; \
    } >> /usr/bin/sudo \
    && chmod +x /usr/bin/sudo \
    && rm -rf /usr/share/zephir

CMD ["zephir"]