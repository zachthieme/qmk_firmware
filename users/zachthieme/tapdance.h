// Tap dance declarations
enum {
  TD_FILE_MAIL,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_FILE_MAIL] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(LSFT(KC_7))),
};
