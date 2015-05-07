
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "ButtonManager.h"

#include "../3rd-party/Atmel/xmega/drivers/qtouch/touch_api.h"
#include "../BackertrapAdaApp.h"


ButtonManager::ButtonManager()
: m_buttons_down_mask(0)
{
	m_button_port[BUTTON_UPPER_LEFT] = GPIO_PUSH_BUTTON_0;
	m_button_port[BUTTON_UPPER_RIGHT] = GPIO_PUSH_BUTTON_1;
	m_button_port[BUTTON_LOWER_LEFT] = 0;
	m_button_port[BUTTON_LOWER_RIGHT] = GPIO_PUSH_BUTTON_2;
}

ButtonManager::~ButtonManager()
{
}

bool ButtonManager::Init()
{
  touch_init();
  return true;
}

void ButtonManager::PollKeyStates()
{
}

void ButtonManager::OnButtonDown(U8 button)
{
	APP()->GetPageManager()->GetCurrentPage()->OnButtonDown(button);
}

void ButtonManager::OnButtonUp(U8 button)
{
	APP()->GetPageManager()->GetCurrentPage()->OnButtonUp(button);
}
