#ifndef _BACKERTRAP_ADA_APP_H_
#define _BACKERTRAP_ADA_APP_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "managers/ButtonManager.h"
#include "managers/DisplayManager.h"
#include "managers/FontManager.h"
#include "managers/PageManager.h"
#include "managers/PowerManager.h"
#include "managers/SensorManager.h"
#include "managers/TimerManager.h"


class BackertrapAdaApp
{
public:
	BackertrapAdaApp();
	~BackertrapAdaApp();

	bool Init();
	void Run();

public:
	ButtonManager* GetButtonManager() {return &m_button_manager;}
	DisplayManager* GetDisplayManager() {return &m_display_manager;}
	FontManager* GetFontManager() {return &m_font_manager;}
	PageManager* GetPageManager() {return &m_page_manager;}
	PowerManager* GetPowerManager() {return &m_power_manager;}
	SensorManager* GetSensorManager() {return &m_sensor_manager;}
	TimerManager* GetTimerManager() {return &m_timer_manager;}
	
private:
	ButtonManager  m_button_manager;
	DisplayManager m_display_manager;
	FontManager    m_font_manager;
	PageManager    m_page_manager;
	PowerManager   m_power_manager;
	SensorManager  m_sensor_manager;
	TimerManager   m_timer_manager;
};

BackertrapAdaApp* APP();


#endif // _BACKERTRAP_ADA_APP_H_
