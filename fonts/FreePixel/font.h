#ifndef _FREEPIXEL_FONT_12_H_
#define _FREEPIXEL_FONT_12_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/free-pixel.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class FreePixelFont12 : public Font
{
public:
  FreePixelFont12();
  ~FreePixelFont12();

public:
	U8 GetHeight() const {return 12;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_FREEPIXEL_FONT_12_H_
