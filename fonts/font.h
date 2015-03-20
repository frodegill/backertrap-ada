#ifndef _FONT_H_
#define _FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"


class Font
{
public:
  Font();
	~Font();

public:
	uint8 GetHeight() const {return 0;}
	uint8 GetMargin() const {return 1;}

	uint8 GetAlphabetByte(uint8 UNUSED(pos)) const {return 0;}
	uint16 GetFontdataChOffset(uint8 ch) const;
	uint8 GetFontdataByte(uint16 UNUSED(ch_offset), uint8 UNUSED(pos)) const {return 0;}

};

#endif // _FONT_H_
