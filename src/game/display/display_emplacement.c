/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display_emplacement
*/

#include "my_defender.h"

int touch_a_tower(tower_move_t *tower_move, game_object_t *game_object)
{
    int verif = FAILURE;

    for (; game_object->prev; game_object = game_object->prev);
    for (; game_object; game_object = game_object->next) {
        if (game_object->tower != NO_TOWER)
            verif = check_if_touch_the_tower(game_object, tower_move);
        if (verif == SUCCESS)
            return (FAILURE);
    }
    return (SUCCESS);
}

int touch_emplacement(emplacement_t *emplacement, tower_move_t *tower_move)
{
    float e_x = emplacement->pos.x;
    float e_y = emplacement->pos.y;
    float t_x = tower_move->pos.x;
    float t_y = tower_move->pos.y;
    float t_s_y = tower_move->size.y;

    if (e_x < t_x && e_x + emplacement->size.x > t_x + 90) {
        if (e_y < t_y + 90 && e_y + emplacement->size.y > t_y + t_s_y)
            return (SUCCESS);
    }
    return (FAILURE);
}

int check_emplacement(emplacement_t *emplacement, game_object_t *game_object,
tower_move_t *tower_move)
{
    for (; emplacement; emplacement = emplacement->next) {
        if (touch_emplacement(emplacement, tower_move) == SUCCESS)
            return (touch_a_tower(tower_move, game_object));
    }
    return (FAILURE);
}

void display_emplacement(sfRenderWindow *window, scene_object_t *scene_object)
{
    sfColor color;
    tower_move_t *tower_move = scene_object->tower_move;
    game_object_t *game_object = scene_object->game_object;
    emplacement_t *emplacement = scene_object->emplacement;

    if (check_emplacement(emplacement, game_object, tower_move) == SUCCESS)
        color = init_color(100, 100, 0, 100);
    else
        color = init_color(255, 0, 0, 150);
    for (; emplacement->next; emplacement = emplacement->next) {
        sfRectangleShape_setFillColor(emplacement->rect, color);
        sfRenderWindow_drawRectangleShape(window, emplacement->rect, NULL);
    }
}