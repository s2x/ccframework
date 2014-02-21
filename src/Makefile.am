## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(YAML_CPP_CFLAGS) \
	$(LIBPCRE_CFLAGS)
	
AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libccframework.la

## bin_PROGRAMS = routertest


libccframework_la_SOURCES =  \
    vendor/ctemplate/base/arena-inl.h \
    vendor/ctemplate/base/arena.cc \
    vendor/ctemplate/base/arena.h \
    vendor/ctemplate/base/fileutil.h \
    vendor/ctemplate/base/macros.h \
    vendor/ctemplate/base/manual_constructor.h \
    vendor/ctemplate/base/mutex.h \
    vendor/ctemplate/base/small_map.h \
    vendor/ctemplate/base/thread_annotations.h \
    vendor/ctemplate/base/util.h \
    vendor/ctemplate/indented_writer.h \
    vendor/ctemplate/per_expand_data.cc \
    vendor/ctemplate/template.cc \
    vendor/ctemplate/template_annotator.cc \
    vendor/ctemplate/template_cache.cc \
    vendor/ctemplate/template_dictionary.cc \
    vendor/ctemplate/template_modifiers.cc \
    vendor/ctemplate/template_modifiers_internal.h \
    vendor/ctemplate/template_namelist.cc \
    vendor/ctemplate/template_pathops.cc \
    vendor/ctemplate/template_string.cc \
    vendor/ctemplate/htmlparser/htmlparser.cc \
    vendor/ctemplate/htmlparser/htmlparser.h \
    vendor/ctemplate/htmlparser/htmlparser_cpp.h \
    vendor/ctemplate/htmlparser/jsparser.cc \
    vendor/ctemplate/htmlparser/jsparser.h \
    vendor/ctemplate/htmlparser/statemachine.cc \
    vendor/ctemplate/htmlparser/statemachine.h\
	vendor/md5/md5.cc \
	vendor/md5/md5.h \
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
	ccframework/helpers/ccBaseHelper.cc

libccframework_la_CXXFLAGS = -Wall -Wwrite-strings -Woverloaded-virtual -Wno-sign-compare -Iinclude -Ivendor/ctemplate -Iinclude/ccframework -std=c++0x
libccframework_la_LDFLAGS = 
libccframework_la_LIBADD =  \
	$(YAML_CPP_LIBS) \
	$(LIBPCRE_LIBS)


## routertest_SOURCES = test/router-test.cc
## routertest_LDADD = libccframework.la \
## 	-lctemplate \
##	-lfcgi \
##	-lfcgi++

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = ccframework.pc

EXTRA_DIST = \
	ccframework.pc.in\
	ccframework.pc

SUBDIRS = vendor \
	include \
	.
