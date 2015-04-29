#ifndef _MAIN_PAGE_H_
#define _MAIN_PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../Page.h"


class MainPage128x32 : public Page
{
public:
	MainPage128x32();
	~MainPage128x32();

public:
	void OnActivated();
	void OnDeactivated();
	void OnButtonDown(U8 button);
	void OnButtonUp(U8 button);

};

#endif // _MAIN_PAGE_H_
