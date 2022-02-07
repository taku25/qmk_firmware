SPLIT_KEYBOARD    = yes

OLED_ENABLE       = yes
OLED_DRIVER       = SSD1306
VIA_ENABLE        = no

RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = yes


ifeq ($(strip $(OLED_ENABLE)), yes)
	OPT_DEFS += -DOLED_FONT_H=\"common/glcdfont.c\"

    SRC += lib/mode_icon_reader.c
    SRC += lib/logo_reader.c
    SRC += lib/key_logger.c
    SRC += lib/layer_state_reader.c
    SRC += lib/oled_display.c
endif

