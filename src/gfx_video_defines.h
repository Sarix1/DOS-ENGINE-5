#ifndef GFX_VIDEO_DEFINES_H
#define GFX_VIDEO_DEFINES_H

#define VGA             0x000A0000
#define CHARSET_ROM     0xF000FA6El // real mode address

#define VIDEO_INT       0x10
#define INPUT_STATUS    0x3DA
#define VRETRACE        0x08

#define SET_MODE        0x00

typedef enum {
    MODE_TEXT = 0x03,
    MODE_320x200 = 0x13
} VideoMode_t;

#define PALETTE_READ    0x03C7
#define PALETTE_WRITE   0x03C8
#define PALETTE_DATA    0x03C9
#define NUM_COLORS      256

#define SCREEN_WIDTH    320
#define SCREEN_HEIGHT   200
#define SCREEN_SIZE     64000u

#define ASPECT_RATIO    (FIXP_ONE*5)/6

#if SCREEN_WIDTH == 320
#define Y_OFFSET(i) (((i)<<8)+((i)<<6))
#else
#define Y_OFFSET(i) ((i)*SCREEN_WIDTH)
#endif/* GFX_VIDEO_DEFINES_H */

#endif/* GFX_VIDEO_DEFINES_H */
