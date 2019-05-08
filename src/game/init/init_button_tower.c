/*
** EPITECH PROJECT, 2019
** initbuttontower
** File description:
** defender
*/

#include "my_defender.h"

button_t *diff_tower_next(button_t *button)
{
    if (button->type == BUTTON_TOWER_THREE) {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/tow_3.png", NULL)))
            return (NULL);
        button->pos = init_vec2f(1665, 600);
        button->size = init_vec2f(154, 148);
        button->rect = init_intrect(0, 0, 154, 148);
    }
    if (button->type == BUTTON_TOWER_FOUR) {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/tow_4.png", NULL)))
            return (NULL);
        button->pos = init_vec2f(1795, 600);
        button->size = init_vec2f(123, 148);
        button->rect = init_intrect(0, 0, 123, 148);
    }
    return (button);
}

button_t *diff_tower(button_t *button)
{
    if (button->type == BUTTON_TOWER_ONE) {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/tow_1.png", NULL)))
            return (NULL);
        button->pos = init_vec2f(1665, 310);
        button->size = init_vec2f(122, 148);
        button->rect = init_intrect(0, 0, 122, 148);
    }
    if (button->type == BUTTON_TOWER_TWO) {
        if (!(button->texture = \
            sfTexture_createFromFile("sprites/game/tow_2.png", NULL)))
            return (NULL);
        button->pos = init_vec2f(1795, 310);
        button->size = init_vec2f(120, 148);
        button->rect = init_intrect(0, 0, 120, 148);
    }
    return (diff_tower_next(button));
}

button_t *init_tower(button_t *button, int i)
{
    button->type = i;
    if (!(diff_tower(button)))
        return (NULL);
    button->activate = false;
    button->sprite = sfSprite_create();
    button->callback = &button_tower_press;
    return (button);
}

button_t *init_button_tower(button_t *button)
{
    if (!(button->next = malloc(sizeof(button_t))))
        return (NULL);
    button->next->prev = button;
    button = button->next;
    for (int i = 3; i < 7; i++) {
        if (!(button = init_tower(button, i)))
            return (NULL);
        if (i == 6)
            break;
        if (!(button->next = malloc(sizeof(button_t))))
            return (NULL);
        button->next->prev = button;
        button = button->next;
    }
    button->next = NULL;
    return (button);
}