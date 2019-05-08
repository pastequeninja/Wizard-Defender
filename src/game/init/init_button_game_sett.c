/*
** EPITECH PROJECT, 2019
** init_buttongamesett
** File description:
** my_defende
*/

#include "my_defender.h"

button_t *next_fill_sett(button_t *button, int i)
{
    if (i == 0) {
        button->rect = init_intrect(0, 0, 320, 213);
        button->pos = init_vec2f(530, 520);
        button->callback = &return_to_the_menu;
    }
    if (i == 1) {
        button->rect = init_intrect(320, 0, 320, 213);
        button->pos = init_vec2f(1040, 520);
        button->callback = &retry_game_sett;
    }
    if (i == 2) {
        button->rect = init_intrect(640, 0, 320, 213);
        button->pos = init_vec2f(770, 300);
        button->callback = &return_the_game;
    }
    if (i == 3) {
        button->rect = init_intrect(0, 0, 60, 60);
        button->pos = init_vec2f(1300, 350);
    }
    return (button);
}

button_t *fill_button_game_sett(button_t *button, int i)
{
    if (i < 3) {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/end.png", NULL)))
            return (NULL);
        button->size = init_vec2f(320, 213);
    } else {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/menu/exit_2.png", NULL)))
            return (NULL);
        button->size = init_vec2f(60, 60);
    }
    return (next_fill_sett(button, i));
}

button_t *init_button_game_sett(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->prev = NULL;
    for (int i = 0; i < 4; i++) {
        if (!(button->sprite = sfSprite_create()))
            return (NULL);
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/end.png", NULL)))
            return (NULL);
        if (!(button = fill_button_game_sett(button, i)))
            return (NULL);
        if (i == 3)
            break;
        if (!(button->next = malloc(sizeof(button_t))))
            return (NULL);
        button->next->prev = button;
        button = button->next;
    }
    button->next = NULL;
    for (; button->prev; button = button->prev);
    return (button);
}