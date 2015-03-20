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
	uint8 GetHeight() const {return 9;}

	uint8 GetAlphabetByte(uint8 pos) const;
	uint8 GetFontdataByte(uint16 ch_offset, uint8 pos) const;

};

#endif //_VOLTER_FONT_9_H_
