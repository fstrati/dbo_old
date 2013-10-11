/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// General macro used through

#ifndef DBO_MACROS_H_INCLUDED
#define DBO_MACROS_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"
#include "dbo/classerr.h"

// General Macro's

#define DBO_VALIDP(x)    ( NULL != (x) )
#define DBO_INVALIDP(x)  ( NULL == (x) )

#define DBO_PRI_CLASS_CTOR_H(x) \
protected: \
   x() { }

#define DBO_DEF_CLASS_ERR_H \
protected: \
   mutable DBO_CLASS_ERR _last_err; \
public: \
   virtual DBO_CLASS_ERR getLastError(void) const DBO_NOTHROW \
   { \
      return _last_err; \
   }; \
   virtual void setLastError(const DBO_CLASS_ERR err) const DBO_NOTHROW \
   { \
      _last_err = err; \
   }

#endif /* !defined(DBO_MACROS_H_INCLUDED) */

