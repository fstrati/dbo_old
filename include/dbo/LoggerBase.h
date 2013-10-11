/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_LOGGERBASE_H_INCLUDED
#define DBO_LOGGERBASE_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/macros.h"
#include "dbo/dbogendefines.h"
#include "dbo/options.h"

#include "dbo/LoggerConstants.h"

NAMESPACE_DBO_OPEN

// The Abstract Base Class adapter for Loggers
class CLoggerBase
{
   DBO_PRI_CLASS_CTOR_H(CLoggerBase);

private:
   // Loggers are NOT copy-constructible and assignable
   CLoggerBase(const CLoggerBase& iOther) DBO_NOTHROW { };
   CLoggerBase& operator=(const CLoggerBase& iOther) DBO_NOTHROW { };

public:
   // explicit Construction/Destruction
   explicit CLoggerBase(const dbo_char_t* const iName) DBO_NOTHROW;
   explicit CLoggerBase(const dbo_string_t& iName) DBO_NOTHROW;
   virtual ~CLoggerBase() DBO_NOTHROW { };

public:
   // Interface
   virtual DBO_TRACE_RESULT TraceAsCString (dbo_uint32_t iErrLevel, const dbo_char_t* const iCStr, const size_t iSize) const DBO_NOTHROW = 0;
   virtual DBO_TRACE_RESULT TraceAsString  (dbo_uint32_t iErrLevel, const dbo_string_t& iStr) const DBO_NOTHROW = 0;
   virtual DBO_TRACE_RESULT TraceAsWCString(dbo_uint32_t iErrLevel, const dbo_wchar_t* const iWCStr, const size_t iSize) const DBO_NOTHROW = 0;
   virtual DBO_TRACE_RESULT TraceAsWString (dbo_uint32_t iErrLevel, const dbo_wstring_t& iWStr) const DBO_NOTHROW = 0;

// Static properties
public:
   FORCE_INLINE const dbo_string_t& getLoggerName(void) const DBO_NOTHROW 
   {
      return _logger_name;
   };
private:
   dbo_string_t _logger_name; /* Logger name */
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_LOGGERBASE_H_INCLUDED) */

