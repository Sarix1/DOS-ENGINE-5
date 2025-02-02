#ifndef STATUS_H
#define STATUS_H

#include "_macro.h"
#include "system_defines.h"

#define NOT_FOUND       -1

#define ENABLED         1
#define DISABLED        0

#define INITIALIZED     1
#define UNINITIALIZED   0

#define FOR_EACH_ERROR(DO) \
    DO(SUCCESS,             "Success") \
    DO(FAILURE,             "Failure") \
    DO(ERROR_ASSERT,        "Expression evaluated as false") \
    DO(ERROR_MEMORY,        "Memory allocation failure") \
    DO(ERROR_TIMER_FROZEN,  "Timer frozen") \
    DO(ERROR_TIMER_SLOW,    "Timer too slow") \
    DO(ERROR_TIMER_FAST,    "Timer too fast")

#define DEF_ERROR_ENUM(e, unused) e,
enum ERROR_CODES
{
    FOR_EACH_ERROR(DEF_ERROR_ENUM)
    NUM_ERRORS
};
#undef DEF_ERROR_ENUM

extern const char FAR* error_strings[];

#endif/* STATUS_H */
