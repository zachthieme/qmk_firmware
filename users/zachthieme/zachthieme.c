#include "zachthieme.h"

/*
### Combinations! ###

I regularly use these for indent/outdent
DF yields ]
SD yields [

Arrows can be handy without layers
JK yields left arrow
KL yields right arrow
JI yields up arrow
J, yields down arrow

*/
enum combos {
  DF_INDENT,
  SD_OUTDENT,
  JK_LEFT,
  KL_RIGHT,
  JI_UP,
  JCOMMA_DOWN,

};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM jcomma_combo[] = {KC_J, KC_COMMA, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_INDENT] = COMBO(df_combo, KC_RBRACKET),
  [SD_OUTDENT] = COMBO(sd_combo, KC_LBRACKET),
  [JK_LEFT] = COMBO(jk_combo, KC_LEFT),
  [KL_RIGHT] = COMBO(kl_combo, KC_RIGHT),
  [JI_UP] = COMBO(ji_combo, KC_UP),
  [JCOMMA_DOWN] = COMBO(jcomma_combo, KC_DOWN),
};


/*

### LEADER KEY ###



*/
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_T) {
      // Anything you can do in a macro.
      SEND_STRING("- [ ]");
    }

    SEQ_ONE_KEY(KC_L) {
      // Show which layer is on

      if (IS_LAYER_ON(0))
      {
        SEND_STRING("Windows");

      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING("Mac");
      }
    }

    SEQ_ONE_KEY(KC_MINS) {
      // Switch between mac and windows layer
      if (IS_LAYER_ON(0))
      {
        layer_on(1);
      }
      else if (IS_LAYER_ON(1))
      {
        layer_off(1);
      }
    }

    SEQ_ONE_KEY(KC_BSLASH) {
      // change to KVM1 - my PC
      // layer 0
      layer_state_set(0);
      SEND_STRING("\\ worked");
    }

    SEQ_ONE_KEY(KC_QUOTE) {
      // change to KVM2 - my mac
      // layer 1
      layer_state_set(1);
      SEND_STRING("quote worked");

    }

    SEQ_ONE_KEY(KC_RSPC) {
      // change to KVM2 - work laptop
      // layer 0
      layer_state_set(0);
      SEND_STRING("RSPC worked");

    }

// helper
//  TODO look into secrets from drashna
    SEQ_ONE_KEY(KC_GESC) {
        SEND_STRING("45!");
    }
  }
}
