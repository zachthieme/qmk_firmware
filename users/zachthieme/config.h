
#define IGNORE_MOD_TAP_INTERRUPT
#define TAP_CODE_DELAY 5
// #define LEADER_TIMEOUT 300

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
//#define BABL_BROWSER_MS
//#define BABL_BROWSER_SAFARI // Safari, Apple defaults.

//// applications vary even more between OSes. We'll do our best.
// #define BABL_APP
// // To enable specific App options.
// #define BABL_APP_CELLS // spreadsheets and tables
// #define BABL_APP_EDITOR // Fancy editor commands
// #define BABL_APP_WINDOWSPLITTING // splitting frames & windows

//// What App keybinding is assumed?
//#define BABL_APP_GOOGLE // Google office
// #define BABL_APP_MSOFFICE // MS office
// //#define BABL_APP_APPLE // Apple office
// #define BABL_APP_SUBLIME
