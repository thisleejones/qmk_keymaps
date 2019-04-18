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

/* Disable action_get_macro and fn_actions, since we don't use these */
/* and it saves on space in the firmware. */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#if defined(AUDIO_ENABLE)
#define STARTUP_SONG SONG(ONE_UP_SOUND)

/* Play sounds when the default layer is set. */
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND),         \
                              SONG(COLEMAK_SOUND) }
#endif

/* Home row modifiers conflict with some frequently used rolling */
/* combos and these fix that. */
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* Prevent power consumption issues when used with iOS devices. */
#define USB_MAX_POWER_CONSUMPTION 100
