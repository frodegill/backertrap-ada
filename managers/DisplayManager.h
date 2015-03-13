#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"

#ifdef DISPLAY_NHDC12832A1ZFSWFBW3V3
# include "../displays/NHD-C12832A1ZFSW-FBW-3V3/Display.h"
#endif


class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();
	
private:
	Display m_display;
};

#endif // _DISPLAY_MANAGER_H_
