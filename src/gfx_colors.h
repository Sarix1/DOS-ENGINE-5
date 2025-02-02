#ifndef COLORS_H
#define COLORS_H

typedef enum COLORS
{
    COLOR_NONE = -1,
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_PURPLE = 5,
    COLOR_BROWN = 6,
    COLOR_L_GREY = 7,
    COLOR_D_GREY = 8,
    COLOR_L_BLUE = 9,
    COLOR_L_GREEN = 10,
    COLOR_L_CYAN = 11,
    COLOR_L_RED = 12,
    COLOR_L_PURPLE = 13,
    COLOR_YELLOW = 14,
    COLOR_WHITE = 15
} Color_t;

#define COLOR_INPUT_BG      COLOR_L_BLUE
#define COLOR_INPUT_TEXT    COLOR_WHITE

#define COLOR_LOG_BG        COLOR_BLUE
#define COLOR_LOG_TEXT      COLOR_L_BLUE

#define COLOR_LOG_UNKNOWN   COLOR_PURPLE
#define COLOR_LOG_ERROR     COLOR_L_RED
#define COLOR_LOG_SYSTEM    COLOR_L_GREY

#define COLOR_DEBUG_TEXT    COLOR_L_BLUE
#define COLOR_DEBUG_LINE    COLOR_BLUE

#endif/* COLORS_H */
