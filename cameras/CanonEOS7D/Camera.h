#ifndef _CAMERA_CANONEOS7D_H_
#define _CAMERA_CANONEOS7D_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Camera.h"


class CameraCanonEOS7D : public Camera
{
public:
	CameraCanonEOS7D();
	~CameraCanonEOS7D();

public:
	void SetAperture(double UNUSED_PARAM(aperture)) {}
  void SetShutter(double UNUSED_PARAM(shutter)) {}
  void TakePicture() {}

};

#endif // _CAMERA_CANONEOS7D_H_
