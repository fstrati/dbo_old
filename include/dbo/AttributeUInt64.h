/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// The 64 bits unsigned integer

#ifndef DBO_ATTRIBUTEUINT64_H_INCLUDED
#define DBO_ATTRIBUTEUINT64_H_INCLUDED

#include "dbo/AttributeGeneric.h"

NAMESPACE_DBO_OPEN

class CAttributeUInt64 : public CAttributeGeneric
{
   DBO_DEF_CLASS_H;
   DBO_DEF_ATTR_H;
   DBO_PRI_CLASS_CTOR_H(CAttributeUInt64);

   // make it copyable and assignable
public:
   CAttributeUInt64(const CAttributeUInt64&) DBO_NOTHROW ;
   CAttributeUInt64& operator=(const CAttributeUInt64&) DBO_NOTHROW ;

protected:
   virtual void buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW ;

public:
   // Construction/Destruction
   // Attributes names are at worst encoded in UTF8
   explicit CAttributeUInt64(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW ;
   explicit CAttributeUInt64(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW ;
   explicit CAttributeUInt64(const dbo_uint64_t& iUInt64, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW ;
   explicit CAttributeUInt64(const dbo_uint64_t& iUInt64, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW ;
   virtual ~CAttributeUInt64() DBO_NOTHROW ;

public:
   // Pure & virtual interface methods ->

   // GET / SET generic methods
   virtual void set(const CAttributeGeneric& iOther) DBO_NOTHROW ;
   virtual void setFromPtr(const CAttributeGeneric* const pOther) DBO_NOTHROW ;

   // Explicit conversions are to be defined here
   // Strings
   virtual dbo_string_t        getAsString(void) const DBO_NOTHROW ;
   virtual void                setAsString(const dbo_string_t& iStr) DBO_NOTHROW ;
   virtual dbo_wstring_t       getAsWString(void) const DBO_NOTHROW ;
   virtual void                setAsWString(const dbo_wstring_t& iWStr) DBO_NOTHROW ;
   // Warning: set the size of the input/output c-string first...
   virtual void                getAsCString(dbo_char_t* oCStr, const size_t iSize) const DBO_NOTHROW ;
   virtual void                setAsCString(const dbo_char_t* const iCStr) DBO_NOTHROW ;
   virtual void                getAsWCString(dbo_wchar_t* oWCStr, const size_t iSize) const DBO_NOTHROW ;
   virtual void                setAsWCString(const dbo_wchar_t* const iWCStr) DBO_NOTHROW ;

   virtual dbo_double_t        getAsDouble(void) const DBO_NOTHROW ;
   virtual void                setAsDouble(const dbo_double_t& iDouble) DBO_NOTHROW ;

   virtual dbo_int64_t         getAsInt64(void) const DBO_NOTHROW ;
   virtual void                setAsInt64(const dbo_int64_t& iInt64) DBO_NOTHROW ;

   virtual dbo_uint64_t        getAsUInt64(void) const DBO_NOTHROW ;
   virtual void                setAsUInt64(const dbo_uint64_t& iUInt64) DBO_NOTHROW ;

   // Warning, setSize does invalidate this attribute
   virtual void setSize(const size_t iSize) DBO_NOTHROW ;
   virtual void reset() DBO_NOTHROW ;
   virtual DBO_BIN_KIND_SIZE getLength(void) const DBO_NOTHROW ;
   virtual DBO_BIN_KIND_SIZE getWLength(void) const DBO_NOTHROW ;

   virtual void emptyValue(void) DBO_NOTHROW ;
   virtual bool isEmpty(void) const DBO_NOTHROW ;

   // Pure & virtual interface methods <-

public:
   // Binary Serialization ->
   // virtual const DBO_BIN_KIND_SIZE getBinKindSize(void) const;

protected:
   virtual void getAttributeBinData(DBO_KIND& bType, DBO_BIN_KIND_SIZE& bSize, void*& pAttribute) const DBO_NOTHROW ;
   virtual void setAttributeBinData(const DBO_KIND& bType, const DBO_BIN_KIND_SIZE& bSize, void* pAttribute) DBO_NOTHROW ;

   // Binary Serialization <-

public:
   // Methods only for binary operations ->

   // Safe access methods
   virtual void getAt(dbo_byte_t& oByte, const DBO_BIN_KIND_SIZE& index) const DBO_NOTHROW ;
   virtual void setAt(const dbo_byte_t& iByte, const DBO_BIN_KIND_SIZE& index) DBO_NOTHROW ;

   // CopyTo, CopyFrom
   virtual void copyTo(dbo_byte_t* oByteArray, const DBO_BIN_KIND_SIZE& oSize) const DBO_NOTHROW ;
   virtual void copyFrom(const dbo_byte_t* const iByteArray, const DBO_BIN_KIND_SIZE& iSize) DBO_NOTHROW ;

   // Methods only for binary operations <-

   // Very unsafe method
protected:
   FORCE_INLINE void* getAttributeBinPtr() const DBO_NOTHROW 
   {
      return (static_cast<void*> (value));
   };

protected:
   /* Attribute value */
   dbo_uint64_t* value;

   static dbo_uint64_t* const Alloca() DBO_NOTHROW ;
   static void Dealloca(dbo_uint64_t* phost) DBO_NOTHROW ;
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_ATTRIBUTEUINT64_H_INCLUDED) */

