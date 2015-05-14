
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "FontManager.h"


FontManager::FontManager()
{
}

FontManager::~FontManager()
{
}

const Font* FontManager::GetFont(FontName font_name) const
{
	switch(font_name)
	{
		case _6PX_6:         return &m_6pxFont6;
		case BMRIZER_6:      return &m_BMRizerFont6;
		case BMPLAIN_7:      return &m_BMPlainFont7;
		case PRESSSTART2P_8: return &m_PressStart2PFont8;
		case DAVID_DEVICE_9: return &m_DavidDeviceFont9;
		case VOLTER_9:       return &m_VolterFont9;
		case FREEPIXEL_12:   return &m_FreePixelFont12;
		case SYMBOLS:
		default:             return &m_SymbolsFont;
	}
}
