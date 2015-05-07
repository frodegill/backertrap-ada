#ifndef _BUTTON_MANAGER_H_
#define _BUTTON_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"


class ButtonManager
{
public:
	enum Buttons
	{
		BUTTON_UPPER_LEFT,
		BUTTON_UPPER_RIGHT,
		BUTTON_LOWER_LEFT,
		BUTTON_LOWER_RIGHT,
		BUTTON_COUNT
	};
	
public:
	ButtonManager();
	~ButtonManager();

  bool Init();

	void PollKeyStates(); //ToDo: This is a polling function. Try to use interrupts instead

private:
	void OnButtonDown(U8 button);
	void OnButtonUp(U8 button);

private:
	U8 m_buttons_down_mask;
	U8 m_button_port[BUTTON_COUNT];
};

#endif // _BUTTON_MANAGER_H_
