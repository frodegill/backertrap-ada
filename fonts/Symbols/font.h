#ifndef _SYMBOLS_FONT_H_
#define _SYMBOLS_FONT_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for license

#include "../../defines.h"
#include "../font.h"


class SymbolsFont : public Font
{
public:
    enum Symbol {
        UP,
        DOWN,
        BACK,
        OK
    };

public:
  SymbolsFont();
  ~SymbolsFont();

public:
	U8 GetFontHeight() const {return 4;} //Update if you create a taller symbol

	U8 GetAlphabetByte(U8 pos) const;
	U8 GetFontdataByte(U16 ch_offset, U8 pos) const;

};

#endif //_SYMBOLS_FONT_H_
