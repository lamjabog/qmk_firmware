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
  _GAME
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  MOUSE,
  CURSOR,
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
[_MAIN] = LAYOUT_preonic_grid( // TODO: copy from jj40 and ergodox
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  JC_L1LF, MO_CURS, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MO_MOUS, JC_L2RG,
  KC_LSPO, JC_CTRZ, JC_ALTX, KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, JC_ALDT, JC_CTRS, KC_RSPC,
  KC_LGUI, _______, _______, _______, JC_SHSP, KC_BSPC, JC_ESCC, KC_ENT,  _______, DF_GAME, _______, KC_RGUI
),

[_NUMBER] = LAYOUT_preonic_grid( // TODO: mouse mode
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PAST, KC_F12,
  _______, _______, _______, _______, _______, KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_0,    KC_PMNS, _______
),

[_MOUSE] = LAYOUT_preonic_grid( // TODO: num mode
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______, _______, KC_WH_U, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______
),
[_CURSOR] = LAYOUT_preonic_grid( // TODO: num mode
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  EE_CLR,  _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_GAME] = LAYOUT_preonic_grid( // TODO: num mode
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, _______, KC_BSPC, KC_SPC,  KC_ESC,  KC_ENT,  _______, DF_GAME, KC_RGUI, KC_RCTL
),

};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  //       case QWERTY:
  //         if (record->event.pressed) {
  //           set_single_persistent_default_layer(_QWERTY);
  //         }
  //         return false;
  //         break;
  //       case COLEMAK: // TODO: to remove
  //         if (record->event.pressed) {
  //           set_single_persistent_default_layer(_COLEMAK);
  //         }
  //         return false;
  //         break;
  //       case DVORAK: // TODO: to remove
  //         if (record->event.pressed) {
  //           set_single_persistent_default_layer(_DVORAK);
  //         }
  //         return false;
  //         break;
  //       case LOWER:
  //         if (record->event.pressed) {
  //           layer_on(_LOWER);
  //           update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //         } else {
  //           layer_off(_LOWER);
  //           update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //         }
  //         return false;
  //         break;
  //       case RAISE:
  //         if (record->event.pressed) {
  //           layer_on(_RAISE);
  //           update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //         } else {
  //           layer_off(_RAISE);
  //           update_tri_layer(_LOWER, _RAISE, _ADJUST);
  //         }
  //         return false;
  //         break;
  //       // TODO: add case for cursor, game and fg
  //       case BACKLIT:
  //         if (record->event.pressed) {
  //           register_code(KC_RSFT);
  //           #ifdef BACKLIGHT_ENABLE
  //             backlight_step();
  //           #endif
  //           #ifdef RGBLIGHT_ENABLE
  //             rgblight_step();
  //           #endif
  //           #ifdef __AVR__
  //           writePinLow(E6);
  //           #endif
  //         } else {
  //           unregister_code(KC_RSFT);
  //           #ifdef __AVR__
  //           writePinHigh(E6);
  //           #endif
  //         }
  //         return false;
  //         break;
  //     }
  //   return true;
// };

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// // TODO: to remove
// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
//     return true;
// }

// // TODO: to remove
// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }


// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
