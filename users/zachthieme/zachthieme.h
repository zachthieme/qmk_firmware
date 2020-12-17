
#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "version.h"
#include "eeprom.h"
// #include "wrappers.h"
#include "process_records.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _NAVIGATION,
    _NUMBERS,
    _FLASH,
    _COLEMAK,
    _DVORAK,
    _WORKMAN,
    _NORMAN,
    _MALTRON,
    _EUCALYN,
    _CARPLAX,
    _MODS, /* layer 8 */
    _GAMEPAD,
    _DIABLO,
    _MACROS,
    _MEDIA,
    _LOWER,
    _RAISE,
    _ADJUST,
};
