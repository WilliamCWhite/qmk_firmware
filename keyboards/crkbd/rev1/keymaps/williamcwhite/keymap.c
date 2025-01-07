/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//TODO Make feature where while in an OSL, it will wait for any active mods before exiting

#include QMK_KEYBOARD_H

enum custom_keycodes {
    UP4 = SAFE_RANGE,
    DOWN4,
    LEFT4,
    RIGHT4,
    UP12,
    DOWN12,
    LEFT12,
    RIGHT12,
    NTAB3,
    PTAB3,
    BS4,
    PGUP3,
    PGDN3,
    RWND,
    RWND2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3( // Base Layer
        KC_ESC, KC_Q, KC_W,        /*s*/ KC_E, KC_R, KC_T,              /*m*/ KC_Y, KC_U, KC_I,              /*e*/ KC_O, KC_P, OSM(MOD_LGUI), 
        KC_TAB, KC_A, KC_S,        /*s*/ KC_D, KC_F, KC_G,              /*m*/ KC_H, KC_J, KC_K,              /*e*/ KC_L, KC_SCLN, KC_ENT, 
        OSM(MOD_LALT), KC_Z, KC_X, /*s*/ KC_C, KC_V, KC_B,              /*m*/ KC_N, KC_M, KC_COMM,           /*e*/ KC_DOT, KC_SLSH, MO(4),
                                   /*s*/ OSL(2), OSM(MOD_LSFT), OSL(1), /*m*/ KC_BSPC, KC_SPC, OSM(MOD_LCTL) /*e*/
    ),
    [1] = LAYOUT_split_3x6_3( // Symbol Layer
        KC_TILD, KC_1, KC_2,             /*s*/ KC_3, KC_4, KC_5,             /*m*/ KC_6, KC_7, KC_8,              /*e*/ KC_9, KC_0, KC_BSLS, 
        KC_GRV, KC_QUOT, KC_DQUO,        /*s*/ KC_LPRN, KC_RPRN, KC_DLR,     /*m*/ KC_AT, KC_UNDS, KC_EQL,        /*e*/ KC_MINS, KC_PLUS, KC_CIRC, 
        OSM(MOD_LALT), KC_PERC, KC_EXLM, /*s*/ KC_LBRC, KC_RBRC, KC_PIPE,    /*m*/ KC_AMPR, KC_LCBR, KC_RCBR,     /*e*/ KC_HASH, KC_ASTR, TO(0),
                                         /*s*/ OSL(2), OSM(MOD_LSFT), TO(1), /*m*/ KC_BSPC, KC_SPC, OSM(MOD_LCTL) /*e*/
    ),
    [2] = LAYOUT_split_3x6_3( // Navigation Layer
        KC_ESC, RWND, KC_BTN2,                /*s*/ KC_UP, KC_BTN1, C(KC_LBRC),      /*m*/ C(KC_RBRC), KC_WH_D, KC_MS_U,  /*e*/ KC_WH_U, KC_PGUP, OSM(MOD_LGUI), 
        KC_TAB, XXXXXXX, KC_LEFT,             /*s*/ KC_DOWN, KC_RGHT, KC_WH_L,       /*m*/ KC_WH_R, KC_MS_L, KC_MS_D,     /*e*/ KC_MS_R, KC_PGDN, KC_ENT, 
        OSM(MOD_LALT), OSM(MOD_LALT), KC_DEL, /*s*/ C(KC_PGUP), C(KC_PGDN), XXXXXXX, /*m*/ XXXXXXX, KC_HOME, KC_END,      /*e*/ RCS(KC_BSLS), OSL(3), TO(0),
                                              /*s*/ TO(2), OSM(MOD_LSFT), OSL(1),    /*m*/ KC_BSPC, KC_SPC, OSM(MOD_LCTL) /*e*/
    ),
    [3] = LAYOUT_split_3x6_3( // Multiplication Layer
        KC_ESC, RWND2, DOWN12,                /*s*/ UP4, UP12, C(KC_LBRC),        /*m*/ C(KC_RBRC), KC_WH_D, KC_MS_U,  /*e*/ KC_WH_U, PGUP3, OSM(MOD_LGUI), 
        KC_TAB, XXXXXXX, LEFT4,               /*s*/ DOWN4, RIGHT4, KC_WH_L,       /*m*/ KC_WH_R, KC_MS_L, KC_MS_D,  /*e*/ KC_MS_R, PGDN3, KC_ENT, 
        OSM(MOD_LALT), OSM(MOD_LALT), KC_DEL, /*s*/ PTAB3, NTAB3, XXXXXXX,        /*m*/ XXXXXXX, LEFT12, RIGHT12,   /*e*/ RCS(KC_BSLS), OSL(3), TO(0),
                                              /*s*/ TO(2), OSM(MOD_LSFT), OSL(1), /*m*/ BS4, KC_SPC, OSM(MOD_LCTL)  /*e*/
    ),
    [4] = LAYOUT_split_3x6_3( // TILING LAYER
        XXXXXXX, MEH(KC_BSLS), MEH(KC_LBRC), /*s*/ LCA(KC_BSLS), MEH(KC_RBRC), KC_BRIU, /*m*/ KC_BRID, KC_VOLD, KC_MUTE,             /*e*/ KC_VOLU, LALT(KC_F4), KC_CAPS, 
        TO(6), LGUI(KC_4), LGUI(KC_3),     /*s*/ LGUI(KC_2), LGUI(KC_1), LGUI(KC_9),  /*m*/ CW_TOGG, LGUI(KC_LEFT), SGUI(KC_LEFT), /*e*/ LGUI(KC_RGHT), XXXXXXX, XXXXXXX, 
        XXXXXXX, LGUI(KC_8), LGUI(KC_7),     /*s*/ LGUI(KC_6), LGUI(KC_5), LGUI(KC_0),  /*m*/ XXXXXXX, KC_MPRV, KC_MPLY,             /*e*/ KC_MNXT, HYPR(KC_D), KC_TRNS,
                                             /*s*/ LALT(KC_TAB), KC_LSFT, KC_LGUI,      /*m*/ TO(5), LGUI(KC_UP), OSM(MOD_LCTL)    /*e*/
    ),
    [5] = LAYOUT_split_3x6_3( // FUNCTION KEY LAYER
        XXXXXXX, KC_F1, KC_F2,           /*s*/ KC_F3, KC_F4, KC_F5,             /*m*/ KC_F6, KC_F7, KC_F8,           /*e*/ KC_F9, KC_F10, OSM(MOD_LGUI), 
        XXXXXXX, XXXXXXX, XXXXXXX,       /*s*/ XXXXXXX, XXXXXXX, KC_F11,        /*m*/ KC_F12, XXXXXXX, XXXXXXX,      /*e*/ XXXXXXX, XXXXXXX, XXXXXXX, 
        OSM(MOD_LALT), XXXXXXX, XXXXXXX, /*s*/ XXXXXXX, XXXXXXX, XXXXXXX,       /*m*/ XXXXXXX, XXXXXXX, XXXXXXX,     /*e*/ XXXXXXX, XXXXXXX, TO(0),
                                         /*s*/ XXXXXXX, OSM(MOD_LSFT), XXXXXXX, /*m*/ KC_BSPC, KC_SPC, OSM(MOD_LCTL) /*e*/
    ),
    [6] = LAYOUT_split_3x6_3( // GAMING LAYER
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LGUI, 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(0), 
        KC_PAST, KC_SPC, MO(7),                    KC_BSPC, KC_SPC, KC_LALT
    ),
    [7] = LAYOUT_split_3x6_3( // SECONDARY GAMING LAYER
        KC_ESC, KC_1, KC_W, KC_2, KC_3, KC_4,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_LSFT, KC_A, KC_S, KC_D, KC_5, KC_6,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_LCTL, KC_7, KC_8, KC_9, KC_0, KC_MINS,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), 
        KC_PAST, KC_SPC, KC_TRNS,                       LALT(KC_TAB), KC_MPLY, LGUI(KC_1)
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        
        switch (keycode) {
            case UP4:
                SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
                return false;
            case UP12:
                SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
                return false;
            case DOWN4:
                SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN));
                return false;
            case DOWN12:
                SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN));
                return false;
            case LEFT4:
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                return false;
            case LEFT12:
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                return false;
            case RIGHT4:
                SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
                return false;
            case RIGHT12:
                SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
                return false;
            case NTAB3:
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_PGDN)SS_TAP(X_PGDN)SS_TAP(X_PGDN)SS_UP(X_LCTL));
                return false;
            case PTAB3:
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_PGUP)SS_TAP(X_PGUP)SS_TAP(X_PGUP)SS_UP(X_LCTL));
                return false;
            case BS4:
                SEND_STRING(SS_TAP(X_BSPC)SS_TAP(X_BSPC)SS_TAP(X_BSPC)SS_TAP(X_BSPC));
                return false;
            case PGUP3:
                SEND_STRING(SS_TAP(X_PGUP)SS_TAP(X_PGUP)SS_TAP(X_PGUP));
                return false;
            case PGDN3:
                SEND_STRING(SS_TAP(X_PGDN)SS_TAP(X_PGDN)SS_TAP(X_PGDN));
                return false;
            case RWND:
                SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI)SS_DELAY(30)SS_TAP(X_LEFT)SS_DELAY(5)SS_TAP(X_LEFT)SS_DELAY(30)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_DELAY(20)SS_UP(X_LALT));
                return false;
            case RWND2:
                SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI)SS_DELAY(30)SS_TAP(X_LEFT)SS_DELAY(5)SS_TAP(X_LEFT)SS_DELAY(5)SS_TAP(X_LEFT)SS_DELAY(5)SS_TAP(X_LEFT)SS_DELAY(30)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_DELAY(20)SS_UP(X_LALT));
                return false;
        }
    }

    return true;
};

//TODO Make Rewind Macro (Or just copy it), also want larger rewind on multiplication layer

