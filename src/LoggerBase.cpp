/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// The Abstract Base Class adapter for Loggers

#include "dbo/callocators.h"

#include "dbo/LoggerBase.h"

NAMESPACE_DBO_OPEN

using namespace std;

// explicit Construction/Destruction
CLoggerBase::CLoggerBase(const dbo_char_t* const iName) DBO_NOTHROW
{
   _logger_name = iName; /* Logger name */
}

CLoggerBase::CLoggerBase(const dbo_string_t& iName) DBO_NOTHROW
{
   _logger_name = iName; /* Logger name */
}

NAMESPACE_DBO_CLOSE

