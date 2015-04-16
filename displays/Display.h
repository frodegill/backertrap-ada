#ifndef _DISPLAY_H_
#define _DISPLAY_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"
#include "../fonts/font.h"


class Display
{
public:
	enum VTABLE_FUNC
	{
		SetBrightnessFunc,
		SetBacklightStatusFunc,
		SetSleepFunc,
		ClearFramebufferFunc,
		SwapBuffersFunc
	};

	enum BacklightStatus
	{
		ON,
		OFF
	};
	
	enum DrawMode
	{
		OR,
		AND,
		NOT,
		XOR
	};
	
public:
	Display(int (*vtable)(void* display, VTABLE_FUNC vfunc, void* param), U16 width, U16 height, U8* framebuffer);

public:
	U16 GetWidth() const {return m_width;}
	U16 GetHeight() const {return m_height;}
	U8* GetFramebuffer() const {return m_framebuffer;}
	void GetDirty(U16& min_x_dirty, U16& min_y_dirty, U16& max_x_dirty, U16& max_y_dirty);
	void ResetDirty();
	void DirtyAll();

public: //Atmel - Why no virtual!?!
	void SetBrightness(double brightness) {m_vtable(this, SetBrightnessFunc, &brightness);}
	void SetBacklightStatus(BacklightStatus status) {m_vtable(this, SetBacklightStatusFunc, &status);}
	void SetSleep(bool sleep) {m_vtable(this, SetSleepFunc, &sleep);}
	
	void ClearFramebuffer()  {m_vtable(this, ClearFramebufferFunc, NULL);}
	void SwapBuffers() {m_vtable(this, SwapBuffersFunc, NULL);}

public:
	void DrawPixel(S16 x, S16 y, DrawMode mode);
	void DrawLine(S16 x, S16 y, U16 delta_x, U16 delta_y, DrawMode mode);
	void DrawRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode);
	void DrawFilledRect(S16 x, S16 y, U16 width, U16 height, DrawMode mode);
	U16 DrawChar(S16 x, S16 y, U8 ch, DrawMode mode, const Font& font); //returns width of character, including margin
	U16 DrawText(S16 x, S16 y, U8 PROGMEM_PTR_T str_p, DrawMode mode, const Font& font); //returns width of text

private:
	int (* m_vtable)(void* display, VTABLE_FUNC vfunc, void* param);
	U16 m_width;
	U16 m_height;
	U8* m_framebuffer;
	U16 m_min_x_dirty;
	U16 m_min_y_dirty;
	U16 m_max_x_dirty;
	U16 m_max_y_dirty;
	
};

#endif // _DISPLAY_H_
