
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
	    !m_display_manager.Init() ||
		  !m_page_manager.Init())
	{
    return false;
	}

#if 0
	touch_init();
	adc_sensors_init();

	// Initialize USB CDC class
	cdc_start();


	// Display a splash screen showing button functions
	button_splash();

	// Set timezone from EEPROM or to a default value
	timezone_init();

	/* Main loop. Read keyboard status and pass input to menu system.
	 * When an element has been selected in the menu, it will return the
	 * index of the element that should be run. This can be an application
	 * or another menu.
	 */
	while (true) {

		// (re)initialize menu system
		gfx_mono_menu_init(&main_menu);

		do {
			do {
				keyboard_get_key_state(&input);
			// Wait for key release
			} while (input.type != KEYBOARD_RELEASE);

			// Send key to menu system
			menu_status = gfx_mono_menu_process_key(&main_menu, input.keycode);
		// Wait for something useful to happen in the menu system
		} while (menu_status == GFX_MONO_MENU_EVENT_IDLE);

		switch (menu_status) {
		case 0:
			ntc_sensor_application();
			break;
		case 1:
			lightsensor_application();
			break;
		case 2:
			production_date_application();
			break;
		case 3:
			date_time_application();
			break;
		case 4:
			// Toggle LCD Backlight
			gpio_toggle_pin(NHD_C12832A1Z_BACKLIGHT);
			break;
		case GFX_MONO_MENU_EVENT_EXIT:
			// Fall trough to default and show button splash
		default:
			button_splash();
			break;
		};
	}
#endif
  return true;
}

void BackertrapAdaApp::Run()
{
	m_page_manager.PushPage(Page::BOOTPAGE);
	
	while(true)
	{
	}
}

/********************************/

BackertrapAdaApp g_app;
BackertrapAdaApp* APP() {return &g_app;}

int main()
{
	if (g_app.Init())
	{
		g_app.Run();
	}

	return 0;
}
