#include "_common.h"
#include "_string.h"
#include "command_defines.h"
#include "command_args.h"
#include "game_macro.h"
#include "game_defines.h"
#include "math_fixp.h"

int cmdSpawn(StringList_t args)
{
    static struct
    {
        int obj_type;
        Vec2 pos;
    } Params;

    static const Arg_t defs[] =
    {
        {ARG_ENUM,  "obj_type", &Params.obj_type},
        {ARG_FLOAT, "x",        &Params.pos.x},
        {ARG_FLOAT, "y",        &Params.pos.y},
        {ARG_NONE,  NULL,       NULL}
    };

    if (parseArgs(args, defs) == FAILURE)
        return FAILURE;
    else
    {
        spawnTemplateObject((ObjectTemplateId_t)Params.obj_type, Params.pos, newVec2(0,0), 0);
        return SUCCESS;
    }
}

void cmdQuit(StringList_t args)
{
    //quit();
}