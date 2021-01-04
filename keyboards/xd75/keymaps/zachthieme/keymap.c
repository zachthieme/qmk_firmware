/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "zachthieme.h"

// TODO: Figure out what to do with the the extra keys

#define LAYOUT_ortho_5x15_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33 \
  ) \
  LAYOUT_ortho_5x15_wrapper( \
    KC_ESCAPE,  KC_1,      KC_2,    KC_3,     KC_4,    KC_5,   KC_NO,    KC_NO, KC_NO,    KC_6,    KC_7,     KC_8,      KC_9,    KC_0,   KC_BSPACE, \
    K00,        K01,       K02,     K03,      K04,     K05,    KC_GRAVE, KC_NO, KC_EQUAL, K06,     K07,      K08,       K09,     K0A,    K0B, \
    K10,        K11,       K12,     K13,      K14,     K15,    KC_NO,    KC_NO, KC_NO,    K16,     K17,      K18,       K19,     K1A,    K1B, \
    K20,        K21,       K22,     K23,      K24,     K25,    BB2,      KC_NO, BB3,      K26,     K27,      K28,       K29,     K2A,    K2B, \
    KC_NO,      KC_HOME,   KC_END,  K30,      K31,     BB1,    KC_NO,    KC_NO, KC_NO,    BB1,     KC_MINS,  K32,       K33,     KC_NO,  KC_NO \
    )

#define LAYOUT_ortho_5x15_base_wrapper(...)       LAYOUT_ortho_5x15_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
     /*
    [_QW] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_RGUI, KC_RCTL
    ),
    */
    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
     /*
    [_FN] = LAYOUT_ortho_5x15(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
    )
    */
    [_QWERTY] = LAYOUT_ortho_5x15_base_wrapper(
      _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
      _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
      _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
      ___________________META_L__________________, ___________________META_R__________________
      ),

    [_NUMBERS] = LAYOUT_ortho_5x15_base_wrapper(
      _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
      _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
      _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
      ___________________META_L__________________, ___________________META_R__________________
    ),

    [_NAVIGATION] = LAYOUT_ortho_5x15_base_wrapper(
      ___________________NAV_L1__________________, ___________________NAV_R1__________________,
      ___________________NAV_L2__________________, ___________________NAV_R2__________________,
      ___________________NAV_L3__________________, ___________________NAV_R3__________________,
      ___________________META_L__________________, ________________META_R_ALT_________________
    ),

    [_FLASH] = LAYOUT_ortho_5x15_base_wrapper(
      __________________BLANK_6__________________, _________________NUMBER_R1_________________,
      __________________BLANK_6__________________, _________________NUMBER_R2_________________,
      __________________BLANK_6__________________, ___________________FLASH___________________,
      ___________________META_L__________________, ___________________META_R__________________
    )
    // [_SCREEN] = LAYOUT_ortho_5x15_base_wrapper(
    //   __________________BLANK_6__________________, _________________SCREEN_R1_________________,
    //   __________________BLANK_6__________________, _________________SCREEN_R2_________________,
    //   __________________BLANK_6__________________, _________________SCREEN_R3_________________,
    //   ___________________META_L__________________, ___________________META_R__________________
    // ),

};
