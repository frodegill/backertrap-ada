
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"

#include "../3rd-party/Atmel/common/services/clock/sysclk.h"


TimerManager::TimerManager()
{
}

TimerManager::~TimerManager()
{
}

bool TimerManager::Init()
{
  sysclk_init();
  return true;
}
