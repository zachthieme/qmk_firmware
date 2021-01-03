#include "zachthieme.h"

uint16_t copy_paste_timer;
uint8_t current_os = 1;

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in zachthieme.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

        case Z_KVM_1:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "1");
            current_os = 1;
          }
          break;
        case Z_KVM_2:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "2");
            current_os = 2;
          }
          break;
        case Z_KVM_3:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "3");
            current_os = 1;
          }
          break;

        case ACT_OS:
          if (record->event.pressed) {
            switch (current_os) {
              case 2:
                 SEND_STRING("mac");
                 break;
              case 1:
                 SEND_STRING("win");
                 break;
            }
          }
          break;


      case OS_IN: //choose correct copy macro per OS
           if (record->event.pressed) {
          switch (current_os) {
            case 2:
               OS_MAC_IN;
               break;
            case 1:
               OS_PC_IN;
               break;
          }
        }
        break;

        case OS_OUT: //choose correct copy macro per OS
             if (record->event.pressed) {
            switch (current_os) {
              case 2:
                 OS_MAC_OUT;
                 break;
              case 1:
                 OS_PC_OUT;
                 break;
            }
          }
          break;


        case OS_COPY: //choose correct copy macro per OS
         if (record->event.pressed) {
           switch (current_os) {
             case 2:
                OS_MAC_COPY;
                break;
             case 1:
                OS_PC_COPY;
                break;
           }
         }
         break;

       case OS_PASTE: //choose correct copy macro per OS
        if (record->event.pressed) {
           switch (current_os) {
            case 2:
               OS_MAC_PASTE;
               break;
            case 1:
               OS_PC_PASTE;
               break;
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
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }
                break;

  }
  return process_record_keymap(keycode, record);
}
