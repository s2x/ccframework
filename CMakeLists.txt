cmake_minimum_required(VERSION 2.8)
project(ccframework)

# The version number.
set (ccframework_VERSION_MAJOR 0)
set (ccframework_VERSION_MINOR 2)
set (ccframework_VERSION_PATCH 2)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(ac_cv_cxx_hash_map "<tr1/unordered_map>")
set(ac_cv_cxx_hash_set "<tr1/unordered_set>")
set(ac_cv_cxx_hash_set_class "std::tr1::unordered_set")
set(ac_cv_cxx_hash_map_class "std::tr1::unordered_map")
set(ac_cv_have_stdint_h "1")
set(ac_cv_have_inttypes_h "1")
set(ac_have_attribute_weak "1")
set(ac_google_attribute "1")
set(ac_cv_uint64 "u_int64_t")
set(ac_google_namespace "::ctemplate")
set(ac_google_start_namespace "namespace ctemplate {")
set(ac_cv_cxx_hash_map_class "std::tr1::unordered_map")
set(PC_FILE ${CMAKE_BINARY_DIR}/src/ccframework.pc)

CONFIGURE_FILE(src/include/ccframework/ctemplate/config.h.in    src/include/ccframework/ctemplate/config.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template.h.in     src/include/ccframework/ctemplate/template.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/find_ptr.h.in  src/include/ccframework/ctemplate/find_ptr.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/per_expand_data.h.in     src/include/ccframework/ctemplate/per_expand_data.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/str_ref.h.in    src/include/ccframework/ctemplate/str_ref.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_annotator.h.in     src/include/ccframework/ctemplate/template_annotator.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_cache.h.in     src/include/ccframework/ctemplate/template_cache.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_dictionary.h.in     src/include/ccframework/ctemplate/template_dictionary.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_dictionary_interface.h.in     src/include/ccframework/ctemplate/template_dictionary_interface.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_emitter.h.in    src/include/ccframework/ctemplate/template_emitter.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_enums.h.in    src/include/ccframework/ctemplate/template_enums.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_modifiers.h.in    src/include/ccframework/ctemplate/template_modifiers.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_namelist.h.in    src/include/ccframework/ctemplate/template_namelist.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_pathops.h.in    src/include/ccframework/ctemplate/template_pathops.h)
CONFIGURE_FILE(src/include/ccframework/ctemplate/template_string.h.in    src/include/ccframework/ctemplate/template_string.h)
CONFIGURE_FILE(src/ccframework.pc.in  ${PC_FILE} @ONLY)

set(HEADER_FILES
    src/include/ccframework/ctemplate/find_ptr.h
    src/include/ccframework/ctemplate/per_expand_data.h
    src/include/ccframework/ctemplate/str_ref.h
    src/include/ccframework/ctemplate/template.h
    src/include/ccframework/ctemplate/template_annotator.h
    src/include/ccframework/ctemplate/template_cache.h
    src/include/ccframework/ctemplate/template_dictionary.h
    src/include/ccframework/ctemplate/template_dictionary_interface.h
    src/include/ccframework/ctemplate/template_emitter.h
    src/include/ccframework/ctemplate/template_enums.h
    src/include/ccframework/ctemplate/template_modifiers.h
    src/include/ccframework/ctemplate/template_namelist.h
    src/include/ccframework/ctemplate/template_pathops.h
    src/include/ccframework/ctemplate/template_string.h
    src/include/ccframework/ccAcl.h
    src/include/ccframework/ccApp.h
    src/include/ccframework/ccBaseForm.h
    src/include/ccframework/ccBaseFormElement.h
    src/include/ccframework/ccBaseHelper.h
    src/include/ccframework/ccClassDeclarations.h
    src/include/ccframework/ccCommon.h
    src/include/ccframework/ccComponentHelper.h
    src/include/ccframework/ccConfig.h
    src/include/ccframework/ccConfigLoader.h
    src/include/ccframework/ccController.h
    src/include/ccframework/ccCookie.h
    src/include/ccframework/ccEvent.h
    src/include/ccframework/ccEventDispatcher.h
    src/include/ccframework/ccException.h
    src/include/ccframework/ccFormElementFormStart.h
    src/include/ccframework/ccFormElementLabel.h
    src/include/ccframework/ccFormElementText.h
    src/include/ccframework/ccFramework.h
    src/include/ccframework/ccMemorySessionProvider.h
    src/include/ccframework/ccMultipartParser.h
    src/include/ccframework/ccPregRoute.h
    src/include/ccframework/ccQueryParser.h
    src/include/ccframework/ccRequest.h
    src/include/ccframework/ccResource.h
    src/include/ccframework/ccResponse.h
    src/include/ccframework/ccRole.h
    src/include/ccframework/ccRoute.h
    src/include/ccframework/ccRouter.h
    src/include/ccframework/ccSession.h
    src/include/ccframework/ccSessionProvider.h
    src/include/ccframework/ccStaticRoute.h
    src/include/ccframework/ccTemplateResponse.h
    src/include/ccframework/ccYamlSessionProvider.h
)

set(SOURCE_FILES
    src/ccframework/acl/ccAcl.cc
    src/ccframework/acl/ccResource.cc
    src/ccframework/acl/ccRole.cc
    src/ccframework/config/ccConfig.cc
    src/ccframework/config/ccConfigLoader.cc
    src/ccframework/events/ccEvent.cc
    src/ccframework/events/ccEventDispatcher.cc
    src/ccframework/form/element/ccBaseFormElement.cc
    src/ccframework/form/ccBaseForm.cc
    src/ccframework/helpers/ccBaseHelper.cc
    src/ccframework/helpers/ccComponentHelper.cc
    src/ccframework/parsers/ccMultipartParser.cc
    src/ccframework/parsers/ccQueryParser.cc
    src/ccframework/response/ccResponse.cc
    src/ccframework/response/ccTemplateResponse.cc
    src/ccframework/router/ccPregRoute.cc
    src/ccframework/router/ccRoute.cc
    src/ccframework/router/ccRouter.cc
    src/ccframework/router/ccStaticRoute.cc
    src/ccframework/session/ccMemorySessionProvider.cc
    src/ccframework/session/ccSession.cc
    src/ccframework/session/ccSessionProvider.cc
    src/ccframework/session/ccYamlSessionProvider.cc
    src/ccframework/ccApp.cc
    src/ccframework/ccCommon.cc
    src/ccframework/ccController.cc
    src/ccframework/ccCookie.cc
    src/ccframework/ccException.cc
    src/ccframework/ccRequest.cc
    src/vendor/ctemplate/base/arena-inl.h
    src/vendor/ctemplate/base/arena.cc
    src/vendor/ctemplate/base/arena.h
    src/vendor/ctemplate/base/fileutil.h
    src/vendor/ctemplate/base/macros.h
    src/vendor/ctemplate/base/manual_constructor.h
    src/vendor/ctemplate/base/mutex.h
    src/vendor/ctemplate/base/small_map.h
    src/vendor/ctemplate/base/thread_annotations.h
    src/vendor/ctemplate/base/util.h
    src/vendor/ctemplate/htmlparser/htmlparser.cc
    src/vendor/ctemplate/htmlparser/htmlparser.h
    src/vendor/ctemplate/htmlparser/htmlparser_cpp.h
    src/vendor/ctemplate/htmlparser/htmlparser_fsm.h
    src/vendor/ctemplate/htmlparser/jsparser.cc
    src/vendor/ctemplate/htmlparser/jsparser.h
    src/vendor/ctemplate/htmlparser/jsparser_fsm.h
    src/vendor/ctemplate/htmlparser/statemachine.cc
    src/vendor/ctemplate/htmlparser/statemachine.h
    src/vendor/ctemplate/diff_tpl_auto_escape.cc
    src/vendor/ctemplate/indented_writer.h
    src/vendor/ctemplate/make_tpl_varnames_h.cc
    src/vendor/ctemplate/per_expand_data.cc
    src/vendor/ctemplate/template.cc
    src/vendor/ctemplate/template_annotator.cc
    src/vendor/ctemplate/template_cache.cc
    src/vendor/ctemplate/template_dictionary.cc
    src/vendor/ctemplate/template_modifiers.cc
    src/vendor/ctemplate/template_modifiers_internal.h
    src/vendor/ctemplate/template_namelist.cc
    src/vendor/ctemplate/template_pathops.cc
    src/vendor/ctemplate/template_string.cc
    src/vendor/md5/md5.cc
    src/vendor/md5/md5.h)

set(FROM_TEST_SOURCE_FILES
    src/test/form_test.cc)

set(ROUTER_TEST_SOURCE_FILES
    src/test/router_test.cc)

set(REQUEST_TEST_SOURCE_FILES
    src/test/request_test.cc)


find_package(Fcgi)
find_package(Threads REQUIRED)
find_package(Boost)
find_package(PCRE)
find_package(YamlCpp)

include_directories(src/include/ccframework)
include_directories(src/include/ccframework/ctemplate)
include_directories(src/vendor/ctemplate)

include_directories(${PCRE_INCLUDE_DIRS})
include_directories(${YAMLCPP_INCLUDE_DIRS})

add_library(ccframework ${SOURCE_FILES} src/ccframework/server/ccPreforkServer.cc src/include/ccframework/ccHttpCodes.h)
add_executable(router-test ${ROUTER_TEST_SOURCE_FILES})
add_executable(form-test ${FROM_TEST_SOURCE_FILES})
add_executable(request-test ${REQUEST_TEST_SOURCE_FILES})

target_link_libraries(router-test ccframework
    ${FCGI_LIBRARY}
    ${FCGICC_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${YAMLCPP_LIBRARY}
    ${PCRE_LIBRARY})
target_link_libraries(form-test ccframework
    ${FCGI_LIBRARY}
    ${FCGICC_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${YAMLCPP_LIBRARY}
    ${PCRE_LIBRARY})

target_link_libraries(request-test ccframework
    ${FCGI_LIBRARY}
    ${FCGICC_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${YAMLCPP_LIBRARY}
    ${PCRE_LIBRARY})


install(TARGETS ccframework DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/include DESTINATION ${CMAKE_INSTALL_PREFIX} FILES_MATCHING PATTERN "*")
install(FILES ${PC_FILE} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${ccframework_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${ccframework_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${ccframework_VERSION_PATCH}")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Piotr Hałas <halaspiotr@gmail.com>") #required
set(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libyaml-cpp0.5, libpcre3, libboost-dev, libfcgi")
include (CPack)

