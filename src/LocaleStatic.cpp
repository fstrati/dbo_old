/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/LocaleStatic.h"

// TODO: Boost

NAMESPACE_DBO_OPEN

using namespace std;

/*static*/ std::locale GetLocaleDefault() DBO_NOTHROW
{
   // Locale names are not standardized. For example, under MSVC you need to provide the name en-US or English_USA.1252, 
   // when on POSIX platforms it would be en_US.UTF-8 or en_US.ISO-8859-1 
   std::locale ldefault;
   try
   {
      ldefault = std::locale::classic();
   }
   catch (...)
   {
   }
   return ldefault;
}

/*static*/ void SetLocaleGlobalToDefault() DBO_NOTHROW
{
   try
   {
      std::locale ldefault = GetLocaleDefault();
      std::locale::global(ldefault);
   }
   catch (...)
   {
   }
}

/*static*/ void SetLocaleGlobalTo(const dbo_string_t&  localeStrId) DBO_NOTHROW
{
   try
   {
      std::locale::global(std::locale(localeStrId));
   }
   catch (...)
   {
   }
}

NAMESPACE_DBO_CLOSE

