
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "font.h"

#include "xmega/utils/progmem.h"


static PROGMEM_DECLARE(U8, g_VolterFont9_alphabet_p[]) = "!\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz{}";

static PROGMEM_DECLARE(U8, g_VolterFont9_font_p[]) = {
CHAR_SIZE(4,0,0), //[SPACE]

CHAR_SIZE(1,7,0), //!
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b00000000,
0b10000000,

CHAR_SIZE(3,2,0), //"
0b10100000,
0b10100000,

CHAR_SIZE(6,6,0), //#
0b01001000,
0b11111100,
0b01001000,
0b01001000,
0b11111100,
0b01001000,

CHAR_SIZE(7,7,0), //%
0b01000010,
0b10100100,
0b01001000,
0b00010000,
0b00100100,
0b01001010,
0b10000100,

CHAR_SIZE(6,7,0), //&
0b00110000,
0b01001000,
0b01001000,
0b01110000,
0b10010100,
0b10001000,
0b01110100,

CHAR_SIZE(1,2,0), //'
0b10000000,
0b10000000,

CHAR_SIZE(3,7,0), //(
0b01100000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b01100000,

CHAR_SIZE(3,7,0), //)
0b11000000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b11000000,

CHAR_SIZE(5,5,0), //*
0b00100000,
0b10101000,
0b01110000,
0b10101000,
0b00100000,

CHAR_SIZE(5,5,2), //+
0b00100000,
0b00100000,
0b11111000,
0b00100000,
0b00100000,

CHAR_SIZE(2,4,5), //,
0b11000000,
0b11000000,
0b01000000,
0b10000000,

CHAR_SIZE(5,1,4), //-
0b11111000,

CHAR_SIZE(2,2,5), //.
0b11000000,
0b11000000,

CHAR_SIZE(7,7,0), // /
0b00000010,
0b00000100,
0b00001000,
0b00010000,
0b00100000,
0b01000000,
0b10000000,

CHAR_SIZE(5,7,0), //0
0b01110000,
0b10001000,
0b10011000,
0b10101000,
0b11001000,
0b10001000,
0b01110000,

CHAR_SIZE(2,7,0), //1
0b11000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,

CHAR_SIZE(5,7,0), //2
0b11110000,
0b00001000,
0b00001000,
0b01110000,
0b10000000,
0b10000000,
0b11111000,

CHAR_SIZE(5,7,0), //3
0b11110000,
0b00001000,
0b00001000,
0b01110000,
0b00001000,
0b00001000,
0b11110000,

CHAR_SIZE(5,7,0), //4
0b00010000,
0b00110000,
0b01010000,
0b10010000,
0b11111000,
0b00010000,
0b00010000,

CHAR_SIZE(5,7,0), //5
0b11111000,
0b10000000,
0b10000000,
0b11110000,
0b00001000,
0b00001000,
0b11110000,

CHAR_SIZE(5,7,0), //6
0b01110000,
0b10000000,
0b10000000,
0b11110000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //7
0b11111000,
0b00001000,
0b00010000,
0b00010000,
0b00100000,
0b00100000,
0b01000000,

CHAR_SIZE(5,7,0), //8
0b01110000,
0b10001000,
0b10001000,
0b01110000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //9
0b01110000,
0b10001000,
0b10001000,
0b01111000,
0b00001000,
0b00001000,
0b01110000,

CHAR_SIZE(2,5,2), //:
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,

CHAR_SIZE(2,7,2), //;
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,
0b01000000,
0b10000000,

CHAR_SIZE(4,7,0), //<
0b00010000,
0b00100000,
0b01000000,
0b10000000,
0b01000000,
0b00100000,
0b00010000,

CHAR_SIZE(5,3,3), //=
0b11111000,
0b00000000,
0b11111000,

CHAR_SIZE(4,7,0), //>
0b10000000,
0b01000000,
0b00100000,
0b00010000,
0b00100000,
0b01000000,
0b10000000,

CHAR_SIZE(5,7,0), //?
0b01110000,
0b10001000,
0b00001000,
0b00010000,
0b00100000,
0b00000000,
0b00100000,

CHAR_SIZE(7,7,0), //@
0b01111100,
0b10000010,
0b10111010,
0b10101010,
0b10111110,
0b10000000,
0b01111100,

CHAR_SIZE(5,7,0), //A
0b01110000,
0b10001000,
0b10001000,
0b11111000,
0b10001000,
0b10001000,
0b10001000,

CHAR_SIZE(5,7,0), //B
0b11110000,
0b10001000,
0b10001000,
0b11110000,
0b10001000,
0b10001000,
0b11110000,

CHAR_SIZE(5,7,0), //C
0b01110000,
0b10001000,
0b10000000,
0b10000000,
0b10000000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //D
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b11110000,

CHAR_SIZE(5,7,0), //E
0b11111000,
0b10000000,
0b10000000,
0b11110000,
0b10000000,
0b10000000,
0b11111000,

CHAR_SIZE(5,7,0), //F
0b11111000,
0b10000000,
0b10000000,
0b11110000,
0b10000000,
0b10000000,
0b10000000,

CHAR_SIZE(5,7,0), //G
0b01110000,
0b10001000,
0b10000000,
0b10111000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //H
0b10001000,
0b10001000,
0b10001000,
0b11111000,
0b10001000,
0b10001000,
0b10001000,

CHAR_SIZE(3,7,0), //I
0b11100000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b11100000,

CHAR_SIZE(5,7,0), //J
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //K
0b10001000,
0b10010000,
0b10100000,
0b11000000,
0b10100000,
0b10010000,
0b10001000,

CHAR_SIZE(5,7,0), //L
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b11111000,

CHAR_SIZE(6,7,0), //M
0b10000100,
0b11001100,
0b10110100,
0b10000100,
0b10000100,
0b10000100,
0b10000100,

CHAR_SIZE(5,7,0), //N
0b10001000,
0b10001000,
0b11001000,
0b10101000,
0b10011000,
0b10001000,
0b10001000,

CHAR_SIZE(5,7,0), //O
0b01110000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //P
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b11110000,
0b10000000,
0b10000000,

CHAR_SIZE(6,8,0), //Q
0b01110000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b10011000,
0b01111000,
0b00000100,

CHAR_SIZE(5,7,0), //R
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b11110000,
0b10010000,
0b10001000,

CHAR_SIZE(5,7,0), //S
0b01110000,
0b10001000,
0b10000000,
0b01110000,
0b00001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //T
0b11111000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,

CHAR_SIZE(5,7,0), //U
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //V
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b01010000,
0b01010000,
0b00100000,

CHAR_SIZE(7,7,0), //W
0b10000010,
0b10000010,
0b10010010,
0b10010010,
0b01010100,
0b01010100,
0b00101000,

CHAR_SIZE(5,7,0), //X
0b10001000,
0b10001000,
0b01010000,
0b00100000,
0b01010000,
0b10001000,
0b10001000,

CHAR_SIZE(5,7,0), //Y
0b10001000,
0b10001000,
0b10001000,
0b01010000,
0b00100000,
0b00100000,
0b00100000,

CHAR_SIZE(5,7,0), //Z
0b11111000,
0b00001000,
0b00010000,
0b00100000,
0b01000000,
0b10000000,
0b11111000,

CHAR_SIZE(3,7,0), //[
0b11100000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b11100000,

CHAR_SIZE(3,7,0), //]
0b11100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b11100000,

CHAR_SIZE(5,1,6), //_
0b11111000,

CHAR_SIZE(5,5,2), //a
0b01110000,
0b00001000,
0b01111000,
0b10001000,
0b01111000,

CHAR_SIZE(5,7,0), //b
0b10000000,
0b10000000,
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b11110000,

CHAR_SIZE(5,5,2), //c
0b01110000,
0b10001000,
0b10000000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,0), //d
0b00001000,
0b00001000,
0b01111000,
0b10001000,
0b10001000,
0b10001000,
0b01111000,

CHAR_SIZE(5,5,2), //e
0b01110000,
0b10001000,
0b11111000,
0b10000000,
0b01111000,

CHAR_SIZE(4,7,0), //f
0b00110000,
0b01000000,
0b11100000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,

CHAR_SIZE(5,7,2), //g
0b01111000,
0b10001000,
0b10001000,
0b10001000,
0b01111000,
0b00001000,
0b01110000,

CHAR_SIZE(5,7,0), //h
0b10000000,
0b10000000,
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,

CHAR_SIZE(1,7,0), //i
0b10000000,
0b00000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,

CHAR_SIZE(2,9,0), //j
0b01000000,
0b00000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b10000000,

CHAR_SIZE(4,7,0), //k
0b10000000,
0b10000000,
0b10010000,
0b10100000,
0b11000000,
0b10100000,
0b10010000,

CHAR_SIZE(1,7,0), //l
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,

CHAR_SIZE(7,5,2), //m
0b11111100,
0b10010010,
0b10010010,
0b10010010,
0b10010010,

CHAR_SIZE(5,5,2), //n
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b10001000,

CHAR_SIZE(5,5,2), //o
0b01110000,
0b10001000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,7,2), //p
0b11110000,
0b10001000,
0b10001000,
0b10001000,
0b11110000,
0b10000000,
0b10000000,

CHAR_SIZE(5,7,2), //q
0b01111000,
0b10001000,
0b10001000,
0b10001000,
0b01111000,
0b00001000,
0b00001000,

CHAR_SIZE(4,5,2), //r
0b10110000,
0b11000000,
0b10000000,
0b10000000,
0b10000000,

CHAR_SIZE(5,5,2), //s
0b01111000,
0b10000000,
0b01110000,
0b00001000,
0b11110000,

CHAR_SIZE(4,7,0), //t
0b01000000,
0b01000000,
0b11110000,
0b01000000,
0b01000000,
0b01000000,
0b00110000,

CHAR_SIZE(5,5,2), //u
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b01110000,

CHAR_SIZE(5,5,2), //v
0b10001000,
0b10001000,
0b01010000,
0b01010000,
0b00100000,

CHAR_SIZE(7,5,2), //w
0b10010010,
0b10010010,
0b10010010,
0b10010010,
0b01101100,

CHAR_SIZE(5,5,2), //x
0b10001000,
0b01010000,
0b00100000,
0b01010000,
0b10001000,

CHAR_SIZE(5,7,2), //y
0b10001000,
0b10001000,
0b10001000,
0b10001000,
0b01111000,
0b00001000,
0b01110000,

CHAR_SIZE(5,5,2), //z
0b11111000,
0b00010000,
0b00100000,
0b01000000,
0b11111000,

CHAR_SIZE(4,7,0), //{
0b00110000,
0b01000000,
0b01000000,
0b10000000,
0b01000000,
0b01000000,
0b00110000,

CHAR_SIZE(4,7,0), //}
0b11000000,
0b00100000,
0b00100000,
0b00010000,
0b00100000,
0b00100000,
0b11000000
};

VolterFont9::VolterFont9()
: Font(9, 1, &g_VolterFont9_alphabet_p[0], &g_VolterFont9_font_p[0])
{
}

VolterFont9::~VolterFont9()
{
}

U8 VolterFont9::GetAlphabetByte(U8 pos) const
{
	return pgm_read_byte(&g_VolterFont9_font_p[pos]);
}

U8 VolterFont9::GetFontdataByte(U16 ch_offset, U8 pos) const
{
	return pgm_read_byte(&g_VolterFont9_font_p[ch_offset+pos]);
}
