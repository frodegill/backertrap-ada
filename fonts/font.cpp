
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

const uint8* Font::GetFontdata(uint8 ch) const
{
	uint8 font_height = GetHeight();
	const uint8* alphabeth = GetAlphabeth();
	const uint8* alpha_ptr = alphabeth;
	while (*alpha_ptr && *(alpha_ptr+1) && *alpha_ptr!=ch) alpha_ptr++;

	const uint8* fontdata = GetFontdata();
	int i;
	for (i=0; i<(alpha_ptr-alphabeth); i++)
	{
		fontdata += ((*fontdata>>3)+1)*font_height + 1;
	}

	return fontdata;
}
