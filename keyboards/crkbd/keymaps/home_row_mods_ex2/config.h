/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C


#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM 80
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_SFT 125

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
// #define SPLIT_MODS_ENABLE
// #define SPLIT_WPM_ENABLE
// #define SPLIT_OLED_ENABLE
// #define SPLIT_POINTING_ENABLE
#define SPLIT_ACTIVITY_ENABLE

#define TIMEOUT 300000

#ifdef MOUSEKEY_ENABLE
#define MK_3_SPEED

#define MK_C_OFFSET_0 4
#define MK_C_INTERVAL_0 16

#define MK_C_OFFSET_1 8
#define MK_C_INTERVAL_1 16

#define MK_C_OFFSET_2 16
#define MK_C_INTERVAL_2 16

#define MK_W_OFFSET_0 1
#define MK_W_INTERVAL_0 360

#define MK_W_OFFSET_1 1
#define MK_W_INTERVAL_1 360

#define MK_W_OFFSET_2 1
#define MK_W_INTERVAL_2 360
#endif

#ifdef RGB_MATRIX_ENABLE
// #define RGB_MATRIX_KEYRELEASES // reactive effects respond to keyreleases (instead of keypresses)
#define RGB_MATRIX_TIMEOUT TIMEOUT // number of milliseconds to wait until rgb automatically turns off
#define RGB_MATRIX_SLEEP // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN // Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 164 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 95 // Sets the default animation speed, if none has been set
#define RGB_MATRIX_HUE_STEP 8 // The value by which to increment the hue per adjustment action
#define RGB_MATRIX_SAT_STEP 16 // The value by which to increment the saturation per adjustment action
#define RGB_MATRIX_VAL_STEP 16 // The value by which to increment the brightness per adjustment action
#define RGB_MATRIX_SPD_STEP 16 // The value by which to increment the animation speed per adjustment action
// #define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL // Sets the default LED flags, if none has been set
// #define RGB_MATRIX_SPLIT { X, Y } 	// (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
//                                         // If reactive effects are enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
// #define RGB_TRIGGER_ON_KEYDOWN      // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
#endif
