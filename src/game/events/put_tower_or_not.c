/*
** EPITECH PROJECT, 2019
** put_tower_or_not
** File description:
** my_defender
*/

#include "my_defender.h"

void put_tower_at_the_end(game_object_t *game_object, tower_move_t *tower_move)
{
    for (; game_object->next; game_object = game_object->next);
    if (!(game_object->next = malloc(sizeof(game_object_t))))
        return;
    game_object->next->prev = game_object;
    game_object = game_object->next;
    game_object->tower = tower_move->type;
    game_object->texture = tower_move->texture;
    game_object->sprite = tower_move->sprite;
    game_object->pos = tower_move->pos;
    game_object->size = tower_move->size;
    game_object->rect = tower_move->rect;
    game_object->next = NULL;
}

int touch_path(emplacement_t *emplacement, tower_move_t *tower_move)
{
    float e_x = emplacement->pos.x;
    float e_y = emplacement->pos.y;
    float t_x = tower_move->pos.x;
    float t_y = tower_move->pos.y;
    float t_s_y = tower_move->size.y;

    if (e_x < t_x && e_x + emplacement->size.x > t_x + 90) {
        if (e_y < t_y + 90 && e_y + emplacement->size.y > t_y + t_s_y)
            return (FAILURE);
    }
    return (SUCCESS);
}

int touch_other_tower(scene_t *scene, tower_move_t *tower_move,
game_object_t *game_object)
{
    int verif = FAILURE;

    for (; game_object->prev; game_object = game_object->prev);
    for (; game_object; game_object = game_object->next) {
        if (game_object->tower != NO_TOWER)
            verif = check_if_touch_the_tower(game_object, tower_move);
        if (verif == SUCCESS)
            return (SUCCESS);
    }
    if (scene->texts->money->nb - tower_move->price < 0)
        return (SUCCESS);
    scene->texts->money->nb -= tower_move->price;
    return (FAILURE);
}

int tower_touch_smth(scene_t *scene, tower_move_t *tower_move)
{
    emplacement_t *emplacement = scene->objs->emplacement;
    game_object_t *game_object = scene->objs->game_object;

    for (; emplacement; emplacement = emplacement->next) {
        if (touch_path(emplacement, tower_move) == FAILURE)
            return (touch_other_tower(scene, tower_move, game_object));
    }
    return (SUCCESS);
}

void put_tower_or_not(scene_t *scene)
{
    tower_move_t *tower_move = scene->objs->tower_move;

    if (tower_move) {
        if (tower_touch_smth(scene, tower_move) == FAILURE) {
            sfMusic_play(scene->music->music_money);
            put_tower_at_the_end(scene->objs->game_object, tower_move);
            scene = init_rocket(scene);
        } else {
            sfCircleShape_destroy(tower_move->circle);
            sfTexture_destroy(tower_move->texture);
            sfSprite_destroy(tower_move->sprite);
        }
        if (!scene)
            return;
        free(tower_move);
        scene->objs->tower_move = NULL;
    }
}