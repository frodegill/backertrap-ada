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
	const uint8* GetAlphabeth() const;
	uint8 GetHeight() const;
	uint8 GetMargin() const;

protected:
	const uint8* GetFontdata() const;

};

#endif //_BMRIZER_FONT_6_H_
