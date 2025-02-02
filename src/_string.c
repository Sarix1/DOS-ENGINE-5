#include <string.h>
#include "_common.h"
#include "_string.h"

StringList_t splitString(char* string, char* delim)
{
    StringList_t tokens;
    char* token = strtok(string, delim);

    while (token != NULL)
    {
        tokens.strings[tokens.count] = token;
        tokens.count++;
        token = strtok(NULL, delim);
    }

    return tokens;
}

int findString(char* string, char** strings)
{
    int index = 0;

    while (strings[index] != NULL)
    {
        if (strcmp(string, strings[index]) == 0)
            return index;

        index++;
    }

    return NOT_FOUND;
}

int strcmptok(char* str, char* token, char delim)
{
    int index = 0; 
    
    /* Skip leading delimiters */
    while (*str == delim)
    {
        str++;
        index++;
    }
    
    /* Compare characters until we hit end of token */
    while (*token != '\0')
    {
        if (*str != *token)
            return -1;
            
        str++;
        token++;
        index++;
    }
    
    /* If next character is delimiter or null, we found the token */
    if (*str == delim || *str == '\0')
        return index;
        
    /* Found the characters but not as a complete token */
    return -1;
}

/*
int strcmptok(char* str, char* token, char delim)
{
    int index = 0; // position in str
    // skip delimeter character(s) in the beginning
    while (*str == delim)
    {
        str++;
        index++;
    }
    // compare str and token
    while (*str == *token)
    {
        // end of token reached and strings were identical;
        // return index in str where the token string ends (final character+1)
        if (*token == '\0')
            return index;

        str++;
        token++;
        index++;
    }
    // when the strings diverge, return -1 (token not found)
    return -1;
}
*/