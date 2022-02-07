# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina
DEFAULT_FOLDER = accent/glissando/rev1

VIA_ENABLE           = no
LTO_ENABLE           = yes
MAGIC_ENABLE         = no

BOOTMAGIC_ENABLE     = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE      = no       # Mouse keys
EXTRAKEY_ENABLE      = no       # Audio control and System control
CONSOLE_ENABLE       = no       # Console for debug
COMMAND_ENABLE       = no       # Commands for debug and configuration
NKRO_ENABLE          = yes      # USB Nkey Rollover
AUDIO_ENABLE         = no       # Audio output
SLEEP_LED_ENABLE     = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE     = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE      = no       # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE    = no
RGB_MATRIX_DRIVER    = WS2812
