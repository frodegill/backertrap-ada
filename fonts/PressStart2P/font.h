#ifndef _PRESSSTART2P_FONT_8_H_
#define _PRESSSTART2P_FONT_8_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/free-pixel.font?fpp=100&l[]=10&l[]=1 >

#include "../../defines.h"
#include "../font.h"


class PressStart2PFont8 : public Font
{
public:
  PressStart2PFont8();
  ~PressStart2PFont8();

public:
	uint8 GetHeight() const {return 8;}

	uint8 GetAlphabetByte(uint8 pos) const;
	uint8 GetFontdataByte(uint16 ch_offset, uint8 pos) const;

};

#endif //_PRESSSTART2P_FONT_8_H_
