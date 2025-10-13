/* Copyright 2020
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


// clang-format off

// Row 1
#define EL_GRV  KC_GRV  // `
#define EL_1    KC_1    // 1
#define EL_2    KC_2    // 2
#define EL_3    KC_3    // 3
#define EL_4    KC_4    // 4
#define EL_5    KC_5    // 5
#define EL_6    KC_6    // 6
#define EL_7    KC_7    // 7
#define EL_8    KC_8    // 8
#define EL_9    KC_9    // 9
#define EL_0    KC_0    // 0
#define EL_SLSH KC_MINS // /
#define EL_EQL  KC_EQL  // =
// Row 2
#define EL_Q    KC_Q    // Q
#define EL_C    KC_W    // C
#define EL_O    KC_E    // O
#define EL_P    KC_R    // P
#define EL_W    KC_T    // W
#define EL_J    KC_Y    // J
#define EL_M    KC_U    // M
#define EL_D    KC_I    // D
#define EL_1DK  KC_O    // dead
#define EL_Y    KC_P    // F
#define EL_LBRC KC_LBRC // [
#define EL_RBRC KC_RBRC // ]
// Row 3
#define EL_A    KC_A    // A
#define EL_S    KC_S    // S
#define EL_E    KC_D    // E
#define EL_N    KC_F    // N
#define EL_F    KC_G    // ,
#define EL_L    KC_H    // L
#define EL_R    KC_J    // R
#define EL_T    KC_K    // T
#define EL_I    KC_L    // I
#define EL_U    KC_SCLN // U
#define EL_QUOT KC_QUOT // '
#define EL_BSLS KC_BSLS // backslash
// Row 4#define EL_LABK KC_NUBS // <
#define EL_Z    KC_Z    // Z
#define EL_X    KC_X    // X
#define EL_MINS KC_C    // -
#define EL_V    KC_V    // V
#define EL_B    KC_B    // B
#define EL_DOT  KC_N    // .
#define EL_H    KC_M    // H
#define EL_G    KC_COMM // G
#define EL_COMM KC_DOT  // Y
#define EL_K    KC_SLSH // K

/* Shifted symbols */

// Row 1
#define EL_TILD S(EL_GRV)  // ~
#define EL_EXLM S(EL_1)    // !
// #define EL_AT   S(EL_2)    // @ use the one in alt-gr
// #define EL_HASH S(EL_3)    // # use the one in alt-gr
#define EL_DLR  S(EL_4)    // $
#define EL_PERC S(EL_5)    // %
#define EL_CIR  S(EL_6)    // ^
#define EL_AMPR S(EL_7)    // &
#define EL_ASTR S(EL_8)    // *
#define EL_LPRN S(EL_9)    // (
#define EL_RPRN S(EL_0)    // )
#define EL_UNDS S(EL_SLSH) // _
#define EL_PLUS S(EL_EQL)  // +
// Row 2
#define EL_DIAE S(EL_DEAD) // ¨ (dead)
#define EL_LCBR S(EL_LBRC) // {
#define EL_RCBR S(EL_RBRC) // }
// Row 3
#define EL_SCLN S(EL_COMM) // ;
#define EL_DQUO S(EL_QUOT) // "
#define EL_PIPE S(EL_BSLS) // |
// Row 4
#define EL_RABK S(EL_LABK) // >
#define EL_QUES S(EL_MINS) // ?
#define EL_COLN S(EL_DOT)  // :
// Row 5
#define EL_NNBS S(KC_SPC)  // (narrow non-breaking space)

/* AltGr symbols */

// Row 1 no alt-gr symbols

// Row 2
#define EL_AT   ALGR(EL_Q)    // @
#define EL_LBRK ALGR(EL_C)    // [
#define EL_RBRK ALGR(EL_O)    // ]
// #define EL_DLR  ALGR(EL_P)    // $ already defined in shifted
// #define EL_PERC ALGR(EL_W)    // % already defined in shifted
#define EL_CIRC ALGR(EL_J)    // ^
// #define EL_AMPR ALGR(EL_M)    // & already defined in shifted
// #define EL_ASTR ALGR(EL_D)    // * already defined in shifted
// #define EL_QUOT ALGR(EL_DEAD) // ' already defined in base
// #define EL_GRV  ALGR(EL_F)    // ` already defined in base
// Row 3
// #define EL_LCBR ALGR(EL_A   )    // { already defined in base
// #define EL_LPRN ALGR(EL_S   ) // ( already defined in shifted
// #define EL_RPRN ALGR(EL_E   )    // ) already defined in shifted
// #define EL_RCBR ALGR(EL_N   )    // } already defined in base
// #define EL_UNDS ALGR(EL_COMM) // _ already defined in base
// #define EL_BSLS ALGR(EL_L   ) // \ already defined in base
// #define EL_PLUS ALGR(EL_R   )    // + already defined in shifted
// #define EL_MINS  ALGR(EL_T   )    // - already defined in base
// #define EL_SLSH ALGR(EL_I   )    // / already defined in base
// #define EL_DQUO   ALGR(EL_U   )    // " already defined in shifted
// Row 4
// #define EL_TILD   ALGR(EL_Z   )    // ~ already defined in shifted
// #define EL_LABK ALGR(EL_X   )    // < already defined in base
// #define EL_RABK ALGR(EL_MINS)    // > already defined in shifted
// #define EL_EQL ALGR(EL_V   )    // = already defined in base
#define EL_HASH ALGR(EL_B   )    // #
// #define EL_PIPE ALGR(EL_DOT )    // | already defined in shifted
// #define EL_EXLM ALGR(EL_H   )    // ! already defined in shifted
// #define EL_SCLN ALGR(EL_G   )    // ; use the one in shifted
// #define EL_COLN ALGR(EL_Y   )    // : use the one in shifted
// #define EL_QUES ALGR(EL_K   )    // ? use the one if shifted


/* Shift+AltGr symbols */

// Row 1 no symbols

// Row 2
#define EL_PERM S(ALGR(EL_W))    // ‰
#define EL_DCIR S(ALGR(EL_J))    // ^ (dead)
#define EL_MUL  S(ALGR(EL_D))    // ×
#define EL_ACUT S(ALGR(EL_DEAD)) // ´ (dead)
// Row 3
#define EL_NDSH S(ALGR(EL_COMM)) // –
#define EL_PLMN S(ALGR(EL_R))    // ±
#define EL_MDSH S(ALGR(EL_T))    // —
#define EL_DIV  S(ALGR(EL_I))    // ÷
// #define EL_DIAE  S(ALGR(EL_U))    // ¨ (dead) use the one on shifted
// Row 4
#define EL_DTIL S(ALGR(EL_Z))    // ~ (dead)
#define EL_LEQL S(ALGR(EL_X))    // ≤
#define EL_GEQL S(ALGR(EL_MINS)) // ≥
#define EL_AEQL S(ALGR(EL_V))    // ≃
#define EL_BRKP S(ALGR(EL_DOT))  // ̣¦
#define EL_NOT  S(ALGR(EL_Y))    // ¬

// Row 5
#define EL_NBSP S(ALGR(KC_SPC))  //   (non-breaking space)
