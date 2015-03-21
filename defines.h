#ifndef _DEFINES_H_
#define _DEFINES_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "common/utils/parts.h"
#include "xmega/utils/compiler.h"
#include "common/services/ioport/ioport.h"


#define MAX_PAGE_STACK_SIZE (16)

#if (BOARD == XMEGA_A3BU_XPLAINED)
# include "xmega/boards/xmega_a3bu_xplained/xmega_a3bu_xplained.h"
//# define DISPLAY_NHDC12832A1ZFSWFBW3V3
//# define STORAGE_AT45DB642D
#else
# error You have to define your board in the Makefile
#endif



#ifndef UNUSED_PARAM
# define UNUSED_PARAM(x)
#endif

#ifndef NULL
# define NULL (0L)
#endif

#endif // _DEFINES_H_
