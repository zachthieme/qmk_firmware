#include QMK_KEYBOARD_H
#include "version.h"


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_gergo(
		KC_GESC,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_BSLS,
		LCTL_T(KC_DEL),KC_A,          KC_S,          KC_D,          KC_F,          KC_G, KC_GRV,                         KC_EQL,  KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       RCTL_T(KC_QUOT),
		KC_LSPO,       LCTL_T(KC_Z),  LALT_T(KC_X),  KC_C,          KC_V,          KC_B, KC_LBRC,  TG(2),      KC_PGDN,  KC_RBRC, KC_N,          KC_M,          KC_COMM,       RALT_T(KC_DOT),RCTL_T(KC_SLSH),KC_RSPC,
		                                                        KC_LGUI, KC_LEAD,   KC_SPC, LT(2,KC_TAB),       LT(2,KC_ENT), KC_SPC,   KC_MINS, KC_BSPC),
	[1] = LAYOUT_gergo(KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_gergo(KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_7, KC_8, KC_9, KC_PAST, KC_PPLS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, KC_UP, KC_PGUP, KC_NO, RESET, KC_0, KC_4, KC_5, KC_6, KC_PSLS, KC_PMNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_DOWN, KC_PGDN, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC),
	[3] = LAYOUT_gergo(
		KC_GESC,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_BSLS,
		LCTL_T(KC_DEL),KC_A,          KC_S,          KC_D,          KC_F,          KC_G, KC_GRV,                         KC_EQL,  KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       RCTL_T(KC_QUOT),
		KC_LSPO,       LCTL_T(KC_Z),  LALT_T(KC_X),  KC_C,          KC_V,          KC_B, KC_LBRC,  TG(2),      KC_PGDN,  KC_RBRC, KC_N,          KC_M,          KC_COMM,       RALT_T(KC_DOT),RCTL_T(KC_SLSH),KC_RSPC,
		                                                        KC_LGUI, KC_LEAD,   KC_SPC, LT(2,KC_TAB),       LT(2,KC_ENT), KC_SPC,   KC_MINS, KC_BSPC),
};
