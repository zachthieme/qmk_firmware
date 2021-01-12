/*  A library to output the right key shortcut in any common app.
Given a global variable babble_mode to show the environment and a
key that calls the paste macro, do the right type of paste.
Setting the context is done by another macro, or TBD interaction with the host.

Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
*/

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblePaste.h"

#    ifdef BABL_MAC

bool babblePaste_mac(uint16_t keycode) {
#        ifdef BABL_MOVE 
    BABLM(BABL_GO_LEFT_WORD, IMALT(X_LEFT));
    BABLM(BABL_GO_RIGHT_WORD, IMALT(X_RIGHT));
    BABLM(BABL_GO_START_LINE, IMGUI(X_LEFT));
    BABLM(BABL_GO_END_LINE, IMGUI(X_RIGHT));
    BABLM(BABL_GO_START_DOC, IMGUI(X_UP));
    BABLM(BABL_GO_END_DOC, IMGUI(X_DOWN));
    BABLM(BABL_DEL_LEFT_WORD, IMALT(X_BSPACE));
    BABLM(BABL_DEL_RIGHT_WORD, IMALT(X_DELETE));
    BABLM(BABL_DEL_TO_LINE_END, OMSFT(IMGUI(X_RIGHT)) SS_TAP(X_BSPACE));  // this is more app agnostic than ctrl-k
    BABLM(BABL_DEL_TO_LINE_START, OMSFT(IMGUI(X_LEFT)) SS_TAP(X_BSPACE));
    BABLM(BABL_MODE, "Mac ");
#        endif
#        ifdef BABL_OSKEYS
    BABLM(BABL_UNDO, SS_LGUI("z"));
    BABLM(BABL_REDO, SS_LGUI("y"));
    BABLM(BABL_CUT, SS_LGUI("x"));
    BABLM(BABL_COPY, SS_LGUI("c"));
    BABLM(BABL_PASTE, SS_LGUI("v"));
    BABLM(BABL_SELECT_ALL, SS_LGUI("a"));
    BABLM(BABL_APP_SAVE, SS_LGUI("s"));
    BABLM(BABL_LEFTDENT, SS_LGUI("["));
    BABLM(BABL_RIGHTDENT, SS_LGUI("]"));
    BABLM(BABL_CANCEL, SS_LCTL("c"));
    BABLM(BABL_WINDOW_NEW, IMGUI(X_N));
    BABLM(BABL_CLOSE_APP, SS_LGUI("q"));
    BABLM(BABL_SCREENCAPTURE, OMSFT(OMGUI(IMALT(X_4))) IMGUI(X_SPACE) "preview" SS_LGUI("d"));
    BABLM(BABL_SWITCH_KEYBOARD_LAYOUT, IMCTL(X_SPACE));
#        endif
#        ifdef BABL_BROWSER
    BABLM(BABL_BROWSER_NEW_TAB, IMGUI(X_T));
    BABLM(BABL_BROWSER_CLOSE_TAB, SS_LGUI("w"));
    BABLM(BABL_BROWSER_REOPEN_LAST_TAB, OMSFT(SS_LGUI("t")));
    BABLM(BABL_BROWSER_NEXT_TAB, OMGUI(IMALT(X_RIGHT)));
    BABLM(BABL_BROWSER_PREV_TAB, OMGUI(IMALT(X_LEFT)));
    BABLM(BABL_BROWSER_URL_BAR, SS_LGUI("l"));
    BABLM(BABL_BROWSER_FORWARD, IMGUI(X_RIGHT));
    BABLM(BABL_BROWSER_BACK, IMGUI(X_LEFT));
    BABLM(BABL_BROWSER_FIND, SS_LGUI("f"));
    BABLM(BABL_BROWSER_BOOKMARK, SS_LGUI("d"));
    BABLM(BABL_BROWSER_RELOAD, SS_LGUI("r"));  //  reload
    BABLM(BABL_BROWSER_FULLSCREEN, OMGUI(SS_LCTRL("p")));
    BABLM(BABL_BROWSER_ZOOM_IN, IMGUI(X_KP_PLUS));  // ctr+ +
    BABLM(BABL_BROWSER_ZOOM_OUT, IMGUI(X_KP_MINUS));
#            ifdef BABL_BROWSER_CHROME
    BABLM(BABL_BROWSER_VIEWSRC, SS_LGUI("u"));           // Chrome or firefox
    BABLM(BABL_BROWSER_DEV_TOOLS, OMGUI(SS_LALT("i")));  // Chrome or Firefox
#            endif
#            ifdef BABL_BROWSER_SAFARI
    BABLM(BABL_BROWSER_VIEWSRC, OMGUI(IMALT(X_U)));  // Safari
                                                     // BABLM( BABL_BROWSER_DEV_TOOLS,	// No real equivalent for Safari
#            endif
#        endif  //  BABL_BROWSER

    // Todo, ring bell, flash light, show user this isn't supported
    return false;
}

#    endif /* mac mode*/
#endif     // Babblepaste
