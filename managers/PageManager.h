#ifndef _PAGE_MANAGER_H_
#define _PAGE_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../defines.h"

#ifdef DISPLAY_NHDC12832A1ZFSWFBW3V3
# include "../pages/128x32/BootPage.h"
#endif


class PageManager
{
public:
	
public:
	PageManager();
	~PageManager();
	
public:
	void PushPage(Page::PageId id);
	void PopPage();

private:
	Page* GetCurrentPage();

private:
	BootPage m_bootpage;

	Page::PageId m_page_list[MAX_PAGE_STACK_SIZE];
	byte         m_page_list_length;
};

#endif // _PAGE_MANAGER_H_
