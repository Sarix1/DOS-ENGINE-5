#ifndef KEYS_H
#define KEYS_H
    
typedef enum KEYCODES
{
    // Control keys
    KEY_ESC = 0x01,
    KEY_ENTER = 0x1C,
    KEY_BACKSPACE = 0x0E,
    KEY_TAB = 0x0F,
    KEY_SPACEBAR = 0x39,
    // Shift keys
    KEY_LSHIFT = 0x2A,
    KEY_RSHIFT = 0x36,
    KEY_LALT = 0x38,
    KEY_RALT = 0xB8,
    KEY_LCTRL = 0x1D,
    KEY_RCTRL = 0x9D,
    // Function keys
    KEY_F1 = 0x3B,
    KEY_F2 = 0x3C,
    KEY_F3 = 0x3D,
    KEY_F4 = 0x3E,
    KEY_F5 = 0x3F,
    KEY_F6 = 0x40,
    KEY_F7 = 0x41,
    KEY_F8 = 0x42,
    KEY_F9 = 0x43,
    KEY_F10 = 0x44,
    KEY_F11 = 0x57,
    KEY_F12 = 0x58,
    // Number keys
    KEY_0 = 0x0B,
    KEY_1 = 0x02,
    KEY_2 = 0x03,
    KEY_3 = 0x04,
    KEY_4 = 0x05,
    KEY_5 = 0x06,
    KEY_6 = 0x07,
    KEY_7 = 0x08,
    KEY_8 = 0x09,
    KEY_9 = 0x0A,
    // Letter keys
    KEY_A = 0x1E,
    KEY_B = 0x30,
    KEY_C = 0x2E,
    KEY_D = 0x20,
    KEY_E = 0x12,
    KEY_F = 0x21,
    KEY_G = 0x22,
    KEY_H = 0x23,
    KEY_I = 0x17,
    KEY_J = 0x24,
    KEY_K = 0x25,
    KEY_L = 0x26,
    KEY_M = 0x32,
    KEY_N = 0x31,
    KEY_O = 0x18,
    KEY_P = 0x19,
    KEY_Q = 0x10,
    KEY_R = 0x13,
    KEY_S = 0x1F,
    KEY_T = 0x14,
    KEY_U = 0x16,
    KEY_V = 0x2F,
    KEY_W = 0x11,
    KEY_X = 0x2D,
    KEY_Y = 0x15,
    KEY_Z = 0x2C,
    // Special keys
    KEY_MINUS = 0x0C,
    KEY_EQUAL = 0x0D,
    KEY_DIVIDE = 0x35,
    KEY_SLASH = 0x2B,
    KEY_COMMA = 0x33,
    KEY_PERIOD = 0x34,
    KEY_SEMICOL = 0x27,
    // Bracket keys
    KEY_L_BRACKET = 0x1A,
    KEY_R_BRACKET = 0x1B,
    // Accent keys
    KEY_ACUTE_ACCENT = 0x28,
    KEY_GRAVE_ACCENT = 0x29,
    // Lock keys
    KEY_PRINT_SCRN = 0xB7,
    KEY_PAUSE = 0x61,
    KEY_NUM_LOCK = 0x45,
    KEY_SCROLL_LOCK = 0x46,
    KEY_CAPS_LOCK = 0x3A,
    // Navigation keys
    KEY_INSERT = 0xD2,
    KEY_DELETE = 0xD3,
    KEY_HOME = 0xC7,
    KEY_END = 0xCF,
    KEY_PAGE_UP = 0xC9,
    KEY_PAGE_DOWN = 0xD1,
    // Arrow keys
    KEY_UP = 0xC8,
    KEY_DOWN = 0xD0,
    KEY_LEFT = 0xCB,
    KEY_RIGHT = 0xCD,
    // Keypad keys
    KEY_PAD_MINUS = 0x4A,
    KEY_PAD_PLUS = 0x4E,
    KEY_PAD_PERIOD = 0x53,
    KEY_PAD_DIV = 0xB5,
    KEY_PAD_MUL = 0x37,
    KEY_PAD_ENTER = 0x9C,
    // Keypad number keys
    KEY_PAD_0 = 0x52,
    KEY_PAD_1 = 0x4F,
    KEY_PAD_2 = 0x50,
    KEY_PAD_3 = 0x51,
    KEY_PAD_4 = 0x4B,
    KEY_PAD_5 = 0x4C,
    KEY_PAD_6 = 0x4D,
    KEY_PAD_7 = 0x47,
    KEY_PAD_8 = 0x48,
    KEY_PAD_9 = 0x49
} KeyCode_t;

extern const char FAR ascii[128];
extern const char FAR ascii_shifted[128];
extern const char FAR ascii_special[128];
extern const char FAR* key_names[256];

#endif/* KEYS_H */
