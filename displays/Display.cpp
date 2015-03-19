
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


Display::Display()
{
}

Display::~Display()
{
}

void Display::DrawPixel(sint16 x, sint16 y, DrawMode mode)
{
	uint16 display_width = GetWidth();
	if (x<0 || x>=static_cast<sint16>(display_width))
		return;

	uint16 display_height = GetHeight();
	if (y<0 || y>=static_cast<sint16>(display_height))
		return;

	uint8* framebuffer = GetFramebuffer();

	uint16 byte_x = (x/8);
	uint8 bit_x = x - (byte_x*8);
	uint16 byte_pos = (display_width/8)*y + byte_x;
	switch(mode)
	{
		case OR:  framebuffer[byte_pos] |= 1<<bit_x; break;
		case AND: framebuffer[byte_pos] &= 1<<bit_x; break;
		case NOT: framebuffer[byte_pos] &= ~(1<<bit_x); break;
		case XOR: framebuffer[byte_pos] ^= 1<<bit_x; break;
		default: break;
	}
}

void Display::DrawLine(sint16 x, sint16 y, uint16 delta_x, uint16 delta_y, DrawMode mode)
{
	double delta;
	uint16 i;
	if (delta_x > delta_y)
	{
		delta = static_cast<double>(delta_y)/static_cast<double>(delta_x);
		for (i=0; i<delta_x; i++)
		{
			DrawPixel(x+i, y + i*delta, mode);
		}
	}
	else
	{
		delta = static_cast<double>(delta_x)/static_cast<double>(delta_y);
		for (i=0; i<delta_y; i++)
		{
			DrawPixel(x + i*delta, y+i, mode);
		}
	}
}

void Display::DrawRect(sint16 x, sint16 y, uint16 width, uint16 height, DrawMode mode)
{
	if (width<=2 || height<=2)
	{
		DrawFilledRect(x, y, width, height, mode);
	}
	else
	{
		uint16 i;
		for (i=0; i<width; i++)
		{
			DrawPixel(x+i, y, mode);
			DrawPixel(x+i, y+height-1, mode);
		}
		for (i=1; i<height-1; i++)
		{
			DrawPixel(x, y+1, mode);
			DrawPixel(x+width-1, y+i, mode);
		}
	}
}

void Display::DrawFilledRect(sint16 x, sint16 y, uint16 width, uint16 height, DrawMode mode)
{
	uint16 i, j;
	for (i=0; i<width; i++)
	{
		for (j=0; j<height; j++)
		{
			DrawPixel(x+i, y+j, mode);
		}
	}
}

uint16 Display::DrawChar(sint16 x, sint16 y, uint8 ch, DrawMode mode, const Font& font) //returns width of character, including margin
{
	const uint8* ch_data = font.GetFontdata(ch);
	const uint8 ch_width = *ch_data;

	int row, col, bit;
	for (row=0; row<font.GetHeight(); row++)
	{
		ch_data++;
		bit = 7;
		for (col=0; col<ch_width; col++)
		{
			if (*ch_data&1<<bit)
			{
				DrawPixel(x+col, y+row, mode);
			}
			
			if (bit==0)
			{
				bit = 7;
				ch_data++;
			}
			else
			{
				bit--;
			}
		}
	}

	return ch_width + font.GetMargin();
}

uint16 Display::DrawText(sint16 x, sint16 y, uint8* str, DrawMode mode, const Font& font) //returns width of text
{
	uint16 text_width = 0;

	uint16 display_width = GetWidth();
	uint16 display_height = GetHeight();
	if ((y+font.GetHeight())>=0 && y<static_cast<sint16>(display_height))
	{
		uint8 ch;
		while ((ch=*str++) && (x+text_width)<display_width)
		{
			text_width += DrawChar(x+text_width, y, ch, mode, font);
		}
	}
	
	return text_width;
}
