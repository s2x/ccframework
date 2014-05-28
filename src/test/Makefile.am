## Process this file with automake to produce Makefile.in

bin_PROGRAMS=router_test form_test

router_test_SOURCES=router_test.cc
form_test_SOURCES=form_test.cc

AM_CPPFLAGS = -I../include/ccframework \
	-std=c++11

router_test_LDADD = ../libccframework.la \
	$(YAML_CPP_LIBS) \
	$(LIBPCRE_LIBS) \
	-lfcgi \
	-lfcgi++

form_test_LDADD = ../libccframework.la \
	$(YAML_CPP_LIBS) \
	$(LIBPCRE_LIBS) \
	-lfcgi \
	-lfcgi++