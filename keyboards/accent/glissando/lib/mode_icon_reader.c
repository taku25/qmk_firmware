#include "mode_icon_reader.h"


char mode_icon[12];

const char *read_mode_icon(bool is_mac) {
static const char icon[][2][3] = {{{0x95,0x96,0},{0xb5,0xb6,0}},
                                   {{0x97,0x98,0},{0xb7,0xb8,0}}};
  if (is_mac) {
    snprintf(mode_icon, sizeof(mode_icon), "%s\n%s", icon[0][0], icon[0][1]);
  } else {
    snprintf(mode_icon, sizeof(mode_icon), "%s\n%s", icon[1][0], icon[1][1]);
  }

  return mode_icon;
}
