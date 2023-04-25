#include "shell.h"

/**
  * get_path - To get command's path
  * @getcmd: Used to find the path of the command
  *
  * Return: command's path
  */

char *get_path(char *getcmd) 
{
    
    char *path = malloc(256*sizeof(char));
        
    FILE *maps_file = fopen("/proc/self/maps", "r");
    if (maps_file == NULL) 
{
        fprintf(stderr, "Error: Impossible to open file/proc/self/maps.\n");
        exit(1);
}
    
    char line[256];
    
    while (fgets(line, 256, maps_file) != NULL) 

{
 
    char *start = strstr(line, "/");
    char *end = strstr(line, getcmd);
        
    if (start != NULL && end != NULL) 
    
{
            sscanf(start, "%s", path);
            break;
}
    

}
    

    fclose(maps_file);
    
    return path;
}
