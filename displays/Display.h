#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"
#include "../fonts/font.h"


class Display
{
public:
	enum BacklightStatus
	{
		ON,
		OFF
	};
	
	enum DrawMode
	{
		OR,
		AND,
		NOT,
		XOR
	};
	
public:
	Display();
	~Display();

public:
	U16 GetWidth() const {return 0;}
	U16 GetHeight() const {return 0;}
	U8* GetFramebuffer() const {return NULL;}

public:
	void SetBrightness(double UNUSED_PARAM(brightness)) {}
	void SetBacklightStatus(BacklightStatus UNUSED_PARAM(status)) {}

	void ClearDisplay() {}
	void RefreshDisplay() {}

	void DrawPixel(S16 x, S16 y, DrawMode mode);
	void DrawLine(S16 x, S16 y, U16 delta_x, U16 delta_y, DrawMode mode);
	void DrawRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode);
	void DrawFilledRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode);
	U16 DrawChar(S16 x, S16 y, U8 ch, DrawMode mode, const Font& font); //returns width of character, including margin
	U16 DrawText(S16 x, S16 y, const U8* str, DrawMode mode, const Font& font); //returns width of text
};

#endif // _DISPLAY_H_
