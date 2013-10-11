/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// The Null Logger Class

#ifndef DBO_LOGGERNULL_H_INCLUDED
#define DBO_LOGGERNULL_H_INCLUDED

#include "dbo/LoggerBase.h"

NAMESPACE_DBO_OPEN

class CLoggerNull : public CLoggerBase
{
   DBO_PRI_CLASS_CTOR_H(CLoggerNull);

private:
   // Loggers are NOT copy-constructible and assignable
   CLoggerNull(const CLoggerNull& iOther) DBO_NOTHROW { };
   CLoggerNull& operator=(const CLoggerNull& iOther) DBO_NOTHROW { };

public:
   // explicit Construction/Destruction
   explicit CLoggerNull(const dbo_char_t* const iName) DBO_NOTHROW;
   explicit CLoggerNull(const dbo_string_t& iName) DBO_NOTHROW;
   virtual ~CLoggerNull() DBO_NOTHROW { };

public:
   // Interface
   virtual DBO_TRACE_RESULT TraceAsCString (dbo_uint32_t iErrLevel, const dbo_char_t* const iCStr, const size_t iSize) const DBO_NOTHROW;
   virtual DBO_TRACE_RESULT TraceAsString  (dbo_uint32_t iErrLevel, const dbo_string_t& iStr) const DBO_NOTHROW;
   virtual DBO_TRACE_RESULT TraceAsWCString(dbo_uint32_t iErrLevel, const dbo_wchar_t* const iWCStr, const size_t iSize) const DBO_NOTHROW;
   virtual DBO_TRACE_RESULT TraceAsWString (dbo_uint32_t iErrLevel, const dbo_wstring_t& iWStr) const DBO_NOTHROW;
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_LOGGERNULL_H_INCLUDED) */

