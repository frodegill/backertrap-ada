#ifndef _TIMER_MANAGER_H_
#define _TIMER_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#define NANOSECONDS_PER_MICROSECOND  (1000L)
#define MICROSECONDS_PER_MILLISECOND (1000L)
#define MILLISECONDS_PER_SECOND      (1000L)
#define NANOSECONDS_PER_MILLISECOND  (NANOSECONDS_PER_MICROSECOND*MICROSECONDS_PER_MILLISECOND)
#define NANOSECONDS_PER_SECOND       (NANOSECONDS_PER_MILLISECOND*MILLISECONDS_PER_SECOND)
#define MICROSECONDS_PER_SECOND      (MICROSECONDS_PER_MILLISECOND*MILLISECONDS_PER_SECOND)
#define SECONDS_PER_MINUTE (60)
#define MINUTES_PER_HOUR   (60)
#define SECONDS_PER_HOUR   (SECONDS_PER_MINUTE*MINUTES_PER_HOUR)

class TimerManager
{
public:
	enum TimerId
	{
		BACKLIGHT_TIMEOUT,
		CAMERA_TRIGGERED_TIMEOUT,
		FLASH_TRIGGERED_TIMEOUT,
		PROGRAM_WAIT_TIMEOUT
	};

	enum Compare
	{
		BEFORE,
		EQUAL,
		AFTER
	};

	enum Unit
	{
		HOUR,
		MINUTE,
		SECOND,
		MILLISECOND,
		MICROSECOND,
		NANOSECOND
	};

	struct Time
	{
		U32 m_seconds;
		U32 m_nanoseconds;
		
public:
		void Now();
		void IncrementTime(const Time& offset);
		void IncrementTime(U32 offset, Unit unit);
		void Reset() {m_seconds = m_nanoseconds = 0;}
		bool IsValid() const {return m_seconds!=0 || m_nanoseconds!=0;}
		TimerManager::Compare Compare(const Time& other_time);
	};

private:
	struct TimedEvent
	{
		TimerId m_id;
		Time    m_time;
		void (* m_callback)(TimerId id, void* calling_object, U8 param);
		void*   m_calling_object;
		U8      m_param;
	};
	
public:
	TimerManager();
	~TimerManager();

  bool Init();

public:
	void OnTimerEvent(TimerId id, U8 param);

public:
	void SetTimeout(TimerId id, const Time& delay);
	void SetTimeout(TimerId id, U32 delay, Unit unit, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param);
	void ResetTimeout(TimerId id, const Time& delay);
	void ResetTimeout(TimerId id, U32 delay, Unit unit, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param);
	void ClearTimeout(TimerId id);

private:
	bool InsertEvent(U8 index, const TimedEvent& event);
	bool RemoveEvent(U8 index);

private:
	TimedEvent m_timed_events[MAX_TIMED_EVENTS_STACK_SIZE];
	U8         m_timed_events_list_length;
};

#endif // _TIMER_MANAGER_H_
