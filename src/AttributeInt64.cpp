/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// Implementation of the 64 bits signed integer

#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cmath>

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/AttributeInt64.h"

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_ATTR_KIND(CAttributeInt64,DBO_KIND_INT64);

// Construction/Destruction

CAttributeInt64::CAttributeInt64(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_int64_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_int64_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_INT_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeInt64::CAttributeInt64(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_int64_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_int64_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_INT_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeInt64::CAttributeInt64(const dbo_int64_t& iInt64, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_int64_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_int64_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = iInt64;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeInt64::CAttributeInt64(const dbo_int64_t& iInt64, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   CAttributeGeneric::setSize(sizeof(dbo_int64_t));
   CAttributeGeneric::setBinKindSize(static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_int64_t)));

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = iInt64;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

CAttributeInt64::~CAttributeInt64() DBO_NOTHROW 
{
   Dealloca(value);
}

// Copyable and assignable
CAttributeInt64::CAttributeInt64(const CAttributeInt64& iOther) DBO_NOTHROW 
{
   // Do copy the base:
   CAttributeGeneric::copyBase( iOther );
   // Set the values...
   this->set(iOther.get());
}

CAttributeInt64& CAttributeInt64::operator=(const CAttributeInt64& iOther) DBO_NOTHROW 
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

void CAttributeInt64::buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   // Set the values...
   this->set(iOther.get());
}

// GET / SET generic methods
void CAttributeInt64::set(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) )
   {
      *value = iOther.getAsInt64();
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeInt64::setFromPtr(const CAttributeGeneric* const pOther) DBO_NOTHROW 
{
   if (DBO_VALIDP(value) && DBO_VALIDP(pOther))
   {
      *value = pOther->getAsInt64();
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Explicit conversions
dbo_string_t CAttributeInt64::getAsString(void) const DBO_NOTHROW 
{
   dbo_string_t str_result = DBO_TXT_NULL_TEXT;
   if (DBO_VALIDP(value))
   {
      dbo_char_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_INT64STRINGFMT, (*value));
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

void CAttributeInt64::setAsString(const dbo_string_t& iStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_int64_t> (strtol(iStr.c_str(), NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_wstring_t CAttributeInt64::getAsWString(void) const DBO_NOTHROW 
{
   dbo_wstring_t str_result = DBO_TXT_NULL_TEXT_L;
   if (DBO_VALIDP(value))
   {
      dbo_wchar_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snwprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_INT64STRINGFMT_L, (*value));
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

void CAttributeInt64::setAsWString(const dbo_wstring_t& iWStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_int64_t> (wcstol(iWStr.c_str(), NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeInt64::getAsCString(dbo_char_t* oCStr, const size_t iSize) const DBO_NOTHROW  
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(oCStr) && (iSize > 0) )
   {
      int iRes = snprintf(oCStr, iSize, DBO_TXT_ATTR_INT64STRINGFMT, (*value));
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

void CAttributeInt64::setAsCString(const dbo_char_t* const iCStr) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(iCStr) )
   {
      *value = static_cast<dbo_int64_t> (strtol(iCStr, NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeInt64::getAsWCString(dbo_wchar_t* oWCStr, const size_t iSize) const DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(oWCStr) && (iSize > 0) )
   {
      int iRes = snwprintf(oWCStr, iSize, DBO_TXT_ATTR_INT64STRINGFMT_L, (*value));
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

void CAttributeInt64::setAsWCString(const dbo_wchar_t* const iWCStr) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && DBO_VALIDP(iWCStr) )
   {
      *value = static_cast<dbo_int64_t> (wcstol(iWCStr, NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_double_t CAttributeInt64::getAsDouble(void) const DBO_NOTHROW 
{
   dbo_double_t dret = DBO_DBLE_ZERO;
   if (DBO_VALIDP(value))
   {
      return (static_cast<dbo_double_t> (*value));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return dret;
}

void CAttributeInt64::setAsDouble(const dbo_double_t& iDouble) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_int64_t> (iDouble);
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_int64_t CAttributeInt64::getAsInt64(void) const DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      return *value;
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return DBO_INT_ZERO;
}

void CAttributeInt64::setAsInt64(const dbo_int64_t& iInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = iInt64;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_uint64_t CAttributeInt64::getAsUInt64(void) const DBO_NOTHROW 
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

void CAttributeInt64::setAsUInt64(const dbo_uint64_t& iUInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      *value = static_cast<dbo_int64_t> (iUInt64);
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Warning, setSize does invalidate this attribute
void CAttributeInt64::setSize(const size_t iSize) DBO_NOTHROW 
{
   setValid(false);
   setLastError(DBO_ATTR_ERR_INVALID_OP);
}

void CAttributeInt64::reset() DBO_NOTHROW 
{
   Dealloca(value);

   value = Alloca();

   if ( DBO_VALIDP(value) )
   {
      *value = DBO_INT_ZERO;
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
   }
}

DBO_BIN_KIND_SIZE CAttributeInt64::getLength(void) const DBO_NOTHROW 
{
   // Convert into a string and get the length
   dbo_string_t res = getAsString();
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (res.size());
   return ulret;
}

DBO_BIN_KIND_SIZE CAttributeInt64::getWLength(void) const DBO_NOTHROW 
{
   // Convert into a string and get the length
   dbo_wstring_t res = getAsWString();
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (res.size());
   return ulret;
}

void CAttributeInt64::emptyValue(void) DBO_NOTHROW 
{
   DBO_DEF_EMPTYVALUE(value,DBO_INT_ZERO);
}

bool CAttributeInt64::isEmpty(void) const DBO_NOTHROW 
{
   if (DBO_INVALIDP(value) || isNull())
   {
      return true;
   }
   return ( DBO_INT_ZERO == (*value) );
}

void CAttributeInt64::getAttributeBinData(DBO_KIND& bType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bType = getKindType();
   bSize = getBinKindSize();
   pAttribute = static_cast<void*> (value);
}

void CAttributeInt64::setAttributeBinData(const DBO_KIND& bType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( ( getKindType() != bType ) || ( getBinKindSize() != bSize ) )
   {
      setValid(false);
      return;
   }
   CAttributeGeneric::genCopy(reinterpret_cast<dbo_byte_t*> (value), static_cast<size_t> (bSize), 
      reinterpret_cast<dbo_byte_t*> (pAttribute), static_cast<size_t> (bSize));
}

// Binary Access methods
void CAttributeInt64::getAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index) const DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getBinKindSize();
   CAttributeGeneric::extractAt(oByte, index, reinterpret_cast<dbo_byte_t*> (value), binSize);
}

void CAttributeInt64::setAt(const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getBinKindSize();
   CAttributeGeneric::insertAt(reinterpret_cast<dbo_byte_t*> (value), binSize, iByte, index);
}

// CopyTo, CopyFrom
void CAttributeInt64::copyTo(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize) const DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getBinKindSize();
   CAttributeGeneric::genCopy(oByteArray, oSize, reinterpret_cast<dbo_byte_t*> (value), binSize);
}

void CAttributeInt64::copyFrom(const dbo_byte_t* iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE binSize = getBinKindSize();
   if ( binSize == iSize )
   {
      CAttributeGeneric::genCopy(reinterpret_cast<dbo_byte_t*> (value), binSize, iByteArray, iSize);
   }
}

dbo_int64_t* const CAttributeInt64::Alloca() DBO_NOTHROW 
{
   dbo_int64_t* Allocated = NULL;
   Allocated = static_cast<dbo_int64_t*> (DBO_MALLOC(sizeof(dbo_int64_t)));
   if ( DBO_INVALIDP(Allocated) )
   {
      Allocated = NULL;
      return Allocated;
   }
   return Allocated;
}

void CAttributeInt64::Dealloca(dbo_int64_t* phost) DBO_NOTHROW 
{
   if (DBO_VALIDP(phost))
   {
      DBO_FREE(phost);
   }
   phost = NULL;
}

NAMESPACE_DBO_CLOSE


