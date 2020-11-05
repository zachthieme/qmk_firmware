#pragma once
#include "zachthieme.h"
// #include "babblePaste.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
KC_QWERTY,                      // Sets default layer to QWERTY
KC_MALTRON,                     // Sets default layer to MALTRON
KC_MAKE,        // Run keyboard's customized make command
KC_RGB_T,       // Toggles RGB Layer Indication mode
KC_SECRET_1,    // test1
KC_SECRET_2,    // test2
KC_SECRET_3,    // test3
KC_SECRET_4,    // test4
KC_SECRET_5,    // test5
KC_CCCV,        // Hold to copy, tap to paste
Z_KVM_1,
Z_KVM_2,
Z_KVM_3,
Z_KVM_4,
OS_COPY,
OS_PASTE,
OS_CUT,
OS_UNDO,
NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_MAC_PREWORD LALT(KC_LEFT)
#define KC_MAC_NEXWORD LALT(KC_RIGHT)
#define KC_MAC_BEGLINE LGUI(KC_LEFT)
#define KC_MAC_ENDLINE LGUI(KC_RIGHT)
#define KC_MAC_HEAD LGUI(KC_UP)
#define KC_MAC_TAIL LGUI(KC_DOWN)
#define KC_MAC_DPWORD LALT(KC_BSPACE)
#define KC_MAC_DNWORD LALT(KC_DELETE)

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define KC_PC_PREWORD LCTL(KC_LEFT)
#define KC_PC_NEXWORD LCTL(KC_RIGHT)
#define KC_PC_BEGLINE KC_HOME
#define KC_PC_ENDLINE KC_END

// #define KC_PC_HEAD KC_HOME(KC_UP)
// #define KC_PC_TAIL KC_HOME(KC_DOWN)
// #define KC_PC_DPWORD LALT(KC_BSPACE)
// #define KC_PC_DNWORD LALT(KC_DELETE)
