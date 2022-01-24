SPLIT_KEYBOARD = yes

RGBLIGHT_ENABLE = yes







OLED_ENABLE = yes

VIA_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no




ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER = SSD1306
	OPT_DEFS += -DOLED_FONT_H=\"common/glcdfont.c\"

    SRC += lib/mode_icon_reader.c
    SRC += lib/logo_reader.c
    SRC += lib/key_logger.c
    SRC += lib/layer_state_reader.c
    SRC += oled_display.c
endif

