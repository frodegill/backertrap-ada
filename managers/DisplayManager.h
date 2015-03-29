#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../displays/NHD-C12832A1ZFSW-FBW-3V3/Display.h"


class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	bool Init();

private:
	DisplayNHDC12832A1ZFSWFBW3V3 m_display;
};

#endif // _DISPLAY_MANAGER_H_
