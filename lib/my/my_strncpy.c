/*
** EPITECH PROJECT, 2018
** task02 / Day06
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int p = 0;

    while (p != n) {
        dest[i] = src[i];
        p++;
        i++;
    }
    return (dest);
}
