// #pragma once
// // Define all of
//
// enum custom_keycodes {
//   KC_MAKE = SAFE_RANGE,
//   Z_KVM1,
//   Z_KVM2,
//   Z_KVM3,
//   Z_KVM4,
//   KEYMAP_SAFE_RANGE
// };
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case Z_KVM1:
//       if (record->event.pressed) {SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "1");}
//       return false; // Skip all further processing of this key
//     case Z_KVM2:
//       if (record->event.pressed) {SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "2");}
//       return false;
//     case Z_KVM3:
//       if (record->event.pressed) {SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "3");}
//       return false;
//     case Z_KVM4:
//       if (record->event.pressed) {SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "4");}
//       return false;
//     default:
//       return true; // Process all other keycodes normally
//   }
// }
