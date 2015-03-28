
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Camera.h"


Camera::Camera(int (*vtable)(void* camera, VTABLE_FUNC vfunc, void* param))
: m_vtable(vtable)
{
}
