#ifndef _BACKERTRAP_ADA_APP_H_
#define _BACKERTRAP_ADA_APP_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "managers/DisplayManager.h"
#include "managers/PageManager.h"
#include "managers/PowerManager.h"
#include "managers/SensorManager.h"
#include "managers/TimerManager.h"


class BackertrapAdaApp
{
public:
	BackertrapAdaApp();
	~BackertrapAdaApp();
	
private:
	DisplayManager m_display_manager;
	PageManager    m_page_manager;
	PowerManager   m_power_manager;
	SensorManager  m_sensor_manager;
	TimerManager   m_timer_manager;
};

#endif // _BACKERTRAP_ADA_APP_H_
