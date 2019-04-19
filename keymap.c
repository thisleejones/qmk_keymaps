/* Copyright 2019 Lee Jones
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
#include "version.h"

#if defined(KEYBOARD_planck)
#define LAYOUT_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define R1(...)
#elif defined(KEYBOARD_preonic)
#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)
#define R1(...) __VA_ARGS__,
#else
#error Keyboard not implemented.
#endif

#define R2(...) __VA_ARGS__,
#define R3(...) __VA_ARGS__,
#define R4(...) __VA_ARGS__,
#define R5(...) __VA_ARGS__

#if defined(DEFAULT_LAYER_SONGS)
extern float default_layer_songs[][16][2];
#endif

enum user_layers {
  QWERTY_LAYER,
  GUEST_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  ADJUST_LAYER,
  NAV_LAYER,
  GUI_LAYER,
  HYPER_LAYER,
};

enum user_keycodes {
  LEADER = SAFE_RANGE,
  QWERTY,
  KC_MAKE,
  KC_VERS,
  ALT_TAB,
  CMD_TAB,
  TLD_SLS,
  APP_TOG,
  EM_TOP,
};

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

#define GUI_L LT(GUI_LAYER, KC_LBRC)
#define GUI_R LT(GUI_LAYER, KC_RBRC)

#define HYPER_L ALL_T(KC_RCBR)
#define HYPER_R ALL_T(KC_LCBR)

/* Alt/Opt/Meta taps */
#define AT_A    LALT_T(KC_A)
#define AT_SCLN RALT_T(KC_S)

/* Control taps */
#define CT_F    LCTL_T(KC_F)
#define CT_J    RCTL_T(KC_J)

/* Gui/Command taps */
#define GT_S    LGUI_T(KC_S)
#define GT_L    RGUI_T(KC_L)

/* Shift taps */
#define ST_D    LSFT_T(KC_D)
#define ST_K    RSFT_T(KC_K)

/* Navigation layer on hold, backspace on tap */
#define NAV_BSP LT(NAV_LAYER, KC_BSPC)

/* Sets guest layer as default. */
#define GUEST DF(GUEST_LAYER)

/* Goodbye aka lock, sleep etc. */
#define KC_GBYE LALT(LGUI(KC_EJCT))

/* see for emacs issue: https://stackoverflow.com/a/21722619/878287 */
#define KC_MHSH RALT(KC_3)

/* tmux prefix */
#define KC_TMUX LCTL(KC_SPC)

/* MacOS Spotlight hotkey (typically remapped to Alfred). */
#define KC_SPOT LGUI(KC_SPC)

/* See rules.mk for a URL to the patch required */
#if !defined(APPLE_FN_ENABLE)
/* no-op when Apple Fn key feature not enabled */
#define KC_APFN KC_NO
#endif

/* TODO: remove when updating qmk_firmware submodule. */
#define MOD_MASK_CTRL            (MOD_BIT(KC_LCTRL)  | MOD_BIT(KC_RCTRL))
#define MOD_MASK_SHIFT           (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))

#define LCTL_E LCTL(KC_E)
#define LCTL_Y LCTL(KC_Y)
#define LCTL_U LCTL(KC_U)
#define LCTL_I LCTL(KC_I)
#define LCTL_O LCTL(KC_O)
#define LCTL_D LCTL(KC_D)
#define LCTL_F LCTL(KC_F)
#define LCTL_B LCTL(KC_B)

#define LGUI_X LGUI(KC_X)
#define LGUI_C LGUI(KC_C)
#define LGUI_V LGUI(KC_V)

#define LSFT_G LSFT(KC_G)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = LAYOUT_wrapper(
    R1(KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS)
    R2(KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT)
    R3(KC_ESC,  AT_A,    GT_S,    ST_D,    CT_F,    KC_G,    KC_H,    CT_J,    ST_K,    GT_L,    AT_SCLN, KC_ENT)
    R4(KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC)
    R5(GUI_L,   HYPER_L, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  NAV_BSP, RAISE,   KC_RGUI, KC_RALT, HYPER_R, GUI_R)
  ),

  [GUEST_LAYER] = LAYOUT_wrapper(
    R1(KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS)
    R2(KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT)
    R3(KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT)
    R4(KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT)
    R5(KC_APFN, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT)
  ),

  [LOWER_LAYER] = LAYOUT_wrapper(
    R1(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R2(_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS,    KC_7,    KC_8,    KC_9, KC_EQL , XXXXXXX)
    R3(_______, XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, XXXXXXX, KC_MINS,    KC_4,    KC_5,    KC_6, KC_ASTR, _______)
    R4(_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, KC_SLSH, _______)
    R5(_______, _______, _______, _______, _______, _______, KC_DEL,     KC_0, KC_COMM,  KC_DOT, _______, _______)
  ),

  [RAISE_LAYER] = LAYOUT_wrapper(
    R1(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R2(_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, XXXXXXX, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_GRV)
    R3(CMD_TAB, XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, TLD_SLS, KC_UNDS, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, _______)
    R4(_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MHSH, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, _______)
    R5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
  ),

  [NAV_LAYER] = LAYOUT_wrapper(
    R1(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R2(_______, XXXXXXX, XXXXXXX, LCTL_E,  XXXXXXX, XXXXXXX, LCTL_Y,  LCTL_U,  LCTL_I,  LCTL_O,  XXXXXXX, _______)
    R3(APP_TOG, EM_TOP,  XXXXXXX, LCTL_D,  LCTL_F,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______)
    R4(_______, LSFT_G,  LGUI_X,  LGUI_C,  LGUI_V,  LCTL_B,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______)
    R5(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
  ),

  [ADJUST_LAYER] = LAYOUT_wrapper(
    R1(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R2(XXXXXXX, QWERTY,  KC_MAKE, XXXXXXX, RESET,   KC_TMUX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GBYE)
    R3(XXXXXXX, KC_SPOT, XXXXXXX, XXXXXXX, XXXXXXX, GUEST,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R4(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VERS, XXXXXXX,  XXXXXXX, MU_TOG,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
    R5(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
  )
};

/* Used to track CMD state during layered CMD+TAB */
bool cmd_tab_pressed = false;

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(QWERTY_LAYER);
    }
    return false;
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
  case GUEST:
    if (record->event.pressed) {
      /* macro DF() does not play audio so lets do it here. */
      PLAY_SONG(default_layer_songs[GUEST_LAYER]);
    }
    /* We require default handling to proceed for actual layer change. */
    return true;
#endif
  case CMD_TAB:
    if (record->event.pressed) {
      if (!cmd_tab_pressed) {
        /* We handle unregister when RAISE, acting as CMD, is released. */
        register_code(KC_LGUI);
        cmd_tab_pressed = true;
      }
      register_code(KC_TAB);
      unregister_code(KC_TAB);
    }
    return false;
  case RAISE:
    if (!record->event.pressed && cmd_tab_pressed) {
        /* Stop acting as a held CMD key during layer invoked CMD+TAB. */
        unregister_code(KC_LGUI);
        cmd_tab_pressed = false;
    }
    return true;
  case APP_TOG:
    if (record->event.pressed) {
      /* Ensure single-press/toggle rather than holding/cycling on MacOS. */
      register_code(KC_LGUI);
      register_code(KC_TAB);
      unregister_code(KC_TAB);
      unregister_code(KC_LGUI);
    }
    return false;
  case TLD_SLS:
    if (record->event.pressed) {
      SEND_STRING("~/");
    }
    return false;
  case EM_TOP:
    if (record->event.pressed) {
      SEND_STRING("gg");
    }
    return false;
  case KC_VERS:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD " @ " QMK_VERSION " (" QMK_BUILDDATE ")");
    }
    return false;
  case KC_MAKE:
    if (!record->event.pressed) {
      uint8_t temp_mod = get_mods();
      uint8_t temp_osm = get_oneshot_mods();
      clear_mods();
      clear_oneshot_mods();
      SEND_STRING("make KEYBOARD=" QMK_KEYBOARD);
      /* currently the modifiers have no effect as invoked from a layer and despite checking upon release. */
      if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
#if (defined(__arm__) || defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
        SEND_STRING(" dfu-util-wait");
#elif defined(BOOTLOADER_HALFKAY)  // only run for teensy boards
        SEND_STRING(" teensy");
#elif defined(BOOTLOADER_CATERINA) // only run for Pro Micros
        SEND_STRING(" avrdude");
#else
        SEND_STRING(" unknown");
#endif // bootloader options
      }
      if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
        SEND_STRING(" -j8 --output-sync");
      }
      /* SEND_STRING(SS_TAP(X_ENTER)); */
      set_mods(temp_mod);
    }
    return false;
  }

  return true;
}
