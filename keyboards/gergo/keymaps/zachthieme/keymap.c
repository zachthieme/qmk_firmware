#include QMK_KEYBOARD_H
#include "version.h"
#include "zachthieme.h"
#include "tapdance.h"
/*
 * ,-------------------------------------------.                  ,-------------------------------------------.
 * |    0   |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |  10  |   11   |
 * |--------+------+------+------+------+------+------.    ,------+------+------+------+------+------+--------|
 * |   12   |  13  |  14  |  15  |  16  |  17  |  18  |    |  19  |  20  |  21  |  22  |  23  |  24  |   25   |
 * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
 * |   26   |  27  |  28  |  29  |  30  |  31  |  32  |    |  35  |  36  |  37  |  38  |  39  |  40  |   41   |
 * `-----------------------------+--------------------'    `--------------------------------------------------'
 *                        |  42  |  43  |                                |  48  |  49  |
 *                        `-------------'                                `-------------'
 *                                             ,------.    ,------.
 *                                             |  33  |    |  34  |
 *                                      ,------+------|    |------+------.
 *                                      |      |      |    |      |      |
 *                                      |  44  |  45  |    |  46  |  47  |
 *                                      |      |      |    |      |      |
 *                                      `-------------'    '-------------'
 * Keymap template

    [SYMB] = LAYOUT_gergo_wrapper(
        _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______,       _______, _______, _______, _______
    ),

*/

#define LAYOUT_gergo_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_gergo_wrapper( \
    KC_ESC,         K01,              K02,     K03,      K04,     K05,                                                    K06,     K07,     K08,     K09,     K0A,          KC_BSLS,      \
    LCTL_T(KC_DEL), K11,              K12,     K13,      K14,     K15,     KC_GRAVE,                            KC_EQL,   K16,     K17,     K18,     K19,     K1A,          RCTL_T(KC_QUOT), \
    KC_LSPO,        TD(TD_FILE_MAIL), K22,     K23,      K24,     K25,     KC_LBRC,   KC_PGUP,       KC_PGDN,   KC_RBRC,  K26,     K27,     K28,     K29,     RCTL_T(K2A),  KC_RSPC,      \
                  KC_LGUI, LT(_FLASH,KC_LBRACKET), LT(_NAVIGATION,KC_SPC), LT(_NUMBERS,KC_TAB),      LT(_NUMBERS,KC_ENT), LT(_NAVIGATION,KC_SPC), KC_MINS, KC_BSPC                          \
    )

#define LAYOUT_gergo_base_wrapper(...)       LAYOUT_gergo_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_gergo_base_wrapper(
        _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
        _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
        _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________
        ),
  [_NAVIGATION] = LAYOUT_gergo_wrapper(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_MAC_DPWORD, KC_MAC_DNWORD, KC_TRNS,                                                KC_TRNS,       KC_MAC_PREWORD,KC_UP,         KC_MAC_NEXWORD,  KC_TRNS,           Z_KVM_1,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,                          KC_TRNS,   KC_MAC_BEGLINE,KC_LEFT,       KC_DOWN,       KC_RIGHT,        KC_MAC_ENDLINE,    Z_KVM_2,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_HOME,       KC_END,       KC_TRNS,   KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,   KC_MAC_HEAD,   KC_PGUP,       KC_PGDN,       KC_MAC_TAIL,     KC_TRNS,           Z_KVM_3,
                                                                KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,          KC_TRNS,      KC_TRNS,        KC_ESCAPE, KC_TRNS),
  [_NUMBERS] = LAYOUT_gergo_wrapper(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                                KC_0,          KC_7,          KC_8,          KC_9,            KC_PAST,           KC_PPLS,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_BSPACE,     KC_DELETE,     KC_TRNS,   KC_NO,                            KC_TRNS,   KC_0,          KC_4,          KC_5,          KC_6,            KC_PSLS,           KC_PMNS,
    KC_TRNS,         KC_TRNS,       KC_HOME,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_NO,    KC_TRNS,      KC_TRNS,  KC_NO,     KC_PDOT,       KC_1,          KC_2,          KC_3,            KC_TRNS,           KC_PEQL,
                                                                    KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,          KC_TRNS,      KC_TRNS,        KC_TRNS, KC_TRNS),
  [_FLASH] = LAYOUT_gergo_wrapper(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                                KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          RESET,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,                          KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          KC_TRNS,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          KC_MAKE,
                                                                    KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),
};
