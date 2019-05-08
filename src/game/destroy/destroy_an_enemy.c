/*
** EPITECH PROJECT, 2019
** free_game_object
** File description:
** my_defender
*/

#include "my_defender.h"

game_object_t *delete_enemy(game_object_t *enemy)
{
    game_object_t *tmp = NULL;

    if (enemy->next && !(enemy->prev)) {
        enemy = enemy->next;
        free(enemy->prev);
        enemy->prev = NULL;
        return (enemy);
    } else if (enemy->prev && !(enemy->next)) {
        enemy = enemy->prev;
        free(enemy->next);
        enemy->next = NULL;
        for (; enemy->prev; enemy = enemy->prev);
        return (enemy);
    }
    tmp = enemy;
    enemy->next->prev = enemy->prev;
    enemy->prev->next = enemy->next;
    for (; enemy->prev; enemy = enemy->prev);
    free(tmp);
    return (enemy);
}

scene_object_t *delete_last_enemy(scene_object_t *obj, game_object_t *go)
{
    free(go);
    obj->game_object = NULL;
    return (obj);
}

void destroy_object(game_object_t *enemy)
{
    sfClock_destroy(enemy->clock);
    sfTexture_destroy(enemy->texture);
    sfSprite_destroy(enemy->sprite);
    sfText_destroy(enemy->text);
    sfFont_destroy(enemy->font);
}

scene_object_t *destroy_enemy(scene_object_t *scene_object)
{
    game_object_t *enemy = scene_object->game_object;
    game_object_t *tmp = scene_object->game_object;

    for (; enemy->prev; enemy = enemy->prev);
    for (; enemy; enemy = enemy->next) {
        if (enemy->tower == NO_TOWER && (enemy->life <= 0 || \
            (enemy->pos.x > 1350 && enemy->pos.y > 740)))
            break;
    }
    if (!enemy) {
        scene_object->game_object = tmp;
        return (scene_object);
    }
    if (enemy->pos.x > 1350 && enemy->pos.y > 740)
        scene_object->life--;
    scene_object->nb_character--;
    destroy_object(enemy);
    if (!(enemy->prev) && !(enemy->next))
        return (delete_last_enemy(scene_object, enemy));
    scene_object->game_object = delete_enemy(enemy);
    return (scene_object);
}