#ifndef _FONT_H_
#define _FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"


#define CHAR_SIZE(x,y,y_offset) (x&0xFF),((y_offset&0x0F)<<4)|(y&0x0F)

class Font
{
public:
  Font();
	~Font();

public:
	U8 GetFontHeight() const {return 0;}
	U8 GetMargin() const {return 1;}

	U8 GetAlphabetByte(U8 UNUSED_PARAM(pos)) const {return 0;}
	U16 GetFontdataChOffset(U8 ch) const;
	U8 GetFontdataByte(U16 UNUSED_PARAM(ch_offset), U8 UNUSED_PARAM(pos)) const {return 0;}

};

#endif // _FONT_H_
