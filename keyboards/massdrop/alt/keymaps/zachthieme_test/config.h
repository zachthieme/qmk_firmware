
#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


// ZachThieme Additions
#define __________________BLANK_6__________________        _______, _______, _______, _______, _______, _______


#define _______________QWERTY_MOD_L0_______________        KC_NO,  KC_1,      KC_2,    KC_3,     KC_4,    KC_5
#define _______________QWERTY_MOD_L1_______________        KC_GRAVE,            KC_Q,              KC_W,          KC_E,          KC_R,          KC_T
#define _______________QWERTY_MOD_L2_______________        _______,    LGUI_T(KC_A),        LCTL_T(KC_S),    LALT_T(KC_D),    SFT_T(KC_F),          KC_G
#define _______________QWERTY_MOD_L3_______________        KC_LSPO,           KC_Z,  KC_X,          KC_C,          KC_V,          KC_B

#define _______________QWERTY_MOD_R0_______________        KC_6,  KC_7,     KC_8,      KC_9,   KC_0,   KC_BSPC 
#define _______________QWERTY_MOD_R1_______________        KC_Y,              KC_U,              KC_I,          KC_O,         KC_P,          KC_BSLS
#define _______________QWERTY_MOD_R2_______________        KC_H,              SFT_T(KC_J),       RALT_T(KC_K),  RCTL_T(KC_L), RGUI_T(KC_SCLN), LT(_SCREEN, KC_QUOT)
#define _______________QWERTY_MOD_R3_______________        KC_N,              KC_M,              KC_COMM,       KC_DOT,       KC_SLASH,      KC_RSPC

#define ______________WORKMAN_MOD_L1_______________        KC_GRAVE,            KC_Q,              KC_D,          KC_R,          KC_W,          KC_B
#define ______________WORKMAN_MOD_L2_______________        LT(_SCREEN, KC_MINS),    LGUI_T(KC_A),        LCTL_T(KC_S),    LALT_T(KC_H),    KC_T,          KC_G
#define ______________WORKMAN_MOD_L3_______________        KC_LSPO,           KC_Z,  KC_X,          KC_M,          KC_C,          KC_V

#define ______________WORKMAN_MOD_R1_______________        KC_J,              KC_F,              KC_U,          KC_P,         KC_SCLN,          KC_BSLS
#define ______________WORKMAN_MOD_R2_______________        KC_Y,              KC_N,              RALT_T(KC_E),  RCTL_T(KC_O), RGUI_T(KC_I), LT(_SCREEN, KC_QUOT)
#define ______________WORKMAN_MOD_R3_______________        KC_K,              KC_L,              KC_COMM,       KC_DOT,       KC_SLASH,      KC_RSPC


#define _________________SYMBOL_L1_________________        KC_TRNS,  KC_AMPR, KC_AT,   KC_LPRN, KC_RPRN, KC_PIPE
#define _________________SYMBOL_L2_________________        KC_TRNS,  KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_ASTR
#define _________________SYMBOL_L3_________________        KC_TRNS,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_EXLM

#define _________________NUMBER_R0_________________        KC_6,  KC_7,     KC_8,      KC_9,   KC_0,   KC_BSPC 
#define _________________NUMBER_R1_________________        _______, KC_7, KC_8, KC_9, KC_PPLS, KC_PAST
#define _________________NUMBER_R2_________________        _______, KC_4, KC_5, KC_6, KC_PMNS, KC_PSLS
#define _________________NUMBER_R3_________________        _______, KC_1, KC_2, KC_3, KC_PEQL, KC_PEQL
#define _________________NUMBER_R4_________________        KC_0,    KC_DOT

#define ___________________NAV_L1__________________        _______, BABL_CLOSE_APP,  BABL_BROWSER_CLOSE_TAB, BABL_BROWSER_URL_BAR, B_BRLD,     B_NTAB
#define ___________________NAV_L2__________________        LT(_NAV2,KC_TRNS),BABL_SELECT_ALL, BABL_APP_SAVE,KC_BSPC,              KC_DEL,     BABL_LEFTDENT
#define ___________________NAV_L3__________________        _______, BABL_UNDO,       BABL_CUT,               BABL_COPY,            BABL_PASTE, BABL_RIGHTDENT

#define ___________________NAV_R0__________________        _______, _______, ______, ______, ______, ______ 
#define ___________________NAV_R1__________________        B_ZIN,  B_L1W,   KC_UP,         B_R1W,    B_ZOUT, _______
#define ___________________NAV_R2__________________        B_GSOL, KC_LEFT, KC_DOWN,       KC_RIGHT, B_GEOL, _______
#define ___________________NAV_R3__________________        B_WINN, KC_PGUP, BABL_CANCEL,   KC_PGDN,  B_BFND, _______ 

#define __________________NAV_2_R1_________________        _______, B_DLW,   _______,   B_DRW,    _______, _______
#define __________________NAV_2_R2_________________        B_DSOL,  _______, _______,   _______,  B_DEOL,  _______
#define __________________NAV_2_R3_________________        _______, _______, _______,   _______,  _______, _______

#define _________________DELETE_L2_________________        KC_TRNS, B_DSOL, KC_TRNS, B_DLW, B_DRW, B_DEOL

#define _________________SCREEN_R0_________________        _______, _______, _______, _______, _______,Z_KVM_1
#define _________________SCREEN_R1_________________        KC_TRNS, KC_TRNS, WIN_MAX, WIN_RT,  KC_TRNS, Z_KVM_2
#define _________________SCREEN_R2_________________        WIN_L2,  WIN_L3,  WIN_M3,  WIN_R3,  WIN_R2,  Z_KVM_3
#define _________________SCREEN_R3_________________        B_LMON, WIN_L23, WIN_R23, WIN_RB,   B_RMON, Z_KVM_4

#define ___________________FLASH___________________        _______, KC_MAKE, RESET, KC_QWERTY, KC_WORKMAN, _______
#define ___________________META_L__________________        B_RUN, LT(_SCREEN, KC_LBRACKET)
#define ___________________META_R__________________        LT(_SCREEN, KC_MINS), LT(_NUMBERS, KC_BSPC)
#define ________________META_R_ALT_________________        KC_ESCAPE, FILE_MAIL

#define ________________SCREEN_R_ALT_______________        WIN_SEL, _______
#define __________________SECRET___________________        KC_SECRET_1, KC_SECRET_2, _______, _______, _______, _______
#define ________________META_L_ALT_________________        B_CLIP, COL_SEL

#define _________________MOUSE_L2__________________        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______
#define _________________MOUSE_R1__________________        _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______
#define _________________MOUSE_R2__________________        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______

// clang-format on
