// Define c-string comparison objects to make STL happy in maps, etc...

#ifndef DBO_LTSTRCMP_H_INCLUDED
#define DBO_LTSTRCMP_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

#include <cstdlib>

NAMESPACE_DBO_OPEN

// custom comparison operators for C strings (used in maps)
#if defined(ltstrcmp)
	#undef ltstrcmp
	struct ltstrcmp
	{
		bool operator()( const char* s1, const char* s2 ) const
		{
         return ( std::strcmp( (const char*) s1, (const char*) s2 ) < 0 );
		}
	};
#else // !defined(ltstrcmp)
	struct ltstrcmp
	{
		bool operator()( const char* s1, const char* s2 ) const
		{
			return ( std::strcmp( (const char*) s1, (const char*) s2 ) < 0 );
		}
	};
#endif

#if defined(ltwstrcmp)
	#undef ltwstrcmp
   struct ltwstrcmp
   {
      bool operator()( const wchar_t* s1, const wchar_t* s2 ) const
      {
         return ( std::wcscmp( (const wchar_t*) s1, (const wchar_t*) s2 ) < 0 );
      }
   };
#else // !defined(ltwstrcmp)
   struct ltwstrcmp
   {
      bool operator()( const wchar_t* s1, const wchar_t* s2 ) const
      {
         return ( std::wcscmp( (const wchar_t*) s1, (const wchar_t*) s2 ) < 0 );
      }
   };
#endif

NAMESPACE_DBO_CLOSE

#endif /* not defined DBO_LTSTRCMP_H_INCLUDED */

