#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    else return OLED_ROTATION_270;
}

bool render_status(void) {
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
        case NOHRM:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case SYMBOLS:
            oled_write_ln_P(PSTR("SYMB"), false);
            break;
        case NAVIGATION:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case SYSTEM:
            oled_write_ln_P(PSTR("SYSTM"), false);
            break;
        case CONFIG:
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
    oled_write_P(layer_state_is(NOHRM) ? PSTR("HRT\xD5\xD6") : PSTR("HRT\xD7\xD8"), false);

    oled_set_cursor(0, 9);
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
