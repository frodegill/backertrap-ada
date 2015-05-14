#ifndef _GPIO_MANAGER_H_
#define _GPIO_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


class GPIOManager
{
public:
	GPIOManager();
	~GPIOManager();

public:
	void SetPinState(U8 pin, U8 state);
	U8   GetPinState(U8 pin) const;

};

#endif // _GPIO_MANAGER_H_
