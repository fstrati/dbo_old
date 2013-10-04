/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_CONVPOLICYCONSTANTS_H_INCLUDED
#define DBO_CONVPOLICYCONSTANTS_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

NAMESPACE_DBO_OPEN

typedef   dbo_uint32_t      DBO_CONV_RESULT;

// Rounding modes: ceil, floor, etc... 
const dbo_uint8_t      DBO_CONV_ROUND_NONE                        = 0x00; // use the implicit env. rounding
const dbo_uint8_t      DBO_CONV_ROUND_CEIL                        = 0x01;
const dbo_uint8_t      DBO_CONV_ROUND_FLOOR                       = 0x02;

// Return values
// Do not use enum until c++11 is fully deployed
const DBO_CONV_RESULT  DBO_CONV_RESULT_SUCCESS                     = 0x00000000;
const DBO_CONV_RESULT  DBO_CONV_RESULT_ILLEGAL                     = 0x00000001;
const DBO_CONV_RESULT  DBO_CONV_RESULT_TRUNCATE                    = 0x00000002;
const DBO_CONV_RESULT  DBO_CONV_RESULT_TRUNCATE_CEIL               = 0x00000003;
const DBO_CONV_RESULT  DBO_CONV_RESULT_TRUNCATE_FLOOR              = 0x00000004;

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_CONVPOLICYCONSTANTS_H_INCLUDED) */

