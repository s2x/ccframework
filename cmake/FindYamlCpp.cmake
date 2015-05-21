# Locate yaml-cpp
#
# This module defines
#  YAMLCPP_FOUND, if false, do not try to link to yaml-cpp
#  YAMLCPP_LIBRARY, where to find yaml-cpp
#  YAMLCPP_INCLUDE_DIR, where to find yaml.h
#
# By default, the dynamic libraries of yaml-cpp will be found. To find the static ones instead,
# you must set the YAMLCPP_STATIC_LIBRARY variable to TRUE before calling find_package(YamlCpp ...).
#
# If yaml-cpp is not installed in a standard path, you can use the YAMLCPP_DIR CMake variable
# to tell CMake where yaml-cpp is.

# attempt to find static library first if this is set
if(YAMLCPP_STATIC_LIBRARY)
    set(YAMLCPP_STATIC libyaml-cpp.a)
endif()

# find the yaml-cpp include directory
FIND_PATH(YAMLCPP_INCLUDE_DIR
  yaml-cpp/yaml.h
  PATHS
  /usr/include
  /usr/local/include
  "$ENV{LIB_DIR}/include"
  $ENV{INCLUDE}
  )
# find the yaml-cpp library
FIND_LIBRARY(YAMLCPP_LIBRARY NAMES yaml-cpp libyaml-cpp PATHS
  /usr/local/lib
  /usr/lib
  "$ENV{LIB_DIR}/lib"
  "$ENV{LIB}"
  )

# handle the QUIETLY and REQUIRED arguments and set YAMLCPP_FOUND to TRUE if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(YAMLCPP DEFAULT_MSG YAMLCPP_INCLUDE_DIR YAMLCPP_LIBRARY)

#mark_as_advanced(YAMLCPP_INCLUDE_DIR YAMLCPP_LIBRARY)
