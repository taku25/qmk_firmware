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

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFFED
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0002
#define MANUFACTURER    taku25
#define PRODUCT         Accent_rev1

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

/* Use I2C or Serial */
#define USE_SERIAL
//#define USE_MATRIX_I2C

/* Soft Serial defines */
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Accent keyboard OLED support
//      see ./local_features.mk: OLED_SELECT=local
// #ifdef OLED_ENABLE
//   #define SSD1306OLED
// #endif

#define OLED_UPDATE_INTERVAL 50

/* Select rows configuration */
// Rows are 4 or 5

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }

// wiring of each half
#define MATRIX_COLS 7
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

//#define RGBLED_NUM 12    // Number of LEDs. see ./keymaps/default/config.h

// Accent keyboard RGB LED support
//#define RGBLIGHT_ANIMATIONS : see ./rules.mk: LED_ANIMATIONS = yes or no
//    see ./rules.mk: LED_BACK_ENABLE or LED_UNDERGLOW_ENABLE set yes
#ifdef RGBLIGHT_ENABLE
    #define RGBLED_NUM 16

    #define RGBLIGHT_LIMIT_VAL 130
    #define RGBLIGHT_VAL_STEP 17

    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
#endif

#define USB_MAX_POWER_CONSUMPTION 400
