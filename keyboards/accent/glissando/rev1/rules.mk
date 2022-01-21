SPLIT_KEYBOARD = yes

RGBLIGHT_ENABLE = yes
LED_ANIMATIONS = yes
# CUSTOM_MATRIX = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306


OPT_DEFS += -DOLED_FONT_H=\"common/glcdfont.c\"


ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += lib/mode_icon_reader.c
    SRC += lib/logo_reader.c
    SRC += lib/key_logger.c
    SRC += lib/layer_state_reader.c
    SRC += oled_display.c
endif

