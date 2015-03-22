#ifndef _VOLTER_FONT_9_H_
#define _VOLTER_FONT_9_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/volter-goldfish.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class VolterFont9 : public Font
{
public:
  VolterFont9();
  ~VolterFont9();

public:
	U8 GetFontHeight() const {return 9;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_VOLTER_FONT_9_H_
