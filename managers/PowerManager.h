#ifndef _POWER_MANAGER_H_
#define _POWER_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"


class PowerManager
{
public:
	PowerManager();
	~PowerManager();

public:
	void OnTimerEvent(TimerManager::TimerId id, U8 param);

public:
	void RegisterActivity();

	void SleepIDLE() const;

};

#endif // _POWER_MANAGER_H_
