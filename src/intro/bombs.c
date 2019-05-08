/*
** EPITECH PROJECT, 2019
** bombs and smoke
** File description:
** My_defender
*/

#include "my_defender.h"

void bombs_falls(intro_t *intro, sfRenderWindow *window)
{
    intro = access_bombs(intro);
    if (sfClock_getElapsedTime(intro->space->clock).microseconds \
        > 100000) {
        intro->space->pos.y += 10;
        intro->space->pos_2.y += 8;
        intro->space->pos_3.y += 12;
        sfClock_restart(intro->space->clock);
    }
    if (intro->space->pos.y >= 500) {
        intro->space->pos.y = -300;
        intro->space->pos_2.y = -300;
        intro->space->pos_3.y = -600;
    }
    set_display(intro->space->sprite_1, \
    intro->space->texture_1, window, intro->space->pos);
    set_display(intro->space->sprite_2, \
    intro->space->texture_2, window, intro->space->pos_2);
    set_display(intro->space->sprite_3, \
    intro->space->texture_3, window, intro->space->pos_3);
}
