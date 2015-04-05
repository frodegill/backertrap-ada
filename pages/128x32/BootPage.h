#ifndef _BOOT_PAGE_H_
#define _BOOT_PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Page.h"


class BootPage128x32 : public Page
{
public:
	BootPage128x32();
	~BootPage128x32();

public:
	void OnActivated();
	void OnDeactivated();

};

#endif // _BOOT_PAGE_H_
