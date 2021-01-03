#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
KC_MAKE,        // Run keyboard's customized make command
KC_CCCV,        // Hold to copy, tap to paste
Z_KVM_1,        // KVM swithing command
Z_KVM_2,        // KVM swithing command
Z_KVM_3,        // KVM swithing command
Z_KVM_4,        // KVM swithing command
DAV_ZOOM_IN,
DAV_ZOOM_OUT,
DAV_FF,
DAV_CUT_ALL,
DAV_RMV_GAP,
DAV_MEDIA,
DAV_CUT,
DAV_EDIT,
DAV_NORM_AUDIO,
DAV_SEL_ALL,
DAV_SEL_END,
DAV_SNAP,
OS_CUT,
OS_COPY,
OS_SAVE,
OS_UNDO,
OS_PASTE,
ACT_OS,
OS_IN,
OS_OUT,
NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};
