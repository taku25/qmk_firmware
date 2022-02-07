#include "rev1.h"

bool is_mac_mode_flag = false;


#ifdef SSD1306OLED
#include "ssd1306.h"

// bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
// 	return process_record_user(keycode, record);
// }
#endif

    #if defined(RGB_MATRIX_ENABLE)

        led_config_t g_led_config = {
        {
            // Key Matrix to LED Index
            //Left
            { 5           , 4      , 3  , 2  , 1  , 0 }  ,
            {6           , 7      , 8  , 9  , 10 , 11 } ,
            {17          , 16     , 15 , 14 , 13 , 12 } ,
            {NO_LED      , NO_LED , 18 , 19 , 20 , 21 } ,
            // Right Half
            { 33         , 32     , 31 , 30 , 29 , 28 } ,
            { 34        , 35     , 36 , 37 , 38 , 39 } ,
            { 45         , 44     , 43 , 42 , 41 , 40 } ,
            { NO_LED      , NO_LED , 46 , 47 , 48 , 49 }
        },
        {
            // LED Index to Physical Position
            // Left
            { 0, 5 }, { 16, 5 }, { 32, 2 }, { 48, 0 }, { 64, 2 }, { 80, 3 },
            { 80, 17 }, { 64, 15 }, { 48, 13 }, { 32, 15 }, { 16, 18 }, { 0, 18 },
            { 0, 32 }, { 16, 32 }, { 32, 28 }, { 48, 27 }, { 64, 28 }, { 80, 30 },
            { 48, 40 }, { 32, 42 }, { 16, 45 }, { 0, 45 },
            { 80     , 58 } , { 40  , 50 } , { 8   , 43 } , { 8   , 5 }  , { 40  , 1 }  , { 72  , 3 }  ,
            // Right
            { 224    , 5 }  , { 208 , 5 }  , { 192 , 2 }  , { 176 , 0 }  , { 160 , 2 }  , { 144 , 3 }  ,
            { 144    , 18 } , { 160 , 18 } , { 176 , 15 } , { 192 , 13 } , { 208 , 15 } , { 244 , 17 } ,
            { 224    , 32 } , { 208 , 32 } , { 192 , 28 } , { 176 , 27 } , { 160 , 28 } , { 144 , 30 } ,
            { 144    , 45 } , { 160 , 45 } , { 176 , 42 } , { 192 , 40 } ,
            { 144    , 58 } , { 184 , 50 } , { 216 , 43 } , { 216 , 5 }  , { 184 , 1 }  , { 152 , 3 }
        },
        {
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW ,

            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  , LED_FLAG_KEYLIGHT  ,
            LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW , LED_FLAG_UNDERGLOW ,
        } };

#endif

bool is_mac_mode(void) {
    return is_mac_mode_flag;
}

void set_mac_mode_kb(bool macmode) {
    is_mac_mode_flag = macmode;
}
