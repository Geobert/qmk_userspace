//! this file is not intended to be compiled, it's included in `keymap.c`
//! I've done this so the keymap is more easily accessible

#include QMK_KEYBOARD_H
#include "keymap_ergol.h"

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)
// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(KC_MINS)
#define PASSMAN C(S(KC_RBRC))
#define DEL_LINE C(S(EL_K))
#define LAUNCH A(KC_SPC)
#define WD_LFT C(KC_LEFT)
#define WD_RGT C(KC_RIGHT)
#define UNDO C(EL_Z)
#define REDO C(EL_Y)
#define TLG A(KC_GRV)
#define SIG A(C(KC_GRV))
#define DSCRD C(KC_GRV)
#define CUT C(EL_X)
#define COPY C(EL_C)
#define PASTE C(EL_V)
#define SPOTI_FAV LSA(EL_B)
#define FFX_DEL C(S(KC_DEL))
#define ACC_CIR EL_CIR
#define OLSFT OSM(MOD_LSFT)
#define ORSFT OSM(MOD_RSFT)

// LAYERS SECTION
enum custom_layers {
    _DEFAULTS = 0,
    _ERGOL = 0,
    _TYPO,
    _NAV,
    _SYM,
    _NUM,
    _MEDIA
};

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
    TYPO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ERGOL] = LAYOUT(
    KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,                           KC_Y,     KC_U,     KC_I,  OSL(_TYPO),    KC_P,
    KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                           KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,
    KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,    KC_DEL,       KC_BSPC, KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,
    KC_ENT, KC_LGUI, KC_LCTL, TL_LOWR,KC_SPC,  KC_LALT,      KC_TAB,  ORSFT,    TL_UPPR,  KC_ESC,   KC_MPLY, LAUNCH
),

[_TYPO] = LAYOUT(
    _______, _______, _______, _______,_______,                        _______, _______, _______, _______, _______,
    _______, _______, _______, _______,_______,                        _______, _______, _______, _______, _______,
    _______, _______, _______, _______,_______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,_______, _______,      _______, _______, _______, _______, _______, _______
),

[_NAV] = LAYOUT(
    KC_F2,  MV_RGT,  C(KC_SPC),  FFX_DEL,  C(KC_PSCR),                  DEL_LINE,   WD_LFT,    KC_UP,    WD_RGT,  KC_F6,
    UNDO,   KC_LALT, KC_LCTL,    KC_LSFT,  ALGR(KC_TAB),                  KC_PGUP,    KC_LEFT,   KC_DOWN,  KC_RGHT, KC_F7,
    REDO,   CUT,     COPY,       PASTE,    DITTO, TLG,            PASSMAN, KC_PGDN,    KC_HOME,   KC_END,   KC_END, XXXXXXX,
    KC_F5,  KC_F1,   KC_F8,      _______,  TG(_MEDIA), _______,    KC_BSPC,  C(KC_BSPC), _______,    KC_F9,  KC_F10, KC_F11
),

[_NUM] = LAYOUT(
    S(KC_1), S(KC_2),   S(KC_3),    S(KC_4),  S(KC_5),                           S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9), S(KC_0),
    KC_1,    KC_2,      KC_3,       KC_4,     KC_5,                              KC_6,      KC_7,      KC_8,      KC_9,    KC_0,
    ALGR(KC_DOT),   S(KC_4),   S(KC_6),   S(KC_1),  KC_N, _______,     _______,  S(KC_5),   KC_PPLS,   KC_PMNS,   KC_PAST, KC_PSLS,
    _______,  _______, _______, _______, KC_SPC,  S(KC_SPC),           C(KC_SPC) , _______, _______,  _______, _______, _______
),

[_SYM] = LAYOUT(
    ALGR(KC_Q), ALGR(KC_W),    ALGR(KC_E),    ALGR(KC_R),    ALGR(KC_T),                    ALGR(KC_Y),     ALGR(KC_U),    ALGR(KC_I),    ALGR(KC_O),    ALGR(KC_P),
    ALGR(KC_A), ALGR(KC_S),    ALGR(KC_D),    ALGR(KC_F),    ALGR(KC_G),                    ALGR(KC_H),     ALGR(KC_J),    ALGR(KC_K),    ALGR(KC_L),    ALGR(KC_SCLN),
    ALGR(KC_Z), ALGR(KC_X),    ALGR(KC_C),    ALGR(KC_V),    ALGR(KC_B), _______,  _______, ALGR(KC_N),     ALGR(KC_M),    ALGR(KC_COMM), ALGR(KC_DOT),  ALGR(KC_SLSH),
    _______  ,  _______,       _______,       ALGR(KC_SPC),  _______,    KC_BSPC,  C(KC_BSPC),_______,        ORSFT,       MO(_NUM),     _______,          XXXXXXX
),

[_MEDIA] = LAYOUT(
    _______,  EL_F,      KC_UP,       EL_O,       _______,                           KC_PPLS,   KC_P7,     KC_P8,    KC_P9,  KC_PSLS,
     _______,  KC_LEFT,   KC_DOWN,     KC_RIGHT,  _______,                           KC_MINS,   KC_P4,     KC_P5,    KC_P6,  KC_PAST,
     _______,  _______,   _______,     _______,    _______, _______,      KC_P0,     KC_P1,     KC_P2,    KC_P3,  KC_PDOT, S(KC_6),
    _______,   _______,   TG(_MEDIA),  TG(_MEDIA), _______,  EL_DOT,      _______,    TG(_MEDIA),  KC_BSPC,  _______, _______ ,TG(_MEDIA)
)
};
