const macro_t *osKeys(uint16_t keycode);

// function to change the active OS
uint8_t switch_os_keys_mode( uint8_t id);

// Holds the current OS that is active.
uint8_t os_keys_mode;

// define functions for os actions
// #define ENTRY(a,b,c)  str c (str action);
  // OS_KEY_MACRO
// #undef ENTRY
