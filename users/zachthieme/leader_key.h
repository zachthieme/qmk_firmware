// TODO add any destructions and examples

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
#ifdef USE_BABLPASTE
  SEND_STRING("babblepaste");
#endif
      switch (babble_mode){
          case 0:
            SEND_STRING("win");
            break;
          case 1:
            SEND_STRING("mac");
            break;
          case 2:
            SEND_STRING("linux");
            break;
          default:
            SEND_STRING("None");
      }

      // if (IS_LAYER_ON(0))
      // {
      //   SEND_STRING("Windows");
      // }
      // if (IS_LAYER_ON(1))
      // {
      //   SEND_STRING("Mac");
      // }
    }
// TODO figure out how layer changes actually work and figure out how to sync correctly within the kvm changes
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

    // SEQ_ONE_KEY(Z_KVM_1) {
    //   // change to KVM1 - my PC
    //   layer_on(0);
    //   SEND_STRING(SS_TAP(KC_LCTL) SS_TAP(KC_LCTL) "1");
    // }

    // SEQ_ONE_KEY(Z_KVM_2) {
    //   // change to KVM2 - my mac
    //   // layer 1
    //   layer_on(1);
    //   SEND_STRING(SS_TAP(KC_LCTL) SS_TAP(KC_LCTL) "2");
    //
    // }
    //
    // SEQ_ONE_KEY(Z_KVM_3) {
    //   // change to KVM3 - work laptop
    //   // layer 0
    //   layer_on(0);
    //   SEND_STRING(SS_TAP(KC_LCTL) SS_TAP(KC_LCTL) "3");
    // }

// helper
//  TODO look into secrets from drashna
    SEQ_ONE_KEY(KC_GESC) {
        SEND_STRING("45!");
    }
  }
}
