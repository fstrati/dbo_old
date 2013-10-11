/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

//
// GenericObj.h
// 
// Description: This is the base class of generic dynamic business objects
// 
// List of functionalities to implement:
// 1. Keep all of the attributes interface hidden in all objects derived from this base.
// 2. Add all functionalities (Serialization, Persistence & Instance from RDBMS, etc.. )
//    in a Hierarchy based on this class.
// 

#ifndef DBO_GENERICOBJ_H_INCLUDED
#define DBO_GENERICOBJ_H_INCLUDED

#include <list>
#include <vector>
#include <map>
#include <string>

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/callocators.h"
#include "dbo/macros.h"
#include "dbo/ltstrcmp.h"

NAMESPACE_DBO_OPEN

// forward the attributes ->
class CAttributeGeneric;
// forward the attributes <-

/* max no. of attributes */
#define IDC_MAX_ATTR_NO             (0x000FFFFF)

// the attributes collections
// attribute names are at worst encoded in UTF8
typedef std::map  < dbo_char_t* , CAttributeGeneric*, ltstrcmp , \
                    DBO_STD_ALLOCATOR< std::pair<const dbo_char_t* , CAttributeGeneric* > > > DefAttributeMap;
typedef std::list < CAttributeGeneric* , DBO_STD_ALLOCATOR<CAttributeGeneric*> > DefAttributeList;
typedef std::vector < CAttributeGeneric* , DBO_STD_ALLOCATOR<CAttributeGeneric*> > DefAttributeVector;

class CGenericObj
{
   DBO_DEF_CLASS_H;
   DBO_PRI_CLASS_CTOR_H(CGenericObj);

// Ctor & Dtor
public:
   explicit CGenericObj(const dbo_char_t* const iObjectName);
   explicit CGenericObj(const dbo_string_t& iObjectName);
   virtual ~CGenericObj();

// Copyable & Assignable
public:
   CGenericObj(const CGenericObj& iOther);
   CGenericObj& operator=(const CGenericObj& iOther);

// Helpers for dynamic construction ->
protected:
   void BuildCopyEraseFirst(const CGenericObj& iOther);
   void BuildCopyAddNew(const CGenericObj& iOther);
   void CopyExistingAttributeOnSwitch(CAttributeGeneric* pTo, const CAttributeGeneric* const pFrom) const ;
   void CreateCopyAttributeOnSwitch(CAttributeGeneric* pTo, const CAttributeGeneric* const pFrom) const ;
   void InsertAttributeCopyOnPtr(CAttributeGeneric* pFrom);
   void DeleteAllAttributes(void);
   dbo_char_t* DoMakeAttributeName(const dbo_char_t* const AttribName) const ;
   dbo_char_t* DoMakeAttributeName(const dbo_string_t& AttribName) const ;
// Helpers for dynamic construction <-

// Static attributes interface ->
public:
   FORCE_INLINE const dbo_string_t& getObjectName(void) const
   {
      return _objectname;
   };
   FORCE_INLINE void setObjectName(const dbo_string_t& iObjectName)
   {
      _objectname = iObjectName;
   };
   FORCE_INLINE const dbo_uint32_t& getAttributeCount(void) const
   {
      return _attribute_idx_counter;
   };
// Static attributes interface <-

// Dynamic and Symbolic name resolved attributes get&set interface ->
public:
   void setAttributeValue(const dbo_char_t* const AttribName, const dbo_double_t& value);
   void setAttributeValue(const dbo_char_t* const AttribName, const dbo_int64_t& value);
   void setAttributeValue(const dbo_char_t* const AttribName, const dbo_uint64_t& value);
   void setAttributeValue(const dbo_char_t* const AttribName, const dbo_char_t* const value);
   void setAttributeValue(const dbo_char_t* const AttribName, const dbo_string_t& value);

   void getAttributeValue(const dbo_char_t* const AttribName, dbo_double_t& value) const;
   void getAttributeValue(const dbo_char_t* const AttribName, dbo_int64_t& value) const;
   void getAttributeValue(const dbo_char_t* const AttribName, dbo_uint64_t& value) const;
   void getAttributeValue(const dbo_char_t* const AttribName, dbo_char_t* value, const size_t iSize) const;
   void getAttributeValue(const dbo_char_t* const AttribName, dbo_string_t& value) const;
// Dynamic and Symbolic name resolved attributes interface <-

// InsertAttribute overloads
public:
   void insertAttribute(const dbo_char_t* const AttribName, const dbo_double_t& value);
   void insertAttribute(const dbo_char_t* const AttribName, const dbo_int64_t& value);
   void insertAttribute(const dbo_char_t* const AttribName, const dbo_uint64_t& value);
   void insertAttribute(const dbo_char_t* const AttribName, const dbo_char_t* const value);
   void insertAttribute(const dbo_char_t* const AttribName, const dbo_string_t& value);

// Erasing the attribute
   void deleteAttribute(const dbo_char_t* const AttribName);

// Interface to be protected in all objects of the Hierarchy ->
protected:
   CAttributeGeneric* getAttributeObj(const dbo_char_t* const AttribName) const;
   CAttributeGeneric* getAttributeObj(const dbo_string_t& AttribName) const;
   CAttributeGeneric* getAttributeObj(const dbo_uint32_t index) const;
// Interface to be protected in all objects of the Hierarchy <-

// Aux interface ->
public:
   void getAttributeName(const dbo_uint32_t index, dbo_char_t* const pAttribName, const size_t iSize) const;
   void getAttributeName(const dbo_uint32_t index, dbo_string_t& AttribName) const;
   bool attributeExists(const dbo_char_t* const AttribName) const;
   bool attributeExists(const dbo_string_t& AttribName) const;
   bool attributeExists(const dbo_uint32_t index) const;
   size_t getAttributeSize(const dbo_char_t* const AttribName) const;
   size_t getAttributeSize(const dbo_string_t& AttribName) const;
   size_t getAttributeSize(const dbo_uint32_t index) const;
// Aux interface <-

protected:
   /* map of the Attributes <attribute name, pointer to attribute> */
   DefAttributeMap     AttributesMap;
   /* vector of the Attributes <pointer to attribute> */
   DefAttributeVector  AttributesVec;

   // "Static" Attributes:
protected:
   // the object name
   dbo_string_t _objectname;
   // the attributes index counter
   dbo_uint32_t _attribute_idx_counter;
};

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_GENERICOBJ_H_INCLUDED) */

