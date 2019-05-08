/*
** EPITECH PROJECT, 2019
** wizards
** File description:
** My_defender
*/

#include "my_defender.h"

intro_t *access_attack_wizard(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != ATTACK; intro = intro->next);
    return (intro);
}

void wizard_attack_castle(sfRenderWindow *window, \
intro_t *intro)
{
    intro = access_attack_wizard(intro);
    if (sfClock_getElapsedTime(intro->clock).microseconds > 120000) {
        intro->rect.left += 250;
        sfClock_restart(intro->clock);
    }
    if (intro->rect.left >= 1800)
        intro->rect.left = 0;
    sfSprite_setPosition(intro->sprite, intro->pos);
    sfSprite_setTextureRect(intro->sprite, intro->rect);
    sfSprite_setTexture(intro->sprite, intro->texture, sfFalse);
    sfRenderWindow_drawSprite(window, intro->sprite, NULL);
    bombs_falls(intro, window);
}

void display_intro_wizards(intro_t *intro, \
sfRenderWindow *window)
{
    intro = access_green_wizard(intro);
    if (intro->user_click == 1) {
        display_normal_wizards(intro, window);
    }
    if (intro->user_click >= 2 && intro->user_click < 4) {
        intro->pos.x = 800;
        set_display(intro->sprite, intro->texture, window, intro->pos);
    }
    if (intro->user_click == 3) {
        intro = access_bubble(intro);
        set_display(intro->space->sprite_1, \
        intro->space->texture_1, window, intro->space->pos);
    }
    if (intro->user_click >= 4) {
        intro = access_bubble(intro);
        set_display(intro->space->sprite_2, intro->space->texture_2, \
        window, intro->space->pos_2);
        wizard_attack_castle(window, intro);
    }
}

void display_normal_wizards(intro_t *intro, sfRenderWindow *window)
{
    if (sfClock_getElapsedTime(intro->clock).microseconds > 100000 \
        && intro->pos.x < 800) {
        intro->rect.left += 250;
        sfClock_restart(intro->clock);
    }
    if (intro->rect.left >= 1980)
        intro->rect.left = 0;
    if (intro->pos.x >= 800) {
        intro->pos.x = 800;
    }
    intro->pos.x += 4;
    sfSprite_setPosition(intro->sprite, intro->pos);
    sfSprite_setTextureRect(intro->sprite, intro->rect);
    sfSprite_setTexture(intro->sprite, intro->texture, sfFalse);
    sfRenderWindow_drawSprite(window, intro->sprite, NULL);
}
