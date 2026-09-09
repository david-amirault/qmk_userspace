// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    DEF,
    LHS,
    NUM,
    NMS,
    CMD,
    CDS,
    RHS,
    SYM,
    SMS,
    NAV,
    NVS,
};

#define EN_DASH A(KC_MINS)
#define NOT_EQL A(KC_EQL)

enum custom_keycodes {
    // Special keycodes.
    CAPSWRD = SAFE_RANGE,
    MAGIC,

    // Macros.
    KM_NB,
    KM_NF,
    KM_PH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
        _______,    KC_Q,       KC_L,       KC_Y,       KC_G,       KC_K,                               KC_B,       KC_F,       KC_O,       KC_U,       KC_J,       _______,
        _______,    KC_C,       KC_R,       KC_S,       KC_T,       KC_M,                               MAGIC,      KC_N,       KC_A,       KC_E,       KC_I,       _______,
        _______,    KC_Z,       KC_X,       KC_V,       KC_D,       KC_W,                               KC_P,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    _______,
                                                        KC_TAB,     KC_SPC,     MO(LHS),    MO(RHS),    KC_BSPC,    KC_ENT
    ),

    [LHS] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            S(KC_B),    S(KC_F),    S(KC_O),    S(KC_U),    S(KC_J),    _______,
        _______,    S(KC_C),    MO(NUM),    MO(NMS),    MO(CMD),    MO(CDS),                            MAGIC,      S(KC_N),    S(KC_A),    S(KC_E),    S(KC_I),    _______,
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            S(KC_P),    S(KC_H),    S(KC_COMM), S(KC_DOT),  S(KC_SLSH), _______,
                                                        _______,    _______,    _______,    KC_ESC,     S(KC_BSPC), S(KC_ENT)
    ),

    [NUM] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    KC_8,       KC_9,       KC_0,       XXXXXXX,    _______,
        _______,    XXXXXXX,    _______,    MO(NMS),    MO(CMD),    MO(CDS),                            KC_QUOT,    KC_1,       KC_2,       KC_3,       KC_4,       _______,
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    KC_5,       KC_6,       KC_7,       KC_SLSH,    _______,
                                                        _______,    _______,    _______,    KC_ESC,     KC_BSPC,    KC_ENT
    ),

    [NMS] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    S(KC_8),    S(KC_9),    S(KC_0),    XXXXXXX,    _______,
        _______,    XXXXXXX,    MO(NUM),    _______,    MO(CMD),    MO(CDS),                            S(KC_QUOT), S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    _______,
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_SLSH), _______,
                                                        _______,    _______,    _______,    S(KC_ESC),  S(KC_BSPC), S(KC_ENT)
    ),

    [CMD] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    QK_BOOT,                            XXXXXXX,    KC_SCLN,    KC_MINS,    KC_DOT,     XXXXXXX,    _______,
        _______,    XXXXXXX,    MO(NUM),    MO(NMS),    _______,    MO(CDS),                            KM_NB,      KM_NF,      KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    KM_PH,      KC_BRID,    KC_BRIU,    XXXXXXX,    _______,
                                                        _______,    _______,    _______,    KC_ESC,     KC_BSPC,    KC_ENT
    ),

    [CDS] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    S(KC_SCLN), S(KC_MINS), S(KC_DOT),  XXXXXXX,    _______,
        _______,    XXXXXXX,    MO(NUM),    MO(NMS),    MO(CMD),    _______,                            KM_NB,      KM_NF,      S(KC_VOLD), S(KC_VOLU), S(KC_MUTE), _______,
        _______,    XXXXXXX,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,                            XXXXXXX,    KM_PH,      S(KC_BRID), S(KC_BRIU), XXXXXXX,    _______,
                                                        _______,    _______,    _______,    S(KC_ESC),  S(KC_BSPC), S(KC_ENT)
    ),

    [RHS] = LAYOUT_split_3x6_3(
        _______,    S(KC_Q),    S(KC_L),    S(KC_Y),    S(KC_G),    S(KC_K),                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
        _______,    S(KC_C),    S(KC_R),    S(KC_S),    S(KC_T),    S(KC_M),                            MO(NVS),    MO(NAV),    MO(SMS),    MO(SYM),    S(KC_I),    _______,
        _______,    S(KC_Z),    S(KC_X),    S(KC_V),    S(KC_D),    S(KC_W),                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
                                                        S(KC_TAB),  S(KC_SPC),  KC_ESC,     _______,    _______,    _______
    ),

    [SYM] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_QUOT,    XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
        _______,    KC_BSLS,    KC_GRV,     KC_MINS,    KC_SCLN,    CAPSWRD,                            MO(NVS),    MO(NAV),    MO(SMS),    _______,    XXXXXXX,    _______,
        _______,    XXXXXXX,    NOT_EQL,    EN_DASH,    KC_EQL,     XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
                                                        KC_TAB,     KC_SPC,     KC_ESC,     _______,    _______,    _______
    ),

    [SMS] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    S(KC_LBRC), S(KC_RBRC), S(KC_QUOT), XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
        _______,    S(KC_BSLS), S(KC_GRV),  S(KC_MINS), S(KC_SCLN), KC_CAPS,                            MO(NVS),    MO(NAV),    _______,    MO(SYM),    XXXXXXX,    _______,
        _______,    XXXXXXX,    S(NOT_EQL), S(EN_DASH), S(KC_EQL),  XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
                                                        S(KC_TAB),  S(KC_SPC),  S(KC_ESC),  _______,    _______,    _______
    ),

    [NAV] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    KC_HOME,    KC_END,     KC_Q,       XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
        _______,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    KC_INS,                             MO(NVS),    _______,    MO(SMS),    MO(SYM),    XXXXXXX,    _______,
        _______,    XXXXXXX,    KC_PGUP,    KC_PGDN,    KC_DEL,     XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
                                                        KC_TAB,     KC_SPC,     KC_ESC,     _______,    _______,    _______
    ),

    [NVS] = LAYOUT_split_3x6_3(
        _______,    XXXXXXX,    S(KC_HOME), S(KC_END),  S(KC_Q),    XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
        _______,    S(KC_LEFT), S(KC_UP),   S(KC_DOWN), S(KC_RGHT), S(KC_INS),                          _______,    MO(NAV),    MO(SMS),    MO(SYM),    XXXXXXX,    _______,
        _______,    XXXXXXX,    S(KC_PGUP), S(KC_PGDN), S(KC_DEL),  XXXXXXX,                            XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    XXXXXXX,    _______,
                                                        S(KC_TAB),  S(KC_SPC),  S(KC_ESC),  _______,    _______,    _______
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
        case KC_EXLM:
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

uint16_t get_primary_keycode(uint16_t keycode) {
    const uint16_t basic = keycode & S(0xff);
    const bool shifted = get_mods() & MOD_MASK_SHIFT;
    switch (basic) {
        case KC_A ... KC_Z:
            return basic;
        default:
            return shifted ? S(basic) : basic;
    }
}

uint16_t magic_keycode = KC_NO;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const uint16_t primary_keycode = get_primary_keycode(keycode);

    if (record->event.pressed) {
        switch (keycode) {
            // Special keycodes.
            case CAPSWRD:
                cw_enabled = !cw_enabled;
                break;
            case MAGIC:
                magic_keycode = get_magic_keycode();
                skip_keycode = prev_keycode;
                prev_keycode = magic_keycode;
                magic_keycode = get_cw_keycode(magic_keycode);
                register_code16(magic_keycode);
                break;

            // Macros.
            case KM_NB:
                cw_tap(KC_N);
                cw_tap(KC_B);
                break;
            case KM_NF:
                cw_tap(KC_N);
                cw_tap(KC_F);
                break;
            case KM_PH:
                cw_tap(KC_P);
                cw_tap(KC_H);
                break;

            default:
                cw_prep(primary_keycode);
        }
    } else {
        switch (keycode) {
            case MAGIC:
                unregister_code16(magic_keycode);
                break;
        }
    }

    return true;
}
