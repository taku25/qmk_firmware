#pragma once

#include "accent.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);
#define LAYOUT( \
	L00, L01, L02, L03, L04, L05,            R00, R01, R02, R03, R04, R05,  \
	L10, L11, L12, L13, L14, L15,            R10, R11, R12, R13, R14, R15,  \
	L20, L21, L22, L23, L24, L25, L36,  R36, R20, R21, R22, R23, R24, R25,  \
	     L30, L31, L32, L33, L34, L35,  R30, R31, R32, R33, R34, R35 \
	) \
	{ \
		{ KC_NO, L05, L04, L03, L02, L01, L00 }, \
		{ KC_NO, L15, L14, L13, L12, L11, L10 }, \
		{ KC_NO, L25, L24, L23, L22, L21, L20 }, \
		{ L36, L35, L34, L33, L32, L31, L30 }, \
		{ KC_NO, R00, R01, R02, R03, R04, R05 }, \
		{ KC_NO, R10, R11, R12, R13, R14, R15 }, \
		{ KC_NO, R20, R21, R22, R23, R24, R25 }, \
		{ R36, R30, R31, R32, R33, R34, R35 } \
	}
