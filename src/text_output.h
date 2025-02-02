#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>

enum PRINT_FLAGS
{
    PRINT_FLAG_STDOUT,
    PRINT_FLAG_STDERR,
    PRINT_FLAG_CONSOLE
};

void print(int color, char* format, ...);
void printStatus(int status);

#define setPrintFlags(flags) (g_System.print_flags |= (flags))
#define clearPrintFlags(flags) (g_System.print_flags &= ~(flags))

#endif/* PRINT_H */
