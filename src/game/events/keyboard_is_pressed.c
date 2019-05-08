/*
** EPITECH PROJECT, 2019
** keyboard is pressed
** File description:
** my_defender
*/

#include "my_defender.h"

void keyspace_is_pressed(scene_t *scene)
{
    button_t *button = scene->button;

    for (; button->type != BUTTON_PLAY_PAUSE; button = button->next);
    button->activate = true;
    scene = button->callback(scene);
    button->activate = false;
}