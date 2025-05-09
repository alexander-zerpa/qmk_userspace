#ifdef RGB_MATRIX_ENABLE
int contains_keycode(uint16_t keycode, uint16_t *keycodes, size_t n) {
    for (int i = 0; i < n; i++) {
        if (keycodes[i] == keycode) {
            return i;
        }
    }
    return -1;
}

void rgb_matrix_set_color_by_keycodes(uint8_t led_min, uint8_t led_max, uint16_t *keycodes, rgb_t *colors, size_t n) {
    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t i_led = g_led_config.matrix_co[row][col];
            uint16_t key = keymap_key_to_keycode(layer, (keypos_t){col,row});
            for (uint8_t l = layer-1; key == KC_TRANSPARENT && l >= 0; l--) {
                key = keymap_key_to_keycode(l, (keypos_t){col,row});
            }
            int i_key = contains_keycode(key, keycodes, n);
            if (i_key >= 0 && i_led >= led_min && i_led < led_max && i_led != NO_LED) {
                rgb_matrix_set_color(i_led, colors[i_key].r, colors[i_key].g, colors[i_key].b);
            }
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    hsv_t hsv_red = {HSV_RED};
    if (hsv_red.v > rgb_matrix_get_val()) {
        hsv_red.v = rgb_matrix_get_val();
    }

    uint16_t keycodes[5];
    rgb_t colors[5];
    size_t n = 0;

    keycodes[n] = KC_CAPS;
    colors[n] = (host_keyboard_led_state().caps_lock) ? hsv_to_rgb(hsv_red) : (rgb_t){RGB_OFF};
    n++;

    if (!host_keyboard_led_state().num_lock) {
        keycodes[n] = KC_NUM;
        colors[n] = (rgb_t){RGB_OFF};
        n++;
    }
    if (!host_keyboard_led_state().scroll_lock) {
        keycodes[n] = KC_SCRL;
        colors[n] = (rgb_t){RGB_OFF};
        n++;
    }

    if (get_highest_layer(layer_state) > NOHRM && get_highest_layer(layer_state) != CONFIG) {
        keycodes[n] = KC_NO;
        colors[n] = (rgb_t){RGB_OFF};
        n++;
    }
    rgb_matrix_set_color_by_keycodes(led_min, led_max, keycodes, colors, n);
    return false;
}
#endif /* ifdef RGB_MATRIX_ENABLE */
