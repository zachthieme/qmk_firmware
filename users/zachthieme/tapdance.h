// Tap dance declarations
enum {
  TD_FILE_MAIL,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Z, twice for Shift+7
    [TD_FILE_MAIL] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(LSFT(KC_7))),
};
