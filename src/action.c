#include "_common.h"
#include "action.h"
#include "timer.h"
#include "input_defines.h"
#include "text_output.h"

static Action_t FAR local_actions[ACTION_QUEUE_LENGTH] = {0};
//static Action_t FAR net_actions[MAX_PLAYERS][ACTION_QUEUE_LENGTH] = {0};
controldata_t local_controldata; // a temporary solution; controldata should go to PlayerInfo_t later

static ActionQueue_t LocalActionQueue =
{
    local_actions, // start
    local_actions+ACTION_QUEUE_LENGTH, //end
    local_actions, // read
    local_actions, // write
    local_actions  // last
};

static Action_t** last_action = &LocalActionQueue.last;

int initActionQueue(ActionQueue_t* queue, size_t capacity)
{
    if (!queue || capacity == 0)
        return FAILURE;

    queue->actions = malloc(capacity * sizeof(Action_t));
    if (!queue->actions)
        return ERROR_MEMORY;

    queue->capacity = capacity;
    queue->count = 0;
    queue->read_ptr = queue->actions;
    queue->write_ptr = queue->actions;

    return SUCCESS;
}

int initLocalActionQueue()
{
    return initActionQueue(&LocalActionQueue, ACTION_QUEUE_LENGTH);
}

int pushAction(ActionQueue_t* queue, const Action_t* action)
{
    if (!queue || !action || queue->count >= queue->capacity)
        return FAILURE;

    _fmemcpy(queue->write_ptr, action, sizeof(Action_t));
    queue->write_ptr++;
    if (queue->write_ptr >= queue->actions + queue->capacity)
        queue->write_ptr = queue->actions;
    queue->count++;

    return SUCCESS;
}

/*
static void pushAction(Action_t action)
{
    print(COLOR_LOG_TEXT, "Last action tick: %ld\n", (*last_action)->tick);
    
    if (action.controldata == (*last_action)->controldata)
        return;
    
    if (action.tick == (*last_action)->tick)
    {
        print(COLOR_LOG_TEXT, "Same tick\n");
        *LocalActionQueue.last = action;

        return;
    }

    *LocalActionQueue.write = action;
    LocalActionQueue.last = LocalActionQueue.write;
    ptrIncAndWrap(LocalActionQueue.write,
                  LocalActionQueue.start,
                  LocalActionQueue.end);

    if (LocalActionQueue.write == LocalActionQueue.read) // this should NEVER happen, it means
        ptrIncAndWrap(LocalActionQueue.read, //  that more actions were generated than the game
                      LocalActionQueue.start, // was able to process, so older actions _DISAPPEAR_
                      LocalActionQueue.end);  // without being processed at all
}
*/

int generateAction(action_id_t action_id, byte state, time_t tick)
{
    Action_t action;
    controldata_t control_bit = BIT(action_id-1);
    
    action.tick = tick + g_Timer.action_delay;
    action.controldata = (state == 0) ?
        ((*last_action)->controldata & ~control_bit) :
        ((*last_action)->controldata | control_bit);

    pushAction(&LocalActionQueue, &action);
}

// updates a player's controldata
void processActions()//(id_t player_id)
{
    while (LocalActionQueue.read != LocalActionQueue.write)
    {
        if (LocalActionQueue.read->tick <= g_Timer.tick_simulated)
        {
            local_controldata = LocalActionQueue.read->controldata;
            ptrIncAndWrap(LocalActionQueue.read,
                          LocalActionQueue.start,
                          LocalActionQueue.end);
            continue;
        }
        else
            break;
    }
}
