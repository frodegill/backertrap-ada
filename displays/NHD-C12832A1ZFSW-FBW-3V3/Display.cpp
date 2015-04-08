
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Display.h"


U8 g_DisplayNHDC12832A1ZFSWFBW3V3_framebuffer_p[NHDC12832A1ZFSWFBW3V3_WIDTH*NHDC12832A1ZFSWFBW3V3_HEIGHT/8];


int DisplayNHDC12832A1ZFSWFBW3V3VTable(void* display, Display::VTABLE_FUNC vfunc, void* param)
{
	DisplayNHDC12832A1ZFSWFBW3V3* native_display = static_cast<DisplayNHDC12832A1ZFSWFBW3V3*>(display);
	switch(vfunc)
	{
		case Display::SetBrightnessFunc:
			native_display->SetBrightness(*reinterpret_cast<double*>(param));
			break;

		case Display::SetBacklightStatusFunc:
			native_display->SetBacklightStatus(*reinterpret_cast<Display::BacklightStatus*>(param));
			break;

		case Display::ClearFramebufferFunc:
			native_display->ClearFramebuffer();
			break;

		case Display::SwapBuffersFunc:
			native_display->SwapBuffers();
			break;
	}
	return 0;
}


DisplayNHDC12832A1ZFSWFBW3V3::DisplayNHDC12832A1ZFSWFBW3V3()
: Display(::DisplayNHDC12832A1ZFSWFBW3V3VTable, 128, 32, NULL)
{
}

DisplayNHDC12832A1ZFSWFBW3V3::~DisplayNHDC12832A1ZFSWFBW3V3()
{
}

bool DisplayNHDC12832A1ZFSWFBW3V3::Init()
{
	/* Initialize the low-level display controller. */
	st7565r_init();

	/* Set display to output data from line 0 */
	st7565r_set_display_start_line_address(0);

	ClearFramebuffer();
	SwapBuffers();

	return true;
}

void DisplayNHDC12832A1ZFSWFBW3V3::SetBacklightStatus(Display::BacklightStatus status)
{
	ioport_set_pin_level(NHD_C12832A1Z_BACKLIGHT, Display::OFF != status);
}

void DisplayNHDC12832A1ZFSWFBW3V3::ClearFramebuffer()
{
	U16 i;
	for (i=0; i<(NHDC12832A1ZFSWFBW3V3_WIDTH*NHDC12832A1ZFSWFBW3V3_HEIGHT/8); i++)
	{
		g_DisplayNHDC12832A1ZFSWFBW3V3_framebuffer_p[i] = 0;
	}
}

void DisplayNHDC12832A1ZFSWFBW3V3::SwapBuffers()
{
	U16 min_x_dirty, min_y_dirty,max_x_dirty,max_y_dirty;
	GetDirty(min_x_dirty, min_y_dirty, max_x_dirty, max_y_dirty);
	if (min_x_dirty>max_x_dirty || min_y_dirty>max_y_dirty)
		return;

	U8 min_y_page = min_y_dirty>>3;
	U8 max_y_page = max_y_dirty>>3;
	U8 min_x_byte = min_x_dirty>>3;
	U8 max_x_byte = max_x_dirty>>3;
	U8 page, x_byte;
	U8 data[8];
	U8 i;
	U8 x, y, fb_data;
	for (page=min_y_page; page<=max_y_page; page++)
	{
		st7565r_set_page_address(page);
		st7565r_set_column_address(min_x_byte<<3);

		for (x_byte=min_x_byte; x_byte<=max_x_byte; x_byte++)
		{
			for (i=0; i<8; i++)
			{
				data[i] = 0;
			}

			for (y=0; y<8; y++)
			{
				fb_data = g_DisplayNHDC12832A1ZFSWFBW3V3_framebuffer_p[(page*8 + y)*NHDC12832A1ZFSWFBW3V3_BYTES_PER_ROW + x_byte];
				for (x=0; x<8; x++)
				{
					if (fb_data & (1<<(7-x)))
					{
						data[x] |= 1<<(7-y);
					}
				}
			}

			for (i=0; i<8; i++)
			{
				st7565r_write_data(data[i]);
			}
		}
	}

	ResetDirty();
}
