
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "DisplayManager.h"


DisplayManager::DisplayManager()
{
}

DisplayManager::~DisplayManager()
{
}

bool DisplayManager::Init()
{
	return m_display.Init();
}
