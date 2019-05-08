/*
** EPITECH PROJECT, 2019
** sort_game_object
** File description:
** my_defender
*/

#include "my_defender.h"

int game_object_is_sorted(game_object_t *game_object)
{
    int tmp_x = game_object->pos.x;
    int tmp_y = game_object->pos.y;

    for (; game_object->next; game_object = game_object->next) {
        if (game_object->pos.x + 40 > tmp_x && game_object->pos.y + 45 > tmp_y)
            return (FAILURE);
    }
    return (SUCCESS);
}

int more_position(game_object_t *game_object)
{
    int i = 0;
    int final = 0;
    int tmp_y = game_object->pos.y;

    for (; game_object; game_object = game_object->next) {
        if (game_object->pos.y < tmp_y) {
            final = i;
            tmp_y = game_object->pos.y;
        }
        i++;
    }
    return (final);
}

game_object_t *sort_linked_list(game_object_t *game_object,
game_object_t *first)
{
    game_object_t *tmp = NULL;

    tmp = first->prev;
    first->prev = game_object->prev;
    game_object->prev = tmp;
    tmp = first->next;
    first->next = game_object->next;
    game_object->next = tmp;
    if (first->prev)
        first->prev->next = first;
    if (first->next)
        first->next->prev = first;
    if (game_object->prev)
        game_object->prev->next = game_object;
    if (game_object->next)
        game_object->next->prev = game_object;
    game_object = game_object->next;
    return (game_object);
}

game_object_t *sort_when_next_to(game_object_t *game_object,
game_object_t *first)
{
    first->next = game_object->next;
    game_object->prev = first->prev;
    if (first->next)
        first->next->prev = first;
    if (game_object->prev)
        game_object->prev->next = game_object;
    game_object->next = first;
    first->prev = game_object;
    game_object = game_object->next;
    return (game_object);
}

game_object_t *sort_game_object(game_object_t *game_object)
{
    int i = 0;
    game_object_t *first = NULL;

    while (game_object->next) {
        first = game_object;
        i = more_position(game_object);
        if (i == 0) {
            game_object = game_object->next;
            continue;
        }
        for (int a = 0; a < i; a++, game_object = game_object->next);
        if (i == 1) {
            game_object = sort_when_next_to(game_object, first);
            continue;
        }
        game_object = sort_linked_list(game_object, first);
    }
    for (; game_object->prev; game_object = game_object->prev);
    return (game_object);
}