/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include "dbo/callocators.h"

#include "dbo/ConvPolicyNull.h"

#include <sstream>

NAMESPACE_DBO_OPEN

using namespace std;

// Construction/Destruction
CConvPolicyNull::CConvPolicyNull(const dbo_char_t* const iName, const dbo_uint8_t convRoundMode) DBO_NOTHROW \
   : CConvPolicyBase(iName,convRoundMode)
{
}

CConvPolicyNull::CConvPolicyNull(const dbo_string_t& iName    , const dbo_uint8_t convRoundMode) DBO_NOTHROW \
   : CConvPolicyBase(iName,convRoundMode)
{
}

// Interface

// Numerical conversions ->

// Integer8 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_int8_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Unsigned Integer8 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint8_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Integer16 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_int16_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Unsigned Integer16 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint16_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Integer32 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_int32_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Unsigned Integer32 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint32_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Integer64 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_int64_t&    iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Unsigned Integer64 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint64_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
// Integer128 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_int128_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Unsigned Integer128 to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_uint128_t&  iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

// Single to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_single_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Double to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_double_t&   iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_double_t&   iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

// Quad to ...
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int8_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int16_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int32_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int64_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint8_t&   oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint16_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint32_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint64_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_int128_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_uint128_t& oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_single_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_double_t&  oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToNum(dbo_quad_t&    oNum, const dbo_quad_t&     iNum) const DBO_NOTHROW // identity
{
   oNum = iNum;
   return DBO_CONV_RESULT_SUCCESS;
}

// Numerical to string
// Helper static
template<typename T>
static DBO_CONV_RESULT stConvNumToStr(dbo_string_t&  oStr, const T& value, const std::locale& localeOut)
{
   // TODO: Boost
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
   std::stringstream ss;
   ss.imbue(localeOut);
   ss << value;
   oStr = ss.str();
   return DBO_CONV_RESULT_SUCCESS;
#else
   return DBO_CONV_RESULT_ILLEGAL;
#endif
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_int8_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_int16_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_int32_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_int64_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_uint8_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_uint16_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_uint32_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_uint64_t>(oStr, iNum, localeOut);
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_int128_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_uint128_t>(oStr, iNum, localeOut);
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_single_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_double_t>(oStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_string_t&  oStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToStr<dbo_quad_t>(oStr, iNum, localeOut);
}

// Helper static
template<typename T>
static DBO_CONV_RESULT stConvNumToWStr(dbo_wstring_t&  oStr, const T& value, const std::locale& localeOut)
{
   // TODO: Boost
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
   std::wstringstream ss;
   ss.imbue(localeOut);
   ss << value;
   oStr = ss.str();
   return DBO_CONV_RESULT_SUCCESS;
#else
   return DBO_CONV_RESULT_ILLEGAL;
#endif
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int8_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_int8_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int16_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_int16_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int32_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_int32_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int64_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_int64_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint8_t&   iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_uint8_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint16_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_uint16_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint32_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_uint32_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint64_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_uint64_t>(oWStr, iNum, localeOut);
}

#if 0
DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_int128_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_int128_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_uint128_t& iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_uint128_t>(oWStr, iNum, localeOut);
}
#endif

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_single_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_single_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_double_t&  iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_double_t>(oWStr, iNum, localeOut);
}

DBO_CONV_RESULT CConvPolicyNull::ConvNumToStr(dbo_wstring_t& oWStr, const dbo_quad_t&    iNum, const std::locale& localeOut) const DBO_NOTHROW
{
   return stConvNumToWStr<dbo_quad_t>(oWStr, iNum, localeOut);
}

// Numerical conversions <-

// String conversions ->
DBO_CONV_RESULT CConvPolicyNull::ConvStrToStr(dbo_string_t&   oStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW
{
   // Identity, discard locale info
   oStr = iStr;
   return DBO_CONV_RESULT_SUCCESS;
}

DBO_CONV_RESULT CConvPolicyNull::ConvStrToStr(dbo_wstring_t& oWStr, const dbo_string_t&   iStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvStrToStr(dbo_string_t&   oStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW
{
   return DBO_CONV_RESULT_ILLEGAL;
}

DBO_CONV_RESULT CConvPolicyNull::ConvStrToStr(dbo_wstring_t& oWStr, const dbo_wstring_t& iWStr, const std::locale& localeOut, const std::locale& localeIn) const DBO_NOTHROW
{
   // Identity, discard locale info
   oWStr = iWStr;
   return DBO_CONV_RESULT_SUCCESS;
}
// String conversions <-

NAMESPACE_DBO_CLOSE

