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

GameData_t g_Game = {0};

int gameInit()
{
    id_t test_poly_id = 0;

    g_Game.object_capacity = OBJ_CHUNK;
    g_Game.id_capacity = OBJ_CHUNK;
    g_Game.Objects = (Object_t*)malloc(g_Game.object_capacity * sizeof(Object_t));
    g_Game.ObjectsById = (Object_t**)calloc(g_Game.id_capacity, sizeof(void*));

    /* Create player ship */
    g_Game.player_id = spawnTemplateObject(OBJ_SHIP, newVec2_I2F(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), newVec2(0, 0), DEG_90);

    /* Create some asteroids */

    spawnTemplateObject(OBJ_ASTEROID, newVec2_I2F(200, 200), newVec2(FIXP_025, FIXP_015), 0);
    spawnTemplateObject(OBJ_ASTEROID, newVec2_I2F(100, 100), newVec2(FIXP_025, FIXP_015), 0);
    spawnTemplateObject(OBJ_ASTEROID, newVec2_I2F(300, 300), newVec2(FIXP_025, FIXP_015), 0);
    spawnTemplateObject(OBJ_ASTEROID, newVec2_I2F(400, 400), newVec2(FIXP_025, FIXP_015), 0);
    spawnTemplateObject(OBJ_ASTEROID, newVec2_I2F(500, 500), newVec2(FIXP_025, FIXP_015), 0);

    /* Create some test objects */
    spawnTemplateObject(OBJ_DIAMOND, newVec2_I2F(100, 100), newVec2(-FIXP_050, FIXP_1_4), 0);
    spawnTemplateObject(OBJ_POWERUP, newVec2_I2F(200, 200), newVec2(FIXP_015, FIXP_1_5), 0);

    return SUCCESS;
}

int gameQuit()
{
    g_Game.object_capacity = 0;
    g_Game.id_capacity = 0;
    free(g_Game.Objects);
    free(g_Game.ObjectsById);

    return SUCCESS;
}

void gameEnter()
{
    g_Input.flags |= INP_FLAG_GAME_CONTROL;
    g_Timer.enable_ticks = 1;
}

void gameLeave()
{
    g_Input.flags &= ~INP_FLAG_GAME_CONTROL;
}

void gameUpdate()
{
    processActions();
    physics();
    #if DEBUG_INFO == 1
    sprintf(debug[DEBUG_OBJECTS], "Objects: %d\n", g_Game.object_count);
    #endif
}

void gameEsc()
{
    ;
}

