#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../fonts/BMRizer/font.h"
#include "../fonts/BMPlain/font.h"
#include "../fonts/PressStart2P/font.h"
#include "../fonts/Volter/font.h"
#include "../fonts/FreePixel/font.h"
#include "../fonts/Symbols/font.h"


class FontManager
{
	enum FontName
	{
		BMRIZER_6,
		BMPLAIN_7,
		PRESSSTART2P_8,
		VOLTER_9,
		FREEPIXEL_12,
		SYMBOLS
	};

public:
	FontManager();
	~FontManager();

public:
	const Font* GetFont(FontName font_name) const;
	
private:
	BMRizerFont6      m_BMRizerFont6;
	BMPlainFont7      m_BMPlainFont7;
	PressStart2PFont8 m_PressStart2PFont8;
	VolterFont9       m_VolterFont9;
	FreePixelFont12   m_FreePixelFont12;
	SymbolsFont       m_SymbolsFont;
};

#endif // _FONT_MANAGER_H_
