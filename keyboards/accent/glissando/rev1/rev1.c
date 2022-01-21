#include "rev1.h"

// Each keymap.c should use is_keyboard_master() instead of 'is_master'.
// But keep 'is_master' for a while for backwards compatibility
//  for the old keymap.c.
uint8_t is_master = false;
bool is_mac_mode_flag = false;


#ifdef SSD1306OLED
#include "ssd1306.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	return process_record_user(keycode, record);
}
#endif

bool is_mac_mode(void) {
    return is_mac_mode_flag;
}

void set_mac_mode_kb(bool macmode) {
    is_mac_mode_flag = macmode;
}

void matrix_init_kb(void) {
    // Each keymap.c should use is_keyboard_master() instead of is_master.
    // But keep is_master for a while for backwards compatibility
    //  for the old keymap.c.
    is_master = is_keyboard_master();

    matrix_init_user();
}

void keyboard_post_init_kb(void) {
#if defined(DEBUG_MATRIX_SCAN_RATE)
    debug_enable = true;
#endif
    keyboard_post_init_user();
}

#if defined(SPLIT_KEYBOARD) && defined(SSD1306OLED)
void matrix_slave_scan_user(void) {
    matrix_scan_user();
}
#endif
