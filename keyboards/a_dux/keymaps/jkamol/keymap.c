// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

// Seniply layout
// https://stevep99.github.io/seniply

enum layer_names {
    _MAIN,
    _QWERTY,
    _SYM,
    _NAV,
    _FN,
    _NUMPAD,
    _MACRO,
};

enum combo_events {
    ENTER,
    ESC,
    FLIP,
    FN_TO,
    LANG_SW,
    MACRO_CR,
    MACRO_LT,
    MACRO_RT,
    NUM_MO,
    NUM_TO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM enter_combo[]    = {LALT_T(KC_R), KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM escape_combo[]   = {KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM flip_combo[]     = {LCTL_T(KC_TAB), LT(_SYM,KC_SPACE), COMBO_END};
const uint16_t PROGMEM fn_to_combo[]    = {KC_N, KC_H, KC_M, RGUI_T(KC_X), COMBO_END};
const uint16_t PROGMEM lang_sw_combo[]  = {LSFT_T(KC_C), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM macro_cr_combo[] = {LT(_SYM,KC_SPACE), LT(3,KC_BSPC), COMBO_END};
const uint16_t PROGMEM macro_lt_combo[] = {KC_G, LGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM macro_rt_combo[] = {KC_M, RGUI_T(KC_X), COMBO_END};
const uint16_t PROGMEM num_mo_combo[]   = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM num_to_combo[]   = {KC_T, KC_D, KC_G, LGUI_T(KC_K), COMBO_END};

combo_t key_combos[] = {
    [ENTER]    = COMBO(enter_combo, KC_ENTER),
    [ESC]      = COMBO(escape_combo, KC_ESCAPE),
    [FLIP]     = COMBO(flip_combo, SH_OS),
    [FN_TO]    = COMBO(fn_to_combo, TO(_FN)),
    [LANG_SW]  = COMBO(lang_sw_combo, LALT(KC_LSFT)),
    [MACRO_CR] = COMBO(macro_cr_combo, MO(_MACRO)),
    [MACRO_LT] = COMBO(macro_lt_combo, MO(_MACRO)),
    [MACRO_RT] = COMBO(macro_rt_combo, MO(_MACRO)),
    [NUM_MO]   = COMBO(num_mo_combo, MO(_NUMPAD)),
    [NUM_TO]   = COMBO(num_to_combo, TO(_NUMPAD)),
};

enum tap_dance_codes {
    DANCE_QUIT,
    DANCE_TASK,
    DANCE_UNDO,
    DANCE_QWERTY,
    DANCE_PWR,
    DANCE_SCR,
    DANCE_FN,
    DANCE_MAIN,
    DANCE_INS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x5_2(
        C_S_T(KC_W),    KC_L,           KC_Y,           KC_P,           RALT_T(KC_B),       /**/ RALT_T(KC_Z),      KC_F,           KC_O,           KC_U,           C_S_T(KC_QUOTE),
        LSFT_T(KC_C),   LALT_T(KC_R),   KC_S,           KC_T,           KC_G,               /**/ KC_M,              KC_N,           KC_E,           KC_I,           LSFT_T(KC_A),
        LCTL_T(KC_Q),   KC_J,           KC_V,           KC_D,           LGUI_T(KC_K),       /**/ RGUI_T(KC_X),      KC_H,           KC_SLASH,       KC_COMMA,       LCTL_T(KC_DOT),
                                                        LCTL_T(KC_TAB), LT(_SYM,KC_SPACE),  /**/ LT(_NAV,KC_BSPC),  LT(_FN,KC_ENTER)
    ),
    [_QWERTY] = LAYOUT_split_3x5_2(
        C_S_T(KC_Q),    KC_W,           KC_E,           KC_R,           RALT_T(KC_T),       /**/ RALT_T(KC_Y),      KC_U,           KC_I,           KC_O,           C_S_T(KC_P),
        LSFT_T(KC_A),   LALT_T(KC_S),   KC_D,           KC_F,           KC_G,               /**/ KC_H,              KC_J,           KC_K,           KC_L,           LSFT_T(KC_SCLN),
        LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           LGUI_T(KC_B),       /**/ RGUI_T(KC_N),      KC_M,           KC_COMMA,       KC_DOT,         LCTL_T(KC_SLASH),
                                                        _______,        _______,            /**/ _______,           _______
    ),
    [_SYM] = LAYOUT_split_3x5_2(
        TD(DANCE_QUIT), KC_7,           TD(DANCE_TASK), KC_9,           KC_0,               /**/ KC_CIRCUMFLEX,     KC_AMPERSAND,   KC_AT,          KC_HASH,        KC_DOLLAR,
        LSFT_T(KC_1),   KC_2,           KC_3,           KC_4,           KC_5,               /**/ KC_GRAVE,          KC_MINUS,       KC_ASTERISK,    KC_EQUAL,       LSFT_T(KC_SCLN),
        TD(DANCE_UNDO), KC_BSPC,        TD(DANCE_SCR),  KC_DEL,         LCTL(KC_Y),         /**/ KC_PERCENT,        KC_LBRC,        KC_BACKSLASH,   KC_EXCLAIM,     LCTL_T(KC_RBRC),
                                                        MO(_FN),        XXXXXXX,            /**/ _______,           _______
    ),
    [_NAV] = LAYOUT_split_3x5_2(
        TD(DANCE_QWERTY), KC_MS_WH_UP,  KC_MS_UP,       KC_MS_BTN3,     KC_LALT,            /**/ KC_ACL0,           KC_APPLICATION, KC_UP,          KC_PAGE_UP,     KC_CAPS_LOCK,
        KC_LSFT,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_INSERT,          /**/ KC_HOME,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       LSFT_T(KC_END),
        KC_LCTL,        KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_LGUI,            /**/ KC_BSPC,           KC_DELETE,      LALT(KC_LSFT),  KC_PAGE_DOWN,   KC_LCTL,
                                                        KC_MS_BTN2,     KC_MS_BTN1,         /**/ XXXXXXX,           KC_LALT
    ),
    [_FN] = LAYOUT_split_3x5_2(
        KC_1,           KC_2,           KC_3,           KC_4,           KC_PAUSE,           /**/ KC_SCROLL_LOCK,    TD(DANCE_PWR),  LCA(KC_DELETE), KC_VOLU,        XXXXXXX,
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,              /**/ KC_F12,            KC_MPRV,        KC_MPLY,        KC_MUTE,        KC_MNXT,
        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,             /**/ KC_F11,            XXXXXXX,        XXXXXXX,        KC_VOLD,        KC_LCTL,
                                                        MO(_NUMPAD),    KC_LALT,            /**/ KC_TAB,            TO(_MAIN)
    ),
    [_NUMPAD] = LAYOUT_split_3x5_2(
        KC_Q,           KC_M,           KC_F,           KC_P,           KC_T,               /**/ TD(DANCE_INS),     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,
        KC_1,           KC_2,           KC_3,           KC_4,           TD(DANCE_MAIN),     /**/ KC_KP_PLUS,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_DOT,
        LCTL_T(KC_Z),   KC_X,           KC_C,           KC_S,           KC_B,               /**/ KC_BSPC,           KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,
                                                        _______,        KC_LALT,            /**/ _______,           KC_KP_0
    ),
    [_MACRO] = LAYOUT_split_3x5_2(
        XXXXXXX,        DM_REC1,        DM_REC2,        XXXXXXX,        XXXXXXX,            /**/ XXXXXXX,           KC_CALCULATOR,  XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,               /**/ KC_6,              KC_7,           KC_8,           KC_9,           KC_0,
        DM_RSTP,        DM_PLY1,        DM_PLY2,        XXXXXXX,        XXXXXXX,            /**/ KC_BSPC,           KC_DELETE,      KC_SLASH,       KC_COMMA,       KC_DOT,
                                                        LALT(KC_LEFT),  LALT(KC_RIGHT),     /**/ _______,           _______
    ),
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t'
static td_tap_t tap_state;

void on_DANCE_QUIT(tap_dance_state_t *state, void *user_data);
void DANCE_QUIT_finished(tap_dance_state_t *state, void *user_data);
void DANCE_QUIT_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_QUIT(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void DANCE_QUIT_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_6); break;
        case TD_SINGLE_HOLD:        register_code16(LALT(KC_F4)); break;
        case TD_DOUBLE_TAP:         register_code16(KC_6); register_code16(KC_6); break;
        case TD_DOUBLE_HOLD:        register_code16(LALT(KC_F4)); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(KC_6); register_code16(KC_6); break;
        default: break;
    }
}

void DANCE_QUIT_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_6); break;
        case TD_SINGLE_HOLD:        unregister_code16(LALT(KC_F4)); break;
        case TD_DOUBLE_TAP:         unregister_code16(KC_6); break;
        case TD_DOUBLE_HOLD:        unregister_code16(LALT(KC_F4)); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(KC_6); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void on_DANCE_TASK(tap_dance_state_t *state, void *user_data);
void DANCE_TASK_finished(tap_dance_state_t *state, void *user_data);
void DANCE_TASK_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_TASK(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

void DANCE_TASK_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_8); break;
        case TD_SINGLE_HOLD:        register_code16(RCS(KC_ESC)); break;
        case TD_DOUBLE_TAP:         register_code16(KC_8); register_code16(KC_8); break;
        case TD_DOUBLE_HOLD:        register_code16(RCS(KC_ESC)); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(KC_8); register_code16(KC_8); break;
        default: break;
    }
}

void DANCE_TASK_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_8); break;
        case TD_SINGLE_HOLD:        unregister_code16(RCS(KC_ESC)); break;
        case TD_DOUBLE_TAP:         unregister_code16(KC_8); break;
        case TD_DOUBLE_HOLD:        unregister_code16(RCS(KC_ESC)); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(KC_8); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void on_DANCE_UNDO(tap_dance_state_t *state, void *user_data);
void DANCE_UNDO_finished(tap_dance_state_t *state, void *user_data);
void DANCE_UNDO_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_UNDO(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
        tap_code16(LCTL(KC_Z));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_Z));
    }
}

void DANCE_UNDO_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(LCTL(KC_Z)); break;
        case TD_SINGLE_HOLD:        register_code16(KC_LCTL); break;
        case TD_DOUBLE_TAP:         register_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        case TD_DOUBLE_HOLD:        register_code16(KC_LCTL); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(LCTL(KC_Z)); register_code16(LCTL(KC_Z)); break;
        default: break;
    }
}

void DANCE_UNDO_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(LCTL(KC_Z)); break;
        case TD_SINGLE_HOLD:        unregister_code16(KC_LCTL); break;
        case TD_DOUBLE_TAP:         unregister_code16(LCTL(KC_Z)); break;
        case TD_DOUBLE_HOLD:        unregister_code16(KC_LCTL); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(LCTL(KC_Z)); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void DANCE_QWERTY_finished(tap_dance_state_t *state, void *user_data);
void DANCE_QWERTY_reset(tap_dance_state_t *state, void *user_data);

void DANCE_QWERTY_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         layer_move(_MAIN); break;
        case TD_SINGLE_HOLD:        layer_move(_QWERTY); break;
        case TD_DOUBLE_TAP:         layer_move(_MAIN); break;
        case TD_DOUBLE_HOLD:        layer_move(_QWERTY); break;
        case TD_DOUBLE_SINGLE_TAP:  layer_move(_MAIN); break;
        default: break;
    }
}

void DANCE_QWERTY_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        default: break;
    }
    tap_state.state = TD_NONE;
}


void DANCE_PWR_finished(tap_dance_state_t *state, void *user_data);
void DANCE_PWR_reset(tap_dance_state_t *state, void *user_data);

void DANCE_PWR_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_DOUBLE_HOLD:        register_code16(KC_SYSTEM_POWER); break;
        default: break;
    }
}

void DANCE_PWR_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_DOUBLE_HOLD:        unregister_code16(KC_SYSTEM_POWER); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void on_DANCE_SCR(tap_dance_state_t *state, void *user_data);
void DANCE_SCR_finished(tap_dance_state_t *state, void *user_data);
void DANCE_SCR_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_SCR(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PRINT_SCREEN);
        tap_code16(KC_PRINT_SCREEN);
        tap_code16(KC_PRINT_SCREEN);
    }
    if(state->count > 3) {
        tap_code16(KC_PRINT_SCREEN);
    }
}

void DANCE_SCR_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_PRINT_SCREEN); break;
        case TD_SINGLE_HOLD:        register_code16(LGUI(LSFT(KC_S))); break;
        case TD_DOUBLE_TAP:         register_code16(KC_PRINT_SCREEN); register_code16(KC_PRINT_SCREEN); break;
        case TD_DOUBLE_HOLD:        register_code16(LGUI(LSFT(KC_S))); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(KC_PRINT_SCREEN); register_code16(KC_PRINT_SCREEN); break;
        default: break;
    }
}

void DANCE_SCR_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_PRINT_SCREEN); break;
        case TD_SINGLE_HOLD:        unregister_code16(LGUI(LSFT(KC_S))); break;
        case TD_DOUBLE_TAP:         unregister_code16(KC_PRINT_SCREEN); break;
        case TD_DOUBLE_HOLD:        unregister_code16(LGUI(LSFT(KC_S))); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(KC_PRINT_SCREEN); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void on_DANCE_MAIN(tap_dance_state_t *state, void *user_data);
void DANCE_MAIN_finished(tap_dance_state_t *state, void *user_data);
void DANCE_MAIN_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_MAIN(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void DANCE_MAIN_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_5); break;
        case TD_DOUBLE_TAP:         register_code16(KC_5); register_code16(KC_5); break;
        case TD_DOUBLE_HOLD:        layer_move(_MAIN); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(KC_5); register_code16(KC_5); break;
        default: break;
    }
}

void DANCE_MAIN_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_5); break;
        case TD_DOUBLE_TAP:         unregister_code16(KC_5); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(KC_5); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}


void on_DANCE_INS(tap_dance_state_t *state, void *user_data);
void DANCE_INS_finished(tap_dance_state_t *state, void *user_data);
void DANCE_INS_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_INS(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void DANCE_INS_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_KP_ASTERISK); break;
        case TD_DOUBLE_TAP:         register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case TD_DOUBLE_HOLD:        register_code16(KC_NUM_LOCK); break;
        case TD_DOUBLE_SINGLE_TAP:  tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        default: break;
    }
}

void DANCE_INS_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_KP_ASTERISK); break;
        case TD_DOUBLE_TAP:         unregister_code16(KC_KP_ASTERISK); break;
        case TD_DOUBLE_HOLD:        unregister_code16(KC_NUM_LOCK); break;
        case TD_DOUBLE_SINGLE_TAP:  unregister_code16(KC_KP_ASTERISK); break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

tap_dance_action_t  tap_dance_actions[] = {
    [DANCE_QUIT]   = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_QUIT, DANCE_QUIT_finished, DANCE_QUIT_reset),
    [DANCE_TASK]   = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_TASK, DANCE_TASK_finished, DANCE_TASK_reset),
    [DANCE_UNDO]   = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_UNDO, DANCE_UNDO_finished, DANCE_UNDO_reset),
    [DANCE_QWERTY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DANCE_QWERTY_finished, DANCE_QWERTY_reset),
    [DANCE_PWR]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DANCE_PWR_finished, DANCE_PWR_reset),
    [DANCE_SCR]    = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_SCR, DANCE_SCR_finished, DANCE_SCR_reset),
    [DANCE_MAIN]   = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_MAIN, DANCE_MAIN_finished, DANCE_MAIN_reset),
    [DANCE_INS]    = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_INS, DANCE_INS_finished, DANCE_INS_reset),
};
