// Keycodes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
// Encoders: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
// RGB control: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
// OLED: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md
// Split keyboard features: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md

#include QMK_KEYBOARD_H

// commented for space
// #include <stdio.h>

// Left-hand home row mods
#define HOME_A     KC_A         // LGUI_T(KC_A)
#define HOME_S     KC_S         // LALT_T(KC_S)
#define HOME_D     MT(MOD_LGUI,KC_D) // LSFT_T(KC_D)
#define HOME_F     MT(MOD_LALT,KC_F) // LCTL_T(KC_F)
// Right-hand home row mods
#define HOME_J     MT(MOD_LALT,KC_J) // RCTL_T(KC_J)
#define HOME_K     MT(MOD_LGUI,KC_K) // RSFT_T(KC_K)
#define HOME_L     KC_L         // LALT_T(KC_L)
#define HOME_SC    KC_SCLN      // RGUI_T(KC_SCLN)

typedef enum {
    _LAYERS_HOME = 0,
    _LAYERS_SYMBOLS,
    _LAYERS_NUM,
    _LAYERS_NAV,
    _LAYERS_FN,
} layers_t;

typedef enum {
    _ENCODER_LEFT = 0,
    _ENCODER_RIGHT
} encoder_t;

// Tap dance (more at the bottom of this file)
enum {
    _DANCE_01,
    _DANCE_02,
    _DANCE_03,
};
#define TD_DOT  TD(_DANCE_01) // KC_DOT  KC_EXLM
#define TD_COMM TD(_DANCE_02) // KC_COMM KC_MINS
#define TD_SLSH TD(_DANCE_03) // KC_SLSH KC_UNDS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	[_LAYERS_HOME] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, 
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, 
        KC_LCTL, HOME_A , HOME_S , HOME_D , HOME_F , KC_G   ,                      KC_H   , HOME_J , HOME_K , HOME_L , HOME_SC, KC_ENT , 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,    KC_PSCR, KC_N   , KC_M   , TD_COMM, TD_DOT , TD_SLSH, KC_RSFT, 
                            KC_LGUI, KC_LALT, KC_RCTL, OSM(MOD_LSFT),          KC_SPC , TO(1)  , KC_DEL , KC_DEL ),
	//                                        OSM(MOD_RCTL)
    [_LAYERS_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
        _______, KC_ESC , KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, KC_BSPC, _______, 
        _______, KC_TAB , KC_GRV , KC_EQL , KC_MINS, KC_QUOT,                      KC_BSLS, KC_LPRN, KC_RPRN, KC_PIPE, KC_ENT , _______,
        _______, TO(4)  , KC_TILD, KC_PPLS, KC_UNDS, KC_DQUO, _______,    _______, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, TO(3)  , _______, 
                             _______, _______, TO(0)  , _______,                _______, TO(2)  , _______, _______),
	[_LAYERS_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR, KC_7   , KC_8   , KC_9   , KC_BSPC, _______, 
        _______, KC_TAB , XXXXXXX, KC_EQL , KC_MINS, XXXXXXX,                      KC_SLSH, KC_4   , KC_5   , KC_6   , KC_ENT , _______, 
        _______, TO(4)  , XXXXXXX, KC_PPLS, KC_UNDS, KC_DOT , _______,    _______, KC_0   , KC_1   , KC_2   , KC_3   , TO(3)  , _______, 
                             _______, _______, TO(0)  , KC_LALT,                _______, TO(2)  , _______, _______),
	[_LAYERS_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_ESC , XXXXXXX, KC_BTN3, KC_F24 , KC_ACL2,                      KC_PGUP, KC_HOME, KC_END , KC_DEL , KC_BSPC, XXXXXXX, 
        XXXXXXX, KC_TAB , KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL1,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , XXXXXXX, 
        XXXXXXX, TO(4)  , KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0, _______,    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, TO(3)  , XXXXXXX, 
                             _______, _______, TO(0)  , KC_LALT,                _______, TO(2)  , _______, _______),
	[_LAYERS_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_CAPS,                      KC_PSCR, RGB_HUD, RGB_HUI, KC_MNXT, KC_VOLU,  XXXXXXX, 
        XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_BRIU,                      RGB_TOG, RGB_SAD, RGB_SAI, KC_MPLY, KC_MUTE,  XXXXXXX, 
        XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_BRID, _______,    _______, RGB_MOD, RGB_VAD, RGB_VAI, KC_MPRV, KC_VOLD,  XXXXXXX, 
                             _______, _______, TO(0)  , _______,                _______, TO(2)  , _______, _______),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise)
{
    switch (index) { 
        case _ENCODER_LEFT: {
            switch (get_highest_layer(layer_state)) {
                default:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
            }
            break;
        }
        case _ENCODER_RIGHT: {
            switch (get_highest_layer(layer_state)) {
                default:
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    break;
            }
            break;
        }
        default: {
            break;
        }
    }

    return false;
}
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void)
{
    if (is_keyboard_master() == false) {
        return;
    }
    rgblight_enable_noeeprom(); // enables RGB, without saving settings
    //rgblight_sethsv_noeeprom(RGBLIGHT_HUE_STEP * 0, RGBLIGHT_SAT_STEP * 15, RGBLIGHT_VAL_STEP * 5); // set H,S,V without saving (each arg is u8)
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 0); // set mode without saving, see feature_rgblight.md Effects and Animations for numbers
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYERS_FN:
            //rgblight_setrgb(RGB_BLUE); // can use this instead of below line to just flash a colour then go back to mode/animation
            rgblight_mode_noeeprom(RGBLIGHT_EFFECT_STATIC_GRADIENT + 0);
            break;
        default: // for any other layers, including the default layer
            rgblight_sethsv_noeeprom(RGBLIGHT_HUE_STEP * 0, RGBLIGHT_SAT_STEP * 15, RGBLIGHT_VAL_STEP * 5); // set H,S,V without saving (each arg is u8)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 0); // set mode without saving, see feature_rgblight.md Effects and Animations for numbers
            break;
    }
  return state;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void)
{
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall

    bool is_left = is_keyboard_left();
    bool is_master = is_keyboard_master();
    uint8_t current_layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();

    // Keys display
    oled_write_P(PSTR("-----"), false);
    switch (current_layer) {
        case _LAYERS_HOME:          oled_write_P(is_left ? PSTR("qwertasdfgzxcvb   C^")  : PSTR("yuiophjkl;nm,./S1   "), false); break;
        case _LAYERS_SYMBOLS:       oled_write_P(is_left ? PSTR("e@#$%t`=-'4~+_\"   0^") : PSTR("^&*!b\\()|e[{}]3S2   "), false); break;
        case _LAYERS_NUM:           oled_write_P(is_left ? PSTR("e    t =- 4 +_.   0a")  : PSTR("*789b/456e01233S2   "), false); break;
        case _LAYERS_NAV:           oled_write_P(is_left ? PSTR("e MMMtMMMM4MMMM   0a")  : PSTR("PHEDbLDURePLDR3S2   "), false); break;
        case _LAYERS_FN:            oled_write_P(is_left ? PSTR("FFFFcFFFFbFFFFb   0 ")  : PSTR("pLLMMLLLMMLLLMMS2   "), false); break;
        default:
            oled_write_P(PSTR("UNKNW"), false);
            break;
    }
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("     "), false);

    // Indicators (Numlock / Capslock / Screenlock / etc.)
    oled_write_P(led_state.num_lock ? PSTR(" NUM ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR(" CAP ") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR(" SCR ") : PSTR("     "), false);
    oled_write_P(PSTR("     "), false);

    // Info
    oled_write_P(PSTR("-----"), false);
    switch (current_layer) {
        case _LAYERS_HOME:          oled_write_P(PSTR("HOME "), false); break;
        case _LAYERS_SYMBOLS:       oled_write_P(PSTR("SYMS "), false); break;
        case _LAYERS_NUM:           oled_write_P(PSTR("NUM  "), false); break;
        case _LAYERS_NAV:           oled_write_P(PSTR("NAV  "), false); break;
        case _LAYERS_FN:            oled_write_P(PSTR("FN MD"), false); break;
        default:
            oled_write_P(PSTR("UNKNW"), false);
            break;
    }
    oled_write_P(is_master ? PSTR("HOST      ") : PSTR("nHOST     "), false);
    oled_write_P(is_left ? PSTR("<<===") : PSTR("===>>"), false);

    // commented for space
    //char rgb_mode_str[6] = {0};
    //sprintf(rgb_mode_str, "m %03d", rgblight_get_mode());
    //oled_write(rgb_mode_str, false);

    return false;
}
#endif

// // chords (combos)
// const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_ent[] = {HOME_L, HOME_SC, COMBO_END};
// const uint16_t PROGMEM combo_bcps[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_layer3_enter[] = {KC_U, KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM combo_layer3_exit[] = {KC_BRIU, KC_BTN3, KC_F24, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(combo_esc, KC_ESC),
//     COMBO(combo_ent, KC_ENT),
//     COMBO(combo_bcps, KC_BSPC),
//     COMBO(combo_layer3_enter, TG(_LAYERS_NAV)),
//     COMBO(combo_layer3_exit, TO(_LAYERS_HOME)),
// };

// tap dance
typedef enum {
    TD_SINGLE_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_MORE_TAPS,
} td_state_t;
typedef struct {
    bool is_press_action;
    td_state_t state;
} tap;
static tap dance_state = {
    .is_press_action = true,
    .state = TD_SINGLE_NONE
};
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
		else if (state->pressed) return TD_DOUBLE_HOLD;
		else return TD_DOUBLE_TAP;
	}
    return TD_MORE_TAPS;
}
void _01_on_press(tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
	}
	else if (state->count > 3) {
		tap_code16(KC_DOT);
	}
}
void _01_finished(tap_dance_state_t *state, void *user_data) {
	dance_state.state = cur_dance(state);
	switch (dance_state.state) {
		case TD_SINGLE_TAP: register_code16(KC_DOT); break;
		case TD_SINGLE_HOLD: register_code16(KC_EXLM); break;
		case TD_DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
		case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
        default: break;
	}
}
void _01_reset(tap_dance_state_t *state, void *user_data) {
	switch (dance_state.state) {
		case TD_SINGLE_TAP: unregister_code16(KC_DOT); break;
		case TD_SINGLE_HOLD: unregister_code16(KC_EXLM); break;
		case TD_DOUBLE_TAP: unregister_code16(KC_DOT); break;
		case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
        default: break;
	}
	dance_state.state = TD_SINGLE_NONE;
}
void _02_on_press(tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
	}
	else if (state->count > 3) {
		tap_code16(KC_COMM);
	}
}
void _02_finished(tap_dance_state_t *state, void *user_data) {
	dance_state.state = cur_dance(state);
	switch (dance_state.state) {
		case TD_SINGLE_TAP: register_code16(KC_COMM); break;
		case TD_SINGLE_HOLD: register_code16(KC_MINS); break;
		case TD_DOUBLE_TAP: register_code16(KC_COMM); register_code16(KC_COMM); break;
		case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_COMM); register_code16(KC_COMM);
        default: break;
	}
}
void _02_reset(tap_dance_state_t *state, void *user_data) {
	switch (dance_state.state) {
		case TD_SINGLE_TAP: unregister_code16(KC_COMM); break;
		case TD_SINGLE_HOLD: unregister_code16(KC_MINS); break;
		case TD_DOUBLE_TAP: unregister_code16(KC_COMM); break;
		case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_COMM); break;
        default: break;
	}
	dance_state.state = TD_SINGLE_NONE;
}
void _03_on_press(tap_dance_state_t *state, void *user_data) {
	if (state->count == 3) {
		tap_code16(KC_SLSH);
		tap_code16(KC_SLSH);
		tap_code16(KC_SLSH);
	}
	else if (state->count > 3) {
		tap_code16(KC_SLSH);
	}
}
void _03_finished(tap_dance_state_t *state, void *user_data) {
	dance_state.state = cur_dance(state);
	switch (dance_state.state) {
		case TD_SINGLE_TAP: register_code16(KC_SLSH); break;
		case TD_SINGLE_HOLD: register_code16(KC_UNDS); break;
		case TD_DOUBLE_TAP: register_code16(KC_SLSH); register_code16(KC_SLSH); break;
		case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_SLSH); register_code16(KC_SLSH);
        default: break;
	}
}
void _03_reset(tap_dance_state_t *state, void *user_data) {
	switch (dance_state.state) {
		case TD_SINGLE_TAP: unregister_code16(KC_SLSH); break;
		case TD_SINGLE_HOLD: unregister_code16(KC_UNDS); break;
		case TD_DOUBLE_TAP: unregister_code16(KC_SLSH); break;
		case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_SLSH); break;
        default: break;
	}
	dance_state.state = TD_SINGLE_NONE;
}
tap_dance_action_t tap_dance_actions[] = {
    [_DANCE_01] = ACTION_TAP_DANCE_FN_ADVANCED(_01_on_press, _01_finished, _01_reset),
    [_DANCE_02] = ACTION_TAP_DANCE_FN_ADVANCED(_02_on_press, _02_finished, _02_reset),
    [_DANCE_03] = ACTION_TAP_DANCE_FN_ADVANCED(_03_on_press, _03_finished, _03_reset),
};