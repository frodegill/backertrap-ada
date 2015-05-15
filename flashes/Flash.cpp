
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Flash.h"

#include "../BackertrapAdaApp.h"


Flash::Flash()
{
}

void Flash::TriggerFlash() const
{
	APP()->GetGPIOManager()->SetPinState(DEFAULT_FLASH_PIN, HIGH);
	APP()->GetTimerManager()->ResetTimeout(TimerManager::FLASH_TRIGGERED_TIMEOUT, DEFAULT_FLASH_DURATION_MS, TimerManager::MILLISECOND);
}

void Flash::TimerCallback()
{
	APP()->GetGPIOManager()->SetPinState(DEFAULT_FLASH_PIN, LOW);
}
