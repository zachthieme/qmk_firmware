
#define IGNORE_MOD_TAP_INTERRUPT
#define TAP_CODE_DELAY 5
// #define LEADER_TIMEOUT 300

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#    define TAPPING_TERM 200
/*
#if defined(KEYBOARD_ergodox_ez)
#    define TAPPING_TERM 300
#else
#    define TAPPING_TERM 300
#endif
*/

#define USE_BABBLEPASTE

//// Uncomment the modes you want to enable
#define BABL_WINDOWS
#define BABL_MAC
#define BABL_LINUX

//// These enable subsets of babble macros. Disable options to save space
#define BABL_MOVE // Uncomment to add basic cursor movement
#define BABL_OSKEYS // This adds Cut, paste, window movement and common OS shortcuts
#define BABL_BROWSER // Browser shortcuts

//// What Browser shortcuts?
#define BABL_BROWSER_CHROME // Chrome browser, Google apps
