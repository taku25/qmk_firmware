#pragma once
#include <stdio.h>

#include QMK_KEYBOARD_H
#include "bootloader.h"

void set_keylog(uint16_t keycode, keyrecord_t *record);

const char *read_keylog(void);
const char *read_keylogs(void);
