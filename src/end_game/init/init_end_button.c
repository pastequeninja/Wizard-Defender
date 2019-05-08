/*
** EPITECH PROJECT, 2019
** init_button
** File description:
** my_defender
*/

#include "my_defender.h"

button_t *fill_button_end(button_t *button, int i)
{
    if (i == 0) {
        button->pos = init_vec2f(1050, 530);
        button->size = init_vec2f(320, 213);
        button->rect = init_intrect(320, 0, 320, 213);
        button->callback = &retry_game;
    } else {
        button->pos = init_vec2f(520, 530);
        button->size = init_vec2f(320, 213);
        button->rect = init_intrect(0, 0, 320, 213);
        button->callback = &return_to_home;
    }
    return (button);
}

button_t *init_end_button(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->prev = NULL;
    for (int i = 0; i < 2; i++) {
        button->activate = false;
        button->sprite = sfSprite_create();
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/end.png", NULL)))
            return (NULL);
        button = fill_button_end(button, i);
        if (i == 1)
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