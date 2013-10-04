/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include "dbo/callocators.h"

#include "dbo/LoggerNull.h"

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_CLASS_SRC(CLoggerNull);

// Construction/Destruction
CLoggerNull::CLoggerNull(const dbo_char_t* const iName) DBO_NOTHROW \
   : CLoggerBase(iName)
{
}

CLoggerNull::CLoggerNull(const dbo_string_t& iName) DBO_NOTHROW \
   : CLoggerBase(iName)
{
}

// Interface
DBO_TRACE_RESULT CLoggerNull::TraceAsCString(dbo_uint32_t iErrLevel, const dbo_char_t* const iCStr, const size_t iSize) const DBO_NOTHROW
{
   // Do nothing;
   return DBO_TRACE_RESULT_SUCCESS;
}

DBO_TRACE_RESULT CLoggerNull::TraceAsString (dbo_uint32_t iErrLevel, const dbo_string_t& iStr) const DBO_NOTHROW
{
   // Do nothing;
   return DBO_TRACE_RESULT_SUCCESS;
}

DBO_TRACE_RESULT CLoggerNull::TraceAsWCString(dbo_uint32_t iErrLevel, const dbo_wchar_t* const iWCStr, const size_t iSize) const DBO_NOTHROW
{
   // Do nothing;
   return DBO_TRACE_RESULT_SUCCESS;
}

DBO_TRACE_RESULT CLoggerNull::TraceAsWString (dbo_uint32_t iErrLevel, const dbo_wstring_t& iWStr) const DBO_NOTHROW
{
   // Do nothing;
   return DBO_TRACE_RESULT_SUCCESS;
}

NAMESPACE_DBO_CLOSE

