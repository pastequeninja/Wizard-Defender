/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** init_end
*/

#include "my_defender.h"

wave_t *init_end_texts(void)
{
    wave_t *wave = malloc(sizeof(wave_t));

    if (!wave)
        return (NULL);
    if (!(wave->str = my_strdup("Wave ")))
        return (NULL);
    if (!(wave->font = sfFont_createFromFile("fonts/sett.ttf")))
        return (NULL);
    if (!(wave->text = sfText_create()))
        return (NULL);
    wave->pos = init_vec2f(1020, 370);
    wave->color = init_color(255, 200, 0, 255);
    sfText_setFont(wave->text, wave->font);
    sfText_setCharacterSize(wave->text, 85);
    sfText_setPosition(wave->text, wave->pos);
    return (wave);
}

scene_t *init_end(scene_t *scene)
{
    if (!(scene->next = malloc(sizeof(scene_t))))
        return (NULL);
    scene->next->prev = scene;
    scene = scene->next;
    scene->type = END;
    if (!(scene->objs = init_end_obj()))
        return (NULL);
    if (!(scene->button = init_end_button()))
        return (NULL);
    if (!(scene->texts = malloc(sizeof(text_t))))
        return (NULL);
    if (!(scene->texts->wave = init_end_texts()))
        return (NULL);
    return (scene);
}