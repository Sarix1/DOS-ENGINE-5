#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "_common.h"
#include "_malloc.h"

#include "text_input.h"
#include "text_defines.h"
#include "text_structs.h"
#include "input.h"

char FAR format_buffer[FORMAT_BUFFER_SIZE] = {0};

void initRingBuf(RingBuf_t* buf, byte* str, size_t size)
{
    if (str == NULL)
        buf->start = (byte*)malloc(size*sizeof(byte*));
    else
        buf->start = str;

    buf->end = buf->start+size;
    buf->read = buf->start;
    buf->write = buf->start;
}

// Log_t

// auxiliary function, do not call directly
static inline void logWrite_(Log_t* log, byte* str, int len, byte color)
{
    int lastlen = len;
    log->L_write->color = color;
    while (len--)
    {
        if (*str == '\n')
            logNewLine(log, color);
        else
            logPutChar(log, *str);
        str++;
    }
    log->L_write->end = log->Buffer.write;
}

// receives a string, does no formatting
void logWrite(Log_t* log, char* str, int len, byte color)
{
    int free_space, write_len;
    
    if (len == 0)
        len = strlen(str);
    if (len <= 0 || len >= logMaxChars(log))
        return;
    if (logNumChars(log) == 0)
    {
        log->L_write->start = log->Buffer.write;
        log->L_write->end = log->Buffer.read;
    }
    
    do {
        free_space = log->max_cols - logLineLen(log, log->L_write);
        if (free_space == 0)
        {
            logNewLine(log, color);
            continue;
        }
        write_len = MIN(free_space, len);
        logWrite_(log, str, write_len, color);
        len -= write_len;
        str += write_len;
    } while (len > 0);
}

// receives a va_list; use like fprintf
void v_logWrite_f(Log_t* log, byte color, byte* format, va_list args)
{
    int len = vsnprintf(format_buffer, FORMAT_BUFFER_SIZE, format, args);
    len = MIN(len, FORMAT_BUFFER_SIZE);
    ASSERT(len > 0);
    logWrite(log, format_buffer, len, color);
}

// receives multiple arguments; use like printf
void logWrite_f(Log_t* log, byte color, byte* format, ...)
{
    va_list args;
    va_start(args, format);
    v_logWrite_f(log, color, format, args);
    va_end(args);
}

// TextInput_t

void resetInput(TextInput_t* input)
{
    input->buffer[0] = '\0';
    input->length = 0;
    input->cursor = 0;
    input->start = 0;
}

static inline void cursorLeft(TextInput_t* text)
{
    if (text->cursor > text->start)
        text->cursor--;
}

static inline void cursorRight(TextInput_t* text)
{
    if (text->cursor < text->length-1)
        text->cursor++;
}

static inline void writeChar(TextInput_t* text, byte c)
{
    if (text->length < text->capacity-1)
    {
        if (text->cursor < text->length)
        {
            int i;
            for (i = text->length; i > text->cursor; i--)
                text->buffer[i] = text->buffer[i-1];
        }
        text->buffer[text->cursor++] = c;
        text->buffer[++text->length] = '\0';
    }
}

static inline void eraseChar(TextInput_t* text)
{
    if (text->cursor > text->start)
    {
        if (text->cursor < text->length)
        {
            int i;
            for (i = text->cursor; i < text->length; i++)
                text->buffer[i-1] = text->buffer[i];
        }
        text->cursor--;
        text->length--;
        text->buffer[text->length] = '\0';
    }
}

static inline char keyToAscii(byte keycode)
{
    byte c;

    if (keycode < 128)
    {
        if ((isKeyDown(KEY_LSHIFT) | isKeyDown(KEY_RSHIFT)) ^ (g_Input.flags & INP_FLAG_CAPS_LOCK))
            c = ascii_shifted[keycode];
        else
            c = ascii[keycode];
    }
    else
        c = ascii_special[keycode & 0x7F];
    // return a character if the keycode corresponds to a valid ASCII code
    if ((c >= 32 && c < 128) || c == '/')
        return c;
    
    return 0;
}

int handleTextInput(InputEvent_t event)
{   
    byte c;

    if (event.type == EV_KEY_REL)
        return INPUT_NOT_HANDLED;

    switch (event.data.keycode)
    {
        // Caps lock
        case KEY_CAPS_LOCK:
            g_Input.flags ^= INP_FLAG_CAPS_LOCK;
            break;
        // Arrow keys
        case KEY_LEFT:
            cursorLeft(g_Input.input_field);
            break;
        case KEY_RIGHT:
            cursorRight(g_Input.input_field);
            break;
        // Backspace
        case KEY_BACKSPACE:
            eraseChar(g_Input.input_field);
            break;
        // Enter
        case KEY_ENTER:
        case KEY_PAD_ENTER:
            if (isKeyDown(KEY_LSHIFT) || isKeyDown(KEY_RSHIFT))
                writeChar(g_Input.input_field, '\n');
            else
                g_Input.input_callback(g_Input.input_field);
            break;
        // Write character
        default:
            if (c = keyToAscii(event.data.keycode))
                writeChar(g_Input.input_field, c);
            else
            return INPUT_NOT_HANDLED;
    }

    return INPUT_HANDLED;
}
