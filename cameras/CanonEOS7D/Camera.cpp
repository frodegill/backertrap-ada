
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Camera.h"


int CameraCanonEOS7DVTable(void* camera, Camera::VTABLE_FUNC vfunc, void* param)
{
	CameraCanonEOS7D* native_display = static_cast<CameraCanonEOS7D*>(camera);
	switch(vfunc)
	{
		case Camera::SetApertureFunc:
			native_display->SetAperture(*reinterpret_cast<double*>(param));
			break;

		case Camera::SetShutterFunc:
			native_display->SetShutter(*reinterpret_cast<double*>(param));
			break;

		case Camera::TakePictureFunc:
			native_display->TakePicture();
			break;
	}
	return 0;
}


CameraCanonEOS7D::CameraCanonEOS7D()
: Camera(::CameraCanonEOS7DVTable)
{
}

CameraCanonEOS7D::~CameraCanonEOS7D()
{
}
