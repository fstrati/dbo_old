
#ifndef DBO_CALLOCATORS_H_INCLUDED
#define DBO_CALLOCATORS_H_INCLUDED

#include "dbo/namespace.h"

#include <cstdlib>

NAMESPACE_DBO_OPEN

#define DBO_MALLOC(x)      std::malloc(x)
#define DBO_FREE(x)        std::free(x)

NAMESPACE_DBO_CLOSE

#endif /* DBO_CALLOCATORS_H_INCLUDED */

