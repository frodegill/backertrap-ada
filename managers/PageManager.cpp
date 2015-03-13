
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../pch.h"
#else
#endif

#include "PageManager.h"


PageManager::PageManager()
: m_page_list_length(0)
{
}

PageManager::~PageManager()
{
	while (0 < m_page_list_length)
	{
		PopPage();
	}
}

void PageManager::PushPage(Page::PageId id)
{
	if (MAX_PAGE_STACK_SIZE > (m_page_list_length+1))
	{
		Page* current_page = GetCurrentPage();
		if (current_page)
			current_page->OnDeactivated();

		m_page_list[m_page_list_length++] = id;

		current_page = GetCurrentPage();
		if (current_page)
			current_page->OnActivated();
	}
}

void PageManager::PopPage()
{
	if (0 < m_page_list_length)
	{
		Page* current_page = GetCurrentPage();
		if (current_page)
			current_page->OnDeactivated();

		m_page_list_length--;

		current_page = GetCurrentPage();
		if (current_page)
			current_page->OnActivated();
	}
}

Page* PageManager::GetCurrentPage()
{
	if (0 == m_page_list_length)
		return NULL;

	switch(m_page_list[m_page_list_length-1])
	{
		case Page::BOOTPAGE: return &m_bootpage;

		default: return NULL;
	}
}
