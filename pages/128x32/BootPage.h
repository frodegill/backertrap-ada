#ifndef _BOOT_PAGE_H_
#define _BOOT_PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../Page.h"


class BootPage : public Page
{
public:
	BootPage();
	~BootPage();

	PageId GetId() {return BOOTPAGE;}

	//From Page
public:
	void OnActivated();
	void OnDeactivated();
};

#endif // _BOOT_PAGE_H_
