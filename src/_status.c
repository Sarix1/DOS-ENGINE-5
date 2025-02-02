#include "_common.h"
#include "_status.h"

#define DECL_ERROR_STRING(unused,str) str,
const char FAR* error_strings[] =
{
    FOR_EACH_ERROR(DECL_ERROR_STRING)
    NULL
};
#undef DECL_ERR_STR