/*
** EPITECH PROJECT, 2019
** re_int_new_game
** File description:
** my_defender
*/

#include "my_defender.h"

button_t *change_fungers(button_t *button)
{
    for (; button->next; button = button->next);
    button->rect.left = 0;
    for (; button->prev; button = button->prev);
    return (button);
}

scene_t *re_init_new_game(scene_t *scene)
{
    scene->texts->wave->nb = 1;
    scene->texts->money->nb = 10;
    scene->objs->nb_character = 3;
    scene->objs->life = 3;
    scene->objs->speed = 1;
    scene->objs->nb_malloc = 3;
    if (!(scene->objs->game_object = malloc(sizeof(game_object_t))))
        return (NULL);
    if (!(scene->objs->game_object = \
        init_game_object(scene->objs->game_object)))
        return (NULL);
    scene->objs->rocket = NULL;
    scene->objs->tower_move = NULL;
    scene->button = change_fungers(scene->button);
    return (scene);
}