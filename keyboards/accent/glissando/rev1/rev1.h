#pragma once

#include "accent.h"

bool is_mac_mode(void);
void set_mac_mode_kb(bool macmode);

#ifndef SPLIT_KEYBOARD
    extern bool is_accent_master(void);
    #define is_keyboard_master() is_accent_master()
#endif

// Each keymap.c should use is_keyboard_master() instead of 'is_master', 'has_usb()'.
// But keep 'is_master' for a while for backwards compatibility
//  for the old keymap.c.
extern uint8_t is_master; // 'is_master' will be obsolete, it is recommended to use 'is_keyboard_master ()' instead.
#define has_usb() is_keyboard_master()

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,            R00, R01, R02, R03, R04, R05,  \
    L10, L11, L12, L13, L14, L15,            R10, R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,            R20, R21, R22, R23, R24, R25,  \
                   L30, L31, L32, L33,  R30, R31, R32, R33  \
) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { KC_NO, KC_NO,  L30, L31, L32, L33  }, \
        {  R05, R04, R03, R02, R01, R00 }, \
        {  R15, R14, R13, R12, R11, R10 }, \
        {  R25, R24, R23, R22, R21, R20 }, \
        { KC_NO, KC_NO, R33, R32, R31, R30}, \
}

