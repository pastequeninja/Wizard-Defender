/*
** EPITECH PROJECT, 2019
** init_game_obect
** File description:
** my_defender
*/

#include "my_defender.h"

game_object_t *first_init_game_object_tr(game_object_t *game_object)
{
    game_object->direction = FIRST_HORIZONTAL_RIGHT;
    if (game_object->character == CHARACTER_3) {
        game_object->speed_x = 1.3;
        game_object->time = 90000;
    }
    else if (game_object->character == CHARACTER_2) {
        game_object->speed_x = 1;
        game_object->time = 95000;
    }
    else if (game_object->character == CHARACTER_1) {
        game_object->speed_x = 0.7;
        game_object->time = 100000;
    }
    return (game_object);
}

game_object_t *fill_game_object_tr(game_object_t *game_object)
{
    if (game_object->character == CHARACTER_1)
        game_object->rect = init_intrect(0, 0, 104, 104);
    else if (game_object->character == CHARACTER_2)
        game_object->rect = init_intrect(0, 832, 104, 104);
    else
        game_object->rect = init_intrect(0, 1664, 104, 104);
    return (game_object);
}

game_object_t *return_game_object(game_object_t *game_object)
{
    game_object->next = NULL;
    for (; game_object->prev; game_object = game_object->prev);
    return (game_object);
}