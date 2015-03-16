
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#ifdef PRECOMP
# include "../../pch.h"
#else
#endif

#include "font.h"

const byte g_BMRizerFont6_alphabeth[] = "!\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz";

byte g_BMRizerFont6_font[] = {
4, //[SPACE]
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,

3, //!
0b11100000,
0b11100000,
0b11100000,
0b00000000,
0b11100000,
0b00000000,

5, //"
0b11011000,
0b11011000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,

7, //#
0b01101100,
0b11111110,
0b01101100,
0b11111110,
0b01101100,
0b00000000,

9, //%
0b11101100, 0b00000000,
0b10101000, 0b00000000,
0b11101011, 0b10000000,
0b00001010, 0b10000000,
0b00011011, 0b10000000,
0b00000000, 0b00000000,

8, //&
0b11111110,
0b11101110,
0b01111100,
0b11101111,
0b11111110,

2, //'
0b11000000,
0b11000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,

4, //(
0b01110000,
0b11100000,
0b11100000,
0b11100000,
0b01110000,
0b00000000,

4, //)
0b11100000,
0b01110000,
0b01110000,
0b01110000,
0b01110000,
0b11100000,
0b00000000,

4, //*
0b01100000,
0b11110000,
0b01100000,
0b00000000,
0b00000000,
0b00000000,

7, //+
0b00111000,
0b00111000,
0b11111110,
0b00111000,
0b00111000,
0b00000000,

2, //,
0b00000000,
0b00000000,
0b00000000,
0b11000000,
0b11000000,
0b01000000,

7, //-
0b00000000,
0b00000000,
0b11111110,
0b00000000,
0b00000000,
0b00000000,

2, //.
0b00000000,
0b00000000,
0b00000000,
0b11000000,
0b11000000,
0b00000000,

7, // /
0b00001110,
0b00011100,
0b00111000,
0b01110000,
0b11100000,
0b00000000,

7, //0
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

4, //1
0b11110000,
0b01110000,
0b01110000,
0b01110000,
0b01110000,
0b00000000,

7, //2
0b11111110,
0b00001110,
0b11111110,
0b11100000,
0b11111110,
0b00000000,

7, //3
0b11111110,
0b00001110,
0b11111110,
0b00001110,
0b11111110,
0b00000000,

7, //4
0b11101110,
0b11101110,
0b11111110,
0b00001110,
0b00001110,
0b00000000,

7, //5
0b11111110,
0b11100000,
0b11111110,
0b00001110,
0b11111110,
0b00000000,

7, //6
0b11111110,
0b11100000,
0b11111110,
0b11101110,
0b11111110,
0b00000000,

7, //7
0b11111110,
0b00001110,
0b00001110,
0b00001110,
0b00001110,
0b00000000,

7, //8
0b11111110,
0b11101110,
0b11111110,
0b11101110,
0b11111110,
0b00000000,

7, //9
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,
0b00000000,

2, //:
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,
0b00000000,

2, //;
0b11000000,
0b11000000,
0b00000000,
0b11000000,
0b11000000,
0b01000000,

3, //<
0b00100000,
0b01100000,
0b11100000,
0b01100000,
0b00100000,
0b00000000,

7, //=
0b00000000,
0b11111110,
0b00000000,
0b11111110,
0b00000000,
0b00000000,

3, //>
0b10000000,
0b11000000,
0b11100000,
0b11000000,
0b10000000,
0b00000000,

7, //?
0b11111110,
0b00001110,
0b00111110,
0b00000000,
0b00111000,
0b00000000,

8, //@
0b11111111,
0b11000011,
0b11011111,
0b11011011,
0b11011111,
0b00000000,

7, //A
0b11111110,
0b11101110,
0b11101110,
0b11111110,
0b11101110,
0b00000000,

7, //B
0b11111110,
0b11101110,
0b11111100,
0b11101110,
0b11111110,
0b00000000,

7, //C
0b11111110,
0b11100000,
0b11100000,
0b11100000,
0b11111110,
0b00000000,

7, //D
0b11111100,
0b11101110,
0b11101110,
0b11101110,
0b11111100,
0b00000000,

7, //E
0b11111110,
0b11100000,
0b11111110,
0b11100000,
0b11111110,
0b00000000,

7, //F
0b11111110,
0b11100000,
0b11111110,
0b11100000,
0b11100000,
0b00000000,

7, //G
0b11111110,
0b11100000,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //H
0b11101110,
0b11101110,
0b11111110,
0b11101110,
0b11101110,
0b00000000,

3, //I
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b00000000,

7, //J
0b00001110,
0b00001110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //K
0b11101110,
0b11101110,
0b11111100,
0b11101110,
0b11101110,
0b00000000,

7, //L
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11111110,
0b00000000,

11, //M
0b11111111, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b00000000, 0b00000000,

7, //N
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11101110,
0b00000000,

7, //O
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //P
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11100000,
0b00000000,

7, //Q
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00111000,

7, //R
0b11111110,
0b11101110,
0b11111100,
0b11101110,
0b11101110,
0b00000000,

7, //S
0b11111110,
0b01110000,
0b00111000,
0b00011100,
0b11111110,
0b00000000,

7, //T
0b11111110,
0b00111000,
0b00111000,
0b00111000,
0b00111000,
0b00000000,

7, //U
0b11101110,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //V
0b11101110,
0b11101110,
0b11101110,
0b01111100,
0b00111000,
0b00000000,

11, //W
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11111111, 0b11100000,
0b00000000, 0b00000000,

7, //X
0b11101110,
0b11101110,
0b01111100,
0b11101110,
0b11101110,
0b00000000,

7, //Y
0b11101110,
0b11101110,
0b01111100,
0b00111000,
0b00111000,
0b00000000,

7, //Z
0b11111110,
0b00011100,
0b00111000,
0b01110000,
0b11111110,
0b00000000,

4, //[
0b11110000,
0b11100000,
0b11100000,
0b11100000,
0b11110000,
0b00000000,

4, //]
0b11110000,
0b01110000,
0b01110000,
0b01110000,
0b11110000,

7, //_
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b11111110,
0b00000000,

7, //a
0b11111110,
0b00001110,
0b11111110,
0b11101110,
0b11111110,
0b00000000,

7, //b
0b11100000,
0b11111110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //c
0b00000000,
0b11111110,
0b11100000,
0b11100000,
0b11111110,
0b00000000,

7, //d
0b00001110,
0b11111110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //e
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11111110,
0b00000000,

7, //f
0b01111110,
0b01110000,
0b11111110,
0b01110000,
0b01110000,
0b00000000,

7, //g
0b00000000,
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,

7, //h
0b11100000,
0b11100000,
0b11111110,
0b11101110,
0b11101110,
0b00000000,

3, //i
0b11100000,
0b00000000,
0b11100000,
0b11100000,
0b11100000,
0b00000000,

7, //j
0b00001110,
0b00000000,
0b00001110,
0b00001110,
0b11111110,
0b00000000,

7, //k
0b11100000,
0b11101110,
0b11101000,
0b11111110,
0b11101110,
0b00000000,

4, //l
0b11100000,
0b11100000,
0b11100000,
0b11100000,
0b11110000,
0b00000000,

11, //m
0b00000000, 0b00000000,
0b11111111, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b00000000, 0b00000000,

7, //n
0b00000000,
0b11111110,
0b11101110,
0b11101110,
0b11101110,
0b00000000,

7, //o
0b00000000,
0b11111110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //p
0b00000000,
0b11111110,
0b11101110,
0b11111110,
0b11100000,
0b11100000,

7, //q
0b00000000,
0b11111110,
0b11101110,
0b11111110,
0b00001110,
0b00001110,

6, //r
0b00000000,
0b11111100,
0b11100000,
0b11100000,
0b11100000,
0b00000000,

6, //s
0b00000000,
0b11111100,
0b01110000,
0b00111000,
0b11111100,
0b00000000,

6, //t
0b11100000,
0b11111100,
0b11100000,
0b11100000,
0b11111100,
0b00000000,

7, //u
0b00000000,
0b11101110,
0b11101110,
0b11101110,
0b11111110,
0b00000000,

7, //v
0b00000000,
0b11101110,
0b11101110,
0b01101100,
0b00111000,
0b00000000,

11, //w
0b00000000, 0b00000000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11101110, 0b11100000,
0b11111111, 0b11100000,
0b00000000, 0b00000000,

7, //x
0b00000000,
0b11101110,
0b01111100,
0b01111100,
0b11101110,
0b00000000,

7, //y
0b00000000,
0b11101110,
0b11101110,
0b11111110,
0b00001110,
0b11111110,
0b00000000,

6, //z
0b00000000,
0b11111100,
0b00111000,
0b01110000,
0b11111100,
0b00000000,




};

BMRizerFont6::BMRizerFont6()
: Font(&g_BMRizerFont6_alphabeth[0], 6, 1, &g_BMRizerFont6_font[0])
{
}

BMRizerFont6::~BMRizerFont6()
{
}
