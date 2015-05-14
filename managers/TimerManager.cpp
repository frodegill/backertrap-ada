
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"

#include "../3rd-party/Atmel/common/services/clock/sysclk.h"
#include "../3rd-party/Atmel/xmega/drivers/rtc32/rtc32.h"


TimerManager::Compare TimerManager::Time::Compare(const Time& other_time)
{
	if (m_seconds < other_time.m_seconds)
	{
		return BEFORE;
	}
	else if (m_seconds > other_time.m_seconds)
	{
		return AFTER;
	}
	else if (m_nanoseconds < other_time.m_nanoseconds)
	{
		return BEFORE;
	}
	else if (m_nanoseconds > other_time.m_nanoseconds)
	{
		return AFTER;
	}
	return EQUAL;
}


TimerManager::TimerManager()
: m_timed_events_list_length(0)
{
}

TimerManager::~TimerManager()
{
}

bool TimerManager::Init()
{
  sysclk_init();

	//From ASF:
	// Workaround for known issue: Enable RTC32 sysclk
	sysclk_enable_module(SYSCLK_PORT_GEN, SYSCLK_RTC);
	while (RTC32.SYNCCTRL & RTC32_SYNCBUSY_bm) {
		// Wait for RTC32 sysclk to become stable
	}
	// If we have battery power and RTC is running, don't initialize RTC32
	if (rtc_vbat_system_check(false) != VBAT_STATUS_OK) {
		rtc_init();
	}

  return true;
}

void TimerManager::SetTimeout(TimerId UNUSED_PARAM(id), const Time& UNUSED_PARAM(delay))
{
	//TODO
}

void TimerManager::SetTimeout(TimerId id, U32 delay, Unit unit)
{
	TimedEvent event;
	event.m_id = id;
	Now(event.m_time);
	IncrementTime(event.m_time, delay, unit);

	U8 index = 0;
	while (index<m_timed_events_list_length && BEFORE == m_timed_events[index].m_time.Compare(event.m_time))
		index++;

	InsertEvent(index, event);
}

void TimerManager::ResetTimeout(TimerId UNUSED_PARAM(id), const Time& UNUSED_PARAM(delay))
{
	//TODO
}

void TimerManager::ResetTimeout(TimerId id, U32 delay, Unit unit)
{
	ClearTimeout(id);
	SetTimeout(id, delay, unit);
}

void TimerManager::ClearTimeout(TimerId id)
{
	U8 i;
	for (i=0; i<m_timed_events_list_length; i++)
	{
		while(i<m_timed_events_list_length && //m_timed_events_list_length will be changed in RemoveEvent
		      m_timed_events[i].m_id==id)
		{
			RemoveEvent(i);
		}
	}
}

void TimerManager::Now(Time& time) const
{
	time.m_seconds = rtc_get_time();
	time.m_nanoseconds = 0; //ToDo
}

void TimerManager::IncrementTime(Time& time, U32 offset, Unit unit) const
{
	U32 units_per_second;
	U32 nanoseconds_per_unit;
	switch(unit)
	{
		case NANOSECOND:  units_per_second=NANOSECONDS_PER_SECOND; nanoseconds_per_unit=1; break;
		case MICROSECOND: units_per_second=MICROSECONDS_PER_SECOND; nanoseconds_per_unit=NANOSECONDS_PER_MICROSECOND; break;
		case MILLISECOND: units_per_second=MILLISECONDS_PER_SECOND; nanoseconds_per_unit=NANOSECONDS_PER_MILLISECOND; break;
		default: units_per_second=nanoseconds_per_unit=0; break;
	}
	
	switch(unit)
	{
		case NANOSECOND:
		case MICROSECOND:
		case MILLISECOND:
		{
			U32 offset_seconds;
			if (offset >= units_per_second)
			{
				offset_seconds = offset/units_per_second;
				offset -= offset_seconds*units_per_second;
				time.m_seconds += offset_seconds;
			}
			time.m_nanoseconds += offset*nanoseconds_per_unit;
			while (time.m_nanoseconds >= NANOSECONDS_PER_SECOND)
			{
				time.m_seconds += 1;
				time.m_nanoseconds -= NANOSECONDS_PER_SECOND;
			}
			break;
		}

		case SECOND:
		{
			time.m_seconds += offset;
			break;
		}

		case MINUTE:
		{
			time.m_seconds += offset*SECONDS_PER_MINUTE;
			break;
		}

		case HOUR:
		{
			time.m_seconds += offset*SECONDS_PER_HOUR;
			break;
		}

		default: break;
	}
}

bool TimerManager::InsertEvent(U8 index, const TimedEvent& event)
{
	if (MAX_TIMED_EVENTS_STACK_SIZE == m_timed_events_list_length ||
	    index > m_timed_events_list_length)
	{
		return false;
	}

	U8 i;
	for (i=m_timed_events_list_length; i>index; i--)
	{
		m_timed_events[i] = m_timed_events[i-1];
	}

	m_timed_events[index] = event;
	m_timed_events_list_length++;
	return true;
}

bool TimerManager::RemoveEvent(U8 index)
{
	if (index >= m_timed_events_list_length)
	{
		return false;
	}
	
	U8 i;
	for (i=index; i<(m_timed_events_list_length-1); i++)
	{
		m_timed_events[i] = m_timed_events[i+1];
	}
	
	m_timed_events_list_length--;
	return true;
}
