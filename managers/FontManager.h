#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../fonts/6px/font.h"
#include "../fonts/BMRizer/font.h"
#include "../fonts/BMPlain/font.h"
#include "../fonts/DavidDevice/font.h"
#include "../fonts/PressStart2P/font.h"
#include "../fonts/Volter/font.h"
#include "../fonts/FreePixel/font.h"
#include "../fonts/Symbols/font.h"


class FontManager
{
public:
	enum FontName
	{
		_6PX_6,
		BMRIZER_6,
		GENERIC_6PX = _6PX_6,
		BMPLAIN_7,
		GENERIC_7PX = BMPLAIN_7,
		PRESSSTART2P_8,
		GENERIC_8PX = PRESSSTART2P_8,
		DAVID_DEVICE_9,
		VOLTER_9,
		GENERIC_9PX = DAVID_DEVICE_9,
		FREEPIXEL_12,
		GENERIC_12PX = FREEPIXEL_12,
		SYMBOLS
	};

public:
	FontManager();
	~FontManager();

public:
	const Font* GetFont(FontName font_name) const;
	
private:
	_6pxFont6         m_6pxFont6;
	BMRizerFont6      m_BMRizerFont6;
	BMPlainFont7      m_BMPlainFont7;
	PressStart2PFont8 m_PressStart2PFont8;
	DavidDeviceFont9  m_DavidDeviceFont9;
	VolterFont9       m_VolterFont9;
	FreePixelFont12   m_FreePixelFont12;
	SymbolsFont       m_SymbolsFont;
};

#endif // _FONT_MANAGER_H_
