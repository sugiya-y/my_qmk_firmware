#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define FN 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   -  | BSPC |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | RCtl | LCmd |   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   '  |  \   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Optn | Ctrl |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  UP  |  FN  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Optn | LSft |   `  |   =  | SYMB |Space | RSft |   |Enter | META | SYMB | RCmd | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_ESC,   KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC, \
    KC_RCTL,  KC_LGUI, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,    KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, \
    KC_LALT,  KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,    KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   MO(FN), \
    KC_RALT,  KC_LSFT, KC_GRV, KC_EQL, MO(SYMB), KC_SPC,   KC_RSFT, KC_ENT, MO(META), MO(SYMB),KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Reset|   1  |   2  |   3  |   4  |   5  |  [   |   |  ]   |   6  |   7  |   8  |   9  |   0  | BSPC |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | RCtrl| LCmd |      |  F1  |  F2  |  F3  |  (   |   |  )   |  F7  |  F8  |  F9  | PGUP | HOME |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Optn | Ctrl |      |  F4  |  F5  |  F6  |  {   |   |  }   | F10  | F11  |  F12 | PGDN |  END |  FN  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Optn | LSft |   `  |  =   | SYMB |Space | RSft |   |Enter | META | BSPC | RAlt |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,    KC_RBRC,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, XXXXXXX, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_END,  _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | RCtrl| LCmd |      |      |      |      |  (   |   |  )   |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Del  | Ctrl |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  |  FN  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LSft |   `  |   =  | SYMB |Space | RSft |   |Enter | META | SYMB | RCmd | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DELT, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______ \
  ),

  /* FN
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |  Tab |      |      |      |      |  [   |   |   ]  |      |      |      |      |      | Del  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | RCtrl| LCmd |      |  F1  |  F2  |  F3  |  (   |   |  )   |  F7  |  F8  |  F9  |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Del  | Ctrl |      |  F4  |  F5  |  F6  |  {   |   |  }   | F10  | F11  | F12  |      |  UP  |  FN  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LSft |   `  |   =  | SYMB |Space | RSft |   |Enter | META | SYMB | RCmd | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [FN] = LAYOUT( \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,    KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DELT, \
    _______, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   S(KC_9),    S(KC_0),    KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   S(KC_LBRC), S(KC_RBRC), KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______ \
  )

};

