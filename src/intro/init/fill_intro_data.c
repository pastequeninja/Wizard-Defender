/*
** EPITECH PROJECT, 2019
** fill all data in ll
** File description:
** My_defender
*/

#include "my_defender.h"

intro_t *set_intro_position(intro_t *intro, const char *str, float a, float b)
{
    intro->texture = sfTexture_createFromFile(str, NULL);
    intro->pos.y = a;
    intro->pos.x = b;
    sfSprite_setTexture(intro->sprite, intro->texture, sfFalse);
    sfSprite_setPosition(intro->sprite, intro->pos);
    return (intro);
}

intro_t *fill_intro_data1(intro_t *intro, int i)
{
    if (i == 4) {
        intro->type = ATTACK;
        intro = set_intro_position(intro, \
        "sprites/intro/blow.png", 750, 800);
        intro->rect.top = 0;
        intro->rect.left = 0;
        intro->rect.width = 225;
        intro->rect.height = 250;
        intro->clock = sfClock_create();
    }
    if (i == 5) {
        intro->type = EXPLOSION;
        intro->space = fill_bombs(intro->space);
    }
    if (i == 6) {
        intro->type = SMOKE;
        intro->space = fill_smoke(intro->space);
    }
    return (intro);
}

intro_t *fill_intro_data2(intro_t *intro, int i)
{
    if (i == 1) {
        intro->type = WIZARD1;
        intro = set_intro_position(intro, \
        "sprites/intro/walk_green.png", 750, -100);
        intro->rect.top = 0;
        intro->rect.left = 0;
        intro->rect.width = 225;
        intro->rect.height = 250;
        intro->clock = sfClock_create();
    }
    if (i == 2) {
        intro->type = SPACE;
        intro->space = fill_space_event(intro->space);
    }
    if (i == 3) {
        intro->type = BUBLE;
        intro->space = fill_bubble_event(intro->space);
    }
    return (intro);
}

intro_t *fill_intro_data(intro_t *intro, int i)
{
    intro->sprite = sfSprite_create();
    intro->user_click = 0;
    if (i == 0) {
        intro->type = BACK;
        intro = set_intro_position(intro, \
        "sprites/intro/intro.png", -30, 0);
    }
    intro = fill_intro_data1(intro, i);
    intro = fill_intro_data2(intro, i);
    return (intro);
}

intro_t *fill_intro(intro_t *intro)
{
    int i = 0;

    if ((intro = malloc(sizeof(intro_t))) == NULL)
        return NULL;
    intro->prev = NULL;
    while (i < 7) {
        intro = fill_intro_data(intro, i);
        if (i == 6)
            break;
        i++;
        if ((intro->next = malloc(sizeof(intro_t))) == NULL)
            return NULL;
        intro->next->prev = intro;
        intro = intro->next;
    }
    intro->next = NULL;
    for (;intro->prev != NULL; intro = intro->prev);
    return (intro);
}
