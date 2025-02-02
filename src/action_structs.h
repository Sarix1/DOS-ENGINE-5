#ifndef EV_TYP_H
#define EV_TYP_H

#include "_common.h"

typedef struct
{
    time_t tick; // this is 4 bytes, but can probably be reduced to just 1
    controldata_t controldata;
} Action_t; // 8 bytes

typedef struct
{
    Action_t FAR* actions;
    size_t capacity;
    size_t count;
    Action_t FAR* read_ptr;
    Action_t FAR* write_ptr;
} ActionQueue_t;


/*
typedef struct t_control_buffer
{
    Action_t* start;
    Action_t* end;
    Action_t* read;
    Action_t* write;
    Action_t* last;
} ActionQueue_t;
*/

typedef struct
{
    id_t object_id;
    ActionQueue_t action_queue;
} PlayerInfo_t;

#endif/* EV_TYP_H */
