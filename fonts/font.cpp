
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../pch.h"
#else
#endif

#include "font.h"


Font::Font()
{
}

Font::~Font()
{
}

uint16 Font::GetFontdataChOffset(uint8 ch) const
{
	uint8 font_height = GetHeight();
	uint8 font_width;
	uint8 alphabet_pos = 0;
	uint8 alphabet_byte;
	uint16 offset = 0;
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

		font_width = GetFontdataByte(offset, 0);
		offset += (1 + ((font_width>>3)+1)*font_height);
		alphabet_pos++;
	}
}
