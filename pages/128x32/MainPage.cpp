
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "MainPage.h"
#include "../../BackertrapAdaApp.h"


static PROGMEM_DECLARE(U8, LASER_p[])   = "Laser";
static PROGMEM_DECLARE(U8, SOUND_p[])   = "Sound";
static PROGMEM_DECLARE(U8, TIMELAPSE_p[])   = "Timelapse";
static PROGMEM_DECLARE(U8, SETTINGS_p[])   = "Settings";


int MainPage128x32VTable(void* page, Page::VTABLE_FUNC vfunc, void* param)
{
	MainPage128x32* native_page = static_cast<MainPage128x32*>(page);
	switch(vfunc)
	{
		case Page::OnActivatedFunc:
			native_page->OnActivated();
			break;

		case Page::OnDeactivatedFunc:
			native_page->OnDeactivated();
			break;

		case Page::OnButtonDownFunc:
			native_page->OnButtonDown(*reinterpret_cast<U8*>(param));
			break;

		case Page::OnButtonUpFunc:
			native_page->OnButtonUp(*reinterpret_cast<U8*>(param));
			break;
	}
	return 0;
}


MainPage128x32::MainPage128x32()
: Page(::MainPage128x32VTable, Page::MAINPAGE)
{
}

MainPage128x32::~MainPage128x32()
{
}

void MainPage128x32::OnActivated()
{
	Display* display = APP()->GetDisplayManager()->GetDisplay();
	const Font* symbols = APP()->GetFontManager()->GetFont(FontManager::SYMBOLS);
	const Font* generic12px = APP()->GetFontManager()->GetFont(FontManager::GENERIC_12PX);

	display->ClearFramebuffer();

	display->DrawChar(0,    0, SymbolsFont::BACK, Display::OR, *symbols);
	display->DrawChar(123,  0, SymbolsFont::UP,   Display::OR, *symbols);
	display->DrawChar(0,   27, SymbolsFont::OK,   Display::OR, *symbols);
	display->DrawChar(123, 27, SymbolsFont::DOWN, Display::OR, *symbols);

	display->DrawText(16, 6, &LASER_p[0], Display::OR, *generic12px);

	display->SwapBuffers();
}

void MainPage128x32::OnDeactivated()
{
}

void MainPage128x32::OnButtonDown(U8 button)
{
}

void MainPage128x32::OnButtonUp(U8 button)
{
}
