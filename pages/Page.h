#ifndef _PAGE_H_
#define _PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


class Page
{
public:
	enum VTABLE_FUNC
	{
		OnActivatedFunc,
		OnDeactivatedFunc
	};

	enum PageId
	{
		BOOTPAGE
	};

public:
	Page(int (*vtable)(void* display, VTABLE_FUNC vfunc, void* param), PageId id);

public:
	PageId GetId() const {return m_id;}

public: //Atmel - Why no virtual!?!
	void OnActivated() {m_vtable(this, OnActivatedFunc, NULL);}
	void OnDeactivated() {m_vtable(this, OnDeactivatedFunc, NULL);}

private:
	int (* m_vtable)(void* page, VTABLE_FUNC vfunc, void* param);
	PageId m_id;
};

#endif // _PAGE_H_
