/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include <cstdio>
#include <cstdlib>

#include "dbo/namespace.h"
#include "dbo/dbogendefines.h"

#include "dbo/StringTruncateStatic.h"

NAMESPACE_DBO_OPEN

using namespace std;

dbo_bool_t TruncateStrToStr(dbo_string_t& oStr, const dbo_string_t& iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW
{
   dbo_bool_t retValue = false;
   try
   {
      if ( iStr.size() <= oMaxSize )
      {
         oStr.reserve((size_t) (iStr.size() + 1));
         oStr = iStr;
      }
      else // iStr.size() > oMaxSize
      {
         oStr.reserve((size_t) oMaxSize);
         size_t k=0;
         for (k=0; k < (oStr.capacity()-1); ++k)
         {
            oStr[k] = iStr[k];
         }
         // let us add a terminator anyway
         oStr[++k] = dbo_string_t::traits_type::to_char_type(DBO_INT_ZERO);
         retValue = true;
      }
   }
   catch (...)
   {
      retValue = true;
   }
   return retValue;
}

dbo_bool_t TruncateStrToStr(dbo_string_t& oStr, const dbo_char_t* const iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW
{
   dbo_bool_t retValue = false;
   size_t iStrLen = DBO_INT_ZERO;
   try
   {
      iStrLen = strlen(iStr);
      if ( iStrLen <= oMaxSize )
      {
         oStr.reserve((size_t) (iStrLen + 1));
         oStr = iStr;
      }
      else // iStrLen > oMaxSize
      {
         oStr.reserve((size_t) oMaxSize);
         size_t k=0;
         for (k=0; k < (oStr.capacity()-1); ++k)
         {
            oStr[k] = *(iStr+k);
         }
         // let us add a terminator anyway
         oStr[++k] = dbo_string_t::traits_type::to_char_type(DBO_INT_ZERO);
         retValue = true;
      }
   }
   catch (...)
   {
      retValue = true;
   }
   return retValue;
}

dbo_bool_t TruncateStrToStr(dbo_wstring_t& oStr, const dbo_wstring_t& iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW
{
   dbo_bool_t retValue = false;
   try
   {
      if ( iStr.size() <= oMaxSize )
      {
         oStr.reserve((size_t) (iStr.size() + 1));
         oStr = iStr;
      }
      else // iStr.size() > oMaxSize
      {
         oStr.reserve((size_t) oMaxSize);
         size_t k=0;
         for (k=0; k < (oStr.capacity()-1); ++k)
         {
            oStr[k] = iStr[k];
         }
         // let us add a terminator anyway
         oStr[++k] = dbo_wstring_t::traits_type::to_char_type(DBO_INT_ZERO);
         retValue = true;
      }
   }
   catch (...)
   {
      retValue = true;
   }
   return retValue;
}

dbo_bool_t TruncateStrToStr(dbo_wstring_t& oStr, const dbo_wchar_t* const iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW
{
   dbo_bool_t retValue = false;
   size_t iStrLen = DBO_INT_ZERO;
   try
   {
      iStrLen = wcslen(iStr);
      if ( iStrLen <= oMaxSize )
      {
         oStr.reserve((size_t) (iStrLen +1));
         oStr = iStr;
      }
      else // iStrLen > oMaxSize
      {
         oStr.reserve((size_t) oMaxSize);
         size_t k=0;
         for (k=0; k < (oStr.capacity()-1); ++k)
         {
            oStr[k] = *(iStr+k);
         }
         // let us add a terminator anyway
         oStr[++k] = dbo_wstring_t::traits_type::to_char_type(DBO_INT_ZERO);
         retValue = true;
      }
   }
   catch (...)
   {
      retValue = true;
   }
   return retValue;
}

NAMESPACE_DBO_CLOSE

