
#define IGNORE_MOD_TAP_INTERRUPT
#define LEADER_TIMEOUT 300
#define COMBO_COUNT 6

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#if defined(KEYBOARD_ergodox_ez)
#    define TAPPING_TERM 350
#elif defined(KEYBOARD_gergo)
#    define TAPPING_TERM 350
#else
#    define TAPPING_TERM 200
#endif
#define TAP_CODE_DELAY 5

#define USE_BABLPASTE

// Expect to get errors if you comment a feature out and leave it in your keymap.

#ifdef USE_BABLPASTE
//define BabblePaste maps
// Windows.
#define MS_MODE 0
#define MAC_MODE 1
#define LINUX_MODE 2
//aka gnome+KDE
//#define EMACS_MODE 3
// #define VI_MODE 3
// Readline and tmux
// #define READMUX_MODE 2
//#define WORDSTAR_MODE 5
#endif

// Uncomment if you need more free flash space

// This removes everything but cursor movement
//#define BABL_MOVEMENTONLY
// and this just removes browser shortcuts
//#define BABL_NOBROWSER
