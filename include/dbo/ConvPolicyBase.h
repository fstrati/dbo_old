/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_CONVPOLICYBASE_H_INCLUDED
#define DBO_CONVPOLICYBASE_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/macros.h"
#include "dbo/dbogendefines.h"
#include "dbo/options.h"

#include "dbo/ConvPolicyConstants.h"

// TODO: Boost
#include <locale>

NAMESPACE_DBO_OPEN

// The Abstract Base Class adapter for Conversion Policies
class CConvPolicyBase
{
   DBO_DEF_CLASS_H;
   // DBO_PRI_CLASS_CTOR_H(CConvPolicyBase);
   // TODO: public default ctor to keep compilers happy...
public:
   CConvPolicyBase() DBO_NOTHROW { };

private:
   // ConvPolicy are NOT copy-constructible and assignable
   CConvPolicyBase(const CConvPolicyBase& iOther) DBO_NOTHROW { };
   CConvPolicyBase& operator=(const CConvPolicyBase& iOther) DBO_NOTHROW { };

public:
   // explicit Construction/Destruction
   explicit CConvPolicyBase(const dbo_char_t* const iName, const dbo_uint8_t convRoundMode = DBO_CONV_ROUND_NONE) DBO_NOTHROW;
   explicit CConvPolicyBase(const dbo_string_t& iName    , const dbo_uint8_t convRoundMode = DBO_CONV_ROUND_NONE) DBO_NOTHROW;
   // TODO: public default dtor to keep compilers happy... (not pure virtual)
   virtual ~CConvPolicyBase() DBO_NOTHROW { };

public:
   // Interface

   // Numerical conversions ->

   // Integer8 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW = 0;

   // Unsigned Integer8 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW = 0;

   // Integer16 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW = 0;

   // Unsigned Integer16 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW = 0;

   // Integer32 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW = 0;

   // Unsigned Integer32 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW = 0;

   // Integer64 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW = 0;

   // Unsigned Integer64 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0; // identity
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW = 0;

#if 0
   // Integer128 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW = 0;

   // Unsigned Integer128 to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW = 0;
#endif

   // Single to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW = 0;

   // Double to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0; // identity
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW = 0;

   // Quad to ...
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW = 0; // identity

   // Numerical to string
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;

   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
#if 0
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
#endif
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW = 0;

   // Numerical conversions <-

   // String conversions ->
   virtual DBO_CONV_RESULT ConvStrToStr(dbo_string_t&   oStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvStrToStr(dbo_wstring_t& oWStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvStrToStr(dbo_string_t&   oStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW = 0;
   virtual DBO_CONV_RESULT ConvStrToStr(dbo_wstring_t& oWStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW = 0;
   // String conversions <-

// Static properties
public:
   FORCE_INLINE const dbo_string_t& getConvName(void) const DBO_NOTHROW 
   {
      return _convpolicy_name;
   };
   FORCE_INLINE const dbo_uint8_t& getConvRoundMode(void) const DBO_NOTHROW 
   {
      return _conv_round_mode;
   };
private:
   dbo_string_t _convpolicy_name; /* Conversion Policy name */
   dbo_uint8_t  _conv_round_mode; /* Rounding mode: ceil, floor, etc... */
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_CONVPOLICYBASE_H_INCLUDED) */

