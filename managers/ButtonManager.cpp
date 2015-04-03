
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "ButtonManager.h"

#include "../3rd-party/Atmel/xmega/drivers/qtouch/touch_api.h"


ButtonManager::ButtonManager()
{
}

ButtonManager::~ButtonManager()
{
}

bool ButtonManager::Init()
{
  touch_init();
  return true;
}
