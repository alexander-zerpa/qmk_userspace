/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    QWERTY,
    NOHRM,
    SYMBOLS,
    NAVIGATION,
    SYSTEM,
    CONFIG
};

// Home row definitions
#define HR_LALT LALT_T(KC_A)
#define HR_LCTL LCTL_T(KC_S)
#define HR_LGUI LGUI_T(KC_D)
#define HR_LSFT LSFT_T(KC_F)

#define HR_RSFT RSFT_T(KC_J)
#define HR_RGUI RGUI_T(KC_K)
#define HR_RCTL RCTL_T(KC_L)
#define HR_RALT LALT_T(KC_SCLN)

#define HR_TOGG TG(NOHRM)

// Shift and enter
#define LSFT_ENT LSFT_T(KC_ENT)
#define RSFT_ENT RSFT_T(KC_ENT)

// Space and layer change
#define SPC_SYM LT(SYMBOLS, KC_SPC)
#define SPC_NAV LT(NAVIGATION, KC_SPC)
#define SPC_SYS LT(SYSTEM, KC_SPC)

// Mouse button and layer change
#define MS1_SYS LT(SYSTEM, MS_BTN1)
#define MS2_SYS LT(SYSTEM, MS_BTN2)
#define MS3_SYS LT(SYSTEM, MS_BTN3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, HR_TOGG,    KC_CAPS,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_ESC, HR_LALT, HR_LCTL, HR_LGUI, HR_LSFT,    KC_G,  KC_NUM,    KC_SCRL,    KC_H, HR_RSFT, HR_RGUI, HR_RCTL, HR_RALT, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, SPC_SYM,LSFT_ENT,   RSFT_ENT, SPC_NAV, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [NOHRM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F, _______, _______,    _______, _______,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYMBOLS] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_INS,      KC_GT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_DOT,      KC_LT, KC_BSLS, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      CW_TOGG,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, SPC_SYS, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NAVIGATION] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      MS_ACL0, XXXXXXX, MS_BTN4,   MS_UP, MS_BTN5, XXXXXXX, XXXXXXX,    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      MS_ACL1, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      MS_ACL2, XXXXXXX, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_APP,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN3, MS2_SYS, MS_BTN1,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYSTEM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, KC_PSCR,    KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_BRID, KC_MPRV, KC_MSTP, KC_MPLY, KC_VOLD, KC_MNXT, XXXXXXX,    XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(CONFIG),
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [CONFIG] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, XXXXXXX,     QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(CONFIG),
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  //   [X] = LAYOUT_split_3x6_3_ex2(
  // //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,    _______, _______, _______
  //                                     //`--------------------------'  `--------------------------'
  // ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif


#if defined(TAPPING_TERM_PER_KEY) && defined(TAPPING_TERM_SFT)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_LSFT:
        case HR_RSFT:
            return TAPPING_TERM_SFT;
    }
    return TAPPING_TERM;
}
#endif

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
      // ,----------------------------------.  ,----------------------------------.
           'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R',
      // |----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
           'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R',
      // |----+----+----+----+----+----+----'  `----+----+----+----+----+----+----|
           'L', 'L', 'L', 'L', 'L', 'L',              'R', 'R', 'R', 'R', 'R', 'R',
      // |----+----+----+----+----+----+----.  ,----+----+----+----+----+----+----|
                              '*', '*', '*',    '*', '*', '*'
                          //`--------------'  `--------------'
    );
#endif /* ifdef CHORDAL_HOLD */

#include "./rgb.c"
