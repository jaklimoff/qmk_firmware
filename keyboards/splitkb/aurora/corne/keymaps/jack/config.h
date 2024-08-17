/*
Copyright 2022 x123 <@x123>
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


#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define TAPPING_TOGGLE 1
// Maximum time between taps of tap dances
#define TAPPING_TERM 280
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX

#define MASTER_LEFT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define COMBO_COUNT 2
//#define IGNORE_MOD_TAP_INTERRUPT true

//#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LAYERS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

//#endif
//#define ENABLE_LED_MATRIX_WAVE_LEFT_RIGHT
// #define RGBLIGHT_DEFAULT_HUE 169
// #define RGBLIGHT_LAYERS
//#define RGBLIGHT_EFFECT_RGB_TEST
