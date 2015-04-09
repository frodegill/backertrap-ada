
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "BootPage.h"
#include "../../BackertrapAdaApp.h"


int BootPage128x32VTable(void* page, Page::VTABLE_FUNC vfunc, void* param)
{
	BootPage128x32* native_page = static_cast<BootPage128x32*>(page);
	switch(vfunc)
	{
		case Page::OnActivatedFunc:
			native_page->OnActivated();
			break;

		case Page::OnDeactivatedFunc:
			native_page->OnDeactivated();
			break;
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
	const Font* generic6px = APP()->GetFontManager()->GetFont(FontManager::GENERIC_6PX);

	display->ClearFramebuffer();

	display->DrawChar(0,    0, SymbolsFont::BACK, Display::OR, *symbols);
	display->DrawChar(124,  0, SymbolsFont::UP,   Display::OR, *symbols);
	display->DrawChar(0,   28, SymbolsFont::OK,   Display::OR, *symbols);
	display->DrawChar(124, 28, SymbolsFont::DOWN, Display::OR, *symbols);

	display->DrawText(6, 6, reinterpret_cast<const U8*>("Backertrap Ada"), Display::OR, *generic12px);

	display->DrawText(6, 20, reinterpret_cast<const U8*>("[Press any button]"), Display::OR, *generic6px);

	display->SwapBuffers();
}

void BootPage128x32::OnDeactivated()
{
}
