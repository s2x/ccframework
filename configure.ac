dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(libccframework, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC


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


LT_INIT





PKG_CHECK_MODULES(LIBPCRE,libpcre)

PKG_CHECK_MODULES(YAML_CPP,yaml-cpp)

AC_OUTPUT([
Makefile
src/libccframework.pc
src/Makefile
po/Makefile.in
src/include/Makefile
src/vendor/Makefile
src/include/ccframework/Makefile
src/vendor/md5/Makefile])
