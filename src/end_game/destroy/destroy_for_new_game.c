/*
** EPITECH PROJECT, 2019
** destory_for_new_game
** File description:
** my_defender
*/

#include "my_defender.h"

void destroy_game_object(game_object_t *go)
{
    if (!go)
        return;
    for (; go->prev; go = go->prev);
    while (go) {
        if (go->tower == NO_TOWER) {
            sfText_destroy(go->text);
            sfFont_destroy(go->font);
            sfClock_destroy(go->clock);
        }
        sfTexture_destroy(go->texture);
        sfSprite_destroy(go->sprite);
        go = go->next;
        if (go)
            free(go->prev);
    }
}

void destroy_rocket(rocket_t *rocket)
{
    if (!rocket)
        return;
    for (; rocket->prev; rocket = rocket->prev);
    while (rocket) {
        sfTexture_destroy(rocket->texture);
        sfSprite_destroy(rocket->sprite);
        rocket = rocket->next;
        if (rocket)
            free(rocket->prev);
    }
}

void destroy_tower_move(tower_move_t *tower_move)
{
    if (!tower_move)
        return;
    sfMusic_destroy(tower_move->music);
    sfTexture_destroy(tower_move->texture);
    sfSprite_destroy(tower_move->sprite);
    sfCircleShape_destroy(tower_move->circle);
}

void destroy_for_new_game(scene_t *scene)
{
    scene_object_t *obj = scene->objs;

    destroy_game_object(obj->game_object);
    destroy_rocket(obj->rocket);
    destroy_tower_move(obj->tower_move);
}