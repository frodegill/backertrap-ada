#ifndef _TIMER_MANAGER_H_
#define _TIMER_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#define MICROSECOND_OFFSET (1000L)
#define MILLISECOND_OFFSET (1000L*1000L)
#define SECOND_OFFSET      (1000L*1000L*1000L)


class TimerManager
{
public:
	enum TimerId
	{
		BACKLIGHT_TIMEOUT
	};

	enum Unit
	{
		SECOND,
		MILLISECOND,
		MICROSECOND,
		NANOSECOND
	};

private:
	struct TimedEvent
	{
		TimerId m_id;
		U64     m_time;
	};
	
public:
	TimerManager();
	~TimerManager();

  bool Init();

public:
	void SetTimeout(TimerId id, U32 delay, Unit unit);
	void ResetTimeout(TimerId id, U32 delay, Unit unit);
	void ClearTimeout(TimerId id);

private:
	U64  Now() const;
	bool InsertEvent(U8 index, const TimedEvent& event);
	bool RemoveEvent(U8 index);

private:
	TimedEvent m_timed_events[MAX_TIMED_EVENTS_STACK_SIZE];
	U8         m_timed_events_list_length;
};

#endif // _TIMER_MANAGER_H_
