/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// CAttributeCString: implementation of the c-style String Attribute
// 
// For this attribute size() (i.e. capacity) is different from length() and binary_size()
// 

#include <cstdio>
//#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cerrno>

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/AttributeCString.h"

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_CLASS_SRC(CAttributeCString);
DBO_DEF_ATTR_KIND(CAttributeCString,DBO_KIND_CSTRING);

// helpers for copy
static void safeCopy(dbo_char_t* const copyto, const dbo_char_t* const copyfrom, const size_t& iSize) DBO_NOTHROW 
{
   if (DBO_VALIDP(copyto) && DBO_VALIDP(copyfrom))
   {
      strncpy(copyto, copyfrom, iSize);
      // Add terminator
      *(copyto + iSize) = DBO_TXT_STDTERM_CHAR;
   }
}

static void forCopy(dbo_char_t* const copyto, const dbo_char_t* const copyfrom, const size_t& iSize) DBO_NOTHROW 
{
   if (DBO_VALIDP(copyto) && DBO_VALIDP(copyfrom))
   {
      for (size_t k = DBO_INT_ZERO; k < iSize; k++)
      {
          *(copyto + k) = *(copyfrom + k);
      }
      // Add terminator
      *(copyto + iSize) = DBO_TXT_STDTERM_CHAR;
   }
}

// Fixed policy resize for small strings
static size_t policyResize(const size_t oldSize, const size_t newSize) DBO_NOTHROW 
{
   size_t diffSize = (newSize - oldSize);
   if(DBO_INT_ZERO >  diffSize)
   {
      return oldSize;
   }
   if(DBO_INT_ZERO == diffSize)
   {
      return newSize;
   }
   size_t nLogSize = static_cast<size_t> (log10(static_cast<dbo_double_t> (oldSize+1)));
   // small strings fixed fraction increase in capacity...
   size_t retSize = newSize;
   if(nLogSize <= DBO_TXT_SMALL_STRING_RESIZE)
   {
       retSize = newSize + static_cast<size_t> (DBO_TXT_SMALL_STRING_RESIZE_FRAC * (static_cast<dbo_double_t> (diffSize)));
   }
   else
   {
       retSize = newSize;
   }
   // Defensive check
   if ( retSize < newSize )
   {
      retSize = newSize;
   }
   return retSize;
}

// Construction/Destruction

CAttributeCString::CAttributeCString(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   setSize(DBO_TXT_STR_DEFAULT_LENGTH);
   ZeroArray(value,getSize());
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::CAttributeCString(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   setSize(DBO_TXT_STR_DEFAULT_LENGTH);
   ZeroArray(value,getSize());
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::CAttributeCString(const dbo_string_t& iStr, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   AllocateArray(iStr.c_str(),iStr.size());
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::CAttributeCString(const dbo_char_t* iCStr, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   AllocateArray(iCStr,strlen(iCStr));
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::CAttributeCString(const dbo_string_t& iStr, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   AllocateArray(iStr.c_str(),iStr.size());
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::CAttributeCString(const dbo_char_t* iCStr, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : CAttributeGeneric(index, iName)
{
   value = NULL;
   AllocateArray(iCStr,strlen(iCStr));
   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

CAttributeCString::~CAttributeCString() DBO_NOTHROW 
{
   Dealloca(value);
}

// Copyable and assignable
CAttributeCString::CAttributeCString(const CAttributeCString& iOther) DBO_NOTHROW 
{
   // Do copy the base:
   CAttributeGeneric::copyBase( iOther );
   // Set the values...
   this->set(iOther.get());
}

CAttributeCString& CAttributeCString::operator=(const CAttributeCString& iOther) DBO_NOTHROW 
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

void CAttributeCString::buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
    // Set the values...
   this->set(iOther.get());
}

// GET / SET generic methods
void CAttributeCString::set(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      size_t iOtherSize = iOther.getSize();

      if ( getSize() >= iOtherSize )
      {
         iOther.getAsCString(value, iOtherSize);
      }
      else
      {
         setSize(iOtherSize);
         iOther.getAsCString(value, getSize());
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeCString::setFromPtr(const CAttributeGeneric* const pOther) DBO_NOTHROW 
{
   if (DBO_VALIDP(pOther) && DBO_VALIDP(value))
   {
      size_t iOtherSize = pOther->getSize();

      if ( getSize() >= iOtherSize )
      {
         pOther->getAsCString(value, iOtherSize);
      }
      else
      {
         setSize(iOtherSize);
         pOther->getAsCString(value, getSize());
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Explicit conversions
dbo_string_t CAttributeCString::getAsString(void) const DBO_NOTHROW 
{
   dbo_string_t str_result(value);
   return str_result;
}

void CAttributeCString::setAsString(const dbo_string_t& iStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      size_t iStrSize = iStr.size();
      if ( iStrSize <= getSize() )
      {
          safeCopy(value, iStr.c_str(), iStrSize);
      }
      else
      {
          AllocateArray(iStr.c_str(), iStrSize);
      }
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_wstring_t CAttributeCString::getAsWString(void) const DBO_NOTHROW 
{
   dbo_wstring_t res = DBO_TXT_NULL_TEXT_L;
   if (DBO_VALIDP(value))
   {
#if defined(_MSC_VER)
      size_t iCount = getSize() + sizeof(dbo_char_t);
      // Use current locale to convert the string
      // Determine first the converted string length
      size_t resCount = mbstowcs(NULL, value, iCount);
      // If mbstowcs encounters an invalid multi-byte character, it returns –1
      if ( resCount != ((size_t) -1) )
      {
         res.resize(resCount+1);
         size_t result = mbstowcs(&res[0], value, iCount);
         // Ensure terminator is there
         res[resCount] = DBO_TXT_STDTERM_CHAR_L;
         // If mbstowcs successfully converts the source string, 
         // it returns the number of converted multi-byte characters. (result).
         // TODO: result = number of bytes or number of multi-byte chars ?
      } 
      else
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
#else
      0;
#endif // _MSC_VER
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return res;
}

void CAttributeCString::setAsWString(const dbo_wstring_t& iWStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
#if defined(_MSC_VER)
      size_t iCount = iWStr.size() + sizeof(dbo_wchar_t);
      // Use current locale to convert the string
      // Determine first the converted string length
      size_t resCount = wcstombs(NULL, &iWStr[0], iCount);
      // If wcstombs encounters an invalid wide character, it returns –1
      if ( resCount != ((size_t) -1) )
      {
         setSize(resCount+1);
         size_t result = DBO_INT_ZERO;
         // Ensure we have enough space
         if ( getSize() >= resCount )
         {
            result = wcstombs(value, &iWStr[0], iCount);
            // Ensure terminator is there
            value[getSize()] = DBO_TXT_STDTERM_CHAR;
         }
         else
         {
            result = wcstombs(value, &iWStr[0], getSize());
            // Ensure terminator is there
            value[getSize()] = DBO_TXT_STDTERM_CHAR;
            setValid(false);
            setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
         }
         // If wcstombs successfully converts to the multi-byte string, 
         // it returns the number of bytes written into the multi-byte output string, 
         // excluding the terminating NULL (if any). (result).
      } 
      else
      {
         setValid(false);
         setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
      }
#else
      0;
#endif // _MSC_VER
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeCString::getAsCString(dbo_char_t* oCStr, const size_t iSize) const DBO_NOTHROW 
{
   if(DBO_VALIDP(oCStr) && DBO_VALIDP(value))
   {
      if (iSize < getSize())
      {
         safeCopy(oCStr, value, iSize);
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
      else
      {
         safeCopy(oCStr, value, getSize());
      }
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeCString::setAsCString(const dbo_char_t* const iCStr) DBO_NOTHROW 
{
   if(DBO_VALIDP(iCStr) && DBO_VALIDP(value))
   {
      size_t iSize = strlen(iCStr);
      if ( iSize <= getSize() )
      {
         safeCopy(value, iCStr, iSize);
      }
      else
      {
         setSize(iSize);
         safeCopy(value, iCStr, getSize());
      }
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeCString::getAsWCString(dbo_wchar_t* oWCStr, const size_t iSize) const DBO_NOTHROW 
{
   if (DBO_VALIDP(value) && DBO_VALIDP(oWCStr))
   {
#if defined(_MSC_VER)
      size_t iCount = getSize() + sizeof(dbo_char_t);
      // Use current locale to convert the string
      // Determine first the converted string length
      size_t resCount = mbstowcs(NULL, value, iCount);
      // If mbstowcs encounters an invalid multi-byte character, it returns –1
      if ( resCount != ((size_t) -1) )
      {
         size_t result = DBO_INT_ZERO;
         if ( resCount <= iSize )
         {
            result = mbstowcs(oWCStr, value, iCount);
            // Ensure terminator is there
            oWCStr[resCount] = DBO_TXT_STDTERM_CHAR_L;
         } 
         else
         {
            // TODO: using input iSize...
            result = mbstowcs(oWCStr, value, iSize);
            // Ensure terminator is there
            oWCStr[iSize] = DBO_TXT_STDTERM_CHAR_L;
            setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
         }
         // If mbstowcs successfully converts the source string, 
         // it returns the number of converted multi-byte characters. (result).
         // TODO: result = number of bytes or number of multi-byte chars ?
      } 
      else
      {
         setLastError(DBO_ATTR_ERR_STR_GET_TRUNCATED);
      }
#else
      0;
#endif // _MSC_VER
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

void CAttributeCString::setAsWCString(const dbo_wchar_t* const iWCStr) DBO_NOTHROW 
{
   if (DBO_VALIDP(value) && DBO_VALIDP(iWCStr))
   {
#if defined(_MSC_VER)
      size_t iCount = wcslen(iWCStr) + sizeof(dbo_wchar_t);
      // Use current locale to convert the string
      // Determine first the converted string length
      size_t resCount = wcstombs(NULL, iWCStr, iCount);
      // If wcstombs encounters an invalid wide character, it returns –1
      if ( resCount != ((size_t) -1) )
      {
         setSize(resCount+1);
         size_t result = DBO_INT_ZERO;
         // Ensure we have enough space
         if ( getSize() >= resCount )
         {
            result = wcstombs(value, iWCStr, iCount);
            // Ensure terminator is there
            value[getSize()] = DBO_TXT_STDTERM_CHAR;
         }
         else
         {
            result = wcstombs(value, iWCStr, getSize());
            // Ensure terminator is there
            value[getSize()] = DBO_TXT_STDTERM_CHAR;
            setValid(false);
            setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
         }
         // If wcstombs successfully converts to the multi-byte string, 
         // it returns the number of bytes written into the multi-byte output string, 
         // excluding the terminating NULL (if any). (result).
      } 
      else
      {
         setValid(false);
         setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
      }
#else
      0;
#endif // _MSC_VER
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_double_t CAttributeCString::getAsDouble(void) const DBO_NOTHROW 
{
   dbo_double_t dret = DBO_DBLE_ZERO;
   if (DBO_VALIDP(value))
   {
      dret = static_cast<dbo_double_t> (strtod(value, NULL));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return dret;
}

void CAttributeCString::setAsDouble(const dbo_double_t& iDouble) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      dbo_char_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_DOUBLESTRINGFMT, iDouble);
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
      }
      cconv[DBO_TXT_ATTR_CONVSTRINGSIZE-1] = DBO_TXT_STDTERM_CHAR;
      setSize(strlen(cconv));
      safeCopy(value,cconv,getSize());
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_int64_t CAttributeCString::getAsInt64(void) const DBO_NOTHROW 
{
   dbo_int64_t lret = DBO_INT_ZERO;
   if (DBO_VALIDP(value))
   {
      lret = static_cast<dbo_int64_t> (strtol(value, NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return lret;
}

void CAttributeCString::setAsInt64(const dbo_int64_t& iInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      dbo_char_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_INT64STRINGFMT, iInt64);
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
      }
      cconv[DBO_TXT_ATTR_CONVSTRINGSIZE-1] = DBO_TXT_STDTERM_CHAR;
      setSize(strlen(cconv));
      safeCopy(value,cconv,getSize());
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

dbo_uint64_t CAttributeCString::getAsUInt64(void) const DBO_NOTHROW 
{
   dbo_uint64_t ulret = DBO_INT_ZERO;
   if (DBO_VALIDP(value))
   {
      ulret = static_cast<dbo_uint64_t> (strtoul(value, NULL, DBO_INT_CONVBASE));
   }
   else
   {
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
   return ulret;
}

void CAttributeCString::setAsUInt64(const dbo_uint64_t& iUInt64) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      dbo_char_t cconv[DBO_TXT_ATTR_CONVSTRINGSIZE];
      int iRes = snprintf(cconv, DBO_TXT_ATTR_CONVSTRINGSIZE-1, DBO_TXT_ATTR_INT64STRINGFMT, iUInt64);
      if (iRes < DBO_INT_ZERO)
      {
         setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
      }
      cconv[DBO_TXT_ATTR_CONVSTRINGSIZE-1] = DBO_TXT_STDTERM_CHAR;
      setSize(strlen(cconv));
      safeCopy(value,cconv,getSize());
      if (DBO_VALIDP(value))
      {
         DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
         CAttributeGeneric::setBinKindSize(binSize);
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
   }
}

// Warning, setSize does a reset() on this attribute
void CAttributeCString::setSize(const size_t iSize) DBO_NOTHROW 
{
   AllocateArray(NULL, iSize);
}

void CAttributeCString::reset() DBO_NOTHROW 
{
   setSize(DBO_TXT_STR_DEFAULT_LENGTH);
}

DBO_BIN_KIND_SIZE CAttributeCString::getLength(void) const DBO_NOTHROW 
{
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (strlen(value));
   return ulret;
}

DBO_BIN_KIND_SIZE CAttributeCString::getWLength(void) const DBO_NOTHROW 
{
   // Convert into a string and get the length
   dbo_wstring_t res = getAsWString();
   DBO_BIN_KIND_SIZE ulret = static_cast<DBO_BIN_KIND_SIZE> (res.size());
   return ulret;
}

void CAttributeCString::emptyValue(void) DBO_NOTHROW 
{
   if (DBO_VALIDP(value))
   {
      ZeroArray(value, getSize());
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_OP);
   }
}

bool CAttributeCString::isEmpty(void) const DBO_NOTHROW 
{
   if (DBO_INVALIDP(value) || isNull())
      return true;
   return ( strcmp(value, DBO_TXT_NULL_TEXT) == DBO_INT_ZERO );
}

DBO_BIN_KIND_SIZE CAttributeCString::getBinKindSize(void) const DBO_NOTHROW 
{
   // return the current bin size + terminator
   return static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
}

void CAttributeCString::getAttributeBinData(DBO_KIND& bType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bType = getKindType();
   bSize = getBinKindSize();
   pAttribute = static_cast<void*> (value);
}

void CAttributeCString::setAttributeBinData(const DBO_KIND& bType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( getKindType() != bType )
   {
      setValid(false);
      return;
   }
   AllocateArray(reinterpret_cast<const dbo_char_t* const> (pAttribute), static_cast<size_t> (bSize));
}

// Binary Access methods
void CAttributeCString::getAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index) const DBO_NOTHROW 
{
   CAttributeGeneric::extractAt(oByte, index, reinterpret_cast<dbo_byte_t*> (value), static_cast<DBO_BIN_KIND_SIZE> (getSize()));
}

void CAttributeCString::setAt(const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW 
{
   CAttributeGeneric::insertAt(reinterpret_cast<dbo_byte_t*> (value), static_cast<DBO_BIN_KIND_SIZE> (getSize()), iByte, index);
}

// CopyTo, CopyFrom
void CAttributeCString::copyTo(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize) const DBO_NOTHROW 
{
   CAttributeGeneric::genCopy(oByteArray, oSize, reinterpret_cast<dbo_byte_t*> (value), static_cast<DBO_BIN_KIND_SIZE> (getSize()));
}

void CAttributeCString::copyFrom(const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
{
   if ( DBO_VALIDP(value) && (iSize > DBO_INT_ZERO) && (iSize <= (static_cast<DBO_BIN_KIND_SIZE> (getSize()))) )
   {
      CAttributeGeneric::genCopy(reinterpret_cast<dbo_byte_t*> (value), static_cast<DBO_BIN_KIND_SIZE> (getSize()), iByteArray, iSize);
      // Add a terminator anyway...
      *(value + iSize) = DBO_TXT_STDTERM_CHAR;
   }
   else if ( DBO_INVALIDP(value) || (iSize > (static_cast<DBO_BIN_KIND_SIZE> (getSize()))) ) // Allocate, Allocate will add a terminator
   {
      AllocateArray(reinterpret_cast<const dbo_char_t* const> (iByteArray), static_cast<size_t> (iSize));
   }
}

dbo_char_t* const CAttributeCString::Alloca(const size_t iSize) DBO_NOTHROW 
{
   dbo_char_t* Allocated = NULL;
   // current size + terminator
   Allocated = static_cast<dbo_char_t*> (DBO_MALLOC( (iSize * sizeof(dbo_char_t) + sizeof(dbo_char_t)) ));
   if ( DBO_INVALIDP(Allocated) )
   {
      Allocated = NULL;
      return Allocated;
   }
   return Allocated;
}

size_t CAttributeCString::CheckSize(const size_t iSize) DBO_NOTHROW 
{
   size_t newSize = iSize;
   if ( (DBO_TXT_STRING_GENERAL_LIMIT <= iSize) )
   {
      // Quietly limit the size...
      newSize = DBO_TXT_STRING_GENERAL_LIMIT;
   }
   return newSize;
}

void CAttributeCString::AllocateArray(const dbo_char_t* const cArray, const size_t& newSize) DBO_NOTHROW 
{
   size_t newCorrSize = newSize;
   if ( DBO_INVALIDP(value) || (newSize > getSize()) )
   {
      // TODO: not used
      // newCorrSize = policyResize(getSize(), newSize);
      newCorrSize = newSize;
   }
   size_t validSize = CheckSize(newCorrSize);
   if ( validSize < newSize )
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_STR_SET_TRUNCATED);
   }

   if ( DBO_INVALIDP(value) )
   {
      CAttributeGeneric::setSize(validSize);
      value = Alloca(getSize());
   }
   else // DBO_VALIDP(value)
   {
      if ( getSize() < validSize )
      {
         Dealloca(value);
         CAttributeGeneric::setSize(validSize);
         value = Alloca(getSize());
      }
   }

   if ( DBO_INVALIDP(value) )
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
      return;
   }
   
   if (DBO_VALIDP(cArray))
   {
      size_t cArrayLen = strlen(cArray);
      safeCopy(value, cArray, ((getSize()<cArrayLen) ? getSize() : cArrayLen));
   }

   if (DBO_VALIDP(value))
   {
      DBO_BIN_KIND_SIZE binSize = static_cast<DBO_BIN_KIND_SIZE> (strlen(value) + 1);
      CAttributeGeneric::setBinKindSize(binSize);
   }
}

void CAttributeCString::ZeroArray(dbo_char_t* const cArray, const size_t& iSize) DBO_NOTHROW 
{
   if (DBO_VALIDP(cArray) && (DBO_INT_ZERO < iSize))
   {
      for(size_t index = DBO_INT_ZERO; index < iSize; index++)
      {
          *(cArray + index) = DBO_TXT_STDTERM_CHAR;
      }
      *(cArray + iSize) = DBO_TXT_STDTERM_CHAR;
   }
}

void CAttributeCString::Dealloca(dbo_char_t* phost) DBO_NOTHROW 
{
   if (DBO_VALIDP(phost))
   {
      DBO_FREE(phost);
   }
   phost = NULL;
}

NAMESPACE_DBO_CLOSE

