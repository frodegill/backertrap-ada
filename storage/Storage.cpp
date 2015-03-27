
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Storage.h"


Storage::Storage(int (*vtable)(void* storage, VTABLE_FUNC vfunc, void* param))
: m_vtable(vtable)
{
}
