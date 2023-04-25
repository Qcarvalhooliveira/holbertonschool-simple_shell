#include "shell.h"


char **split_env(char *path)

{
    int i = 0;
    char **tokens = malloc(sizeof(char*));
    char *token = strtok(path, "/");

    while (token != NULL) 
{
        tokens[i] = token;
        i++;
        tokens = realloc(tokens, (i+1)*sizeof(char*));
        token = strtok(NULL, "/");
}
    tokens[i] = NULL;

    return tokens;
}

int main() 
{
    char *path = "/home/user/documents/file.txt";
    char **tokens = split_env(path);

    int i = 0;
    while (tokens[i] != NULL) {
        printf("%s\n", tokens[i]);
        i++;
}

    free(tokens);
    
    return 0;
}
