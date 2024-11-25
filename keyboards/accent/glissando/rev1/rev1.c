#include "rev1.h"


    #if defined(RGB_MATRIX_ENABLE)

        led_config_t g_led_config = {
        {
            // Key Matrix to LED Index
            //Left
            {5          , 4      , 3  , 2  , 1  , 0}  ,
            {6          , 7      , 8  , 9  , 10 , 11} ,
            {17         , 16     , 15 , 14 , 13 , 12} ,
            {NO_LED     , NO_LED , 18 , 19 , 20 , 21} ,
            //RightHalf
            {33         , 32     , 31 , 30 , 29 , 28} ,
            {34         , 35     , 36 , 37 , 38 , 39} ,
            {45         , 44     , 43 , 42 , 41 , 40} ,
            {NO_LED     , NO_LED , 46 , 47 , 48 , 49}
        },
        {
            // LED Index to Physical Position
            // Left
            {96     , 15} , {80 , 14} , {64 , 12} , {48  , 13} , {32 , 15} , {16 , 16} ,
            {16     , 24} , {32 , 23} , {48 , 21} , {64  , 20} , {80 , 22} , {96 , 25} ,
            {96     , 31} , {80 , 30} , {64 , 28} , {48  , 29} , {32 , 31} , {16 , 32} ,
            {64     , 40} , {80 , 39} , {96 , 40} , {112 , 45} ,
            {96     , 35} , {64 , 32} , {32 , 26} , {32  , 18} , {64 , 16} , {96 , 19} ,
            //Right
            {144    , 15} , {160 , 14} , {176 , 12} , {192 , 13} , {208 , 15} , {224 , 16} ,
            {224    , 24} , {208 , 23} , {192 , 21} , {176 , 20} , {160 , 22} , {144 , 24} ,
            {144    , 31} , {160 , 30} , {176 , 28} , {192 , 29} , {208 , 31} , {224 , 32} ,
            {176    , 40} , {160 , 39} , {144 , 40} , {128 , 45} ,
            {144    , 35} , {176 , 32} , {208 , 26} , {208  , 18} , {176 , 16} , {144 , 19} ,
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



