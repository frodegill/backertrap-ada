
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "font.h"

#include "xmega/utils/progmem.h"


static PROGMEM_DECLARE(U8, g_SymbolsFont_alphabet_p[]) = {
	SymbolsFont::UP,
	SymbolsFont::DOWN,
	SymbolsFont::BACK,
	SymbolsFont::OK,
	0
};

static PROGMEM_DECLARE(U8, g_SymbolsFont_font_p[]) = {
CHAR_SIZE(5,5,0), //UP
0b11011000,
0b10001000,
0b00000000,
0b11011000,
0b11011000,

CHAR_SIZE(5,5,0), //DOWN
0b11011000,
0b11011000,
0b00000000,
0b10001000,
0b11011000,

CHAR_SIZE(5,5,0), //BACK
0b11011000,
0b10011000,
0b00000000,
0b10011000,
0b11011000,

CHAR_SIZE(5,5,0), //OK
0b11111000,
0b11101000,
0b01011000,
0b10111000,
0b11111000
};

SymbolsFont::SymbolsFont()
: Font(5, 1, &g_SymbolsFont_alphabet_p[0], &g_SymbolsFont_font_p[0])
{
}

SymbolsFont::~SymbolsFont()
{
}
