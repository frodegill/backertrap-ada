#ifndef _PAGE_H_
#define _PAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license


class Page
{
public:
	enum PageId
	{
		UNKNOWN,
		BOOTPAGE
	};

public:
	Page();
	~Page();

	PageId GetId() {return UNKNOWN;}

public:
	void OnActivated() {}
	void OnDeactivated() {}
};

#endif // _PAGE_H_
