#ifndef _DEFINES_H_
#define _DEFINES_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license


#define MAX_PAGE_STACK_SIZE (16)

#ifdef XMEGA256A3
# define DISPLAY_NHDC12832A1ZFSWFBW3V3
# define STORAGE_AT45DB642D
#else
# error You have to define your board in the Makefile
#endif

#define UNUSED(x)
#define NULL (0L)

typedef unsigned char  uint8;
typedef unsigned short uint16;

#endif // _DEFINES_H_
