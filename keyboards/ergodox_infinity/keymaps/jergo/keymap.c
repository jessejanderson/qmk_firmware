// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define VIMM 2 // vim
#define NUMP 3 // numpad
#define PCMR 4 // pc
#define MIRR 5 // mirror

enum macro_keycodes
{
  KC_CMD_TAB,
};

#define _______ KC_TRNS

// Macros

#define CMD_TAB M(KC_CMD_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
 *
 * (1) = Hold for layer 1
 * [1] = Locked to layer 1
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |    `   |   1  |   2  |   3  |   4  |   5  |[NUMP]|           |[NUMP]|   6  |   7  |   8  |   9  |   _  |   =    |
 * |--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |[PCMR]|           | Del  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  +------+           +------+   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------+ Caps |           | Bspc +------+------+------+------+------+--------+
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |/LGUI | SHIFT  |
 * +-+------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   | Ctrl | Hypr | Ctrl | Lalt | Gui  |                                       |(SYMB)|   <  |  v   |  ^   |   >  |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        | Vol- | Vol+ |       | Prev | Next |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      | Mute |       | Play |      |      |
 *                                 |(VIMM)|[VIMM]+------+       +------+ Enter| Space|
 *                                 |      |      | Mute |       | Play |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = LAYOUT_ergodox( // layer 0 : default
                             // left hand
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, TG(NUMP),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(PCMR),
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_CAPS,
        KC_LCTL, KC_FN1, KC_LCTL, KC_LALT, KC_LGUI,
        KC_VOLD, KC_VOLU,
        KC_MUTE,
        MO(VIMM), TG(VIMM), KC_MUTE,
        // right hand
        TG(NUMP), KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_BSPC, KC_N, KC_M, KC_COMM, KC_DOT, GUI_T(KC_SLSH), KC_RSFT,
        MO(SYMB), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        KC_MPRV, KC_MNXT,
        KC_MPLY,
        KC_MPLY, KC_ENT, KC_SPC),
    /* Keymap 1: Symbol Layer
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   |  |   \  |        |
 * |--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |   [  |   (  |   =  |   +  |   {  |------|           |------|   }  |   -  |   _  |   )  |   ]  |        |
 * |--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +-+------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        |      |      |       |      |      |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      +------+       +------+      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    [SYMB] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11,
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TRNS,
        KC_TRNS, KC_LBRC, KC_LPRN, KC_EQL, KC_PLUS, KC_LCBR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, KC_TRNS,
        KC_RCBR, KC_MINS, KC_UNDS, KC_RPRN, KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS),
    /* Keymap 2: Vim Mapping (just HJKL arrows for now)
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      +------+           +------+   <  |   v  |   ^  |   >  |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        |      |      |       |      |      |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      +------+       +------+      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    [VIMM] = LAYOUT_ergodox(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS),
    /* Keymap 3: numpad so i can use top row symbols
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * | FLASH  |      |      |      |      |      |      |           |      |      | NMLCK|  P/  |  P*  |  P-  | FLASH  |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |  P7  |  P8  |  P9  |  P+  |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      +------+           +------+      |  P4  |  P5  |  P6  |  P+  |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |  P1  |  P2  |  P3  | PENT |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   |      |      |      |      |      |                                       |      |      |  P.  | PENT |      |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        |      |      |       |      |      |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      +------+       +------+      |  P0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    [NUMP] = LAYOUT_ergodox(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, RESET,
        KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_TRNS,
        KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_DOT, KC_KP_ENTER, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_KP_0),
    /* Keymap 4: PC Mapping
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * | Esc    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * | Caps   |      |      |      |      |      +------+           +------+      |      |      |      |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   |      |      | LGUI |      |(MIRR)|                                       |      |      |      |      |      |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        |      |      |       |      |      |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      |      |       |      |      |      |
 *                                 | Spc  | Bspc +------+       +------+      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    [PCMR] = LAYOUT_ergodox(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, MO(MIRR),
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_SPC, KC_BSPC, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS),
    /* Keymap 5: Left-hand Mirror
 *
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |        |   0  |   9  |   8  |   7  |   6  |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+--------+
 * |    \   |   P  |   O  |   I  |   U  |   Y  |      |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |    '   |   ;  |   L  |   K  |   J  |   H  +------+           +------+      |      |      |      |      |        |
 * +--------+------+------+------+------+------+      |           |      +------+------+------+------+------+--------+
 * |        |   /  |   .  |   ,  |   M  |   N  | Bspc |           |      |      |      |      |      |      |        |
 * +--------+------+------+------+------+------+------+           +------+------+------+------+------+------+------+-+
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   +------+------+------+------+------+                                       +------+------+------+------+------+
 *                                        +------+------+       +------+------+
 *                                        |      |      |       |      |      |
 *                                 +------+------+------+       +------+------+------+
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      +------+       +------+      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 +------+------+------+       +------+------+------+
 */
    [MIRR] = LAYOUT_ergodox(
        KC_TRNS, KC_0, KC_9, KC_8, KC_7, KC_6, KC_TRNS,
        KC_BSLS, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_TRNS,
        KC_QUOT, KC_SCLN, KC_L, KC_K, KC_J, KC_H,
        KC_TRNS, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_MODS_ONESHOT(MOD_LSFT | MOD_LALT | MOD_LCTL | MOD_LGUI), // FN1 - hyper oneshot
};

static uint16_t start;
static bool keypressed;
static bool shiftdownbefore;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
    keypressed = true;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer)
  {
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  default:
    // none
    break;
  }
};

/* Keymap template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 /
// Escape
[ESCP] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, 
),
*/
