/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_BFLOATS_H_INCLUDED
#define DBO_BFLOATS_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

NAMESPACE_DBO_OPEN

#if ( defined(_MSC_VER) && (_MSC_VER>=1600) )
#ifdef DBO_DEBUG
#pragma pack(show)
#endif
#pragma pack(push, rfloats, 1) // n = 1, pushed to stack
#ifdef DBO_DEBUG
#pragma pack(show)
#endif
#else // !( defined(_MSC_VER) && (_MSC_VER>=1600) )
#error your platform is not supported yet
#endif

struct dbo_bin_float_t
{
   dbo_uint32_t mantissa; // encoding sign bit & mantissa together
   dbo_uint8_t  exp;
};

struct dbo_bin_double_t
{
   dbo_uint64_t mantissa; // encoding sign bit & mantissa together
   dbo_uint16_t exp;
};

#if 0
struct dbo_bin_quad_t
{
   dbo_uint64_t mantissa_high; // encoding sign bit & mantissa together
   dbo_uint64_t mantissa_low;
   dbo_uint32_t exp;
};
#endif

#if ( defined(_MSC_VER) && (_MSC_VER>=1600) )
#ifdef DBO_DEBUG
#pragma pack(show)
#endif
#pragma pack(pop, rfloats) // stack popped
#ifdef DBO_DEBUG
#pragma pack(show)
#endif
#endif // !( defined(_MSC_VER) && (_MSC_VER>=1600) )

// The utility functions
#if ( defined(_MSC_VER) && (_MSC_VER>=1600) )

static void ComputeFloatFromInd(dbo_double_t& oDouble, const dbo_bin_double_t& iStr) DBO_NOTHROW ;

static void ComputeIndFromFloat(dbo_bin_double_t& oStr, const dbo_double_t& iDouble) DBO_NOTHROW ;

#endif // !( defined(_MSC_VER) && (_MSC_VER>=1600) )

NAMESPACE_DBO_CLOSE

#endif // !defined(DBO_BFLOATS_H_INCLUDED)

