/* gfx_poly.h */
#ifndef POLY_H
#define POLY_H

#include "_common.h"
#include "gfx_draw_structs.h"

/* First, define the polygon list that will be used by multiple sections */
#define POLYGON_LIST \
    DEFINE_POLY(BOX, \
        VERTEX(-10,-10) \
        VERTEX(10,-10) \
        VERTEX(10,10) \
        VERTEX(-10,10) \
    ) \
    DEFINE_POLY(SHIP, \
        VERTEX(12,0) \
        VERTEX(-8,-8) \
        VERTEX(-3,0) \
        VERTEX(-8,8) \
    ) \
    DEFINE_POLY(ASTEROID, \
        VERTEX(-15,-5) \
        VERTEX(-5,-15) \
        VERTEX(5,-15) \
        VERTEX(15,-5) \
        VERTEX(15,5) \
        VERTEX(5,15) \
        VERTEX(-5,15) \
        VERTEX(-15,5) \
    ) \
    DEFINE_POLY(DIAMOND, \
        VERTEX(0,-15) \
        VERTEX(15,0) \
        VERTEX(0,15) \
        VERTEX(-15,0) \
    ) \
    DEFINE_POLY(POWERUP, \
        VERTEX(0,-15) \
        VERTEX(15,0) \
        VERTEX(0,15) \
        VERTEX(-15,0) \
    ) \
    DEFINE_POLY(TEST, \
        VERTEX(-20,-20) \
        VERTEX(20,-20) \
        VERTEX(30,0) \
        VERTEX(20,20) \
        VERTEX(-20,20) \
        VERTEX(-30,0) \
    ) \

/* Define the enum first, before any code tries to use it */
enum POLY {
    POLY_NONE = -1,
    #define VERTEX(x,y)
    #define DEFINE_POLY(name, vertices) POLY_##name,
    POLYGON_LIST
    #undef DEFINE_POLY
    #undef VERTEX
    NUM_POLYS
};

Poly_t* getPoly(id_t id);

#endif/* POLY_H */