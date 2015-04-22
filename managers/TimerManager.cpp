
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"

#include "../3rd-party/Atmel/common/services/clock/sysclk.h"
#include "../3rd-party/Atmel/xmega/drivers/rtc32/rtc32.h"


TimerManager::TimerManager()
: m_timed_events_list_length(0)
{
}

TimerManager::~TimerManager()
{
}

bool TimerManager::Init()
{
  sysclk_init();

	//From ASF:
	// Workaround for known issue: Enable RTC32 sysclk
	sysclk_enable_module(SYSCLK_PORT_GEN, SYSCLK_RTC);
	while (RTC32.SYNCCTRL & RTC32_SYNCBUSY_bm) {
		// Wait for RTC32 sysclk to become stable
	}
	// If we have battery power and RTC is running, don't initialize RTC32
	if (rtc_vbat_system_check(false) != VBAT_STATUS_OK) {
		rtc_init();
	}

  return true;
}

void TimerManager::SetTimeout(TimerId UNUSED_PARAM(id), U32 UNUSED_PARAM(delay), Unit UNUSED_PARAM(unit))
{
}

void TimerManager::ResetTimeout(TimerId UNUSED_PARAM(id), U32 UNUSED_PARAM(delay), Unit UNUSED_PARAM(unit))
{
}
