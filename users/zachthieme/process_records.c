#include "zachthieme.h"
#include "babblePaste.c"

uint16_t copy_paste_timer;

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in zachthieme.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case VRSN:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            break;
        case  Z_KVM_1:
        // case Z_KVM_1:
            if (record->event.pressed) {
              layer_off(1);
              // switch_babble_mode(0);
              babble_mode = 0;
              tap_code(KC_LCTL);
              tap_code(KC_LCTL);
              tap_code(KC_1);
                // SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) SS_TAP(X_F1));
            }
            break;
        case Z_KVM_2:
            if (record->event.pressed) {
              layer_on(1);
              // switch_babble_mode(1);
              babble_mode = 1;
              tap_code(KC_LCTL);
              tap_code(KC_LCTL);
              tap_code(KC_2);
                // SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) SS_TAP(X_F2));
            }
            break;
        case Z_KVM_3:
            if (record->event.pressed) {
              layer_off(1);
              // switch_babble_mode(0);
              babble_mode = 1;
              tap_code(KC_LCTL);
              tap_code(KC_LCTL);
              tap_code(KC_3);
                // SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) SS_TAP(X_F3));
            }
            break;
        case Z_KVM_4:
            if (record->event.pressed) {
              layer_off(1);
              // switch_babble_mode(0);
              babble_mode = 1;
              tap_code(KC_LCTL);
              tap_code(KC_LCTL);
              tap_code(KC_4);
                // SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) SS_TAP(X_F4));
            }
            break;
        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    register_code(KC_LGUI);
                    tap_code(KC_C);
                    unregister_code(KC_LGUI);
                } else {  // Tap, paste
                    register_code(KC_LGUI);
                    tap_code(KC_V);
                    unregister_code(KC_LGUI);
                }
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
    #ifdef RGB_MATRIX_SPLIT_RIGHT
                    send_string_with_delay_P(PSTR(" RGB_MATRIX_SPLIT_RIGHT=yes"), TAP_CODE_DELAY);
    #    ifndef OLED_DRIVER_ENABLE
                    send_string_with_delay_P(PSTR(" OLED_DRIVER_ENABLE=no"), TAP_CODE_DELAY);
    #    endif
    #endif
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }

                break;

  }
  return process_record_keymap(keycode, record) &&
        process_record_secrets(keycode, record);
}
