/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display_tower
*/

#include "my_defender.h"

void display_towers(sfRenderWindow *window, game_object_t *game_object)
{
    sfSprite_setPosition(game_object->sprite, game_object->pos);
    sfSprite_setTextureRect(game_object->sprite, game_object->rect);
    sfSprite_setTexture(game_object->sprite, game_object->texture, sfFalse);
    sfRenderWindow_drawSprite(window, game_object->sprite, NULL);
}