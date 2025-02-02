//#ifndef COMMON_H
//#define COMMON_H

#define DEBUG_INFO      1
#define DEBUG_ASSERT    1
#define DEBUG_SYSTEM    1
#define DEBUG_HITBOX    1
#define ASPECT          0

#include "_watcom.h"
#include "_bits.h"
#include "_macro.h"
#include "_status.h"
#include "_types.h"

#include "gfx_colors.h"
#include "gfx_video_defines.h"
#include "math_fixp_defines.h"

#if DEBUG_INFO == 1
#include "_debug.h"
#endif

void quit();

//#endif/* COMMON_H */
