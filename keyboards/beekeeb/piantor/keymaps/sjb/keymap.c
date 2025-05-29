// Copyright (c) 2023 Sagacity Solutions Inc. All right reserved.

#include QMK_KEYBOARD_H
#include "sjb.h"

#define LAYOUT LAYOUT_split_3x6_3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    OSM_HYPR, LEFT_QW_ROW_1            , RIGHT_QW_ROW_1 , OSM_MEH  ,
    KC_Q    , LEFT_QW_ROW_2            , RIGHT_QW_ROW_2 , KC_P ,
    OSM_SFT , LEFT_QW_ROW_3            , RIGHT_QW_ROW_3 , OSM_SFT ,

    LEFT_PRIMARY_THUMB_CLUSTER ,
    RIGHT_PRIMARY_THUMB_CLUSTER
  ),
  [_RAISE] = LAYOUT_wrapper(
    _______ , LEFT_RAISE_ROW_1          , RIGHT_RAISE_ROW_1 , _______ ,
    S(KC_1) , LEFT_RAISE_ROW_2          , RIGHT_RAISE_ROW_2 , S(KC_0) ,
    _______ , LEFT_RAISE_ROW_3          , RIGHT_RAISE_ROW_3 , _______ ,

    LEFT_RAISE_THUMB_CLUSTER ,
    RIGHT_RAISE_THUMB_CLUSTER
  ),
  [_NAV] = LAYOUT_wrapper(
    RGB_TOG , LEFT_SYS_ROW_1 , RIGHT_NAV_ROW_1 , RGB_HUI ,
    RGB_MOD , LEFT_SYS_ROW_2 , RIGHT_NAV_ROW_2 , RGB_SAI ,
    NK_TOGG , LEFT_SYS_ROW_3 , RIGHT_NAV_ROW_3 , RGB_VAI ,

    LEFT_NAV_THUMB_CLUSTER,
    RIGHT_NAV_THUMB_CLUSTER
  ),
  [_NUMPAD] = LAYOUT_wrapper(
    _______ , FUNCPAD_ROW_1              , NUMPAD_ROW_1 , _______ ,
    KC_F1   , FUNCPAD_ROW_2              , NUMPAD_ROW_2 , KC_PMNS ,
    _______ , FUNCPAD_ROW_3              , NUMPAD_ROW_3 , _______ ,

    LEFT_NUMPAD_THUMB_CLUSTER,
    RIGHT_NUMPAD_THUMB_CLUSTER
  ),
  [_MOUSE] = LAYOUT_wrapper(
    _______ , LEFT_MOUSE_ROW_1 , RIGHT_MOUSE_ROW_1 , _______ ,
    _______ , LEFT_MOUSE_ROW_2 , RIGHT_MOUSE_ROW_2 , _______ ,
    _______ , LEFT_MOUSE_ROW_3 , RIGHT_MOUSE_ROW_3 , _______ ,

    LEFT_MOUSE_THUMB_CLUSTER ,
    RIGHT_MOUSE_THUMB_CLUSTER
  ),
  [_BHRL] = LAYOUT_wrapper(
    _______, TRANS_ROW    , TRANS_ROW, _______,
    _______, LEFT_HOME_ROW, RIGHT_HOME_ROW, _______,
    _______, TRANS_ROW    , TRANS_ROW, _______,
    LEFT_HOME_ROW_THUMB_CLUSTER,
    RIGHT_HOME_ROW_THUMB_CLUSTER
  ),
  [_RHRL] = LAYOUT_wrapper(
    _______, TRANS_ROW, TRANS_ROW, _______,
    _______, LEFT_HOME_ROW, TRANS_ROW, _______,
    _______, TRANS_ROW, TRANS_ROW, _______,
    LEFT_HOME_ROW_THUMB_CLUSTER,
    RIGHT_HOME_ROW_THUMB_CLUSTER
  ),
  [_LHRL] = LAYOUT_wrapper(
    _______, TRANS_ROW, TRANS_ROW, _______,
    _______, TRANS_ROW, RIGHT_HOME_ROW, _______,
    _______, TRANS_ROW, TRANS_ROW, _______,
    LEFT_HOME_ROW_THUMB_CLUSTER,
    RIGHT_HOME_ROW_THUMB_CLUSTER
  ),
};

#ifdef RGBLIGHT_LAYERS

#define _NLAYERS 5
const rgblight_segment_t PROGMEM ll_0[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_OFF});
const rgblight_segment_t PROGMEM ll_1[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_BLUE});
const rgblight_segment_t PROGMEM ll_2[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_PURPLE});
const rgblight_segment_t PROGMEM ll_3[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_GREEN});
const rgblight_segment_t PROGMEM ll_4[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_YELLOW});
const rgblight_segment_t PROGMEM ll_5[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});
const rgblight_segment_t PROGMEM ll_6[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});
const rgblight_segment_t PROGMEM ll_7[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});

const rgblight_segment_t* const PROGMEM ll_layers[] =
    RGBLIGHT_LAYERS_LIST(ll_0,ll_1,ll_2,ll_3, ll_4, ll_5, ll_6, ll_7);

layer_state_t layer_state_set_keymap(layer_state_t state) {
    for (uint8_t i=0 ; i < _NLAYERS; i++)
        rgblight_set_layer_state(i, layer_state_cmp(state, i));

    return state;
}

void keyboard_post_init_user(void) {
    rgblight_layers = ll_layers;
    rgblight_set_layer_state(0, 1);
}
#endif
