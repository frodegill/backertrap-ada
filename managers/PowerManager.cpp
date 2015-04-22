
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "PowerManager.h"
#include "../BackertrapAdaApp.h"


PowerManager::PowerManager()
{
}

PowerManager::~PowerManager()
{
}

void PowerManager::RegisterActivity()
{
	APP()->GetTimerManager()->ResetTimeout(TimerManager::BACKLIGHT_TIMEOUT, 20, TimerManager::SECOND); //ToDo: Load from settings
}
