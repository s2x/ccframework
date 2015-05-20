/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* always defined to indicate that i18n is enabled */
#define ENABLE_NLS 1

/* GETTEXT package name */
#define GETTEXT_PACKAGE "libccframework"

/* Namespace for Google classes */
#define GOOGLE_NAMESPACE ::ctemplate

/* the location of <unordered_map> or <hash_map> */
#define HASH_MAP_H <tr1/unordered_map>

/* the namespace of hash_map/hash_set */
#define HASH_NAMESPACE std::tr1

/* the location of <unordered_set> or <hash_set> */
#define HASH_SET_H <tr1/unordered_set>

/* Define to 1 if you have the `bind_textdomain_codeset' function. */
#define HAVE_BIND_TEXTDOMAIN_CODESET 1

/* Define to 1 if you have the <boost/shared_ptr.hpp> header file. */
#define HAVE_BOOST_SHARED_PTR_HPP 1

/* Define to 1 if you have the `dcgettext' function. */
#define HAVE_DCGETTEXT 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <fcgiapp.h> header file. */
#define HAVE_FCGIAPP_H 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* define if the compiler has hash_map */
#define HAVE_HASH_MAP 1

/* define if the compiler has hash_set */
#define HAVE_HASH_SET 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if your <locale.h> file defines LC_MESSAGES. */
#define HAVE_LC_MESSAGES 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* define if the compiler implements namespaces */
#define HAVE_NAMESPACES 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* define if the compiler implements pthread_rwlock_* */
#define HAVE_RWLOCK 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `uint32_t'. */
#define HAVE_UINT32_T 1

/* Define to 1 if the system has the type `uint64_t'. */
#define HAVE_UINT64_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* define if the compiler supports unordered_{map,set} */
#define HAVE_UNORDERED_MAP 1

/* Define to 1 if the system has the type `u_int32_t'. */
#define HAVE_U_INT32_T 1

/* Define to 1 if the system has the type `u_int64_t'. */
#define HAVE_U_INT64_T 1

/* Define to 1 if the system has the type `__int32'. */
/* #undef HAVE___INT32 */

/* Define to 1 if the system has the type `__int64'. */
/* #undef HAVE___INT64 */

/* The namespace to put the htmlparser code. */
#define HTMLPARSER_NAMESPACE google_ctemplate_streamhtmlparser

/* define if first argument to InterlockedExchange is just LONG */
#define INTERLOCKED_EXCHANGE_NONVOLATILE 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "libccframework"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "libccframework"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libccframework 0.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libccframework"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.1"

/* printf format code for printing a size_t and ssize_t */
#define PRIdS "ld"

/* printf format code for printing a size_t and ssize_t */
#define PRIuS "lu"

/* printf format code for printing a size_t and ssize_t */
#define PRIxS "lx"

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* the namespace where STL code like vector<> is defined */
#define STL_NAMESPACE std

/* Version number of package */
#define VERSION "0.1"

/* Stops putting the code inside the Google namespace */
#define _END_GOOGLE_NAMESPACE_ }

/* Puts following code inside the Google namespace */
#define _START_GOOGLE_NAMESPACE_ namespace ctemplate {
