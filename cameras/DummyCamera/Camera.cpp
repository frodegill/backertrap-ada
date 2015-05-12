
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Camera.h"


int CameraDummyVTable(void* camera, Camera::VTABLE_FUNC vfunc, void* param)
{
	CameraDummy* native_camera = static_cast<CameraDummy*>(camera);
	switch(vfunc)
	{
		case Camera::SetApertureFunc:
			native_camera->SetAperture(*reinterpret_cast<double*>(param));
			break;

		case Camera::SetShutterFunc:
			native_camera->SetShutter(*reinterpret_cast<double*>(param));
			break;

		case Camera::TakePictureFunc:
			native_camera->TakePicture();
			break;
	}
	return 0;
}


CameraDummy::CameraDummy()
: Camera(::CameraDummyVTable)
{
}

CameraDummy::~CameraDummy()
{
}
