#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

// Layer Names
#define MBKL 0
#define LWCTRL 1
#define MSBKL 2
#define SYM 3
#define NUM 4
#define MCTRLSH 5
#define GAME 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0+1: Base + Shift
 *
 * .--------------------------------------------------.       .--------------------------------------------------.
 * |Shft+Esc|  F3  |   +  |   =  |   *  |  F4  |      |       |       |  F5 |   ^  |   %  |   ~  |  F12 |        |
 * |  LEAD  |   4  |   0  |   1  |   2  |   3  | Cmd+Z|       |Ctl+F10|  7  |   6  |   5  |   9  |   8  |  TO 0  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * |  TT 2  |   J  |   H  |   O  |   U  |   K  | Cmd+C|       |LT(CTL)|  G  |   C  |   R  |   F  |   Z  |  TT 3  |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |    _   |      |      |      |      |      |      |       |      |      |      |      |      |      |    ;   |
 * |    -   |   Q  |   I  |   E  |   A  |   Y  |------|       |------|   D  |   S  |   T  |   N  |   B  |    :   |
 * |--------+------+------+------+------+------| Cmd+V|       | LCtl |------+------+------+------+------+--------|
 * |        |   ?  |   !  |   `  |   @  |      |      |       |      |      |      |      |      |      |        |
 * |Shft/Esc|   /  |   ,  |   '  |   .  |   X  |      |       |      |   W  |   M  |   L  |   P  |   V  |Shft/Esc|
 * .--------+------+------+------+------+-------------.       .-------------+------+------+------+------+--------.
 *   |  Cmd | Left |  Up  | Down | Right|                                   |  Del |Shift | TT 1 |  Alt | Cmd  |
 *   .----------------------------------.                                   .----------------------------------.
 *                                      .-------------.       .-------------.
 *                                      |  Cmd | Home |       | PgUp | Cmd  |
 *                               .------+------+------|       |------+------+------.
 *                               |      |      | End  |       | PgDn |      |      |
 *                               | Space| OSL 1|------|       |------| Tab  | Bksp |
 *                               |      |      | Enter|       | OSL 2|      |      |
 *                               .--------------------.       .--------------------.
 */
  [MBKL] = LAYOUT_ergodox(
    // Left
     KC_LEAD,        KC_4,    KC_0,    KC_1,    KC_2,    KC_3,   LGUI(KC_Z)
    ,TT(SYM),        KC_J,    KC_H,    KC_O,    KC_U,    KC_K,   LGUI(KC_C)
    ,KC_MINUS,       KC_Q,    KC_I,    KC_E,    KC_A,    KC_Y
    ,LT(MSBKL,KC_ESCAPE),KC_SLASH,KC_COMMA,KC_QUOTE,KC_DOT,  KC_X,   LGUI(KC_V)
    ,LM(MCTRLSH, MOD_LGUI),KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
                                               ,OSM(MOD_LGUI),KC_HOME
                                                        ,KC_END
                                      ,KC_SPACE,OSL(MSBKL),  KC_ENTER
    // Right
      ,C(KC_F10),     KC_7,    KC_6,    KC_5,    KC_9,    KC_8,    TO(MBKL)
      ,TG(LWCTRL),    KC_G,    KC_C,    KC_R,    KC_F,    KC_Z,    TT(NUM)
                     ,KC_D,    KC_S,    KC_T,    KC_N,    KC_B,    KC_COLN
      ,OSM(MOD_LCTL), KC_W,    KC_M,    KC_L,    KC_P,    KC_V,    LT(MSBKL,KC_ESCAPE)
                              ,KC_DELETE,OSM(MOD_LSFT),TT(MSBKL),OSM(MOD_LALT),OSM(MOD_LGUI)
      ,KC_PGUP,       OSM(MOD_LGUI)
      ,KC_PGDOWN
      ,OSL(SYM), KC_TAB,  KC_BSPACE),

  [LWCTRL] = LAYOUT_ergodox(
    // Left
     _______,         _______, _______, _______, _______, _______, C(KC_Z)
    ,_______,         _______, _______, _______, _______, _______, C(KC_C)
    ,_______,         _______, _______, _______, _______, _______
    ,_______,         _______, _______, _______, _______, _______, C(KC_V)
    ,LM(MCTRLSH, MOD_LCTL),    _______, _______, _______, _______
                                                   ,OSM(MOD_LCTL),_______
                                                            ,_______
                                          ,_______, _______, _______
    // Right
    ,_______,         _______,  _______, _______, _______, _______, _______
    ,_______,         _______,  _______, _______, _______, _______, _______
                     ,_______,  _______, _______, _______, _______, _______
    ,OSM(MOD_LGUI),   _______,  _______, _______, _______, _______, _______
                               ,_______, _______, _______, _______, OSM(MOD_LCTL)
    ,_______, OSM(MOD_LCTL)
    ,_______
    ,_______, _______,  _______),

  [MSBKL] = LAYOUT_ergodox(
    // Left
     LSFT(KC_ESCAPE),KC_F3,   KC_PLUS, KC_EQUAL,KC_ASTERISK,KC_F4,LCTL(LSFT(KC_Z))
    ,_______,        LSFT(KC_J),LSFT(KC_H),LSFT(KC_O),LSFT(KC_U),LSFT(KC_K),LCTL(LSFT(KC_C))
    ,KC_UNDS,        LSFT(KC_Q),LSFT(KC_I),LSFT(KC_E),LSFT(KC_A),LSFT(KC_Y)
    ,_______,        KC_QUES, KC_EXLM, KC_GRAVE,KC_AT,   LSFT(KC_X),LCTL(LSFT(KC_V))
    ,OSM(MOD_LSFT|MOD_LGUI),LSFT(KC_LEFT),LSFT(KC_UP),LSFT(KC_DOWN),LSFT(KC_RIGHT)
                                               ,OSM(MOD_LSFT|MOD_LGUI),LSFT(KC_HOME)
                                                        ,S(KC_END)
                                      ,LSFT(KC_SPACE),_______,LSFT(KC_ENTER)
    // Right
    ,_______,         KC_F5,   KC_CIRC, KC_PERC, KC_TILD, KC_F12,  TO(0)
    ,_______,         LSFT(KC_G),LSFT(KC_C),LSFT(KC_R),LSFT(KC_F),LSFT(KC_Z),_______
                     ,LSFT(KC_D),LSFT(KC_S),LSFT(KC_T),LSFT(KC_N),LSFT(KC_B),KC_SCOLON
    ,LSFT(MOD_LCTL), LSFT(KC_W),LSFT(KC_M),LSFT(KC_L),LSFT(KC_P),LSFT(KC_V),_______
                              ,S(KC_DELETE),_______,_______,OSM(MOD_LSFT|MOD_LALT),OSM(MOD_LSFT|MOD_LGUI)
    ,LSFT(KC_PGUP),   LSFT(KC_LGUI)
    ,LSFT(KC_PGDOWN)
    ,_______,  LSFT(KC_TAB),LSFT(KC_BSPACE)),

/* Layer 2: Symbols
 *
 * .--------------------------------------------------.       .--------------------------------------------------.
 * |        |      |      |      |      |      |      |       |  App |      |      |      |      |      |  TO 0  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * |        |      |   <  |   $  |   >  |Ply/Ps|      |       | AltGr|  Ins |   [  |   _  |   ]  | Pause|  TT 3  |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |    -   |   \  |   (  |   "  |   )  |   +  |------|       |------|   %  |   {  |   &  |   }  |   ~  |    ;   |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |        |   /  |   :  |   *  |   #  |   !  |      |       |      | PrtSc|   =  |   ^  |   |  |      |        |
 * .--------+------+------+------+------+-------------.       .-------------+------+------+------+------+--------.
 *   |      |      |      |      |      |                                   |      |      |      |      |      |
 *   .----------------------------------.                                   .----------------------------------.
 *                                      .-------------.       .-------------.
 *                                      |      |      |       |      |      |
 *                               .------+------+------|       |------+------+------.
 *                               |      |      |      |       |      |      |      |
 *                               |      |      |------|       |------|      |      |
 *                               |      |      |      |       | OSL 2|      |      |
 *                               .--------------------.       .--------------------.
 */

  [SYM] = LAYOUT_ergodox(
  // Left
   _______,          _______, _______, _______, _______, _______,_______
  ,_______,          _______, KC_LABK, KC_DLR,  KC_RABK, KC_MPLY,_______
  ,KC_MINUS,         KC_BSLASH,KC_LPRN,KC_DQUO, KC_RPRN, KC_PLUS
  ,KC_LSPO,          KC_SLASH,KC_COLN, KC_ASTR, KC_HASH, KC_EXLM,_______
  ,_______,          _______, _______, _______, _______
                                               ,_______,_______
                                                       ,_______
                                      ,_______, _______,_______
  // Right
  ,KC_APPLICATION,    _______, _______, _______, _______, _______, _______
  ,OSM(MOD_RALT),     KC_INSERT,KC_LBRACKET,KC_UNDS,KC_RBRACKET,KC_PAUSE,_______
                     ,KC_PERC,  KC_LCBR, KC_AMPR, KC_RCBR, KC_TILD, KC_SCOLON
  ,_______,           KC_PSCREEN,KC_EQUAL,KC_CIRC,KC_PIPE, _______, KC_RSPC
                               ,_______, _______, _______, _______, _______
  ,_______, _______
  ,_______
  ,_______, _______,  _______),

/* Layer 3: Numpad and Function
 *
 * .--------------------------------------------------.       .--------------------------------------------------.
 * |        | Left |  Up  | Right| Down |   -  |      |       |      |      |      |      |      |      |  TO 0  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * |        |   =  |   7  |   8  |   9  |   +  |      |       |      |  F13 |  F1  |  F2  |  F3  |  F4  |  TT 3  |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |    (   |   *  |   4  |   5  |   6  |   )  |------|       |------|  F14 |  F5  |  F6  |  F7  |  F8  |  TG 5  |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |Shft/Esc|   /  |   1  |   2  |   3  | Enter|      |       |      |  F15 |  F9  |  F10 |  F11 |  F12 |Shft/Esc|
 * .--------+------+------+------+------+-------------.       .-------------+------+------+------+------+--------.
 *   |      | Tab  |   0  |   0  |   .  |                                   |      |      |      |      |      |
 *   .----------------------------------.                                   .----------------------------------.
 *                                      .-------------.       .-------------.
 *                                      |      |      |       |      |      |
 *                               .------+------+------|       |------+------+------.
 *                               |      |      |      |       |      |      |      |
 *                               |      |      |------|       |------|      |      |
 *                               |      |      |      |       |      |      |      |
 *                               .--------------------.       .--------------------.
 */

  [NUM] = LAYOUT_ergodox(
  // Left
   _______,          KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,KC_MINUS,_______
  ,_______,          KC_EQUAL,KC_7,    KC_8,    KC_9,    KC_PLUS, _______
  ,KC_LPRN,          KC_ASTR ,KC_4,    KC_5,    KC_6,    KC_RPRN
  ,LSFT_T(KC_ESCAPE),KC_SLASH,KC_1,    KC_2,    KC_3,    KC_ENTER,_______
  ,_______,          KC_TAB,  KC_0,    KC_0,    KC_DOT
                                               ,_______, _______
                                                        ,_______
                                      ,_______, _______, _______
  // Right
  ,_______,           _______,  _______, _______, _______, _______, _______
  ,_______,           KC_F13,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______
                     ,KC_F14,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   TG(GAME)
  ,_______,           KC_F15,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RSFT_T(KC_ESCAPE)
                               ,_______, _______, _______, _______, _______
  ,_______, _______
  ,_______
  ,_______, _______,  _______),

/* Layer 4: Ctrl shortcut layer
 *
 * .--------------------------------------------------.       .--------------------------------------------------.
 * |        |      |      |      |      |      |      |       |      |      |      |      |      |      |  TO 0  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |       |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |        | Cmd+A|      |      |      |      |------|       |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |        | Cmd+Z| Cmd+X| Cmd+C| Cmd+V|      |      |       |      |      |      |      |      |      |        |
 * .--------+------+------+------+------+-------------.       .-------------+------+------+------+------+--------.
 *   |      |      |      |      |      |                                   |      |      |      |      |      |
 *   .----------------------------------.                                   .----------------------------------.
 *                                      .-------------.       .-------------.
 *                                      |      |      |       |      |      |
 *                               .------+------+------|       |------+------+------.
 *                               |      |      |      |       |      |      |      |
 *                               |      |      |------|       |------|      |      |
 *                               |      |      |      |       |      |      |      |
 *                               .--------------------.       .--------------------.
 */

  [MCTRLSH] = LAYOUT_ergodox(
  // Left
   _______,           _______, _______, _______, _______, _______, _______
  ,_______,           _______, _______, _______, _______, _______, _______
  ,_______,           KC_A   , _______, _______, _______, _______
  ,_______,           KC_Z   , KC_X   , KC_C   , KC_V   , _______, _______
  ,_______,           _______, _______, _______, _______
                                                 ,_______, _______
                                                          ,_______
                                        ,_______, _______, _______
  // Right
  ,_______,           _______,  _______, _______, _______, _______, _______
  ,_______,           _______,  _______, _______, _______, _______, _______
                     ,_______,  _______, _______, _______, _______, _______
  ,_______,           _______,  _______, _______, _______, _______, _______
                               ,_______, _______, _______, _______, _______
  ,_______, _______
  ,_______
  ,_______, _______,  _______),

/* Layer 5: Gaming
 *
 * .--------------------------------------------------.       .--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  |       |      |      |      |      |      |      |  TO 0  |
 * |--------+------+------+------+------+-------------|       |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |  F6  |       |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |       |      |------+------+------+------+------+--------|
 * |    -   |   A  |   S  |   D  |   F  |   G  |------|       |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  F5  |       |      |------+------+------+------+------+--------|
 * |  LShft |   Z  |   X  |   C  |   V  |   B  |      |       |      |      |      |      |      |      |        |
 * .--------+------+------+------+------+-------------.       .-------------+------+------+------+------+--------.
 *   | LCtrl|  F1  |  F2  |  F3  |  F4  |                                   |      |      |      |      |      |
 *   .----------------------------------.                                   .----------------------------------.
 *                                      .-------------.       .-------------.
 *                                      |  Cmd |   `  |       |      |      |
 *                               .------+------+------|       |------+------+------.
 *                               |      |      |   =  |       |      |      |      |
 *                               | Space| L Alt|------|       |------|      |      |
 *                               |      |      | Enter|       |      |      |      |
 *                               .--------------------.       .--------------------.
 */
  [GAME] = LAYOUT_ergodox(
    // Left
     KC_ESCAPE,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6
    ,KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_F6
    ,KC_MINUS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
    ,KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_F5
    ,KC_LCTL,       KC_F1,   KC_F2,   KC_F3,    KC_F4
                                               ,OSM(MOD_LGUI),KC_GRAVE
                                                        ,KC_EQUAL
                                      ,KC_SPACE, KC_LALT,  KC_ENTER
    // Right
      ,_______,       _______, _______, _______, _______, _______,    TO(MBKL)
      ,_______,       _______, _______, _______, _______, _______,    _______
                     ,_______, _______, _______, _______, _______,    _______
      ,_______,       _______, _______, _______, _______, _______,    _______
                              ,_______, _______, _______, _______,    _______
      ,_______,      _______
      ,_______
      ,_______, _______,  _______),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_C) {
      register_code(KC_LSFT);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LSFT);
      register_code(KC_DELETE);
      unregister_code(KC_DELETE);
    }
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_HOME);
      unregister_code(KC_HOME);
      register_code(KC_LSFT);
      register_code(KC_DOWN);
      unregister_code(KC_DOWN);
      unregister_code(KC_LSFT);
      register_code(KC_LCTRL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LCTRL);
    }
    SEQ_ONE_KEY(KC_F) {
      register_code(KC_LCTRL);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LCTRL);
      register_code(KC_LBRACKET);
      unregister_code(KC_LBRACKET);
    }
  }
}

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
      case LWCTRL:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case MSBKL:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case SYM:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case NUM:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 6:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 7:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
    }
    return state;
};
