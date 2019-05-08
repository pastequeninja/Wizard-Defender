/*
** EPITECH PROJECT, 2019
** check other tower
** File description:
** my_defender
*/

#include "my_defender.h"

int check_if_touch_the_tower(game_object_t *game_object, tower_move_t *tower)
{
    float g_x = game_object->pos.x;
    float g_y = game_object->pos.y;
    float t_x = tower->pos.x;
    float t_y = tower->pos.y;
    float t_s_y = tower->size.y;

    if (t_x > g_x && t_x < g_x + 80) {
        if (t_y + 110 > g_y + 80 && t_y + 110 < g_y + game_object->size.y)
            return (SUCCESS);
    }
    if (t_x + 60 > g_x && t_x + 60 < g_x + 90) {
        if (t_y + t_s_y > g_y + 80 && t_y + t_s_y < g_y + game_object->size.y)
            return (SUCCESS);
    }
    if (t_x + 50 > g_x && t_x + 50 < g_x + 90) {
        if (t_y + 90 < g_y + 130 && t_y + 90 > g_y + 85)
            return (SUCCESS);
    }
    return (FAILURE);
}