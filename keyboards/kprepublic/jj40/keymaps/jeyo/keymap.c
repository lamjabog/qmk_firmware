#include QMK_KEYBOARD_H

#define _KEYMN  0
#define _GAME_  1
#define _NUMBR  2
#define _MOUSE  3
#define _CURSR  4
#define _GAM2_  5
//#define _FG___  5

// CUSTOM DEFINES FOR READABILITY
#define JC_L1LF LT(_NUMBR, KC_TAB)
#define JC_L2RG LT(_NUMBR, KC_QUOT)
#define MO_CURS LT(_CURSR, KC_A)
#define MO_MOUS LT(_MOUSE, KC_SCLN)
#define JC_CMDZ GUI_T(KC_Z)
#define JC_CTRX LALT_T(KC_X)
#define JC_CTDT RALT_T(KC_DOT)
#define JC_CMDS RGUI_T(KC_SLSH)
#define JC_SHSP SFT_T(KC_SPC)
#define JC_PLUS KC_KP_PLUS
#define JC_SLSH KC_KP_SLASH
#define JC_ESCC RCTL_T(KC_ESC)
#define DF_GAME TG(_GAME_)
#define DF_KEYM DF(_KEYMN)
#define DF_GAM2 TG(_GAM2_)
//#define DF_FG__ DF(_FG___)


enum custom_keycodes {
  KEYMN = SAFE_RANGE, // TODO: you dont need these
  GAME_,
  NUMBR,
  MOUSE,
  CURSR,
  //FG___,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |      |      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_KEYMN] = LAYOUT_ortho_4x12( \
  KC_GRV , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  JC_L1LF, MO_CURS, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MO_MOUS, JC_L2RG, \
  KC_LSPO, JC_CMDZ, JC_CTRX, KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, JC_CTDT, JC_CMDS, KC_RSPC, \
  _______, KC_LALT, _______, _______, JC_SHSP, KC_BSPC, JC_ESCC, KC_ENT,  _______, DF_GAM2, KC_RALT, DF_GAME  \
),
/* Game
 * ,-----------------------------------------------------------------------------------.
 * | tilde|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   z  |   x  |   v  |  b   | space|      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_GAME_] = LAYOUT_ortho_4x12( \
  KC_ESC , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JC_L2RG, \
  KC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSPC, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_B,  KC_SPC,    KC_ENT,  KC_GRV,  _______, _______, KC_RALT, _______  \
),
*/
[_GAME_] = LAYOUT_ortho_4x12( \
  KC_ESC,  XXXXXXX, XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  \
  KC_BSPC, XXXXXXX, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, KC_U,    KC_I,    KC_O,    KC_P,    KC_SPC,  \
  DF_GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_W,    KC_J,    KC_K,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
),
/* Game
 * ,-----------------------------------------------------------------------------------.
 * | tilde|   1  |   2  |   3  |   4  |   5  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   a  |   s  |   d  |   f  |   g  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      | space|      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBR] = LAYOUT_ortho_4x12( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_PAST, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    JC_PLUS, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  _______, KC_DEL , _______, _______, KC_PDOT, KC_0,    JC_SLSH, _______  \
),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |      |      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, KC_MS_U, _______, _______, _______, _______, KC_WH_U, _______, _______, _______, \
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______  \
),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |      |      |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CURSR] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, _______, KC_UP,   _______, _______, RESET,   \
  _______, _______, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, RGB_M_P, RGB_SAD, RGB_SAI, _______, _______, _______, KC_RALT, KC_RCTL, KC_RSFT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RGUI, _______  \
),
[_GAM2_] = LAYOUT_ortho_4x12( \
  KC_ESC , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JC_L2RG, \
  KC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSPC, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,  KC_SPC,    KC_ENT,  KC_GRV,  _______, _______, KC_RALT, XXXXXXX  \
),
/* Fighting game layout 
//[_FG___] = LAYOUT_ortho_4x12( \
  //KC_ESC,  XXXXXXX, XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  \
  //KC_BSPC, XXXXXXX, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_SPC,  \
  //DF_FG__, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
  //XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_W,    KC_M,    KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
//),
*/
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

// TODO: Create socd cleaner
// use vsfighter socd cleaner