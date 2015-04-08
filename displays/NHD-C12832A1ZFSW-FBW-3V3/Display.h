#ifndef _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_
#define _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Display.h"

#define NHDC12832A1ZFSWFBW3V3_WIDTH         (128)
#define NHDC12832A1ZFSWFBW3V3_HEIGHT        (32)
#define NHDC12832A1ZFSWFBW3V3_BYTES_PER_ROW (NHDC12832A1ZFSWFBW3V3_WIDTH/8)
#define NHDC12832A1ZFSWFBW3V3_PAGES         (NHDC12832A1ZFSWFBW3V3_HEIGHT/8)

class DisplayNHDC12832A1ZFSWFBW3V3 : public Display
{
public:
	DisplayNHDC12832A1ZFSWFBW3V3();
	~DisplayNHDC12832A1ZFSWFBW3V3();

  bool Init();

public:
	void SetBrightness(double UNUSED_PARAM(brightness)) {}
	void SetBacklightStatus(Display::BacklightStatus status);

  void ClearFramebuffer();
  void SwapBuffers();

};

#endif // _DISPLAY_NHDC12832A1ZFSWFBW3V3_H_
