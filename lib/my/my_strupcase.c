/*
** EPITECH PROJECT, 2018
** task07 / Day06
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
