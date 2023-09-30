#pragma once

// TT(layer) - Layer Tap-Toggle
//#define TAPPING_TOGGLE 5 // keymap.c example use: TT(1)

//// Configure the global tapping term (default: 200ms)
//#define TAPPING_TERM 200
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat
////#define QUICK_TAP_TERM 100 // max = TAPPING_TERM, 0 is optimal for home row mods but disallows double tap for layer toggle (see TAPPING_TOGGLE)
#define QUICK_TAP_TERM 0 // max = TAPPING_TERM, 0 is optimal for home row mods but disallows double tap for layer toggle (see TAPPING_TOGGLE)

// copied from https://github.com/benvallack/34-QMK-Ferris-Sweep/blob/main/config.h
#define TAPPING_TERM 240
// COMMENTING OUT BELOW TO TRY EACH INDIVIDUALLY, MAY WANT TO TRY QUICK_TAP_TERM??
// #define TAPPING_FORCE_HOLD
// #define RETRO_TAPPING
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY 5
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL 16
// #undef MOUSEKEY_MOVE_DELTA
// #define MOUSEKEY_MOVE_DELTA 1
// #undef MOUSEKEY_INITIAL_SPEED 
// #define MOUSEKEY_INITIAL_SPEED 1
// #undef MOUSEKEY_DECELERATED_SPEED
// #define MOUSEKEY_DECELERATED_SPEED 12
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED 22
// #define USB_SUSPEND_WAKEUP_DELAY 0
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 83
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 83
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #define MOUSEKEY_WHEEL_MAX_SPEED 3

// Encoder
#define ENCODER_RESOLUTION 2

// RGBLIGHT
// Info: feature_rgblight.md
#ifdef RGBLIGHT_ENABLE
//// Configuration
//#define RGBLIGHT_SAT_STEP 	        17 	                        // The number of steps to increment the saturation by
//#define RGBLIGHT_VAL_STEP 	        17 	                        // The number of steps to increment the brightness by
//#define RGBLIGHT_HUE_STEP 	        8 	                        // The number of steps to cycle through the hue by
//#define RGBLIGHT_LIMIT_VAL 	        255 	                    // The maximum brightness level
#define RGBLIGHT_SLEEP 	 	                                    // If defined, the RGB lighting will be switched off when the host goes to sleep
#define RGBLIGHT_SPLIT 	 	                                    // If defined, synchronization functionality for split keyboards is added
//#define RGBLIGHT_DISABLE_KEYCODES 	                            // If defined, disables the ability to control RGB Light from the keycodes. You must use code functions to control the feature
#define RGBLIGHT_DEFAULT_MODE 	    RGBLIGHT_MODE_STATIC_LIGHT 	// The default mode to use upon clearing the EEPROM
//#define RGBLIGHT_DEFAULT_HUE 	    0  	                        // The default hue to use upon clearing the EEPROM
//#define RGBLIGHT_DEFAULT_SAT 	    UINT8_MAX  	                // The default saturation to use upon clearing the EEPROM
//#define RGBLIGHT_DEFAULT_VAL 	    RGBLIGHT_LIMIT_VAL 	        // The default value (brightness) to use upon clearing the EEPROM
//#define RGBLIGHT_DEFAULT_SPD 	    0 	                        // The default speed to use upon clearing the EEPROM

//// Effect and Animation Toggles
//#define RGBLIGHT_EFFECT_ALTERNATING         // Enable alternating animation mode.
//#define RGBLIGHT_EFFECT_BREATHING           // Enable breathing animation mode.
//#define RGBLIGHT_EFFECT_CHRISTMAS           // Enable christmas animation mode.
//#define RGBLIGHT_EFFECT_KNIGHT              // Enable knight animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_MOOD        // Enable rainbow mood animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL       // Enable rainbow swirl animation mode.
//#define RGBLIGHT_EFFECT_RGB_TEST            // Enable RGB test animation mode.
//#define RGBLIGHT_EFFECT_SNAKE               // Enable snake animation mode.
#define RGBLIGHT_EFFECT_STATIC_GRADIENT     // Enable static gradient mode.
//#define RGBLIGHT_EFFECT_TWINKLE             // Enable twinkle animation mode.

//// Also see "Effect and Animation Settings" and "Animation Speed"
#endif

// OLED
#ifdef OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE    // This enables syncing of the layer state between both halves
#define SPLIT_LED_STATE_ENABLE      // This enables syncing of the Host LED status (caps lock, num lock, etc) between both halves
#endif