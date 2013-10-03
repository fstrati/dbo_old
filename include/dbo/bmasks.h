/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_BMASKS_H_INCLUDED
#define DBO_BMASKS_H_INCLUDED

#include "dbo/typesdef.h"

NAMESPACE_DBO_OPEN

   // Intel IEEE formats, leading digit of the mantissa assumed to 1 and omitted
   // S = Sign bit, X = Exponent, M = Mantissa
   //   bits = 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
   // real*4 =  S  X  X  X  X  X  X  X  X  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M
   //   bits = 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32
   // real*8 =  S  X  X  X  X  X  X  X  X  X  X  X  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M
   //   bits = 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
   // real*8 =  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M

   // Functions for Masks to extract the Sign (S), the Mantissa (M) and the Exponent (X)

extern FORCE_INLINE dbo_uint32_t ComputeSignMaskFloat() DBO_NOTHROW ;

extern FORCE_INLINE dbo_uint32_t ComputeMantMaskFloat() DBO_NOTHROW ;

extern FORCE_INLINE dbo_uint32_t ComputeExpMaskFloat() DBO_NOTHROW ;

extern FORCE_INLINE dbo_uint64_t ComputeSignMaskDouble() DBO_NOTHROW ;

extern FORCE_INLINE dbo_uint64_t ComputeMantMaskDouble() DBO_NOTHROW ;

extern FORCE_INLINE dbo_uint64_t ComputeExpMaskDouble() DBO_NOTHROW ;

NAMESPACE_DBO_CLOSE

#endif // !defined(DBO_BMASKS_H_INCLUDED)

