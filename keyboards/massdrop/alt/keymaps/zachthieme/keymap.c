#include QMK_KEYBOARD_H
#include "zachthieme.h"

/*
 * [X] = LAYOUT(
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
 *    _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
 * ),
*/

// TODO: figure out why this binaryas bricks the keyboard
//  the internet seems to believe this is an issue due to QMK and ALT not using the same version of QMK
//  the binary size of my alt is 1400k which is way too small

#define LAYOUT_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33 \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,      KC_0,    KC_MINS,    KC_EQL,  KC_BSPC, KC_DEL,  \
    BB2,     K01,  K02,     K03,     K04,     K05,     K06,     K07,     K08,      K09,       K0A,     K0B,        KC_RBRC, KC_BSLS, KC_HOME, \
    K10,     K11,  K12,     K13,     K14,     K15,     K16,     K17,     K18,      K19,       K1A,     K1B,                 BB3,     KC_PGUP, \
    K20,     K21,  K22,     K23,     K24,     K25,     K26,     K27,     K28,      K29,       K2A,     K2B,                 KC_UP,   KC_PGDN, \
    KC_LCTL, K30,  K31,                 BB1,                                       K32,       K33,                 KC_LEFT, KC_DOWN, KC_RGHT  \
)

#define LAYOUT_base_wrapper(...)       LAYOUT_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_base_wrapper(
    _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
    _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
    _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
    ___________________META_L__________________, ___________________META_R__________________
    ),

  [_NUMBERS] = LAYOUT_base_wrapper(
    _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
    _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
    _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
    ___________________META_L__________________, ___________________META_R__________________
  ),

  [_NAVIGATION] = LAYOUT_base_wrapper(
    __________________BLANK_6__________________, ___________________NAV_R1__________________,
    ___________________NAV_L2__________________, ___________________NAV_R2__________________,
    __________________BLANK_6__________________, ___________________NAV_R3__________________,
    ___________________META_L__________________, ________________META_R_ALT_________________
  ),

  [_FLASH] = LAYOUT_base_wrapper(
    __________________BLANK_6__________________, __________________BLANK_6__________________,
    __________________BLANK_6__________________, __________________BLANK_6__________________,
    __________________BLANK_6__________________, ___________________FLASH___________________,
    ___________________META_L__________________, ___________________META_R__________________
  ),
  [_SCREEN] = LAYOUT_base_wrapper(
    __________________BLANK_6__________________, _________________SCREEN_R1_________________,
    __________________BLANK_6__________________, _________________SCREEN_R2_________________,
    __________________BLANK_6__________________, _________________SCREEN_R3_________________,
    ___________________META_L__________________, ___________________META_R__________________
  )
};
