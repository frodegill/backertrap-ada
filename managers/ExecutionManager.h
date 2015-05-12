#ifndef _EXECUTION_MANAGER_H_
#define _EXECUTION_MANAGER_H_

// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "../defines.h"

#include "TimerManager.h"


class ExecutionManager
{
public:
	enum ExecuteState
	{
		STOPPED,
		PAUSED,
		RUNNING
	};
	
	enum OpCodes
	{
		//OpCodes without data
		END_OF_PROGRAM = 0,
		LOOP,
		FOREVER, //End loop
		TRIGGER_CAMERA,
		TRIGGER_FLASH,
		ADJUST_EXPOSURE_PLUS2,
		ADJUST_EXPOSURE_PLUS3,
		ADJUST_EXPOSURE_MINUS2,
		ADJUST_EXPOSURE_MINUS3,
		//OpCodes with 8-bit data
		SET_PIN_LOW = 64,
		SET_PIN_HIGH,
		UNTIL_PIN_LOW, //End loop
		UNTIL_PIN_HIGH, //End loop
		WAIT_FOR_PIN_LOW,
		WAIT_FOR_PIN_HIGH,
		SET_SHUTTER_TIME,
		//OpCodes with 16-bit data
		UNTIL_TIME_NANO = 128, //End loop
		UNTIL_TIME_MICRO, //End loop
		UNTIL_TIME_MILLI, //End loop
		UNTIL_TIME_SECOND, //End loop
		UNTIL_TIME_MINUTES, //End loop
		UNTIL_TIME_HOURS, //End loop
		UNTIL_COUNT, //End loop
		WAIT_NANO,
		WAIT_MICRO,
		WAIT_MILLI,
		WAIT_SECOND,
		WAIT_MINUTES
	};


private:
	struct LoopContext
	{
		U8  m_start_of_loop_pointer;
		U16 m_counter;
		TimerManager::Time m_start_time;
		TimerManager::Time m_end_time;
	};

public:
	ExecutionManager();
	~ExecutionManager();

public:
	bool LoadProgram(U8 id);
	void StartExecutingProgram();
	void StopExecutingProgram();
	void ResumeExecutingProgram();
	ExecuteState GetExecuteState() const {return m_execute_state;}

private:
	ExecuteState ExecuteNextOpCode();
	U8  GetByte(U8& instruction_pointer) const;
	U16 GetWord(U8& instruction_pointer) const;
	void PushLoopContext();
	void PopLoopContext();

private:
	U8           m_program[MAX_PROGRAM_SIZE];
	LoopContext  m_loop_context[MAX_PROGRAM_LOOP_CONTEXT_SIZE];
	U8           m_loop_context_index;
	U8           m_instruction_pointer;
	ExecuteState m_execute_state;

	U8  m_shuttertime_index; //one stop = 6
};

#endif // _EXECUTION_MANAGER_H_
