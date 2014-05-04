#pragma once

#include "Common.h"

typedef void*(*xMALLOC)(size_t size);
typedef void(*xFREE)(void*);

#define malloc ((xMALLOC)SYM_MALLOC)
#define free ((xFREE)SYM_FREE)
