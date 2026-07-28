// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    DEF,
    NUM,
    NMX,
    SYS,
    TYP,
    SYM,
    SMX,
    NAV,
    EDT,
};

#define TOP_G LT(TYP,KC_G)
#define TOP_F LT(EDT,KC_F)
#define TOP_Y LT(NMX,KC_Y)
#define TOP_O LT(SMX,KC_O)
#define TOP_L LT(NUM,KC_L)
#define TOP_U LT(SYM,KC_U)

#define HOME_T LT(SYS,KC_T)
#define HOME_N LT(NAV,KC_N)
#define HOME_S LT(NMX,KC_S)
#define HOME_A LT(SMX,KC_A)
#define HOME_R LT(NUM,KC_R)
#define HOME_E LT(SYM,KC_E)

#define BOTM_D LGUI_T(KC_D)
#define BOTM_H RGUI_T(KC_H)
#define BOTM_V LALT_T(KC_V)
#define BOTM_CM RALT_T(KC_COMM)
#define BOTM_X LCTL_T(KC_X)
#define BOTM_DT RCTL_T(KC_DOT)

#define THMB_SP LSFT_T(KC_SPC)
#define THMB_BS RSFT_T(KC_BSPC)

#define EN_DASH A(KC_MINS)
#define EM_DASH S(A(KC_MINS))
#define NOT_EQL A(KC_EQL)
#define PL_MINS S(A(KC_EQL))

enum custom_keycodes {
    // Special keycodes.
    CAPSWRD = SAFE_RANGE,
    REPEAT,
    MAGIC,

    // Macros.
    KM_FN,
    KM_NB,
    KM_NF,
    KM_PH,

    LOGIN,
    EMAIL,

    VIM_Q,
    VIM_WQ,
    VIM_W,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
        _______, KC_Q,    TOP_L,   TOP_Y,   TOP_G,   KC_K,                      KC_B,    TOP_F,   TOP_O,   TOP_U,   KC_J,    _______,
        _______, KC_C,    HOME_R,  HOME_S,  HOME_T,  KC_M,                      MAGIC,   HOME_N,  HOME_A,  HOME_E,  KC_I,    _______,
        _______, KC_Z,    BOTM_X,  BOTM_V,  BOTM_D,  KC_W,                      KC_P,    BOTM_H,  BOTM_CM, BOTM_DT, KC_SLSH, _______,
                                            REPEAT,  THMB_SP, KC_TAB,  KC_ENT,  THMB_BS, KC_ESC
    ),

    [NUM] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_8,    KC_9,    KC_0,    XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                   MAGIC,   KC_1,    KC_2,    KC_3,    KC_4,    _______,
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_5,    KC_6,    KC_7,    KC_SLSH, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [NMX] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                   MAGIC,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_QUES, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [SYS] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, QK_BOOT,                   XXXXXXX, KM_FN,   KC_MINS, KC_COLN, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                   KM_NB,   KM_NF,   KC_VOLD, KC_VOLU, KC_MUTE, _______,
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KM_PH,   KC_BRID, KC_BRIU, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [TYP] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KM_FN,   LOGIN,   EMAIL,   XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                   KM_NB,   KM_NF,   KC_VOLD, KC_VOLU, KC_MUTE, _______,
        _______, _______, _______, _______, _______, _______,                   XXXXXXX, KM_PH,   KC_BRID, KC_BRIU, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [SYM] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_QUOT, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
        _______, KC_BSLS, KC_GRV,  KC_MINS, KC_SCLN, CAPSWRD,                   _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, NOT_EQL, EN_DASH, KC_EQL,  XXXXXXX,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [SMX] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_DQUO, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
        _______, KC_PIPE, KC_TILD, KC_UNDS, KC_COLN, KC_CAPS,                   _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, PL_MINS, EM_DASH, KC_PLUS, XXXXXXX,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_HOME, KC_END,  KC_Q,    XXXXXXX,                   _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_INS,                    _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_PGUP, KC_PGDN, KC_DEL,  XXXXXXX,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),

    [EDT] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, VIM_W,   VIM_WQ,  VIM_Q,   XXXXXXX,                   _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_INS,                    _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_PGUP, KC_PGDN, KC_DEL,  XXXXXXX,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),
};

bool should_cw_continue(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false;
    }
}

bool should_cw_shift(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            return true;
        default:
            return false;
    }
}

bool cw_enabled = false;

uint16_t get_cw_keycode(uint16_t keycode) {
    if (cw_enabled) {
        cw_enabled = should_cw_continue(keycode);
        if (should_cw_shift(keycode)) {
            return S(keycode);
        }
    }
    return keycode;
}

uint16_t skip_keycode = KC_NO;
uint16_t prev_keycode = KC_NO;

void cw_tap(uint16_t keycode) {
    skip_keycode = prev_keycode;
    prev_keycode = keycode;
    tap_code16(get_cw_keycode(keycode));
}

void cw_prep(uint16_t keycode) {
    skip_keycode = prev_keycode;
    prev_keycode = keycode;
    if (keycode != get_cw_keycode(keycode)) {
        // Apply shift to the next key.
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
}

uint16_t get_magic_keycode(void) {
    if (IS_LAYER_ON(NMX)) {
        switch (prev_keycode) {
            case KC_EXLM:
                return KC_EQL;
            default:
                return KC_DQUO;
        }
    }

    if (IS_LAYER_ON(NUM)) {
        switch (prev_keycode) {
            case KC_1 ... KC_0:
                return KC_DOT;
            default:
                return KC_QUOT;
        }
    }

    switch (prev_keycode) {
        // Left half.
        case KC_Q:
            cw_tap(KC_U);
            cw_tap(KC_E);
            return KC_N;
        case KC_C:
            switch (skip_keycode) {
                case KC_X:
                    return KC_H;
                default:
                    return KC_Q;
            }
        case KC_Z:
        case KC_X:
            return KC_C;
        case KC_L:
            return KC_R;
        case KC_R:
            return KC_L;
        case KC_Y:
        case KC_V:
            return KC_S;
        case KC_S:
            return KC_Y;
        case KC_G:
        case KC_M:
            return KC_D;
        case KC_T:
            return KC_W;
        case KC_D:
            switch (skip_keycode) {
                case KC_G:
                case KC_K:
                    return KC_B;
                default:
                    return KC_G;
            }
        case KC_K:
            switch (skip_keycode) {
                case KC_C:
                case KC_E:
                    return KC_D;
                default:
                    return KC_W;
            }
        case KC_W:
            switch (skip_keycode) {
                case KC_E:
                    return KC_M;
                default:
                    cw_tap(KC_T);
                    return KC_H;
            }

        // Right half.
        case KC_B:
        case KC_N:
            return KC_P;
        case KC_P:
            return KC_B;
        case KC_O:
        case KC_COMM:
            return KC_A;
        case KC_A:
            switch (skip_keycode) {
                case KC_O:
                    return KC_H;
                default:
                    return KC_COMM;
            }
        case KC_U:
        case KC_J:
        case KC_DOT:
            return KC_E;
        case KC_E:
            switch (skip_keycode) {
                case KC_U:
                case KC_J:
                case KC_DOT:
                    return KC_N;
                default:
                    return KC_DOT;
            }
        case KC_I:
            switch (skip_keycode) {
                case KC_SLSH:
                    return KC_N;
                default:
                    return KC_QUOT;
            }
        case KC_SLSH:
            return KC_I;

        // Punctuation.
        case KC_TAB:
            return KC_SPC;
        case KC_SPC:
            cw_tap(KC_T);
            cw_tap(KC_H);
            return KC_E;
        case KC_BSPC:
            return KC_ESC;
        case KC_ENT:
            return KC_BSPC;

        // Symbols.
        case KC_RPRN:
        case KC_BSLS:
        case KC_GRV:
            return KC_DOT;
        case KC_MINS:
        case KC_EQL:
        case KC_UNDS:
            return KC_RABK;
        case KC_RABK:
        case KC_LABK:
            return KC_EQL;
        case KC_LPRN:
            return KC_LBRC;
        case KC_RBRC:
        case KC_RCBR:
            return KC_RPRN;

        default:
            return KC_NO;
    }
}

static bool on_left_hand(keypos_t pos) {
#ifdef SPLIT_KEYBOARD
    return pos.row < MATRIX_ROWS / 2;
#else
    return (MATRIX_COLS > MATRIX_ROWS) ? pos.col < MATRIX_COLS / 2
                                       : pos.row < MATRIX_ROWS / 2;
#endif
}

bool on_same_hands(keyrecord_t* record, keyrecord_t* other_record) {
    return on_left_hand(record->event.key)
        == on_left_hand(other_record->event.key);
}

uint16_t get_primary_keycode(uint16_t keycode) {
    const bool is_lt = IS_QK_LAYER_TAP(keycode);
    const bool is_tap_hold = is_lt || IS_QK_MOD_TAP(keycode);
    const uint16_t basic = keycode & (is_tap_hold ? 0xff : S(0xff));
    const bool shifted = get_mods() & MOD_MASK_SHIFT;
    switch (basic) {
        case KC_A ... KC_Z:
            return basic;
        default:
            return shifted ? S(basic) : basic;
    }
}

uint16_t press_timer = 0;
uint16_t repeat_keycode = KC_NO;
uint16_t magic_keycode = KC_NO;
uint16_t queued_keycode = KC_NO;
keyrecord_t queued_record;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const bool is_lt = IS_QK_LAYER_TAP(keycode);
    const bool is_tap_hold = is_lt || IS_QK_MOD_TAP(keycode);
    const bool is_held = record->tap.count == 0;
    const bool is_tapped = !(is_tap_hold && is_held);
    const uint16_t primary_keycode = get_primary_keycode(keycode);

    if (record->event.pressed) {
        press_timer = record->event.time;

        // Send queued tap code when we register a same-handed keypress.
        if (queued_keycode != KC_NO && queued_keycode != primary_keycode) {
            if (is_tapped && on_same_hands(record, &queued_record)) {
                cw_tap(queued_keycode);
            }
            queued_keycode = KC_NO;
        }

        switch (keycode) {
            // Special keycodes.
            case CAPSWRD:
                cw_enabled = !cw_enabled;
                return true;
            case REPEAT:
                repeat_keycode = get_cw_keycode(prev_keycode);
                register_code16(repeat_keycode);
                return true;
            case MAGIC:
                magic_keycode = get_magic_keycode();
                skip_keycode = prev_keycode;
                prev_keycode = magic_keycode;
                magic_keycode = get_cw_keycode(magic_keycode);
                register_code16(magic_keycode);
                return true;

            // Macros.
            case KM_FN:
                cw_tap(KC_F);
                cw_tap(KC_N);
                return true;
            case KM_NB:
                cw_tap(KC_N);
                cw_tap(KC_B);
                return true;
            case KM_NF:
                cw_tap(KC_N);
                cw_tap(KC_F);
                return true;
            case KM_PH:
                cw_tap(KC_P);
                cw_tap(KC_H);
                return true;

            case LOGIN:
                SEND_STRING("damirault");
                return true;
            case EMAIL:
                SEND_STRING("david.j.amirault@gmail.com");
                return true;

            case VIM_Q:
                SEND_STRING("\e" SS_DELAY(40) ":q\n");
                return true;
            case VIM_WQ:
                SEND_STRING("\e" SS_DELAY(40) ":wq\n");
                return true;
            case VIM_W:
                SEND_STRING("\e" SS_DELAY(40) ":w\n");
                return true;
        }

        if (is_tapped) {
            cw_prep(primary_keycode);
        }

        // When an LT key is held, queue it for potential tapping.
        if (is_lt && is_held) {
            queued_keycode = primary_keycode;
            queued_record = *record;
        }

    } else {
        switch (keycode) {
            case REPEAT:
                unregister_code16(repeat_keycode);
                return true;
            case MAGIC:
                unregister_code16(magic_keycode);
                return true;
            case CAPSWRD:
            case KM_FN ... VIM_W:
                return true;
        }

        // When a queued LT key is raised, unqueue it.
        if (is_lt && queued_keycode == primary_keycode) {
            queued_keycode = KC_NO;
        }
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THMB_SP:
        case THMB_BS:
            return TAPPING_TERM - 20;
        case BOTM_D:
        case BOTM_H:
        case BOTM_V:
        case BOTM_CM:
        case BOTM_X:
        case BOTM_DT:
            return TAPPING_TERM + 23;
        default:
            // Increase tapping term if a key was pressed recently.
            if (timer_elapsed(press_timer) < TAPPING_TERM - 20) {
                return TAPPING_TERM + 23;
            }
            return TAPPING_TERM;
    }
}
