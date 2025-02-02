#include "_common.h"
#include "_string.h"
#include "command_defines.h"
#include "array_list.h"
#include "console.h"

// function definitions
int parseArg(char* arg, Arg_t* def, int i)
{
    switch (def->type)
    {
        /* integer */
        case ARG_INT:
            if (sscanf(arg, "%d", def->value) != 1)
            {
                printConsole(COLOR_LOG_ERROR, "Failed to parse argument %d as int\n", i);
                return FAILURE;
            }
            break;
        /* float */
        case ARG_FLOAT:
            if (sscanf(arg, "%f", def->value) != 1)
            {
                printConsole(COLOR_LOG_ERROR, "Failed to parse argument %d as float\n", i);
                return FAILURE;
            }
            break;
        /* char */
        case ARG_CHAR:
            if (sscanf(arg, "%c", def->value) != 1)
            {
                printConsole(COLOR_LOG_ERROR, "Failed to parse argument %d as char\n", i);
                return FAILURE;
            }
            break;
        /* string */
        case ARG_STRING:
            *(char**)def->value = arg;
            break;
        /* bool */
        case ARG_BOOL:
            if (sscanf(arg, "%d", def->value) != 1 || ((int)def->value != 0 && (int)def->value != 1))
            {
                print(COLOR_LOG_ERROR, "Failed to parse argument %d as bool\n", i);
                return FAILURE;
            }
            break;
        /* enum */
        case ARG_ENUM:
        {
            int array_id = findString(def->name, ArrayNames);
            if (array_id == NOT_FOUND)
            {
                printConsole(COLOR_LOG_ERROR, "Array not found: %s\n", def->name);
                return FAILURE;
            }
            else
            {
                int string_id = findString(arg, ArrayList[array_id]);
                if (string_id == NOT_FOUND)
                {
                    printConsole(COLOR_LOG_ERROR, "Enum \"%s\" not found in array \"%s\"\n", arg, def->name);
                    return FAILURE;
                }
                else
                {
                    (int)def->value = string_id;
                }
            }
        }
            break;
        /* invalid */      
        default:
            printConsole(COLOR_LOG_ERROR, "Invalid argument type\n");
            return FAILURE;
    }
    return FAILURE;
}

// args is a list of input arguments
// defs is a list of argument definitions, all of which are positional and required. there are no optional arguments.
// the function should print an error message if an argument is missing, or it failes to parse as the required type
// the return value should be true if parsing all arguments succeeded
// an error message should also be printed if not enough arguments were provided in args
int parseArgs(StringList_t args, Arg_t* defs)
{
    int i;
    int def_count = 0;
    Arg_t* def = defs;

    while (def->type != 0)
    {
        def_count++;
        def++;
    }

    if (args.count < def_count)
    {
        print(COLOR_LOG_ERROR, "Not enough arguments provided\n");
        return FAILURE;
    }

    for (i = 0; i < args.count; i++)
    {
        char* arg;
        def = defs + i;
        arg = args.strings[i];

        if (parseArg(arg, def, i) == FAILURE)
            return FAILURE;
    }

    return SUCCESS;
}
