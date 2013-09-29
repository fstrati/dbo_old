// Define the basic types used through dbo namespace

#ifndef DBO_TYPESDEF_H_INCLUDED
#define DBO_TYPESDEF_H_INCLUDED

#include "dbo/namespace.h"

#include <wchar.h>
#include <string>

#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#pragma warning( disable : 4996 ) // non-std enum's
#endif

NAMESPACE_DBO_OPEN

// types

// typedefs for win32 msvc from vs2005 onwards
#if (defined(_MSC_VER) && (_MSC_VER >= 1400))

typedef unsigned char                  dbo_byte_t;

typedef char                           dbo_char_t;
// typedef std::string                    dbo_string_t;
typedef std::basic_string<char>	      dbo_string_t;

typedef wchar_t                        dbo_wchar_t;
// typedef std::wstring                   dbo_wstring_t;
typedef std::basic_string<wchar_t>     dbo_wstring_t;

typedef __int8                         dbo_int8_t;
typedef unsigned __int8                dbo_uint8_t;
typedef __int16                        dbo_int16_t;
typedef unsigned __int16               dbo_uint16_t;
typedef __int32                        dbo_int32_t;
typedef unsigned __int32               dbo_uint32_t;
typedef __int64                        dbo_int64_t;
typedef unsigned __int64               dbo_uint64_t;

typedef float                          dbo_single_t;
typedef double                         dbo_double_t;
typedef long double                    dbo_quad_t;

#else
#error check your compiler and platform in file typesdef.h ...
#endif

// Definitions dependent on the platform
#if defined(_MSC_VER) && (_MSC_VER >= 1400)

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

#endif /* DBO_TYPESDEF_H_INCLUDED */





