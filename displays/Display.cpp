
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


Display::Display(int (*vtable)(void* display, VTABLE_FUNC vfunc, void* param), U16 width, U16 height, U8* framebuffer)
: m_vtable(vtable),
  m_width(width),
  m_height(height),
  m_framebuffer(framebuffer)
{
	ResetDirty();
}

void Display::GetDirty(U16& min_x_dirty, U16& min_y_dirty, U16& max_x_dirty, U16& max_y_dirty)
{
	min_x_dirty = m_min_x_dirty;
	min_y_dirty = m_min_y_dirty;
	max_x_dirty = m_max_x_dirty;
	max_y_dirty = m_max_y_dirty;
}

void Display::ResetDirty()
{
	m_min_x_dirty = GetWidth();
	m_min_y_dirty = GetHeight();
	m_max_x_dirty = 0;
	m_max_y_dirty = 0;
}

void Display::DirtyAll()
{
	m_min_x_dirty = 0;
	m_min_y_dirty = 0;
	m_max_x_dirty = GetWidth()-1;
	m_max_y_dirty = GetHeight()-1;
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

	U16 byte_x = (x>>3);
	U8 bit_x = x - (byte_x<<3);
	U16 byte_pos = (display_width>>3)*y + byte_x;
	switch(mode)
	{
		case OR:  framebuffer[byte_pos] |= 1<<bit_x; break;
		case AND: framebuffer[byte_pos] &= 1<<bit_x; break;
		case NOT: framebuffer[byte_pos] &= ~(1<<bit_x); break;
		case XOR: framebuffer[byte_pos] ^= 1<<bit_x; break;
		default: break;
	}
	
	if (x < static_cast<S16>(m_min_x_dirty)) m_min_x_dirty=x;
	if (y < static_cast<S16>(m_min_y_dirty)) m_min_y_dirty=y;
	if (x > static_cast<S16>(m_max_x_dirty)) m_max_x_dirty=x;
	if (y > static_cast<S16>(m_max_y_dirty)) m_max_y_dirty=y;
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
			DrawPixel(x, y+i, mode);
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
  U8 pos = 0;
	U8 ch_width = font.GetFontdataByte(ch_offset, pos++);
  U8 ch_height = font.GetFontdataByte(ch_offset, pos++);
  U8 ch_vertical_offset = (ch_height&0xF0)>>4;  
  ch_height = ch_height&0x0F;

	U8 row, col, bit, ch_data;
	for (row=0; row<ch_height; row++)
	{
		ch_data = font.GetFontdataByte(ch_offset, pos++);
		bit = 7;
		for (col=0; col<ch_width; col++)
		{
			if (ch_data&(1<<bit))
			{
				DrawPixel(x+col, y+ch_vertical_offset+row, mode);
			}
			
			if (bit==0)
			{
				if ((col+1)<ch_width) //If we are at the end of a byte, and have more columns, read next byte
				{
					bit = 7;
					ch_data = font.GetFontdataByte(ch_offset, pos++);
				}
			}
			else
			{
				bit--;
			}
		}
	}

	return ch_width + font.GetMargin();
}

U16 Display::DrawText(S16 x, S16 y, U8 PROGMEM_PTR_T str_p, DrawMode mode, const Font& font) //returns width of text
{
	U16 text_width = 0;

	U16 display_width = GetWidth();
	U16 display_height = GetHeight();
	if ((y+font.GetFontHeight())>=0 && y<static_cast<S16>(display_height))
	{
		U8 ch;
		while ((ch=PROGMEM_READ_BYTE((U8 PROGMEM_PTR_T)(str_p++))) && (x+text_width)<display_width)
		{
			text_width += DrawChar(x+text_width, y, ch, mode, font);
		}
	}
	
	return text_width;
}

U16 Display::DrawNumber(S16 x, S16 y, S16 n, DrawMode mode, const Font& font) //returns width of number (as text)
{
	U16 text_width = 0;

	U16 display_width = GetWidth();
	U16 display_height = GetHeight();
	U16 exp = 10000;
	bool printing = false;
	if ((y+font.GetFontHeight())>=0 && y<static_cast<S16>(display_height))
	{
		if (0 > n)
		{
			text_width += DrawChar(x, y, '-', mode, font);
			n = -n;
		}

		U8 ch;
		while (0<exp && (x+text_width)<display_width)
		{
			ch = n/exp;
			n -= ch*exp;
			ch += '0';
			exp /= 10;

			if (printing || '0'!=ch || 0==exp)
			{
				text_width += DrawChar(x+text_width, y, ch, mode, font);
				printing = true;
			}
		}
	}
	
	return text_width;
}
