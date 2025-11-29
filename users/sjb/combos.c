/* Copyright 2022 Sagacity Solutions Inc. All right reserved.
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

#ifdef COMBO_ENABLE

#include QMK_KEYBOARD_H

#include "sjb.h"

#define SJB_DEFINE_KEY(name, ...) const uint16_t PROGMEM combo_##name[] = {__VA_ARGS__, COMBO_END}

#define SJB_COMBO(name, action) COMBO(combo_##name, action)

SJB_DEFINE_KEY(CK_LBOOT,  HRM_COL1(LEFT_QW_ROW_1),  HRM_COL5(LEFT_QW_ROW_1));
SJB_DEFINE_KEY(CK_RBOOT,  HRM_COL1(RIGHT_QW_ROW_1), HRM_COL5(RIGHT_QW_ROW_1));
SJB_DEFINE_KEY(CK_POWER,  HRM_COL1(LEFT_QW_ROW_1),  HRM_COL1(LEFT_QW_ROW_3));
SJB_DEFINE_KEY(CK_RSTL,   HRM_COL1(LEFT_QW_ROW_2),  HRM_COL2(LEFT_QW_ROW_2));

#ifdef KEY_LOCK_ENABLE
// r + u = Key_lock
SJB_DEFINE_KEY(CK_KEY_LOCK, HRM_COL4(LEFT_QW_ROW_1), HRM_COL2(RIGHT_QW_ROW_1));
#endif

#ifdef CAPS_WORD_ENABLE
//  left-shift + right-shift
SJB_DEFINE_KEY(CK_CWTOGG,   HRM_COL4(LEFT_QW_ROW_2), HRM_COL2(RIGHT_QW_ROW_2));
#endif

#ifdef SWAP_HANDS_ENABLE
// left-a + left-s = SWAP hands
// SJB_DEFINE_KEY(CK_SWAP_HANDS, HRM_COL5(LEFT_QW_ROW_2), HRM_COL4(LEFT_QW_ROW_2));
// left-Backspace + left-Escape = layer lock
SJB_DEFINE_KEY(CK_SWAP_HANDS, SB_BSPC, SB_ESC);
#endif

combo_t key_combos[] = {
    SJB_COMBO(CK_LBOOT, QK_BOOT),
    SJB_COMBO(CK_RBOOT, QK_BOOT),
    SJB_COMBO(CK_POWER, KC_PWR),
    SJB_COMBO(CK_RSTL, KC_ESC),

#ifdef KEY_LOCK_ENABLE
    SJB_COMBO(CK_KEY_LOCK,   QK_LOCK),
#endif

#ifdef CAPS_WORD_ENABLE
    SJB_COMBO(CK_CWTOGG, CW_TOGG),
#endif

#ifdef SWAP_HANDS_ENABLE
    SJB_COMBO(CK_SWAP_HANDS, SH_OS),
#endif


};

#endif
