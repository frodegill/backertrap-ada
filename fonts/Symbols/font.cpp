
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "font.h"

#include "xmega/utils/progmem.h"


const U8 g_SymbolsFont_alphabet_p[] PROGMEM = {
	SymbolsFont::UP,
	SymbolsFont::DOWN,
	SymbolsFont::BACK,
	SymbolsFont::OK,
	0
};

const U8 g_SymbolsFont_font_p[] PROGMEM = {
CHAR_SIZE(4,4,0), //UP
0b11010000,
0b10000000,
0b11010000,
0b11010000,

CHAR_SIZE(4,4,0), //DOWN
0b11010000,
0b11010000,
0b10000000,
0b11010000,

CHAR_SIZE(4,4,0), //BACK
0b10110000,
0b00000000,
0b10110000,
0b11110000,

CHAR_SIZE(4,4,0), //OK
0b11110000,
0b11100000,
0b01010000,
0b10110000
};

SymbolsFont::SymbolsFont()
: Font(4, 1, &g_SymbolsFont_alphabet_p[0], &g_SymbolsFont_font_p[0])
{
}

SymbolsFont::~SymbolsFont()
{
}
