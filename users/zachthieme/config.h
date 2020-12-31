
#define IGNORE_MOD_TAP_INTERRUPT
#define TAP_CODE_DELAY 5
#define LEADER_TIMEOUT 300

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#    define TAPPING_TERM 300
/*
#if defined(KEYBOARD_ergodox_ez)
#    define TAPPING_TERM 300
#else
#    define TAPPING_TERM 300
#endif
*/
