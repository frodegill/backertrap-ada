#ifndef _FONT_H_
#define _FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

class Font
{
public:
  Font(const byte* alphabeth, const byte height, const byte margin, const byte* fontdata);
	~Font();

private:
  const byte* m_alphabeth;
  byte m_height;
  byte m_margin;
  const byte* m_fontdata;
};

#endif // _FONT_H_
