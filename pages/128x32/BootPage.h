#ifndef _BOOT_PAGE_H_
#define _BOOT_PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../Page.h"
#include "../../fonts/BMPlain/font.h"
#include "../../fonts/BMRizer/font.h"
#include "../../fonts/Volter/font.h"


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
  
private:
  BMPlainFont7 m_BMPlainFont7;
  BMRizerFont6 m_BMRizerFont6;
  VolterFont9  m_VolterFont9;
};

#endif // _BOOT_PAGE_H_
