/*
** EPITECH PROJECT, 2019
** move_scene_objects
** File description:
** my_defender
*/

#include "my_defender.h"

void move_character(game_object_t *game_object)
{
    int tmp_x = game_object->pos.x + game_object->diff_for_direction;
    int tmp_y = game_object->pos.y + game_object->diff_for_direction;

    first_walk(game_object, tmp_x, tmp_y);
    game_object->pos.x += game_object->speed_x;
    game_object->pos.y += game_object->speed_y;
    if (sfClock_getElapsedTime(game_object->clock).microseconds > \
    game_object->time) {
        game_object->rect.left += 104;
        if (game_object->rect.left == 832)
            game_object->rect.left = 0;
        sfClock_restart(game_object->clock);
    }
}