// Keycodes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
// Encoders: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
// RGB control: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
// OLED: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md
// Split keyboard features: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md

#include QMK_KEYBOARD_H

// commented for space
// #include <stdio.h>

// Left-hand home row mods
#define HOME_A     LGUI_T(KC_A)
#define HOME_S     LALT_T(KC_S)
#define HOME_D     LSFT_T(KC_D)
#define HOME_F     LCTL_T(KC_F)
// Right-hand home row mods
#define HOME_J     RCTL_T(KC_J)
#define HOME_K     RSFT_T(KC_K)
#define HOME_L     LALT_T(KC_L)
#define HOME_SC    KC_SCLN        // RGUI_T(KC_SCLN)

typedef enum {
    _LAYERS_HOME = 0,
    _LAYERS_SYMBOLS,
    _LAYERS_NUM_AND_NAV,
    _LAYERS_CONTROLS,
    _LAYERS_FN,
} layers_t;

typedef enum {
    _ENCODER_LEFT = 0,
    _ENCODER_RIGHT
} encoder_t;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	[_LAYERS_HOME] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, 
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, 
        KC_LCTL, HOME_A , HOME_S , HOME_D , HOME_F , KC_G   ,                      KC_H   , HOME_J , HOME_K , HOME_L , HOME_SC, KC_ENT , 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,    KC_PSCR, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, 
                             KC_LGUI, KC_LALT, MO(1)  , LT(4, KC_SPC),                KC_SPC , MO(2)  , KC_DEL , KC_DEL ),
	[_LAYERS_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
        _______, KC_TAB , KC_GRV , KC_TILD, KC_BSLS, KC_PIPE,                      KC_QUOT, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______,
        _______, XXXXXXX, KC_TILD, XXXXXXX, KC_PIPE, XXXXXXX, _______,    _______, KC_DQUO, KC_UNDS, KC_PPLS, KC_LCBR, KC_RCBR, _______, 
                             _______, _______, _______, _______,                _______, MO(3)  , _______, _______),
	[_LAYERS_NUM_AND_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, 
        _______, KC_TAB , XXXXXXX, KC_HOME, KC_PGUP, KC_DEL ,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , _______, 
        _______, XXXXXXX, XXXXXXX, KC_END , KC_PGDN, KC_DEL , _______,    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, 
                             _______, _______, MO(3)  , _______,                _______, _______, _______, _______),
	[_LAYERS_CONTROLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_PSCR, KC_MNXT, KC_VOLU, RGB_HUD, RGB_HUI,                      KC_BRID, KC_BRIU, KC_BTN3, KC_F24 , KC_ACL2, XXXXXXX, 
        XXXXXXX, KC_CAPS, KC_MPLY, KC_MUTE, RGB_SAD, RGB_SAI,                      RGB_TOG, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL1, XXXXXXX, 
        XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, RGB_VAD, RGB_VAI, _______,    _______, RGB_MOD, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0, XXXXXXX, 
                             _______, _______, _______, _______,                _______, _______, _______, _______),
	[_LAYERS_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                             _______, _______, _______, _______,                _______, _______, _______, _______),
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
        case _LAYERS_HOME:        oled_write_P(is_left ? PSTR("12345qwertasdfgzxcvb")  : PSTR("67890yuiophjkl;nm,./"), false); break;
        case _LAYERS_SYMBOLS:     oled_write_P(is_left ? PSTR("     !@#$%T`~\\| ~ | ") : PSTR("     ^&*()'-=[]\"_+{}"), false); break;
        case _LAYERS_NUM_AND_NAV: oled_write_P(is_left ? PSTR("     12345T HPD  EPD")  : PSTR("     67890LDURe LDR "), false); break;
        case _LAYERS_CONTROLS:    oled_write_P(is_left ? PSTR("     pMVRRcMVRR MVRR")  : PSTR("     bbM mRMMMmRMMMm"), false); break;
        case _LAYERS_FN:          oled_write_P(is_left ? PSTR("     FFFF FFFF FFFF ")  : PSTR("                    "), false); break;
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
        case _LAYERS_HOME:        oled_write_P(PSTR("HOME "), false); break;
        case _LAYERS_SYMBOLS:     oled_write_P(PSTR("SYMS "), false); break;
        case _LAYERS_NUM_AND_NAV: oled_write_P(PSTR("NM NV"), false); break;
        case _LAYERS_CONTROLS:    oled_write_P(PSTR("CTRLS"), false); break;
        case _LAYERS_FN:          oled_write_P(PSTR("FNKEY"), false); break;
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

// chords (combos)
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {HOME_L, HOME_SC, COMBO_END};
const uint16_t PROGMEM combo_bcps[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_layer3_enter[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_layer3_exit[] = {KC_BRIU, KC_BTN3, KC_F24, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_ent, KC_ENT),
    COMBO(combo_bcps, KC_BSPC),
    COMBO(combo_layer3_enter, TG(_LAYERS_CONTROLS)),
    COMBO(combo_layer3_exit, TO(_LAYERS_HOME)),
};