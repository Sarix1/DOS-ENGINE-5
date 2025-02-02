/* game_templates.c */
#include "_common.h"
#include "game.h"
#include "game_macro.h"
#include "math_fixp.h"

const ObjectTemplate_t ObjectTemplates[] =
{
    FOR_EVERY_OBJECT_TEMPLATE(DECL_OBJECT_TEMPLATE)
};

const char* ObjectNames[] =
{
    FOR_EVERY_OBJECT_TEMPLATE(DECL_OBJECT_STRING)
    NULL
};

id_t spawnTemplateObject(ObjectTemplateId_t template_id, Vec2 pos, Vec2 vel, brad angle)
{
    const ObjectTemplate_t* tmpl;
    Vec2 dir;
    id_t obj_id;
    
    /* Validate template ID */
    if (template_id >= NUM_OBJECT_TEMPLATES)
        return 0;
        
    tmpl = &ObjectTemplates[template_id];
    dir = newVec2_angle(angle);
    
    obj_id = createObject(
        pos,
        vel, 
        dir,
        tmpl->default_angvel,
        tmpl->radius,
        tmpl->obb_w,
        tmpl->obb_h,
        tmpl->scale,
        getPoly(tmpl->poly_id),
        tmpl->color
    );
    
    if (obj_id)
        g_Game.ObjectsById[obj_id]->flags |= tmpl->flags;
    else
        printConsole(0, "Failed to spawn object\n");
    
    return obj_id;
}