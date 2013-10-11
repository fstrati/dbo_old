/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// The generic attribute base abstract interface class.
// This class defines the generic attribute interface.

#ifndef DBO_ATTRIBUTEGENERIC_H_INCLUDED
#define DBO_ATTRIBUTEGENERIC_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/macros.h"
#include "dbo/attributedef.h"
#include "dbo/dbogendefines.h"
#include "dbo/options.h"

NAMESPACE_DBO_OPEN

// The Abstract Base Class of All Attributes
class CAttributeGeneric
{
   DBO_DEF_ATTR_H;
   DBO_PRI_CLASS_CTOR_H(CAttributeGeneric);

public:
   // Attributes are copy-constructible and assignable
   CAttributeGeneric(const CAttributeGeneric& iOther) DBO_NOTHROW;
   CAttributeGeneric& operator=(const CAttributeGeneric& iOther) DBO_NOTHROW;
protected:
   // To extend functionality of assignment and copy of base class pointers:
   // override the following BuildVirtualCopy in derived classes.
   virtual void buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW { };
   void copyBase(const CAttributeGeneric& iOther) DBO_NOTHROW;

public:
   // explicit Construction/Destruction
   explicit CAttributeGeneric(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW;
   explicit CAttributeGeneric(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW;
   virtual ~CAttributeGeneric() DBO_NOTHROW { };

   DBO_DEF_ATTR_ERR_H;

public:
   // Pure & virtual interface methods ->

   // GET / SET generic methods
   FORCE_INLINE const CAttributeGeneric& get(void) const DBO_NOTHROW 
   {
      return *this;
   };
   virtual void set(const CAttributeGeneric& iOther) DBO_NOTHROW = 0;
   FORCE_INLINE const CAttributeGeneric* const getPtr(void) const DBO_NOTHROW
   {
      return this;
   };
   virtual void setFromPtr(const CAttributeGeneric* const pOther) DBO_NOTHROW = 0;

	// Explicit conversions are to be defined here
   // Strings
   virtual dbo_string_t             getAsString(void) const DBO_NOTHROW = 0;
   virtual void                     setAsString(const dbo_string_t& iStr) DBO_NOTHROW = 0;
   virtual dbo_wstring_t            getAsWString(void) const DBO_NOTHROW = 0;
   virtual void                     setAsWString(const dbo_wstring_t& iWStr) DBO_NOTHROW = 0;
   // Warning: set the size of the input/output c-string first...
   virtual void                     getAsCString(dbo_char_t* oCStr, const size_t iSize) const DBO_NOTHROW = 0;
   virtual void                     setAsCString(const dbo_char_t* const iCStr) DBO_NOTHROW = 0;
   virtual void                     getAsWCString(dbo_wchar_t* oWCStr, const size_t iSize) const DBO_NOTHROW = 0;
   virtual void                     setAsWCString(const dbo_wchar_t* const iWCStr) DBO_NOTHROW = 0;

   virtual dbo_double_t             getAsDouble(void) const DBO_NOTHROW = 0;
   virtual void                     setAsDouble(const dbo_double_t& iDouble) DBO_NOTHROW = 0;

   virtual dbo_int64_t              getAsInt64(void) const DBO_NOTHROW = 0;
   virtual void                     setAsInt64(const dbo_int64_t& iInt64) DBO_NOTHROW = 0;

   virtual dbo_uint64_t             getAsUInt64(void) const DBO_NOTHROW = 0;
   virtual void                     setAsUInt64(const dbo_uint64_t& iUInt64) DBO_NOTHROW = 0;

   // Size has a semantic meaning given by the attribute kind, 
   //    it may be different from the binary size and/or whatever capacity is there
   // Warning, setSize does a reset() on some attributes
   virtual void setSize(const size_t iSize) DBO_NOTHROW 
   {
      _size = iSize;
   };
   virtual void reset() DBO_NOTHROW = 0;
   // Length is the real length of the converted string
   virtual DBO_BIN_KIND_SIZE getLength(void) const DBO_NOTHROW = 0;
   virtual DBO_BIN_KIND_SIZE getWLength(void) const DBO_NOTHROW = 0;

   virtual void emptyValue(void) DBO_NOTHROW = 0;
   virtual bool isEmpty(void) const DBO_NOTHROW = 0;

   // Pure & virtual interface methods <-

public:
   // Binary Serialization ->
   virtual DBO_BIN_KIND_SIZE getBinKindSize(void) const DBO_NOTHROW
   {
      return _binsize;
   };

protected:
   // This is used in all attribute ctor's
   void setBinKindSize(const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW 
   {
      _binsize = iSize;
   };
   // Generic interface
   virtual void getAttributeBinData(DBO_KIND& bType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW = 0;
   virtual void setAttributeBinData(const DBO_KIND& bType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW = 0;
   // Static attributes data
   void getAttributeBinName(DBO_KIND& bNameType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW ;
   void setAttributeBinName(const DBO_KIND& bNameType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW ;
   void getAttrUnitsBinName(DBO_KIND& bUnitsType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW ;
   void setAttrUnitsBinName(const DBO_KIND& bUnitsType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW ;
   void getPropertiesBinData(DBO_KIND& bUnitsType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW ;
   void setPropertiesBinData(const DBO_KIND& bUnitsType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW ;

   // Binary Serialization <-

public:
   // Methods only for binary operations ->

   // Safe access methods
   virtual void getAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index) const DBO_NOTHROW = 0;
   virtual void setAt(const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW = 0;

   // CopyTo, CopyFrom
   virtual void copyTo(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize) const DBO_NOTHROW = 0;
   virtual void copyFrom(const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW = 0;

   // Methods only for binary operations <-

public:
   // Real general methods ->
   FORCE_INLINE size_t getSize(void) const DBO_NOTHROW 
   {
      return _size;
   };
   FORCE_INLINE dbo_uint32_t getIndex(void) const DBO_NOTHROW 
   {
      return _attribute_idx;
   };
   FORCE_INLINE void setIndex(const dbo_uint32_t& index) DBO_NOTHROW 
   {
      _attribute_idx = index;
   };
   FORCE_INLINE const dbo_string_t& getUnits(void) const DBO_NOTHROW 
   {
      return _units;
   };
   FORCE_INLINE void setUnits(const dbo_string_t& iUnitStr) DBO_NOTHROW 
   {
      _units = iUnitStr;
   };
   FORCE_INLINE void setUnits(const dbo_char_t* const iUnitStr) DBO_NOTHROW 
   {
      _units = iUnitStr;
   };
   FORCE_INLINE const dbo_string_t& getAttributeName(void) const DBO_NOTHROW 
   {
      return _attribute_name;
   };
   FORCE_INLINE void setAttributeName(const dbo_string_t& iName) DBO_NOTHROW 
   {
      _attribute_name = iName;
   };
   FORCE_INLINE void setAttributeName(const dbo_char_t* const iName) DBO_NOTHROW 
   {
      _attribute_name = iName;
   };
   FORCE_INLINE bool isValid(void) const DBO_NOTHROW 
   {
      return (1 == _properties.isValid);
   };
   FORCE_INLINE void setValid(const bool bValid) const DBO_NOTHROW 
   {
      if (bValid)
      {
         _properties.isValid = 1;
      } 
      else
      {
         _properties.isValid = 0;
      }
   };
   FORCE_INLINE bool isNull(void) const DBO_NOTHROW 
   {
      return (1 == _properties.isNull);
   };
   FORCE_INLINE void setNull(const bool bNull) const DBO_NOTHROW 
   {
      if (bNull)
      {
         _properties.isNull = 1;
      } 
      else
      {
         _properties.isNull = 0;
      }
   };
   FORCE_INLINE bool isTruncated(void) const DBO_NOTHROW 
   {
      return (1 == _properties.isTruncated);
   };
   FORCE_INLINE void setTruncated(const bool bTruncated) const DBO_NOTHROW 
   {
      if (bTruncated)
      {
         _properties.isTruncated= 1;
      } 
      else
      {
         _properties.isTruncated = 0;
      }
   };
   FORCE_INLINE void setProperties(const dbo_attr_properties_t& properties) const DBO_NOTHROW 
   {
      _properties = properties;
   };
   FORCE_INLINE const dbo_attr_properties_t& getProperties(void) const DBO_NOTHROW 
   {
      return _properties;
   };
   // Real general methods <-

protected:
   // Helpers for binary operations
   static void extractAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index, const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW ;
   static void insertAt(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize, const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW ;
   static void genCopy(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize, const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW ;

// Static properties
private:
   size_t               _size; /* Size whose meaning is dependent on attribute kind */
   DBO_BIN_KIND_SIZE    _binsize; /* Binary Size whose meaning is dependent on attribute kind */
   dbo_string_t         _units; /* Attribute units */
   dbo_string_t         _attribute_name; /* Attribute name */
   dbo_uint32_t         _attribute_idx; /* Attribute index */
   /* bit-field for attribute properties */
   mutable dbo_attr_properties_t _properties;
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_ATTRIBUTEGENERIC_H_INCLUDED) */

