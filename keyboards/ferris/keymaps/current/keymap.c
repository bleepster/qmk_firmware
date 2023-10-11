#include QMK_KEYBOARD_H

#include "color.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_ESC, KC_W, LT(4,KC_E), KC_R, LT(3,KC_T), LT(3,KC_Y), KC_U, KC_I, KC_O, KC_BSPC, MT(MOD_LGUI,KC_A), MT(MOD_LSFT,KC_S), MT(MOD_LCTL,KC_D), MT(MOD_LALT,KC_F), LT(2,KC_G), LT(2,KC_H), MT(MOD_LALT | MOD_RALT,KC_J), MT(MOD_LCTL | MOD_RCTL,KC_K), MT(MOD_LSFT | MOD_RSFT,KC_L), MT(MOD_LGUI,KC_P), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_Q, KC_COMM, KC_DOT, KC_TAB, LT(1,KC_ENT), LT(1,KC_SPC), TO(1)),
  [1] = LAYOUT(KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_COLN, KC_EQL, KC_BSLS, KC_SLSH, KC_MINS, KC_QUOT, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC, KC_LT, KC_GT, KC_RBRC, KC_RCBR, KC_RPRN, KC_GRV, TO(0), KC_TRNS, KC_TRNS, TO(2)),
  [2] = LAYOUT(KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_CAPS, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, TO(3)),
  [3] = LAYOUT(KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_NO, TO(2), KC_TRNS, KC_TRNS, TO(4)),
  [4] = LAYOUT(KC_NO, KC_BTN1, KC_NO, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), KC_TRNS, KC_TRNS, TO(0))
};

void housekeeping_task_user(void) {
  if (is_keyboard_master()) {
    static uint32_t timer = 0;
    static HSV color = { .h = 0, .s = 255, .v = 255 };

    if (timer_elapsed32(timer) < 400)
        return;

    timer = timer_read32();

    // increase hue -> change color
    color.h++;

    RGB rgb = hsv_to_rgb(color);
    pimoroni_trackball_set_rgbw(rgb.r, rgb.g, rgb.b, 0);
  }
}

