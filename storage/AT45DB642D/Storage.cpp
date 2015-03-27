
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Storage.h"


int StorageAT45DB642DVTable(void* storage, Storage::VTABLE_FUNC vfunc, void* param)
{
	StorageAT45DB642D* native_storage = static_cast<StorageAT45DB642D*>(storage);
	switch(vfunc)
	{
	}
	return 0;
}


StorageAT45DB642D::StorageAT45DB642D()
: Storage(::StorageAT45DB642DVTable)
{
}

StorageAT45DB642D::~StorageAT45DB642D()
{
}
