/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// The c-style String Attribute

#ifndef DBO_ATTRIBUTECSTRING_H_INCLUDED
#define DBO_ATTRIBUTECSTRING_H_INCLUDED

#include "dbo/AttributeGeneric.h"

NAMESPACE_DBO_OPEN

class CAttributeCString : public CAttributeGeneric
{
   DBO_DEF_ATTR_H;
   DBO_PRI_CLASS_CTOR_H(CAttributeCString);

   // make it copyable and assignable
public:
   CAttributeCString(const CAttributeCString&) DBO_NOTHROW ;
   CAttributeCString& operator=(const CAttributeCString&) DBO_NOTHROW ;

protected:
   virtual void buildVirtualCopy(const CAttributeGeneric& iOther) DBO_NOTHROW ;

public:
   // Construction/Destruction
   // Attributes names are at worst encoded in UTF8
   explicit CAttributeCString(const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW ;
   explicit CAttributeCString(const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW ;
   explicit CAttributeCString(const dbo_string_t& iStr, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW ;
   explicit CAttributeCString(const dbo_char_t* const iCStr, const dbo_uint32_t& index, const dbo_char_t* const iName) DBO_NOTHROW ;
   explicit CAttributeCString(const dbo_string_t& iStr, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW ;
   explicit CAttributeCString(const dbo_char_t* const iCStr, const dbo_uint32_t& index, const dbo_string_t& iName) DBO_NOTHROW ;
   virtual ~CAttributeCString() DBO_NOTHROW ;

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

   // Warning, setSize does a Reset() on this attribute
   virtual void setSize(const size_t iSize) DBO_NOTHROW ;
   virtual void reset() DBO_NOTHROW ;
   virtual DBO_BIN_KIND_SIZE getLength(void) const DBO_NOTHROW ;
   virtual DBO_BIN_KIND_SIZE getWLength(void) const  DBO_NOTHROW ;

   virtual void emptyValue(void) DBO_NOTHROW ;
   virtual bool isEmpty(void) const DBO_NOTHROW ;

   // Pure & virtual interface methods <-

public:
   // Binary Serialization ->
   virtual DBO_BIN_KIND_SIZE getBinKindSize(void) const DBO_NOTHROW ;

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
   // Attribute value
   dbo_char_t* value;

   // Allocation and others
   static dbo_char_t* const Alloca(const size_t iSize) DBO_NOTHROW ;
   static void Dealloca(dbo_char_t* phost) DBO_NOTHROW ;
   static size_t CheckSize(const size_t iSize) DBO_NOTHROW ;
   static void ZeroArray(dbo_char_t* const cArray, const size_t& iSize) DBO_NOTHROW ;

   // Array methods
   void AllocateArray(const dbo_char_t* const cArray, const size_t& newSize) DBO_NOTHROW ;
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_ATTRIBUTECSTRING_H_INCLUDED) */


