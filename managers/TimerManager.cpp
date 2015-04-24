
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "TimerManager.h"

#include "../3rd-party/Atmel/common/services/clock/sysclk.h"
#include "../3rd-party/Atmel/xmega/drivers/rtc32/rtc32.h"


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

void TimerManager::SetTimeout(TimerId id, U32 delay, Unit unit)
{
	TimedEvent event;
	event.m_id = id;
	event.m_time = Now();
	switch(unit)
	{
		case MICROSECOND: event.m_time += delay*MICROSECOND_OFFSET; break;
		case MILLISECOND: event.m_time += delay*MILLISECOND_OFFSET; break;
		case SECOND:      event.m_time += delay*SECOND_OFFSET; break;
		default: break;
	}
	
	U8 index = 0;
	while (index<m_timed_events_list_length && m_timed_events[index].m_time<event.m_time)
		index++;

	InsertEvent(index, event);
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

U64 TimerManager::Now() const
{
	return 0; //ToDo
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
