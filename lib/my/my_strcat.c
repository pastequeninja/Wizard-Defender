/*
** EPITECH PROJECT, 2018
** tesk02 / Day07
** File description:
** my_strcat
*/

#include <stddef.h>

char *my_strcat(char *dest, char const *src, int *position)
{
    int a = 0;

    if (dest == NULL)
        return (NULL);
    while (src[a] != '\0') {
        dest[*position] = src[a];
        a++;
        *position += 1;
    }
    return (dest);
}
