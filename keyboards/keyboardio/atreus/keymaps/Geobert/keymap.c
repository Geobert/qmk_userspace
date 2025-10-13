#include <stdio.h>

#include QMK_KEYBOARD_H


#include "features/layer_lock.h"
#include "layout.c"

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case ALT_T_U:
//         // case LCTL_T_I:
//         // case LSFT_T_E:
//         case RSFT_T_T:
//         case RCTL_T_S:
//         case RCTL_T_R:
//         case RSFT_T_P4:
//         case ALGR_T_P5:
//             return true;
//         default:
//             return false;
//     }
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(_SYM):
        case TT(_NAV):
        case TT(_NUM):
        //case TT(_TYPO):
            return 90;
        default:
            return TAPPING_TERM;
    }
}

bool is_bepo = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    if (IS_LAYER_ON(_TYPO)) {
        if (record->event.pressed) {
            if ((keycode >= KC_A && keycode <= KC_0) || keycode == KC_SPC
                || keycode == KC_SCLN || keycode == KC_SLSH
                || keycode == KC_DOT || keycode == KC_COMM) {
                int oneshot_state = get_oneshot_mods();
                int state = get_mods();
                clear_mods();
                clear_oneshot_mods();
                wait_ms(4);
                tap_code16_delay(KC_O, 4);
                set_mods(state);
                set_oneshot_mods(oneshot_state);
                wait_ms(4);
                tap_code16_delay(keycode, 4);
                return false;
            }
       }

        return true;
    }

    return true;
}

void oneshot_layer_changed_user(uint8_t layer) {
    if (layer == _TYPO) {
        bool shifted = get_mods() & MOD_MASK_SHIFT;
        if (shifted) {
            tap_code16(KC_O);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case EL_A:
        case EL_B:
        case EL_C:
        case EL_D:
        case EL_E:
        case EL_F:
        case EL_G:
        case EL_H:
        case EL_I:
        case EL_J:
        case EL_K:
        case EL_L:
        case EL_M:
        case EL_N:
        case EL_O:
        case EL_P:
        case EL_Q:
        case EL_R:
        case EL_S:
        case EL_T:
        case EL_U:
        case EL_V:
        case EL_W:
        case EL_X:
        case EL_Y:
        case EL_Z:
        case EL_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
