
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


int DisplayNHDC12832A1ZFSWFBW3V3VTable(void* display, Display::VTABLE_FUNC vfunc, void* param)
{
	DisplayNHDC12832A1ZFSWFBW3V3* native_display = static_cast<DisplayNHDC12832A1ZFSWFBW3V3*>(display);
	switch(vfunc)
	{
		case Display::SetBrightnessFunc:
			native_display->SetBrightness(*reinterpret_cast<double*>(param));
			break;

		case Display::SetBacklightStatusFunc:
			native_display->SetBacklightStatus(*reinterpret_cast<Display::BacklightStatus*>(param));
			break;

		case Display::ClearDisplayFunc:
			native_display->ClearDisplay();
			break;

		case Display::RefreshDisplayFunc:
			native_display->RefreshDisplay();
			break;
	}
	return 0;
}


DisplayNHDC12832A1ZFSWFBW3V3::DisplayNHDC12832A1ZFSWFBW3V3()
: Display(::DisplayNHDC12832A1ZFSWFBW3V3VTable, 128, 32, NULL)
{
}

DisplayNHDC12832A1ZFSWFBW3V3::~DisplayNHDC12832A1ZFSWFBW3V3()
{
}

void DisplayNHDC12832A1ZFSWFBW3V3::SetBacklightStatus(Display::BacklightStatus status)
{
    ioport_set_pin_level(NHD_C12832A1Z_BACKLIGHT, Display::OFF != status);
}
