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
	const uint8* GetAlphabeth() const {return NULL;}
	uint8 GetHeight() const {return 0;}
	uint8 GetMargin() const {return 0;}
	const uint8* GetFontdata(uint8 UNUSED(ch)) const;

protected:
	const uint8* GetFontdata() const {return NULL;}

};

#endif // _FONT_H_
