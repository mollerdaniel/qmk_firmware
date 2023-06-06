#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, MO(2), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_NO, KC_NO, KC_SPC, KC_ENT, KC_BSPC, KC_DEL),

[_LAYER1] = LAYOUT(KC_PWR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_NO, KC_NO, RGB_TOG, RGB_VAD, RGB_VAI, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_GRV, RALT(KC_W), KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, RALT(KC_P), RALT(KC_Q), KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_MRWD, KC_MFFD, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU),

[_LAYER2] = LAYOUT(KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RGUI, KC_APP, KC_TRNS) 

};


#ifdef OLED_ENABLE



//oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//    if (is_keyboard_master()) {
//        return OLED_ROTATION_270;
//    }
//    return rotation;
//}

static bool caps_lock_on = false;
static bool num_lock_on = false;

static void print_status_narrow(void) {
    static const char PROGMEM hr[] = {
        0x81, 0x81, 0x81, 0x81, 
        0x00,
    };

    static const char PROGMEM logo[] = {
        0x80, 0x84, 0x85, 0x80,
        0x80, 0x86, 0x87, 0x80,
        0x00,
    };

    static const char PROGMEM empty [] = {
        0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80,
        0x00,
    };

    static const char PROGMEM layer0[] = {
        0x90, 0x91, 0x80, 0x80,
        0x92, 0x93, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer1[] = {
        0x80, 0x80, 0x94, 0x95, 
        0x80, 0x80, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer01[] = {
        0x90, 0x91, 0x94, 0x95, 
        0x92, 0x93, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer2[] = {
        0x98, 0x99, 0x80, 0x80,
        0x9a, 0x9b, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer3[] = {
        0x80, 0x80, 0x9c, 0x9d, 
        0x80, 0x80, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM layer23[] = {
        0x98, 0x99, 0x9c, 0x9d, 
        0x9a, 0x9b, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM mod0[] = {
        0xa0, 0xa1, 0x80, 0x80,
        0xa2, 0xa3, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod1[] = {
        0x80, 0x80, 0xa4, 0xa5, 
        0x80, 0x80, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod01[] = {
        0xa0, 0xa1, 0xa4, 0xa5, 
        0xa2, 0xa3, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod2[] = {
        0xa8, 0xa9, 0x80, 0x80,
        0xaa, 0xab, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod3[] = {
        0x80, 0x80, 0xac, 0xad, 
        0x80, 0x80, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM mod23[] = {
        0xa8, 0xa9, 0xac, 0xad, 
        0xaa, 0xab, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM capslock_enabled_numlock_enabled[] = {
        0xb0, 0xb1, 0xb8, 0xb9,
        0xb2, 0xb3, 0xba, 0xbb,
        0x00,
    };

    static const char PROGMEM capslock_disabled_numlock_disabled[] = {
        0xb4, 0xb5, 0xbc, 0xbd,
        0xb6, 0xb7, 0xbe, 0xbf,
        0x00,
    };
    static const char PROGMEM capslock_disabled_numlock_enabled[] = {
        0xb4, 0xb5, 0xb8, 0xb9,
        0xb6, 0xb7, 0xba, 0xbb,
        0x00,
    };

    static const char PROGMEM capslock_enabled_numlock_disabled[] = {
        0xb0, 0xb1, 0xbc, 0xbd,
        0xb2, 0xb3, 0xbe, 0xbf,
        0x00,
    };

    oled_write_P(logo, false);
    oled_write_P(hr, false);

    bool layer0_on = IS_LAYER_ON(_LAYER0);
    bool layer1_on = IS_LAYER_ON(_LAYER2);
    bool layer2_on = IS_LAYER_ON(_LAYER1);
    bool layer3_on = false;

    // we are not doing one shot mods here
    static uint8_t mods;
    mods = get_mods();
    bool mod0_on = mods & MOD_MASK_CTRL;
    bool mod1_on = mods & MOD_MASK_SHIFT;
    bool mod2_on = mods & MOD_MASK_ALT;
    bool mod3_on = mods & MOD_MASK_GUI;

    if (layer0_on) {
        oled_write_P(layer1_on ? layer01 : layer0, false);
    } else {
        oled_write_P(layer1_on ? layer1 : empty, false);
    }

    if (layer2_on) {
        oled_write_P(layer3_on ? layer23 : layer2, false);
    } else {
        oled_write_P(layer3_on ? layer3 : empty, false);
    }

    oled_write_P(hr, false);

    if (mod0_on) {
        oled_write_P(mod1_on ? mod01 : mod0, false);
    } else {
        oled_write_P(mod1_on ? mod1 : empty, false);
    }

    if (mod2_on) {
        oled_write_P(mod3_on ? mod23 : mod2, false);
    } else {
        oled_write_P(mod3_on ? mod3 : empty, false);
    }

    oled_write_P(hr, false);
    if (caps_lock_on) {
	if (num_lock_on) {
            oled_write_P(capslock_enabled_numlock_enabled, false);
	} else {
	    oled_write_P(capslock_enabled_numlock_disabled, false);
	}
    } else {
	if (num_lock_on) {
            oled_write_P(capslock_disabled_numlock_enabled, false);
	} else {
	    oled_write_P(capslock_disabled_numlock_disabled, false);
	}
    }
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on = led_state.num_lock;
    return true;
}

bool oled_task_user(void) {
    //if (is_keyboard_master()) {
        print_status_narrow();
    //}
    return false;
}

#endif
