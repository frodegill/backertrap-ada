#ifndef _BMPLAIN_FONT_7_H_
#define _BMPLAIN_FONT_7_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/bm-plain.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class BMPlainFont7 : public Font
{
public:
  BMPlainFont7();
  ~BMPlainFont7();

public:
	U8 GetHeight() const {return 7;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_BMPLAIN_FONT_7_H_
