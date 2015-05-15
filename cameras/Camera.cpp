
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Camera.h"

#include "../BackertrapAdaApp.h"


static PROGMEM_DECLARE(U8, SHUTTER_1_4000_p[]) = "1/4000";
static PROGMEM_DECLARE(U8, SHUTTER_1_2000_p[]) = "1/2000";
static PROGMEM_DECLARE(U8, SHUTTER_1_1000_p[]) = "1/1000";
static PROGMEM_DECLARE(U8, SHUTTER_1_500_p[])  = "1/500";
static PROGMEM_DECLARE(U8, SHUTTER_1_250_p[])  = "1/250";
static PROGMEM_DECLARE(U8, SHUTTER_1_125_p[])  = "1/125";
static PROGMEM_DECLARE(U8, SHUTTER_1_60_p[])   = "1/60";
static PROGMEM_DECLARE(U8, SHUTTER_1_30_p[])   = "1/30";
static PROGMEM_DECLARE(U8, SHUTTER_1_15_p[])   = "1/15";
static PROGMEM_DECLARE(U8, SHUTTER_1_8_p[])    = "1/8";
static PROGMEM_DECLARE(U8, SHUTTER_1_4_p[])    = "1/4";
static PROGMEM_DECLARE(U8, SHUTTER_1_2_p[])    = "1/2";
static PROGMEM_DECLARE(U8, SHUTTER_1_p[])      = "1\"";
static PROGMEM_DECLARE(U8, SHUTTER_2_p[])      = "2\"";
static PROGMEM_DECLARE(U8, SHUTTER_4_p[])      = "4\"";
static PROGMEM_DECLARE(U8, SHUTTER_8_p[])      = "8\"";
static PROGMEM_DECLARE(U8, SHUTTER_16_p[])     = "16\"";
static PROGMEM_DECLARE(U8, SHUTTER_32_p[])     = "32\"";
static PROGMEM_DECLARE(U8, SHUTTER_64_p[])     = "1'04\"";
static PROGMEM_DECLARE(U8, SHUTTER_128_p[])    = "2'08\"";
static PROGMEM_DECLARE(U8, SHUTTER_256_p[])    = "4'16\"";
static PROGMEM_DECLARE(U8, SHUTTER_512_p[])    = "8'32\"";
static PROGMEM_DECLARE(U8, SHUTTER_1024_p[])   = "17'04\"";

static PROGMEM_T PROGMEM_BYTE_ARRAY_T g_shutter_time_strings_p[] = {
	SHUTTER_1_4000_p,
	SHUTTER_1_2000_p,
	SHUTTER_1_1000_p,
	SHUTTER_1_500_p,
	SHUTTER_1_250_p,
	SHUTTER_1_125_p,
	SHUTTER_1_60_p,
	SHUTTER_1_30_p,
	SHUTTER_1_15_p,
	SHUTTER_1_8_p,
	SHUTTER_1_4_p,
	SHUTTER_1_2_p,
	SHUTTER_1_p,
	SHUTTER_2_p,
	SHUTTER_4_p,
	SHUTTER_8_p,
	SHUTTER_16_p,
	SHUTTER_32_p,
	SHUTTER_64_p,
	SHUTTER_128_p,
	SHUTTER_256_p,
	SHUTTER_512_p,
	SHUTTER_1024_p,
};

static PROGMEM_DECLARE(U8, g_shutter_time_p[]) = { //Accurate, logaritmic shutter times
	//Byte 0: bit 0-7 of second
	//Byte 1: bit 8-11 of second, bit 16-19 of microsecond
	//Byte 2: bit 8-15 of microsecond
	//Byte 3: bit 0-7 of microsecond
	//6 groups (EV +x/6)
/*EV13  1/8192 */ 0,0,0,122,   0,0,0,137,     0,0,0,154,     0,0,0,173,     0,0,0,194,      0,0,0,218,
/*EV12  1/4096 */ 0,0,0,244,   0,0,1,18,      0,0,1,52,      0,0,1,89,      0,0,1,132,      0,0,1,179,
/*EV11  1/2048 */ 0,0,1,232,   0,0,2,36,      0,0,2,103,     0,0,2,179,     0,0,3,7,        0,0,3,102,
/*EV10  1/1024 */ 0,0,3,209,   0,0,4,72,      0,0,4,206,     0,0,5,101,     0,0,6,14,       0,0,6,204,
/*EV9   1/512  */ 0,0,7,161,   0,0,8,144,     0,0,9,157,     0,0,10,202,    0,0,12,28,      0,0,13,152,
/*EV8   1/256  */ 0,0,15,66,   0,0,17,33,     0,0,19,58,     0,0,21,148,    0,0,24,57,      0,0,27,48,
/*EV7   1/128  */ 0,0,30,133,  0,0,34,65,     0,0,38,115,    0,0,43,41,     0,0,48,114,     0,0,54,96,
/*EV6   1/64   */ 0,0,61,9,    0,0,68,130,    0,0,76,230,    0,0,86,81,     0,0,96,227,     0,0,108,193,
/*EV5   1/32   */ 0,0,122,18,  0,0,137,5,     0,0,153,205,   0,0,172,162,   0,0,193,198,    0,0,217,129,
/*EV4   1/16   */ 0,0,244,36,  0,1,18,10,     0,1,51,153,    0,1,89,68,     0,1,131,141,    0,1,179,2,
/*EV3   1/8    */ 0,1,232,72,  0,2,36,20,     0,2,103,50,    0,2,178,137,   0,3,7,25,       0,3,102,5,
/*EV2   1/4    */ 0,3,208,144, 0,4,72,40,     0,4,206,100,   0,5,101,17,    0,6,14,50,      0,6,204,9,
/*EV1   1/2    */ 0,7,161,32,  0,8,144,79,    0,9,156,201,   0,10,202,35,   0,12,28,101,    0,13,152,19,
/*EV0    1"    */ 1,0,0,0,     1,1,222,94,    1,3,247,81,    1,6,82,6,      1,8,246,137,    1,11,237,229,
/*EV-1   2"    */ 2,0,0,0,     2,3,188,188,   2,7,238,162,   2,12,164,11,   3,2,170,210,    3,8,153,139,
/*EV-2   4"    */ 4,0,0,0,     4,7,121,120,   5,0,155,4,     5,10,5,214,    6,5,85,164,     7,1,240,214,
/*EV-3   8"    */ 8,0,0,0,     8,14,242,240,  10,1,54,8,     11,4,201,108,  12,10,171,72,   14,3,225,171,
/*EV-4  16"    */ 16,0,0,0,    17,14,163,161, 20,2,108,17,   22,9,146,217,  25,6,20,81,     28,7,195,87,
/*EV-5  32"    */ 32,0,0,0,    35,14,5,2,     40,4,216,34,   45,3,227,114,  50,12,40,162,   57,0,68,110,
/*EV-6  64"    */ 64,0,0,0,    71,12,199,195, 80,9,176,67,   90,7,198,228,  101,9,15,3,     114,0,136,220,
/*EV-7  128"   */ 128,0,0,0,   143,10,77,70,  161,4,30,70,   181,0,75,136,  203,2,219,199,  228,1,17,184,
/*EV-8  256"   */ 0,16,0,0,    31,21,88,76,   66,24,60,141,  106,16,151,16, 150,21,183,141, 200,18,35,112,
/*EV-9  512"   */ 0,32,0,0,    62,42,176,153, 133,33,54,218, 212,33,46,32,  44,59,111,27,   144,52,70,223,
/*EV-10 1024"  */ 0,64,0,0,    125,70,30,241, 10,82,109,179, 168,82,92,64,  89,103,155,245, 32,120,141,191
};


Camera::Camera(int (*vtable)(void* camera, VTABLE_FUNC vfunc, void* param))
: m_vtable(vtable)
{
}

void Camera::TriggerCamera(const TimerManager::Time& shutter) const
{
	APP()->GetGPIOManager()->SetPinState(DEFAULT_CAMERA_PIN, HIGH);
	APP()->GetTimerManager()->ResetTimeout(TimerManager::CAMERA_TRIGGERED_TIMEOUT, shutter);
}

void Camera::TimerCallback()
{
	APP()->GetGPIOManager()->SetPinState(DEFAULT_CAMERA_PIN, LOW);
}

U8 PROGMEM_PTR_T Camera::GetShutterText(ShutterTime shutter) const
{
	return g_shutter_time_strings_p[shutter];
}

void Camera::GetShutterSpeed(U8 shutter_index, TimerManager::Time& time)
{
	if (MIN_SHUTTER_INDEX>shutter_index || MAX_SHUTTER_INDEX>shutter_index)
	{
		time.Reset();
	}
	else
	{
		time.m_seconds = PROGMEM_READ_BYTE((U8 PROGMEM_PTR_T)(&g_shutter_time_p[shutter_index])) |
		                 (PROGMEM_READ_BYTE((U8 PROGMEM_PTR_T)(&g_shutter_time_p[shutter_index+1]))&0xF0)<<4;

		time.m_nanoseconds = ((PROGMEM_READ_WORD((U8 PROGMEM_PTR_T)(&g_shutter_time_p[shutter_index+1]))&0x0F)<<12 |
		                      PROGMEM_READ_BYTE((U8 PROGMEM_PTR_T)(&g_shutter_time_p[shutter_index+2]))<<8 |
		                      PROGMEM_READ_BYTE((U8 PROGMEM_PTR_T)(&g_shutter_time_p[shutter_index+3]))) * NANOSECONDS_PER_MICROSECOND;
	}
}
