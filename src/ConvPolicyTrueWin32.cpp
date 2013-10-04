/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/ConvPolicyTrueWin32.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1400)

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_CLASS_SRC(CConvPolicyTrueWin32);

// Construction/Destruction
CConvPolicyTrueWin32::CConvPolicyTrueWin32(const dbo_char_t* const iName, const dbo_uint8_t convRoundMode) DBO_NOTHROW \
   : CConvPolicyNull(iName,convRoundMode)
{
}

CConvPolicyTrueWin32::CConvPolicyTrueWin32(const dbo_string_t& iName    , const dbo_uint8_t convRoundMode) DBO_NOTHROW \
   : CConvPolicyNull(iName,convRoundMode)
{
}

// Interface, added only to save them

NAMESPACE_DBO_CLOSE

#endif // !defined(_MSC_VER) || !(_MSC_VER >= 1400)

