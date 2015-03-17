
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../pch.h"
#else
#endif

#include "font.h"


Font::Font(const uint8* alphabeth, uint8 height, uint8 margin,const uint8* fontdata)
: m_alphabeth(alphabeth),
  m_height(height),
  m_margin(margin),
  m_fontdata(fontdata)
{
}

Font::~Font()
{
}
