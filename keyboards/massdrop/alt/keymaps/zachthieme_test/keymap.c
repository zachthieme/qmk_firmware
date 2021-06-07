#include QMK_KEYBOARD_H
#include "config.h"

/*
 * [X] = LAYOUT(
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
 *    _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
 * ),
*/

// TODO: figure out why this binary bricks the keyboard
//  the internet seems to believe this is an issue due to QMK and ALT not using the same version of QMK
//  the binary size of my alt is 1400k which is way too small

#define LAYOUT_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33 \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,      KC_0,    KC_MINS,    KC_EQL,  KC_BSPC, KC_DEL,  \
    TAB_NUM, K01,  K02,     K03,     K04,     K05,     K06,     K07,     K08,      K09,       K0A,     K0B,        KC_RBRC, KC_BSLS, KC_HOME, \
    K10,     K11,  K12,     K13,     K14,     K15,     K16,     K17,     K18,      K19,       K1A,     K1B,                 ENT_NUM, KC_PGUP, \
    K20,     K21,  K22,     K23,     K24,     K25,     K26,     K27,     K28,      K29,       K2A,     K2B,                 KC_UP,   KC_PGDN, \
    KC_LCTL, K30,  K31,                                SPC_NAV,                               K32,     K33,        KC_LEFT, KC_DOWN, KC_RGHT  \
)

#define LAYOUT_base_wrapper(...)       LAYOUT_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_base_wrapper(
    _______________QWERTY_MOD_L1_______________, _______________QWERTY_MOD_R1_______________,
    _______________QWERTY_MOD_L2_______________, _______________QWERTY_MOD_R2_______________,
    _______________QWERTY_MOD_L3_______________, _______________QWERTY_MOD_R3_______________,
    ___________________META_L__________________, ___________________META_R__________________
    ),

  [_NUMBERS] = LAYOUT_base_wrapper(
    _________________SYMBOL_L1_________________, _________________NUMBER_R1_________________,
    _________________SYMBOL_L2_________________, _________________NUMBER_R2_________________,
    _________________SYMBOL_L3_________________, _________________NUMBER_R3_________________,
    ___________________META_L__________________, _________________NUMBER_R4_________________
  ),

  [_NAVIGATION] = LAYOUT_base_wrapper(
    ___________________NAV_L1__________________, ___________________NAV_R1__________________,
    ___________________NAV_L2__________________, ___________________NAV_R2__________________,
    ___________________NAV_L3__________________, ___________________NAV_R3__________________,
    ___________________META_L__________________, ________________META_R_ALT_________________
  ),

  [_SCREEN] = LAYOUT_base_wrapper(
    __________________BLANK_6__________________, _________________SCREEN_R1_________________,
    _________________DELETE_L2_________________, _________________SCREEN_R2_________________,
    ___________________FLASH___________________, _________________SCREEN_R3_________________,
    ___________________META_L__________________, ___________________META_R__________________
  ),

};

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Added these to ensure I stopped typing paren+LC instead of a CL

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSPO:
            return 150;
        case KC_RSPC:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in zachthieme.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      #ifdef USE_BABBLEPASTE
         if( keycode > BABBLE_START && keycode < BABBLE_END_RANGE )  {
            if (record->event.pressed)  { // is there a case where this isn't desired?
              babblePaste ( keycode );
            } else{
              return true;
            }
          }
    #endif

    switch (keycode) {
        case KC_QWERTY ... KC_WORKMAN:
          if (record->event.pressed) {
            uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
            if (!mods) {
              set_single_persistent_default_layer(keycode - KC_QWERTY);
            }
          }
          break;

        case COL_SEL:
          if (record->event.pressed) {
            switch (get_babble_mode()) {
              case 0: //mac
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                break;

              case 1: // Windows
                register_code(KC_LALT);
                register_code(KC_LSFT);
                break;
              /* code */
            }
          } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_LSFT);
              unregister_code(KC_LALT);
          }
          break;

        case Z_KVM_1:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "1");
            set_babble_mode(BABL_WINDOWS_MODE);
          }
          break;

        case Z_KVM_2:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "2");
            set_babble_mode(BABL_MAC_MODE);
          }
          break;

        case Z_KVM_3:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "3");
            set_babble_mode(BABL_WINDOWS_MODE);
          }
          break;

        case Z_KVM_4:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "4");
            set_babble_mode(BABL_WINDOWS_MODE);
          }
          break;

        case FILE_MAIL:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("7")));
          }
          break;

        case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
                if (!record->event.pressed) {
    #ifndef MAKE_BOOTLOADER
                    uint8_t temp_mod = mod_config(get_mods());
                    uint8_t temp_osm = mod_config(get_oneshot_mods());
                    clear_mods();
                    clear_oneshot_mods();
    #endif
                    send_string_with_delay_P(PSTR("qmk"), TAP_CODE_DELAY);
    #ifndef MAKE_BOOTLOADER
                    if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
    #endif
                    {
                        send_string_with_delay_P(PSTR(" flash "), TAP_CODE_DELAY);
    #ifndef MAKE_BOOTLOADER
                    } else {
                        send_string_with_delay_P(PSTR(" compile "), TAP_CODE_DELAY);
                    } else {
                        send_string_with_delay_P(PSTR(" compile "), TAP_CODE_DELAY);
    #endif
                    }
                    send_string_with_delay_P(PSTR("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }
                break;

  }
  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}
