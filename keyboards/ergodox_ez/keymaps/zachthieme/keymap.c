#include QMK_KEYBOARD_H
#include "zachthieme.h"

/* Ergodox EZ
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    0   |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |  10  |  11  |  12  |   13   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   14   |  15  |  16  |  17  |  18  |  19  |  20  |           |  21  |  22  |  23  |  24  |  25  |  26  |   27   |
 * |--------+------+------+------+------+------+------'           '------|------+------+------+------+------+--------|
 * |   28   |  29  |  30  |  31  |  32  |  33  |                         |  34  |  35  |  36  |  37  |  38  |   39   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |   40   |  41  |  42  |  43  |  44  |  45  |  46  |           |  47  |  48  |  49  |  50  |  51  |  52  |   53   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  54  |  55  |  56  |  57  |  58  |                                       |  59  |  60  |  61  |  62  |  63  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  64  |  65  |       |  66  |  67  |
 *                                 ,------+------|------|       |------|------+------.
 *                                 |      |      |  68  |       |  69  |      |      |
 *                                 |  70  |  71  |------|       |------|  74  |  75  |
 *                                 |      |      |  72  |       |  73  |      |      |
 *                                 `--------------------'       `--------------------'
 */

#define LAYOUT_ergodox_pretty_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33 \
  ) \
  LAYOUT_ergodox_pretty_wrapper( \
    KC_ESCAPE,  KC_1,      KC_2,    KC_3,     KC_4,    KC_5,  KC_TRANSPARENT,            KC_TRANSPARENT, KC_6,  KC_7,     KC_8,      KC_9,   KC_0,   KC_BSPACE, \
    K00,        K01,       K02,     K03,      K04,     K05,   KC_GRAVE,                  KC_EQUAL,       K06,   K07,      K08,       K09,    K0A,    K0B, \
    K10,        K11,       K12,     K13,      K14,     K15,                                              K16,   K17,      K18,       K19,    K1A,    K1B, \
    K20,        K21,       K22,     K23,      K24,     K25,   KC_LBRACKET,               KC_RBRACKET,    K26,   K27,      K28,       K29,    K2A,    K2B, \
    KC_NO,    KC_NO,   KC_END,  K30,      K31,                                                       K32,   K33,      KC_NO,     KC_NO,  KC_NO, \
                                                       MUTE,  KC_VOLD,                   KC_VOLU,        KC_MEDIA_PLAY_PAUSE, \
                                                              KC_PGUP,                   KC_PGDOWN, \
                                                   BB1, BB2,  KC_LBRACKET,               KC_MINUS, BB3, BB1 \
    )

#define LAYOUT_ergodox_pretty_base_wrapper(...)       LAYOUT_ergodox_pretty_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ergodox_pretty_base_wrapper(
    _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
    _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
    _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
    ___________________META_L__________________, ___________________META_R__________________
    ),

  [_NUMBERS] = LAYOUT_ergodox_pretty_base_wrapper(
    _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
    _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
    _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
    ___________________META_L__________________, ___________________META_R__________________
  ),

  [_NAVIGATION] = LAYOUT_ergodox_pretty_base_wrapper(
    ___________________NAV_L1__________________, ___________________NAV_R1__________________,
    ___________________NAV_L2__________________, ___________________NAV_R2__________________,
    ___________________NAV_L3__________________, ___________________NAV_R3__________________,
    ___________________META_L__________________, ________________META_R_ALT_________________
  ),

  [_SCREEN] = LAYOUT_ergodox_pretty_base_wrapper(
    __________________BLANK_6__________________, _________________SCREEN_R1_________________,
    _________________DELETE_L2_________________, _________________SCREEN_R2_________________,
    ___________________FLASH___________________, _________________SCREEN_R3_________________,
    ___________________META_L__________________, ___________________META_R__________________
  )
};
