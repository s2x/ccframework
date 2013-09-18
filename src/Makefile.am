## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libccframework.la


libccframework_la_SOURCES =  \
	ccframework/ccApp.cc \
	ccframework/ccCommon.cc \
	ccframework/ccController.cc \
	ccframework/ccCookie.cc \
	ccframework/ccQueryParser.cc \
	ccframework/ccRequest.cc \
	ccframework/ccSession.cc \
	ccframework/config/ccConfig.cc \
	ccframework/config/ccConfigLoader.cc \
	ccframework/events/ccEvent.cc \
	ccframework/events/ccEventDispatcher.cc \
	ccframework/response/ccResponse.cc \
	ccframework/response/ccTemplateResponse.cc \
	ccframework/router/ccRoute.cc \
	ccframework/router/ccRouteMatcher.cc \
	ccframework/router/ccRouter.cc

libccframework_la_CXXFLAGS = -Iinclude 

libccframework_la_LDFLAGS = 

libccframework_la_LIBADD = 

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libccframework-0.1.pc

EXTRA_DIST = \
	libccframework.pc

SUBDIRS = \
	include \
	vendor
