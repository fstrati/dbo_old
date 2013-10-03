/*
 * Where not otherwise stated the following LICENSE does apply
 * LICENSE: GNU General Public License version 3.0 - GNU GPL v.3
 *
 */

// General attributes errors

#ifndef DBO_ATTRERR_H_INCLUDED
#define DBO_ATTRERR_H_INCLUDED

#include "dbo/namespace.h"

NAMESPACE_DBO_OPEN

typedef	dbo_uint32_t      DBO_ATTR_ERR;

// Do not use enum until c++11 is fully deployed
const DBO_ATTR_ERR  DBO_ATTR_ERR_SUCCESS                             = 0x00000000;
const DBO_ATTR_ERR  DBO_ATTR_ERR_INVALID_OP                          = 0x00000001;
const DBO_ATTR_ERR  DBO_ATTR_ERR_INVALID_PTR                         = 0x00000002;
const DBO_ATTR_ERR  DBO_ATTR_ERR_INVALID_CONV                        = 0x00000003;
const DBO_ATTR_ERR  DBO_ATTR_ERR_INVALID_KIND                        = 0x00000004;
const DBO_ATTR_ERR  DBO_ATTR_ERR_OUT_OF_MEMORY                       = 0x00000005;
const DBO_ATTR_ERR  DBO_ATTR_ERR_STR_GET_TRUNCATED                   = 0x00000006;
const DBO_ATTR_ERR  DBO_ATTR_ERR_STR_SET_TRUNCATED                   = 0x00000007;
const DBO_ATTR_ERR  DBO_ATTR_ERR_LAST                                = 0x00000008;

NAMESPACE_DBO_CLOSE

#endif /* DBO_ATTRERR_H_INCLUDED */



