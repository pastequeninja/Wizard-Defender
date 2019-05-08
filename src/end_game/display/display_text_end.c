/*
** EPITECH PROJECT, 2019
** display
** File description:
** my_defender
*/

#include "my_defender.h"

void display_text_end(sfRenderWindow *window, wave_t *wave, int nb)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(wave->str) + 5));

    if (!tmp)
        return;
    tmp[0] = '\0';
    tmp = my_str_cat(tmp, wave->str);
    tmp = my_str_cat(tmp, nbr_to_str(nb));
    sfText_setString(wave->text, tmp);
    sfText_setColor(wave->text, wave->color);
    sfRenderWindow_drawText(window, wave->text, NULL);
    free(tmp);
}