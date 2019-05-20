#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

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
  ADJUST,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * | -       |   Q  |   W  |   E  |   R  |   T   |                      |  y   |  u   |  i   |  o   |  p   | =        |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |LCTRL(`) |   A  |   S  |   D  |   F  |   G   |                      |  h   |  j   |  k   |  l   |  ;   | RCTRL([) |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |RAISE(`) |   Z  |   X  |   C  |   V  |   B   |  BSSP |      | esc   |  n   |  m   |  ,   |  .   |  /   | RAISE(]) |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |  &   | LGUI | ALT  |      | LShift| Spacet|      | enter |RShift|      | ALT  | GUI  |  \   |
 *           |      |      |      | LOW  | lagn2 |       |      |       |lagn1 | LOW  |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 *
 */
 [_QWERTY] = LAYOUT( \
  KC_MINUS,                   KC_Q,      KC_W,    KC_E,    KC_R,              KC_T,                                    KC_Y,    KC_U,     KC_I,    KC_O,       KC_P,           KC_EQUAL,\
  LCTL_T(KC_QUOTE),           KC_A,     KC_S,     KC_D,    KC_F,              KC_G,                                    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,    RCTL_T(KC_LBRC),\
  LT(_RAISE, KC_GRV),         KC_Z,     KC_X,     KC_C,    KC_V,              KC_B,   KC_BSPC,    KC_ESC,              KC_N,    KC_M,  KC_COMM,  KC_DOT,    KC_SLSH, LT(_RAISE,KC_RBRC),\
                      KC_AMPERSAND,  KC_LGUI,  KC_LALT,   LOWER,  LSFT_T(KC_LANG2),    KC_SPC,    KC_ENT,  RSFT_T(KC_LANG1),   LOWER,  KC_RALT, KC_RGUI,  KC_BSLASH\
),
/* LOWER
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |  F11    |  F1  |  F2  |  F3  |  F4  |  F5   |                      |  F6  |  F7  |  F8  | F9   |  F10 | F12      |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |         |   !  |  @   |  #   |  $   |  %    |                      |  ^   |  &   |  *   |  (   |  )   |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |  "   |  :   |  +   |  _   |  ?    |       |      |       |  |   |  <   |  >   |  {   |  }   |          |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |      |      |      |      |       |  ~    |      |       |      |      |      |      |      |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_LOWER] = LAYOUT( \
   KC_F11,    KC_F1,    KC_F2,     KC_F3,    KC_F4,    KC_F5,                         KC_F6,     KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F12,\
  _______,  KC_EXLM,    KC_AT,   KC_HASH,   KC_DLR,  KC_PERC,                       KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,\
  _______,   KC_DQT,  KC_COLN,   KC_PLUS,  KC_UNDS,  KC_QUES, _______,    _______,  KC_PIPE,   KC_LABK,  KC_RABK,  KC_LCBR,  KC_RCBR,  _______,\
            _______,  _______,   _______,  _______,  _______, KC_TILD,    _______,  _______,   _______,  _______,  _______,  _______\
),
/* RAISE
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |         |   1  |   2  |   3  |   4  |   5   |                      |   6  |   7  |   8  |  9   |   10 |          |
 * |---------+------+----- +------+------+-------|                      |------+------+----- +------+------+----------|
 * |         |   =  |  "   |  -   |  /   |  ¥     |                     | Left | Down | Up   | Down |  "   |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |   _  |      |      |      |       |       |      |       |      |      |      |  ¥   |  \   |          |
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |      |      |      |      |       | TAB   |      | BackSP|      |      |      |      |      |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_RAISE] = LAYOUT( \
  _______,      KC_1,    KC_2,      KC_3,     KC_4,      KC_5,                          KC_6,     KC_7,     KC_8,      KC_9,       KC_0,  _______,\
  _______,  KC_EQUAL,  KC_GRV,  KC_MINUS, KC_SLASH, KC_BSLASH,                       KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT,   KC_MINUS,  _______,\
  _______,  KC_MINUS, _______,   _______,  _______,   _______, _______,    _______,  _______,  _______,  _______,   KC_JYEN,  KC_BSLASH,  _______,\
            _______,  _______,   _______,  _______,   _______,  KC_TAB,    KC_BSPC,  _______,  _______,  _______,   _______,    _______\
),

/* RAISE
 * ,---------------------------------------------.                      ,---------------------------------------------.
 * |         |  HU+ |  SA+ |  VA+ |      |       |                      |      |      |  VA+ |  SA+ |  HU+ |          |
 * |---------+------+------+------+------+-------|                      |------+------+------+------+------+----------|
 * |         |  HU- |  SA- |  VA+ |      |       |                      |      |      |  VA+ |  SA- |  HU- |          |
 * |---------+------+------+------+------+-------|-------.      .-------|------+------+------+------+------+----------|
 * |         |      |      |      |RMODE | MODE  | Tog   |      |  Tog  | MODE | RMODE|      |      |      |          | 
 * `---------+------+------+------+------+-------+-------|      |-------+------+------+------+------+------|----------'
 *           |      |      |      |      |       | RST   |      | RST   |      |      |      |      |      |
 *           |      |      |      |      |       |       |      |       |      |      |      |      |      |
 *           `-------------------------------------------'      '-----------------------------------'------'
 */
 [_ADJUST] = LAYOUT( \
  _______,  RGB_HUI,  RGB_SAI,  RGB_VAI,    _______, _______,                       _______,  _______,  RGB_VAI,  RGB_SAI,  RGB_HUI, _______,\
  _______,  RGB_HUD,  RGB_SAD,  RGB_VAD,    _______, _______,                       _______,  _______,  RGB_VAD,  RGB_SAD,  RGB_HUD, _______,\
  _______,  _______,  _______,   _______,  RGB_RMOD, RGB_MOD, RGB_TOG,    RGB_TOG,  RGB_MOD, RGB_RMOD,  _______,  _______,  _______, _______,\
            _______,  _______,   _______,   _______, _______, RGBRST,      RGBRST,  _______,  _______,  _______,  _______,  _______\
)
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
//const char *read_rgb_info(void); 
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
//    case RGB_MOD:
//      #ifdef RGBLIGHT_ENABLE
//        if (record->event.pressed) {
//          rgblight_mode(RGB_current_mode);
//          rgblight_step();
//          RGB_current_mode = rgblight_config.mode;
//        }
//      #endif
//      return false;
//      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
