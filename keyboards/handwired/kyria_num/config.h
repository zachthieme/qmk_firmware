#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0114
#define DEVICE_VER      0x0001
#define MANUFACTURER    Zach Thieme
#define PRODUCT         Kyria Number

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/* key matrix pins */
// #define MATRIX_ROW_PINS { A4, A5, A6, A7, A8 }
// #define MATRIX_COL_PINS { A2, A1, A0, B8, B13, B14, B15, B9, B0, B1, B2, B3, B4, B5, B6, B7 }

#define MATRIX_ROW_PINS { B10, B11, B12, A14, A13 }
#define MATRIX_COL_PINS { A2, A1, A0, B8, B13, B14, B15, B9, B0, B1, B2, B3, B4, B5, B6, B7 }

#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif
