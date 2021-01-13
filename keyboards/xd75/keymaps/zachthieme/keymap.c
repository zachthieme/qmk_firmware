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
    [_QWERTY] = LAYOUT_ortho_5x15_base_wrapper(
      _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
      _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
      _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
      ___________________META_L__________________, ___________________META_R__________________
      ),

    [_WORKMAN] = LAYOUT_ortho_5x15_base_wrapper(
      ______________WORKMAN_MOD_L1_______________, ______________WORKMAN_MOD_R1_______________,
      ______________WORKMAN_MOD_L2_______________, ______________WORKMAN_MOD_R2_______________,
      ______________WORKMAN_MOD_L3_______________, ______________WORKMAN_MOD_R3_______________,
      ___________________META_L__________________, ___________________META_R__________________
    ),

    [_NUMBERS] = LAYOUT_ortho_5x15_base_wrapper(
      _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
      _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
      _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
      ___________________META_L__________________, _________________NUMBER_R4_________________
    ),

    [_NAVIGATION] = LAYOUT_ortho_5x15_base_wrapper(
      ___________________NAV_L1__________________, ___________________NAV_R1__________________,
      ___________________NAV_L2__________________, ___________________NAV_R2__________________,
      ___________________NAV_L3__________________, ___________________NAV_R3__________________,
      ___________________META_L__________________, ________________META_R_ALT_________________
    ),

    [_SCREEN] = LAYOUT_ortho_5x15_base_wrapper(
      __________________BLANK_6__________________, _________________SCREEN_R1_________________,
      _________________DELETE_L2_________________, _________________SCREEN_R2_________________,
      ___________________FLASH___________________, _________________SCREEN_R3_________________,
      ___________________META_L__________________, ___________________META_R__________________
    )

};
