
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "PowerManager.h"
#include "../BackertrapAdaApp.h"


void PowerManagerTimerCallback(TimerManager::TimerId id, void* calling_object, U8 param)
{
	static_cast<PowerManager*>(calling_object)->OnTimerEvent(id, param);
}


PowerManager::PowerManager()
{
}

PowerManager::~PowerManager()
{
}

void PowerManager::OnTimerEvent(TimerManager::TimerId id, U8 UNUSED_PARAM(param>))
{
	switch(id)
	{
		case TimerManager::BACKLIGHT_TIMEOUT: APP()->GetDisplayManager()->GetDisplay()->SetBacklightStatus(Display::OFF); break;
		default: break;
	}
}

void PowerManager::RegisterActivity()
{
	APP()->GetTimerManager()->ResetTimeout(TimerManager::BACKLIGHT_TIMEOUT, 20, TimerManager::SECOND, ::PowerManagerTimerCallback, this, 0); //ToDo: Load from settings
}

void PowerManager::SleepIDLE() const
{
	sleep_set_mode(SLEEP_SMODE_IDLE_gc);
	sleep_enable();
	sleep_enter();
	sleep_disable();
}
