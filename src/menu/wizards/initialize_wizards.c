/*
** EPITECH PROJECT, 2019
** initialize sprites
** File description:
** My_defender
*/

#include "my_defender.h"

wizard_t *fill_wizards_data(wizard_t *wizard, char *str, int x, int y)
{
    wizard->texture = sfTexture_createFromFile(str, NULL);
    wizard->pos.x = x;
    wizard->pos.y = y;
    wizard->rect.top = 0;
    wizard->rect.left = 0;
    wizard->rect.width = 225;
    wizard->rect.height = 250;
    wizard->sprite = sfSprite_create();
    return (wizard);
}

wizard_t *fill_wizards(wizard_t *wizards)
{
    wizards->prev = NULL;
    wizards = fill_wizards_data(wizards, \
    "sprites/menu/walk_little2.png", -40, 750);
    if ((wizards->next = malloc(sizeof(wizard_t))) == NULL)
        return NULL;
    wizards->next->prev = wizards;
    wizards->next = fill_wizards_data(wizards->next, \
    "sprites/menu/walk_new.png", -140, 750);
    wizards->next->next = NULL;
    return (wizards);
}
