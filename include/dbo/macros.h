// General macro used through

#ifndef DBO_MACROS_H_INCLUDED
#define DBO_MACROS_H_INCLUDED

#include "dbo/namespace.h"

#include "dbo/typesdef.h"
#include "dbo/classerr.h"
#include "dbo/attrerr.h"

// General Macro's

#define DBO_DEF_CLASS_H \
private: \
   static dbo_string_t _classname; \
public: \
   virtual dbo_string_t getClassName(void) const DBO_NOTHROW \
   { \
      return _classname; \
   }

#define DBO_PRI_CLASS_CTOR_H(x) \
private: \
   x() { 0; }

#define DBO_DEF_CLASS_SRC(x) \
dbo_string_t x::_classname = #x

#define DBO_VALIDP(x)    ( NULL != (x) )
#define DBO_INVALIDP(x)  ( NULL == (x) )

#define DBO_DEF_CLASS_ERR_H \
protected: \
   mutable DBO_CLASS_ERR _last_err; \
public: \
   FORCE_INLINE DBO_CLASS_ERR getLastError(void) const DBO_NOTHROW \
   { \
      return _last_err; \
   }; \
   FORCE_INLINE void setLastError(const DBO_CLASS_ERR err) const DBO_NOTHROW \
   { \
      _last_err = err; \
   }

#endif /* DBO_MACROS_H_INCLUDED */

