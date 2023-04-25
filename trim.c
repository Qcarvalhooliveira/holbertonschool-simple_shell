#include "shell.h"

/**
 * trim - Function that remove whitespaces from start abd end strings
 * @str: trim string
 * Return: str
 */

char *trim(char *str)

{
    char *start = str;
    char *end = str + strlen(str) - 1;

    
    while (isspace(*start))
    {
        start++;
    }

    
    while (end > start && isspace(*end)) 
    {
        end--;
    }

    
    *(end+1) = '\0';

        memmove(str, start, end - start + 2);

    return str;
}
