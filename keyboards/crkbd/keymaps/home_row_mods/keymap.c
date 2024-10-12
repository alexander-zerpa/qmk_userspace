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

// Home row definitions
#define HR_LALT LALT_T(KC_A)
#define HR_LCTL LCTL_T(KC_S)
#define HR_LGUI LGUI_T(KC_D)
#define HR_LSFT LSFT_T(KC_F)

#define HR_RSFT RSFT_T(KC_J)
#define HR_RGUI RGUI_T(KC_K)
#define HR_RCTL RCTL_T(KC_L)
#define HR_RALT LALT_T(KC_SCLN)

// Shift and enter
#define LSFT_ENT LSFT_T(KC_ENT)
#define RSFT_ENT RSFT_T(KC_ENT)

// Space and layer change
#define LT_SPC1 LT(1, KC_SPC)
#define LT_SPC2 LT(2, KC_SPC)
#define LT_SPC3 LT(3, KC_SPC)

// Enter and layer change
#define LT_ENT1 LT(1, KC_ENT)
#define LT_ENT2 LT(2, KC_ENT)
#define LT_ENT3 LT(3, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC, HR_LALT, HR_LCTL, HR_LGUI, HR_LSFT,    KC_G,                         KC_H, HR_RSFT, HR_RGUI, HR_RCTL, HR_RALT, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, LT_SPC1,LSFT_ENT,   RSFT_ENT, LT_SPC2, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_BSLS, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, LT_SPC3, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MS_ACL0, XXXXXXX, MS_BTN4,   MS_UP, MS_BTN5, XXXXXXX,                      MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MS_ACL1, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MS_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MS_BTN2, LT_SPC3, MS_BTN1,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_NUM,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_CAPS,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_SCRL,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  //   [X] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,    _______, _______, _______
  //                                     //`--------------------------'  `--------------------------'
  // ),
};


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

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    else return OLED_ROTATION_270;
}

bool render_status(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("SYMB"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("CONF"), false);
            break;
        default:
            oled_write_ln_P(PSTR("undef"), false);
    }

    // Host Keyboard LED Status
    oled_set_cursor(0, 4);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM\xD5\xD6") : PSTR("NUM\xD7\xD8"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP\xD5\xD6") : PSTR("CAP\xD7\xD8"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\xD5\xD6") : PSTR("SCR\xD7\xD8"), false);

    oled_set_cursor(0, 8);
    #ifndef NO_ACTION_ONESHOT
    oled_write_P((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT ? PSTR("SFT\xD5\xD6") : PSTR("SFT\xD7\xD8"), false);
    oled_write_P((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL ? PSTR("CTL\xD5\xD6") : PSTR("CTL\xD7\xD8"), false);
    oled_write_P((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT ? PSTR("ALT\xD5\xD6") : PSTR("ALT\xD7\xD8"), false);
    oled_write_P((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI ? PSTR("GUI\xD5\xD6") : PSTR("GUI\xD7\xD8"), false);
    #else
    oled_write_P((get_mods()) & MOD_MASK_SHIFT ? PSTR("SFT\xD5\xD6") : PSTR("SFT\xD7\xD8"), false);
    oled_write_P((get_mods()) & MOD_MASK_CTRL ? PSTR("CTL\xD5\xD6") : PSTR("CTL\xD7\xD8"), false);
    oled_write_P((get_mods()) & MOD_MASK_ALT ? PSTR("ALT\xD5\xD6") : PSTR("ALT\xD7\xD8"), false);
    oled_write_P((get_mods()) & MOD_MASK_GUI ? PSTR("GUI\xD5\xD6") : PSTR("GUI\xD7\xD8"), false);
    #endif

    return false;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}
#endif
