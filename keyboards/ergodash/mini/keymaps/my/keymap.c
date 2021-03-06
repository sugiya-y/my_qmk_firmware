#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Cmd  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Ctrl |   Z  |   X  |   C  |   V  |   B  | Space|                    | Tab  |   N  |   M  |   ,  |   .  |   /  |  \   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Optn | Esc  |   `  | Optn |||||||| Lower| Space|Shift |||||||| Enter| Tab  | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LGUI,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_TAB , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
    KC_LALT,  KC_ESC,  KC_GRV,  KC_LALT,          LOWER,   KC_SPC , KC_LSFT,       KC_ENT, KC_TAB , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  | del  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Cmd  |   1  |   2  |   3  |   4  |   5  |   {  |                    |   }  |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |      |      |      |      | Space|                    | Tab  |      |      |      |      |      |  |   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Optn | Esc  |  `   | Optn |||||||| Lower| Space|Shift |||||||| Enter| Tab  | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( \
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_LCBR,                        KC_RCBR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, \
    _______, _______, _______, _______,           LOWER,   _______, _______,      _______, _______, RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | Esc  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  | Bspc |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * | Cmd  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  |   F6 |   F7 |   F8 |   F9 |  F10 |      |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Ctrl |      |      |      |      |  F11 | Space|                    | Tab  | F12  |      |      |      |      |  |   |
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Optn | Esc  |  `   | Optn |||||||| Lower| Space|Shift |||||||| Enter| Tab  | Raise|||||||| Home |PageDn|PageUp|  End |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT( \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  _______,                        _______, KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, \
    _______, _______, _______, _______,          LOWER,   _______, _______,      _______, _______, RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT( \
    XXXXXXX, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,XXXXXXX,                       XXXXXXX, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
