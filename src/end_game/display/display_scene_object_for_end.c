/*
** EPITECH PROJECT, 2019
** displayscene_obect_for_end
** File description:
** my_defender
*/

#include "my_defender.h"

void display_game_object_for_end(sfRenderWindow *window, game_object_t *go)
{
    if (!go)
        return;
    for (; go->prev; go = go->prev);
    for (; go; go = go->next) {
        sfSprite_setTexture(go->sprite, go->texture, sfFalse);
        sfSprite_setTextureRect(go->sprite, go->rect);
        sfSprite_setPosition(go->sprite, go->pos);
        sfRenderWindow_drawSprite(window, go->sprite, NULL);
    }
}

void display_rocket_end(sfRenderWindow *window, rocket_t *rocket)
{
    for (; rocket->prev; rocket = rocket->prev);
    for (; rocket; rocket = rocket->next) {
        sfSprite_setTexture(rocket->sprite, rocket->texture, sfFalse);
        sfSprite_setPosition(rocket->sprite, rocket->pos);
        sfRenderWindow_drawSprite(window, rocket->sprite, NULL);
    }
}

void display_heart_end(sfRenderWindow *window, heart_t *heart)
{
    for (; heart; heart = heart->next) {
        sfSprite_setTextureRect(heart->sprite, heart->rect);
        sfSprite_setTexture(heart->sprite, heart->texture, sfFalse);
        sfSprite_setPosition(heart->sprite, heart->pos);
        sfRenderWindow_drawSprite(window, heart->sprite, NULL);
    }
}

void display_scene_object_for_end(sfRenderWindow *window, scene_object_t *sc)
{
    display_background(window, sc->background);
    display_game_object_for_end(window, sc->game_object);
    if (sc->rocket)
        display_rocket_end(window, sc->rocket);
    if (sc->heart)
        display_heart_end(window, sc->heart);
}