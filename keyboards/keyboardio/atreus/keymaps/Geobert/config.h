#pragma once

//#define USE_MATRIX_I2C

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


// #define CUSTOM_FONT

// #define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

// #define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define RETRO_TAPPING

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 2

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// #ifdef DEBOUNCE
//     #undef DEBOUNCE
// #endif
// #define DEBOUNCE 8

