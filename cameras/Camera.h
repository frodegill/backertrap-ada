#ifndef _CAMERA_H_
#define _CAMERA_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#include "../managers/TimerManager.h"


class Camera
{
public:
	enum ShutterTime
	{
		MIN_SHUTTER = 0,
		SHUTTER_1_4000 = MIN_SHUTTER,
		SHUTTER_1_2000,
		SHUTTER_1_1000,
		SHUTTER_1_500,
		SHUTTER_1_250,
		SHUTTER_1_100,
		SHUTTER_1_60,
		SHUTTER_1_30,
		SHUTTER_1_15,
		SHUTTER_1_8,
		SHUTTER_1_4,
		SHUTTER_1_2,
		SHUTTER_1,
		SHUTTER_2,
		SHUTTER_4,
		SHUTTER_8,
		SHUTTER_16,
		SHUTTER_32,
		SHUTTER_64,
		SHUTTER_128,
		SHUTTER_256,
		SHUTTER_512,
		SHUTTER_1024,
		DEFAULT_SHUTTERTIME = SHUTTER_1_100,
		MAX_SHUTTER = SHUTTER_1024
	};
#define MIN_SHUTTER_INDEX (Camera::MIN_SHUTTER*6+0)
#define MAX_SHUTTER_INDEX (Camera::MAX_SHUTTER*6+5)
#define DEFAULT_SHUTTER_INDEX (Camera::DEFAULT_SHUTTERTIME*6+0)

public:
	enum VTABLE_FUNC
	{
		SetApertureFunc,
		SetShutterFunc,
		TakePictureFunc
	};

public:
	Camera(int (*vtable)(void* camera, VTABLE_FUNC vfunc, void* param));

public:
	void OnTimerEvent(TimerManager::TimerId id, U8 param);

public: //Atmel - Why no virtual!?!
	void SetAperture(double aperture) {m_vtable(this, SetApertureFunc, &aperture);}
	void SetShutter(double shutter) {m_vtable(this, SetShutterFunc, &shutter);}
	void TakePicture()  {m_vtable(this, TakePictureFunc, NULL);}

	void TriggerCamera(const TimerManager::Time& shutter); //Quick'n'dirty triggering of camera 

public:
	U8 PROGMEM_PTR_T GetShutterText(ShutterTime shutter) const;
	void GetShutterSpeed(U8 shutter_index, TimerManager::Time& time);

private:
	int (* m_vtable)(void* camera, VTABLE_FUNC vfunc, void* param);
};

#endif // _CAMERA_H_
