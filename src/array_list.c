#include "_common.h"
#include "array_list.h"

#define DECL_ARRAY_STRING(name, array) name,
#define DECL_ARRAY_REFERENCE(name, array) array,
#define DECL_ARRAY_EXTERN(name, array) extern const char* array[];

FOR_EACH_ARRAY(DECL_ARRAY_EXTERN)

const char* ArrayNames[] =
{
    FOR_EACH_ARRAY(DECL_ARRAY_STRING)
    NULL
};

const char** ArrayList[] =
{
    FOR_EACH_ARRAY(DECL_ARRAY_REFERENCE)
    NULL
};