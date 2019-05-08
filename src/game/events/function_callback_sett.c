/*
** EPITECH PROJECT, 2019
** funtciton
** File description:
** my_defender
*/

#include "my_defender.h"

scene_t *return_the_game(scene_t *scene)
{
    scene = scene->prev;
    scene = scene->prev;
    return (scene);
}

scene_t *retry_game_sett(scene_t *scene)
{
    scene = scene->prev;
    scene = scene->prev;
    destroy_for_new_game(scene);
    scene = re_init_new_game(scene);
    return (scene);
}

scene_t *return_to_the_menu(scene_t *scene)
{
    scene = scene->prev;
    scene = scene->prev;
    destroy_for_new_game(scene);
    scene = re_init_new_game(scene);
    scene = scene->prev;
    return (scene);
}