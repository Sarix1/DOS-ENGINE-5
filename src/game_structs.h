#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include "_common.h"
#include "math_fixp_defines.h"
#include "gfx_draw_structs.h"

typedef struct
{
    /* Object identification */
    id_t id;
    id_t type;
    
    /* Physics */
    controldata_t controldata;
    Vec2 pos;
    Vec2 vel;
    Vec2 dir;
    brad angle;
    brad last_angle;
    brad angvel;
    fixp radius;
    
    fixp aabb_w;
    fixp aabb_h;
    fixp obb_w;
    fixp obb_h;
    
    /* Graphics */
    Poly_t* poly;
    Poly_t transformed_poly;
    fixp scale;
    byte color;
    byte color2;
    byte flags;
} Object_t;

typedef struct
{
    id_t poly_id;
    fixp radius;
    fixp obb_w;
    fixp obb_h;
    fixp scale;
    byte color;
    byte flags;
    brad default_angvel;
} ObjectTemplate_t;

typedef struct
{
    Object_t* Objects;
    Object_t** ObjectsById;
    id_t object_count;
    id_t object_capacity;
    id_t max_id;
    id_t id_capacity;
    id_t player_id;
} GameData_t;

#endif/* GAME_STRUCTS_H */
