#include QMK_KEYBOARD_H
#include "zachthieme.h"
#include "tapdance.h"

#define LAYOUT_ergodox_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B \
  ) \
  LAYOUT_ergodox_wrapper( \
    KC_ESCAPE,  KC_1, KC_2, KC_3, KC_4, KC_5,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6, KC_7,  KC_8, KC_9, KC_0, KC_BSPACE, \
    K00,        K01,  K02,  K03,  K04,  K05,   KC_GRAVE,                                       KC_EQUAL,       K06,  K07,   K08,  K09,  K0A,  K0B, \
    K10,        K11,  K12,  K13,  K14,  K15,                                                                   K16,  K17,   K18,  K19,  K1A,  K1B, \
    K20,        K21,  K22,  K23,  K24,  K25,   KC_LBRACKET,                                    KC_RBRACKET,    K26,  K27,   K28,  K29,  K2A,  K2B, \
    KC_NO,  KC_HOME,   KC_END, KC_LGUI, LT(_FLASH,KC_LBRACKET),                                  KC_MINUS,       KC_BSPACE,      KC_NO,         KC_NO,         KC_NO, \
                                                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE, \
                                                              KC_PGUP,        KC_PGDOWN, \
                  LT(_NAVIGATION,KC_SPACE),       LT(_NUMBERS,KC_TAB),   KC_MINUS,       KC_LBRACKET,       LT(_NUMBERS,KC_ENTER), LT(_NAVIGATION,KC_SPACE) \
    )

#define LAYOUT_ergodox_base_wrapper(...)       LAYOUT_ergodox_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ergodox_base_wrapper(
    _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
    _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
    _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________
    ),
  [_NAVIGATION] = LAYOUT_ergodox_base_wrapper(
    __________________BLANK_6__________________, ___________________NAV_R1__________________,
    ___________________NAV_L2__________________, ___________________NAV_R2__________________,
    __________________BLANK_6__________________, ___________________NAV_R3__________________
  ),

  [_NUMBERS] = LAYOUT_ergodox_base_wrapper(
    __________________BLANK_6__________________, _________________NUMBER_R1_________________,
    __________________BLANK_6__________________, _________________NUMBER_R2_________________,
    __________________BLANK_6__________________, _________________NUMBER_R3_________________
  ),

  [_FLASH] = LAYOUT_ergodox_base_wrapper(
    __________________BLANK_6__________________, _________________NUMBER_R1_________________,
    __________________BLANK_6__________________, _________________NUMBER_R2_________________,
    __________________BLANK_6__________________, ___________________FLASH___________________
  )
};
