/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// General helpers

#ifndef DBO_HELPERS_H_INCLUDED
#define DBO_HELPERS_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

// Global helpers for 64bits

NAMESPACE_DBO_OPEN

#ifdef __cplusplus

static FORCE_INLINE dbo_uint16_t MAKE_UINT16(dbo_uint16_t high, dbo_uint16_t low)
{
    return (((dbo_uint16_t) high) << 8) | low;
}

static FORCE_INLINE dbo_uint16_t LOW_UINT16(dbo_uint16_t word)
{
    return (dbo_uint16_t) (word & 0xFF);
}

static FORCE_INLINE dbo_uint16_t HIGH_UINT16(dbo_uint16_t word)
{
    return (dbo_uint16_t) ((word >> 8) & 0xFF);
}

static FORCE_INLINE dbo_uint32_t MAKE_UINT32(dbo_uint16_t high, dbo_uint16_t low)
{
    return (((dbo_uint32_t) high) << 16) | ((dbo_uint32_t) low);
}

static FORCE_INLINE dbo_uint32_t LOW_UINT32(dbo_uint32_t word)
{
    return (dbo_uint32_t) (word & 0xFFFF);
}

static FORCE_INLINE dbo_uint32_t HIGH_UINT32(dbo_uint32_t word)
{
    return (dbo_uint32_t) ((word >> 16) & 0xFFFF);
}

static FORCE_INLINE dbo_uint64_t MAKE_UINT64(dbo_uint32_t high, dbo_uint32_t low)
{
    return (((dbo_uint64_t) high) << 32) | ((dbo_uint64_t) low);
}

static FORCE_INLINE dbo_uint64_t LOW_UINT64(dbo_uint64_t word)
{
    return ((dbo_uint64_t)) (word & 0xFFFFFFFF);
}

static FORCE_INLINE dbo_uint64_t HIGH_UINT64(dbo_uint64_t word)
{
    return ((dbo_uint64_t)) ((word >> 32) & 0xFFFFFFFF);
}

#endif /* __cplusplus */

NAMESPACE_DBO_CLOSE

#endif /* DBO_HELPERS_H_INCLUDED */

