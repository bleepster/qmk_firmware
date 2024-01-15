#include QMK_KEYBOARD_H

#include "color.h"

// mod tap, layer tap definitions - start
//
// left half mod tap
#define LH_1 MT(MOD_LGUI, KC_A)
#define LH_2 MT(MOD_LSFT, KC_S)
#define LH_3 MT(MOD_LCTL, KC_D)
#define LH_4 MT(MOD_LALT, KC_F)
#define LH_5 HYPR_T(KC_TAB)
// right half mod tap
#define RH_1 MT(MOD_RALT, KC_J)
#define RH_2 MT(MOD_RCTL, KC_K)
#define RH_3 MT(MOD_RSFT, KC_L)
#define RH_4 MT(MOD_LGUI, KC_P)
#define RH_5 MEH_T(KC_DEL)
// left half - layer 3 tap and layer 4 tap
#define LT_3T LT(3, KC_T)
#define LT_4C LT(4, KC_C)
// right half - layer 3 tap and layer 4 tap
#define RT_3Y LT(3, KC_Y)
#define RT_4Q LT(4, KC_Q)
// left half - layer 2 tap
#define LT_2G LT(2, KC_G)
// right half - layer 2 tap
#define RT_2H LT(2, KC_H)
// left half - layer 1 tap
#define LT_1ENT LT(1, KC_ENT)
// right half - layer 1 tap
#define RT_1SPC LT(1, KC_SPC)
// mod tap, layer tap defininitions - end

#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// add drag/scroll key
enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC, KC_W,  KC_E,  KC_R, LT_3T,        RT_3Y, KC_U, KC_I,  KC_O,    KC_BSPC,
      LH_1, LH_2,  LH_3,  LH_4, LT_2G,        RT_2H, RH_1, RH_2,  RH_3,    RH_4,
      KC_Z, KC_X, LT_4C,  KC_V,  KC_B,        KC_N,  KC_M, RT_4Q, KC_COMM, KC_DOT,
                        LH_5, LT_1ENT,        RT_1SPC, RH_5
  ),
  [1] = LAYOUT(
    KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_COLN,
     KC_EQL, KC_BSLS, KC_SLSH, KC_MINS, KC_QUOT,        KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN,
    KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT,        KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN,  KC_GRV,
                               KC_TRNS, KC_TRNS,        LCTL(KC_LSFT), LALT(KC_LSFT)
  ),
  [2] = LAYOUT(
    KC_NO, KC_7, KC_8, KC_9, KC_NO,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
    KC_NO, KC_4, KC_5, KC_6, KC_NO,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
     KC_0, KC_1, KC_2, KC_3, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
      LGUI(KC_LSFT), LGUI(KC_LCTL),        LCTL(KC_LSFT), LALT(KC_LSFT)
  ),
  [3] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,        KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,        KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_NO,
                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO,       QK_BOOT,
    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO,
      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, DRAG_SCROLL, KC_NO,
                             KC_BTN2, KC_BTN1,        KC_NO, KC_NO
  )
};

// RGB for pimoroni module
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

// required for automouse layer
void pointing_device_init_user(void) {
  set_auto_mouse_layer(4);
  set_auto_mouse_enable(true);
}

// drag/scroll toggle functions
// https://docs.qmk.fm/#/feature_pointing_device?id=advanced-drag-scroll
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  if (set_scrolling) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == DRAG_SCROLL && record->event.pressed) {
    set_scrolling = !set_scrolling;
  }
  return true;
}

// drag/scroll toggle functions - end
