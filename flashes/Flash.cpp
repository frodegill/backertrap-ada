
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Flash.h"

#include "../BackertrapAdaApp.h"


void FlashTimerCallback(TimerManager::TimerId id, void* calling_object, U8 param)
{
	static_cast<Flash*>(calling_object)->OnTimerEvent(id, param);
}


Flash::Flash()
{
}

void Flash::OnTimerEvent(TimerManager::TimerId id, U8 param)
{
	switch(id)
	{
		case TimerManager::FLASH_TRIGGERED_TIMEOUT: APP()->GetGPIOManager()->SetPinState(param, LOW); break;
		default: break;
	}
}

void Flash::TriggerFlash()
{
	APP()->GetGPIOManager()->SetPinState(DEFAULT_FLASH_PIN, HIGH);
	APP()->GetTimerManager()->ResetTimeout(TimerManager::FLASH_TRIGGERED_TIMEOUT, DEFAULT_FLASH_DURATION_MS, TimerManager::MILLISECOND, ::FlashTimerCallback, this, DEFAULT_FLASH_PIN);
}
