/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// Implementation of the common generic attribute methods

#include "dbo/namespace.h"
#include "dbo/callocators.h"

#include "dbo/AttributeGeneric.h"

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_ATTR_KIND(CAttributeGeneric,DBO_KIND_NULL);

// Construction/Destruction
CAttributeGeneric::CAttributeGeneric(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW 
   : _attribute_idx(index), _attribute_name(iName)
{
   _size = DBO_INT_ZERO;
   _units = DBO_DEF_UNITS_STR;
   _last_err = DBO_ATTR_ERR_SUCCESS;
}

CAttributeGeneric::CAttributeGeneric(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW 
   : _attribute_idx(index), _attribute_name(iName)
{
   _size = DBO_INT_ZERO;
   _units = DBO_DEF_UNITS_STR;
   _last_err = DBO_ATTR_ERR_SUCCESS;
}

CAttributeGeneric::CAttributeGeneric(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   copyBase(iOther);
   // Delegate to virtual copy
   buildVirtualCopy(iOther);
}

CAttributeGeneric& CAttributeGeneric::operator=(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   if( this != &iOther )
   {
      copyBase(iOther);
      // Delegate to virtual copy
      buildVirtualCopy(iOther);
   }
   return *this;
}

void CAttributeGeneric::copyBase(const CAttributeGeneric& iOther) DBO_NOTHROW 
{
   // Deep copy
   _size = iOther.getSize();
   _units = iOther.getUnits();
   _attribute_name = iOther.getAttributeName();
   _properties = iOther.getProperties();
   _attribute_idx = iOther.getIndex();
   // Reset errors
   _last_err = DBO_ATTR_ERR_SUCCESS;
}

void CAttributeGeneric::getAttributeBinName(DBO_KIND& bNameType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bNameType = DBO_KIND_ATTNAME;
   // Safe, copy all of the string plus terminator
   bSize = static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_char_t)*(_attribute_name.length() + 1));
   pAttribute = static_cast<void*> (const_cast<dbo_char_t*> (_attribute_name.c_str()));
}

void CAttributeGeneric::setAttributeBinName(const DBO_KIND& bNameType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( DBO_KIND_ATTNAME != bNameType ) // Correctness check
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_KIND);
      return;
   }
   if (DBO_VALIDP(pAttribute))
   {
      // Safe, make a copy
      // TODO: write translation methods also for bSizes...
      dbo_char_t* pTemp = NULL;
      pTemp = (dbo_char_t*) DBO_MALLOC( (size_t) (bSize) * sizeof(dbo_char_t) ); // Terminator is included, see above
      if (DBO_VALIDP(pTemp))
      {
         strncpy(pTemp, reinterpret_cast<dbo_char_t*> (pAttribute), static_cast<size_t> (bSize));
         // ensure the terminator is there
         *(pTemp + static_cast<size_t> (bSize-1)) = DBO_TXT_STDTERM_CHAR;
         _attribute_name = pTemp; // Set the attribute name
         DBO_FREE(pTemp);
      }
      else
      {
         DBO_FREE(pTemp);
         setValid(false);
         setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
         return;
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
      return;
   }
}

void CAttributeGeneric::getAttrUnitsBinName(DBO_KIND& bUnitsType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bUnitsType = DBO_KIND_ATTUNITS;
   // Safe, copy all of the string plus terminator
   bSize = static_cast<DBO_BIN_KIND_SIZE> (sizeof(dbo_char_t)*(_units.length() + 1));
   pAttribute = static_cast<void*> (const_cast<dbo_char_t*> (_units.c_str()));
}

void CAttributeGeneric::setAttrUnitsBinName(const DBO_KIND& bUnitsType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( DBO_KIND_ATTUNITS != bUnitsType ) // Correctness check
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_KIND);
      return;
   }
   if (DBO_VALIDP(pAttribute))
   {
      // Safe, make a copy
      // TODO: write translation methods also for bSizes...
      dbo_char_t* pTemp = NULL;
      pTemp = (dbo_char_t*) DBO_MALLOC( (size_t) (bSize) * sizeof(dbo_char_t) ); // Terminator is included, see above
      if (DBO_VALIDP(pTemp))
      {
         strncpy(pTemp, reinterpret_cast<dbo_char_t*> (pAttribute), static_cast<size_t> (bSize));
         // ensure the terminator is there
         *(pTemp + static_cast<size_t> (bSize-1)) = DBO_TXT_STDTERM_CHAR;
         _units = pTemp; // Set the units name
         DBO_FREE(pTemp);
      }
      else
      {
         DBO_FREE(pTemp);
         setValid(false);
         setLastError(DBO_ATTR_ERR_OUT_OF_MEMORY);
         return;
      }
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
      return;
   }
}

void CAttributeGeneric::getPropertiesBinData(DBO_KIND& bUnitsType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW 
{
   bUnitsType = DBO_KIND_ATTPROPS;
   bSize = sizeof(dbo_attr_properties_t);
   pAttribute = static_cast<void*> (&_properties);
}

void CAttributeGeneric::setPropertiesBinData(const DBO_KIND& bUnitsType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW 
{
   if ( DBO_KIND_ATTPROPS != bUnitsType ) // Correctness check
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_KIND);
      return;
   }
   if (DBO_VALIDP(pAttribute))
   {
      // Safe, make a copy
      // TODO: write translation methods also for bSizes...
      dbo_attr_properties_t properties;
      genCopy(reinterpret_cast<dbo_byte_t*> (&properties), sizeof(dbo_attr_properties_t), \
               reinterpret_cast<dbo_byte_t*> (pAttribute), static_cast<size_t> (bSize));
      setProperties(properties);
   }
   else
   {
      setValid(false);
      setLastError(DBO_ATTR_ERR_INVALID_PTR);
      return;
   }
}

void CAttributeGeneric::extractAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index, const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
{
   if (DBO_VALIDP(iByteArray))
   {
      if ( (0 <= index) && (index < iSize) )
      {
         oByte = *(iByteArray + index);
      }
   }
}

void CAttributeGeneric::insertAt(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize, const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW 
{
   if (DBO_VALIDP(oByteArray))
   {
      if ( (0 <= index) && (index < oSize) )
      {
         *( oByteArray + index) = iByte;
      }
   }
}

void CAttributeGeneric::genCopy(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize, const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
{
   if (DBO_VALIDP(iByteArray) && DBO_VALIDP(oByteArray))
   {
      if ( (oSize > 0) && ( oSize <= iSize ) )
      {
         for (size_t k = 0; k < oSize; k++)
         {
            *(oByteArray + k) = *(iByteArray + k);
         }
      }
      else if ( oSize > iSize )
      {
         for (size_t k = 0; k < iSize; k++)
         {
            *(oByteArray + k) = *(iByteArray + k);
         }
      }
   }
}

NAMESPACE_DBO_CLOSE


