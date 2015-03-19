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
	uint16 GetWidth() const {return 0;}
	uint16 GetHeight() const {return 0;}
	uint8* GetFramebuffer() const {return NULL;}

public:
	void SetBrightness(double UNUSED(brightness)) {}
	void SetBacklightStatus(BacklightStatus UNUSED(status)) {}

	void ClearDisplay() {}
	void RefreshDisplay() {}

	void DrawPixel(sint16 x, sint16 y, DrawMode mode);
	void DrawLine(sint16 x, sint16 y, uint16 delta_x, uint16 delta_y, DrawMode mode);
	void DrawRect(sint16 x, sint16 y, uint16 width, uint16 height, DrawMode mode);
	void DrawFilledRect(sint16 x, sint16 y, uint16 width, uint16 height, DrawMode mode);
	uint16 DrawChar(sint16 x, sint16 y, uint8 ch, DrawMode mode, const Font& font); //returns width of character, including margin
	uint16 DrawText(sint16 x, sint16 y, uint8* str, DrawMode mode, const Font& font); //returns width of text
};

#endif // _DISPLAY_H_
