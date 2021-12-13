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

#include QMK_KEYBOARD_H
#include "bootloader.h"


#ifdef OLED_ENABLE
#include "lib/key_logger.h"
#endif


#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
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


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  // ADJUST,
  RGBRST,
  L_TOS,
  L_T_CMD_CTL,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |LALT(-)  |   Q  |   W  |   E  |   R  |   T   |                      |  y   |  u   |  i   |  o   |  p   | =        |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |LCTRL(`) |   A  |   S  |   D  |   F  |   G   |                      |  h   |  j   |  k   |  l   |  ;   | RCTRL([) |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |RAISE(`) |   Z  |   X  |   C  |   V  |   B   |  esc  |      | Dele  |  n   |  m   |  ,   |  .   |  /   | RAISE(]) |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           | Back | LALT |L_CMD | Del  | LShift| space |      | enter |RShift| esc  | GUI  | ALT  |  \   |
 *           |  SP  |      |L_CTL | LOW  | lagn2 |       |      |       |lagn1 | LOW  |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 *
 */
 [_QWERTY] = LAYOUT( \
  LALT_T(KC_MINUS),    KC_Q,     KC_W,    KC_E,         KC_R,                   KC_T,                                              KC_Y,                KC_U,     KC_I,     KC_O,         KC_P,           KC_EQUAL,\
  LCTL_T(KC_QUOTE),    KC_A,     KC_S,    KC_D,         KC_F,                   KC_G,                                              KC_H,                KC_J,     KC_K,     KC_L,      KC_SCLN,    RCTL_T(KC_LBRC),\
  LT(_RAISE, KC_GRV),  KC_Z,     KC_X,    KC_C,         KC_V,                   KC_B,             KC_ESC,  KC_DELETE,              KC_N,                KC_M,  KC_COMM,   KC_DOT,      KC_SLSH, LT(_RAISE,KC_RBRC),\
                       KC_BSPC,  KC_LALT, L_T_CMD_CTL,  LT(_LOWER, KC_DELETE),  LSFT_T(KC_LANG2), KC_SPC,     KC_ENT,  RSFT_T(KC_LANG1),  LT(_LOWER, KC_ESC),  KC_RGUI,  KC_RALT,    KC_BSLASH\
),

/* RAISE
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |         |   1  |   2  |   3  |   4  |   5   |                      |   6  |   7  |   8  |  9   |  0   |          |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |         |      |      |      |      |       |                      | Left | Down | Up   | Down |      |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |      |      |      |      |       |       |      |       |      |      |      |      |  \   |          |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |Delet |      |      |      |       | TAB   |      | BackSP|      |      |      |      |   ¥  |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_RAISE] = LAYOUT( \
  _______,       KC_1,    KC_2,     KC_3,    KC_4,     KC_5,                            KC_6,     KC_7,     KC_8,      KC_9,       KC_0,   _______,\
  _______,    _______, _______,  _______, _______,  _______,                         KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT,    _______,   _______,\
  _______,    _______, _______,  _______, _______,  _______,   _______,    _______,  _______,  _______,  _______,   _______,  KC_BSLASH,   _______,\
            KC_DELETE, _______,  _______, _______,  _______,    KC_TAB,    KC_BSPC,  _______,  _______,  _______,   _______,    KC_JYEN\
),

/* LOWER
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |  F11    |  F1  |  F2  |  F3  |  F4  |  F5   |                      |  F6  |  F7  |  F8  | F9   |  F10 | F12      |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |         |      |      |      |      |       |                      |  INS | HOME |  PGU |      |      |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |      |      |      |      |       | c+a+d |      | PAUSE |PRINT |  END |  PGD |      |      |          |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |      |      |      |      |       |       |      | Delet |      |      |      |      |      |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_LOWER] = LAYOUT( \
   KC_F11,    KC_F1,  KC_F2,     KC_F3,   KC_F4,    KC_F5,                                    KC_F6,      KC_F7,       KC_F8,    KC_F9,    KC_F10,   KC_F12,\
  _______,  _______, _______,  _______, _______,  _______,                                  KC_LEFT,    KC_DOWN,       KC_UP,  KC_RIGHT, _______,  _______,\
  _______,  _______, _______,  _______, _______,  _______, LCA(KC_DELETE),   KC_PAUSE,   KC_PSCREEN,     KC_END,   KC_PGDOWN,  _______,   _______,  _______,\
            _______, _______,  _______, _______,  _______,        _______,  KC_DELETE,      _______,    _______,     _______,  _______,   _______\
),
/* ADJUST
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * | han/zen |  HU+ |  SA+ |  VA+ |      |       |                      |  0   |   1  |  4   |  7   |      |          |
 * |---------+------+------+------+------+-------|                      |------+------+------+------+------+----------|
 * |         |  HU- |  SA- |  VA+ |      |       |                      |  ,   |   2  |  5   |  8   |      |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |      |      |      |RMODE | MODE  | Tog   |      |       |  .   |   3  |  6   |  9   |      |          |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |      |      |      |      | TOS   | RST   |      |       |      |      |      |      |      |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_ADJUST] = LAYOUT( \
    L_TOS,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______, _______,                        KC_7,     KC_8,     KC_9,  _______,  _______, _______,\
  _______,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______, _______,                        KC_4,     KC_5,     KC_6,  _______,  _______, _______,\
  _______,  RGB_MOD,  RGB_TOG,   RGBRST,  _______, _______, _______,  _______,     KC_1,     KC_2,     KC_3,  _______,  _______, _______,\
            _______,  _______,   _______, _______, _______, _______,  _______,     KC_0,   KC_COMM,  KC_DOT,  _______,  _______\
)
};

#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
int RGB_current_mode;

uint8_t TOGGLE_MAC_LGUI = KC_LGUI;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


void keyboard_post_init_user(void)
{
    set_mac_mode_kb(true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {


#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    // case RAISE:
    //   if (record->event.pressed) {
    //     //not sure how to have keyboard check mode and set it to a variable, so my work around
    //     //uses another variable that would be set to true after the first time a reactive key is pressed.
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     #ifdef RGBLIGHT_ENABLE
    //       //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
    //     #endif
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
    case L_TOS:
        if (record->event.pressed) {
            set_mac_mode_kb(!is_mac_mode());
            if(is_mac_mode())
            {
                TOGGLE_MAC_LGUI = KC_LGUI;
            }
            else
            {
                TOGGLE_MAC_LGUI = KC_LCTL;
            }
        }
      return true;
      break;
    case L_T_CMD_CTL:
        if (record->event.pressed)
        {
            register_code(TOGGLE_MAC_LGUI);
        }
        else
        {
            unregister_code(TOGGLE_MAC_LGUI);
        }

      return true;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  return true;
}

#ifdef SPLIT_TRANSPORT_MIRROR
bool should_process_keypress(void)
{
    return true;
}
#endif

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_get_mode();
    #endif
    // //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init();   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
