
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "ExecutionManager.h"

#include "../BackertrapAdaApp.h"
#include "../cameras/Camera.h"


ExecutionManager::ExecutionManager()
: m_execute_state(STOPPED)
{
	U8 i;
	for (i=0; i<MAX_PROGRAM_SIZE; i++)
	{
		m_program[i] = END_OF_PROGRAM;
	}
}

ExecutionManager::~ExecutionManager()
{
}

bool ExecutionManager::LoadProgram(U8 id)
{
	return APP()->GetStorageManager()->LoadProgram(id);
}

void ExecutionManager::StartExecutingProgram()
{
	m_shuttertime_index = DEFAULT_SHUTTER_INDEX;

	m_loop_context_index = 0;
	m_loop_context[m_loop_context_index].m_start_of_loop_pointer = 0;
	m_loop_context[m_loop_context_index].m_counter = 0;
	m_loop_context[m_loop_context_index].m_start_time.Reset();
	m_loop_context[m_loop_context_index].m_end_time.Reset();

	m_instruction_pointer = 0;
	m_execute_state = RUNNING;
	ResumeExecutingProgram();
}

void ExecutionManager::StopExecutingProgram()
{
	APP()->GetTimerManager()->ClearTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT);
	//ToDo?
	m_execute_state = STOPPED;
}

void ExecutionManager::ResumeExecutingProgram()
{
	if (STOPPED == m_execute_state)
		return;

	while(RUNNING == ExecuteNextOpCode())
	{
	}
}

ExecutionManager::ExecuteState ExecutionManager::ExecuteNextOpCode()
{
	TimerManager::Time time;
	switch(m_program[m_instruction_pointer++])
	{
		case TRIGGER_CAMERA: break; //ToDo

		case TRIGGER_FLASH: break; //ToDo

		case ADJUST_EXPOSURE_PLUS2: m_shuttertime_index += MIN(MAX_SHUTTER_INDEX-m_shuttertime_index,3); break; //Half stop, where a whole stop is 6
		case ADJUST_EXPOSURE_PLUS3: m_shuttertime_index += MIN(MAX_SHUTTER_INDEX-m_shuttertime_index,2); break; //A third of a stop, where a whole stop is 6
		case ADJUST_EXPOSURE_MINUS2: m_shuttertime_index -= MIN(m_shuttertime_index-MIN_SHUTTER_INDEX,3); break; //Half stop, where a whole stop is 6
		case ADJUST_EXPOSURE_MINUS3: m_shuttertime_index -= MIN(m_shuttertime_index-MIN_SHUTTER_INDEX,2); break; //A third of a stop, where a whole stop is 6

		case SET_SHUTTER_TIME: m_shuttertime_index = GetByte(m_instruction_pointer);
		                       break;

		case SET_PIN_LOW: APP()->GetGPIOManager()->SetPinState(GetByte(m_instruction_pointer), LOW);
		                  break;

		case SET_PIN_HIGH: APP()->GetGPIOManager()->SetPinState(GetByte(m_instruction_pointer), HIGH);
		                   break;

		case WAIT_NANO: APP()->GetTimerManager()->SetTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT, GetWord(m_instruction_pointer), TimerManager::NANOSECOND);
		                 m_execute_state = PAUSED;
		                 break;

		case WAIT_MICRO: APP()->GetTimerManager()->SetTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT, GetWord(m_instruction_pointer), TimerManager::MICROSECOND);
		                 m_execute_state = PAUSED;
		                 break;

		case WAIT_MILLI: APP()->GetTimerManager()->SetTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT, GetWord(m_instruction_pointer), TimerManager::MILLISECOND);
		                 m_execute_state = PAUSED;
		                 break;

		case WAIT_SECOND: APP()->GetTimerManager()->SetTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT, GetWord(m_instruction_pointer), TimerManager::SECOND);
		                  m_execute_state = PAUSED;
		                  break;

		case WAIT_MINUTES: APP()->GetTimerManager()->SetTimeout(TimerManager::PROGRAM_WAIT_TIMEOUT, 60 * GetWord(m_instruction_pointer), TimerManager::SECOND);
		                   m_execute_state = PAUSED;
		                   break;

		case WAIT_FOR_PIN_LOW: break; //ToDo
		case WAIT_FOR_PIN_HIGH: break; //ToDo

		case LOOP: PushLoopContext(); break;

		case FOREVER: m_instruction_pointer = m_loop_context[m_loop_context_index].m_start_of_loop_pointer;
		              break;

		case UNTIL_COUNT: if (m_loop_context[m_loop_context_index].m_counter++ < GetByte(m_instruction_pointer))
		                  {
			                  m_instruction_pointer = m_loop_context[m_loop_context_index].m_start_of_loop_pointer;
		                  }
		                  else
		                  {
			                  PopLoopContext();
		                  }
		                  break;
		                  
		case UNTIL_PIN_LOW: if (APP()->GetGPIOManager()->GetPinState(GetByte(m_instruction_pointer)) != LOW)
		                    {
			                    m_instruction_pointer = m_loop_context[m_loop_context_index].m_start_of_loop_pointer;
		                    }
		                    else
		                    {
			                    PopLoopContext();
		                    }
		                    break;

		case UNTIL_PIN_HIGH: if (APP()->GetGPIOManager()->GetPinState(GetByte(m_instruction_pointer)) != HIGH)
		                     {
			                     m_instruction_pointer = m_loop_context[m_loop_context_index].m_start_of_loop_pointer;
		                     }
		                     else
		                     {
			                     PopLoopContext();
		                     }
		                     break;

		case UNTIL_TIME_NANO:
		case UNTIL_TIME_MICRO:
		case UNTIL_TIME_MILLI:
		case UNTIL_TIME_SECOND:
		case UNTIL_TIME_MINUTES:
		case UNTIL_TIME_HOURS:
		                      APP()->GetTimerManager()->Now(time);
		                      if (!m_loop_context[m_loop_context_index].m_end_time.IsValid())
		                      {
			                      TimerManager::Unit unit;
			                      switch(m_program[m_instruction_pointer-1]) //The first switch incremented it
			                      {
			                        default:
			                        case UNTIL_TIME_NANO:    unit = TimerManager::NANOSECOND; break;
			                        case UNTIL_TIME_MICRO:   unit = TimerManager::MICROSECOND; break;
			                        case UNTIL_TIME_MILLI:   unit = TimerManager::MILLISECOND; break;
			                        case UNTIL_TIME_SECOND:  unit = TimerManager::SECOND; break;
			                        case UNTIL_TIME_MINUTES: unit = TimerManager::MINUTE; break;
			                        case UNTIL_TIME_HOURS:   unit = TimerManager::HOUR; break;
			                      }
			                      m_loop_context[m_loop_context_index].m_end_time = m_loop_context[m_loop_context_index].m_start_time;
			                      APP()->GetTimerManager()->IncrementTime(m_loop_context[m_loop_context_index].m_end_time, GetWord(m_instruction_pointer), unit);
		                      }
		                      if (TimerManager::AFTER == m_loop_context[m_loop_context_index].m_end_time.Compare(time))
		                      {
			                      m_instruction_pointer = m_loop_context[m_loop_context_index].m_start_of_loop_pointer;
		                      }
		                      else
		                      {
			                      PopLoopContext();
		                      }
		                      break;

		case END_OF_PROGRAM:
		default: m_execute_state = STOPPED; break;
	}

	if (MAX_PROGRAM_SIZE == m_instruction_pointer)
	{
		m_execute_state = STOPPED;
	}

	return m_execute_state;
}

U8 ExecutionManager::GetByte(U8& instruction_pointer) const
{
	return m_program[instruction_pointer++];
}

U16 ExecutionManager::GetWord(U8& instruction_pointer) const
{
	U16 val = m_program[instruction_pointer++];
	return val<<8 | m_program[instruction_pointer++];
}

void ExecutionManager::PushLoopContext()
{
	m_loop_context_index++;
	if (MAX_PROGRAM_LOOP_CONTEXT_SIZE <= m_loop_context_index)
	{
		m_execute_state = STOPPED;
	}
	else
	{
		APP()->GetTimerManager()->Now(m_loop_context[m_loop_context_index].m_start_time);
		m_loop_context[m_loop_context_index].m_end_time.Reset();
		m_loop_context[m_loop_context_index].m_counter = 0;
		m_loop_context[m_loop_context_index].m_start_of_loop_pointer = m_instruction_pointer;
	}
}

void ExecutionManager::PopLoopContext()
{
	if (0 == m_loop_context_index)
	{
		m_execute_state = STOPPED;
	}
	else
	{
		m_loop_context_index--;
	}
}
