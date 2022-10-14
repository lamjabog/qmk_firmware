/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#define JC_L1LF LT(_NUMBER, KC_TAB)
#define JC_L2RG LT(_NUMBER, KC_QUOT)
#define MO_CURS LT(_CURSOR, KC_A)
#define MO_MOUS LT(_MOUSE, KC_SCLN)
#define JC_CTRZ CTL_T(KC_Z)
#define JC_ALTX LALT_T(KC_X)
#define JC_ALDT RALT_T(KC_DOT)
#define JC_CTRS RCTL_T(KC_SLSH)
#define JC_SHSP SFT_T(KC_SPC)
#define JC_ESCC RCTL_T(KC_ESC)
#define DF_GAME TG(_GAME)

enum preonic_layers {
  _MAIN,
  _NUMBER,
  _MOUSE,
  _CURSOR,
  _GAME,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  MOUSE,
  CURSOR,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MAIN] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  JC_L1LF, MO_CURS, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MO_MOUS, JC_L2RG,
  KC_LSPO, JC_CTRZ, JC_ALTX, KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, JC_ALDT, JC_CTRS, KC_RSPC,
  KC_LGUI, _______, _______, _______, JC_SHSP, KC_BSPC, JC_ESCC, KC_ENT,  ADJUST,  DF_GAME, _______, KC_RGUI
),

[_NUMBER] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PAST, KC_F12,
  _______, _______, _______, _______, _______, KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_0,    KC_PMNS, _______
),

[_MOUSE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______, _______, KC_WH_U, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______
),

[_CURSOR] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_GAME] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, _______, KC_BSPC, KC_SPC,  KC_ESC,  KC_ENT,  _______, DF_GAME, KC_RGUI, KC_RCTL
),

[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, EEP_RST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_NO,   KC_NO,   MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, KC_NO,   KC_NO,   KC_NO,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _GAME:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case ADJUST:
      return false;
    default:
      return true;
  }
}