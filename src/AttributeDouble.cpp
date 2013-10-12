/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// Implementation of the double attribute

#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cmath>

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/AttributeDouble.h"

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_ATTR_KIND(CAttributeDouble,DBO_KIND_DOUBLE);

// Construction/Destruction

CAttributeDouble::CAttributeDouble(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_double_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_double_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_DBLE_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeDouble::CAttributeDouble(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_double_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_double_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_DBLE_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeDouble::CAttributeDouble(const dbo_double_t& iDouble, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_double_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_double_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = iDouble;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeDouble::CAttributeDouble(const dbo_double_t& iDouble, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_double_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_double_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = iDouble;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeDouble::~CAttributeDouble() DBO_NOTHROW 
{
   Dealloca(value);
}

// Copyable and assignable
CAttributeDouble::CAttributeDouble(const CAttributeDouble& iOther) DBO_NOTHROW 
{
   // Do copy the base:
   CAttributeGeneric::copyBase( iOther );
   // Set the values...
   this->set(iOther.get());
}

CAttributeDouble& CAttributeDouble::operator=(const CAttributeDouble& iOther) DBO_NOTHROW 
{
   if ( this != &iOther ) // Prevent self assignment
   {
      // Do copy the base:
      CAttributeGeneric::copyBase( iOther );
      // Set the values...
      this->set(iOther.get());
   }
   return *this;
}

void CAttributeDouble::buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   // Set the values...
   this->set(iOther.get());
}

// GET / SET generic methods
void CAttributeDouble::set(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) )
   {
      *value = iOther.getAsDouble();
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeDouble::setFromPtr(const CAttributeGeneric* const pOther) DBO_NOTHROW 
{
   if (DBO_VALIDP(value) && DBO_VALIDP(pOther))
   {
      *value = pOther->getAsDouble();
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Explicit conversions
dbo_string_t CAttributeDouble::getAsString(void) const DBO_NOTHROW 
{
   dbo_string_t str_result = DBO_TXT_NULL_TEXT;
   if (DBO_VALIDP(value))
   {
      dbo_char_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_DOUBLESTRINGFMT, (*value));
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
      cconv[DBO_TXT_ATTR_CONVSTRINGSIZE-1] = DBO_TXT_STDTERM_CHAR;
      str_result = cconv;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return str_result;
}

void CAttributeDouble::setAsString(const dbo_string_t& iStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_double_t> (strtod(iStr.c_str(), NULL));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_wstring_t CAttributeDouble::getAsWString(void) const DBO_NOTHROW 
{
   dbo_wstring_t str_result = DBO_TXT_NULL_TEXT_L;
   if (DBO_VALIDP(value))
   {
      dbo_wchar_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snwprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_DOUBLESTRINGFMT_L, (*value));
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
      cconv[DBO_TXT_ATTR_CONVSTRINGSIZE-1] = DBO_TXT_STDTERM_CHAR_L;
      str_result = cconv;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return str_result;
}

void CAttributeDouble::setAsWString(const dbo_wstring_t& iWStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_double_t> (wcstod(iWStr.c_str(), NULL));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeDouble::getAsCString(dbo_char_t* oCStr, const size_t iSize) const DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(oCStr) && (iSize > 0) )
   {
      int iRes = snprintf(oCStr, iSize, DBO_TXT_ATTR_DOUBLESTRINGFMT, (*value));
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
      oCStr[iSize] = DBO_TXT_STDTERM_CHAR;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeDouble::setAsCString(const dbo_char_t* const iCStr) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(iCStr) )
   {
      *value = static_cast<dbo_double_t> (strtod(iCStr, NULL));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeDouble::getAsWCString(dbo_wchar_t* oWCStr, const size_t iSize) const DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(oWCStr) && (iSize > 0) )
   {
      int iRes = snwprintf(oWCStr, iSize, DBO_TXT_ATTR_DOUBLESTRINGFMT_L, (*value));
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
      oWCStr[iSize] = DBO_TXT_STDTERM_CHAR_L;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeDouble::setAsWCString(const dbo_wchar_t* const iWCStr) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(iWCStr) )
   {
      *value = static_cast<dbo_double_t> (wcstod(iWCStr, NULL));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_double_t CAttributeDouble::getAsDouble(void) const DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      return *value;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return DBO_DBLE_ZERO;
}

void CAttributeDouble::setAsDouble(const dbo_double_t& iDouble) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      (*value) = iDouble;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_int64_t CAttributeDouble::getAsInt64(void) const DBO_NOTHROW 
{
   dbo_int64_t lret = DBO_INT_ZERO;
   if (DBO_VALIDP(value))
   {
      return (static_cast<dbo_int64_t> (*value));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return lret;
}

void CAttributeDouble::setAsInt64(const dbo_int64_t& iInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_double_t> (iInt64);
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_uint64_t CAttributeDouble::getAsUInt64(void) const DBO_NOTHROW 
{
   dbo_uint64_t ulret = DBO_INT_ZERO;
   if (DBO_VALIDP(value))
   {
      return (static_cast<dbo_uint64_t> (*value));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return ulret;
}

void CAttributeDouble::setAsUInt64(const dbo_uint64_t& iUInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_double_t> (iUInt64);
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Warning, setSize does invalidate this attribute
void CAttributeDouble::setSize(const size_t iSize) DBO_NOTHROW 
{
   setValid(false);
   setLastError(DBO_ATTR_ERR_INVALID_OP);
}

void CAttributeDouble::reset() DBO_NOTHROW 
{
   Dealloca(value);

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_DBLE_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

DBO_BIN_KIND_SIZE CAttributeDouble::getLength(void) const DBO_NOTHROW 
{
   // Convert into a string and get the length
   dbo_string_t res = getAsString();
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (res.size());
   return ulret;
}

DBO_BIN_KIND_SIZE CAttributeDouble::getWLength(void) const DBO_NOTHROW 
{
   // Convert into a string and get the length
   dbo_wstring_t res = getAsWString();
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (res.size());
   return ulret;
}

void CAttributeDouble::emptyValue(void) DBO_NOTHROW 
{
   DBO_DEF_EMPTYVALUE(value,DBO_DBLE_ZERO);
}

bool CAttributeDouble::isEmpty(void) const DBO_NOTHROW 
{
   if (DBO_INVALIDP(value) || isNull())
   {
      return true;
   }
   return ( DBO_DBLE_ZERO == (*value) );
}

void CAttributeDouble::getAttributeBinData(DBO_KIND& bType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bType = getKindType();
   bSize = getBinKindSize();
   // Do use the plain representation, double IEEE Intel format already in the correct byte order (little endian)
   pAttribute = static_cast<void*> (value);
}

void CAttributeDouble::setAttributeBinData(const DBO_KIND& bType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( ( getKindType() != bType ) || ( getBinKindSize() != bSize ) )
   {
      setValid(false);
      return;
   }
   // Do use the plain representation already in the correct byte order
   CAttributeGeneric::genCopy(reinterpret_cast<dbo_byte_t*> (value), static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_double_t)), 
      reinterpret_cast<dbo_byte_t*> (pAttribute), bSize);
}

// Binary Access methods
// Do use the intrinsic IEEE or not IEEE representation
void CAttributeDouble::getAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index) const DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getSize();
   CAttributeGeneric::extractAt(oByte, index, reinterpret_cast<dbo_byte_t*> (value), binSize);
}

// Do use the intrinsic IEEE or not IEEE representation
void CAttributeDouble::setAt(const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getSize();
   CAttributeGeneric::insertAt(reinterpret_cast<dbo_byte_t*> (value), binSize, iByte, index);
}

// CopyTo, CopyFrom
// Do use the intrinsic IEEE or not IEEE representation
void CAttributeDouble::copyTo(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize) const DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getSize();
   CAttributeGeneric::genCopy(oByteArray, oSize, reinterpret_cast<dbo_byte_t*> (value), binSize);
}

// Do use the intrinsic IEEE or not IEEE representation
void CAttributeDouble::copyFrom(const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getSize();
   if ( binSize == iSize )
   {
      CAttributeGeneric::genCopy(reinterpret_cast<dbo_byte_t*> (value), binSize, iByteArray, iSize);
   }
}

dbo_double_t* const CAttributeDouble::Alloca() DBO_NOTHROW 
{
   dbo_double_t* Allocated = NULL;
   Allocated = static_cast<dbo_double_t*> (DBO_MALLOC(sizeof(dbo_double_t)));
   if ( DBO_INVALIDP(Allocated) )
   {
      Allocated = NULL;
      return Allocated;
   }
   return Allocated;
}

void CAttributeDouble::Dealloca(dbo_double_t* phost) DBO_NOTHROW 
{
   if (DBO_VALIDP(phost))
   {
      DBO_FREE(phost);
   }
   phost = NULL;
}

NAMESPACE_DBO_CLOSE

