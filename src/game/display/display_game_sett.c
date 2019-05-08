/*
** EPITECH PROJECT, 2019
** display_game
** File description:
** my_defnede
*/

#include "my_defender.h"

void display_background_gs(sfRenderWindow *window, background_t *bg)
{
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setPosition(bg->sprite, bg->pos);
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
}

void display_go_sett(sfRenderWindow *window, game_object_t *go)
{
    sfSprite_setTexture(go->sprite, go->texture, sfFalse);
    sfSprite_setPosition(go->sprite, go->pos);
    sfRenderWindow_drawSprite(window, go->sprite, NULL);
}

void display_button_sett(sfRenderWindow *window, button_t *button)
{
    for (; button->prev; button = button->prev);
    for (; button; button = button->next) {
        sfSprite_setTexture(button->sprite, button->texture, sfFalse);
        sfSprite_setTextureRect(button->sprite, button->rect);
        sfSprite_setPosition(button->sprite, button->pos);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    }
}

int display_game_sett(sfRenderWindow *window, scene_t **scene)
{
    display_background_gs(window, (*scene)->objs->background);
    display_go_sett(window, (*scene)->objs->game_object);
    display_button_sett(window, (*scene)->button);
    events_game_sett(window, scene);
    return (SUCCESS);
}