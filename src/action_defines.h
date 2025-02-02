#ifndef ACTION_DEF_H
#define ACTION_DEF_H

#include "_common.h"

#define ACTION_DELAY 2
#define ACTION_QUEUE_LENGTH 512

/* Define all actions in one list, e.g. FIRE */
#define FOR_EACH_ACTION(DO) \
    DO(UP)      \
    DO(DOWN)    \
    DO(LEFT)    \
    DO(RIGHT)   \
    DO(FIRE)    \
    DO(USE)     \
    DO(07)      \
    DO(08)      \
    DO(09)      \
    DO(10)      \
    DO(11)      \
    DO(12)      \
    DO(13)      \
    DO(14)      \
    DO(15)      \
    DO(16)      \
    DO(17)      \
    DO(18)      \
    DO(19)      \
    DO(20)      \
    DO(21)      \
    DO(22)      \
    DO(23)      \
    DO(24)      \
    DO(25)      \
    DO(26)      \
    DO(27)      \
    DO(28)      \
    DO(29)      \
    DO(30)      \
    DO(31)      \
    DO(32)      \

/* Generate enum values, e.g. EV_ACTION_FIRE = 4 */
#define DECL_ACTION_ENUM(name) EV_ACTION_##name,

enum ACTION_EVENTS
{
    EV_ACTION_NONE = 0,
    FOR_EACH_ACTION(DECL_ACTION_ENUM) 
    NUM_ACTIONS
};

/* Generate bit mask macros, e.g. BIT_ACTION_FIRE =  */
#define DECL_ACTION_BIT(name) BIT_ACTION_##name = BIT(EV_ACTION_##name-1),

enum ACTION_BITS
{
    FOR_EACH_ACTION(DECL_ACTION_BIT)
};

#undef DECL_ACTION_ENUM
#undef DECL_ACTION_BIT

#endif/* ACTION_DEF_H */