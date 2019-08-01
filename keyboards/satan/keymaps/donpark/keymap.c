#include QMK_KEYBOARD_H
#include "action_layer.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RL 2

#define _______ KC_TRNS

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT_60_ansi_split_bs_rshift(
  KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,   KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT), MO(_RL), \
  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RALT, KC_PGDN, KC_PGUP, KC_RCTL \
  ),

[_FL] = LAYOUT_60_ansi_split_bs_rshift(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS,  KC_UP,   KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_APP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN,  KC_HOME, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

[_RL] = LAYOUT_60_ansi_split_bs_rshift(
  KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_INC,  KC_TRNS, \
  KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  )
};

/*
enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
*/