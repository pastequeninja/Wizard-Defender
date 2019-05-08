/*
** EPITECH PROJECT, 2019
** display_heart
** File description:
** my_defender
*/

#include "my_defender.h"

void display_heart(sfRenderWindow *window, heart_t *heart, int life)
{
    for (int i = 0; i < life; heart = heart->next, i++) {
        if (heart->display == false)
            continue;
        sfSprite_setTextureRect(heart->sprite, heart->rect);
        sfSprite_setTexture(heart->sprite, heart->texture, sfFalse);
        sfSprite_setPosition(heart->sprite, heart->pos);
        sfRenderWindow_drawSprite(window, heart->sprite, NULL);
    }
}