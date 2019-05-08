/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** button_fugus
*/

#include "my_defender.h"

button_t *init_fungus(button_t *button)
{
    if (!(button->next = malloc(sizeof(button_t))))
        return (NULL);
    button->next->prev = button;
    button = button->next;
    button->type = BUTTON_FUNGUS;
    button->activate = false;
    if (!(button->texture = \
        sfTexture_createFromFile("sprites/game/fungus.png", NULL)))
        return (NULL);
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(1750, 900);
    button->size = init_vec2f(75, 75);
    button->rect = init_intrect(0, 0, 75, 75);
    button->callback = &change_speed;
    button->next = NULL;
    return (button);
}