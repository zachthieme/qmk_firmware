
#define IGNORE_MOD_TAP_INTERRUPT
#define LEADER_TIMEOUT 300
#define COMBO_COUNT 6

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#if defined(KEYBOARD_ergodox_ez)
#    define TAPPING_TERM 250
#elif defined(KEYBOARD_gergo)
#    define TAPPING_TERM 200
#else
#    define TAPPING_TERM 200
#endif
#define TAP_CODE_DELAY 5


#define USE_OSKEYS 1
