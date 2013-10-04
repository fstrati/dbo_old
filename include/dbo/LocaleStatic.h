/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_LOCALESTATIC_H_INCLUDED
#define DBO_LOCALESTATIC_H_INCLUDED

#include <locale>

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

// Glorified globals, pay attention in DLL

NAMESPACE_DBO_OPEN

static std::locale GetLocaleDefault() DBO_NOTHROW ;

static void SetLocaleGlobalToDefault() DBO_NOTHROW ;

static void SetLocaleGlobalTo(const dbo_string_t&  localeStrId) DBO_NOTHROW ;

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_LOCALESTATIC_H_INCLUDED) */

