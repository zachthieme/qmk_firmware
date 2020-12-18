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

#define LAYOUT_gergo_base_wrapper(...)       LAYOUT_gergo_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_gergo(
    KC_GRAVE,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                                   KC_Y,          KC_U,          KC_I,          KC_O,            KC_P,              KC_BSLS,
    LCTL_T(KC_DEL),  LGUI_T(KC_A),  LCTL_T(KC_S),  LALT_T(KC_D),  KC_F,          KC_G,      KC_GRV,                           KC_EQL,    KC_H,          KC_J,          RALT_T(KC_K),  RCTL_T(KC_L),    RGUI_T(KC_SCLN),   RCTL_T(KC_QUOT),
    KC_LSPO,         TD(TD_FILE_MAIL),  KC_X,          KC_C,          KC_V,          KC_B,      KC_LBRC,  KC_PGUP,      KC_PGDN,  KC_RBRC,   KC_N,          KC_M,          KC_COMM,       KC_DOT,          KC_SLSH,           KC_RSPC,
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
};
