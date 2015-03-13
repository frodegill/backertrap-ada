#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../../defines.h"
#ifdef DISPLAY_NHDC12832A1ZFSWFBW3V3


class Display
{
public:
	enum BacklightStatus
	{
		ON,
		OFF
	};
	
public:
	Display();
	~Display();
	
public:
	void SetBrightness(double UNUSED(brightness)) {}
	void SetBacklightStatus(BacklightStatus UNUSED(status)) {}

	void ClearDisplay() {}
	void RefreshDisplay() {}

};

#endif // DISPLAY_NHDC12832A1ZFSWFBW3V3

#endif // _DISPLAY_H_
