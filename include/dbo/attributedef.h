/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// Attribute pertinent global definitions

#ifndef DBO_ATTRIBUTEDEF_H_INCLUDED
#define DBO_ATTRIBUTEDEF_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/attrerr.h"

NAMESPACE_DBO_OPEN

// OS independent sizes
typedef dbo_uint16_t                   DBO_SER_ENDIAN_BOM;
typedef dbo_uint8_t                    DBO_KIND;
// the following shall be at least a 64bit unsigned long
typedef dbo_uint64_t                   DBO_BIN_KIND_SIZE;

// Define all known base kind types.
// Do not use enum until c++11 is fully deployed
// This is the list of all known attribute kinds.
const   DBO_KIND DBO_KIND_NULL                                          = 0x00;
const   DBO_KIND DBO_KIND_ATTNAME                                       = 0x01;
const   DBO_KIND DBO_KIND_ATTUNITS                                      = 0x02;
const   DBO_KIND DBO_KIND_ATTPROPS                                      = 0x03;
const   DBO_KIND DBO_KIND_CSTRING                                       = 0x04;
const   DBO_KIND DBO_KIND_STRING                                        = 0x05;
const   DBO_KIND DBO_KIND_WCSTRING                                      = 0x06;
const   DBO_KIND DBO_KIND_WSTRING                                       = 0x07;
const   DBO_KIND DBO_KIND_DOUBLE                                        = 0x08;
const   DBO_KIND DBO_KIND_INT64                                         = 0x09;
const   DBO_KIND DBO_KIND_UINT64                                        = 0x0A;
const   DBO_KIND DBO_KIND_LAST                                          = 0x0B;

typedef struct DBO_ATTR_PROPERTIES 
{
   dbo_uint32_t  isNull : 1
                ,isValid : 1
                ,isTruncated : 1
                ,spare : 29
      ;
} dbo_attr_properties_t;

NAMESPACE_DBO_CLOSE

#define DBO_DEF_ATTR_KIND(x,z) \
   DBO_KIND x::_kind = z

#define DBO_DEF_ATTR_H \
private: \
   static DBO_KIND _kind; \
public: \
   virtual DBO_KIND getKindType(void) const DBO_NOTHROW \
   { \
      return _kind; \
   }

#define DBO_DEF_ATTR_ERR_H \
protected: \
   mutable DBO_ATTR_ERR _last_err; \
public: \
   virtual DBO_ATTR_ERR getLastError(void) const DBO_NOTHROW \
   { \
      return _last_err; \
   }; \
   virtual void setLastError(const DBO_ATTR_ERR err) const DBO_NOTHROW \
   { \
      _last_err = err; \
   }

#define DBO_DEF_EMPTYVALUE(value,empty_value)   do \
                                                { \
                                                   if (DBO_VALIDP(value)) \
                                                   { \
                                                      (*value) = empty_value; \
                                                   } \
                                                } while (false)

#endif /* !defined(DBO_ATTRIBUTEDEF_H_INCLUDED) */

