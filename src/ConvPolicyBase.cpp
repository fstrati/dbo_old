/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/ConvPolicyBase.h"

NAMESPACE_DBO_OPEN

using namespace std;

// explicit Construction/Destruction
CConvPolicyBase::CConvPolicyBase(const dbo_char_t* const iName, \
                                 const dbo_uint8_t convRoundMode /* = DBO_CONV_ROUND_NONE */) DBO_NOTHROW
{
  _convpolicy_name = iName; /* Conversion Policy name */
  _conv_round_mode = convRoundMode; /* Rounding mode: ceil, floor, etc... */
}

CConvPolicyBase::CConvPolicyBase(const dbo_string_t& iName    , \
                                 const dbo_uint8_t convRoundMode /* = DBO_CONV_ROUND_NONE */) DBO_NOTHROW
{
   _convpolicy_name = iName; /* Conversion Policy name */
   _conv_round_mode = convRoundMode; /* Rounding mode: ceil, floor, etc... */
}

NAMESPACE_DBO_CLOSE

