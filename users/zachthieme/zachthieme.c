#include "zachthieme.h"

// Added these to ensure I stopped typing paren+LC instead of a CL

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSPO:
            return 200;
        case KC_RSPC:
            return 200;
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
    #endif
                    }
                    send_string_with_delay_P(PSTR("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }
                break;

  }
  return process_record_keymap(keycode, record);
}
