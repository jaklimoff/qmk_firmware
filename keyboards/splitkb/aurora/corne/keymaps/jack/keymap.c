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

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _FKEYS,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    FKEYS,
    LOWER,
    RAISE,
    ADJUST,
    FUNCTION
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_QWERTY] = LAYOUT_split_3x6_3(

     // ╭---------+---------+---------+---------+---------+---------╮ ╭---------+---------+---------+---------+---------+---------╮
          KC_GRV ,    KC_Q ,    KC_W ,    KC_E ,    KC_R ,    KC_T ,      KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
     // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
          KC_TAB ,  HOME_A ,  HOME_S ,  HOME_D ,  HOME_F ,    KC_G ,      KC_H ,  HOME_J ,  HOME_K ,  HOME_L ,HOME_SCLN, KC_QUOT ,
     // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         XXXXXXX ,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,      KC_N ,    KC_M , KC_COMM ,  KC_DOT , KC_SLSH , KC_BSLS ,
     // ╰---------+---------+---------+---------/---------/---------/ \---------\---------\---------+---------+---------+---------╯
                                       FUNCTION ,  LOWER,   KC_ENT ,     KC_SPC ,   RAISE,  KC_BSPC
     //                              /_________/_________/_________/   \_________\_________\_________\_

     ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, KC_A   , _______,                      KC_PAST, KC_F7   , KC_F8   , KC_F9   , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_PEQL, KC_F4   , KC_F5   , KC_F6   , KC_0   , KC_PDOT,
        _______, _______, _______, _______, _______, _______,                      KC_PSLS, KC_F1   , KC_F2   , KC_F3   , KC_MINUS, _______,
                                         _______, _______, _______,       KC_BSPC, ADJUST, KC_DEL
        ),

    [_FKEYS] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, KC_A   , _______,                      KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_PEQL, KC_4   , KC_5   , KC_6   , KC_0   , KC_PDOT,
        _______, _______, _______, _______, _______, _______,                      KC_PSLS, KC_U   , KC_2   , KC_3   , KC_MINUS, _______,
                                         _______, _______, _______,       KC_BSPC, ADJUST, KC_DEL
        ),

    [_GAMING] = LAYOUT_split_3x6_3(
        KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A ,   KC_S ,   KC_D   , KC_F ,   KC_G   ,                      KC_H   , KC_J ,   KC_K , KC_L , HOME_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
                                             KC_LCTL, KC_SPC, KC_ENT ,         KC_SPC , RAISE, KC_BSPC

        ),

    [_LOWER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, KC_A   , _______,                      KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_PEQL, KC_4   , KC_5   , KC_6   , KC_0   , KC_PDOT,
        _______, _______, _______, _______, _______, _______,                      KC_PSLS, KC_1   , KC_2   , KC_3   , KC_MINUS, _______,
                                         _______, _______, _______,       KC_BSPC, ADJUST, KC_DEL
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
        KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______,                      KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                        _______, ADJUST, KC_ESC,       _______, _______, _______
        ),

    [_ADJUST] = LAYOUT_split_3x6_3(
        RGB_TOG, RGB_MOD, RGB_M_R, RGB_HUI, RGB_SAI, RGB_VAI,                       KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, QWERTY, GAMING,
        RGB_MODE_PLAIN, RGB_MODE_BREATHE, XXXXXXX, RGB_M_R, RGB_M_P, RGB_HUI,                      KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______, _______,    _______, _______, _______
        )
};





// Define colors for each layer
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_BLUE}
//    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
//    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12

);
const rgblight_segment_t PROGMEM my_fkeys_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_RED}
);
const rgblight_segment_t PROGMEM my_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_fkeys_layer,
    my_gaming_layer,
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer,
    my_func_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FKEYS));
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUNCTION));
    return state;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // enables RGB, without saving settings
    rgblight_layers = my_rgb_layers;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            break;
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case FUNCTION:
            if (record->event.pressed) {
                layer_on(_FUNCTION);
            } else {
                layer_off(_FUNCTION);
            }
            return false;
        case FKEYS:
            if (record->event.pressed) {
                layer_on(_FKEYS);
            } else {
                layer_off(_FKEYS);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}
