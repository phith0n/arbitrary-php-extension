
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ARBITRARYPHP_H
#define PHP_ARBITRARYPHP_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ARBITRARYPHP_NAME        "arbitraryphp"
#define PHP_ARBITRARYPHP_VERSION     "1.0.0"
#define PHP_ARBITRARYPHP_EXTNAME     "arbitraryphp"
#define PHP_ARBITRARYPHP_AUTHOR      "github"
#define PHP_ARBITRARYPHP_ZEPVERSION  "0.11.1"
#define PHP_ARBITRARYPHP_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(arbitraryphp)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(arbitraryphp)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(arbitraryphp)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(arbitraryphp_globals_id, zend_arbitraryphp_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (arbitraryphp_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_arbitraryphp_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(arbitraryphp_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(arbitraryphp_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def arbitraryphp_globals
#define zend_zephir_globals_def zend_arbitraryphp_globals

extern zend_module_entry arbitraryphp_module_entry;
#define phpext_arbitraryphp_ptr &arbitraryphp_module_entry

#endif
