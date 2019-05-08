/*
** EPITECH PROJECT, 2019
** init_heart
** File description:
** my_defender
*/

#include "my_defender.h"

void init_position(heart_t *heart, int i)
{
    heart->display = true;
    heart->rect = init_intrect(0, 0, 87, 75);
    heart->size = init_vec2f(87, 75);
    if (i == 0)
        heart->pos = init_vec2f(30, 40);
    if (i == 1)
        heart->pos = init_vec2f(130, 40);
    if (i == 2)
        heart->pos = init_vec2f(230, 40);
}

heart_t *return_heart(heart_t *heart)
{
    heart->next = NULL;
    for (; heart->prev; heart = heart->prev);
    return (heart);
}

heart_t *init_heart(void)
{
    heart_t *heart = malloc(sizeof(heart_t));

    if (!heart)
        return (NULL);
    heart->prev = NULL;
    for (int i = 0; i < 3; i++) {
        if (!(heart->texture = \
            sfTexture_createFromFile("sprites/game/heart.png", NULL)))
            return (NULL);
        heart->sprite = sfSprite_create();
        init_position(heart, i);
        if (i == 2)
            break;
        if (!(heart->next = malloc(sizeof(heart_t))))
            return (NULL);
        heart->next->prev = heart;
        heart = heart->next;
    }
    return (return_heart(heart));
}