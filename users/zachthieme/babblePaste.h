/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.

Setting the bable_mode is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and jeebak & algernon's keymap
*/

#pragma once
#include "quantum.h"

#ifdef USE_BABBLEPASTE

void set_babble_mode(uint8_t id);
void babble_mode_increment(void);
void babble_mode_decrement(void);
void babble_led_user(void);

// manually re-order these if you want to set the order or default.
enum babble_modes {
#    ifdef BABL_MAC
    BABL_MAC_MODE,
#    endif
#    ifdef BABL_WINDOWS
    BABL_WINDOWS_MODE,
#    endif
#    ifdef BABL_LINUX
    BABL_LINUX_MODE,
#    endif
    BABL_MODEMAX
};

// void babble_led_user( uint8_t id)

/// Hacks to make it easier to create sendstring macros

//"outer" versions wrap text
#    define OMCTL(arg) SS_DOWN(X_LCTRL) arg SS_UP(X_LCTRL)
#    define OMGUI(arg) SS_DOWN(X_LGUI) arg SS_UP(X_LGUI)
#    define OMALT(arg) SS_DOWN(X_LALT) arg SS_UP(X_LALT)
#    define OMSFT(...) SS_DOWN(X_LSHIFT) __VA_ARGS__ SS_UP(X_LSHIFT)
//"inner" versions wrap a key tap
#    define IMCTL(arg) SS_DOWN(X_LCTRL) SS_TAP(arg) SS_UP(X_LCTRL)
#    define IMGUI(arg) SS_DOWN(X_LGUI) SS_TAP(arg) SS_UP(X_LGUI)
#    define IMALT(arg) SS_DOWN(X_LALT) SS_TAP(arg) SS_UP(X_LALT)
#    define IMSFT(arg) SS_DOWN(X_LSHIFT) SS_TAP(arg) SS_UP(X_LSHIFT)

#    define BABLM(ent, ...)           \
        if (ent == keycode) {         \
            SEND_STRING(__VA_ARGS__); \
            return true;              \
        }

// BabblePaste should be loaded first (header in userspace .h file, before all else)
// if not,we'll do our best.
#    if defined(NEW_SAFE_RANGE)
#        define BABBLE_START NEW_SAFE_RANGE
#    else
#        if defined(KEYMAP_SAFE_RANGE)
#            define BABBLE_START KEYMAP_SAFE_RANGE
#        else
#            define BABBLE_START SAFE_RANGE
#        endif
#    endif

enum babble_keycodes {
    FIRST = BABBLE_START,
#    ifdef BABL_MOVE
    BABL_GO_LEFT_WORD,
    BABL_GO_RIGHT_WORD,
    BABL_GO_START_LINE,
    BABL_GO_END_LINE,
    BABL_DEL_LEFT_WORD,
    BABL_DEL_RIGHT_WORD,
    BABL_DEL_TO_LINE_END,    // delete from cursor to end of line
    BABL_DEL_TO_LINE_START,  // delete from cursor to begining line
    BABL_MODE,               // print out string saying what mode we're in.
    BABL_LEFTDENT,           // decrease indent
    BABL_RIGHTDENT,          // increase indent
    BABL_CANCEL,             // always be ctrl+c no matter the OS
#    endif
#    ifdef BABL_OSKEYS
    BABL_UNDO,
    BABL_REDO,
    BABL_CUT,
    BABL_COPY,
    BABL_PASTE,
    BABL_SELECT_ALL,
    BABL_WINDOW_NEW,
    BABL_CLOSE_APP,
    BABL_SCREENCAPTURE,
    BABL_SWITCH_KEYBOARD_LAYOUT,
    BABL_APP_SAVE,
    BABL_LAUNCHER,
    BABL_CLIP,
#    endif
#    ifdef BABL_BROWSER
    BABL_BROWSER_NEW_TAB,
    BABL_BROWSER_CLOSE_TAB,
    BABL_BROWSER_URL_BAR,
    BABL_BROWSER_RELOAD,
    BABL_BROWSER_ZOOM_IN,
    BABL_BROWSER_ZOOM_OUT,
    BABL_BROWSER_FIND,
#    endif

// Macros for mode switching
#    ifdef BABL_WINDOWS
    BABL_DO_WINDOWS,
#    endif
#    ifdef BABL_MAC
    BABL_DO_MAC,
#    endif
#    ifdef BABL_LINUX
    BABL_DO_LINUX,
#    endif
    BABBLE_END_RANGE
};

// primary function.
bool babblePaste(uint16_t keycode);

/****************************************************/
/* All per-os includes and short mode switch macros*/
#    ifdef BABL_WINDOWS
#        define B_WIN BABL_DO_WINDOWS
bool babblePaste_win(uint16_t keycode);
#    endif
#    ifdef BABL_MAC
#        define B_MAC BABL_DO_MAC
bool babblePaste_mac(uint16_t keycode);
#    endif
#    ifdef BABL_LINUX
#        define B_LINUX BABL_DO_LINUX
bool babblePaste_linux(uint16_t keycode);
#    endif

#    define BABL_INC babble_mode_increment();
#    define BABL_DEC babble_mode_decrement();

/****************************************************
**    All keyboard macros for Babble Actions
*****************************************************/

#    ifdef BABL_MOVE
#        define B_L1W BABL_GO_LEFT_WORD
#        define B_R1W BABL_GO_RIGHT_WORD
#        define B_GSOL BABL_GO_START_LINE
#        define B_GEOL BABL_GO_END_LINE
#        define B_DLW BABL_DEL_LEFT_WORD
#        define B_DRW BABL_DEL_RIGHT_WORD
#        define B_DEOL BABL_DEL_TO_LINE_END    // delete from cursor to end of line
#        define B_DSOL BABL_DEL_TO_LINE_START  // delete from cursor to begining line
#        define B_MODE BABL_MODE               // type out name of current mode.
#    endif

#    ifdef BABL_OSKEYS
#        define B_UNDO BABL_UNDO
#        define B_REDO BABL_REDO
#        define B_CUT BABL_CUT
#        define B_COPY BABL_COPY
#        define B_PASTE BABL_PASTE
#        define B_SELALL BABL_SELECT_ALL
#        define B_SELA BABL_SELECT_ALL
#        define B_WINN BABL_WINDOW_NEW
#        define B_CAPP BABL_CLOSE_APP
#        define B_SCAP BABL_SCREENCAPTURE
#        define B_KEYB BABL_SWITCH_KEYBOARD_LAYOUT
#        define B_RUN BABL_LAUNCHER
#        define B_CLIP BABL_CLIP
#    endif

#    ifdef BABL_BROWSER
#        define B_NTAB BABL_BROWSER_NEW_TAB
#        define B_CTAB BABL_BROWSER_CLOSE_TAB
#        define B_NURL BABL_BROWSER_URL_BAR
#        define B_BRLD BABL_BROWSER_RELOAD
#        define B_ZIN BABL_BROWSER_ZOOM_IN
#        define B_ZOUT BABL_BROWSER_ZOOM_OUT
#        define B_BFND BABL_BROWSER_FIND
#    endif

#endif
