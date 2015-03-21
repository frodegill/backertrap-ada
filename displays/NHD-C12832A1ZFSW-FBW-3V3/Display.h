#ifndef _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_
#define _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Display.h"


class DisplayNHDC12832A1ZFSWFBW3V3 : public Display
{
public:
	DisplayNHDC12832A1ZFSWFBW3V3();
	~DisplayNHDC12832A1ZFSWFBW3V3();

public:
	uint16 GetWidth() const {return 128;}
	uint16 GetHeight() const {return 32;}
	
public:
	void SetBrightness(double UNUSED_PARAM(brightness)) {}
	void SetBacklightStatus(Display::BacklightStatus status);

	void ClearDisplay() {}
	void RefreshDisplay() {}

};

#endif // _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_
