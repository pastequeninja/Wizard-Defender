/*
** EPITECH PROJECT, 2019
** event_buttonretry
** File description:
** my_defendr
*/

#include "my_defender.h"

scene_t *retry_game(scene_t *scene)
{
    scene = scene->prev;
    destroy_for_new_game(scene);
    scene = re_init_new_game(scene);
    return (scene);
}