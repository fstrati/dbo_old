/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

//
// GenericObj.cpp
//
// Implementation of the Generic Object Interface
// 
//

#include <algorithm>

#include "dbo/namespace.h"

#include "dbo/typesdef.h"
#include "dbo/macros.h"
#include "dbo/callocators.h"
#include "dbo/dbogendefines.h"

#include "dbo/GenericObj.h"

// Attributes... ->
#include "dbo/AttributeGeneric.h"
#include "dbo/AttributeDouble.h"
#include "dbo/AttributeInt64.h"
#include "dbo/AttributeUInt64.h"
#include "dbo/AttributeCString.h"
// Attributes... <-

NAMESPACE_DBO_OPEN

using namespace std;

DBO_DEF_CLASS_SRC(CGenericObj);

// DO NOT USE THIS...
// CGenericObj construction, destruction
/*
CGenericObj::CGenericObj()
{
   // the object name
   _objectname = "CGenericObj";
   // the attribute index counter
   _attribute_idx_counter = DBO_INT_ZERO;
   // collections
   AttributesMap.clear();
   AttributesVec.clear();
   DBO_ERROR_THROW_TMP;
}
*/

CGenericObj::CGenericObj(const dbo_char_t* const iObjectName)
   : _objectname(iObjectName)
{
    // the attribute index counter
    _attribute_idx_counter = DBO_INT_ZERO;
    // collections
    AttributesMap.clear();
    AttributesVec.clear();
}

CGenericObj::CGenericObj(const dbo_string_t& iObjectName)
   : _objectname(iObjectName)
{
   // the attribute index counter
   _attribute_idx_counter = DBO_INT_ZERO;
   // collections
   AttributesMap.clear();
   AttributesVec.clear();
}

// Build object by deleting all previous attributes and nested objects
CGenericObj::CGenericObj(const CGenericObj& iOther)
{
   BuildCopyEraseFirst(iOther);
   // TODO: Pass Policies ?
   // Set the object name as well
   _objectname = iOther.getObjectName();
}

// Build object by deleting all previous attributes and nested objects
CGenericObj& CGenericObj::operator=(const CGenericObj& iOther)
{
   if ( this != &iOther ) // Prevent self assignment
   {
      BuildCopyEraseFirst(iOther);
      // TODO: Pass Policies ?
      // Set the object name as well
      _objectname = iOther.getObjectName();
   }
   return *this;
}

// Build object by erasing existing attributes and adding new ones
void CGenericObj::BuildCopyEraseFirst(const CGenericObj& iOther)
{
   DeleteAllAttributes();
   dbo_uint32_t iOtherCount = iOther.getAttributeCount();
   CAttributeGeneric* pOtherAtt = NULL;
   CAttributeGeneric* pTo = NULL;
   for(dbo_uint32_t k = DBO_INT_ZERO; k < iOtherCount; k++)
   {
      pOtherAtt = NULL;
      pOtherAtt = iOther.getAttributeObj(k);
      if (DBO_VALIDP(pOtherAtt))
      {
         // Insert a new one
         pTo = NULL;
         // Create a new copy of the attribute
         CreateCopyAttributeOnSwitch(pTo, pOtherAtt);
         // Insert the new attribute
         InsertAttributeCopyOnPtr(pTo);
      }
   }
}

// Build object by looking for existing attributes and adding new ones
void CGenericObj::BuildCopyAddNew(const CGenericObj& iOther)
{
    // Copy attributes if they do exists, add new ones
   dbo_uint32_t iOtherCount = iOther.getAttributeCount();
   CAttributeGeneric* pOtherAtt = NULL;
   CAttributeGeneric* pThisAtt = NULL;
   for(dbo_uint32_t k = DBO_INT_ZERO; k < iOtherCount; k++)
   {
      pOtherAtt = NULL;
      pOtherAtt = iOther.getAttributeObj(k);
      if (DBO_VALIDP(pOtherAtt))
      {
         if (attributeExists(pOtherAtt->getAttributeName()))
         {
            pThisAtt = NULL;
            pThisAtt = getAttributeObj(pOtherAtt->getAttributeName());
            if (DBO_VALIDP(pThisAtt))
            {
               // Do copy attributes: do use direct copy between attributes
               // Direct copy does reset the attribute idx...
               dbo_uint32_t indexThis = pThisAtt->getIndex();
               *pThisAtt = *pOtherAtt;
               pThisAtt->setIndex(indexThis);
            }
            else
            {
               DBO_ERROR_THROW_TMP;
            }
         }
         else
         {
            CAttributeGeneric* pTo = NULL;
            // Create a new copy of the attribute
            CreateCopyAttributeOnSwitch(pTo, pOtherAtt);
            // Insert the new attribute
            InsertAttributeCopyOnPtr(pTo);
         }
      }
      else
      {
         DBO_ERROR_THROW_TMP;
      }
   }
}

// Use only as a fail-over, prefer direct copy of attributes instead !
// This is a factory method
void CGenericObj::CopyExistingAttributeOnSwitch(CAttributeGeneric* pTo, const CAttributeGeneric* const pFrom) const
{
   if( DBO_INVALIDP(pFrom) || DBO_INVALIDP(pTo) )
   {
      DBO_ERROR_THROW_TMP;
   }
   if ( pTo->getKindType() != pFrom->getKindType() )
   {
      DBO_ERROR_THROW_TMP;
   }
   switch ( pFrom->getKindType() )
   {
      case (DBO_KIND_NULL) :
         DBO_ERROR_THROW_TMP;
         break;
      case (DBO_KIND_ATTNAME) :
         DBO_ERROR_THROW_TMP;
         break;
      case (DBO_KIND_ATTUNITS) :
         DBO_ERROR_THROW_TMP;
         break;
      case (DBO_KIND_DOUBLE) :
         {
            CAttributeDouble* pCheckedTo = dynamic_cast<CAttributeDouble*> (pTo);
            const CAttributeDouble* const pCheckedFrom = dynamic_cast<const CAttributeDouble* const> (pFrom);
            if ( DBO_VALIDP(pCheckedTo) && DBO_VALIDP(pCheckedFrom) )
            {
               (*pCheckedTo) = (*pCheckedFrom);
            }
         }
         break;
      case (DBO_KIND_INT64) :
         {
            CAttributeInt64* pCheckedTo = dynamic_cast<CAttributeInt64*> (pTo);
            const CAttributeInt64* const pCheckedFrom = dynamic_cast<const CAttributeInt64* const> (pFrom);
            if ( DBO_VALIDP(pCheckedTo) && DBO_VALIDP(pCheckedFrom) )
            {
               (*pCheckedTo) = (*pCheckedFrom);
            }
         }
         break;
      case (DBO_KIND_UINT64) :
         {
            CAttributeUInt64* pCheckedTo = dynamic_cast<CAttributeUInt64*> (pTo);
            const CAttributeUInt64* const pCheckedFrom = dynamic_cast<const CAttributeUInt64* const> (pFrom);
            if ( DBO_VALIDP(pCheckedTo) && DBO_VALIDP(pCheckedFrom) )
            {
               (*pCheckedTo) = (*pCheckedFrom);
            }
         }
         break;
      case (DBO_KIND_CSTRING) :
         {
            CAttributeCString* pCheckedTo = dynamic_cast<CAttributeCString*> (pTo);
            const CAttributeCString* const pCheckedFrom = dynamic_cast<const CAttributeCString* const> (pFrom);
            if ( DBO_VALIDP(pCheckedTo) && DBO_VALIDP(pCheckedFrom) )
            {
               (*pCheckedTo) = (*pCheckedFrom);
            }
         }
         break;
/*
      case (DBO_KIND_xxx) :
         {
            CAttributeXxx* pCheckedTo = dynamic_cast<CAttributeXxx*> (pTo);
            const CAttributeXxx* const pCheckedFrom = dynamic_cast<const CAttributeXxx* const> (pFrom);
            if ( DBO_VALIDP(pCheckedTo) && DBO_VALIDP(pCheckedFrom) )
            {
               (*pCheckedTo) = (*pCheckedFrom);
            }
         }
         break;
*/
      default:
         DBO_ERROR_THROW_TMP;
         break;
   }
}

// Use it but prefer direct copy of attributes whenever possible...
// This is a factory method
void CGenericObj::CreateCopyAttributeOnSwitch(CAttributeGeneric* pTo, const CAttributeGeneric* const pFrom) const 
{
   if (DBO_INVALIDP(pFrom))
   {
      DBO_ERROR_THROW_TMP;
   }
   pTo = NULL;
   if(    DBO_KIND_NULL == pFrom->getKindType() \
       || DBO_KIND_ATTNAME == pFrom->getKindType() \
       || DBO_KIND_ATTUNITS == pFrom->getKindType() \
       )
   {
      DBO_ERROR_THROW_TMP;
   }
   else if( DBO_KIND_DOUBLE == pFrom->getKindType() )
   {
      const CAttributeDouble* const pCheckedFrom = dynamic_cast<const CAttributeDouble* const> (pFrom);
      if (DBO_VALIDP(pCheckedFrom))
      {
         pTo = new CAttributeDouble(*pCheckedFrom);
      }
   }
   else if( DBO_KIND_INT64 == pFrom->getKindType() )
   {
      const CAttributeInt64* const pCheckedFrom = dynamic_cast<const CAttributeInt64* const> (pFrom);
      if (DBO_VALIDP(pCheckedFrom))
      {
         pTo = new CAttributeInt64(*pCheckedFrom);
      }
   }
   else if( DBO_KIND_UINT64 == pFrom->getKindType() )
   {
      const CAttributeUInt64* const pCheckedFrom = dynamic_cast<const CAttributeUInt64* const> (pFrom);
      if (DBO_VALIDP(pCheckedFrom))
      {
         pTo = new CAttributeUInt64(*pCheckedFrom);
      }
   }
   else if( DBO_KIND_CSTRING == pFrom->getKindType() )
   {
      const CAttributeCString* const pCheckedFrom = dynamic_cast<const CAttributeCString* const> (pFrom);
      if (DBO_VALIDP(pCheckedFrom))
      {
         pTo = new CAttributeCString(*pCheckedFrom);
      }
   }
/*
   else if( DBO_KIND_XXX == pFrom->getKindType() )
   {
      const CAttributeXxx* const pCheckedFrom = dynamic_cast<const CAttributeXxx* const> (pFrom);
      if (DBO_VALIDP(pCheckedFrom))
      {
         pTo = new CAttributeXxx(*pCheckedFrom);
      }
   }
*/
   else
   {
      DBO_ERROR_THROW_TMP;
   }
   if( DBO_INVALIDP(pTo) )
   {
      delete pTo;
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::InsertAttributeCopyOnPtr(CAttributeGeneric* pFrom)
{
   if (DBO_INVALIDP(pFrom))
   {
      DBO_ERROR_THROW_TMP;
   }
   // 0. Prepare the new attribute name
   dbo_char_t* NewAttribName = DoMakeAttributeName(pFrom->getAttributeName());
   if ( DBO_VALIDP(NewAttribName) )
   {
      // 1. Delayed construction, first try to insert new attribute in map
      std::pair<dbo_char_t*,CAttributeGeneric*> pairAttr = std::make_pair(NewAttribName,pFrom);
      std::pair<DefAttributeMap::iterator,bool> pairInsertAttr = AttributesMap.insert(pairAttr);
      if ( pairInsertAttr.second ) // insert succeeded 
      {
         // TODO: pass to policy
         // Reset the attribute idx with our current available value
         pFrom->setIndex(_attribute_idx_counter);
         AttributesVec.push_back(pFrom);
         _attribute_idx_counter++; // A new canonical attribute was inserted
      }
      else // Attribute already exist!, insert did fail...
      {
         delete pFrom;
         pFrom = NULL;
         delete [] NewAttribName;
         NewAttribName = NULL;
         DBO_ERROR_THROW_TMP;
      }
   }
   else // No way to get a new name
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::DeleteAllAttributes(void)
{
   // Delete all attributes
   DefAttributeMap::iterator itObj = AttributesMap.begin();
   while ( itObj != AttributesMap.end() )
   {
      delete []   itObj->first;
      delete      itObj->second;
      itObj++;
   }
   // Reset containers
   AttributesMap.clear();
   AttributesVec.clear();
   _attribute_idx_counter = DBO_INT_ZERO;
}

dbo_char_t* CGenericObj::DoMakeAttributeName(const dbo_char_t* const AttribName) const 
{
   size_t sLenAttr = strlen(AttribName);
   dbo_char_t* NewAttribName = NULL;
   NewAttribName = new dbo_char_t[sLenAttr + 1];
   if ( DBO_VALIDP(NewAttribName) )
   {
      strcpy(NewAttribName, AttribName);
      NewAttribName[sLenAttr] = DBO_TXT_STDTERM_CHAR;
   }
   else
   {
      delete [] NewAttribName;
      NewAttribName = NULL;
      DBO_ERROR_THROW_TMP;
   }
   return NewAttribName;
}

dbo_char_t* CGenericObj::DoMakeAttributeName(const string& AttribName) const 
{
   size_t sLenAttr = AttribName.size();
   dbo_char_t* NewAttribName = NULL;
   NewAttribName = new dbo_char_t[sLenAttr + 1];
   if ( DBO_VALIDP(NewAttribName) )
   {
      strcpy(NewAttribName, AttribName.c_str());
      NewAttribName[sLenAttr] = DBO_TXT_STDTERM_CHAR;
   }
   else
   {
      delete [] NewAttribName;
      NewAttribName = NULL;
      DBO_ERROR_THROW_TMP;
   }
   return NewAttribName;
}

/* virtual */ CGenericObj::~CGenericObj()
{
    DeleteAllAttributes();
    // TODO: Policies...
}

// The Dynamic attributes interface, set&get attributes ->
void CGenericObj::setAttributeValue(const dbo_char_t* const AttribName, const dbo_double_t& value)
{
   DefAttributeMap::iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if(itObj != AttributesMap.end())
   {
      // TODO: pass to Policy
      // CAttributeDouble* pDouble = dynamic_cast<CAttributeDouble*> (itObj->second);
      if (DBO_INVALIDP(itObj->second))
      {
         DBO_ERROR_THROW_TMP;
      }
      itObj->second->setAsDouble(value);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::setAttributeValue(const dbo_char_t* const AttribName, const dbo_int64_t& value)
{
   DefAttributeMap::iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if(itObj != AttributesMap.end())
   {
      // TODO: pass to Policy
      // CAttributeInt64* pInt64 = dynamic_cast<CAttributeInt64*> (itObj->second);
      if (DBO_INVALIDP(itObj->second))
      {
         DBO_ERROR_THROW_TMP;
      }
      itObj->second->setAsInt64(value);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::setAttributeValue(const dbo_char_t* const AttribName, const dbo_uint64_t& value)
{
   DefAttributeMap::iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if(itObj != AttributesMap.end())
   {
      // TODO: pass to Policy
      // CAttributeUInt64* pInt64 = dynamic_cast<CAttributeUInt64*> (itObj->second);
      if (DBO_INVALIDP(itObj->second))
      {
         DBO_ERROR_THROW_TMP;
      }
      itObj->second->setAsUInt64(value);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::setAttributeValue(const dbo_char_t* const AttribName, const dbo_char_t* const value)
{
   DefAttributeMap::iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if(itObj != AttributesMap.end())
   {
      // TODO: pass to Policy
      // CAttributeUInt64* pInt64 = dynamic_cast<CAttributeUInt64*> (itObj->second);
      if (DBO_INVALIDP(itObj->second))
      {
         DBO_ERROR_THROW_TMP;
      }
      itObj->second->setAsCString(value);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::setAttributeValue(const dbo_char_t* const AttribName, const dbo_string_t& value)
{
   DefAttributeMap::iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if(itObj != AttributesMap.end())
   {
      // TODO: pass to Policy
      // CAttributeUInt64* pInt64 = dynamic_cast<CAttributeUInt64*> (itObj->second);
      if (DBO_INVALIDP(itObj->second))
      {
         DBO_ERROR_THROW_TMP;
      }
      itObj->second->setAsString(value);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeValue(const dbo_char_t* const AttribName, dbo_double_t& value) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      // Get a copy
      value = itObj->second->getAsDouble();
      // TODO: pass to policy
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeValue(const dbo_char_t* const AttribName, dbo_int64_t& value) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      // Get a copy
      value = itObj->second->getAsInt64();
      // TODO: pass to policy
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeValue(const dbo_char_t* const AttribName, dbo_uint64_t& value) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      // Get a copy
      value = itObj->second->getAsUInt64();
      // TODO: pass to policy
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeValue(const dbo_char_t* const AttribName, dbo_char_t* value, const size_t iSize) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      // Get a copy
      itObj->second->getAsCString(value, iSize);
      // TODO: pass to policy
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeValue(const dbo_char_t* const AttribName, dbo_string_t& value) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      // Get a copy
      value = itObj->second->getAsString();
      // TODO: pass to policy
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}
// The Dynamic attributes interface, set&get attributes <-

// InsertAttribute overloads ->
void CGenericObj::insertAttribute(const dbo_char_t* const AttribName, const dbo_double_t& value)
{
    // TODO:
    0;
}

void CGenericObj::insertAttribute(const dbo_char_t* const AttribName, const dbo_int64_t& value)
{
    // TODO:
    0;
}

void CGenericObj::insertAttribute(const dbo_char_t* const AttribName, const dbo_uint64_t& value)
{
    // TODO:
    0;
}

void CGenericObj::insertAttribute(const dbo_char_t* const AttribName, const dbo_char_t* const value)
{
   // 0. Prepare the new attribute name
   dbo_char_t* NewAttribName = DoMakeAttributeName(AttribName);
   if ( DBO_VALIDP(NewAttribName) )
   {
      // 1. Delayed construction, first try to insert new dummy attribute in map
      CAttributeCString* pAttribute = NULL;
      std::pair<dbo_char_t*,CAttributeGeneric*> pairAttr = std::make_pair(NewAttribName,pAttribute);
      std::pair<DefAttributeMap::iterator,bool> pairInsertAttr = AttributesMap.insert(pairAttr);
      if ( pairInsertAttr.second ) // insert succeeded 
      {
         // 2. Create new attribute and place it there
         pAttribute = new CAttributeCString(value, _attribute_idx_counter, NewAttribName);
         if ( DBO_VALIDP(pAttribute) )
         {
            // TODO: pass to policy
            pairInsertAttr.first->second = pAttribute;
            AttributesVec.push_back(pAttribute);
            _attribute_idx_counter++; // Canonical attribute
         }
         else // No new attribute
         {
            AttributesMap.erase(pairInsertAttr.first);
            delete pAttribute;
            pAttribute = NULL;
            delete [] NewAttribName;
            NewAttribName = NULL;
            DBO_ERROR_THROW_TMP;
         }
      }
      else // Attribute already exist!, insert did fail...
      {
         delete [] NewAttribName;
         NewAttribName = NULL;
         DBO_ERROR_THROW_TMP;
      }
   }
   else // No way to get a new name
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::insertAttribute(const dbo_char_t* const AttribName, const dbo_string_t& value)
{
    // TODO:
    0;
}
// InsertAttribute overloads <-

void CGenericObj::deleteAttribute(const dbo_char_t* const AttribName)
{
   DefAttributeMap::iterator itObjMap;
   itObjMap = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObjMap != AttributesMap.end())
   {
      DefAttributeVector::iterator itObjVec;
      itObjVec = find(AttributesVec.begin(), AttributesVec.end(), itObjMap->second);
      if( itObjVec != AttributesVec.end() )
      {
         AttributesVec.erase(itObjVec);
      }
      delete[]   itObjMap->first;
      delete     itObjMap->second;
      AttributesMap.erase(itObjMap);
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

// Interface to be protected, no direct access to attributes ->
CAttributeGeneric* CGenericObj::getAttributeObj(const dbo_char_t* const AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   // const_cast<dbo_char_t*> : hack to keep compilers happy
   itObj = AttributesMap.find( const_cast<dbo_char_t*> (AttribName) );
   if (itObj != AttributesMap.end())
   {
      if( DBO_INVALIDP(itObj->second) )
      {
         DBO_ERROR_THROW_TMP;
      }
      return itObj->second;
   }
   else // Attribute not found
   {
      DBO_ERROR_THROW_TMP;
   }
}

CAttributeGeneric* CGenericObj::getAttributeObj(const string& AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   // const_cast<dbo_char_t*> : hack to keep compilers happy
   itObj = AttributesMap.find( const_cast<dbo_char_t*> (AttribName.c_str()) );
   if (itObj != AttributesMap.end())
   {
      if( DBO_INVALIDP(itObj->second) )
      {
         DBO_ERROR_THROW_TMP;
      }
      return itObj->second;
   }
   else // Attribute not found
   {
      DBO_ERROR_THROW_TMP;
   }
}

CAttributeGeneric* CGenericObj::getAttributeObj(const dbo_uint32_t index) const
{
   CAttributeGeneric* pObj = NULL;
   pObj = AttributesVec.at(static_cast<size_t> (index));
   if (DBO_INVALIDP(pObj))
   {
      DBO_ERROR_THROW_TMP;
   }
   return pObj;
}
// Interface to be protected <-

// Aux interface ->
void CGenericObj::getAttributeName(const dbo_uint32_t index, dbo_char_t* const pAttribName, const size_t iSize) const
{
   CAttributeGeneric* pObj = NULL;
   pObj = AttributesVec.at(static_cast<size_t> (index));
   if (DBO_VALIDP(pObj))
   {
      if ( iSize < pObj->getAttributeName().length() )
      {
         DBO_ERROR_THROW_TMP;
      }
      strncpy(pAttribName, pObj->getAttributeName().c_str(), iSize);
      *(pAttribName + iSize) = DBO_TXT_STDTERM_CHAR;
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

void CGenericObj::getAttributeName(const dbo_uint32_t index, dbo_string_t& AttribName) const
{
   CAttributeGeneric* pObj = NULL;
   pObj = AttributesVec.at(static_cast<size_t> (index));
   if (DBO_VALIDP(pObj))
   {
      AttribName = pObj->getAttributeName();
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

bool CGenericObj::attributeExists(const dbo_char_t* const AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   // const_cast<dbo_char_t*> : hack to keep compilers happy
   itObj = AttributesMap.find( const_cast<dbo_char_t*> (AttribName) );
   if (itObj != AttributesMap.end())
   {
      return true;
   }
   else
   {
      return false;
   }
   return false;
}

bool CGenericObj::attributeExists(const string& AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   // const_cast<dbo_char_t*> : hack to keep compilers happy
   itObj = AttributesMap.find( const_cast<dbo_char_t*> (AttribName.c_str()) );
   if (itObj != AttributesMap.end())
   {
      return true;
   }
   else
   {
      return false;
   }
   return false;
}

bool CGenericObj::attributeExists(const dbo_uint32_t index) const
{
   if ( AttributesVec.size() <= index )
   {
      return false;
   }
   CAttributeGeneric* pObj = NULL;
   pObj = AttributesVec.at(static_cast<size_t> (index));
   if (DBO_VALIDP(pObj))
   {
      return true;
   }
   else
   {
      return false;
   }
   return false;
}

size_t CGenericObj::getAttributeSize(const dbo_char_t* const AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   itObj = AttributesMap.find(const_cast<dbo_char_t*> (AttribName));
   if (itObj != AttributesMap.end())
   {
      return itObj->second->getSize();
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

size_t CGenericObj::getAttributeSize(const dbo_string_t& AttribName) const
{
   DefAttributeMap::const_iterator itObj;
   // const_cast<dbo_char_t*> : hack to keep compilers happy
   itObj = AttributesMap.find( const_cast<dbo_char_t*> (AttribName.c_str()) );
   if (itObj != AttributesMap.end())
   {
      return itObj->second->getSize();
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}

size_t CGenericObj::getAttributeSize(const dbo_uint32_t index) const
{
   CAttributeGeneric* pObj = NULL;
   pObj = AttributesVec.at(static_cast<size_t> (index));
   if (DBO_VALIDP(pObj))
   {
      return pObj->getSize();
   }
   else
   {
      DBO_ERROR_THROW_TMP;
   }
}
// Aux interface <-

NAMESPACE_DBO_CLOSE


