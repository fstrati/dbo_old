/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// Define the basic types used through dbo namespace

#ifndef DBO_TYPESDEF_H_INCLUDED
#define DBO_TYPESDEF_H_INCLUDED

#include <wchar.h>
#include <iosfwd>
#include <string>

#include "dbo/namespace.h"
#include "dbo/callocators.h"

NAMESPACE_DBO_OPEN

// types

// typedefs for win32 msvc onwards
#if (defined(_MSC_VER) && (_MSC_VER >= 1600))

// bytes
typedef unsigned char                  dbo_byte_t;
typedef bool                           dbo_bool_t;

typedef char                           dbo_char_t;
typedef wchar_t                        dbo_wchar_t;

// Strings ->

// typedef std::string                 dbo_string_t;
// typedef std::basic_string<char>     dbo_string_t;
typedef std::basic_string<char, std::char_traits<char>, DBO_STD_ALLOCATOR<char> > dbo_string_t;

// typedef std::wstring                dbo_wstring_t;
// typedef std::basic_string<wchar_t>  dbo_wstring_t;
typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, DBO_STD_ALLOCATOR<wchar_t> > dbo_wstring_t;

// Strings <-

typedef __int8                         dbo_int8_t;
typedef unsigned __int8                dbo_uint8_t;
typedef __int16                        dbo_int16_t;
typedef unsigned __int16               dbo_uint16_t;
typedef __int32                        dbo_int32_t;
typedef unsigned __int32               dbo_uint32_t;
typedef __int64                        dbo_int64_t;
typedef unsigned __int64               dbo_uint64_t;

#if 0
// The followings do not work on 32bits old compilers (they map to 64bits integers)
typedef long long                      dbo_int128_t;
typedef unsigned long long             dbo_uint128_t;
#endif

typedef float                          dbo_single_t;
typedef double                         dbo_double_t;
typedef long double                    dbo_quad_t;

#else
#error check your compiler and platform in file typesdef.h ...
#endif

// Definitions dependent on the platform

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma warning( disable : 4996 ) // non-std enum's
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1600)

#define FORCE_INLINE __forceinline
#define DBO_NOTHROW  throw()

#define NOMINMAX

#if !defined(snprintf)
#undef  snprintf
#define snprintf                _snprintf
#endif

#if !defined(snwprintf)
#undef  snwprintf
#define snwprintf               _snwprintf
#endif

#else // !defined(_MSC_VER)

#define FORCE_INLINE inline
#define DBO_NOTHROW  throw()

#endif

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_TYPESDEF_H_INCLUDED) */





