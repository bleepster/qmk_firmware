#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_ESC,  KC_W,  KC_E,  KC_R, LT_3T,                  RY_3Y, KC_U,  KC_I,  KC_O,    KC_BSPC, KC_NO,
    KC_NO,   LH_1,  LH_2,  LH_3,  LH_4, LT_2G,                  RT_2H, RH_1,  RH_2,  RH_3,    RH_4,    KC_NO,
    KC_NO,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, TO(3),    KC_NO, KC_N,  KC_M,  KC_Q,  KC_COMM, KC_DOT,  KC_NO,
                                KC_NO, LH_5, LT1_ENT,    RT_1SPC, RH_5, KC_NO
  ),
  [1] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO,                    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_COLN, KC_NO,
    KC_NO, KC_EQL,  KC_BSLS, KC_SLSH, KC_MINS, KC_QUOT,                    KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_NO,
    KC_NO, KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT, KC_TRNS,    TO(0), KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_GRV,  KC_NO,
                                        KC_NO, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_NO
  ),
  [2] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_NO, KC_NO,  KC_7,  KC_8,  KC_9, KC_NO,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS, KC_NO,
    KC_NO, KC_NO,  KC_4,  KC_5,  KC_6, KC_NO,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
    KC_NO,  KC_0,  KC_1,  KC_2,  KC_3, KC_NO, KC_TRNS,    TO(0), KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   KC_NO,
                            KC_NO, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_NO

  ),
  [3] = LAYOUT(
      KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6,                   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_NO,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,  KC_NO, KC_NO,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC,    TO(0), KC_N,  KC_M,  KC_NO, KC_NO, KC_NO, KC_NO,
                           KC_DEL, KC_SPC, KC_ENT,    KC_TRNS, KC_TRNS, KC_TRNS

  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



