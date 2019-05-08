/*
** EPITECH PROJECT, 2019
** change_speed
** File description:
** my_defender
*/

#include "my_defender.h"

void change_speed_game_object_next(game_object_t *game_object, float x,
float y)
{
    if (ABS(x) == ABS(y)) {
        game_object->speed_x += (x < 0 ? 0.6 : -0.6);
        game_object->speed_y += (y < 0 ? 0.6 : -0.6);
        return;
    }
    if (x != 0)
        game_object->speed_x += (x < 0 ? 1.2 : -1.2);
    if (y != 0)
        game_object->speed_y += (y < 0 ? 1.2 : -1.2);
}

void change_speed_game_object(game_object_t *game_object, int left, float x,
float y)
{
    if (left == 0 || left == 75) {
        if (ABS(x) == ABS(y)) {
            game_object->speed_x += (x < 0 ? -0.3 : 0.3);
            game_object->speed_y += (y < 0 ? -0.3 : 0.3);
            return;
        }
        if (x != 0)
            game_object->speed_x += (x < 0 ? -0.6 : 0.6);
        if (y != 0)
            game_object->speed_y += (y < 0 ? -0.6 : 0.6);
    } else
        change_speed_game_object_next(game_object, x, y);
}

void change_speed_rocket(rocket_t *rocket, int left)
{
    if (left == 0 || left == 75)
        rocket->speed += 1;
    else
        rocket->speed = 3;
}

scene_t *change_speed(scene_t *scene)
{
    int left;
    button_t *button = scene->button;
    rocket_t *rocket = scene->objs->rocket;
    game_object_t *game_object = scene->objs->game_object;

    for (; button->type != BUTTON_FUNGUS; button = button->next);
    left = button->rect.left;
    for (; game_object->prev; game_object = game_object->prev);
    for (; game_object; game_object = game_object->next) {
        if (game_object->tower == NO_TOWER)
            change_speed_game_object(game_object, button->rect.left,
            game_object->speed_x, game_object->speed_y);
    }
    for (; rocket; rocket = rocket->next)
        change_speed_rocket(rocket, button->rect.left);
    scene->objs->speed += (left == 0 || left == 75) ? 1 : -2;
    button->rect.left += (button->rect.left != 150) ? 75 : -150;
    return (scene);
}