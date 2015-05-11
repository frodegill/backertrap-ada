#ifndef _6PX_FONT_6_H_
#define _6PX_FONT_6_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/6px.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class _6pxFont6 : public Font
{
public:
  _6pxFont6();
  ~_6pxFont6();

public:
	U8 GetFontHeight() const {return 6;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_6PX_FONT_6_H_
