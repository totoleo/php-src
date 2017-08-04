/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"

#include "ext/standard/info.h"
#include "php_php_perf.h"

#include <time.h>

/* If you declare any globals in php_php_perf.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php_perf)
*/

/* True global resources - no need for thread safety here */
static int le_php_perf;

/* {{{ proto string hello_world(string arg)
   Say Hello World to everyone */
PHP_FUNCTION(hello_world)
{
		uint64_t n=0;
		uint64_t arg_len;
		clock_t start, end;

		if(zend_parse_parameters(ZEND_NUM_ARGS(),"l", &n,&arg_len)==FAILURE){
			return;
		}

		const char * s = "Hello world";
		start = clock();
		for (size_t i = 0; i < n; i++) {
			/* code */
			ZVAL_STRING(return_value, s);
			zend_string_release(return_value->value.str);
		}

		end = clock();
		php_printf("%f\n", ((double)(end-start))/CLOCKS_PER_SEC);
		RETURN_STRING(s);

}
/* }}} */
/*{{{ perf_array()*/
PHP_FUNCTION(perf_array)
{
	zval test;
	clock_t start,end;
	start = clock();
	array_init(&test);

	char index[20];
	for (size_t i = 0; i < 10000; i++) {
		sprintf(index,"hello:%d",i);
		add_assoc_long(&test,index,i);
		char value[40];
		sprintf(value,"hello_value:%zu",i);
		add_assoc_string(&test,index,value);
	}
	end = clock();
	php_printf("%f\n", ((double)(end-start))/CLOCKS_PER_SEC);

	RETURN_ZVAL(&test,0,0);
}
/*}}}*/

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php_perf)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_perf)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_perf)
{
#if defined(COMPILE_DL_PHP_PERF) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_perf)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_perf)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php_perf support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ php_perf_functions[]
 *
 * Every user visible function must have an entry in php_perf_functions[].
 */
const zend_function_entry php_perf_functions[] = {
	PHP_FE(hello_world, NULL)
	PHP_FE(perf_array, NULL)/*array test*/
	PHP_FE_END	/* Must be the last line in php_perf_functions[] */
};
/* }}} */

/* {{{ php_perf_module_entry
 */
zend_module_entry php_perf_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_perf",
	php_perf_functions,
	PHP_MINIT(php_perf),
	PHP_MSHUTDOWN(php_perf),
	PHP_RINIT(php_perf),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php_perf),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php_perf),
	PHP_PHP_PERF_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_PERF
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(php_perf)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
