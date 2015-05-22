
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "GPIOManager.h"


GPIOManager::GPIOManager()
{
}

GPIOManager::~GPIOManager()
{
}

void GPIOManager::SetPinState(U8 pin, U8 state)
{
	switch(state)
	{
		case LOW: gpio_set_pin_low(pin); break;
		case HIGH: gpio_set_pin_high(pin); break;
	}
}

U8 GPIOManager::GetPinState(U8 pin) const
{
	return ioport_pin_is_low(pin) ? LOW : HIGH;
}
