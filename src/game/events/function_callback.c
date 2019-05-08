/*
** EPITECH PROJECT, 2019
** function_call_back
** File description:
** defedner
*/

#include "my_defender.h"

scene_t *next_scene(scene_t *scene)
{
    scene = scene->next;
    scene = scene->next;
    return (scene);
}

rocket_t *pause_rocket(rocket_t *rocket)
{
    for (; rocket->next; rocket = rocket->next) {
        if (rocket->pause == false)
            rocket->pause = true;
        else
            rocket->pause = false;
    }
    if (rocket->pause == false)
        rocket->pause = true;
    else
        rocket->pause = false;
    for (; rocket->prev; rocket = rocket->prev);
    return (rocket);
}

scene_t *change_button_play(scene_t *scene)
{
    button_t *button = scene->button;
    game_object_t *game_object = scene->objs->game_object;

    for (; button->activate != true; button = button->next);
    button->rect.left += (button->rect.left == 93) ? -93 : 93;
    for (; game_object->prev; game_object = game_object->prev);
    if (button->rect.left == 0) {
        for (; game_object; game_object = game_object->next)
            game_object->display = false;
    } else {
        for (; game_object; game_object = game_object->next)
            game_object->display = true;
    }
    if (scene->texts->money->display == true)
        scene->texts->money->display = false;
    else
        scene->texts->money->display = true;
    scene->objs->pause = (scene->objs->pause == false) ? true : false;
    if (scene->objs->rocket)
        scene->objs->rocket = pause_rocket(scene->objs->rocket);
    return (scene);
}