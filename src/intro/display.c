/*
** EPITECH PROJECT, 2019
** display intro
** File description:
** My_defender
*/

#include "my_defender.h"

void set_display(sfSprite *sprite, sfTexture *texture, \
sfRenderWindow *window, sfVector2f pos)
{
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_space_event(sfRenderWindow *window, intro_t *intro, sfClock *clock)
{
    sfSprite *sprite;
    sfTexture *texture;

    intro = access_space_event(intro);
    if (sfClock_getElapsedTime(clock).microseconds < 600000) {
        sprite = intro->space->sprite_1;
        texture = intro->space->texture_1;
    }
    if (sfClock_getElapsedTime(clock).microseconds > 600000) {
        sprite = intro->space->sprite_2;
        texture = intro->space->texture_2;
        if (sfClock_getElapsedTime(clock).microseconds > 1200000)
            sfClock_restart(clock);
    }
    sfSprite_setPosition(sprite, intro->space->pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void events_spaces(sfRenderWindow *window, scene_t **scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        (*scene)->intro = access_green_wizard((*scene)->intro);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            (*scene)->intro = access_green_wizard((*scene)->intro);
            (*scene)->intro->user_click += 1;
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int display_intro(sfRenderWindow *window, scene_t **scene, sfClock *clock)
{
    (*scene)->intro = access_background((*scene)->intro);
    sfRenderWindow_drawSprite(window, (*scene)->intro->sprite, NULL);
    draw_space_event(window, (*scene)->intro, clock);
    events_spaces(window, scene);
    (*scene)->intro = access_green_wizard((*scene)->intro);
    if ((*scene)->intro->user_click > 4)
        (*scene)->type = MENU;
    if ((*scene)->intro->user_click >= 1)
        display_intro_wizards((*scene)->intro, window);
    return SUCCESS;
}
