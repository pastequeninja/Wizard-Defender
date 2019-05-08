/*
** EPITECH PROJECT, 2019
** display_backgorun end
** File description:
** my_ddefender
*/

#include "my_defender.h"

int display_money_end(sfRenderWindow *window, money_t *money)
{
    char *tmp;

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
    return (SUCCESS);
}

int display_wave_end(sfRenderWindow *window, wave_t *wave)
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
    return (SUCCESS);
}

int display_texts_for_end(sfRenderWindow *window, text_t *text)
{
    if (display_money_end(window, text->money) == FAILURE)
        return (FAILURE);
    if (display_wave_end(window, text->wave) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int display_background_end(sfRenderWindow *window, scene_t *scene)
{
    display_scene_object_for_end(window, scene->objs);
    display_button(window, scene->button);
    if (display_texts_for_end(window, scene->texts) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}