#include "shell.h"

/**
  * get_path - To get command's path
  * @getcmd: Used to find the path of the command
  *
  * Return: command's path
  */

char *get_path(char *getcmd)
{
    char line[256];
    char *path = NULL;

    FILE *maps_file = fopen("/proc/self/maps", "r");
    if (maps_file == NULL)
    {
        fprintf(stderr, "Error: Impossible to open file/proc/self/maps.\n");
        exit(1);
    }

    while (fgets(line, 256, maps_file) != NULL)
    {
        char *start = strstr(line, "/");
        char *end = strstr(line, getcmd);

        if (start != NULL && end != NULL)
        {
            path = malloc(strlen(start) + 1);
            if (path == NULL)
            {
                fprintf(stderr, "Error: Memory allocation failed.\n");
                exit(1);
            }
            sscanf(start, "%s", path);
            break;
        }
    }

    fclose(maps_file);

    return path;
}
