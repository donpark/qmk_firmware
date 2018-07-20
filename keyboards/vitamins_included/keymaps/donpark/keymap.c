#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _POK3R 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  POK3R,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define __LOWER    TT(_LOWER)
#define __RAISE    TT(_RAISE)
#define __POK3R    TT(_POK3R)
#define __LSFT     KC_LSFT
#define __ENTER    MT(MOD_RSFT, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T   },
  { __POK3R, KC_A,    KC_S,    KC_D,    KC_F,    KC_G   },
  { __LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B   },
  { KC_ESC,  KC_LALT, KC_LGUI, KC_LCTL, LOWER,   KC_SPC },
  { KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
  { KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, __ENTER },
  { KC_SPC,  RAISE,   KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |RESET |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC },
  { _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5   },
  { RESET,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
  { _______, _______, _______, _______, _______, KC_BSPC },
  { KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  { KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE },
  { KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______ },
  { KC_BSPC, _______, KC_HOME,    KC_PGDN, KC_PGUP, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |RESET |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 },
  { _______, _______, _______, _______, _______, _______},
  { KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  { KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
  { KC_F12,  KC_NUHS, KC_NUBS, _______, _______, RESET },
  { _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},

[_POK3R] = {
  { _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T   },
  { _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G   },
  { _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B   },
  { _______, _______, _______, _______, _______, _______},
  { KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_END,  KC_BSPC },
  { KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_ENTER },
  { KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______  },
  { _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |RGB_MOD|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  { _______, RESET,   _______, _______, _______, _______ },
  { _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM },
  { _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, KC_DEL },
  { AG_SWAP, QWERTY,  _______, _______,  _______, _______ },
  { _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, RGB_MOD }
}


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case POK3R:
      if (record->event.pressed) {
        layer_on(_POK3R);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_POK3R);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
