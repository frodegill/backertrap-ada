#ifndef _DAVID_DEVICE_FONT_9_H_
#define _DAVID_DEVICE_FONT_9_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license
//
// Font-data from <URL: http://www.dafont.com/david-device.font?fpp=100 >

#include "../../defines.h"
#include "../font.h"


class DavidDeviceFont9 : public Font
{
public:
  DavidDeviceFont9();
  ~DavidDeviceFont9();

public:
	U8 GetFontHeight() const {return 9;}

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_DAVID_DEVICE_FONT_9_H_
