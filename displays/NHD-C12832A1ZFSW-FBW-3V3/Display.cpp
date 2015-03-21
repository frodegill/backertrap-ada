
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


DisplayNHDC12832A1ZFSWFBW3V3::DisplayNHDC12832A1ZFSWFBW3V3()
: Display()
{
}

DisplayNHDC12832A1ZFSWFBW3V3::~DisplayNHDC12832A1ZFSWFBW3V3()
{
}

void DisplayNHDC12832A1ZFSWFBW3V3::SetBacklightStatus(Display::BacklightStatus status)
{
    ioport_set_pin_level(NHD_C12832A1Z_BACKLIGHT, Display::OFF != status);
}
