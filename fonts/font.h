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
	U8 GetHeight() const {return 0;}
	U8 GetMargin() const {return 1;}

	U8 GetAlphabetByte(U8 UNUSED_PARAM(pos)) const {return 0;}
	U16 GetFontdataChOffset(U8 ch) const;
	U8 GetFontdataByte(U16 UNUSED_PARAM(ch_offset), U8 UNUSED_PARAM(pos)) const {return 0;}

};

#endif // _FONT_H_
