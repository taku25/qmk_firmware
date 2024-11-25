#include "accent.h"


bool is_mac_mode_flag = false;

bool is_mac_mode(void) {
    return is_mac_mode_flag;
}

void set_mac_mode_kb(bool macmode) {
    is_mac_mode_flag = macmode;
}



uint8_t TOGGLE_MAC_LGUI = KC_LGUI;

void persistent_default_layer_set(uint16_t default_layer)
{
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


void keyboard_post_init_user(void)
{
    set_mac_mode_kb(true);
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
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
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
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
  }
  return true;
}

#ifdef SPLIT_TRANSPORT_MIRROR
bool should_process_keypress(void)
{
    return true;
}
#endif


#ifdef OLED_ENABLE
void matrix_init_user(void) {
    iota_gfx_init();   // turns on the display
}
#endif


