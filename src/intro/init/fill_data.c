/*
** EPITECH PROJECT, 2019
** fill_data on elements
** File description:
** My_defender
*/

#include "my_defender.h"

intro_text_t *fill_space_event(intro_text_t *space)
{
    if ((space = malloc(sizeof(intro_text_t))) == NULL)
        return NULL;
    space->texture_1 = sfTexture_createFromFile(\
    "sprites/intro/space_1.png", NULL);
    space->sprite_1 = sfSprite_create();
    space->texture_2 = sfTexture_createFromFile(\
    "sprites/intro/space_2.png", NULL);
    space->sprite_2 = sfSprite_create();
    space->pos.x = 300;
    space->pos.y = 70;
    space->clock = sfClock_create();
    return (space);
}

intro_text_t *fill_bubble_event(intro_text_t *bubble)
{
    if ((bubble = malloc(sizeof(intro_text_t))) == NULL)
        return NULL;
    bubble->texture_1 = sfTexture_createFromFile(\
    "sprites/intro/bubble1.png", NULL);
    bubble->sprite_1 = sfSprite_create();
    bubble->texture_2 = sfTexture_createFromFile(\
    "sprites/intro/bubble2.png", NULL);
    bubble->sprite_2 = sfSprite_create();
    bubble->pos.x = 910;
    bubble->pos.y = 570;
    bubble->pos_2.x = 350;
    bubble->pos_2.y = 470;
    return (bubble);
}

intro_text_t *fill_smoke(intro_text_t *smoke)
{
    if ((smoke = malloc(sizeof(intro_text_t))) == NULL)
        return NULL;
    smoke->texture_1 = sfTexture_createFromFile(\
    "sprites/intro/fumée.png", NULL);
    smoke->sprite_1 = sfSprite_create();
    smoke->texture_2 = sfTexture_createFromFile(\
    "sprites/intro/fumée2.png", NULL);
    smoke->sprite_2 = sfSprite_create();
    smoke->pos.x = 1620;
    smoke->pos.y = -500;
    smoke->pos_2.x = 1840;
    smoke->pos_2.y = -500;
    return (smoke);
}

intro_text_t *fill_bombs(intro_text_t *bomb)
{
    if ((bomb = malloc(sizeof(intro_text_t))) == NULL)
        return NULL;
    bomb->texture_1 = sfTexture_createFromFile(\
    "sprites/intro/comète1.png", NULL);
    bomb->sprite_1 = sfSprite_create();
    bomb->texture_2 = sfTexture_createFromFile(\
    "sprites/intro/comète2.png", NULL);
    bomb->sprite_2 = sfSprite_create();
    bomb->pos.x = 1800;
    bomb->pos.y = -100;
    bomb->pos_2.x = 1720;
    bomb->pos_2.y = -100;
    bomb->texture_3 = sfTexture_createFromFile(\
    "sprites/intro/comète3.png", NULL);
    bomb->sprite_3 = sfSprite_create();
    bomb->pos_3.x = 1500;
    bomb->pos_3.y = -200;
    bomb->clock = sfClock_create();
    return (bomb);
}
