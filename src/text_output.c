#include <stdio.h>
#include <stdarg.h>

#include "_common.h"
#include "_status.h"
#include "system.h"

#include "console.h"
#include "input.h"

#include "text_defines.h"
#include "text_input.h"
#include "text_output.h"

void setTextColor(byte fore, byte back)
{
	// Escape code to set foreground/background colours
	printf("%c[1;%d;%dm", 0x1B, fore, back);
}

void print(int color, char* format, ...)
{
    va_list args;
    byte color_;

    color_ = color;

    if (g_System.print_flags & PRINT_FLAG_CONSOLE)
    {
        va_start(args, format);
        v_printConsole(color_, format, args);
        va_end(args);
    }
}

void printStatus(int status)
{
    if (status == SUCCESS || status == FAILURE)
        print(0, "%s\n", error_strings[status]);
    else if (status > 0 && status < NUM_ERRORS)
        print(0, "Error: %s\n", error_strings[status]);
    else
        print(0, "Invalid error id: %d\n", status);
}
