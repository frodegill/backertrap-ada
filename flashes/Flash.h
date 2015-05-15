#ifndef _FLASH_H_
#define _FLASH_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#include "../managers/TimerManager.h"

#define DEFAULT_FLASH_DURATION_MS	(10)


class Flash
{
public:
	Flash();

	void TriggerFlash() const; //Quick'n'dirty triggering of flash
	void TimerCallback();

};

#endif // _FLASH_H_
