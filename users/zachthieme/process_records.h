#pragma once
// #include "zachthieme.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

// #ifdef USE_OSKEYS
// #define MAC_MODE 0
// #define MS_MODE 1
// #define LINUX_MODE 2
// #endif
//
/*
#define OS_KEY_MACRO \
  ENTRY(OS_COPY, "COPY", oskeys_copy) \
  ENTRY(OS_PASTE, "PASTE", oskeys_paste) \
  ENTRY(OS_CUT, "CUT", oskeys_cut) \
  ENTRY(OS_UNDO, "UNDO", oskeys_undo) \
*/

enum userspace_custom_keycodes {
VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
KC_QWERTY,                      // Sets default layer to QWERTY
KC_MALTRON,                     // Sets default layer to MALTRON
KC_MAKE,        // Run keyboard's customized make command
KC_RGB_T,       // Toggles RGB Layer Indication mode
KC_CCCV,        // Hold to copy, tap to paste
Z_KVM_1,        // KVM swithing command
Z_KVM_2,        // KVM swithing command
Z_KVM_3,        // KVM swithing command
Z_KVM_4,        // KVM swithing command
// #ifdef USE_OSKEYS
// #define ENTRY(a,b,c) a,
//   OS_KEY_MACRO
// #undef ENTRY
// #endif
NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};
//
// bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
//
// // #ifdef
// #define KC_MAC_UNDO LGUI(KC_Z)
// #define KC_MAC_CUT LGUI(KC_X)
// #define OS_MAC_COPY LGUI(KC_C)
// #define KC_MAC_PASTE LGUI(KC_V)
// #define KC_MAC_PREWORD LALT(KC_LEFT)
// #define KC_MAC_NEXWORD LALT(KC_RIGHT)
// #define KC_MAC_BEGLINE LGUI(KC_LEFT)
// #define KC_MAC_ENDLINE LGUI(KC_RIGHT)
// #define KC_MAC_HEAD LGUI(KC_UP)
// #define KC_MAC_TAIL LGUI(KC_DOWN)
// #define KC_MAC_DPWORD LALT(KC_BSPACE)
// #define KC_MAC_DNWORD LALT(KC_DELETE)
//
// #define KC_PC_UNDO LCTL(KC_Z)
// #define KC_PC_CUT LCTL(KC_X)
// #define OS_PC_COPY LCTL(KC_C)
// #define KC_PC_PASTE LCTL(KC_V)
// #define KC_PC_PREWORD LCTL(KC_LEFT)
// #define KC_PC_NEXWORD LCTL(KC_RIGHT)
// #define KC_PC_BEGLINE KC_HOME
// #define KC_PC_ENDLINE KC_END
//
// #define KC_PC_HEAD KC_HOME(KC_UP)
// #define KC_PC_TAIL KC_HOME(KC_DOWN)
// #define KC_PC_DPWORD LALT(KC_BSPACE)
// #define KC_PC_DNWORD LALT(KC_DELETE)
