#ifndef _STORAGE_H_
#define _STORAGE_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


class Storage
{
public:
	enum VTABLE_FUNC
	{
	};

public:
	Storage(int (*vtable)(void* storage, VTABLE_FUNC vfunc, void* param));

public: //Atmel - Why no virtual!?!

private:
	int (* m_vtable)(void* storage, VTABLE_FUNC vfunc, void* param);
};

#endif // _STORAGE_H_
