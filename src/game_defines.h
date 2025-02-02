#ifndef GAME_DEF_H
#define GAME_DEF_H

#include "_common.h"
#include "game_structs.h"
#include "game_macro.h"
#include "gfx_poly.h"

#define OBJ_CHUNK       16
#define OBJ_FLAG_FILLED BIT_0

#define COLOR_BG            COLOR_BLACK
#define COLOR_HITBOX        COLOR_BLUE
#define COLOR_HITBOX_ACTIVE COLOR_RED

#define COLOR_SHIP          COLOR_CYAN
#define COLOR_ASTEROID      COLOR_D_GREY
#define COLOR_POWERUP       COLOR_YELLOW
#define COLOR_DIAMOND       COLOR_GREEN

// Object templates
#define FOR_EVERY_OBJECT_TEMPLATE(DO) \
    /*  enum            string      poly id         color           radius  obb_w   obb_h   angvel */ \
    DO( OBJ_SHIP,       "ship",     POLY_SHIP,      COLOR_SHIP,     F(32),  F(8),   F(30),  DEG_0 ) \
    DO( OBJ_ASTEROID,   "asteroid", POLY_ASTEROID,  COLOR_ASTEROID, F(16),  F(16),  F(16),  DEG_1 ) \
    DO( OBJ_DIAMOND,    "diamond",  POLY_DIAMOND,   COLOR_DIAMOND,  F(16),  F(16),  F(16),  DEG_1 ) \
    DO( OBJ_POWERUP,    "powerup",  POLY_POWERUP,   COLOR_POWERUP,  F(16),  F(16),  F(16),  DEG_1 )

typedef enum OBJECT_TEMPLATE_ENUM
{
    FOR_EVERY_OBJECT_TEMPLATE(DECL_OBJECT_ENUM)
    NUM_OBJECT_TEMPLATES
} ObjectTemplateId_t;



#endif/* GAME_DEF_H */
