#ifndef _FONT_H_
#define _FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"


#define CHAR_SIZE(x,y,y_offset) (x&0xFF),((y_offset&0x0F)<<4)|(y&0x0F)

class Font
{
public:
  Font(U8 height, U8 margin, const U8* alphabet_p, const U8* fontdata_p);

public:
	U8 GetFontHeight() const {return m_height;}
	U8 GetMargin() const {return m_margin;}
	
	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;
	U16 GetFontdataChOffset(U8 ch) const;

private:
	U8 m_height;
	U8 m_margin;
	const U8* m_alphabet_p;
	const U8* m_fontdata_p;
};

#endif // _FONT_H_
