#pragma once

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...)       LAYOUT_ortho_5x15(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt \and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


// ZachThieme Additions
#define __________________BLANK_6__________________        _______, _______, _______, _______, _______, _______

#define _______________QWERTY_MOD_L1_______________        KC_ESC,            KC_Q,              KC_W,          KC_E,          KC_R,          KC_T
#define _______________QWERTY_MOD_L2_______________        LT(_SCREEN, KC_DELETE),    LGUI_T(KC_A),        LCTL_T(KC_S),    LALT_T(KC_D),    KC_F,          KC_G
#define _______________QWERTY_MOD_L3_______________        KC_LSPO,           KC_Z,  KC_X,          KC_C,          KC_V,          KC_B

#define _______________QWERTY_MOD_R1_______________        KC_Y,              KC_U,              KC_I,          KC_O,         KC_P,          KC_BSLS
#define _______________QWERTY_MOD_R2_______________        KC_H,              KC_J,              RALT_T(KC_K),  RCTL_T(KC_L), RGUI_T(KC_SCLN), LT(_SCREEN, KC_QUOT)
#define _______________QWERTY_MOD_R3_______________        KC_N,              KC_M,              KC_COMM,       KC_DOT,       KC_SLASH,      KC_RSPC

#define _________________NUMBER_R1_________________        KC_P0,    KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST
#define _________________NUMBER_R2_________________        KC_P0,    KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PSLS
#define _________________NUMBER_R3_________________        KC_PDOT,  KC_P1, KC_P2, KC_P3, KC_P0,   KC_PEQL

#define _________________SYMBOL_L1_________________        KC_TRNS,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE
#define _________________SYMBOL_L2_________________        KC_TRNS,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR
#define _________________SYMBOL_L3_________________        KC_TRNS,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR

#define ___________________NAV_R1__________________        BABL_BROWSER_ZOOM_IN, BABL_GO_LEFT_WORD, KC_UP,    BABL_GO_RIGHT_WORD, BABL_BROWSER_ZOOM_OUT, Z_KVM_1
#define ___________________NAV_R2__________________        BABL_GO_START_LINE,   KC_LEFT,           KC_DOWN,  KC_RIGHT,           BABL_GO_END_LINE,      Z_KVM_2
#define ___________________NAV_R3__________________        BABL_GO_START_DOC,    KC_PGUP,           KC_PGDN,  _______,            BABL_GO_END_DOC,       Z_KVM_3

#define ___________________NAV_L1__________________        _______,                BABL_CLOSE_APP,  BABL_BROWSER_CLOSE_TAB, BABL_BROWSER_URL_BAR, BABL_LEFTDENT, BABL_RIGHTDENT
#define ___________________NAV_L2__________________        BABL_DEL_TO_LINE_START, BABL_SELECT_ALL, BABL_APP_SAVE,          KC_BSPC,              KC_DEL,       BABL_DEL_TO_LINE_END
#define ___________________NAV_L3__________________        _______,                BABL_UNDO,       BABL_CUT,               BABL_COPY,            BABL_PASTE,   _______

#define ___________________FLASH___________________        _______, KC_MAKE, RESET, _______,  _______, _______
#define ___________________META_L__________________        KC_LGUI, KC_LBRACKET
#define ___________________META_R__________________        KC_MINS, KC_BSPC
#define ________________META_R_ALT_________________        KC_ESCAPE, FILE_MAIL

#define _________________DELETE_L2_________________        KC_TRNS, KC_TRNS, KC_TRNS, B_DLW, B_DRW, KC_TRNS

#define _________________SCREEN_R1_________________        KC_TRNS, KC_TRNS, WIN_MAX, WIN_RT,  KC_TRNS, Z_KVM_1
#define _________________SCREEN_R2_________________        WIN_L2,  WIN_L3,  WIN_M3,  WIN_R3,  WIN_R2,  Z_KVM_2
#define _________________SCREEN_R3_________________        KC_TRNS, WIN_L23, WIN_R23, WIN_RB,  KC_TRNS, Z_KVM_3

// clang-format on
