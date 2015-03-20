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
	uint8 GetHeight() const {return 6;}

	uint8 GetAlphabetByte(uint8 pos) const;
	uint8 GetFontdataByte(uint16 ch_offset, uint8 pos) const;

};

#endif //_BMRIZER_FONT_6_H_
