
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../pch.h"
#else
#endif

#include "font.h"


Font::Font(U8 height, U8 margin, const U8* alphabet_p, const U8* fontdata_p)
: m_height(height),
  m_margin(margin),
  m_alphabet_p(alphabet_p),
  m_fontdata_p(fontdata_p)
{
}

U8 Font::GetAlphabetByte(U8 pos) const
{
	return pgm_read_byte(&m_alphabet_p[pos]);
}

U8 Font::GetFontdataByte(U16 ch_offset, U8 pos) const
{
	return pgm_read_byte(&m_fontdata_p[ch_offset+pos]);
}

U16 Font::GetFontdataChOffset(U8 ch) const
{
	U8 ch_width, ch_height;
	U8 alphabet_pos = 0;
	U8 alphabet_byte;
	U16 offset = 0;
	while(true)
	{
		alphabet_byte = GetAlphabetByte(alphabet_pos);
		if (alphabet_byte == ch)
		{
			return offset;
		}
		else if (alphabet_byte == 0)
		{
			return 0;
		}

		ch_width = GetFontdataByte(offset, 0);
    ch_height = GetFontdataByte(offset, 1)&0x0F;
		offset += (1 + 1 + ((ch_width>>3)+1)*ch_height);
		alphabet_pos++;
	}
}
