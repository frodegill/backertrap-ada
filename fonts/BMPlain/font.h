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
	const uint8* GetAlphabeth() const;
	uint8 GetHeight() const;
	uint8 GetMargin() const;

protected:
	const uint8* GetFontdata() const;

};

#endif //_BMPLAIN_FONT_7_H_
