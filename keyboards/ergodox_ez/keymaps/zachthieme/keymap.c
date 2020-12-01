#include QMK_KEYBOARD_H
#include "version.h"
#include "zachthieme.h"
// #include "babblePaste.h"

enum macro_keycodes {
DHPASTE=1,
VIBRK,
};

// #include process_record_user
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_GRAVE,                                       KC_EQUAL,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    LCTL_T(KC_DELETE),LGUI_T(KC_A), LCTL_T(KC_S),   LALT_T(KC_D),   KC_F,           KC_G,                                                           KC_H,           KC_J,           LALT_T(KC_K),   LCTL_T(KC_L),   LGUI_T(KC_SCOLON),      LT(4,KC_QUOTE),
    KC_LSPO,        KC_Z,           KC_X,   KC_C,           KC_V,   KC_B,           KC_LBRACKET,                                    KC_RBRACKET,    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
    KC_NO,          KC_HOME,      KC_END,         KC_LGUI,        LT(3,KC_LBRACKET),                                                                 KC_MINUS,       KC_BSPACE,      KC_NO,          KC_NO,        LT(4,KC_NO),
                                                                                                    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE,
                                                                                                                    KC_PGUP,        KC_PGDOWN,
                                                                                    LT(1,KC_SPACE),       LT(2,KC_TAB),   KC_MINUS,       KC_LBRACKET,       LT(2,KC_ENTER), LT(1,KC_SPACE)
  ),
  // [1] = LAYOUT_ergodox_pretty(
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //                                                                                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //                                                                                                                   KC_TRANSPARENT, KC_TRANSPARENT,
  //                                                                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  // ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MAC_DPWORD,  KC_MAC_DNWORD,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MAC_PREWORD, KC_UP,          KC_MAC_NEXWORD, KC_TRANSPARENT, Z_KVM_1,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_MAC_BEGLINE, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MAC_ENDLINE , Z_KVM_2,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MAC_HEAD,    KC_PGUP,        KC_PGDOWN,      KC_MAC_TAIL,    KC_TRANSPARENT, Z_KVM_3,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, Z_KVM_4,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0,           KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, KC_KP_PLUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,      KC_DELETE,      KC_TRANSPARENT,                                                                 KC_0,           KC_4,           KC_5,           KC_6,           KC_KP_SLASH,    KC_KP_MINUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PDOT,        KC_1,           KC_2,           KC_3,           KC_UP,          KC_KP_EQUAL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MAKE,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MAC_DPWORD,  KC_MAC_DNWORD,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,      KC_DELETE,      KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OS_UNDO,        OS_CUT,         OS_COPY,        OS_PASTE,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

//
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case KC_J:
//         //   if (record->event.pressed) {
//         //     #ifdef USE_BABLPASTE
//         //               SEND_STRING("babble");
//         //     #endif
//         //     send_string("keymap J");
//         //     SEND_STRING("JJJJ");
//         //   }
//         //   break;
//         // case KC_2:
//         //     if (layer_state_is(_GAMEPAD) && userspace_config.swapped_numbers) {
//         //         if (record->event.pressed) {
//         //             register_code(KC_1);
//         //         } else {
//         //             unregister_code(KC_1);
//         //         }
//         //         return false;
//         //     }
//         //     break;
//         // case KC_SWAP_NUM:
//         //     if (record->event.pressed) {
//         //         userspace_config.swapped_numbers ^= 1;
//         //         eeconfig_update_user(userspace_config.raw);
//         //         unregister_code(KC_1);
//         //         unregister_code(KC_2);
//         //     }
//         //     break;
//     }
//     return true;
// }
//
// extern bool g_suspend_state;
// extern rgb_config_t rgb_matrix_config;
//
// void keyboard_post_init_user(void) {
//   rgb_matrix_enable();
// }
//
// const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
//     [0] = { {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193}, {152,206,193} },
//
//     [1] = { {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244}, {0,4,244} },
//
//     [2] = { {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,60,246}, {0,60,246}, {0,60,246}, {31,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,183,238}, {31,255,255}, {31,255,255}, {31,255,255}, {0,60,246}, {0,183,238}, {31,255,255}, {0,183,238}, {0,183,238}, {0,60,246}, {0,60,246}, {0,60,246}, {0,60,246}, {0,183,238} },
//
//     [3] = { {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255} },
//
// };
//
// void set_layer_color(int layer) {
//   for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//     HSV hsv = {
//       .h = pgm_read_byte(&ledmap[layer][i][0]),
//       .s = pgm_read_byte(&ledmap[layer][i][1]),
//       .v = pgm_read_byte(&ledmap[layer][i][2]),
//     };
//     if (!hsv.h && !hsv.s && !hsv.v) {
//         rgb_matrix_set_color( i, 0, 0, 0 );
//     } else {
//         RGB rgb = hsv_to_rgb( hsv );
//         float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//         rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
//     }
//   }
// }
//
// void rgb_matrix_indicators_user(void) {
//   if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
//   switch (biton32(layer_state)) {
//     case 0:
//       set_layer_color(0);
//       break;
//     case 1:
//       set_layer_color(1);
//       break;
//     case 2:
//       set_layer_color(2);
//       break;
//     case 3:
//       set_layer_color(3);
//       break;
//    default:
//     if (rgb_matrix_get_flags() == LED_FLAG_NONE)
//       rgb_matrix_set_color_all(0, 0, 0);
//     break;
//   }
// }
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case RGB_SLD:
//       if (record->event.pressed) {
//         rgblight_mode(1);
//       }
//       return false;
//   }
//   return true;
// }
//
// uint32_t layer_state_set_user(uint32_t state) {
//
//   uint8_t layer = biton32(state);
//
//   ergodox_board_led_off();
//   ergodox_right_led_1_off();
//   ergodox_right_led_2_off();
//   ergodox_right_led_3_off();
//   switch (layer) {
//     case 1:
//       ergodox_right_led_1_on();
//       break;
//     case 2:
//       ergodox_right_led_2_on();
//       break;
//     case 3:
//       ergodox_right_led_3_on();
//       break;
//     case 4:
//       ergodox_right_led_1_on();
//       ergodox_right_led_2_on();
//       break;
//     case 5:
//       ergodox_right_led_1_on();
//       ergodox_right_led_3_on();
//       break;
//     case 6:
//       ergodox_right_led_2_on();
//       ergodox_right_led_3_on();
//       break;
//     case 7:
//       ergodox_right_led_1_on();
//       ergodox_right_led_2_on();
//       ergodox_right_led_3_on();
//       break;
//     default:
//       break;
//   }
//   return state;
// };
