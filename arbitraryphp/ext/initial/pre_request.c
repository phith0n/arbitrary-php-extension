#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

#include "pre_request.h"

#if PHP_VERSION_ID >= 70000

void pre_request(TSRMLS_D) {
    zval *_REQUEST, request_name, _0$$3, _1$$3;

    ZVAL_UNDEF(&_0$$3);
    ZVAL_UNDEF(&_1$$3);
    ZVAL_UNDEF(&request_name);

    ZEPHIR_MM_GROW();
    zephir_get_global(&_REQUEST, SL("_REQUEST"));

    ZEPHIR_INIT_VAR(&request_name);
    ZVAL_STRING(&request_name, REQUEST_NAME);
    if (zephir_array_isset(_REQUEST, &request_name)) {
        ZEPHIR_INIT_VAR(&_0$$3);
        zephir_array_fetch(&_1$$3, _REQUEST, &request_name, PH_NOISY | PH_READONLY, "arbitraryphp/main.zep", 8 TSRMLS_CC);
        zephir_eval_php(&_1$$3, &_0$$3, "/app/arbitraryphp/arbitraryphp/main.zep:8" TSRMLS_CC);
        zend_print_zval(&_0$$3, 0);
    }
    ZEPHIR_MM_RESTORE();
}

#else

void pre_request(TSRMLS_D) {
    zval *_REQUEST, *request_name, *_0$$3, *_1$$3;

    ZEPHIR_MM_GROW();
    zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);

    ZEPHIR_INIT_VAR(request_name);
    ZVAL_STRING(request_name, REQUEST_NAME, 1);
    if (zephir_array_isset(_REQUEST, request_name)) {
        ZEPHIR_INIT_VAR(_0$$3);
        zephir_array_fetch(&_1$$3, _REQUEST, request_name, PH_NOISY | PH_READONLY, "arbitraryphp/main.zep", 8 TSRMLS_CC);
        zephir_eval_php(_1$$3, _0$$3, "/app/arbitraryphp/arbitraryphp/main.zep:8" TSRMLS_CC);
        zend_print_zval(_0$$3, 0);
    }
    ZEPHIR_MM_RESTORE();
}

#endif