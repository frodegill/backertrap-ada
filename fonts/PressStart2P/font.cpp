
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "font.h"

#include "xmega/utils/progmem.h"


static PROGMEM_DECLARE(U8, g_PressStart2PFont8_alphabeth[]) = "!\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz{}";

static PROGMEM_DECLARE(U8, g_PressStart2PFont8_font[]) = {
CHAR_SIZE(4,0,0), //[SPACE]

CHAR_SIZE(3,7,0), //!
0b11100000,
0b11100000,
0b11100000,
0b11000000,
0b11000000,
0b00000000,
0b11000000,

CHAR_SIZE(5,3,0), //"
0b11011000,
0b11011000,
0b11011000,

CHAR_SIZE(7,7,0), //#
0b01101100,
0b11111110,
0b01101100,
0b01101100,
0b01101100,
0b11111110,
0b01101100,

CHAR_SIZE(7,7,0), //%
0b01100010,
0b10100100,
0b11001000,
0b00010000,
0b00100110,
0b01001010,
0b10001100,

CHAR_SIZE(7,7,0), //&
0b01110000,
0b11011000,
0b11011000,
0b01110000,
0b11011010,
0b11001100,
0b01111110,

CHAR_SIZE(2,3,0), //'
0b11000000,
0b11000000,
0b11000000,

CHAR_SIZE(4,7,0), //(
0b00110000,
0b01100000,
0b11000000,
0b11000000,
0b11000000,
0b01100000,
0b00110000,

CHAR_SIZE(4,7,0), //)
0b11000000,
0b01100000,
0b00110000,
0b00110000,
0b00110000,
0b01100000,
0b11000000,

CHAR_SIZE(7,5,1), //*
0b01101100,
0b00111000,
0b11111110,
0b00111000,
0b01101100,

CHAR_SIZE(6,5,1), //+
0b00110000,
0b00110000,
0b11111100,
0b00110000,
0b00110000,

CHAR_SIZE(3,3,5), //,
0b01100000,
0b01100000,
0b11000000,

CHAR_SIZE(6,1,3), //-
0b11111100,

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

CHAR_SIZE(7,7,0), //0
0b00111000,
0b01001100,
0b11000110,
0b11000110,
0b11000110,
0b01100100,
0b00111000,

CHAR_SIZE(6,7,0), //1
0b00110000,
0b01110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b11111100,

CHAR_SIZE(7,7,0), //2
0b01111100,
0b11000110,
0b00001110,
0b00111100,
0b01111000,
0b11100000,
0b11111110,

CHAR_SIZE(7,7,0), //3
0b01111110,
0b00001100,
0b00011000,
0b00111100,
0b00000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //4
0b00011100,
0b00111100,
0b01101100,
0b11001100,
0b11111110,
0b00001100,
0b00001100,

CHAR_SIZE(7,7,0), //5
0b11111100,
0b11000000,
0b11111100,
0b00000110,
0b00000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //6
0b00111100,
0b01100000,
0b11000000,
0b11111100,
0b11000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //7
0b11111110,
0b11000110,
0b00001100,
0b00011000,
0b00110000,
0b00110000,
0b00110000,

CHAR_SIZE(7,7,0), //8
0b01111000,
0b11000100,
0b11100100,
0b01111000,
0b10011110,
0b10000110,
0b01111100,

CHAR_SIZE(7,7,0), //9
0b01111100,
0b11000110,
0b11000110,
0b01111110,
0b00000110,
0b00001100,
0b01111000,

CHAR_SIZE(2,5,1), //:
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,

CHAR_SIZE(3,6,1), //;
0b01100000,
0b01100000,
0b00000000,
0b01100000,
0b01100000,
0b11000000,

CHAR_SIZE(5,7,0), //<
0b00011000,
0b00110000,
0b01100000,
0b11000000,
0b01100000,
0b00110000,
0b00011000,

CHAR_SIZE(6,3,2), //=
0b11111100,
0b00000000,
0b11111100,

CHAR_SIZE(5,7,0), //>
0b11000000,
0b01100000,
0b00110000,
0b00011000,
0b00110000,
0b01100000,
0b11000000,

CHAR_SIZE(7,7,0), //?
0b01111100,
0b11111110,
0b11000110,
0b00001100,
0b00011000,
0b00000000,
0b00011000,

CHAR_SIZE(7,7,0), //@
0b01111100,
0b10000010,
0b10111010,
0b10101010,
0b10111110,
0b10000000,
0b01111100,

CHAR_SIZE(7,7,0), //A
0b00111000,
0b01101100,
0b11000110,
0b11000110,
0b11111110,
0b11000110,
0b11000110,

CHAR_SIZE(7,7,0), //B
0b11111100,
0b11000110,
0b11000110,
0b11111100,
0b11000110,
0b11000110,
0b11111100,

CHAR_SIZE(7,7,0), //C
0b00111100,
0b01100110,
0b11000000,
0b11000000,
0b11000000,
0b01100110,
0b00111100,

CHAR_SIZE(7,7,0), //D
0b11111000,
0b11001100,
0b11000110,
0b11000110,
0b11000110,
0b11001100,
0b11111000,

CHAR_SIZE(7,7,0), //E
0b11111110,
0b11000000,
0b11000000,
0b11111100,
0b11000000,
0b11000000,
0b11111110,

CHAR_SIZE(7,7,0), //F
0b11111110,
0b11000000,
0b11000000,
0b11111100,
0b11000000,
0b11000000,
0b11000000,

CHAR_SIZE(7,7,0), //G
0b00111110,
0b01100000,
0b11000000,
0b11001110,
0b11000110,
0b01100110,
0b00111110,

CHAR_SIZE(7,7,0), //H
0b11000110,
0b11000110,
0b11000110,
0b11111110,
0b11000110,
0b11000110,
0b11000110,

CHAR_SIZE(6,7,0), //I
0b11111100,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b11111100,

CHAR_SIZE(7,7,0), //J
0b00000110,
0b00000110,
0b00000110,
0b00000110,
0b00000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //K
0b11000110,
0b11001100,
0b11011000,
0b11110000,
0b11111000,
0b11011100,
0b11001110,

CHAR_SIZE(6,7,0), //L
0b11000000,
0b11000000,
0b11000000,
0b11000000,
0b11000000,
0b11000000,
0b11111100,

CHAR_SIZE(7,7,0), //M
0b11000110,
0b11101110,
0b11111110,
0b11111110,
0b11010110,
0b11000110,
0b11000110,

CHAR_SIZE(7,7,0), //N
0b11000110,
0b11100110,
0b11110110,
0b11111110,
0b11011110,
0b11001110,
0b11000110,

CHAR_SIZE(7,7,0), //O
0b01111100,
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //P
0b11111100,
0b11000110,
0b11000110,
0b11000110,
0b11111100,
0b11000000,
0b11000000,

CHAR_SIZE(7,7,0), //Q
0b01111100,
0b11000110,
0b11000110,
0b11000110,
0b11011110,
0b11001100,
0b01111010,

CHAR_SIZE(7,7,0), //R
0b11111100,
0b11000110,
0b11000110,
0b11001110,
0b11111000,
0b11011100,
0b11001110,

CHAR_SIZE(7,7,0), //S
0b01111000,
0b11001100,
0b11000000,
0b01111100,
0b00000110,
0b11000110,
0b01111100,

CHAR_SIZE(6,7,0), //T
0b11111100,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,

CHAR_SIZE(7,7,0), //U
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,7,0), //V
0b11000110,
0b11000110,
0b11000110,
0b11101110,
0b01111100,
0b00111000,
0b00010000,

CHAR_SIZE(7,7,0), //W
0b11000110,
0b11000110,
0b11010110,
0b11111110,
0b11111110,
0b11101110,
0b11000110,

CHAR_SIZE(7,7,0), //X
0b11000110,
0b11101110,
0b01111100,
0b00111000,
0b01111100,
0b11101110,
0b11000110,

CHAR_SIZE(6,7,0), //Y
0b11001100,
0b11001100,
0b11001100,
0b01111000,
0b00110000,
0b00110000,
0b00110000,

CHAR_SIZE(7,7,0), //Z
0b11111110,
0b00001110,
0b00011100,
0b00111000,
0b01110000,
0b11100000,
0b11111110,

CHAR_SIZE(4,7,0), //[
0b11110000,
0b11000000,
0b11000000,
0b11000000,
0b11000000,
0b11000000,
0b11110000,

CHAR_SIZE(4,7,0), //]
0b11110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b11110000,

CHAR_SIZE(6,1,7), //_
0b11111100,

CHAR_SIZE(7,5,2), //a
0b01111100,
0b00000110,
0b01111110,
0b11000110,
0b01111110,

CHAR_SIZE(7,7,0), //b
0b11000000,
0b11000000,
0b11111100,
0b11000110,
0b11000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,5,2), //c
0b01111110,
0b11000000,
0b11000000,
0b11000000,
0b01111110,

CHAR_SIZE(7,7,0), //d
0b00000110,
0b00000110,
0b01111110,
0b11000110,
0b11000110,
0b11000110,
0b01111110,

CHAR_SIZE(7,5,2), //e
0b01111100,
0b11000110,
0b11111110,
0b11000000,
0b01111100,

CHAR_SIZE(6,7,0), //f
0b00011100,
0b00110000,
0b11111100,
0b00110000,
0b00110000,
0b00110000,
0b00110000,

CHAR_SIZE(7,6,2), //g
0b01111110,
0b11000110,
0b11000110,
0b01111110,
0b00000110,
0b01111100,

CHAR_SIZE(7,7,0), //h
0b11000000,
0b11000000,
0b11111100,
0b11000110,
0b11000110,
0b11000110,
0b11000110,

CHAR_SIZE(6,7,0), //i
0b00110000,
0b00000000,
0b01110000,
0b00110000,
0b00110000,
0b00110000,
0b11111100,

CHAR_SIZE(5,8,0), //j
0b00011000,
0b00000000,
0b00111000,
0b00011000,
0b00011000,
0b00011000,
0b00011000,
0b11110000,

CHAR_SIZE(7,7,0), //k
0b11000000,
0b11000000,
0b11001110,
0b11111100,
0b11111000,
0b11011100,
0b11001110,

CHAR_SIZE(6,7,0), //l
0b01110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b00110000,
0b11111100,

CHAR_SIZE(7,5,2), //m
0b11111100,
0b10110110,
0b10110110,
0b10110110,
0b10110110,

CHAR_SIZE(7,5,2), //n
0b11111100,
0b11000110,
0b11000110,
0b11000110,
0b11000110,

CHAR_SIZE(7,5,2), //o
0b01111100,
0b11000110,
0b11000110,
0b11000110,
0b01111100,

CHAR_SIZE(7,6,2), //p
0b11111100,
0b11000110,
0b11000110,
0b11111100,
0b11000000,
0b11000000,

CHAR_SIZE(7,6,2), //q
0b01111110,
0b11000110,
0b11000110,
0b01111110,
0b00000110,
0b00000110,

CHAR_SIZE(6,5,2), //r
0b11011100,
0b11100000,
0b11000000,
0b11000000,
0b11000000,

CHAR_SIZE(7,5,2), //s
0b01111100,
0b11000000,
0b01111100,
0b00000110,
0b11111100,

CHAR_SIZE(6,7,0), //t
0b00110000,
0b00110000,
0b11111100,
0b00110000,
0b00110000,
0b00110000,
0b00110000,

CHAR_SIZE(7,5,2), //u
0b11000110,
0b11000110,
0b11000110,
0b11000110,
0b01111110,

CHAR_SIZE(6,5,2), //v
0b11001100,
0b11001100,
0b11001100,
0b01111000,
0b00110000,

CHAR_SIZE(7,5,2), //w
0b10110110,
0b10110110,
0b10110110,
0b10110110,
0b01111110,

CHAR_SIZE(7,5,2), //x
0b11000110,
0b11111110,
0b00111000,
0b11111110,
0b11000110,

CHAR_SIZE(7,6,2), //y
0b11000110,
0b11000110,
0b11000110,
0b01111110,
0b00000110,
0b01111100,

CHAR_SIZE(7,5,2), //z
0b11111110,
0b00011100,
0b00111000,
0b01110000,
0b11111110,

CHAR_SIZE(4,7,0), //{
0b00110000,
0b01100000,
0b01100000,
0b11000000,
0b01100000,
0b01100000,
0b00110000,

CHAR_SIZE(4,7,0), //}
0b11000000,
0b01100000,
0b01100000,
0b00110000,
0b01100000,
0b01100000,
0b11000000
};

PressStart2PFont8::PressStart2PFont8()
: Font(8, 1, &g_PressStart2PFont8_alphabeth[0], &g_PressStart2PFont8_font[0])
{
}

PressStart2PFont8::~PressStart2PFont8()
{
}
