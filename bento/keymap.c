/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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

enum custom_keycodes {
    MESSAGE = SAFE_RANGE,
    CATCHPHRASE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case MESSAGE:
          if (record->event.pressed) {
              // when keycode MESSAGE is pressed
              SEND_STRING("Hello World");
          } else {
              // when keycode MESSAGE is released
          }
          break;
      case CATCHPHRASE:
          if (record->event.pressed) {
              // when keycode CATCHPHRASE is pressed
              SEND_STRING("Amy Likes Keyboards");
          } else {
              // when keycode CATCHPHRASE is released
          }
          break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                  |          | Knob 2: Vol Up/Dn |
        |  Toggle Layer 1  |    Up    |    Press: Mute    |
        |      Left        |   Down   |      Right        |
     */
    [0] = LAYOUT(
        CATCHPHRASE, MESSAGE, KC_MUTE,
        KC_MPRV , KC_MPLY  , KC_MNXT
    ),
    /*
        |               |   Increase Brightness  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Hue Cycle |
     */
    [1] = LAYOUT(
        _______  , RGB_VAI, KC_MUTE,
        RGB_MOD, RGB_VAD, RGB_HUI
    ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }

    return false;
}
