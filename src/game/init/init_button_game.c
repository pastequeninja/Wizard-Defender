/*
** EPITECH PROJECT, 2019
** init_button_game
** File description:
** defender
*/

#include "my_defender.h"

button_t *init_button_setting(button_t *button)
{
    button->type = BUTTON_MENU;
    if (!(button->texture = \
        sfTexture_createFromFile("sprites/game/setting.png", NULL)))
        return (NULL);
    button->activate = false;
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(1820, 100);
    button->size = init_vec2f(85, 85);
    button->rect = init_intrect(0, 0, 85, 85);
    button->callback = &next_scene;
    return (button);
}

button_t *init_button_playpause(button_t *button)
{
    button->type = BUTTON_PLAY_PAUSE;
    if (!(button->texture = \
        sfTexture_createFromFile("sprites/game/play_pause.png", NULL)))
        return (NULL);
    button->activate = false;
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(1720, 100);
    button->size = init_vec2f(85, 85);
    button->rect = init_intrect(93, 0, 77, 85);
    button->callback = &change_button_play;
    return (button);
}