
Save
    SEQ_ONE_KEY(KC_S) {
      if (IS_LAYER_ON(0))
      {
        SEND_STRING(SS_LCTL("S"));
      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING(SS_LGUI("S"));
      }
    }

Select All
    SEQ_ONE_KEY(KC_A) {
      if (IS_LAYER_ON(0))
      {
        SEND_STRING(SS_LCTL("A"));
      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING(SS_LGUI("A"));
      }
    }
    SAVE ME
    SEQ_ONE_KEY(KC_C) {
      // copy per platform
      if (IS_LAYER_ON(0))
      {
        SEND_STRING(SS_LCTL("c"));
      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING(SS_LGUI("c"));
      }
    }

    SEQ_ONE_KEY(KC_P) {
      // paste per platform
      if (IS_LAYER_ON(0))
      {
        SEND_STRING(SS_LCTL("p"));
      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING(SS_LGUI("p"));
      }
    }

    SEQ_ONE_KEY(KC_X) {
      // cut per platform
      if (IS_LAYER_ON(0))
      {
        SEND_STRING(SS_LCTL("x"));
      }
      if (IS_LAYER_ON(1))
      {
        SEND_STRING(SS_LGUI("x"));
      }
    }


    // Indent
        SEQ_ONE_KEY(KC_I) {
          if (IS_LAYER_ON(0))
          {
            SEND_STRING(SS_LCTL("]"));
          }
          if (IS_LAYER_ON(1))
          {
            SEND_STRING(SS_LGUI("]"));
          }
        }

    // Indent
        SEQ_ONE_KEY(KC_O) {
          if (IS_LAYER_ON(0))
          {
            SEND_STRING(SS_LCTL("["));
          }
          if (IS_LAYER_ON(1))
          {
            SEND_STRING(SS_LGUI("["));
          }
        }


        // Zoom in
            SEQ_ONE_KEY(KC_M) {
              if (IS_LAYER_ON(0))
              {
                SEND_STRING(SS_LCTL("="));
              }
              if (IS_LAYER_ON(1))
              {
                SEND_STRING(SS_LGUI("="));
              }
            }

        // Zoom Out
            SEQ_ONE_KEY(KC_COMMA) {
              if (IS_LAYER_ON(0))
              {
                SEND_STRING(SS_LCTL("-"));
              }
              if (IS_LAYER_ON(1))
              {
                SEND_STRING(SS_LGUI("-"));
              }
            }

        // Zoom to 100
            SEQ_ONE_KEY(KC_SLASH) {
              if (IS_LAYER_ON(0))
              {
                SEND_STRING(SS_LCTL("0"));
              }
              if (IS_LAYER_ON(1))
              {
                SEND_STRING(SS_LGUI("0"));
              }
            }

    // TODO beginning of previous word : b goes to the beginning of the previous word.
    //    Mac: opt left arrow
    // TODO beginning of next word : w goes to the beginning of the next word.
    // TODO end of next word : e
    //    Mac: opt right arrow
    // TODO end of previous word : ge
    //
    // TODO beginning of line : j
    //    Mac: meta left arrow
    // TODO end of line : k
    //    Mac: meta right arrow
