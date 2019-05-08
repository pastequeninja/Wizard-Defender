/*
** EPITECH PROJECT, 2019
** event_buttonhom
** File description:
** my_defender
*/

#include "my_defender.h"

scene_t *return_to_home(scene_t *scene)
{
    scene = scene->prev;
    destroy_for_new_game(scene);
    scene = re_init_new_game(scene);
    scene = scene->prev;
    return (scene);
}