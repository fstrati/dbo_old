/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// implementation file for bfloats

#include "dbo/namespace.h"
#include "dbo/dbogendefines.h"
#include "dbo/bfloats.h"
#include "dbo/bmasks.h"

NAMESPACE_DBO_OPEN

// Intel IEEE formats, leading digit of the mantissa assumed to 1 and omitted
// S = Sign bit, X = Exponent, M = Mantissa
//   bits = 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
// real*4 =  S  X  X  X  X  X  X  X  X  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M
//   bits = 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32
// real*8 =  S  X  X  X  X  X  X  X  X  X  X  X  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M
//   bits = 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
// real*8 =  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M  M

// Functions to extract the independent float binary format for any given platform

void ComputeFloatFromInd(dbo_double_t& oDouble, const dbo_bin_double_t& iStr) DBO_NOTHROW
{
   dbo_double_t reconstruction = 0;
#if ( defined(_MSC_VER) && (_MSC_VER>=1600) )
   // For Intel IEEE the representation is IEEE float with leading 1 in the mantissa omitted
   // Import the data
   dbo_uint64_t dmant_exp = ((dbo_uint64_t) 1022)<<((dbo_uint64_t) 52); // 1022 is the bias
   dbo_uint64_t dmantissa = DBO_INT_ZERO; 
   dmantissa = iStr.mantissa | dmant_exp ; // convert mantissa to its double format
   dbo_double_t in_dmantissa;
   memset((void*) &in_dmantissa, 0, sizeof(dbo_double_t));
   memcpy((void*) &in_dmantissa, (void*) &dmantissa, sizeof(dbo_double_t));
   dbo_int32_t dinput_exp = ((dbo_int32_t) iStr.exp) - 1022;
   // rebuild from converted mantissa(+sign) and exp
   reconstruction = ldexp(in_dmantissa,dinput_exp);
#endif
   oDouble = reconstruction;
}

void ComputeIndFromFloat(dbo_bin_double_t& oStr, const dbo_double_t& iDouble) DBO_NOTHROW
{
   // Convert the double value in our custom independent representation, i.e. split (Sign+Mantissa) from (Exponent)
   // In IEEE float representations a double is given by x = S*M*(2**E) - ** means exponentation
   // The Sign (S) is the leading bit
   // The Exponent (E) (biased by a value in order to represent negative exponents) is the following 11 bits (binary representation) in a double
   // The Mantissa (M) is the remaining 52 bits (binary representation of the mantissa) in a double
   // For Intel IEEE the representation is IEEE float with leading 1 in the mantissa omitted
   // For every platform do encode double as for Intel IEEE Format
   // NOTE: Not every platform adhere to the IEEE formats, that's why we do encode in our expanded form
#if ( defined(_MSC_VER) && (_MSC_VER>=1600) )
   // For msvc the representation is IEEE float with leading 1 in the mantissa omitted
   // Get the masks for Intel IEEE double
   dbo_uint64_t dsign_mask = ComputeSignMaskDouble();
   dbo_uint64_t dexp_mask  = ComputeExpMaskDouble();
   dbo_uint64_t dman_mask  = ComputeMantMaskDouble();
   // Extract the data
   dbo_uint64_t didirect = DBO_INT_ZERO;
   memcpy((void*) &didirect, (void*) &iDouble, sizeof(dbo_double_t));
   dbo_uint64_t dextracted_sign = didirect & dsign_mask;
   dbo_uint64_t dextracted_exp  = didirect & dexp_mask;
   dbo_uint64_t dextracted_man  = didirect & dman_mask;
   // Copy the mantissa and its sign to our format
   oStr.mantissa = DBO_INT_ZERO;
   oStr.mantissa = dextracted_sign | dextracted_man;
   oStr.exp = DBO_INT_ZERO;
   oStr.exp = static_cast<dbo_uint16_t> (dextracted_exp>>((dbo_uint64_t) 52));
#else
   oStr.mantissa = DBO_INT_ZERO;
   oStr.exp = DBO_INT_ZERO;
#endif
}

NAMESPACE_DBO_CLOSE









