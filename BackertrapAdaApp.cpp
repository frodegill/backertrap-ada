
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "BackertrapAdaApp.h"

#include "3rd-party/Atmel/common/boards/board.h"


BackertrapAdaApp::BackertrapAdaApp()
{
}

BackertrapAdaApp::~BackertrapAdaApp()
{
}

bool BackertrapAdaApp::Init()
{
  if (!m_timer_manager.Init())
    return false;

  board_init();
  pmic_init();

  if (!m_button_manager.Init() ||
	    !m_display_manager.Init())
	{
    return false;
	}

  return true;
}

/********************************/

int main()
{
	BackertrapAdaApp app;
	app.Init();

	return 0;
}
