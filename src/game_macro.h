/* game_templates.h */
#ifndef GAME_TEMPLATES_H
#define GAME_TEMPLATES_H

#define DECL_OBJECT_ENUM(enum_, name, poly, color, radius, obb_w, obb_h, angvel) enum_,
#define DECL_OBJECT_STRING(enum_, name, poly, color, radius, obb_w, obb_h, angvel) name,
#define DECL_OBJECT_TEMPLATE(enum_, name, poly, color, radius, obb_w, obb_h, angvel) \
    { \
        poly, \
        radius, \
        obb_w, \
        obb_h, \
        FIXP_1, \
        color, \
        0, \
        angvel \
    },

#endif/* GAME_TEMPLATES_H */