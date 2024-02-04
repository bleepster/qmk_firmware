#include QMK_KEYBOARD_H

#include "color.h"

// mod tap, layer tap definitions - start
//

// left half mod tap (layer 1)
#define LH1_1 MT(MOD_LGUI, KC_A)
#define LH1_2 MT(MOD_LSFT, KC_S)
#define LH1_3 MT(MOD_LCTL, KC_D)
#define LH1_4 MT(MOD_LALT, KC_F)
#define LH_5 HYPR_T(KC_TAB)

// left half mod tap (layer 2)
#define LH2_1 MT(MOD_LGUI, KC_EQL)
#define LH2_2 MT(MOD_LSFT, KC_BSLS)
#define LH2_3 MT(MOD_LCTL, KC_SLSH)
#define LH2_4 MT(MOD_LALT, KC_MINS)

// left half mod tap (layer 3)
#define LH3_1 MT(MOD_LSFT, KC_4)
#define LH3_2 MT(MOD_LCTL, KC_5)
#define LH3_3 MT(MOD_LALT, KC_6)

// left half mod tap (layer 4)
#define LH4_1 MT(MOD_LGUI, KC_F11)
#define LH4_2 MT(MOD_LSFT, KC_F4)
#define LH4_3 MT(MOD_LCTL, KC_F5)
#define LH4_4 MT(MOD_LALT, KC_F6)

// right half mod tap (layer 1)
#define RH1_1 MT(MOD_RALT, KC_J)
#define RH1_2 MT(MOD_RCTL, KC_K)
#define RH1_3 MT(MOD_RSFT, KC_L)
#define RH1_4 MT(MOD_LGUI, KC_P)
#define RH_5 MEH_T(KC_DEL)

// right half mod tap (layer 2)
#define RH2_1 MT(MOD_RALT, KC_CIRC)
#define RH2_2 MT(MOD_RCTL, KC_AMPR)
#define RH2_3 MT(MOD_RSFT, KC_ASTR)
#define RH2_4 MT(MOD_LGUI, KC_SCLN)

// right half mod tap (layer 3)
#define RH3_1 MT(MOD_RALT, KC_DOWN)
#define RH3_2 MT(MOD_RCTL, KC_UP)
#define RH3_3 MT(MOD_RSFT, KC_RIGHT)

// right half mod tap (layer 4)
#define RH4_1 MT(MOD_RALT, KC_VOLD)
#define RH4_2 MT(MOD_RCTL, KC_VOLU)

// left half - layer 3 tap
#define LT_3T LT(3, KC_T)

// right half - layer 3 tap
#define RT_3Y LT(3, KC_Y)

// left half - layer 2 tap
#define LT_2G LT(2, KC_G)

// right half - layer 2 tap
#define RT_2H LT(2, KC_H)

// left half - layer 1 tap
#define LT_1ENT LT(1, KC_ENT)

// right half - layer 1 tap
#define RT_1SPC LT(1, KC_SPC)

// left control + left shift
#define CTRLSHFT LCTL(KC_LSFT)

// left OS + left shift
#define OSSHFT LGUI(KC_LSFT)

// left alt + left shift
#define ALTSHFT LALT(KC_LSFT)

// left OS + left ctrl
#define OSCTRL LGUI(KC_LCTL)

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
    MO(4),  KC_W,   KC_E,   KC_R, LT_3T,        RT_3Y, KC_U,  KC_I,  KC_O,    MO(4),
    LH1_1, LH1_2,  LH1_3,  LH1_4, LT_2G,        RT_2H, RH1_1, RH1_2, RH1_3,   RH1_4,
     KC_Z,  KC_X,   KC_C,   KC_V,  KC_B,        KC_N,  KC_M,  KC_Q,  KC_COMM, KC_DOT,
                          LH_5, LT_1ENT,        RT_1SPC, RH_5
  ),
  [1] = LAYOUT(
    KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_COLN,
      LH2_1,   LH2_2,   LH2_3,   LH2_4, KC_QUOT,        KC_PERC, RH2_1,   RH2_2,   RH2_3,   RH2_4,
    KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT,        KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_GRV,
                               KC_TRNS, KC_TRNS,        CTRLSHFT, ALTSHFT
  ),
  [2] = LAYOUT(
      KC_NO,  KC_7,  KC_8,  KC_9, KC_NO,        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
    KC_LGUI, LH3_1, LH3_2, LH3_3, KC_NO,        KC_LEFT, RH3_1,   RH3_2,   RH3_3,  KC_RGUI,
       KC_0,  KC_1,  KC_2,  KC_3, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                         OSSHFT, OSCTRL,        CTRLSHFT, ALTSHFT
  ),
  [3] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     LH4_1, LH4_2, LH4_3, LH4_4, KC_NO,        KC_MUTE, RH4_1,   RH4_2,   KC_RSFT, KC_RGUI,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,        KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_NO,
                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT(
    KC_TRNS,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,       KC_NO, KC_TRNS,
    KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,        KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO,
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, DRAG_SCROLL, KC_NO, QK_BOOT,
                             KC_BTN2, KC_BTN1,        KC_NO, KC_NO
  )
};

// combos
const uint16_t PROGMEM combo_capslock[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_capslock, KC_CAPS),
    COMBO(combo_backspace, KC_BSPC),
    COMBO(combo_escape, KC_ESC)
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
