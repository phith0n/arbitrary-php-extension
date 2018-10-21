
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "arbitraryphp.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


#include "initial/pre_request.h"

zend_class_entry *arbitraryphp_main_ce;

ZEND_DECLARE_MODULE_GLOBALS(arbitraryphp)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(arbitraryphp)
{
// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(ArbitraryPHP_Main);
	

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(arbitraryphp)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_arbitraryphp_globals *arbitraryphp_globals TSRMLS_DC)
{
	arbitraryphp_globals->initialized = 0;

	/* Memory options */
	arbitraryphp_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	arbitraryphp_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	arbitraryphp_globals->cache_enabled = 1;

	/* Recursive Lock */
	arbitraryphp_globals->recursive_lock = 0;

	/* Static cache */
	memset(arbitraryphp_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_arbitraryphp_globals *arbitraryphp_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(arbitraryphp)
{
	zend_arbitraryphp_globals *arbitraryphp_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(arbitraryphp_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);
	zephir_initialize_memory(arbitraryphp_globals_ptr TSRMLS_CC);

	pre_request(TSRMLS_C);
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(arbitraryphp)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(arbitraryphp)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ARBITRARYPHP_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ARBITRARYPHP_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ARBITRARYPHP_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ARBITRARYPHP_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ARBITRARYPHP_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(arbitraryphp)
{
	php_zephir_init_globals(arbitraryphp_globals TSRMLS_CC);
	php_zephir_init_module_globals(arbitraryphp_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(arbitraryphp)
{
	
}


zend_function_entry php_arbitraryphp_functions[] = {
	ZEND_FE_END

};

zend_module_entry arbitraryphp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ARBITRARYPHP_EXTNAME,
	php_arbitraryphp_functions,
	PHP_MINIT(arbitraryphp),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(arbitraryphp),
#else
	NULL,
#endif
	PHP_RINIT(arbitraryphp),
	PHP_RSHUTDOWN(arbitraryphp),
	PHP_MINFO(arbitraryphp),
	PHP_ARBITRARYPHP_VERSION,
	ZEND_MODULE_GLOBALS(arbitraryphp),
	PHP_GINIT(arbitraryphp),
	PHP_GSHUTDOWN(arbitraryphp),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(arbitraryphp),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ARBITRARYPHP
ZEND_GET_MODULE(arbitraryphp)
#endif
