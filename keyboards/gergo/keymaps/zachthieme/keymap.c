#include QMK_KEYBOARD_H
#include "version.h"
#include "zachthieme.h"

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
   */


   /* Keymap template

      [SYMB] = LAYOUT_gergo_wrapper(
          _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                              _______, _______, _______, _______,       _______, _______, _______, _______
          ),

      */

/*
clang-format off
#define LAYOUT_gergo_base( \
  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) \
LAYOUT_gergo_wrapper( \
  KC_ESC,  K01,    K02,     K03,      K04,     K05,                                                K06,     K07,     K08,     K09,     K0A,    RESET,      \
  LCTL_T(KC_TAB), K11, K12, K13,      K14,     K15,     _______,                         _______,  K16,     K17,     K18,     K19,     K1A, KC_QUOT, \
  KC_LSPO, K21, K22, K23,      K24,     K25,     _______, _______,       _______, _______,  K26,     K27,     K28,     K29, K2A, KC_RSPC,      \
                                     KC_GRV,   LT(1,KC_SPC),  KC_NO, KC_NO,       KC_NO, KC_NO, KC_ENT, _______                            \
  )
*/

#define LAYOUT_gergo_base_wrapper(...)       LAYOUT_gergo_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_gergo(
    KC_GRAVE,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                                   KC_Y,          KC_U,          KC_I,          KC_O,            KC_P,              KC_BSLS,
    LCTL_T(KC_DEL),  LGUI_T(KC_A),  LCTL_T(KC_S),  LALT_T(KC_D),  KC_F,          KC_G,      KC_GRV,                           KC_EQL,    KC_H,          KC_J,          RALT_T(KC_K),  RCTL_T(KC_L),    RGUI_T(KC_SCLN),   RCTL_T(KC_QUOT),
    KC_LSPO,         KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_LBRC,  KC_PGUP,      KC_PGDN,  KC_RBRC,   KC_N,          KC_M,          KC_COMM,       KC_DOT,          KC_SLSH,           KC_RSPC,
                                                            KC_LGUI, LT(_FLASH,KC_LBRACKET),   LT(_NAVIGATION,KC_SPC), LT(_NUMBERS,KC_TAB),     LT(_NUMBERS,KC_ENT), LT(_NAVIGATION,KC_SPC),   KC_MINS, KC_BSPC),
  [_NAVIGATION] = LAYOUT_gergo(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_MAC_DPWORD, KC_MAC_DNWORD, KC_TRNS,                                                KC_TRNS,       KC_MAC_PREWORD,KC_UP,         KC_MAC_NEXWORD,  KC_TRNS,           Z_KVM_1,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,                          KC_TRNS,   KC_MAC_BEGLINE,KC_LEFT,       KC_DOWN,       KC_RIGHT,        KC_MAC_ENDLINE,    Z_KVM_2,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_HOME,       KC_END,       KC_TRNS,   KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,   KC_MAC_HEAD,   KC_PGUP,       KC_PGDN,       KC_MAC_TAIL,     KC_TRNS,           Z_KVM_3,
                                                                KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,          KC_TRNS,      KC_TRNS,        KC_ESCAPE, KC_TRNS),
  [_NUMBERS] = LAYOUT_gergo(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                                KC_0,          KC_7,          KC_8,          KC_9,            KC_PAST,           KC_PPLS,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_BSPACE,     KC_DELETE,     KC_TRNS,   KC_NO,                            KC_TRNS,   KC_0,          KC_4,          KC_5,          KC_6,            KC_PSLS,           KC_PMNS,
    KC_TRNS,         KC_TRNS,       KC_HOME,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_NO,    KC_TRNS,      KC_TRNS,  KC_NO,     KC_PDOT,       KC_1,          KC_2,          KC_3,            KC_TRNS,           KC_PEQL,
                                                                    KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,          KC_TRNS,      KC_TRNS,        KC_TRNS, KC_TRNS),
  [_FLASH] = LAYOUT_gergo(
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                                KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          RESET,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,                          KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          KC_TRNS,
    KC_TRNS,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,          KC_MAKE,
                                                                    KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),
   // [_QWERTY] = LAYOUT_gergo_base_wrapper(
   //     _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
   //     _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
   //     _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
   //     ),
   // [_COLEMAK] = LAYOUT_gergo_base_wrapper(
   //     _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
   //     _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
   //     _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
   // ),
   //
   // [_DVORAK] = LAYOUT_gergo_base_wrapper(
   //     _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
   //     _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
   //     _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
   // ),
   //
   // [_WORKMAN] = LAYOUT_gergo_base_wrapper(
   //     _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
   //     _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
   //     _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
   // ),
   //
   // [_NORMAN] = LAYOUT_gergo_base_wrapper(
   //     _________________NORMAN_L1_________________, _________________NORMAN_L1_________________,
   //     _________________NORMAN_L2_________________, _________________NORMAN_R2_________________,
   //     _________________NORMAN_L3_________________, _________________NORMAN_R3_________________
   // ),
   //
   // [_MALTRON] = LAYOUT_gergo_base_wrapper(
   //     _________________MALTRON_L1________________, _________________MALTRON_R1________________,
   //     _________________MALTRON_L2________________, _________________MALTRON_R2________________,
   //     _________________MALTRON_L3________________, _________________MALTRON_R3________________
   // ),
   //
   // [_EUCALYN] = LAYOUT_gergo_base_wrapper(
   //     _________________EUCALYN_L1________________, _________________EUCALYN_R1________________,
   //     _________________EUCALYN_L2________________, _________________EUCALYN_R2________________,
   //     _________________EUCALYN_L3________________, _________________EUCALYN_R3________________
   // ),
   //
   // [_CARPLAX] = LAYOUT_gergo_base_wrapper(
   //     _____________CARPLAX_QFMLWY_L1_____________, _____________CARPLAX_QFMLWY_R1_____________,
   //     _____________CARPLAX_QFMLWY_L2_____________, _____________CARPLAX_QFMLWY_R2_____________,
   //     _____________CARPLAX_QFMLWY_L3_____________, _____________CARPLAX_QFMLWY_R3_____________
   // ),
   //
   // [_MODS] = LAYOUT_gergo_wrapper(
   //     _______, ___________________BLANK___________________,                                           ___________________BLANK___________________, _______,
   //     _______, ___________________BLANK___________________, _______,                         _______, ___________________BLANK___________________, _______,
   //     KC_LSFT, ___________________BLANK___________________, _______, _______,       _______, _______, ___________________BLANK___________________, KC_RSFT,
   //                                         _______, _______, _______, _______,       _______, _______, _______, _______
   //     ),
   // [_LOWER] = LAYOUT_gergo_wrapper(
   //     KC_F12,  _________________LOWER_L1__________________,                                           _________________LOWER_R1__________________, KC_F11,
   //     _______, _________________LOWER_L2__________________, _______,                         _______, _________________LOWER_R2__________________, KC_PIPE,
   //     _______, _________________LOWER_L3__________________, _______, _______,       _______, _______, _________________LOWER_R3__________________, _______,
   //                                         _______, _______, _______, _______,       _______, _______, _______, _______
   //     ),
   //
   // [_RAISE] = LAYOUT_gergo_wrapper(
   //     _______, _________________RAISE_L1__________________,                                           _________________RAISE_R1__________________, _______,
   //     _______, _________________RAISE_L2__________________, _______,                         _______, _________________RAISE_R2__________________, KC_BSLS,
   //     _______, _________________RAISE_L3__________________, _______, _______,       _______, _______, _________________RAISE_R3__________________, _______,
   //                                         _______, _______, _______, _______,       _______, _______, _______, _______
   //     ),
   //
   // [_ADJUST] = LAYOUT_gergo_wrapper(
   //     KC_MAKE, _________________ADJUST_L1_________________,                                           _________________ADJUST_R1_________________, KC_RESET,
   //     VRSN,    _________________ADJUST_L2_________________, _______,                         KC_NUKE, _________________ADJUST_R2_________________, EEP_RST,
   //     _______, _________________ADJUST_L3_________________, _______, _______,       _______, _______, _________________ADJUST_R3_________________, TG_MODS,
   //                                         _______, _______, _______, _______,       _______, _______, _______, _______
   //     ),

// clang-format on

};
