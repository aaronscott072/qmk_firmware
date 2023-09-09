// Keycodes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
// Encoders: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
// RGB control: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
// OLED: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md
// Split keyboard features: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md

#include QMK_KEYBOARD_H

#include <stdio.h>

// Left-hand home row mods
#define HOME_A     LGUI_T(KC_A)
#define HOME_S     LALT_T(KC_S)
#define HOME_D     LSFT_T(KC_D)
#define HOME_F     LCTL_T(KC_F)
// Right-hand home row mods
#define HOME_J     RCTL_T(KC_J)
#define HOME_K     RSFT_T(KC_K)
#define HOME_L     LALT_T(KC_L)
#define HOME_SC    RGUI_T(KC_SCLN)

typedef enum {
    _LAYERS_HOME = 0,
    _LAYERS_SYMBOLS,
    _LAYERS_NUM_AND_NAV,
    _LAYERS_CONTROLS
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
                             KC_LGUI, KC_LALT, MO(1)  , KC_SPC ,                KC_SPC , MO(2)  , QK_REP , KC_DEL ),
	[_LAYERS_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
        _______, KC_TAB , KC_GRV , KC_TILD, KC_BSLS, KC_PIPE,                      KC_QUOT, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______,
        _______, XXXXXXX, KC_TILD, XXXXXXX, KC_PIPE, XXXXXXX, _______,    _______, KC_DQUO, KC_UNDS, KC_PPLS, KC_LCBR, KC_RCBR, _______, 
                             _______, _______, _______, _______,                _______, MO(3)  , _______, _______),
	[_LAYERS_NUM_AND_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, 
        _______, KC_TAB , XXXXXXX, KC_HOME, KC_PGUP, KC_DEL ,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______, 
        _______, XXXXXXX, XXXXXXX, KC_END , KC_PGDN, KC_DEL , _______,    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, 
                             _______, _______, MO(3)  , _______,                _______, _______, _______, _______),
	[_LAYERS_CONTROLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,                      KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_PSCR, KC_PSCR, 
        KC_CAPS, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_BRIU,                      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_BRID, _______,    _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, 
                             _______, _______, _______, _______,                _______, _______, _______, _______)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise)
{
    switch (index) {
        case _ENCODER_LEFT: {
            switch (get_highest_layer(layer_state)) {
                case _LAYERS_HOME:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
                case _LAYERS_SYMBOLS:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
                case _LAYERS_NUM_AND_NAV:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
                case _LAYERS_CONTROLS:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
                default:
                    break;
            }
            break;
        }
        case _ENCODER_RIGHT: {
            switch (get_highest_layer(layer_state)) {
                case _LAYERS_HOME:
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    break;
                case _LAYERS_SYMBOLS:
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    break;
                case _LAYERS_NUM_AND_NAV:
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    break;
                case _LAYERS_CONTROLS:
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    break;
                default:
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
    rgblight_sethsv_noeeprom(RGBLIGHT_HUE_STEP * 0, RGBLIGHT_SAT_STEP * 15, RGBLIGHT_VAL_STEP * 5); // set H,S,V without saving (each arg is u8)
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 0); // set mode without saving, see feature_rgblight.md Effects and Animations for numbers
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
        case _LAYERS_NUM_AND_NAV: oled_write_P(is_left ? PSTR("     12345T HPD  EPD")  : PSTR("     67890LDUR  LDR "), false); break;
        case _LAYERS_CONTROLS:    oled_write_P(is_left ? PSTR("     FFFF FFFFBFFFFB")  : PSTR("MMM  VVV PLLLL LLLL "), false); break;
        default:
            oled_write_ln_P(PSTR("UNKNW"), false); // Or use the write_ln shortcut over adding '\n' to the end of your string
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
        default:
            oled_write_P(PSTR("UNKNW"), false);
            break;
    }
    oled_write_P(is_master ? PSTR("HOST ") : PSTR("nHOST"), false);
    oled_write_P(is_left ? PSTR("<<===") : PSTR("===>>"), false);

    char rgb_mode_str[6] = {0};
    sprintf(rgb_mode_str, "m %03d", rgblight_get_mode());
    oled_write(rgb_mode_str, false);

    return false;
}
#endif