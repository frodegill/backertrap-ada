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
        UP = 1,
        DOWN,
        BACK,
        OK
    };

public:
  SymbolsFont();
  ~SymbolsFont();
};

#endif //_SYMBOLS_FONT_H_
