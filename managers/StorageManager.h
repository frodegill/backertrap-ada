#ifndef _STORAGE_MANAGER_H_
#define _STORAGE_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#ifdef STORAGE_AT45DB642D
# include "../storage/AT45DB642D/Storage.h"
#endif


class StorageManager
{
public:
	StorageManager();
	~StorageManager();

public:
	bool LoadProgram(U8 program_id) const;

};

#endif // _STORAGE_MANAGER_H_
