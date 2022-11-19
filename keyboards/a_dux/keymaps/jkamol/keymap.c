// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

// Seniply layout
// https://stevep99.github.io/seniply

#define MAIN_L   0
#define QWERTY_L 1
#define SYM_L    2
#define NAV_L    3
#define FN_L     4
#define NUMPAD_L 5
#define MACRO_L  6

enum combo_events {
  LPAR,
  RPAR,
  ALT_TAB,
  ENTER,
  ESC,
  FLIP,
  CH_LANG,
  GV_MACRO,
  MK_MACRO,
  MACRO,
  NUM_MO,
  NUM_TO,
  FN_TO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM enter_combo[] = {LALT_T(KC_R), KC_S, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM flip_combo[] = {LCTL_T(KC_TAB), LT(SYM_L,KC_SPACE), COMBO_END};
const uint16_t PROGMEM gv_combo[] = {KC_G, LGUI_T(KC_V), COMBO_END};
const uint16_t PROGMEM lang_combo[] = {LSFT_T(KC_A), LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM mk_combo[] = {KC_M, RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM macro_combo[] = {LT(SYM_L,KC_SPACE), LT(3,KC_BSPACE), COMBO_END};
const uint16_t PROGMEM num_mo_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM num_to_combo[] = {KC_T, KC_D, KC_G, LGUI_T(KC_V), COMBO_END};
const uint16_t PROGMEM fn_to_combo[] = {KC_N, KC_H, KC_M, RGUI_T(KC_K), COMBO_END};

combo_t key_combos[] = {
  [ENTER] = COMBO(enter_combo, KC_ENTER),
  [ESC]   = COMBO(escape_combo, KC_ESCAPE),
  [FLIP]  = COMBO(flip_combo, SH_OS),
  [CH_LANG]  = COMBO(lang_combo, LALT(KC_LSHIFT)),
  [GV_MACRO] = COMBO(gv_combo, MO(MACRO_L)),
  [MK_MACRO] = COMBO(mk_combo, MO(MACRO_L)),
  [MACRO]    = COMBO(macro_combo, MO(MACRO_L)),
  [NUM_MO] = COMBO(num_mo_combo, MO(NUMPAD_L)),
  [NUM_TO] = COMBO(num_to_combo, TO(NUMPAD_L)),
  [FN_TO]  = COMBO(fn_to_combo, TO(FN_L)),
};

enum tap_dance_codes {
  DANCE_QUIT,
  DANCE_TASK,
  DANCE_QWERTY,
  DANCE_PWR,
  DANCE_SCR,
  DANCE_FN,
  DANCE_MAIN,
  DANCE_INS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN_L] = LAYOUT_split_3x5_2(
    RCS_T(KC_Q),    KC_W,           KC_F,           KC_P,           RALT_T(KC_B),   /**/ RALT_T(KC_J),   KC_L,           KC_U,           KC_Y,           RCS_T(KC_QUOTE), 
    LSFT_T(KC_A),   LALT_T(KC_R),   KC_S,           KC_T,           KC_G,           /**/ KC_M,           KC_N,           KC_E,           KC_I,           RSFT_T(KC_O),
    LCTL_T(KC_Z),   KC_X,           KC_C,           KC_D,           LGUI_T(KC_V),   /**/ RGUI_T(KC_K),   KC_H,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),
    LCTL_T(KC_TAB), LT(SYM_L,KC_SPACE),                                             /**/ LT(NAV_L,KC_BSPACE), LT(FN_L,KC_ENTER)
  ),
  [QWERTY_L] = LAYOUT_split_3x5_2(
    _______,        _______,        KC_E,           KC_R,           RALT_T(KC_T),   /**/ RALT_T(KC_Y),   KC_U,           KC_I,           KC_O,           RCS_T(KC_P), 
    _______,        LALT_T(KC_S),   KC_D,           KC_F,           _______,        /**/ KC_H,           KC_J,           KC_K,           KC_L,           RSFT_T(KC_SCOLON),
    _______,        _______,        _______,        KC_V,           LGUI_T(KC_B),   /**/ RGUI_T(KC_N),   KC_M,           _______,        _______,        _______,
    _______,        _______,                                                        /**/ _______,        _______ 
  ),
  [SYM_L] = LAYOUT_split_3x5_2(
    TD(DANCE_QUIT), KC_7,           TD(DANCE_TASK), KC_9,           KC_0,           /**/ KC_CIRCUMFLEX,  KC_AMPERSAND,   KC_AT,          KC_HASH,        KC_DOLLAR,
    LSFT_T(KC_1),   KC_2,           KC_3,           KC_4,           KC_5,           /**/ KC_GRAVE,       KC_MINUS,       KC_ASTERISK,    KC_EQUAL,       RSFT_T(KC_SCOLON),
    LCTL(KC_Z),     KC_BSPC,        TD(DANCE_SCR),  KC_DEL,         LCTL(KC_Y),     /**/ KC_PERCENT,     KC_LBRACKET,    KC_RBRACKET,    KC_EXCLAIM,     RCTL_T(KC_BACKSLASH),
    MO(FN_L),       XXXXXXX,                                                        /**/ _______,        _______
  ),
  [NAV_L] = LAYOUT_split_3x5_2(
    TD(DANCE_QWERTY), KC_MS_WH_UP,  KC_MS_UP,       KC_MS_BTN3,     KC_LALT,        /**/ KC_ACL0,        KC_APPLICATION, KC_UP,          KC_PGUP,        KC_CAPSLOCK,
    KC_LSHIFT,      KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_INSERT,      /**/ KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       RSFT_T(KC_END),
    KC_LCTRL,       KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_LGUI,        /**/ KC_BSPACE,      KC_DELETE,      LALT(KC_LSHIFT),KC_PGDOWN,      KC_RCTRL,
    KC_MS_BTN2,     KC_MS_BTN1,                                                     /**/ XXXXXXX,        KC_LALT
  ),
  [FN_L] = LAYOUT_split_3x5_2(
    KC_1,           KC_2,           KC_3,           KC_4,           KC_PAUSE,       /**/ KC_SCROLLLOCK,  TD(DANCE_PWR),  LCA(KC_DELETE), XXXXXXX,        XXXXXXX,
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          /**/ KC_F12,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         /**/ KC_F11,         DM_REC1,        DM_REC2,        DM_RSTP,        KC_RCTRL,
    MO(NUMPAD_L),   KC_LALT,                                                        /**/ KC_TAB,         TO(MAIN_L)
  ),
  [NUMPAD_L] = LAYOUT_split_3x5_2(
    KC_Q,           KC_M,           KC_F,           KC_P,           KC_T,           /**/ TD(DANCE_INS),  KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,
    KC_1,           KC_2,           KC_3,           KC_4,           TD(DANCE_MAIN), /**/ KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_DOT,
    LCTL_T(KC_Z),   KC_X,           KC_C,           KC_S,           KC_B,           /**/ KC_BSPACE,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_SLASH,
    _______,        KC_LALT,                                                        /**/ _______,        KC_KP_0
  ),
  [MACRO_L] = LAYOUT_split_3x5_2(
    KC_AUDIO_MUTE,  KC_VOLU,        DM_PLY1,        DM_PLY2,        XXXXXXX,        /**/ XXXXXXX,        KC_CALCULATOR,  XXXXXXX,        XXXXXXX,        XXXXXXX,
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           /**/ KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
    KC_MPRV,        KC_VOLD,        KC_MNXT,        KC_MPLY,        XXXXXXX,        /**/ KC_BSPACE,      KC_DELETE,      KC_COMMA,       KC_DOT,         KC_SLASH,
	LALT(KC_LEFT),  LALT(KC_RIGHT),                                                 /**/ _______,        _______
  ),
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[13];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_DANCE_QUIT(qk_tap_dance_state_t *state, void *user_data);
void DANCE_QUIT_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_QUIT_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_QUIT(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void DANCE_QUIT_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F4)); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void DANCE_QUIT_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[9].step = 0;
}
void on_DANCE_TASK(qk_tap_dance_state_t *state, void *user_data);
void DANCE_TASK_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_TASK_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_TASK(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

void DANCE_TASK_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_8); break;
        case SINGLE_HOLD: register_code16(RCS(KC_ESC)); break;
        case DOUBLE_TAP: register_code16(KC_8); register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_8); register_code16(KC_8);
    }
}

void DANCE_TASK_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_8); break;
        case SINGLE_HOLD: unregister_code16(RCS(KC_ESC)); break;
        case DOUBLE_TAP: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_8); break;
    }
    dance_state[9].step = 0;
}
void DANCE_QWERTY_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_QWERTY_reset(qk_tap_dance_state_t *state, void *user_data);

void DANCE_QWERTY_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: layer_move(MAIN_L); break;
        case SINGLE_HOLD: layer_move(QWERTY_L); break;
        case DOUBLE_TAP: layer_move(MAIN_L); break;
        case DOUBLE_SINGLE_TAP: layer_move(MAIN_L); break;
    }
}

void DANCE_QWERTY_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
    }
    dance_state[7].step = 0;
}
void DANCE_PWR_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_PWR_reset(qk_tap_dance_state_t *state, void *user_data);

void DANCE_PWR_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case DOUBLE_TAP: register_code16(KC_SYSTEM_POWER); break;
    }
}

void DANCE_PWR_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case DOUBLE_TAP: unregister_code16(KC_SYSTEM_POWER); break;
    }
    dance_state[8].step = 0;
}
void on_DANCE_SCR(qk_tap_dance_state_t *state, void *user_data);
void DANCE_SCR_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_SCR_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_SCR(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
        tap_code16(KC_PSCREEN);
    }
    if(state->count > 3) {
        tap_code16(KC_PSCREEN);
    }
}

void DANCE_SCR_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: register_code16(KC_PSCREEN); register_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PSCREEN); register_code16(KC_PSCREEN);
    }
}

void DANCE_SCR_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: unregister_code16(KC_PSCREEN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PSCREEN); break;
    }
    dance_state[9].step = 0;
}
void on_DANCE_MAIN(qk_tap_dance_state_t *state, void *user_data);
void DANCE_MAIN_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_MAIN_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_MAIN(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void DANCE_MAIN_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_HOLD: layer_move(MAIN_L); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void DANCE_MAIN_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[11].step = 0;
}
void on_DANCE_INS(qk_tap_dance_state_t *state, void *user_data);
void DANCE_INS_finished(qk_tap_dance_state_t *state, void *user_data);
void DANCE_INS_reset(qk_tap_dance_state_t *state, void *user_data);

void on_DANCE_INS(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void DANCE_INS_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_TAP: register_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK); break;
        case DOUBLE_HOLD: register_code16(KC_NUMLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ASTERISK); register_code16(KC_KP_ASTERISK);
    }
}

void DANCE_INS_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
        case DOUBLE_HOLD: unregister_code16(KC_NUMLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ASTERISK); break;
    }
    dance_state[12].step = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_QUIT] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_QUIT, DANCE_QUIT_finished, DANCE_QUIT_reset),
        [DANCE_TASK] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_TASK, DANCE_TASK_finished, DANCE_TASK_reset),
        [DANCE_QWERTY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DANCE_QWERTY_finished, DANCE_QWERTY_reset),
        [DANCE_PWR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DANCE_PWR_finished, DANCE_PWR_reset),
        [DANCE_SCR] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_SCR, DANCE_SCR_finished, DANCE_SCR_reset),
        [DANCE_MAIN] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_MAIN, DANCE_MAIN_finished, DANCE_MAIN_reset),
        [DANCE_INS] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_INS, DANCE_INS_finished, DANCE_INS_reset),
};
