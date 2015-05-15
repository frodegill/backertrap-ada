#ifndef _CAMERA_MANAGER_H_
#define _CAMERA_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#include "../cameras/Camera.h"
#include "../cameras/DummyCamera/Camera.h"


class CameraManager
{
public:
	CameraManager();
	~CameraManager();

public:
	Camera* GetDefaultCamera() {return &m_default_camera;}

private:
	CameraDummy m_default_camera;
};

#endif // _CAMERA_MANAGER_H_
