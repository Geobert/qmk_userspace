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

    switch (keycode) {
       case TGL_GAME:
            if (record->event.pressed) {
                if (is_bepo) {
                    is_bepo = false;
                    default_layer_set(1UL << _ERGOL);
                } else {
                    is_bepo = true;
                    default_layer_set(1UL << _GAME);
                }
            }
            break;
    }
    return true;
}

void oneshot_layer_changed_user(uint8_t layer) {
    if (layer == _TYPO) {
        bool shifted = (get_mods() & MOD_MASK_SHIFT) || (get_oneshot_mods() & MOD_MASK_SHIFT) ;
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

// OLED screen

#ifdef OLED_ENABLE

void render_mod_status_caps_alt(uint8_t col, uint8_t line, uint8_t modifiers) {
    static const char PROGMEM caps_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM caps_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM caps_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM caps_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    led_t led_usb_state = host_keyboard_led_state();
    // oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_set_cursor(col, line);
    if(led_usb_state.caps_lock) {
        oled_write_P(caps_on_1, false);
    } else {
        oled_write_P(caps_off_1, false);
    }

    if ((led_usb_state.caps_lock) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(led_usb_state.caps_lock) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }


    oled_set_cursor(col, line + 1);
    if(led_usb_state.caps_lock) {
        oled_write_P(caps_on_2, false);
    } else {
        oled_write_P(caps_off_2, false);
    }

    if (led_usb_state.caps_lock && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_2, false);
    } else if(led_usb_state.caps_lock) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t col, uint8_t line, uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    oled_set_cursor(col, line);
    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    oled_set_cursor(col, line + 1);
    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void print_raise_layer(uint8_t col, uint8_t line) {
    static const char PROGMEM raise_layer1[] = {
        0x20, 0x97, 0x98, 0x99, 0x20, 0};
    static const char PROGMEM raise_layer2[] = {
        0x20, 0xb7, 0xb8, 0xb9, 0x20, 0};
    static const char PROGMEM raise_layer3[] = {
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    oled_write_P(raise_layer1, false);
    oled_set_cursor(col, line + 1);
    oled_write_P(raise_layer2, false);
    oled_set_cursor(col, line + 2);
    oled_write_P(raise_layer3, false);
}

void print_lower_layer(uint8_t col, uint8_t line) {
    static const char PROGMEM lower_layer1[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20, 0};
    static const char PROGMEM lower_layer2[] = {
        0x20, 0xba, 0xbb, 0xbc, 0x20, 0};
    static const char PROGMEM lower_layer3[] = {
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};

    oled_write_P(lower_layer1, false);
    oled_set_cursor(col, line + 1);
    oled_write_P(lower_layer2, false);
    oled_set_cursor(col, line + 2);
    oled_write_P(lower_layer3, false);
}

void print_default_layer(uint8_t col, uint8_t line) {
    static const char PROGMEM default_layer1[] = {
        0x20, 0x94, 0x95, 0x96, 0x20, 0};
    static const char PROGMEM default_layer2[] = {
        0x20, 0xb4, 0xb5, 0xb6, 0x20, 0};
    static const char PROGMEM default_layer3[] = {
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};

    oled_write_P(default_layer1, false);
    oled_set_cursor(col, line + 1);
    oled_write_P(default_layer2, false);
    oled_set_cursor(col, line + 2);
    oled_write_P(default_layer3, false);
}

void print_raise_and_lower_layer(uint8_t col, uint8_t line) {
    static const char PROGMEM raise_low_layer1[] = {
        0x20, 0x97, 0x98, 0x99, 0x20, 0};
    static const char PROGMEM raise_low_layer2[] = {
        0x20, 0xba, 0xb8, 0xbc, 0x20, 0};
    static const char PROGMEM raise_low_layer3[] = {
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};

    oled_write_P(raise_low_layer1, false);
    oled_set_cursor(col, line + 1);
    oled_write_P(raise_low_layer2, false);
    oled_set_cursor(col, line + 2);
    oled_write_P(raise_low_layer3, false);
}

void render_layer_state(uint8_t col, uint8_t line) {
    oled_set_cursor(col, line);

    if (layer_state_is(_SYM)) {
        print_lower_layer(col, line);
    } else if (layer_state_is(_NAV)) {
        print_raise_layer(col, line);
    } else if (layer_state_is(_MEDIA)) {
        print_raise_and_lower_layer(col, line);
    } else {
        print_default_layer(col, line);
    }
}

void render_logo(uint8_t line) {
    static const char PROGMEM logo1[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0};
    static const char PROGMEM logo2[] = {
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0};
    static const char PROGMEM logo3[] = {
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};

    oled_set_cursor(0, line);
    oled_write_P(logo1, false);
    oled_set_cursor(0, line + 1);
    oled_write_P(logo2, false);
    oled_set_cursor(0, line + 2);
    oled_write_P(logo3, false);
}

void print_base_layer(uint8_t col, uint8_t line) {
    static const char PROGMEM bepo1[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0
    };
    static const char PROGMEM bepo2[] = {
        0x21, 0x22, 0x23, 0x24, 0x25, 0
    };

    static const char PROGMEM game1[] = {
        0x06, 0x07, 0x08, 0x09, 0x14, 0
    };
    static const char PROGMEM game2[] = {
        0x26, 0x27, 0x28, 0x29, 0x2A, 0
    };


    oled_set_cursor(col, line);
    switch (get_highest_layer(default_layer_state)) {
        case _ERGOL:
            // oled_write_P(PSTR("Bepo"), false);
            oled_write_P(bepo1, false);
            oled_set_cursor(col, line + 1);
            oled_write_P(bepo2, false);
            break;
        case _GAME:
            oled_write_P(game1, false);
            oled_set_cursor(col, line + 1);
            oled_write_P(game2, false);
            // oled_write_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

static void print_status_narrow(void) {
    render_logo(0);
    render_layer_state(5, 0);

    const uint8_t col = 10;
    render_mod_status_caps_alt(col, 0, get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(col, 2, get_mods()|get_oneshot_mods());

    oled_set_cursor(16, 2);
    print_base_layer(16, 1);
    oled_render();
}

// WPM-responsive animation stuff here

#include "bongocat.h"
#define IDLE_SPEED 10 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_SPEED 30 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Implementation credit j-inc(/James Incandenza), pixelbenny, and obosob.
// Bongo cat images changed and adapted for sofle keyboard oled size.
// Original gif can be found here: https://www.pixilart.com/art/bongo-cat-bd2a8e9323aa705
static void render_anim(void) {
    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            /*
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            */
            oled_write_raw_P(idle[0], ANIM_SIZE);
         }
         /*
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }*/
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }

    if(get_current_wpm() != 000) {
        // oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            // oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    print_status_narrow();
    oled_set_cursor(0, 4);
    render_anim();
    return false;
}

#endif
