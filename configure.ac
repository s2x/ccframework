dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(libccframework, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11 subdir-objects])

AM_SILENT_RULES([yes])
AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CPP
AC_PROG_CXX



dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=libccframework
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT
AC_CHECK_TYPES([uint32_t])
AC_CHECK_TYPES([u_int32_t])
AC_CHECK_TYPES([__int32])
AC_CHECK_TYPES([uint64_t])
AC_CHECK_TYPES([u_int64_t])
AC_CHECK_TYPES([__int64])

LT_INIT

# A lot of the code in this directory depends on pthreads
ACX_PTHREAD

# We'd like to use read/write locks in several places in the code.
# See if our pthreads support extends to that.  Note: for linux, it
# does as long as you define _XOPEN_SOURCE appropriately.
AC_RWLOCK

# For mingw/cygwin, figure out if the mutex code needs to use
# 'volatile' in some places.  They differ from MSVC, and the API is
# unclear, so it's best just to check.
AC_INTERLOCKED_EXCHANGE_NONVOLATILE

# Find out what namespace 'normal' STL code lives in, and also what namespace
# the user wants our classes to be defined in
AC_CXX_STL_NAMESPACE
AC_DEFINE_GOOGLE_NAMESPACE(ctemplate)
# Figures out where hash_map and hash_set live, and what namespace they use
AC_CXX_STL_HASH

# This will (should) never change, but we put it here so if we do need
# to change it, to avoid naming conflicts or something, it's easy to
# do in one place.
ac_htmlparser_namespace=google_ctemplate_streamhtmlparser
AC_SUBST(ac_htmlparser_namespace)
AC_DEFINE_UNQUOTED(HTMLPARSER_NAMESPACE, $ac_htmlparser_namespace,
                   [The namespace to put the htmlparser code.])

# Defines PRIuS
AC_COMPILER_CHARACTERISTICS

AC_SUBST(ac_google_namespace)
AC_SUBST(ac_google_start_namespace)
AC_SUBST(ac_google_end_namespace)
AC_SUBST(ac_cv_cxx_hash_map)
AC_SUBST(ac_cv_cxx_hash_set)
AC_SUBST(ac_cv_cxx_hash_map_class)
AC_SUBST(ac_cv_cxx_hash_set_class)
if test "$ac_cv___attribute__" = "yes"; then
   AC_SUBST(ac_google_attribute, 1)
else
   AC_SUBST(ac_google_attribute, 0)
fi
if test "$ac_cv_type_u_int64_t" = "yes"; then
   AC_SUBST(ac_cv_uint64, u_int64_t)
elif test "$ac_cv_type_uint64_t" = "yes"; then
   AC_SUBST(ac_cv_uint64, uint64_t)
elif test "$ac_cv_type___int64" = "yes"; then
   AC_SUBST(ac_cv_uint64, unsigned __int64)
else
   AC_SUBST(ac_cv_uint64, unsigned long long)   # best we can do
fi
# These are used by template_string.h.in
if test "$ac_cv_header_stdint_h" = "yes"; then
   AC_SUBST(ac_cv_have_stdint_h, 1)
else
   AC_SUBST(ac_cv_have_stdint_h, 0)
fi
if test "$ac_cv_header_inttypes_h" = "yes"; then
   AC_SUBST(ac_cv_have_inttypes_h, 1)
else
   AC_SUBST(ac_cv_have_inttypes_h, 0)
fi


PKG_CHECK_MODULES(LIBPCRE,libpcre)

PKG_CHECK_MODULES(YAML_CPP,yaml-cpp)

AC_OUTPUT([
Makefile
src/ccframework.pc
src/Makefile
po/Makefile.in
src/include/Makefile
src/vendor/Makefile
src/include/ccframework/Makefile
src/vendor/md5/Makefile
src/vendor/ctemplate/Makefile
src/vendor/ctemplate/base/Makefile
src/vendor/ctemplate/htmlparser/Makefile
src/test/Makefile
])
