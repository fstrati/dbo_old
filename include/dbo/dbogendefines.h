// Global library definitions that do not fit elsewhere

#ifndef DBO_DBOGENDEFINES_H_INCLUDED
#define DBO_DBOGENDEFINES_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

// General library defines
#define DBO_HAS_EXPLICIT_CONVERSIONS   1
#define DBO_HAS_SMALL_STRING_RESIZE    1
//#define _CRT_SECURE_NO_WARNINGS

// Array hard limits

// Oracle string VARCHAR2 limit is
#define DBO_TXT_STRING_ORADB_LIMIT   4000
// Oracle string VARCHAR2 limit is (in PL/SQL)
#define DBO_TXT_STRING_PLSQL_LIMIT   32767
// Arbitrary Array limit: 0xFFFFFFFF / 16
#define DBO_ARRAY_ELEM_HARD_LIMIT    0xBA2E8BA

#define DBO_TXT_STRING_GENERAL_LIMIT   65536

// Various defaults
#define DBO_TXT_STR_DEFAULT_LENGTH         0x00FF
#define DBO_TXT_SMALL_STRING_RESIZE        3
#define DBO_TXT_SMALL_STRING_RESIZE_FRAC   0.33

// TimeStamps
#define DBO_TXT_ATTR_DEF_DBTIME(tStamp)  { tStamp.year=2000; tStamp.month=1;  tStamp.day=1; \
                                           tStamp.hour=0;    tStamp.minute=0; tStamp.second=0; \
                                           tStamp.fraction=0; }
// Definitions for integers
#define DBO_INT_ZERO            0
#define DBO_INT_CONVBASE        10

// Definitions for floating point calculations
#define DBO_FLOAT_TOL           ((dbo_single_t)  3.0e-08)
#define DBO_FLOAT_ZERO          ((dbo_single_t)  0.0e+00)
#define DBO_FLOAT_MAXP          ((dbo_single_t)  1.0e+31)
#define DBO_FLOAT_MAXN          ((dbo_single_t) -1.0e+31)
#define DBO_FLOAT_MINP          ((dbo_single_t)  1.0e-18)
#define DBO_FLOAT_MINN          ((dbo_single_t) -1.0e-18)

#define DBO_DBLE_TOL            ((dbo_double_t)  3.0e-15)
#define DBO_DBLE_ZERO           ((dbo_double_t)  0.0e+00)
#define DBO_DBLE_MAXP           ((dbo_double_t)  1.0e+300)
#define DBO_DBLE_MAXN           ((dbo_double_t) -1.0e+300)
#define DBO_DBLE_MINP           ((dbo_double_t)  1.0e-300)
#define DBO_DBLE_MINN           ((dbo_double_t) -1.0e-300)

// Time conversions
#define DBO_TIME_BASE_TM_YEAR        1900
#define DBO_TIME_BASE_ST_MONTH       1

// Formatting
#define DBO_TXT_ATTR_CONVSTRINGSIZE        0x0FFF

NAMESPACE_DBO_OPEN

const dbo_char_t  DBO_TXT_ATTR_TIMESTRINGFMT[]        = "%04d-%02d-%02d %02d:%02d:%02d";
const dbo_char_t  DBO_TXT_ATTR_TIMESTAMPSTRINGFMT[]   = "%04d-%02d-%02d %02d:%02d:%02d.%06d";
const dbo_char_t  DBO_TXT_ATTR_FLOATSTRINGFMT[]       = "%.7e";
const dbo_char_t  DBO_TXT_ATTR_DOUBLESTRINGFMT[]      = "%.15e";
const dbo_char_t  DBO_TXT_ATTR_INTSTRINGFMT[]         = "%d";
const dbo_char_t  DBO_TXT_ATTR_INT64STRINGFMT[]       = "%ld";
const dbo_char_t  DBO_TXT_NULL_TEXT[]                 = "";
const dbo_char_t  DBO_TXT_STDTERM_CHAR                = '\0';

const dbo_wchar_t DBO_TXT_ATTR_TIMESTRINGFMT_L[]      = L"%04d-%02d-%02d %02d:%02d:%02d";
const dbo_wchar_t DBO_TXT_ATTR_TIMESTAMPSTRINGFMT_L[] = L"%04d-%02d-%02d %02d:%02d:%02d.%06d";
const dbo_wchar_t DBO_TXT_ATTR_FLOATSTRINGFMT_L[]     = L"%.7e";
const dbo_wchar_t DBO_TXT_ATTR_DOUBLESTRINGFMT_L[]    = L"%.15e";
const dbo_wchar_t DBO_TXT_ATTR_INTSTRINGFMT_L[]       = L"%d";
const dbo_wchar_t DBO_TXT_ATTR_INT64STRINGFMT_L[]     = L"%ld";
const dbo_wchar_t DBO_TXT_NULL_TEXT_L[]               = L"";
const dbo_wchar_t DBO_TXT_STDTERM_CHAR_L              = L'\0';

const dbo_string_t DBO_DEF_UNITS_STR = "<N/A>";

NAMESPACE_DBO_CLOSE

#define DBO_ERROR_THROW_TMP                           do \
                                                      { \
                                                         throw; \
                                                      } while (false)

#endif /* DBO_DBOGENDEFINES_H_INCLUDED */


