/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_CALLOCATORS_H_INCLUDED
#define DBO_CALLOCATORS_H_INCLUDED

#include <cstdlib>

#if (defined(_MSC_VER) && (_MSC_VER >= 1600))
// MICROSOFT extensions, custom allocators in stdext::
#include <allocators>
#endif

#include "dbo/namespace.h"

NAMESPACE_DBO_OPEN

// The purpose of these definitions is just to mark explicitly where we do use
// allocators: transition to a custom allocator will be easier.

// c-way
#define DBO_MALLOC(x)      std::malloc(x)
#define DBO_FREE(x)        std::free(x)

// Markers
#define DBO_STD_ALLOCATOR  std::allocator
#define DBO_NEW            ::new
#define DBO_DELETE         ::delete

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_CALLOCATORS_H_INCLUDED) */

