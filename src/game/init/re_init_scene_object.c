/*
** EPITECH PROJECT, 2019
** re_int_scene_oject
** File description:
** my_defendeer
*/

#include "my_defender.h"

void init_speed(game_object_t *game_object, float i)
{
    if (i == 2)
        game_object->speed_x += 0.6;
    if (i == 3) {
        game_object->speed_x += 1.2;
    }
}

game_object_t *init_first(game_object_t *game_object, int i)
{
    game_object->pos_in_list = i;
    if (i % 9 == 0 && i != 0)
        game_object->character = CHARACTER_3;
    else if (i % 6 == 0 && i != 0)
        game_object->character = CHARACTER_2;
    else
        game_object->character = CHARACTER_1;
    return (game_object);
}

game_object_t *re_init(game_object_t *game_object, int nb, float b)
{
    for (; game_object->next; game_object = game_object->next);
    if (!(game_object->next = malloc(sizeof(game_object_t))))
        return (NULL);
    game_object->next->prev = game_object;
    game_object = game_object->next;
    for (int i = 0; i < nb; i++) {
        game_object = init_first(game_object, i);
        if (!(game_object = fill_game_object(game_object, nb, nb)))
            return (NULL);
        init_speed(game_object, b);
        if (i == nb - 1)
            break;
        if (!(game_object->next = malloc(sizeof(game_object_t))))
            return (NULL);
        game_object->next->prev = game_object;
        game_object = game_object->next;
    }
    game_object->next = NULL;
    for (; game_object->prev; game_object = game_object->prev);
    return (game_object);
}

scene_object_t *re_init_enemy(scene_object_t *scene_object)
{
    float i = scene_object->speed;

    scene_object->nb_malloc += 3;
    scene_object->nb_character = scene_object->nb_malloc;
    if (!(scene_object->game_object = \
        re_init(scene_object->game_object, scene_object->nb_malloc, i)))
        return (NULL);
    return (scene_object);
}