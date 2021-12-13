/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include QMK_KEYBOARD_H

#include "lib/mode_icon_reader.h"
#include "lib/key_logger.h"
#include "lib/logo_reader.h"
#include "lib/layer_state_reader.h"

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#if defined(SSD1306OLED) || defined(OLED_ENABLE)

#    if defined(OLED_ENABLE)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    } else {
        return OLED_ROTATION_180;
    }
}
#    else
#        define oled_write(data,flag)    matrix_write(matrix, data)
#        define oled_write_P(data,flag)  matrix_write_P(matrix, data)
#    endif

#    ifdef SSD1306OLED
void matrix_scan_user(void) {
    iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                   const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}
#    endif

//assign the right code to your layers for OLED display

#    ifdef SSD1306OLED
static void render_logo(struct CharacterMatrix *matrix) {
#    else
static void render_logo(void) {
#    endif
    oled_write(read_logo(), false);
}

// #    ifdef SSD1306OLED
// static void render_rgbled_status(bool full, struct CharacterMatrix *matrix) {
// #    else
// static void render_rgbled_status(bool full) {
// #    endif
// #    ifdef RGBLIGHT_ENABLE
//     char buf[30];
//     if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
//         if (full) {
//             snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ",
//                      rgblight_get_mode(),
//                      rgblight_get_hue()/RGBLIGHT_HUE_STEP,
//                      rgblight_get_sat()/RGBLIGHT_SAT_STEP,
//                      rgblight_get_val()/RGBLIGHT_VAL_STEP);
//         } else {
//             snprintf(buf, sizeof(buf), "[%2d] ", rgblight_get_mode());
//         }
//         oled_write(buf, false);
//     }
// #    endif
// }

#    ifdef SSD1306OLED
static void render_key_status(bool full, struct CharacterMatrix *matrix) {
#    else
static void render_key_status(bool full) {
#    endif

    oled_write(read_keylog(), false);
    if(full){
        oled_write_P(PSTR("\n"), false);
        oled_write(read_keylogs(), false);
    }
}

#    ifdef SSD1306OLED
static void render_layer_status(struct CharacterMatrix *matrix) {
#    else
static void render_layer_status(void) {
#    endif

    const char* buf = read_layer_state();
    oled_write(buf, false);
    oled_write_P(PSTR("\n"), false);
}

#    ifdef SSD1306OLED
void render_mode_status(struct CharacterMatrix *matrix) {
#    else
void render_mode_status(void) {
#    endif
  // Render to mode icon
    const char * icon = read_mode_icon(is_mac_mode());
    oled_write(icon, false);
    oled_write_P(PSTR(" "), false);
}


#    ifdef SSD1306OLED
#        if OLED_UPDATE_INTERVAL > 0
uint16_t oled_update_timeout;
#        endif

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;

#        if DEBUG_TO_SCREEN
    if (debug_enable) {
        return;
    }
#        endif

#if      OLED_UPDATE_INTERVAL > 0
    if (timer_elapsed(oled_update_timeout) < OLED_UPDATE_INTERVAL) {
        return;
    }
    oled_update_timeout = timer_read();
#endif
    matrix_clear(&matrix);
    if (is_keyboard_master()) {

        render_logo(&matrix);
    } else {
        render_mode_status(&matrix);
        // render_rgbled_status(false, &matrix);
        render_layer_status(&matrix);
        render_key_status(true, &matrix);
    }
    matrix_update(&display, &matrix);
}
#    else
bool oled_task_user(void) {

#        if DEBUG_TO_SCREEN
    if (debug_enable) {
        return;
    }
#        endif

    if (is_keyboard_master()) {
        render_logo();
    } else {
        render_mode_status();
        render_layer_status();
        render_key_status(true);
        // render_rgbled_status(false);
    }
    return false;
}
#    endif
#endif
