#ifndef _BMRIZER_FONT_6_H_
#define _BMRIZER_FONT_6_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/bm-rizer.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class BMRizerFont6 : public Font
{
public:
  BMRizerFont6();
  ~BMRizerFont6();

public:
	U8 GetFontHeight() const {return 6;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_BMRIZER_FONT_6_H_
