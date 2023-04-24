#include "shell.h"

/**
 * _strcat - Function that concatenante two strings
 * @dest: This is the string to be contenated to
 * @src: The source of string 
 *
 * Return: destination concatened string
 */

char *_strcat(char *dest, const char *source)
{
	char *ptr = dest + strlen(dest);
	
	while (*source != '\0')

{

	*ptr++ = *source++;
}

	*ptr = '\0';

	return(dest);

}


/**
  * _strcmp - The function compares two strings
  * @first:  First string
  * @second: Second string
  *
  * Return: 0  if first string == second string 
  * 	    -1 if first string < second string
  * 	    1  if first string > second string		 
  */
int _strcmp(char *first, char *second)
{
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0' && first[i] == second[i])
{
        i++;
}

        if (first[i] == '\0' && second[i] == '\0')
        {
        return 0;

}
        else if (first[i] < second[i])

{
        return -1;

} 

else

{

	return 1;
}

}



/**
  * _strlen - Function to find the size of the string
  * @string: The string to be founded
  *  
  * Return: Size of the string
  */

int _strlen(char *string)
{
 	int i = 0;
	
        while (string[i] != '\0')
        {
            ++i;
        }
        return (i);
}



/**
  * _strncmp - Function to compare the number of strings's characters
  * @string1: First string
  * @String2: Second string  
  * @n: numbers of characters to compare
  *
  * Return: Difference of two strings  
  */

int _strncmp(char *string1, char *string2, int n)
{
    int i;

    for (i = 0; string1[i] && string2[i] && i < n; i++)
    {
        if (string1[i] != string2[i])
            return (string1[i] - string2[i]);
    }

    if (i == n || string1[i] == string2[i])
        return 0;

    return (string1[i] - string2[i]);
}
