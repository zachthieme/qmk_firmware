/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "zachthieme.h"
#include "version.h"
#include "tapdance.h"

/* 0: plain Qwerty without layer switching
 *         ,---------------. ,---------------. ,---------------.
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
 * |-----------------------------------------------------------| |-----------| |---------------| |-------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 * |-----------------------------------------------------------| `-----------' |---------------| |-------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
 * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
 * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
 * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
 * `-----------------------------------------------------------' `-----------' `---------------' `-------'
 */

// TODO: Finish _NAVIGATION
// TODO: finish wrapper work  

 // #define LAYOUT_iso_base( \
 //     K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
 //     K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
 //     K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
 //   ) \
 //   LAYOUT_iso_wrapper( \
 //     KC_NO,             KC_NO,        KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO, KC_NO,                                                                                \
 //     KC_ESC,            K3A,          K3B,       K3C,   K3D,   K3E,   K3F,   K40,   K41,    K42,      K43,       K44,   K45,             K46,   K47,   K48,      KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,        \
 //     KC_GRV,            K1E,          K1F,       K20,   K21,   K22,   K23,   K24,   K25,    K26,      K27,       K2D,   K2E,   KC_NO, K2A,      K49,   K4A,   K4B,      K53,   K54,   K55,   K56,      KC_NO, KC_NO, \
 //     KC_TAB,            K01,          K02,       K03,   K04,   K05,   K06,   K07,   K08,    K09,      K0A,       K2F,   K30,          K32,      K4C,   K4D,   K4E,      K5F,   K60,   K61,   K57,      KC_NO, KC_NO, \
 //     LCTL(KC_DELETE),   K11,          K12,       K13,   K14,   K15,   K16,   K17,   K18,    K19,      K1A,       K34,          K32,   K28,                              K5C,   K5D,   K5E,   KC_NO,    KC_NO, KC_NO, \
 //     KC_LSPO,           K21,          K22,       K23,   K24,   K25,   K26,   K27,   K28,    K29,      K2A,       K38,          KC_NO, KE5,             K52,             K59,   K5A,   K5B,   KC_NO,    KC_NO, KC_NO, \
 //     LT(2,KC_LCTL),     KC_LBRACKET,  KC_LALT,   KC_NO, KC_NO,      LT(_NAVIGATION,KC_SPC), KC_RALT,  KC_MINS,   K65,   KE4,      K50,   K51,   K4F,      K62,          K63,   K58,      KC_NO, KC_NO  \
 //
 //
 //
 //    KC_F13,           KC_F14,       KC_F15,       KC_F16,       KC_F17,   KC_F18, KC_F19, KC_F20, KC_F21, KC_F22,   KC_F23,  KC_F24, \
 //    KC_ESC,           KC_F1,        KC_F2,        KC_F3,        KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP, \
 //    KC_GRV,           KC_1,         KC_2,         KC_3,         KC_4,     KC_5,   KC_6,   KC_7,   KC_8,   KC_9,     KC_0,    KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN, \
 //    KC_TAB,           K01,          K02,          K03,          K04,      K05,    K06,    K07,    K08,    K09,      K0A,     KC_LBRC, KC_RBRC,KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_7,   KC_8,   KC_9,   KC_PPLS,    KC_MENU, KC_UNDO, \
 //    LCTL_T(KC_DELETE),K11,          K12,          K13,          K14,      K15,    K16,    K17,    K18,    K19,      K1A,     KC_QUOTE,KC_NUHS,LT(3,KC_ENT),                                    KC_4,   KC_5,   KC_6,   KC_PCMM,    KC_SLCT, KC_COPY, \
 //    KC_LSPO,KC_NUBS,  K21,          K22,          K23,          K24,      K25,    K26,    K27,    K28,    K29,      K2A,     KC_RO, KC_RSPC,              KC_UP,               KC_1,   KC_2,   KC_3,   KC_PEQL,    KC_EXEC, KC_PSTE, \
 //    LT(2,KC_LCTL),          KC_LBRACKET,  KC_LALT,      KC_MHEN, KC_HANJ,         LT(_NAVIGATION,KC_SPC),         KC_HAEN, KC_HENK, KC_KANA, KC_RALT, KC_MINUS, KC_APP,  KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT \
 //   )
 //
 // #define LAYOUT_iso_base_wrapper(...)       LAYOUT_iso_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_all_base_wrapper(
      _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
      _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
      _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________
      ),
    [_FLASH] = LAYOUT_all_wrapper(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,RESET,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,KC_MAKE,    ______,______
    ),

    [_NAVIGATION] = LAYOUT_all_wrapper(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  KC_BSPACE,  KC_DELETE, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______, ______,    ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
};
