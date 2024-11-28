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
    _GAME,
    _TYPO,
    _NAV,
    _SYM,
    _NUM,
    _MEDIA
};

enum custom_keycodes {
    TGL_GAME = SAFE_RANGE,
    LLOCK,
    TYPO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ERGOL] = LAYOUT(
    KC_ESC, KC_1, KC_2,    KC_3,    KC_4,      KC_5,                        KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    SIG,
    KC_TAB  , KC_Q, KC_W,    KC_E,    KC_R,      KC_T,                        KC_Y,     KC_U,     KC_I,  OSL(_TYPO),    KC_P,    DSCRD,
    OLSFT   , KC_A, KC_S,    KC_D,    KC_F,      KC_G,                       KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LGUI , KC_Z, KC_X,    KC_C,    KC_V,      KC_B,                        KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RCTL,
    KC_ENT  , KC_LALT, KC_LCTL, TL_LOWR,  KC_SPC, KC_DEL,         KC_BSPC,  ORSFT, TL_UPPR, KC_ESC, KC_MPLY,           LAUNCH
),

[_GAME] = LAYOUT(
    KC_ESC, KC_1, KC_2,    KC_3,    KC_4,      KC_5,                        KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    SIG,
    KC_TAB  , KC_Q, KC_W,    KC_E,    KC_R,      KC_T,                        KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,    DSCRD,
    OLSFT   , KC_A, KC_S,    KC_D,    KC_F,      KC_G,                       KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LGUI , KC_Z, KC_X,    KC_C,    KC_V,      KC_B,                        KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RCTL,
    KC_ENT  , KC_LALT, KC_LCTL, TL_LOWR,  KC_SPC, KC_DEL,                  KC_BSPC,    KC_RSFT,  TL_UPPR, KC_ESC, KC_MPLY,   LAUNCH
),

[_TYPO] = LAYOUT(
    _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______,_______,     _______, _______,_______,  _______,_______,           _______
),

[_NAV] = LAYOUT(
    LGUI(KC_F2),  KC_F1,   KC_F2,     KC_F3,      KC_F4,    KC_F5,                         KC_F6,      KC_F7,     KC_F8,    KC_F9,   KC_F10,     KC_F11,
    C(KC_TAB),  MV_LFT,  SPOTI_FAV, C(KC_SPC),  FFX_DEL,  C(KC_PSCR),                  DEL_LINE,   WD_LFT,    KC_UP,    WD_RGT,  XXXXXXX,    KC_F12,
    KC_MNXT,  UNDO,    KC_LALT,   KC_LCTL,    KC_LSFT,  ALGR(KC_TAB),                  KC_PGUP,    KC_LEFT,   KC_DOWN,  KC_RGHT, KC_APP,    KC_LGUI,
    KC_CAPS,  REDO,    CUT,       COPY,       PASTE,    DITTO,                         KC_PGDN,    KC_HOME,   KC_END,   KC_END, XXXXXXX,    LGUI(KC_SPC),
    KC_MPLY,           LLOCK,     TG(_MEDIA), TG(_NAV), KC_SPC,     TLG,     PASSMAN,  C(KC_BSPC),    _______,   KC_RSFT,  KC_RCTL,             TGL_GAME
),

[_NUM] = LAYOUT(
    KC_NUM,  KC_F1,   KC_F2,     KC_F3,      KC_F4,    KC_F5,                         KC_F6,     KC_F7,     KC_F8,     KC_F9,   KC_F10,     KC_F11,
    _______,  S(KC_1), S(KC_2),   S(KC_3),    S(KC_4),  S(KC_5),                       S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9), S(KC_0),    KC_F12,
    KC_LGUI,   KC_1,    KC_2,      KC_3,       KC_4,     KC_5,                          KC_6,      KC_7,      KC_8,      KC_9,    KC_0,       S(KC_SPC),
    _______,  ALGR(KC_DOT),   S(KC_4),   S(KC_6),   S(KC_1),  KC_N,                    S(KC_5),   KC_PPLS,   KC_PMNS,   KC_PAST, KC_PSLS,    KC_PDOT,
    _______,           LLOCK,     TG(_MEDIA), TG(_NAV), S(KC_SPC),   S(KC_SPC),      S(KC_SPC) ,  TG(_NUM),  TG(_NUM),  TG(_NUM),  KC_RCTL,             KC_P0
),

[_SYM] = LAYOUT(
    KC_ESC,  ALGR(KC_1), ALGR(KC_2),    ALGR(KC_3),    ALGR(KC_4),    ALGR(KC_5),                    ALGR(KC_6),     ALGR(KC_7),    ALGR(KC_8),    ALGR(KC_9),    ALGR(KC_0),          KC_NO,
    KC_TAB,  ALGR(KC_Q), ALGR(KC_W),    ALGR(KC_E),    ALGR(KC_R),    ALGR(KC_T),                    ALGR(KC_Y),     ALGR(KC_U),    ALGR(KC_I),    ALGR(KC_O),    ALGR(KC_P),    KC_NO,
    OLSFT ,  ALGR(KC_A), ALGR(KC_S),    ALGR(KC_D),    ALGR(KC_F),    ALGR(KC_G),                    ALGR(KC_H),     ALGR(KC_J),    ALGR(KC_K),    ALGR(KC_L),    ALGR(KC_SCLN), ORSFT,
    KC_NO,   ALGR(KC_Z), ALGR(KC_X),    ALGR(KC_C),    ALGR(KC_V),    ALGR(KC_B),                    ALGR(KC_N),     ALGR(KC_M),    ALGR(KC_COMM), ALGR(KC_DOT),  ALGR(KC_SLSH), QK_BOOT,
    CW_TOGG,           _______  ,         KC_LCTL,       _______,       ALGR(KC_SPC),   KC_DEL,  KC_BSPC,  MOD_RSFT,        TG(_SYM),       MO(_NUM),     _______,                      KC_ENT
),

[_MEDIA] = LAYOUT(
    _______,  KC_F1,    KC_F2,     KC_F3,       KC_F4,      KC_F5,                    KC_F6,     KC_F7,     KC_F8,    KC_F9,  KC_F10,  KC_F11,
    KC_NUM,  _______,  EL_F,      KC_UP,       EL_O,       _______,                  KC_PPLS,   KC_P7,     KC_P8,    KC_P9,  KC_PSLS, KC_F12,
    _______,  _______,  KC_LEFT,   KC_DOWN,     KC_RIGHT,  _______,                  KC_MINS,   KC_P4,     KC_P5,    KC_P6,  KC_PAST, S(KC_1),
    _______,  _______,  _______,   _______,     _______,    _______,                  KC_P0,     KC_P1,     KC_P2,    KC_P3,  KC_PDOT, S(KC_6),
    _______,            _______,   TG(_MEDIA),  TG(_MEDIA), KC_SPC, _______,   EL_DOT, _______,    TG(_MEDIA),  KC_BSPC,  _______,         TG(_MEDIA)
)
};
