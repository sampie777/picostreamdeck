//
// Created by samuel on 21-2-23.
//

#ifndef PICO_TEST1_KEYCODES_H
#define PICO_TEST1_KEYCODES_H

#define MODIFIER_CTRL ((int16_t) 0x01 << 8)
#define MODIFIER_SHIFT ((int16_t) 0x02 << 8)
#define MODIFIER_ALT ((int16_t) 0x04 << 8)
#define MODIFIER_LOGO ((int16_t) 0x08 << 8)
#define MODIFIER_CTRL_RIGHT ((int16_t) 0x10 << 8)
#define MODIFIER_SHIFT_RIGHT ((int16_t) 0x20 << 8)
#define MODIFIER_ALT_RIGHT ((int16_t) 0x40 << 8)
#define MODIFIER_LOGO_RIGHT ((int16_t) 0x80 << 8)

#define KEY_F1 128 // Keyboard F1
#define KEY_F2 129 // Keyboard F2
#define KEY_F3 130 // Keyboard F3
#define KEY_F4 131 // Keyboard F4
#define KEY_F5 132 // Keyboard F5
#define KEY_F6 133 // Keyboard F6
#define KEY_F7 134 // Keyboard F7
#define KEY_F8 135 // Keyboard F8
#define KEY_F9 136 // Keyboard F9
#define KEY_F10 137 // Keyboard F10
#define KEY_F11 138 // Keyboard F11
#define KEY_F12 139 // Keyboard F12

#define KEY_PRINT_SCREEN 140
#define KEY_SCROLL_LOCK 141
#define KEY_CAPS_LOCK 142
#define KEY_NUM_LOCK 143
#define KEY_INSERT 144
#define KEY_HOME 145
#define KEY_PAGE_UP 146
#define KEY_PAGE_DOWN 147

#define KEY_F13 ((int16_t) KEY_F1 | MODIFIER_SHIFT)
#define KEY_F14 ((int16_t) KEY_F2 | MODIFIER_SHIFT)
#define KEY_F15 ((int16_t) KEY_F3 | MODIFIER_SHIFT)
#define KEY_F16 ((int16_t) KEY_F4 | MODIFIER_SHIFT)
#define KEY_F17 ((int16_t) KEY_F5 | MODIFIER_SHIFT)
#define KEY_F18 ((int16_t) KEY_F6 | MODIFIER_SHIFT)
#define KEY_F19 ((int16_t) KEY_F7 | MODIFIER_SHIFT)
#define KEY_F20 ((int16_t) KEY_F8 | MODIFIER_SHIFT)
#define KEY_F21 ((int16_t) KEY_F9 | MODIFIER_SHIFT)
#define KEY_F22 ((int16_t) KEY_F10 | MODIFIER_SHIFT)
#define KEY_F23 ((int16_t) KEY_F11 | MODIFIER_SHIFT)
#define KEY_F24 ((int16_t) KEY_F12 | MODIFIER_SHIFT)

#endif //PICO_TEST1_KEYCODES_H
