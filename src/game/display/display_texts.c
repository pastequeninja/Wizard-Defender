/*
** EPITECH PROJECT, 2019
** display_texts
** File description:
** my_defender
*/

#include "my_defender.h"

int display_money(sfRenderWindow *window, money_t *money, int speed)
{
    static int i = 0;
    char *tmp;

    if (money->display == true && i % (200 - (speed * 50)) == 0)
        money->nb++;
    money->str = my_strdup(nbr_to_str(money->nb));
    if (!(tmp = malloc(sizeof(char) * (my_strlen(money->str) + 4))))
        return (FAILURE);
    tmp[0] = '\0';
    tmp = my_str_cat(tmp, money->str);
    tmp = my_str_cat(tmp, "$");
    sfText_setString(money->text, tmp);
    sfText_setColor(money->text, money->color);
    sfRenderWindow_drawText(window, money->text, NULL);
    free(tmp);
    free(money->str);
    i++;
    return (SUCCESS);
}

int display_wave(sfRenderWindow *window, wave_t *wave)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(wave->str) + 5));

    if (!tmp)
        return (FAILURE);
    tmp[0] = '\0';
    tmp = my_str_cat(tmp, wave->str);
    tmp = my_str_cat(tmp, nbr_to_str(wave->nb));
    sfText_setString(wave->text, tmp);
    sfText_setColor(wave->text, wave->color);
    sfRenderWindow_drawText(window, wave->text, NULL);
    free(tmp);
    return (SUCCESS);
}

int display_texts(sfRenderWindow *window, text_t *texts, float speed)
{
    if (display_money(window, texts->money, speed) == FAILURE)
        return (FAILURE);
    if (display_wave(window, texts->wave) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
