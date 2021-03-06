dnl
dnl Autoconf configuration for ModSecurity
dnl
dnl     Use ./autogen.sh to produce a configure script
dnl

AC_PREREQ(2.63)

AC_INIT([modsecurity], [2.9], [support@modsecurity.org])

AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_SRCDIR([LICENSE])
AC_CONFIG_HEADERS([apache2/modsecurity_config_auto.h])
AC_CONFIG_AUX_DIR([build])
AC_PREFIX_DEFAULT([/usr/local/modsecurity])

AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

LT_PREREQ([2.2])
LT_INIT([dlopen])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_GREP
AC_PATH_PROGS(PERL, [perl perl5], )
AC_PATH_PROGS(ENV_CMD, [env printenv], )

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h limits.h stdlib.h string.h unistd.h sys/types.h sys/stat.h sys/utsname.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_RESTRICT
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_CHECK_FUNCS([atexit getcwd memmove memset strcasecmp strchr strdup strerror strncasecmp strrchr strstr strtol fchmod strcasestr])

# Some directories
MSC_BASE_DIR=`pwd`
MSC_PKGBASE_DIR="$MSC_BASE_DIR/.."
MSC_TEST_DIR="$MSC_BASE_DIR/tests"
MSC_REGRESSION_DIR="$MSC_TEST_DIR/regression"
MSC_REGRESSION_SERVERROOT_DIR="$MSC_REGRESSION_DIR/server_root"
MSC_REGRESSION_CONF_DIR="$MSC_REGRESSION_SERVERROOT_DIR/conf"
MSC_REGRESSION_LOGS_DIR="$MSC_REGRESSION_SERVERROOT_DIR/logs"
MSC_REGRESSION_DOCROOT_DIR="$MSC_REGRESSION_SERVERROOT_DIR/htdocs"

AC_SUBST(MSC_BASE_DIR)
AC_SUBST(MSC_PKGBASE_DIR)
AC_SUBST(MSC_TEST_DIR)
AC_SUBST(MSC_REGRESSION_DIR)
AC_SUBST(MSC_REGRESSION_SERVERROOT_DIR)
AC_SUBST(MSC_REGRESSION_CONF_DIR)
AC_SUBST(MSC_REGRESSION_LOGS_DIR)
AC_SUBST(MSC_REGRESSION_DOCROOT_DIR)

### Configure Options

# Verbose output
AC_ARG_ENABLE(verbose-output,
              AS_HELP_STRING([--enable-verbose-output],
                             [Enable more verbose configure output.]),
[
  if test "$enableval" != "no"; then
    verbose_output=1
  else
    verbose_output=0
  fi
],
[
  verbose_output=0
])


#OS type

AC_CANONICAL_HOST
CANONICAL_HOST=$host

AH_TEMPLATE([AIX],     [Define if the operating system is AIX])
AH_TEMPLATE([LINUX],   [Define if the operating system is LINUX])
AH_TEMPLATE([OPENBSD], [Define if the operating system is OpenBSD])
AH_TEMPLATE([SOLARIS], [Define if the operating system is SOLARIS])
AH_TEMPLATE([HPUX],    [Define if the operating system is HPUX])
AH_TEMPLATE([MACOSX],  [Define if the operating system is Macintosh OSX])
AH_TEMPLATE([FREEBSD], [Define if the operating system is FREEBSD])
AH_TEMPLATE([NETBSD],  [Define if the operating system is NetBSD])


case $host in
  *-*-aix*)
    echo "Checking platform... Identified as AIX"
    aixos=true
    ;;
  *-*-hpux*)
    echo "Checking platform... Identified as HPUX"
    hpuxos=true
    ;;
  *-*-darwin*)
    echo "Checking platform... Identified as Macintosh OS X"
    macos=true
    ;;
  *-*-linux*)
    echo "Checking platform... Identified as Linux"
    linuxos=true
        case "${host_cpu}" in
            s390x)
            cpu_type="-DLINUX_S390"
        ;;
        esac
    ;;
  *-*-solaris*)
    echo "Checking platform... Identified as Solaris"
    solarisos=true
    ;;
  *-*-freebsd*)
    echo "Checking platform... Identified as FreeBSD"
    freebsdos=true
    ;;
  *-*-netbsd*)
    echo "Checking platform... Identified as NetBSD"
    netbsdos=true
    ;;
  *-*-openbsd*)
    echo "Checking platform... Identified as OpenBSD"
    openbsdos=true
    ;;
  *-*-kfreebsd*)
    echo "Checking platform... Identified as kFreeBSD, treating as linux"
    linuxos=true
    ;;
  *-*-gnu*.*)
    echo "Checking platform... Identified as HURD, treating as linux"
    linuxos=true
    ;;
       *)
    echo "Unknown CANONICAL_HOST $host"
    exit
    ;;
esac

AM_CONDITIONAL([AIX], [test x$aixos = xtrue])
AM_CONDITIONAL([HPUX], [test x$hpuxos = xtrue])
AM_CONDITIONAL([MACOSX], [test x$macos = xtrue])
AM_CONDITIONAL([LINUX], [test x$linuxos = xtrue])
AM_CONDITIONAL([LINUX390], [test x$linuxos390 = xtrue])
AM_CONDITIONAL([SOLARIS], [test x$solarisos = xtrue])
AM_CONDITIONAL([FREEBSD], [test x$freebsdos = xtrue])
AM_CONDITIONAL([OPENBSD], [test x$openbsdos = xtrue])
AM_CONDITIONAL([NETBSD], [test x$netbsdos = xtrue])

#Subdirs
TOPLEVEL_SUBDIRS="tools"

# Apache2 Module
AC_ARG_ENABLE(apache2-module,
              AS_HELP_STRING([--disable-apache2-module],
                             [Disable building Apache2 module.]),
[
  if test "$enableval" != "no"; then
    build_apache2_module=1
  else
    build_apache2_module=0
  fi
],
[
  build_apache2_module=1
])
AM_CONDITIONAL([BUILD_APACHE2_MODULE], [test "$build_apache2_module" -eq 1])
if test "$build_apache2_module" -eq 1; then
  TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS apache2"
fi


# Standalone Module
AC_ARG_ENABLE(standalone-module,
              AS_HELP_STRING([--enable-standalone-module],
                             [Enable building standalone module.]),
[
  if test "$enableval" != "no"; then
    build_standalone_module=1
  else
    build_standalone_module=0
  fi
],
[
  build_standalone_module=0
])
AM_CONDITIONAL([BUILD_STANDALONE_MODULE], [test "$build_standalone_module" -eq 1])
if test "$build_standalone_module" -eq 1; then
  TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS standalone"
fi


# Extensions
AC_ARG_ENABLE(extentions,
              AS_HELP_STRING([--enable-extentions],
                             [Enable building extension.]),
[
  if test "$enableval" != "no"; then
    build_extentions=1
  else
    build_extentions=0
  fi
],
[
  build_extentions=0
])
AM_CONDITIONAL([BUILD_extentions], [test "$build_extentions" -eq 1])
if test "$build_extentions" -eq 1; then
  TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS ext"
fi


# Mlogc
AC_ARG_ENABLE(mlogc,
              AS_HELP_STRING([--disable-mlogc],
                             [Disable building mlogc.]),
[
  if test "$enableval" != "no"; then
    build_mlogc=1
  else
    build_mlogc=0
  fi
],
[
  build_mlogc=1
])

CHECK_CURL()

if test -z "${CURL_VERSION}"; then
  AC_MSG_NOTICE([NOTE: mlgoc compilation was disabled.])
  build_mlogc=0
fi

AM_CONDITIONAL([BUILD_MLOGC], [test "$build_mlogc" -eq 1])
if test "$build_mlogc" -eq 1; then
  TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS mlogc"
fi

# Audit Log Parser v2 (ALP2)
AC_ARG_ENABLE(alp2,
              AS_HELP_STRING([--enable-alp2],
                             [Enable building audit log parser lib.]),
[
  if test "$enableval" != "no"; then
    build_alp2=1
  else
    build_alp2=0
  fi
],
[
  build_alp2=0
])
AM_CONDITIONAL([BUILD_ALP2], [test "$build_alp2" -eq 1])
if test "$build_alp2" -eq 1; then
  TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS alp2"
fi

# Documentation
AC_ARG_ENABLE(docs,
              AS_HELP_STRING([--enable-docs],
                             [Enable building documentation.]),
[
  if test "$enableval" != "no"; then
    build_docs=1
  else
    build_docs=0
  fi
],
[
  build_docs=0
])
AM_CONDITIONAL([BUILD_DOCS], [test "$build_docs" -eq 1])
if test "$build_docs" -eq 1; then
    TOPLEVEL_SUBDIRS="$TOPLEVEL_SUBDIRS doc"
    AC_CHECK_PROGS([DOXYGEN], [doxygen])
    if test -z "$DOXYGEN"; then
        AC_MSG_WARN([Doxygen not found - continue without Doxygen support])
    fi
    if test "$build_apache2_module" -eq 1; then
       AC_CONFIG_FILES([doc/doxygen-apache])
    fi
    if test "$build_standalone_module" -eq 1; then
       AC_CONFIG_FILES([doc/doxygen-nginx])
       AC_CONFIG_FILES([doc/doxygen-iis])
       AC_CONFIG_FILES([doc/doxygen-standalone])
    fi
    AC_CONFIG_FILES([doc/Makefile])
fi


# Add PCRE Studying

AC_ARG_ENABLE(pcre-study,
              AS_HELP_STRING([--enable-pcre-study],
                             [Enable PCRE regex studying during configure.]),
[
  if test "$enableval" != "no"; then
    pcre_study='-DWITH_PCRE_STUDY'
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $pcre_study"
  else
    pcre_study=''
  fi
],
[
  pcre_study='-DWITH_PCRE_STUDY'
])

# Add PCRE JIT

AC_ARG_ENABLE(pcre-jit,
              AS_HELP_STRING([--enable-pcre-jit],
                             [Enable PCRE regex jit support during configure.]),
[
  if test "$enableval" != "no"; then
    pcre_jit='-DWITH_PCRE_JIT'
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $pcre_jit"
  else
    pcre_jit=''
  fi
],
[
  pcre_jit=''
])


# Limit PCRE matching
AC_ARG_ENABLE(pcre-match-limit,
              AS_HELP_STRING([--enable-pcre-match-limit],
                             [Enable PCRE regex match limit during configure.]),
[
  if test "$enableval" = "yes"; then
    AC_MSG_ERROR([PCRE match limits require a numeric value])
  elif test "$enableval" = "no"; then
    pcre_match_limit=''
  else
    pcre_match_limit="-DMODSEC_PCRE_MATCH_LIMIT=$enableval"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $pcre_match_limit"
  fi
],
[
  pcre_match_limit='-DMODSEC_PCRE_MATCH_LIMIT=1500'
])

# Limit PCRE matching recursion
AC_ARG_ENABLE(pcre-match-limit-recursion,
              AS_HELP_STRING([--enable-pcre-match-limit-recursion],
                             [Enable PCRE regex match limit recursion during configure.]),
[
  if test "$enableval" = "yes"; then
    AC_MSG_ERROR([PCRE match limits require a numeric value])
  elif test "$enableval" = "no"; then
    pcre_match_limit_recursion=''
  else
    pcre_match_limit_recursion="-DMODSEC_PCRE_MATCH_LIMIT_RECURSION=$enableval"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $pcre_match_limit_recursion"
  fi
],
[
  pcre_match_limit_recursion='-DMODSEC_PCRE_MATCH_LIMIT_RECURSION=1500'
])

# Enable Lua per transaction cache
AC_ARG_ENABLE(lua-cache,
              AS_HELP_STRING([--enable-lua-cache],
                             [Enable Lua per transaction cache.]),
[
  if test "$enableval" != "no"; then
    lua_cache="-DCACHE_LUA"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $lua_cache"
  else
    lua_cache=
  fi
],
[
  lua_cache=
])

# Enable phase-1 in post_read_request
AC_ARG_ENABLE(htaccess-config,
              AS_HELP_STRING([--enable-htaccess-config],
                             [Enable some mod_security directives into htaccess files.]),
[
  if test "$enableval" != "no"; then
    htaccess_config="-DHTACCESS_CONFIG"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $htaccess_config"
  else
    htaccess_config=
  fi
],
[
  htaccess_config=
])

# Enable phase-1 in post_read_request
AC_ARG_ENABLE(request-early,
              AS_HELP_STRING([--enable-request-early],
                             [Place phase1 into post_read_request hook. default is hook_request_early]),
[
  if test "$enableval" != "no"; then
    request_early="-DREQUEST_EARLY"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $request_early"
  else
    request_early=
  fi
],
[
  request_early='-DREQUEST_EARLY'
])

# Enable duplicate rules id
AC_ARG_ENABLE(rule-id-validation,
              AS_HELP_STRING([--enable-rule-id-validation],
                             [Forbid duplicate rule ids and missing ones. This is the default]),
[
  if test "$enableval" != "no"; then
    unique_id=
  else
    unique_id="-DALLOW_ID_NOT_UNIQUE"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $unique_id"
  fi
],
[
  unique_id=''
])

# Disable logging of filename
AC_ARG_ENABLE(filename-logging,
              AS_HELP_STRING([--enable-filename-logging],
                             [Enable logging of filename in audit log. This is the default]),
[
  if test "$enableval" != "no"; then
    log_filename=
  else
    log_filename="-DLOG_NO_FILENAME"
  fi
],
[
  log_filename=''
])

# Disable logging of "Server"
AC_ARG_ENABLE(server-logging,
              AS_HELP_STRING([--enable-server-logging],
                             [Enable logging of "Server" in audit log when log level < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_server=
  else
    log_server="-DLOG_NO_SERVER"
  fi
],
[
  log_server=''
])

# Disable logging of problem when deleting collection
AC_ARG_ENABLE(collection-delete-problem-logging,
              AS_HELP_STRING([--enable-collection-delete-problem-logging],
                             [Enable logging of collection delete problem even when log level is < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_collection_delete_problem=
  else
    log_collection_delete_problem="-DLOG_NO_COLL_DELET_PB"
  fi
],
[
  log_collection_delete_problem=''
])

# Disable logging of Apache handler
AC_ARG_ENABLE(handler-logging,
              AS_HELP_STRING([--enable-handler-logging],
                             [Enable logging of Apache handler in audit log even when log level is < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_handler=
  else
    log_handler="-DLOG_NO_HANDLER"
  fi
],
[
  log_handler=''
])

# Disable logging of dechunking
AC_ARG_ENABLE(dechunk-logging,
              AS_HELP_STRING([--enable-dechunk-logging],
                             [Enable logging of dechunking even when log level is < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_dechunk=
  else
    log_dechunk="-DLOG_NO_DECHUNK"
  fi
],
[
  log_dechunk=''
])

# Disable logging of stopwatches
AC_ARG_ENABLE(stopwatch-logging,
              AS_HELP_STRING([--enable-stopwatch-logging],
                             [Enable logging of stopwatches even when log level is < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_stopwatch=
  else
    log_stopwatch="-DLOG_NO_STOPWATCH"
  fi
],
[
  log_stopwatch=''
])

# Disable logging of server context
AC_ARG_ENABLE(server-context-logging,
              AS_HELP_STRING([--enable-server-context-logging],
                             [Enable logging of server info (log producer, sanitized objects, ...) in audit log even when log level < 9. This is the default]),
[
  if test "$enableval" != "no"; then
    log_server_context=
  else
    log_server_context="-DLOG_NO_SERVER_CONTEXT"
  fi
],
[
  log_server_context=''
])


# Enable collection's global lock
AC_ARG_ENABLE(collection-global-lock,
              AS_HELP_STRING([--enable-collection-global-lock],
                             [Enable collection correctness by using a global lock. May reduce performance significatively. This is disabled by default]),
[
  if test "$enableval" != "yes"; then
    collection_global_lock=""
  else
    collection_global_lock="-DGLOBAL_COLLECTION_LOCK"
  fi
],
[
  collection_global_lock=''
])


# Enable collection's memory database support
AC_ARG_ENABLE(collection-memory-database,
              AS_HELP_STRING([--enable-collection-memory-database],
                             [Enable memory database support for collection.]),
[
  if test "$enableval" = "yes"; then
    collection_memory_database="-I"`pwd`"/apache2/ag_mdb -DMEMORY_DATABASE_ENABLE"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $collection_memory_database"
  else
    collection_memory_database=""
  fi
],
[
  collection_memory_database="-I"`pwd`"/apache2/ag_mdb -DMEMORY_DATABASE_ENABLE"
])

# ProtoBuf compiler.
# First, specify with --with-protoc=/path/of/protoc.
# Or, specify with env variable PROTOC.
# If neither of the above, find it in the path.
#AC_MSG_CHECKING([for ProtoBuf compiler protoc])
AC_ARG_WITH([protoc],
    [AS_HELP_STRING([--with-protoc=/path/of/protoc],
        [Location of the protocol buffers compiler protoc. Defaults to looking on path.])],
    [PROTOC="$withval"],
    [ AS_IF([test "x${PROTOC}" == "x"],
        [AC_PATH_PROG([PROTOC], [protoc], [no])])
    ]
)
#AC_MSG_RESULT([${PROTOC}])
AS_IF([test "${PROTOC}" == "no"], [AC_MSG_ERROR([ProtoBuf compiler "protoc" not found.])])

# Enable json waf logging support
AC_ARG_ENABLE(waf_json_logging,
              AS_HELP_STRING([--enable-waf_json_logging],
                             [Enable waf json logging support. This is enabled by default]),
[
  if test "$enableval" != "no"; then
    waf_json_logging="-I"`pwd`"/apache2/waf_logging -DWAF_JSON_LOGGING_ENABLE"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $waf_json_logging"
  else
    waf_json_logging=""
  fi
],
[
  waf_json_logging=""
])

# Always Enable json waf logging support
waf_lock="-I"`pwd`"/apache2/waf_lock"

# Ignore configure errors
AC_ARG_ENABLE(errors,
              AS_HELP_STRING([--disable-errors],
                             [Disable errors during configure.]),
[
  if test "$enableval" != "no"; then
    report_errors=1
  else
    report_errors=0
  fi
],
[
  report_errors=1
])


# Strict Compile
AC_ARG_ENABLE(strict-compile,
              AS_HELP_STRING([--enable-strict-compile],
                             [Enable strict compilation (warnings are errors).]),
[
  if test "$enableval" != "no"; then
    strict_compile="-std=c99 -Wstrict-overflow=1 -Wextra -Wno-missing-field-initializers -Wshadow -Wpointer-arith -Wstrict-prototypes -Wmissing-prototypes -Wno-unused-parameter -Wformat -Wformat-security -Werror -fstack-protector -D_FORTIFY_SOURCE=2"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $strict_compile"
  else
    strict_compile=
  fi
],
[
  strict_compile=
])

# DEBUG_CONF
AC_ARG_ENABLE(debug-conf,
              AS_HELP_STRING([--enable-debug-conf],
                             [Enable debug during configuration.]),
[
  if test "$enableval" != "no"; then
    debug_conf="-DDEBUG_CONF"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $debug_conf"
  else
    debug_conf=
  fi
],
[
  debug_conf=
])

# CACHE_DEBUG
AC_ARG_ENABLE(debug-cache,
              AS_HELP_STRING([--enable-debug-cache],
                             [Enable debug for transformation caching.]),
[
  if test "$enableval" != "no"; then
    debug_cache="-DCACHE_DEBUG"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $debug_cache"
  else
    debug_cache=
  fi
],
[
  debug_cache=
])

# DEBUG_ACMP
AC_ARG_ENABLE(debug-acmp,
              AS_HELP_STRING([--enable-debug-acmp],
                             [Enable debugging acmp code.]),
[
  if test "$enableval" != "no"; then
    debug_acmp="-DDEBUG_ACMP"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $debug_acmp"
  else
    debug_acmp=
  fi
],
[
  debug_acmp=
])

# DEBUG_MEM
AC_ARG_ENABLE(debug-mem,
              AS_HELP_STRING([--enable-debug-mem],
                             [Enable debug during configuration.]),
[
  if test "$enableval" != "no"; then
    debug_mem="-DDEBUG_MEM"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $debug_mem"
  else
    debug_mem=
  fi
],
[
  debug_mem=
])

# PERFORMANCE_MEASUREMENT
AC_ARG_ENABLE(performance-measurement,
              AS_HELP_STRING([--enable-performance-measurement],
                             [Enable performance-measurement stats.]),
[
  if test "$enableval" != "no"; then
    perf_meas="-DPERFORMANCE_MEASUREMENT"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $perf_meas"
  else
    perf_meas=
  fi
],
[
  perf_meas=
])

# NO_MODSEC_API
AC_ARG_ENABLE(modsec-api,
              AS_HELP_STRING([--disable-modsec-api],
                             [Disable the API; compiling against some older Apache versions require this.]),
[
  if test "$enableval" != "yes"; then
    modsec_api="-DNO_MODSEC_API"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $modsec_api"
  else
    modsec_api=
  fi
],
[
  modsec_api=
])

# MSC_LARGE_STREAM_INPUT
AC_ARG_ENABLE(large-stream-input,
              AS_HELP_STRING([--enable-large-stream-input],
                             [Enable optimization for large stream input]),
[
  if test "$enableval" == "yes"; then
    large_stream_input="-DMSC_LARGE_STREAM_INPUT"
    MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS $large_stream_input"
  else
    large_stream_input=
  fi
],
[
  large_stream_input=
])

# Find apxs
AC_MSG_NOTICE(looking for Apache module support via DSO through APXS)
AC_ARG_WITH(apxs,
            [AS_HELP_STRING([[--with-apxs=FILE]],
                            [FILE is the path to apxs; defaults to "apxs".])],
[
  if test "$withval" = "yes"; then
    APXS=apxs
  else
    APXS="$withval"
  fi
])

if test -z "$APXS"; then
  for i in /usr/local/apache22/bin \
           /usr/local/apache2/bin \
           /usr/local/apache/bin \
           /usr/local/sbin \
           /usr/local/bin \
           /usr/sbin \
           /usr/bin;
  do
    if test -f "$i/apxs2"; then
      APXS="$i/apxs2"
      break
    elif test -f "$i/apxs"; then
      APXS="$i/apxs"
      break
    fi
  done
fi

# arbitrarily picking the same version subversion looks for, don't know how
# accurate this really is, but at least it'll force us to have apache2...
HTTPD_WANTED_MMN=20020903

if test -n "$APXS" -a "$APXS" != "no" -a -x "$APXS" ; then
  APXS_INCLUDE="`$APXS -q INCLUDEDIR`"
  if test -r $APXS_INCLUDE/httpd.h; then
    AC_MSG_NOTICE(found apxs at $APXS)
    AC_MSG_NOTICE(checking httpd version)
    AC_EGREP_CPP(VERSION_OK,
    [
#include "$APXS_INCLUDE/ap_mmn.h"
#if AP_MODULE_MAGIC_AT_LEAST($HTTPD_WANTED_MMN,0)
VERSION_OK
#endif],
    [AC_MSG_NOTICE(httpd is recent enough)],
    [
     if test "$report_errors" -eq 1; then
       AC_MSG_ERROR(apache is too old, mmn must be at least $HTTPD_WANTED_MMN)
     else
       AC_MSG_NOTICE(apache is too old, mmn must be at least $HTTPD_WANTED_MMN)
     fi
    ])
  fi
  APXS_INCLUDEDIR="`$APXS -q INCLUDEDIR`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs INCLUDEDIR: $APXS_INCLUDEDIR); fi
  # Make sure the include dir is used
  if test -n "$APXS_INCLUDEDIR"; then
    APXS_INCLUDES="-I${APXS_INCLUDEDIR} `$APXS -q INCLUDES` `$APXS -q EXTRA_INCLUDES`"
  else
    APXS_INCLUDES="`$APXS -q INCLUDES` `$APXS -q EXTRA_INCLUDES`"
  fi
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs INCLUDES: $APXS_INCLUDES); fi
  APXS_CFLAGS=-I`$APXS -q INCLUDEDIR`
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs CFLAGS: $APXS_CFLAGS); fi
  APXS_LDFLAGS=
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs LDFLAGS: $APXS_LDFLAGS); fi
  APXS_LIBDIR="`$APXS -q LIBDIR`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs LIBDIR: $APXS_LIBDIR); fi
  # Make sure the lib dir is used
  if test -n "$APXS_LIBDIR"; then
    APXS_LIBS="-L${APXS_LIBDIR} `$APXS -q LIBS` `$APXS -q EXTRA_LIBS`"
  else
    APXS_LIBS="`$APXS -q LIBS` `$APXS -q EXTRA_LIBS`"
  fi
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs LIBS: $APXS_LIBS); fi
  APXS_LIBTOOL="`$APXS -q LIBTOOL`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs LIBTOOL: $APXS_LIBTOOL); fi
  APXS_CC="`$APXS -q CC`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs CC: $APXS_CC); fi
  APXS_BINDIR="`$APXS -q BINDIR`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs BINDIR: $APXS_BINDIR); fi
  APXS_SBINDIR="`$APXS -q SBINDIR`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs SBINDIR: $APXS_SBINDIR); fi
  APXS_PROGNAME="`$APXS -q PROGNAME`"
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs PROGNAME: $APXS_PROGNAME); fi
  APXS_LIBEXECDIR="`$APXS -q LIBEXECDIR`"
  if test "xx$APXS_LIBEXECDIR" = "xx"; then APXS_LIBEXECDIR="`$APXS -q LIBDIR`/modules"; fi
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs LIBEXECDIR: $APXS_LIBEXECDIR); fi
  APXS_MODULES=$APXS_LIBEXECDIR
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs MODULES: $APXS_MODULES); fi
  if test "$APXS_SBINDIR" = "/"; then
    APXS_HTTPD="$APXS_SBINDIR/$APXS_PROGNAME"
  else
    APXS_HTTPD="$APXS_SBINDIR/$APXS_PROGNAME"
  fi
  if test "$verbose_output" -eq 1; then AC_MSG_NOTICE(apxs HTTPD: $APXS_HTTPD); fi
else
  if test "$report_errors" -eq 1; then
    AC_MSG_ERROR(couldn't find APXS)
  else
    AC_MSG_NOTICE(couldn't find APXS)
  fi
fi

### Build *EXTRA_CFLAGS vars

# Allow overriding EXTRA_CFLAGS
if $ENV_CMD | $GREP "^EXTRA_CFLAGS" > /dev/null 2>&1; then
  if test -z "$debug_mem"; then
    EXTRA_CFLAGS="$EXTRA_CFLAGS $strict_compile"
  fi
else
  if test -n "$debug_mem"; then
    EXTRA_CFLAGS="-O0 -g -Wall"
  else
    EXTRA_CFLAGS="-O2 -g -Wall $strict_compile"
  fi
fi

MODSEC_EXTRA_CFLAGS="$pcre_study $pcre_match_limit $pcre_match_limit_recursion $pcre_jit $request_early $htaccess_config $lua_cache $debug_conf $debug_cache $debug_acmp $debug_mem $perf_meas $modsec_api $cpu_type $unique_id $log_filename $log_server $log_collection_delete_problem $log_dechunk $log_stopwatch $log_handler $log_server_context $collection_global_lock $large_stream_input $collection_memory_database $waf_json_logging $waf_lock"

APXS_WRAPPER=build/apxs-wrapper
APXS_EXTRA_CFLAGS=""
for f in $EXTRA_CFLAGS; do
    APXS_EXTRA_CFLAGS="$APXS_EXTRA_CFLAGS -Wc,$f"
done;
MODSEC_APXS_EXTRA_CFLAGS=""
for f in $MODSEC_EXTRA_CFLAGS; do
    MODSEC_APXS_EXTRA_CFLAGS="$MODSEC_APXS_EXTRA_CFLAGS -Wc,$f"
done;

### Substitute the vars

AC_SUBST(TOPLEVEL_SUBDIRS)
AC_SUBST(EXTRA_CFLAGS)
AC_SUBST(MODSEC_EXTRA_CFLAGS)
AC_SUBST(APXS)
AC_SUBST(APXS_WRAPPER)
AC_SUBST(APXS_INCLUDEDIR)
AC_SUBST(APXS_INCLUDES)
AC_SUBST(APXS_EXTRA_CFLAGS)
AC_SUBST(MODSEC_APXS_EXTRA_CFLAGS)
AC_SUBST(APXS_LDFLAGS)
AC_SUBST(APXS_LIBS)
AC_SUBST(APXS_CFLAGS)
AC_SUBST(APXS_LIBTOOL)
AC_SUBST(APXS_CC)
AC_SUBST(APXS_LIBDIR)
AC_SUBST(APXS_BINDIR)
AC_SUBST(APXS_SBINDIR)
AC_SUBST(APXS_PROGNAME)
AC_SUBST(APXS_LIBEXECDIR)
AC_SUBST(APXS_MODULES)
AC_SUBST(APXS_HTTPD)

CHECK_PCRE()
if test "$build_apache2_module" -ne 0 -o "$build_mlogc" -ne 0; then
CHECK_APR()
CHECK_APU()
fi
CHECK_LIBXML2()
CHECK_LUA()
#if test "$build_mlogc" -ne 0; then
#CHECK_CURL()
#fi

# Check for YAJL libs (for JSON body processor)
CHECK_YAJL()
#AC_SEARCH_LIBS([yajl_alloc], [yajl])
CHECK_SSDEEP()
#AC_SEARCH_LIBS([fuzzy_hash_buf], [fuzzy])

# Temporarily set cflags for apr_crypto check, then restore
# since it's already used correctly to compile modsecurity module.
ORIG_CFLAGS="$CFLAGS $APU_CFLAGS"
ORIG_CPPFLAGS="$CPPFLAGS"
CFLAGS="$CFLAGS $APR_CFLAGS"
CPPFLAGS="$CPPFLAGS $APR_CPPFLAGS"
AC_TRY_COMPILE(
	[#include <apr_crypto.h>],
	[
          #if APU_HAVE_CRYPTO == 0
          #error APR util was not compiled with crypto support.
          #endif
	],
	[ AC_DEFINE([WITH_APU_CRYPTO], [1], [APR util was compiled with crypto support])
	  MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS -DWITH_APU_CRYPTO"
	],
	[ AC_MSG_WARN([APR util was not compiled with crypto support. SecRemoteRule will not support the parameter 'crypto']) ]
)
# Restore env vars so that we don't clutter with duplicates that
# are eventually appended later on
CFLAGS="$ORIG_CFLAGS"
CPPFLAGS="$ORIG_CPPFLAGS"

# Current our unique download backend is curl, furhter we can support more.
if test ! -z "${CURL_VERSION}"; then
  AC_DEFINE([WITH_REMOTE_RULES], [1], [Enables SecRemoteRules support])
  MODSEC_EXTRA_CFLAGS="$MODSEC_EXTRA_CFLAGS -DWITH_REMOTE_RULES"
fi

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([tools/Makefile])
if test "$build_alp2" -ne 0; then
AC_CONFIG_FILES([alp2/Makefile])
fi
if test "$build_apache2_module" -ne 0; then
AC_CONFIG_FILES([apache2/Makefile])
fi
if test "$build_standalone_module" -ne 0; then
AC_CONFIG_FILES([standalone/Makefile])
AC_CONFIG_FILES([nginx/modsecurity/config])
fi
if test "$build_extentions" -ne 0; then
AC_CONFIG_FILES([ext/Makefile])
fi
AC_CONFIG_FILES([build/apxs-wrapper], [chmod +x build/apxs-wrapper])
if test -e "$PERL"; then
    if test "$build_mlogc" -ne 0; then
        AC_CONFIG_FILES([mlogc/mlogc-batch-load.pl], [chmod +x mlogc/mlogc-batch-load.pl])
        AC_CONFIG_FILES([tests/regression/misc/40-secRemoteRules.t])
        AC_CONFIG_FILES([tests/regression/misc/50-ipmatchfromfile-external.t])
        AC_CONFIG_FILES([tests/regression/misc/60-pmfromfile-external.t])
    fi
    AC_CONFIG_FILES([tests/run-unit-tests.pl], [chmod +x tests/run-unit-tests.pl])
    AC_CONFIG_FILES([tests/run-regression-tests.pl], [chmod +x tests/run-regression-tests.pl])
    AC_CONFIG_FILES([tests/gen_rx-pm.pl], [chmod +x tests/gen_rx-pm.pl])
    AC_CONFIG_FILES([tests/csv_rx-pm.pl], [chmod +x tests/csv_rx-pm.pl])
    AC_CONFIG_FILES([tests/regression/server_root/conf/httpd.conf])

    # Perl based tools
    AC_CONFIG_FILES([tools/rules-updater.pl], [chmod +x tools/rules-updater.pl])
fi
if test "$build_mlogc" -ne 0; then
    AC_CONFIG_FILES([mlogc/Makefile])
fi
AC_CONFIG_FILES([tests/Makefile])

AC_OUTPUT
