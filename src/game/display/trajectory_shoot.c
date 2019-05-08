/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** trajectory_shoot
*/

#include "my_defender.h"

void deplacement_ball(rocket_t *rocket)
{
    float sp = rocket->speed;

    if (rocket->malloc == true)
        rocket->end = init_vec2f(rocket->enemy->pos.x + 52,
        rocket->enemy->pos.y + 40);
    rocket->a = (rocket->end.y - rocket->start.y) / \
    (rocket->end.x - rocket->start.x);
    if (rocket->end.x < rocket->start.x + 40 && \
        rocket->end.x > rocket->start.x - 40 && rocket->end.y > \
        rocket->start.y - 40 && rocket->end.y < rocket->start.y + 40)
        sp /= 3;
    rocket->b = (rocket->start.y) - (rocket->a * rocket->start.x);
    if (ABS((rocket->a)) < 1) {
        rocket->pos.x += (rocket->start.x > rocket->end.x) ? -sp : sp;
        rocket->pos.y = rocket->a * rocket->pos.x + rocket->b;
    } else {
        rocket->pos.y += (rocket->start.y > rocket->end.y) ? -sp : sp;
        rocket->pos.x = (rocket->pos.y - rocket->b) / rocket->a;
    }
}

void touch_enemy(rocket_t *rocket)
{
    if (rocket->malloc == false) {
        rocket->display = false;
        return;
    }
    rocket->enemy->life -= rocket->damage;
    rocket->display = false;
    rocket->malloc = false;
}

void continue_to_display(sfRenderWindow *window, rocket_t *rocket)
{
    if (rocket->pause == false)
        deplacement_ball(rocket);
    if (rocket->start.x > rocket->end.x) {
        if (rocket->pos.x < rocket->end.x)
            touch_enemy(rocket);
    } else {
        if (rocket->pos.x > rocket->end.x)
            touch_enemy(rocket);
    }
    if (rocket->start.y < rocket->end.y && rocket->pos.y > rocket->end.y)
        touch_enemy(rocket);
    sfSprite_setTexture(rocket->sprite, rocket->texture, sfFalse);
    sfSprite_setPosition(rocket->sprite, rocket->pos);
    sfRenderWindow_drawSprite(window, rocket->sprite, NULL);
}