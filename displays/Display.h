#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


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

	void DrawPixel(uint16 x, uint16 y, DrawMode mode);
	void DrawLine(uint16 x, uint16 y, uint16 delta_x, uint16 delta_y, DrawMode mode);
	void DrawRect(uint16 x, uint16 y, uint16 width, uint16 height, DrawMode mode);
	void DrawFilledRect(uint16 x, uint16 y, uint16 width, uint16 height, DrawMode mode);
	uint16 DrawChar(uint16 x, uint16 y, uint8 ch, DrawMode mode); //returns width of character
	uint16 DrawText(uint16 x, uint16 y, uint8* str, DrawMode mode); //returns width of text
};

#endif // _DISPLAY_H_
