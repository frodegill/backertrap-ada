
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"

#include "../3rd-party/Atmel/common/services/clock/sysclk.h"
#include "../3rd-party/Atmel/xmega/drivers/rtc32/rtc32.h"


void TimerManagerTimerCallback(TimerManager::TimerId id, void* calling_object, U8 param)
{
	static_cast<TimerManager*>(calling_object)->OnTimerEvent(id, param);
}


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

void TimerManager::Time::SetNow()
{
	m_seconds = rtc_get_time();
	m_nanoseconds = 0; //TODO
}

void TimerManager::Time::SetByOffset(U32 offset, Unit unit)
{
	Reset();

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
				m_seconds += offset_seconds;
			}
			m_nanoseconds += offset*nanoseconds_per_unit;
			while (m_nanoseconds >= NANOSECONDS_PER_SECOND)
			{
				m_seconds += 1;
				m_nanoseconds -= NANOSECONDS_PER_SECOND;
			}
			break;
		}

		case SECOND:
		{
			m_seconds += offset;
			break;
		}

		case MINUTE:
		{
			m_seconds += offset*SECONDS_PER_MINUTE;
			break;
		}

		case HOUR:
		{
			m_seconds += offset*SECONDS_PER_HOUR;
			break;
		}

		default: break;
	}
}

void TimerManager::Time::IncrementTime(const Time& offset)
{
	m_nanoseconds += offset.m_nanoseconds;
	while (m_nanoseconds >= NANOSECONDS_PER_SECOND)
	{
		m_seconds += 1;
		m_nanoseconds -= NANOSECONDS_PER_SECOND;
	}
	m_seconds += offset.m_seconds;
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

void TimerManager::OnTimerEvent(TimerId UNUSED_PARAM(id), U8 UNUSED_PARAM(param))
{
	while(0<m_timed_events_list_length /* && AFTER!=now.Compare(m_timed_events.m_time TODO*/)
	{
		m_timed_events[0].m_callback(m_timed_events[0].m_id, m_timed_events[0].m_calling_object, m_timed_events[0].m_param);
		RemoveEvent(0);
	}
}

void TimerManager::SetTimeout(TimerId id, const Time& delay, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param)
{
	TimedEvent event;
	event.m_id = id;
	event.m_time.SetNow();
	event.m_time.IncrementTime(delay);
	event.m_callback = callback;
	event.m_calling_object = calling_object;
	event.m_param = param;

	U8 index = 0;
	while (index<m_timed_events_list_length && BEFORE == m_timed_events[index].m_time.Compare(event.m_time))
		index++;

	InsertEvent(index, event);
}

void TimerManager::SetTimeout(TimerId id, U32 delay, Unit unit, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param)
{
	TimedEvent event;
	event.m_id = id;
	event.m_time.SetNow();
	Time offset;
	offset.SetByOffset(delay, unit);
	event.m_time.IncrementTime(offset);
	event.m_callback = callback;
	event.m_calling_object = calling_object;
	event.m_param = param;

	U8 index = 0;
	while (index<m_timed_events_list_length && BEFORE == m_timed_events[index].m_time.Compare(event.m_time))
		index++;

	InsertEvent(index, event);
}

void TimerManager::ResetTimeout(TimerId id, const Time& delay, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param)
{
	ClearTimeout(id);
	SetTimeout(id, delay, callback, calling_object, param);
}

void TimerManager::ResetTimeout(TimerId id, U32 delay, Unit unit, void (* callback)(TimerId id, void* calling_object, U8 param), void* calling_object, U8 param)
{
	ClearTimeout(id);
	SetTimeout(id, delay, unit, callback, calling_object, param);
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
