// https://stackoverflow.com/questions/6635851/real-world-use-of-x-macros
// https://stackoverflow.com/questions/147267/easy-way-to-use-variables-of-enum-types-as-string-in-c


#include "osKeys.h"

uint8_t os_keys_mode = 0;

const macro_t *osKeys(uint16_t keycode) {

  switch (keycode)
  {
#define ENTRY(a,b,c) \
  case a: SEND_STRING(b); break;
  OS_KEY_MACRO
#undef ENTRY

    default:
      return MACRO_NONE;
      break;
  }

  return MACRO_NONE;
}

uint8_t switch_os_keys_mode( uint8_t id) {
 os_keys_mode = id;
 return id;
}
