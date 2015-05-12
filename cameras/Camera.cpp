
// Copyright (C) 2015  Frode Roxrud Gill
// See LICENSE file for GPLv3 license

#include "Camera.h"


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
	SHUTTER_32_p
};

static PROGMEM_DECLARE(U8, g_shutter_time_p[]) = { //Accurate, logaritmic shutter times
	//One byte Second, two bytes microsecond (0-65535)
	//6 groups (EV +x/6)
/*EV13  1/8192 */ 0,0,8,      0,0,9,      0,0,10,     0,0,11,     0,0,13,     0,0,14,
/*EV12  1/4096 */ 0,0,16,     0,0,18,     0,0,20,     0,0,23,     0,0,25,     0,0,29,
/*EV11  1/2048 */ 0,0,32,     0,0,36,     0,0,40,     0,0,45,     0,0,51,     0,0,57,
/*EV10  1/1024 */ 0,0,64,     0,0,72,     0,0,81,     0,0,91,     0,0,102,    0,0,114,
/*EV9   1/512  */ 0,0,128,    0,0,144,    0,0,161,    0,0,181,    0,0,203,    0,0,228,
/*EV8   1/256  */ 0,1,0,      0,1,31,     0,1,67,     0,1,106,    0,1,150,    0,1,200,
/*EV7   1/128  */ 0,2,0,      0,2,63,     0,2,133,    0,2,212,    0,3,45,     0,3,144,
/*EV6   1/64   */ 0,4,0,      0,4,125,    0,5,10,     0,5,168,    0,6,89,     0,7,33,
/*EV5   1/32   */ 0,8,0,      0,8,251,    0,10,20,    0,11,80,    0,12,179,   0,14,65,
/*EV4   1/16   */ 0,16,0,     0,17,246,   0,20,41,    0,22,161,   0,25,102,   0,28,130,
/*EV3   1/8    */ 0,32,0,     0,35,235,   0,40,81,    0,45,65,    0,50,204,   0,57,4,
/*EV2   1/4    */ 0,64,0,     0,71,214,   0,80,163,   0,90,130,   0,101,152,  0,114,9,
/*EV1   1/2    */ 0,128,0,    0,143,173,  0,161,69,   0,181,5,    0,203,48,   0,228,18,
/*EV0    1"    */ 1,0,0,      1,31,90,    1,66,138,   1,106,10,   1,150,96,   1,200,36,
/*EV-1   2"    */ 2,0,0,      2,62,179,   2,133,20,   2,212,20,   3,44,192,   3,144,72,
/*EV-2   4"    */ 4,0,0,      4,125,103,  5,10,41,    5,168,40,   6,89,128,   7,32,144,
/*EV-3   8"    */ 8,0,0,      8,250,205,  10,20,81,   11,80,79,   12,178,255, 14,65,31,
/*EV-4  16"    */ 16,0,0,     17,245,155, 20,40,163,  22,160,158, 25,101,255, 28,130,62,
/*EV-5  32"    */ 32,0,0,     35,235,54,  40,81,70,   45,65,61,   50,203,253, 57,4,124
};


Camera::Camera(int (*vtable)(void* camera, VTABLE_FUNC vfunc, void* param))
: m_vtable(vtable)
{
}

U8 PROGMEM_PTR_T Camera::GetShutterText(ShutterTime shutter) const
{
	return g_shutter_time_strings_p[shutter];
}
