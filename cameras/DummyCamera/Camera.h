#ifndef _CAMERA_DUMMY_H_
#define _CAMERA_DUMMY_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Camera.h"


// A class implementing a camera without any kind of protocol or intelligence

class CameraDummy : public Camera
{
public:
	CameraDummy();
	~CameraDummy();

public:
	void SetAperture(double UNUSED_PARAM(aperture)) {}
  void SetShutter(double UNUSED_PARAM(shutter)) {}
  void TakePicture() {}

};

#endif // _CAMERA_DUMMY_H_
