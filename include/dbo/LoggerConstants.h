/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_LOGGERCONSTANTS_H_INCLUDED
#define DBO_LOGGERCONSTANTS_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

NAMESPACE_DBO_OPEN

typedef   dbo_uint32_t      DBO_TRACE_RESULT;

// Do not use enum until c++11 is fully deployed
const DBO_TRACE_RESULT  DBO_TRACE_RESULT_SUCCESS                     = 0x00000000;

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_LOGGERCONSTANTS_H_INCLUDED) */

