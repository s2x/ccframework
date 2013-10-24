## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(YAML_CPP_CFLAGS) \
	$(LIBPCRE_CFLAGS) \
	-std=c++11

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libccframework.la

bin_PROGRAMS = routertest

libccframework_la_SOURCES =  \
	ccframework/ccApp.cc \
	ccframework/ccCommon.cc \
	ccframework/ccController.cc \
	ccframework/ccCookie.cc \
	ccframework/parsers/ccQueryParser.cc \
	ccframework/parsers/ccMultipartParser.cc \
	ccframework/ccRequest.cc \
	ccframework/ccSession.cc \
	ccframework/ccException.cc \
	ccframework/config/ccConfig.cc \
	ccframework/config/ccConfigLoader.cc \
	ccframework/events/ccEvent.cc \
	ccframework/events/ccEventDispatcher.cc \
	ccframework/response/ccResponse.cc \
	ccframework/response/ccTemplateResponse.cc \
	ccframework/router/ccRoute.cc \
	ccframework/router/ccRouter.cc \
	ccframework/acl/ccRole.cc \
	ccframework/acl/ccAcl.cc \
	ccframework/acl/ccResource.cc \
	vendor/md5/md5.cc \
	vendor/md5/md5.h

libccframework_la_CXXFLAGS = -Iinclude 

libccframework_la_LDFLAGS = 

libccframework_la_LIBADD =  \
	$(YAML_CPP_LIBS) \
	$(LIBPCRE_LIBS)

routertest_SOURCES = test/router-test.cc
routertest_LDADD = libccframework.la \
	-lctemplate \
	-lfcgi \
	-lfcgi++

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = ccframework.pc

EXTRA_DIST = \
	ccframework.pc.in\
	ccframework.pc

SUBDIRS = \
	include \
	vendor
