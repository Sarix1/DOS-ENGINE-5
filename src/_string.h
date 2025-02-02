#ifndef _STRING_H
#define _STRING_H

typedef struct
{
    char** strings;
    int count;
} StringList_t;

int strcmptok(char* str, char* token, char delim);
int findString(char* str, char** list);
StringList_t splitString(char* string, char* delim);

#endif/* _STRING_H */
