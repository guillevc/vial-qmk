/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#define RGB_DKRED 0x28, 0x00, 0x00

enum custom_layers {
    _WIN,
    _MACOS,
    _FN,
    _BLANK,
};

enum custom_keycodes {
    CAF11 = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [_WIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           CAF11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MACOS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        _______, _______,  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, RGB_TOG,  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           _______,
        _______, _______,  RGB_VAI,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,
        _______, _______,  RGB_VAD,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______,  _______,    RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_MOD,  _______,
        _______, DF(_WIN), DF(_MACOS),                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

   [_BLANK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    )

};
// clang-format on

// Enable ENCODER_MAP_ENABLE to use
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_WIN]   = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
//     [_MACOS] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
//     [_FN]    = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
//     [_BLANK] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
// };

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CAF11:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F11))));
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        rgb_matrix_set_color_all(RGB_DKRED);
    }
    return false;
}

void encoder_action_hue(uint8_t clockwise) {
    if (clockwise) {
        rgblight_increase_hue_noeeprom();
    } else {
        rgblight_decrease_hue_noeeprom();
    }
}

void encoder_action_sat(uint8_t clockwise) {
    if (clockwise) {
        rgblight_increase_sat_noeeprom();
    } else {
        rgblight_decrease_sat_noeeprom();
    }
}

void encoder_action_val(uint8_t clockwise) {
    if (clockwise) {
        rgblight_increase_val_noeeprom();
    } else {
        rgblight_decrease_val_noeeprom();
    }
}

void encoder_action_volume(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    if (layer_state_is (_FN)) {
        encoder_action_hue(clockwise);
    } else if (mods_state & MOD_BIT(KC_RCTL)) {
        encoder_action_sat(clockwise);
    } else if (mods_state & MOD_BIT(KC_RALT)) {
        encoder_action_val(clockwise);
    } else {
        encoder_action_volume(clockwise);
    }
    return false;
}
