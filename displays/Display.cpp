
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


Display::Display()
{
}

Display::~Display()
{
}

void Display::DrawPixel(S16 x, S16 y, DrawMode mode)
{
	U16 display_width = GetWidth();
	if (x<0 || x>=static_cast<S16>(display_width))
		return;

	U16 display_height = GetHeight();
	if (y<0 || y>=static_cast<S16>(display_height))
		return;

	U8* framebuffer = GetFramebuffer();

	U16 byte_x = (x/8);
	U8 bit_x = x - (byte_x*8);
	U16 byte_pos = (display_width/8)*y + byte_x;
	switch(mode)
	{
		case OR:  framebuffer[byte_pos] |= 1<<bit_x; break;
		case AND: framebuffer[byte_pos] &= 1<<bit_x; break;
		case NOT: framebuffer[byte_pos] &= ~(1<<bit_x); break;
		case XOR: framebuffer[byte_pos] ^= 1<<bit_x; break;
		default: break;
	}
}

void Display::DrawLine(S16 x, S16 y, U16 delta_x, U16 delta_y, DrawMode mode)
{
	double delta;
	U16 i;
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

void Display::DrawRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode)
{
	if (width<=2 || height<=2)
	{
		DrawFilledRect(x, y, width, height, mode);
	}
	else
	{
		U16 i;
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

void Display::DrawFilledRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode)
{
	U16 i, j;
	for (i=0; i<width; i++)
	{
		for (j=0; j<height; j++)
		{
			DrawPixel(x+i, y+j, mode);
		}
	}
}

U16 Display::DrawChar(S16 x, S16 y, U8 ch, DrawMode mode, const Font& font) //returns width of character, including margin
{
	U16 ch_offset = font.GetFontdataChOffset(ch);
	U8 ch_width = font.GetFontdataByte(ch_offset, 0);

	U8 row, col, bit, ch_data, pos=0;
	for (row=0; row<font.GetHeight(); row++)
	{
		ch_data = font.GetFontdataByte(ch_offset, ++pos);
		bit = 7;
		for (col=0; col<ch_width; col++)
		{
			if (ch_data&(1<<bit))
			{
				DrawPixel(x+col, y+row, mode);
			}
			
			if (bit==0)
			{
				bit = 7;
				ch_data = font.GetFontdataByte(ch_offset, ++pos);
			}
			else
			{
				bit--;
			}
		}
	}

	return ch_width + font.GetMargin();
}

U16 Display::DrawText(S16 x, S16 y, U8* str, DrawMode mode, const Font& font) //returns width of text
{
	U16 text_width = 0;

	U16 display_width = GetWidth();
	U16 display_height = GetHeight();
	if ((y+font.GetHeight())>=0 && y<static_cast<S16>(display_height))
	{
		U8 ch;
		while ((ch=*str++) && (x+text_width)<display_width)
		{
			text_width += DrawChar(x+text_width, y, ch, mode, font);
		}
	}
	
	return text_width;
}
