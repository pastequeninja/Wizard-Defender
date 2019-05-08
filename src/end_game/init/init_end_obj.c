/*
** EPITECH PROJECT, 2019
** inti_obj
** File description:
** my_defnedr
*/

#include "my_defender.h"

game_object_t *file_game_object_end(game_object_t *game_object, int i)
{
    if (i == 0) {
        if (!(game_object->texture = \
            sfTexture_createFromFile("sprites/game/board.png", NULL)))
            return (NULL);
        game_object->rect = init_intrect(0, 0, 900, 460);
        game_object->size = init_vec2f(900, 460);
        game_object->pos = init_vec2f(500, 300);
    }
    if (i == 1) {
        if (!(game_object->texture = \
            sfTexture_createFromFile("sprites/game/walk_end.png", NULL)))
            return (NULL);
        game_object->pos = init_vec2f(690, 300);
        game_object->rect = init_intrect(0, 0, 512, 512);
        game_object->size = init_vec2f(512, 512);
        game_object->clock = sfClock_create();
        game_object->time = 83000;
    }
    return (game_object);
}

game_object_t *init_game_object_end(void)
{
    game_object_t *game_object = malloc(sizeof(game_object_t));

    if (!game_object)
        return (NULL);
    game_object->prev = NULL;
    for (int i = 0; i < 2; i++) {
        game_object->sprite = sfSprite_create();
        if (!(game_object = file_game_object_end(game_object, i)))
            return (NULL);
        if (i == 1)
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

game_object_t *init_medal(game_object_t *obj)
{
    for (; obj->next; obj = obj->next);
    if (!(obj->next = malloc(sizeof(game_object_t))))
        return (NULL);
    obj->next->prev = obj;
    obj = obj->next;
    if (!(obj->texture = \
        sfTexture_createFromFile("sprites/game/medal.png", NULL)))
        return (NULL);
    if (!(obj->sprite = sfSprite_create()))
        return (NULL);
    obj->pos = init_vec2f(600, 310);
    obj->size = init_vec2f(400 / 3, 246);
    obj->next = NULL;
    for (; obj->prev; obj = obj->prev);
    return (obj);
}

scene_object_t *init_end_obj(void)
{
    scene_object_t *scene_object = malloc(sizeof(scene_object_t));

    if (!scene_object)
        return (NULL);
    if (!(scene_object->game_object = init_game_object_end()))
        return (NULL);
    if (!(scene_object->game_object = init_medal(scene_object->game_object)))
        return (NULL);
    return (scene_object);
}