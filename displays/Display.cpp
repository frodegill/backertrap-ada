
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


Display::Display()
{
}

Display::~Display()
{
}

void Display::DrawPixel(uint16 x, uint16 y, DrawMode mode)
{
	uint16 display_width = GetWidth();
	if (x >= display_width)
		return;

	uint16 display_height = GetHeight();
	if (y >= display_height)
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

void Display::DrawLine(uint16 x, uint16 y, uint16 delta_x, uint16 delta_y, DrawMode mode)
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

void Display::DrawRect(uint16 x, uint16 y, uint16 width, uint16 height, DrawMode mode)
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

void Display::DrawFilledRect(uint16 x, uint16 y, uint16 width, uint16 height, DrawMode mode)
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

uint16 Display::DrawChar(uint16 UNUSED(x), uint16 UNUSED(y), uint8 UNUSED(ch), DrawMode UNUSED(mode)) //returns width of character
{
	return 0;
}

uint16 Display::DrawText(uint16 UNUSED(x), uint16 UNUSED(y), uint8* UNUSED(str), DrawMode UNUSED(mode)) //returns width of text
{
	return 0;
}
