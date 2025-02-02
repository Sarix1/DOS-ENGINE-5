#include <string.h>
#include "_common.h"
#include "_malloc.h"
#include "_debug.h"

#include "game.h"
#include "game_physics.h"
#include "game_macro.h"

#include "timer.h"
#include "input.h"
#include "action.h"

#include "math_fixp_inline.h"
#include "gfx_draw_defines.h"
#include "gfx_poly.h"

static id_t getNewId()
{
    id_t id; // skip 0
    for (id = 1; id < g_Game.id_capacity; id++)
        if (g_Game.ObjectsById[id] == NULL)
            return id;

    g_Game.id_capacity += OBJ_CHUNK;
    g_Game.ObjectsById = (Object_t**)realloc(g_Game.ObjectsById, g_Game.id_capacity * sizeof(void*));
    memset(g_Game.ObjectsById, 0, OBJ_CHUNK * sizeof(void*)); // set new pointers to NULL

    return id;
}

id_t createObject(Vec2 pos, Vec2 vel, Vec2 dir, brad angvel,
                  fixp radius, fixp obb_w, fixp obb_h,
                  fixp scale, Poly_t* poly,  byte color)
{
    Object_t* obj;
    id_t id = getNewId();

    if (g_Game.object_count >= g_Game.object_capacity)
    {
        g_Game.object_capacity += OBJ_CHUNK;
        g_Game.Objects = (Object_t*)realloc(g_Game.Objects, g_Game.object_capacity * sizeof(Object_t));
        // to do: ensure successful allocation
    }

    obj = g_Game.ObjectsById[id] = &g_Game.Objects[g_Game.object_count++];
    obj->pos = pos;
    obj->vel = vel;
    obj->dir = dir;
    obj->angle = vec2angle(dir);
    obj->angvel = angvel;
    obj->radius = radius;
    obj->obb_w = obb_w;
    obj->obb_h = obb_h;
    obj->poly = poly;
    memcpy(obj->transformed_poly.points, poly->points, poly->num_points*sizeof(Vec2));
    obj->transformed_poly.num_points = obj->poly->num_points;
    obj->scale = scale;
    obj->color = color;
    obj->color2 = COLOR_HITBOX;

    return id;
}

void deleteObject(id_t id)
{
    if (g_Game.ObjectsById[id] != &g_Game.Objects[g_Game.object_count])
        *g_Game.ObjectsById[id] = g_Game.Objects[g_Game.object_count-1];

    g_Game.object_count--;
    g_Game.ObjectsById[id] = NULL;

    if (g_Game.object_count < g_Game.object_capacity - OBJ_CHUNK)
    {
        g_Game.object_capacity -= OBJ_CHUNK;
        g_Game.Objects = (Object_t*)realloc(g_Game.Objects, g_Game.object_capacity * sizeof(Object_t));
    }
}

void deleteLastObject()
{
    if (g_Game.object_count > 0)
        deleteObject(g_Game.object_count-1);
}

id_t spawnShip(Vec2 pos, brad angle)
{
    return createObject(pos, newVec2_I2F(0,0), newVec2_angle(0), 0, F(32), F(8), F(30), F(1), getPoly(POLY_SHIP), COLOR_SHIP);
}
