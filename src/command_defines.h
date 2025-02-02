#ifndef COMMAND_DEFINES_H
#define COMMAND_DEFINES_H

#include "command_macro.h"

// command list
#define FOR_EACH_COMMAND(DO) \
    DO(CMD_SPAWN,   "spawn",    cmdSpawn) \
    DO(CMD_QUIT,    "quit",     cmdQuit) \

// command ids
typedef enum COMMAND_IDS
{
    CMD_NONE = -1,
    FOR_EACH_COMMAND(DECL_COMMAND_ENUM)
    NUM_COMMANDS
} CommandId_t;

// argument types
typedef enum ARGUMENT_TYPES
{
    ARG_NONE = -1,
    ARG_INT,
    ARG_FLOAT,
    ARG_CHAR,
    ARG_STRING,
    ARG_BOOL,
    ARG_ENUM,
    NUM_ARG_TYPES
} ArgType_t;

typedef struct
{
    ArgType_t type;
    char* name;
    void* value;
} Arg_t;

typedef int (*fnp_cmd)(StringList_t);

#endif/* COMMAND_DEFINES_H */