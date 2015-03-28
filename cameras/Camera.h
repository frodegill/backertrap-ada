#ifndef _CAMERA_H_
#define _CAMERA_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


class Camera
{
public:
	enum VTABLE_FUNC
	{
		SetApertureFunc,
		SetShutterFunc,
		TakePictureFunc
	};

public:
	Camera(int (*vtable)(void* camera, VTABLE_FUNC vfunc, void* param));

public: //Atmel - Why no virtual!?!
	void SetAperture(double aperture) {m_vtable(this, SetApertureFunc, &aperture);}
	void SetShutter(double shutter) {m_vtable(this, SetShutterFunc, &shutter);}
	void TakePicture()  {m_vtable(this, TakePictureFunc, NULL);}

private:
	int (* m_vtable)(void* camera, VTABLE_FUNC vfunc, void* param);
};

#endif // _CAMERA_H_
