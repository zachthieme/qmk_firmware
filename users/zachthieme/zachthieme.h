#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "process_records.h"

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
