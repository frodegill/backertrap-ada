
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "BootPage.h"


int BootPage128x32VTable(void* page, Page::VTABLE_FUNC vfunc, void* param)
{
	BootPage128x32* native_page = static_cast<BootPage128x32*>(page);
	switch(vfunc)
	{
		case Page::OnActivatedFunc:
			native_page->OnActivated();
			break;

		case Page::OnDeactivatedFunc:
			native_page->OnDeactivated();
			break;
	}
	return 0;
}


BootPage128x32::BootPage128x32()
: Page(::BootPage128x32VTable, Page::BOOTPAGE)
{
}

BootPage128x32::~BootPage128x32()
{
}

void BootPage128x32::OnActivated()
{
}

void BootPage128x32::OnDeactivated()
{
}
