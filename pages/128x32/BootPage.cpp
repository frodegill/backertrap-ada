
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "BootPage.h"
#include "../../BackertrapAdaApp.h"


static PROGMEM_DECLARE(U8, BACKERTRAP_ADA_p[])   = "Backertrap Ada";
static PROGMEM_DECLARE(U8, PRESS_ANY_BUTTON_p[]) = "[Press any button]";


int BootPage128x32VTable(void* page, Page::VTABLE_FUNC vfunc, void* param)
{
	BootPage128x32* native_page = static_cast<BootPage128x32*>(page);
	switch(vfunc)
	{
		case Page::OnActivatedFunc:
			native_page->OnActivated();
			break;

		case Page::OnButtonDownFunc:
			native_page->OnButtonDown(*reinterpret_cast<U8*>(param));
			break;

		default:  break;
	}
	return 0;
}


BootPage128x32::BootPage128x32()
: Page(::BootPage128x32VTable, Page::BOOTPAGE)
{
}

BootPage128x32::~BootPage128x32()
{
}

void BootPage128x32::OnActivated()
{
	Display* display = APP()->GetDisplayManager()->GetDisplay();
	const Font* symbols = APP()->GetFontManager()->GetFont(FontManager::SYMBOLS);
	const Font* generic12px = APP()->GetFontManager()->GetFont(FontManager::GENERIC_12PX);
	const Font* generic7px = APP()->GetFontManager()->GetFont(FontManager::GENERIC_7PX);

	display->ClearFramebuffer();

	display->DrawChar(0,    0, SymbolsFont::BACK, Display::OR, *symbols);
	display->DrawChar(123,  0, SymbolsFont::UP,   Display::OR, *symbols);
	display->DrawChar(0,   27, SymbolsFont::OK,   Display::OR, *symbols);
	display->DrawChar(123, 27, SymbolsFont::DOWN, Display::OR, *symbols);

	display->DrawText(16, 6, &BACKERTRAP_ADA_p[0], Display::OR, *generic12px);
	display->DrawText(16, 20, &PRESS_ANY_BUTTON_p[0], Display::OR, *generic7px);

	display->SwapBuffers();
}

void BootPage128x32::OnButtonDown(U8 button)
{
	APP()->GetPageManager()->PushPage(Page::MAINPAGE);
}
