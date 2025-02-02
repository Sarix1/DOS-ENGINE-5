#include "_common.h"
#include "_string.h"
#include "command_defines.h"
#include "console.h"

// forward declarations
FOR_EACH_COMMAND(DECL_COMMAND_PROTOTYPE)

// command function array
fnp_cmd CommandFuncs[] =
{
    FOR_EACH_COMMAND(DECL_COMMAND_FUNC)
    NULL
};

// command name array
const char* CommandNames[] =
{
    FOR_EACH_COMMAND(DECL_COMMAND_STRING)
    NULL
};

int commandInput(char* input_string)
{
    StringList_t tokens;
    CommandId_t cmd_id;

    tokens = splitString(input_string, " ");
    cmd_id = findString(tokens.strings[0], CommandNames);

    if (cmd_id == NOT_FOUND)
    {
        printConsole(COLOR_LOG_ERROR, "Command not found: %s\n", tokens.strings[0]);
        return FAILURE;
    }

    return CommandFuncs[cmd_id](tokens);
}