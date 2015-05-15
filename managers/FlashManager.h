#ifndef _FLASH_MANAGER_H_
#define _FLASH_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#include "../flashes/Flash.h"


class FlashManager
{
public:
	FlashManager();
	~FlashManager();

public:
	Flash* GetDefaultFlash() {return &m_default_flash;}

private:
	Flash m_default_flash;
};

#endif // _FLASH_MANAGER_H_
