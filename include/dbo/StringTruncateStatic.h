/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_STRINGTRUNCATESTATIC_H_INCLUDED
#define DBO_STRINGTRUNCATESTATIC_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

// Utilities to truncate small strings in copying them

NAMESPACE_DBO_OPEN

// All these functions return true if string was actually truncated

static dbo_bool_t TruncateStrToStr(dbo_string_t& oStr, const dbo_string_t& iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW ;

static dbo_bool_t TruncateStrToStr(dbo_string_t& oStr, const dbo_char_t* const iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW ;

static dbo_bool_t TruncateStrToStr(dbo_wstring_t& oStr, const dbo_wstring_t& iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW ;

static dbo_bool_t TruncateStrToStr(dbo_wstring_t& oStr, const dbo_wchar_t* const iStr, const dbo_uint32_t oMaxSize) DBO_NOTHROW ;

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_STRINGTRUNCATESTATIC_H_INCLUDED) */

