
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "font.h"

#include "xmega/utils/progmem.h"


static PROGMEM_DECLARE(U8, g_BMRizerFont6_alphabet_p[]) = "!\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz";

static PROGMEM_DECLARE(U8, g_BMRizerFont6_font_p[]) = {
CHAR_SIZE(6,0,0), //[SPACE]

CHAR_SIZE(3,5,0), //!
0b11100000,
0b11100000,
0b11100000,
0b00000000,
0b11100000,

CHAR_SIZE(5,2,0), //"
0b11011000,
0b11011000,

CHAR_SIZE(7,5,0), //#
0b01101100,
0b11111110,
0b01101100,
0b11111110,
0b01101100,

CHAR_SIZE(9,5,0), //%
0b11101100, 0b00000000,
0b10101000, 0b00000000,
0b11101011, 0b10000000,
0b00001010, 0b10000000,
0b00011011, 0b10000000,

CHAR_SIZE(8,5,0), //&
0b11111110,
0b11101110,
0b01111100,
0b11101111,
0b11111110,

CHAR_SIZE(2,2,0), //'
0b11000000,
0b11000000,

CHAR_SIZE(4,5,0), //(
0b01110000,
0b11100000,
0b11100000,
0b11100000,
0b01110000,

CHAR_SIZE(4,5,0), //)
0b11100000,
0b01110000,
0b01110000,
0b01110000,
0b11100000,

CHAR_SIZE(4,3,0), //*
0b01100000,
0b11110000,
0b01100000,

CHAR_SIZE(7,5,0), //+
0b00111000,
0b00111000,
0b11111110,
0b00111000,
0b00111000,

CHAR_SIZE(2,3,3), //,
0b11000000,
0b11000000,
0b01000000,

CHAR_SIZE(7,1,2), //-
0b11111110,

CHAR_SIZE(2,2,3), //.
0b11000000,
0b11000000,

CHAR_SIZE(7,5,0), // /
0b00001110,
0b00011100,
0b00111000,
0b01110000,
0b11100000,

CHAR_SIZE(7,5,0), //0
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(4,5,0), //1
0b11110000,
0b01110000,
0b01110000,
0b01110000,
0b01110000,

CHAR_SIZE(7,5,0), //2
0b11111110,
0b00001110,
0b11111110,
0b11100000,
0b11111110,

CHAR_SIZE(7,5,0), //3
0b11111110,
0b00001110,
0b11111110,
0b00001110,
0b11111110,

CHAR_SIZE(7,5,0), //4
0b11101110,
0b11101110,
0b11111110,
0b00001110,
0b00001110,

CHAR_SIZE(7,5,0), //5
0b11111110,
0b11100000,
0b11111110,
0b00001110,
0b11111110,

CHAR_SIZE(7,5,0), //6
0b11111110,
0b11100000,
0b11111110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //7
0b11111110,
0b00001110,
0b00001110,
0b00001110,
0b00001110,

CHAR_SIZE(7,5,0), //8
0b11111110,
0b11101110,
0b11111110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //9
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,

CHAR_SIZE(2,5,0), //:
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,

CHAR_SIZE(2,6,0), //;
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,
0b01000000,

CHAR_SIZE(3,5,0), //<
0b00100000,
0b01100000,
0b11100000,
0b01100000,
0b00100000,

CHAR_SIZE(7,3,1), //=
0b11111110,
0b00000000,
0b11111110,

CHAR_SIZE(3,5,0), //>
0b10000000,
0b11000000,
0b11100000,
0b11000000,
0b10000000,

CHAR_SIZE(7,5,0), //?
0b11111110,
0b00001110,
0b00111110,
0b00000000,
0b00111000,

CHAR_SIZE(8,5,0), //@
0b11111111,
0b11000011,
0b11011111,
0b11011011,
0b11011111,

CHAR_SIZE(7,5,0), //A
0b11111110,
0b11101110,
0b11101110,
0b11111110,
0b11101110,

CHAR_SIZE(7,5,0), //B
0b11111110,
0b11101110,
0b11111100,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //C
0b11111110,
0b11100000,
0b11100000,
0b11100000,
0b11111110,

CHAR_SIZE(7,5,0), //D
0b11111100,
0b11101110,
0b11101110,
0b11101110,
0b11111100,

CHAR_SIZE(7,5,0), //E
0b11111110,
0b11100000,
0b11111110,
0b11100000,
0b11111110,

CHAR_SIZE(7,5,0), //F
0b11111110,
0b11100000,
0b11111110,
0b11100000,
0b11100000,

CHAR_SIZE(7,5,0), //G
0b11111110,
0b11100000,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //H
0b11101110,
0b11101110,
0b11111110,
0b11101110,
0b11101110,

CHAR_SIZE(3,5,0), //I
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11100000,

CHAR_SIZE(7,5,0), //J
0b00001110,
0b00001110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //K
0b11101110,
0b11101110,
0b11111100,
0b11101110,
0b11101110,

CHAR_SIZE(7,5,0), //L
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11111110,

CHAR_SIZE(11,5,0), //M
0b11111111, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,

CHAR_SIZE(7,5,0), //N
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11101110,

CHAR_SIZE(7,5,0), //O
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //P
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11100000,

CHAR_SIZE(7,6,0), //Q
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00111000,

CHAR_SIZE(7,5,0), //R
0b11111110,
0b11101110,
0b11111100,
0b11101110,
0b11101110,

CHAR_SIZE(7,5,0), //S
0b11111110,
0b01110000,
0b00111000,
0b00011100,
0b11111110,

CHAR_SIZE(7,5,0), //T
0b11111110,
0b00111000,
0b00111000,
0b00111000,
0b00111000,

CHAR_SIZE(7,5,0), //U
0b11101110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //V
0b11101110,
0b11101110,
0b11101110,
0b01111100,
0b00111000,

CHAR_SIZE(11,5,0), //W
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11111111, 0b11100000,

CHAR_SIZE(7,5,0), //X
0b11101110,
0b11101110,
0b01111100,
0b11101110,
0b11101110,

CHAR_SIZE(7,5,0), //Y
0b11101110,
0b11101110,
0b01111100,
0b00111000,
0b00111000,

CHAR_SIZE(7,5,0), //Z
0b11111110,
0b00011100,
0b00111000,
0b01110000,
0b11111110,

CHAR_SIZE(4,5,0), //[
0b11110000,
0b11100000,
0b11100000,
0b11100000,
0b11110000,

CHAR_SIZE(4,5,0), //]
0b11110000,
0b01110000,
0b01110000,
0b01110000,
0b11110000,

CHAR_SIZE(7,1,4), //_
0b11111110,

CHAR_SIZE(7,5,0), //a
0b11111110,
0b00001110,
0b11111110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //b
0b11100000,
0b11111110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,4,1), //c
0b11111110,
0b11100000,
0b11100000,
0b11111110,

CHAR_SIZE(7,5,0), //d
0b00001110,
0b11111110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,0), //e
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11111110,

CHAR_SIZE(7,5,0), //f
0b01111110,
0b01110000,
0b11111110,
0b01110000,
0b01110000,

CHAR_SIZE(7,5,1), //g
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,

CHAR_SIZE(7,5,0), //h
0b11100000,
0b11100000,
0b11111110,
0b11101110,
0b11101110,

CHAR_SIZE(3,5,0), //i
0b11100000,
0b00000000,
0b11100000,
0b11100000,
0b11100000,

CHAR_SIZE(7,5,0), //j
0b00001110,
0b00000000,
0b00001110,
0b00001110,
0b11111110,

CHAR_SIZE(7,5,0), //k
0b11100000,
0b11101110,
0b11101000,
0b11111110,
0b11101110,

CHAR_SIZE(4,5,0), //l
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11110000,

CHAR_SIZE(11,4,1), //m
0b11111111, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,

CHAR_SIZE(7,4,1), //n
0b11111110,
0b11101110,
0b11101110,
0b11101110,

CHAR_SIZE(7,4,1), //o
0b11111110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,5,1), //p
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11100000,

CHAR_SIZE(7,5,1), //q
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b00001110,

CHAR_SIZE(6,4,1), //r
0b11111100,
0b11100000,
0b11100000,
0b11100000,

CHAR_SIZE(6,4,1), //s
0b11111100,
0b01110000,
0b00111000,
0b11111100,

CHAR_SIZE(6,5,0), //t
0b11100000,
0b11111100,
0b11100000,
0b11100000,
0b11111100,

CHAR_SIZE(7,4,1), //u
0b11101110,
0b11101110,
0b11101110,
0b11111110,

CHAR_SIZE(7,4,1), //v
0b11101110,
0b11101110,
0b01101100,
0b00111000,

CHAR_SIZE(11,4,1), //w
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11111111, 0b11100000,

CHAR_SIZE(7,4,1), //x
0b11101110,
0b01111100,
0b01111100,
0b11101110,

CHAR_SIZE(7,5,1), //y
0b11101110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,

CHAR_SIZE(6,4,1), //z
0b11111100,
0b00111000,
0b01110000,
0b11111100
};

BMRizerFont6::BMRizerFont6()
: Font(6, 1, &g_BMRizerFont6_alphabet_p[0], &g_BMRizerFont6_font_p[0])
{
}

BMRizerFont6::~BMRizerFont6()
{
}
