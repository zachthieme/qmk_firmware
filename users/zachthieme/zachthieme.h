#pragma once
#include QMK_KEYBOARD_H
#include "zachthieme.h"
#include "custom_keycodes.h"
#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _NAVIGATION,
    _NUMBERS,
    _FLASH,
    _MALTRON,
    _MACROS,
    _SCREEN,
    _NAV_WIN
};

// MACRO's for moving cursor around on the MAC
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define OS_MAC_COPY LGUI(KC_C)
#define OS_MAC_PASTE LGUI(KC_V)
#define KC_MAC_PREWORD LALT(KC_LEFT)
#define KC_MAC_NEXWORD LALT(KC_RIGHT)
#define KC_MAC_BEGLINE LGUI(KC_LEFT)
#define KC_MAC_ENDLINE LGUI(KC_RIGHT)
#define KC_MAC_HEAD LGUI(KC_UP)
#define KC_MAC_TAIL LGUI(KC_DOWN)
#define KC_MAC_DPWORD LALT(KC_BSPACE)
#define KC_MAC_DNWORD LALT(KC_DELETE)

// MACRO's for moving cursor around on the PC
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define OS_PC_COPY LCTL(KC_C)
#define OS_PC_PASTE LCTL(KC_V)
#define KC_PC_PREWORD LCTL(KC_LEFT)
#define KC_PC_NEXWORD LCTL(KC_RIGHT)
#define KC_PC_BEGLINE KC_HOME
#define KC_PC_ENDLINE KC_END
#define KC_PC_HEAD KC_HOME(KC_UP)
#define KC_PC_TAIL KC_HOME(KC_DOWN)
#define KC_PC_DPWORD LALT(KC_BSPACE)
#define KC_PC_DNWORD LALT(KC_DELETE)

// MACRO's for Davinci
#define DAV_ZOOM_IN LCTL(KC_PLUS)
#define DAV_ZOOM_OUT LCTL(KC_MINUS)
#define DAV_FF LSFT(KC_2)
// #define DAV_CUT_ALL,
// #define DAV_RMV_GAP,
// #define DAV_MEDIA,
// #define DAV_CUT,
// #define DAV_EDIT,
// #define DAV_NORM_AUDIO,
// #define DAV_SEL_ALL,
// #define DAV_SEL_END,
#define DAV_SNAP KC_N

// MACRO's to clean up keymaps
#define MUTE KC_AUDIO_MUTE
#define BB1 LT(_NAVIGATION,KC_SPACE)
#define BB2 LT(_NUMBERS,KC_TAB)
#define BB3 LT(_NUMBERS,KC_ENTER)
#define ZT_FLASH LT(_FLASH,KC_LBRACKET)

// MACRO's for moving windows on Mac
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
