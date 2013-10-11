/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// General business objects errors

#ifndef DBO_CLASSERR_H_INCLUDED
#define DBO_CLASSERR_H_INCLUDED

#include "dbo/namespace.h"
#include "dbo/typesdef.h"

NAMESPACE_DBO_OPEN

typedef	dbo_uint32_t      DBO_CLASS_ERR;

// Do not use enum until c++11 is fully deployed
const DBO_CLASS_ERR  DBO_CLASS_ERR_SUCCESS                            = 0x00000000;
const DBO_CLASS_ERR  DBO_CLASS_ERR_INVALID_OP                         = 0x00000001;
const DBO_CLASS_ERR  DBO_CLASS_ERR_INVALID_PTR                        = 0x00000002;
const DBO_CLASS_ERR  DBO_CLASS_ERR_INVALID_CONV                       = 0x00000003;
const DBO_CLASS_ERR  DBO_CLASS_ERR_INVALID_KIND                       = 0x00000004;
const DBO_CLASS_ERR  DBO_CLASS_ERR_OUT_OF_MEMORY                      = 0x00000005;
const DBO_CLASS_ERR  DBO_CLASS_ERR_LAST                               = 0x00000006;

NAMESPACE_DBO_CLOSE

#endif /* !defined(DBO_CLASSERR_H_INCLUDED) */

