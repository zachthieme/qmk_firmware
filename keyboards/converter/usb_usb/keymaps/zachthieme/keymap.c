#include QMK_KEYBOARD_H
#include "zachthieme.h"


// For some reason this layout is reversing the order of the replacement arrays.
// i've reversed 31/30 and 33/32 in the layout to accomodate.

#define LAYOUT_all_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33 \
  ) \
  LAYOUT_all( \
    KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, \
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_JYEN, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN, \
    TAB_NUM, K01,     K02,     K03,     K04,     K05,    K06,    K07,    K08,     K09,     K0A,     K0B,     KC_RBRC,          KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO, \
    K10,     K11,     K12,     K13,     K14,     K15,    K16,    K17,    K18,     K19,     K1A,     K1B,     KC_NUHS, ENT_NUM,                                            KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY, \
    K20,     KC_NUBS, K21,     K22,     K23,     K24,    K25,    K26,    K27,     K28,     K29,     K2A,     KC_RO,   K2B,                           KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE, \
    KC_LCTL, K31,     K30, KC_MHEN, KC_HANJ,         SPC_NAV,         KC_HAEN, KC_HENK, KC_KANA, K33, K32, KC_APP,  KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT \
  )

#define LAYOUT_all_base_wrapper(...)       LAYOUT_all_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_QWERTY] = LAYOUT_all_base_wrapper(
       _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
       _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
       _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
       ___________________META_L__________________, ___________________META_R__________________
     ),

     // [_WORKMAN] = LAYOUT_all_base_wrapper(
     //   ______________WORKMAN_MOD_L1_______________, ______________WORKMAN_MOD_R1_______________,
     //   ______________WORKMAN_MOD_L2_______________, ______________WORKMAN_MOD_R2_______________,
     //   ______________WORKMAN_MOD_L3_______________, ______________WORKMAN_MOD_R3_______________,
     //   ___________________META_L__________________, ___________________META_R__________________
     // ),

     [_NAVIGATION] = LAYOUT_all_base_wrapper(
       ___________________NAV_L1__________________, ___________________NAV_R1__________________,
       ___________________NAV_L2__________________, ___________________NAV_R2__________________,
       ___________________NAV_L3__________________, ___________________NAV_R3__________________,
       ________________META_L_ALT_________________, ________________META_R_ALT_________________
     ),

     [_NUMBERS] = LAYOUT_all_base_wrapper(
       _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
       _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
       _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
       ___________________META_L__________________, _________________NUMBER_R4_________________
     ),

     [_SCREEN] = LAYOUT_all_base_wrapper(
       ___________________FLASH___________________, _________________SCREEN_R1_________________,
       _________________DELETE_L2_________________, _________________SCREEN_R2_________________,
       __________________SECRET___________________, _________________SCREEN_R3_________________,
       ___________________META_L__________________, ________________SCREEN_R_ALT_______________
     ),

     [_MOUSE] = LAYOUT_all_base_wrapper(
       ___________________FLASH___________________, _________________SCREEN_R1_________________,
       _________________DELETE_L2_________________, _________________SCREEN_R2_________________,
       __________________BLANK_6__________________, _________________SCREEN_R3_________________,
       ___________________META_L__________________, ___________________META_R__________________
     )
};
