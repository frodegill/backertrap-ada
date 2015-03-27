
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Page.h"


Page::Page(int (*vtable)(void* display, VTABLE_FUNC vfunc, void* param), PageId id)
: m_vtable(vtable),
  m_id(id)
{
}
