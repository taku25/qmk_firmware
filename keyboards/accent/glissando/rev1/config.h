/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

/* Use I2C or Serial */
#define USE_SERIAL
//#define USE_I2C

/* Soft Serial defines */
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS


#ifdef OLED_ENABLE
    #define OLED_UPDATE_INTERVAL 50
    #define SPLIT_TRANSPORT_MIRROR
#endif

/* Select rows configuration */
// Rows are 4 or 5

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }

// wiring of each half
#define MATRIX_COLS 6
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order
//
//
//
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


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_PIN D3
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3


#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    #define RGBLIGHT_LIMIT_VAL 130
    #define RGBLIGHT_VAL_STEP 17

    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17

    #define RGBLED_NUM 56
    #define RGBLED_SPLIT { 28, 28 }


    #if defined(RGB_MATRIX_ENABLE)

        #define DRIVER_LED_TOTAL RGBLED_NUM
        #define RGB_MATRIX_SPLIT RGBLED_SPLIT
        #define SPLIT_TRANSPORT_MIRROR

        #define RGB_MATRIX_KEYPRESSES
        #define RGB_MATRIX_KEYRELEASES


        #define RGB_DISABLE_WHEN_USB_SUSPENDED true
        #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
        #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200

    #else
        #define RGBLIGHT_SPLIT

        #define RGBLIGHT_EFFECT_BREATHING
        #define RGBLIGHT_EFFECT_RAINBOW_MOOD
        #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
        #define RGBLIGHT_EFFECT_SNAKE
        #define RGBLIGHT_EFFECT_KNIGHT
        #define RGBLIGHT_EFFECT_CHRISTMAS
        #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #endif
#endif


#define USB_MAX_POWER_CONSUMPTION 400
