/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
https://support.microsoft.com/en-gb/help/12445/windows-keyboard-shortcuts

Remember to check  https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h

*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef BABL_WINDOWS

bool babblePaste_win(uint16_t keycode) {
#        ifdef BABL_MOVE
    BABLM(BABL_GO_LEFT_WORD, IMCTL(X_LEFT));
    BABLM(BABL_GO_RIGHT_WORD, IMCTL(X_RIGHT));
    BABLM(BABL_GO_START_LINE, SS_TAP(X_HOME));
    BABLM(BABL_GO_END_LINE, SS_TAP(X_END));
    BABLM(BABL_GO_START_DOC, IMCTL(X_HOME));
    BABLM(BABL_GO_END_DOC, IMCTL(X_END));
    BABLM(BABL_DEL_LEFT_WORD, IMCTL(X_BSPACE));
    BABLM(BABL_DEL_RIGHT_WORD, IMCTL(X_DELETE));
    BABLM(BABL_DEL_TO_LINE_END, IMSFT(X_HOME) SS_TAP(X_DELETE));
    BABLM(BABL_DEL_TO_LINE_START, IMSFT(X_END) SS_TAP(X_DELETE));
    BABLM(BABL_MODE, "Windows ");
#        endif

#        ifdef BABL_OSKEYS
    BABLM(BABL_UNDO, SS_LCTRL("z"));
    BABLM(BABL_REDO, SS_LCTRL("y"));
    BABLM(BABL_CUT, SS_LCTRL("x"));
    BABLM(BABL_COPY, SS_LCTRL("c"));
    BABLM(BABL_PASTE, SS_LCTRL("v"));
    BABLM(BABL_SELECT_ALL, SS_LCTRL("a"));
    BABLM(BABL_WINDOW_NEW, IMCTL(X_N));
    BABLM(BABL_CLOSE_APP, IMALT(X_F4));
    BABLM(BABL_SCREENCAPTURE, OMSFT(SS_LGUI("s")));
    BABLM(BABL_SWITCH_KEYBOARD_LAYOUT, IMGUI(X_SPACE));
    BABLM(BABL_APP_SAVE, SS_LCTL("s"));
    BABLM(BABL_LEFTDENT, SS_LCTL("["));
    BABLM(BABL_RIGHTDENT, SS_LCTL("]"));
    BABLM(BABL_CANCEL, SS_LCTL("c"));
#        endif

#        ifdef BABL_BROWSER
    BABLM(BABL_BROWSER_NEW_TAB, SS_LCTRL("t"));
    BABLM(BABL_BROWSER_CLOSE_TAB, SS_LCTRL("w"));
    BABLM(BABL_BROWSER_REOPEN_LAST_TAB, OMSFT(IMCTL(X_T)));
    BABLM(BABL_BROWSER_NEXT_TAB, IMCTL(X_TAB));
    BABLM(BABL_BROWSER_PREV_TAB, OMSFT(IMCTL(X_TAB)));
    BABLM(BABL_BROWSER_URL_BAR, SS_LCTRL("l"));
    BABLM(BABL_BROWSER_FORWARD, IMALT(X_RIGHT));
    BABLM(BABL_BROWSER_BACK, OMSFT(IMALT(X_LEFT)));
    BABLM(BABL_BROWSER_FIND, SS_LCTRL("f"));
    BABLM(BABL_BROWSER_BOOKMARK, SS_LCTRL("d"));
#            ifdef BABL_BROWSER_MS
    BABLM(BABL_BROWSER_DEV_TOOLS, IMCTL(X_F12));  // EDGE
#            else
    BABLM(BABL_BROWSER_DEV_TOOLS, SS_LCTRL("t"));  // Chrome
    BABLM(BABL_BROWSER_VIEWSRC, SS_LCTRL("u"));    // Chrome or firefox
#            endif
    // chrome
    BABLM(BABL_BROWSER_RELOAD, IMCTL(X_F5));             // hard reload w/o cache
    BABLM(BABL_BROWSER_FULLSCREEN, SS_TAP(X_F11));       // command shift F
    BABLM(BABL_BROWSER_ZOOM_IN, OMSFT(IMCTL(X_EQUAL)));  // ctr+ +
    BABLM(BABL_BROWSER_ZOOM_OUT, IMCTL(X_MINUS));

#        endif

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* BABL_WINDOWS*/
#endif     /* babblepaste */
