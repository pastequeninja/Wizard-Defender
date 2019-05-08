/*
** EPITECH PROJECT, 2019
** my_defene
** File description:
** dipslay_rocket
*/

#include "my_defender.h"

int check_if_can_touch(game_object_t *game_object, rocket_t *rocket)
{
    sfVector2f pos_enemy = init_vec2f(game_object->pos.x, game_object->pos.y);
    sfVector2f pos_tower = rocket->tower->pos;

    pos_enemy.x += 52;
    pos_enemy.y += 52;
    pos_tower.x += 54;
    if (pos_tower.x - 150 < pos_enemy.x && pos_tower.y + 230 > pos_enemy.y \
        && pos_tower.x + 150 > pos_enemy.x && pos_tower.y - 100 < pos_enemy.y \
        && pos_enemy.x > 0)
        return (SUCCESS);
    return (FAILURE);
}

void calcul_traj(rocket_t *rocket)
{
    rocket->a = (rocket->end.y - rocket->start.y) / \
    (rocket->end.x - rocket->start.x);
    rocket->b = (rocket->start.y) - (rocket->a * rocket->start.x);
    rocket->pos = rocket->start;
}

void search_an_enemy(game_object_t *game_object, rocket_t *rocket)
{
    int verif = FAILURE;

    for (; game_object->prev; game_object = game_object->prev);
    for (; game_object; game_object = game_object->next) {
        if (game_object->tower == NO_TOWER)
            verif = check_if_can_touch(game_object, rocket);
        if (verif == SUCCESS) {
            rocket->enemy = game_object;
            rocket->end = init_vec2f(game_object->pos.x + 52,
            game_object->pos.y + 40);
            rocket->display = true;
            rocket->malloc = true;
            calcul_traj(rocket);
            return;
        }
    }
}

void change_rocket(rocket_t *rocket)
{
    for (; rocket->prev; rocket = rocket->prev);
    for (; rocket; rocket = rocket->next) {
        if (rocket->display == false)
            rocket->malloc = false;
        if (rocket->malloc == false)
            continue;
        if (rocket->enemy->life <= 0 || (rocket->enemy->pos.x > 1350 && \
            rocket->enemy->pos.y > 740))
            rocket->malloc = false;
    }
}

scene_object_t *display_rocket(sfRenderWindow *window,
scene_object_t *scene_object)
{
    game_object_t *game_object = scene_object->game_object;
    rocket_t *rocket = scene_object->rocket;

    for (; rocket; rocket = rocket->next) {
        if (rocket->display == true) {
            continue_to_display(window, rocket);
            change_rocket(scene_object->rocket);
            scene_object = destroy_enemy(scene_object);
            game_object = scene_object->game_object;
        } else if (rocket->display == false && scene_object->pause == false)
            search_an_enemy(game_object, rocket);
    }
    return (scene_object);
}