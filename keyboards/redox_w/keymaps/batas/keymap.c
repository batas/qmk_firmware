#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
	    LT(2,KC_GRV), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(2,KC_MINS), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, MO(1), MO(1), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(3,KC_PGUP), KC_PGDN, KC_HOME, LT(3,KC_END), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, LCTL_T(KC_PPLS), KC_PMNS, LALT_T(KC_PAST), KC_BSLS, KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),
	[_SYMB] = LAYOUT(
	    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_TRNS, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, KC_TRNS, KC_TRNS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_TRNS, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_PENT, KC_NO
    ),
	[_NAV] = LAYOUT(
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_WH_U, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_F13, KC_MPLY, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    ),
	[_ADJUST] = LAYOUT(
	    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            grn_led_on;
            blu_led_off;
            red_led_off;
            break;
        case _NAV:
            grn_led_on;
            blu_led_on;
            red_led_off;
            break;
        case _ADJUST:
            grn_led_on;
            blu_led_on;
            red_led_on;
            break;
        default:
            break;
    }
  return state;
}


