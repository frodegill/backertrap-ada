#ifndef _PAGE_MANAGER_H_
#define _PAGE_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"
#include "../pages/128x32/BootPage.h"


class PageManager
{
public:
	
public:
	PageManager();
	~PageManager();

	bool Init();
	
public:
	void PushPage(Page::PageId id);
	void PopPage();
	Page* GetCurrentPage();

private:
	BootPage128x32 m_bootpage;

	Page::PageId m_page_list[MAX_PAGE_STACK_SIZE];
	U8           m_page_list_length;
};

#endif // _PAGE_MANAGER_H_
