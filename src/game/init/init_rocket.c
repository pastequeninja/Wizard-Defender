/*
** EPITECH PROJECT, 2019
** init_rocket
** File description:
** my_defender
*/

#include "my_defender.h"

rocket_t *init_next_ball(game_object_t *game_object, rocket_t *rocket)
{
    if (game_object->tower == TOWER_FOUR) {
        if (!(rocket->texture = \
            sfTexture_createFromFile("sprites/game/ball_4.png", NULL)))
            return (NULL);
        rocket->damage = 35;
    }
    if (game_object->tower == TOWER_ONE) {
        if (!(rocket->texture = \
            sfTexture_createFromFile("sprites/game/ball.png", NULL)))
            return (NULL);
        rocket->damage = 10;
    }
    return (rocket);
}

rocket_t *init_ball(game_object_t *game_object, rocket_t *rocket)
{
    if (game_object->tower == TOWER_TWO) {
        if (!(rocket->texture = \
            sfTexture_createFromFile("sprites/game/ball_2.png", NULL)))
            return (NULL);
        rocket->damage = 15;
    }
    if (game_object->tower == TOWER_THREE) {
        if (!(rocket->texture = \
            sfTexture_createFromFile("sprites/game/ball_3.png", NULL)))
            return (NULL);
        rocket->damage = 25;
    }
    return (init_next_ball(game_object, rocket));
}

rocket_t *init_first_rocket(game_object_t *game_object, bool pause, float i)
{
    rocket_t *rocket = malloc(sizeof(rocket_t));

    if (!rocket)
        return (NULL);
    for (; game_object->next; game_object = game_object->next);
    rocket->prev = NULL;
    rocket->next = NULL;
    rocket->display = false;
    rocket->malloc = false;
    rocket->pause = pause;
    rocket->speed = 3 * i;
    rocket = init_ball(game_object, rocket);
    rocket->sprite = sfSprite_create();
    rocket->enemy = NULL;
    for (; game_object->next; game_object = game_object->next);
    rocket->tower = game_object;
    rocket->start = init_vec2f(game_object->pos.x + 54, game_object->pos.y);
    return (rocket);
}

rocket_t *init_new_rocket(rocket_t *rocket, game_object_t *game_object,
bool pause, float i)
{
    for (; rocket->next; rocket = rocket->next);
    for (; game_object->next; game_object = game_object->next);
    if (!(rocket->next = malloc(sizeof(rocket_t))))
        return (NULL);
    rocket->next->prev = rocket;
    rocket = rocket->next;
    rocket->next = NULL;
    rocket->display = false;
    rocket->pause = pause;
    rocket->malloc = false;
    rocket->speed = i * 3;
    rocket = init_ball(game_object, rocket);
    rocket->sprite = sfSprite_create();
    rocket->start = init_vec2f(game_object->pos.x + 54, game_object->pos.y);
    rocket->enemy = NULL;
    rocket->tower = game_object;
    for (; rocket->prev; rocket = rocket->prev);
    return (rocket);
}

scene_t *init_rocket(scene_t *scene)
{
    float i = scene->objs->speed;
    bool pause = scene->objs->pause;
    rocket_t *rocket = scene->objs->rocket;
    game_object_t *game_object = scene->objs->game_object;

    if (!rocket) {
        if (!(rocket = init_first_rocket(game_object, pause, i)))
            return (NULL);
    } else {
        if (!(rocket = init_new_rocket(rocket, game_object, pause, i)))
            return (NULL);
    }
    scene->objs->rocket = rocket;
    return (scene);
}