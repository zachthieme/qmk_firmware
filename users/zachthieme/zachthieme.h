#pragma once
#include QMK_KEYBOARD_H
// #include "custom_keycodes.h"
#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

#ifdef USE_BABBLEPASTE
#include "babblePaste.h"
#endif

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _NAVIGATION,
    _NUMBERS,
    _SCREEN
};

#if defined(BABBLE_END_RANGE)
      #define USER_START BABBLE_END_RANGE
#else
    #if defined(KEYMAP_SAFE_RANGE)
        #define USER_START KEYMAP_SAFE_RANGE
    #else
        #define USER_START SAFE_RANGE
    #endif
#endif

enum userspace_custom_keycodes {
VRSN = BABBLE_END_RANGE,  // Prints QMK Firmware and board info
KC_MAKE,        // Run keyboard's customized make command
KC_CCCV,        // Hold to copy, tap to paste
Z_KVM_1,        // KVM swithing command
Z_KVM_2,        // KVM swithing command
Z_KVM_3,        // KVM swithing command
Z_KVM_4,        // KVM swithing command
FILE_MAIL,
NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

// MACRO's for Davinci'
// TODO: migrate to BabblePaste
// #define DAV_ZOOM_IN LCTL(KC_PLUS)
// #define DAV_ZOOM_OUT LCTL(KC_MINUS)
// #define DAV_FF LSFT(KC_2)
// #define DAV_CUT_ALL,
// #define DAV_RMV_GAP,
// #define DAV_MEDIA,
// #define DAV_CUT,
// #define DAV_EDIT,
// #define DAV_NORM_AUDIO,
// #define DAV_SEL_ALL,
// #define DAV_SEL_END,
// #define DAV_SNAP KC_N

// // MACRO's to clean up keymaps
#define MUTE KC_AUDIO_MUTE
#define BB1 LT(_NAVIGATION,KC_SPACE)
#define BB2 LT(_NUMBERS,KC_TAB)
#define BB3 LT(_NUMBERS,KC_ENTER)

// // MACRO's for moving windows on Mac
#define WIN_L23 LCTL(LALT(KC_P1))
#define WIN_R23 LCTL(LALT(KC_P2))
#define WIN_RB  LCTL(LALT(KC_P3))
#define WIN_RT  LCTL(LALT(KC_P9))
#define WIN_L3  LCTL(LALT(KC_P4))
#define WIN_M3  LCTL(LALT(KC_P5))
#define WIN_R3  LCTL(LALT(KC_P6))
#define WIN_L2  LCTL(LALT(KC_LEFT))
#define WIN_R2  LCTL(LALT(KC_RIGHT))
#define WIN_MAX LCTL(LALT(KC_ENTER))
