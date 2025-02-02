/* gfx_poly.c */
#include "gfx_poly.h"

/* First compute vertex counts as enums to make them compile-time constants */
enum {
    #define VERTEX(x,y) +1
    #define DEFINE_POLY(name, vertices) \
        POLY_##name##_VCOUNT = 0 vertices,
    POLYGON_LIST
    #undef DEFINE_POLY
    #undef VERTEX
    MAX_VCOUNT
};

/* Now use these constants in the polygon definitions */
#define VERTEX(x,y) {F(x), F(y)},
#define DEFINE_POLY(name, vertices) \
    static const Poly_t poly_##name = { \
        { vertices }, \
        POLY_##name##_VCOUNT \
    };

POLYGON_LIST
#undef DEFINE_POLY
#undef VERTEX

Poly_t* getPoly(id_t id)
{
    #define VERTEX(x,y)
    #define DEFINE_POLY(name, vertices) \
        case POLY_##name: return (Poly_t*)&poly_##name;

    switch (id)
    {
        POLYGON_LIST
        default: return (Poly_t*)&poly_BOX;
    }

    #undef DEFINE_POLY
    #undef VERTEX
}