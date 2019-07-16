#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control                          //Working
    DBG_TOG,            //DEBUG Toggle On / Off                                     //
    DBG_MTRX,           //DEBUG Toggle Matrix Prints                                //
    DBG_KBD,            //DEBUG Toggle Keyboard Prints                              //
    DBG_MOU,            //DEBUG Toggle Mouse Prints                                 //
    MD_BOOT,             //Restart into bootloader after hold timeout                //Working
    TOG                 // Custom
};

enum ctrl_layers {
    _QWERTY,
    _COLEMAK,
    _FF14,
    _FUNCTION
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FUNCTION),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_COLEMAK] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_TRNS,   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_FF14] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_F2,   KC_E,    KC_F3,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_LALT, KC_F1,   KC_S,    KC_D,    KC_F,    KC_F4,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_TRNS,   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_FUNCTION] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   KC_CALC, KC_NO,              RGB_TOG, TG(_FF14), TOG, \
        KC_NO,   RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, KC_NO,   KC_NO,   KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_BSPC,   RGB_MOD, BL_INC,  KC_VOLU, \
        KC_NO,   KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,   KC_NO,     RGB_RMOD,BL_DEC,  KC_VOLD, \
MAGIC_UNSWAP_ALL,KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PENT,\
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   TG_NKRO, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_NO,                                RGB_SAI, \
        MAGIC_SWAP_CONTROL_CAPSLOCK, KC_NO, MAGIC_SWAP_ALT_CAPSLOCK,   KC_NO,            KC_P0,   KC_TRNS, KC_NO, KC_NO,                RGB_HUD, RGB_SAD, RGB_HUI \
    )
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

void rgb_matrix_indicators_user(void)
{
	uint8_t this_led = host_keyboard_leds();

	if (!g_suspend_state && rgb_matrix_config.enable) {
		switch (biton32(layer_state)) {
		case _FUNCTION:
			if (this_led & (1 << USB_LED_NUM_LOCK)) {
				rgb_matrix_set_color(24, 0xFF, 0xFF, 0xFF);
			} else {
				rgb_matrix_set_color(24, 0x00, 0x00, 0x00);
			}
            // F-Keys
			rgb_matrix_set_color(6,  0x66, 0xCC, 0xFF); // f6 (prev)
			rgb_matrix_set_color(7,  0x66, 0xCC, 0xFF); // f7 (play/pause)
			rgb_matrix_set_color(8,  0x66, 0xCC, 0xFF); // f8 (next)
			rgb_matrix_set_color(11, 0x66, 0xCC, 0xFF); // f11 (calc)

            // TKL Area
			rgb_matrix_set_color(13, 0xD6, 0xF5, 0xF5); // print (tog_rgb)
			rgb_matrix_set_color(30, 0x33, 0xCC, 0xCC); // ins (matrix next)
			rgb_matrix_set_color(47, 0x99, 0xE6, 0xE6); // del (matrix prev)
			/* rgb_matrix_set_color(32, 0x00, 0xFF, 0xCC); // home (bl useless) */
			/* rgb_matrix_set_color(49, 0x80, 0xFF, 0xE5); // end (bl_d useless) */
			rgb_matrix_set_color(32, 0x00, 0xFF, 0xCC); // pg_up (volu)
			rgb_matrix_set_color(49, 0x80, 0xFF, 0xE5); // pg_dn (vold)

            // caps/shift/ctrl
			rgb_matrix_set_color(50, 0xFF, 0x00, 0x66); // caps
			rgb_matrix_set_color(76, 0xFF, 0x00, 0x66); // ctrl
			rgb_matrix_set_color(78, 0xFF, 0x00, 0x66); // alt

            // rgb settings
			rgb_matrix_set_color(17, 0xFF, 0x00, 0x66); // 1
			rgb_matrix_set_color(18, 0xFF, 0x00, 0x66); // 2
			rgb_matrix_set_color(19, 0xFF, 0x00, 0xFF); // 3
			rgb_matrix_set_color(20, 0xFF, 0x00, 0xFF); // 4

			// ESDF
			rgb_matrix_set_color(35, 0x21, 0xBD, 0xA9);
			rgb_matrix_set_color(36, 0xCC, 0x99, 0xFF);
			rgb_matrix_set_color(37, 0x21, 0xBD, 0xA9); // W E R
			rgb_matrix_set_color(52, 0xCC, 0x99, 0xFF); // S D F
			rgb_matrix_set_color(53, 0xCC, 0x99, 0xFF);
			rgb_matrix_set_color(54, 0xCC, 0x99, 0xFF);

			// numpad
			rgb_matrix_set_color(24, 0xE1, 0x51, 0x6E);
			rgb_matrix_set_color(25, 0xE1, 0x51, 0x6E);
			rgb_matrix_set_color(26, 0xE1, 0x51, 0x6E); // Num / * -
			rgb_matrix_set_color(27, 0xE1, 0x51, 0x6E);
			rgb_matrix_set_color(41, 0xDA, 0x25, 0x49); 
			rgb_matrix_set_color(42, 0xDA, 0x25, 0x49); // 7 8 9 +
			rgb_matrix_set_color(43, 0xDA, 0x25, 0x49); 
			rgb_matrix_set_color(44, 0xDA, 0x25, 0x49);
			rgb_matrix_set_color(58, 0xAE, 0x1E, 0x3B); 
			rgb_matrix_set_color(59, 0xAE, 0x1E, 0x3B); // 4 5 6 . Enter
			rgb_matrix_set_color(60, 0xAE, 0x1E, 0x3B);
			rgb_matrix_set_color(61, 0xAE, 0x1E, 0x3B);
			rgb_matrix_set_color(62, 0xFF, 0x00, 0x66);
			rgb_matrix_set_color(71, 0x83, 0x16, 0x2c); // 1 2 3
			rgb_matrix_set_color(72, 0x83, 0x16, 0x2c);
			rgb_matrix_set_color(73, 0x83, 0x16, 0x2c);
			rgb_matrix_set_color(80, 0x57, 0x0F, 0x1E);

            // Fn key
			rgb_matrix_set_color(81, 0xFF, 0xFF, 0xFF);
			break;

		case _FF14:
            // tilde/tab/caps/shift/ctrl
			rgb_matrix_set_color(16, 0xFF, 0x00, 0x66); // tilde
			rgb_matrix_set_color(33, 0xFF, 0x00, 0x66); // tab
			rgb_matrix_set_color(50, 0xFF, 0x00, 0x66); // alt (caps)
			rgb_matrix_set_color(63, 0xFF, 0x00, 0x66); // shift
			rgb_matrix_set_color(76, 0xFF, 0x00, 0x66); // ctrl

            // Nums 1-6
			rgb_matrix_set_color(17, 0xFF, 0x00, 0x33); // 1
			rgb_matrix_set_color(18, 0xFF, 0x00, 0x33); // 2
			rgb_matrix_set_color(19, 0xFF, 0x00, 0x33); // 3
			rgb_matrix_set_color(20, 0xFF, 0x00, 0x33); // 4
			rgb_matrix_set_color(21, 0xFF, 0x00, 0x33); // 5
			rgb_matrix_set_color(22, 0xFF, 0x00, 0x33); // 6
            // Nums 7-= (bottom row)
			rgb_matrix_set_color(64, 0xFF, 0x00, 0x33); // 7
			rgb_matrix_set_color(65, 0xFF, 0x00, 0x33); // 8
			rgb_matrix_set_color(66, 0xFF, 0x00, 0x33); // 9
			rgb_matrix_set_color(67, 0xFF, 0x00, 0x33); // 0
			rgb_matrix_set_color(68, 0xFF, 0x00, 0x33); // -
			rgb_matrix_set_color(69, 0xFF, 0x00, 0x33); // =

			// ESDF
			rgb_matrix_set_color(14, 0xFF, 0xFF, 0xFF); // Scroll Lock; (show enabled)
			rgb_matrix_set_color(35, 0x21, 0xBD, 0xA9); // W - F2
			rgb_matrix_set_color(36, 0xCC, 0x99, 0xFF); // E
			rgb_matrix_set_color(37, 0x21, 0xBD, 0xA9); // R - F3
			rgb_matrix_set_color(51, 0x21, 0xBD, 0xA9); // A - F1
			rgb_matrix_set_color(52, 0xCC, 0x99, 0xFF);
			rgb_matrix_set_color(53, 0xCC, 0x99, 0xFF); // S D F
			rgb_matrix_set_color(54, 0xCC, 0x99, 0xFF);
			rgb_matrix_set_color(55, 0x21, 0xBD, 0xA9); // G - F4
		    break;

        case _COLEMAK:
			rgb_matrix_set_color(15, 0xFF, 0xFF, 0xFF); // Pause; (show enabled)
            break;
		}
	}
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case TOG:
            if (record->event.pressed) {
                if (layer_state_is(_QWERTY)) {
                    layer_off(_QWERTY);
                    layer_off(_FF14);
                    layer_on(_COLEMAK);
                    default_layer_set(1UL<<_COLEMAK);
                }
                else {
                    layer_off(_COLEMAK);
                    layer_off(_FF14);
                    layer_on(_QWERTY);
                    default_layer_set(1UL<<_QWERTY);
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

