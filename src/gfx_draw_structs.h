#ifndef DRAW_DEFS_H
#define DRAW_DEFS_H

#include "_types.h"
#include "math_fixp_structs.h"

typedef struct
{
    Vec2 points[16];
    uint8_t num_points;
} Poly_t;

typedef struct
{
    byte* pixels;
    int16_t w, h;
    int16_t size;
    int16_t num_frames;
} Texture_t;

typedef struct
{
    Texture_t* texture;
    byte* pixels;
    int16_t frame;
    int16_t frame_interval;
    fixp scale_x;
    fixp scale_y;
} Sprite_t;

typedef struct
{
    fixp x;          /* Current x position in fixed point */
    fixp dx;         /* Change in x per scanline */
    int16_t steps;   /* Remaining scanlines for this edge - screen height is 200 so int16_t suffices */
} Edge_t;

#endif/* DRAW_DEFS_H */
