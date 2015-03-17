
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../pch.h"
#else
#endif

#include "font.h"


Font::Font(const byte* alphabeth, byte height, byte margin,const byte* fontdata)
: m_alphabeth(alphabeth),
  m_height(height),
  m_margin(margin),
  m_fontdata(fontdata)
{
}

Font::~Font()
{
}
