/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#ifndef DBO_CONVPOLICYTRUEWIN32_H_INCLUDED
#define DBO_CONVPOLICYTRUEWIN32_H_INCLUDED

#include "dbo/ConvPolicyNull.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1400)

NAMESPACE_DBO_OPEN

// The Null Policy Class
class CConvPolicyTrueWin32 : public CConvPolicyNull
{
   DBO_DEF_CLASS_H;
   DBO_PRI_CLASS_CTOR_H(CConvPolicyTrueWin32);

private:
   // ConvPolicy are NOT copy-constructible and assignable
   CConvPolicyTrueWin32(const CConvPolicyTrueWin32& iOther) DBO_NOTHROW { };
   CConvPolicyTrueWin32& operator=(const CConvPolicyTrueWin32& iOther) DBO_NOTHROW { };

public:
   // explicit Construction/Destruction
   explicit CConvPolicyTrueWin32(const dbo_char_t* const iName, const dbo_uint8_t convRoundMode = DBO_CONV_ROUND_NONE) DBO_NOTHROW;
   explicit CConvPolicyTrueWin32(const dbo_string_t& iName    , const dbo_uint8_t convRoundMode = DBO_CONV_ROUND_NONE) DBO_NOTHROW;
   virtual ~CConvPolicyTrueWin32() DBO_NOTHROW { };

public:
   // Interface: do use base class behavior when not otherwise stated

   // Numerical conversions ->

   // Integer8 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW;

   // Unsigned Integer8 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW;

   // Integer16 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW;

   // Unsigned Integer16 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW;

   // Integer32 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW;

   // Unsigned Integer32 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW;

   // Integer64 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW;

   // Unsigned Integer64 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW; // identity
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW;

#if 0
   // Integer128 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW;

   // Unsigned Integer128 to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW;
#endif

   // Single to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW;

   // Double to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW; // identity
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW;

   // Quad to ...
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int8_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int16_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int32_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int64_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint8_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint16_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint32_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint64_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_int128_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_uint128_t& oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_single_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_double_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToNum(dbo_quad_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW; // identity

   // Numerical to string
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_string_t&  oStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW;

   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
#if 0
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW;
#endif
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvNumToStr(dbo_wstring_t& oWStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW;

   // Numerical conversions <-

   // String conversions ->
   // virtual DBO_CONV_RESULT ConvStrToStr(dbo_string_t&   oStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvStrToStr(dbo_wstring_t& oWStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvStrToStr(dbo_string_t&   oStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW;
   // virtual DBO_CONV_RESULT ConvStrToStr(dbo_wstring_t& oWStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW;
   // String conversions <-
};

NAMESPACE_DBO_CLOSE

#endif // !defined(_MSC_VER) || !(_MSC_VER >= 1400)

#endif /* !defined(DBO_CONVPOLICYTRUEWIN32_H_INCLUDED) */

