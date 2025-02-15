#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "_common.h"
#include "_string.h"

#include "console.h"
#include "command.h"
#include "input.h"
#include "state.h"
#include "timer.h"

#include "text_defines.h"
#include "text_input.h"
#include "text_output.h"

#include "gfx_draw_text.h"

static byte FAR console_input_buffer[CONSOLE_INPUT_SIZE] = {0};
static byte FAR console_log_buffer[CONSOLE_BUFFER_SIZE] = {0};
static Line_t FAR console_log_lines[CONSOLE_MAX_LINES] = {0};

extern char FAR format_buffer[FORMAT_BUFFER_SIZE];

static TextInput_t ConsoleInput =
{
    console_input_buffer,
    CONSOLE_INPUT_SIZE,
    0, 0, 0
};

static Log_t ConsoleLog =
{
    {
        console_log_buffer,
        console_log_buffer+CONSOLE_BUFFER_SIZE,
        console_log_buffer,
        console_log_buffer
    },
    console_log_lines,
    console_log_lines+CONSOLE_MAX_LINES,
    console_log_lines,
    console_log_lines,
    MAX_SCREEN_COLS,
    CONSOLE_MAX_LINES,
    CONSOLE_VIS_LINES,
    COLOR_LOG_BG
};

int consoleInit()
{
    resetInput(&ConsoleInput);

    return SUCCESS;
}

int consoleQuit()
{
    return SUCCESS;
}

void consoleEnter()
{
    setStateFlags(STATE_CONSOLE, STATE_FLAG_DRAW);
    g_Input.flags |= (INP_FLAG_WRITE_TEXT|INP_FLAG_REPEAT_KEYS);
    g_Input.input_field = &ConsoleInput;
    g_Input.input_callback = consoleInput;
}

void consoleLeave()
{
    clearStateFlags(STATE_CONSOLE, STATE_FLAG_DRAW);
    g_Input.flags &= ~(INP_FLAG_WRITE_TEXT|INP_FLAG_REPEAT_KEYS);
}

void consoleUpdate()
{
    ;
}

void consoleEsc()
{
    removeState(STATE_CONSOLE);
}

// receives a va_list; use like fprintf
void v_printConsole(byte color, char *format, va_list args)
{
    int len = vsnprintf(format_buffer, FORMAT_BUFFER_SIZE, format, args);
    len = MIN(len, FORMAT_BUFFER_SIZE);
    ASSERT(len > 0);
    logWrite(&ConsoleLog, format_buffer, len, color);
}

// receives multiple arguments; use like printf
void printConsole(byte color, char* format, ...)
{
    va_list args;
    va_start(args, format);
    v_logWrite_f(&ConsoleLog, color, format, args);
    va_end(args);
}

void consoleInput(TextInput_t* input)
{
    static char command_buffer[CONSOLE_INPUT_SIZE];
    // Ignore empty input
    if (input->buffer[0] == '\0')
        return;
    // Create null-terminated copy of input
    memcpy(command_buffer, input->buffer, input->length);
    command_buffer[input->length] = '\0';
    commandInput(command_buffer);  
    resetInput(input);
}
void consoleDraw()
{
    const int input_y_pos = ConsoleLog.vis_lines * CHAR_HEIGHT;
    drawLog(0, 0, &ConsoleLog);
    drawInput(0, input_y_pos, MAX_SCREEN_COLS, &ConsoleInput, COLOR_INPUT_TEXT);
}
