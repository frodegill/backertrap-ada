#ifndef _FONT_H_
#define _FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"


class Font
{
public:
  Font(const uint8* alphabeth, const uint8 height, const uint8 margin, const uint8* fontdata);
	~Font();

private:
  const uint8* m_alphabeth;
  uint8 m_height;
  uint8 m_margin;
  const uint8* m_fontdata;
};

#endif // _FONT_H_
