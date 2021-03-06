#ifndef _BACKERTRAP_ADA_APP_H_
#define _BACKERTRAP_ADA_APP_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "managers/ButtonManager.h"
#include "managers/CameraManager.h"
#include "managers/DisplayManager.h"
#include "managers/ExecutionManager.h"
#include "managers/FlashManager.h"
#include "managers/FontManager.h"
#include "managers/GPIOManager.h"
#include "managers/PageManager.h"
#include "managers/PowerManager.h"
#include "managers/SensorManager.h"
#include "managers/StorageManager.h"
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
	CameraManager* GetCameraManager() {return &m_camera_manager;}
	DisplayManager* GetDisplayManager() {return &m_display_manager;}
	ExecutionManager* GetExecutionManager() {return &m_execution_manager;}
	FlashManager* GetFlashManager() {return &m_flash_manager;}
	FontManager* GetFontManager() {return &m_font_manager;}
	GPIOManager* GetGPIOManager() {return &m_gpio_manager;}
	PageManager* GetPageManager() {return &m_page_manager;}
	PowerManager* GetPowerManager() {return &m_power_manager;}
	SensorManager* GetSensorManager() {return &m_sensor_manager;}
	StorageManager* GetStorageManager() {return &m_storage_manager;}
	TimerManager* GetTimerManager() {return &m_timer_manager;}
	
private:
	ButtonManager    m_button_manager;
	CameraManager    m_camera_manager;
	DisplayManager   m_display_manager;
	ExecutionManager m_execution_manager;
	FlashManager     m_flash_manager;
	FontManager      m_font_manager;
	GPIOManager      m_gpio_manager;
	PageManager      m_page_manager;
	PowerManager     m_power_manager;
	SensorManager    m_sensor_manager;
	StorageManager   m_storage_manager;
	TimerManager     m_timer_manager;
};

BackertrapAdaApp* APP();


#endif // _BACKERTRAP_ADA_APP_H_
