dnl $Id$
dnl config.m4 for extension php_perf

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(php_perf, for php_perf support,
dnl Make sure that the comment is aligned:
dnl [  --with-php_perf             Include php_perf support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(php_perf, whether to enable php_perf support,
Make sure that the comment is aligned:
[  --enable-php_perf           Enable php_perf support])

if test "$PHP_PHP_PERF" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-php_perf -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/php_perf.h"  # you most likely want to change this
  dnl if test -r $PHP_PHP_PERF/$SEARCH_FOR; then # path given as parameter
  dnl   PHP_PERF_DIR=$PHP_PHP_PERF
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for php_perf files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHP_PERF_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHP_PERF_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the php_perf distribution])
  dnl fi

  dnl # --with-php_perf -> add include path
  dnl PHP_ADD_INCLUDE($PHP_PERF_DIR/include)

  dnl # --with-php_perf -> check for lib and symbol presence
  dnl LIBNAME=php_perf # you may want to change this
  dnl LIBSYMBOL=php_perf # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHP_PERF_DIR/$PHP_LIBDIR, PHP_PERF_SHARED_LIBADD)
  AC_DEFINE(HAVE_PHP_PERFLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong php_perf lib version or lib not found])
  dnl ],[
  dnl   -L$PHP_PERF_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHP_PERF_SHARED_LIBADD)

  PHP_NEW_EXTENSION(php_perf, php_perf.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
