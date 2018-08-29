#include QMK_KEYBOARD_H

// Helpful defines
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0+1: Base+Shift
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |Shft+Esc|   F3   |   +    |   =    |   *    |   F4   |        |        |C+S+F10 |   F5   |   ^    |   %    |   ~    |  F12   |        |
 * |   |    |   4    |   0    |   1    |   2    |   3    | Ctrl+Z |  TT1   |Ctrl+F10|   7    |   6    |   5    |   9    |   8    |  TO 0  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |   "    |        |        |        |        |        |        |        |
 * |  TT2   |   J    |   H    |   O    |   U    |   K    |  Home  |   #    |  PgUp  |   G    |   C    |   R    |   F    |   Z    |   TT3  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |   _    |        |        |        |        |        |        |   $    |        |        |        |        |        |        |   ;    |
 * |   -    |   Q    |   I    |   E    |   A    |   Y    |  End   |   &    |  PgDn  |   D    |   S    |   T    |   N    |   B    |   :    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |   ?    |   !    |   `    |   @    |        |        |        |        |        |        |        |        |        |        |
 * |Shft/Esc|   /    |   ,    |   '    |   .    |   X    | Enter  |  Alt   |  OSL2  |   W    |   M    |   L    |   P    |   V    |Shft/Esc|
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |  Next  |        |        |
 * |  Ctrl  |  Left  |   Up   |  Down  |  Right |  Spc   |  Tab   |  Ctrl  |  OSL1  |  Bksp  |  Del   |  Supr  | Play/Ps| AltGr  |  Ctrl  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [0] = LAYOUT_ortho_5x15(
    KC_PIPE, KC_4,    KC_0,    KC_1,    KC_2,    KC_3,    LCTL(KC_Z), TT(1), LCTL(KC_F10), KC_7, KC_6, KC_5,    KC_9,   KC_8,     TO(0)
   ,TT(2),   KC_J,    KC_H,    KC_O,    KC_U,    KC_K,    KC_HOME, KC_DQUO, KC_PGUP, KC_G,    KC_C,    KC_R,    KC_F,   KC_Z,     TT(3)
   ,KC_MINS, KC_Q,    KC_I,    KC_E,    KC_A,    KC_Y,    KC_END, KC_AMPR,  KC_PGDN, KC_D,    KC_S,    KC_T,    KC_N,   KC_B,     KC_COLN
   ,LT(1,KC_ESCAPE), KC_SLSH, KC_COMM, KC_QUOT, KC_DOT, KC_X, KC_ENT, OSM(MOD_LALT), OSL(2), KC_W, KC_M, KC_L,  KC_P,   KC_V,     LT(1,KC_ESCAPE)
   ,OSM(MOD_LCTL), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_SPC, KC_TAB, OSM(MOD_LCTL), OSL(1), KC_BSPC, KC_DEL, OSM(MOD_LGUI), KC_MPLY, KC_RALT, OSM(MOD_RCTL)),
  [1] = LAYOUT_ortho_5x15(
    LSFT(KC_ESC), KC_F3, KC_PLUS, KC_EQL, KC_ASTR, KC_F4, LCTL(LSFT(KC_Z)), _______, LCTL(LSFT(KC_F10)), KC_F5, KC_CIRC, KC_PERC, KC_TILD, KC_F12, _______
   ,_______, LSFT(KC_J), LSFT(KC_H), LSFT(KC_O), LSFT(KC_U), LSFT(KC_K), LSFT(KC_HOME), KC_HASH, LSFT(KC_PGUP), LSFT(KC_G), LSFT(KC_C), LSFT(KC_R), LSFT(KC_F), LSFT(KC_Z), _______
   ,KC_UNDS, LSFT(KC_Q), LSFT(KC_I), LSFT(KC_E), LSFT(KC_A), LSFT(KC_Y), LSFT(KC_END), KC_DLR, LSFT(KC_PGDN), LSFT(KC_D), LSFT(KC_S), LSFT(KC_T), LSFT(KC_N), LSFT(KC_B), KC_SCLN
   ,_______, KC_QUES, KC_EXLM, KC_GRV, KC_AT, LSFT(KC_X), LSFT(KC_ENT), OSM(MOD_LALT|MOD_LSFT), OSL(2), LSFT(KC_W), LSFT(KC_M), LSFT(KC_L), LSFT(KC_P), LSFT(KC_V), _______
   ,OSM(MOD_LCTL|MOD_LSFT), LSFT(KC_LEFT), LSFT(KC_UP), LSFT(KC_DOWN), LSFT(KC_RGHT), LSFT(KC_SPC), LSFT(KC_TAB), OSM(MOD_LCTL|MOD_LSFT), _______, LSFT(KC_BSPC), LSFT(KC_DEL), OSM(MOD_LGUI|MOD_LSFT), KC_MNXT, LSFT(KC_RALT), OSM(MOD_LCTL|MOD_LSFT)),

/* Layer 2: Symbols
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |   4    |   0    |   1    |   2    |   3    |  Mute  |  Nkro  |        |   7    |   6    |   5    |   9    |   8    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |  Calc  |   <    |   $    |   >    |        |  Vol-  |        |  Prev  | Insert |   [    |   &    |   ]    | Pause  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   -    |   \    |   (    |   "    |   )    |   #    |  Vol+  |        |  Next  |   %    |   {    |   =    |   }    |   |    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shft/( |   /    |   :    |   *    |   +    |        |        |        |        | PrntSc |   _    |   ^    |   ~    |        | Shft/) |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  App   |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [2] = LAYOUT_ortho_5x15(
    KC_NO,   KC_4,    KC_0,    KC_1,    KC_2,    KC_3,    KC_MUTE, MAGIC_HOST_NKRO, KC_NO, KC_7, KC_6, KC_5,    KC_9,   KC_8,     _______
   ,_______, KC_CALC, KC_LT,   KC_DLR,  KC_GT,   KC_NO,   KC_VOLD, _______, KC_MPRV, KC_INS,  KC_LBRC, KC_AMPR, KC_RBRC,KC_PAUS,  _______
   ,KC_MINS, KC_BSLS, KC_LPRN, KC_DQUO, KC_RPRN, KC_HASH, KC_VOLU, _______, KC_MNXT, KC_PERC, KC_LCBR, KC_EQL,  KC_RCBR,KC_PIPE,  KC_SCLN
   ,KC_LSPO, KC_SLSH, KC_COLN, KC_ASTR, KC_PLUS, KC_NO,   _______, _______, _______, KC_PSCR, KC_UNDS, KC_CIRC, KC_TILD,KC_NO,    KC_RSPC
   ,_______, _______, _______, _______, _______, _______, _______, _______, KC_NO,   _______, _______, KC_APP,  KC_NO,  KC_NO,    _______),

/* Layer 3: Numpad and function
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |   =    |   /    |   *    |   -    |        |  Reset |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   :    |   7    |   8    |   9    |   +    |        |  Debug |        |        |   F1   |   F2   |   F3   |   F4   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   (    |  Tab   |   4    |   5    |   6    |   +    |    )   |        |        |        |   F5   |   F6   |   F7   |   F8   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   ,    |   1    |   2    |   3    | Enter  |        |   Up   |        |        |   F9   |   F10  |   F11  |   F12  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |   0    |   0    |   .    |  Spc   |  Left  |  Down  | Right  |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [3] = LAYOUT_ortho_5x15(
    KC_NO,   KC_NO,   KC_EQL,  KC_SLSH, KC_ASTR, KC_MINS, KC_NO,   RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    _______
   ,KC_NO,   KC_COLN, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_NO,   DEBUG,   KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F4,    _______
   ,KC_LPRN, KC_TAB,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_RPRN, KC_NO,   KC_NO,   KC_NO,   KC_F5,   KC_F6,   KC_F7,  KC_F8,    KC_NO
   ,_______, KC_COMM, KC_1,    KC_2,    KC_3,    KC_ENT,  KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_F9,   KC_F10,  KC_F11, KC_F12,   _______
   ,_______, KC_NO,   KC_0,    KC_0,    KC_DOT,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    _______)
};

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t r = 0, g = 0, b = 0;
  if (state & (1 << 1))
    r += 0xFF;
  if (state & (1 << 2))
    g += 0xFF;
  if (state & (1 << 3))
    b += 0xFF;
  rgblight_setrgb(r, g, b);
  return state;
}
