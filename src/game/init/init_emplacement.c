/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** init_emplacement
*/

#include "my_defender.h"

sfVector2f init_pos_rect(int i)
{
    if (i == 0)
        return (init_vec2f(0, 250));
    if (i == 1)
        return (init_vec2f(375, 85));
    if (i == 2)
        return (init_vec2f(185, 570));
    if (i == 3)
        return (init_vec2f(0, 888));
    if (i == 4)
        return (init_vec2f(632, 185));
    if (i == 5)
        return (init_vec2f(1015, 185));
    if (i == 6)
        return (init_vec2f(1270, 185));
    if (i == 7)
        return (init_vec2f(760, 575));
    if (i == 8)
        return (init_vec2f(1015, 375));
    else
        return (init_vec2f(1175, 695));
}

sfVector2f init_size_rect(int i)
{
    if (i == 0)
        return (init_vec2f(265, 205));
    if (i == 1)
        return (init_vec2f(145, 360));
    if (i == 2)
        return (init_vec2f(460, 205));
    if (i == 3)
        return (init_vec2f(710, 132));
    if (i == 4)
        return (init_vec2f(273, 272));
    if (i == 5)
        return (init_vec2f(125, 80));
    if (i == 6)
        return (init_vec2f(210, 400));
    if (i == 7)
        return (init_vec2f(145, 280));
    if (i == 8)
        return (init_vec2f(145, 315));
    else
        return (init_vec2f(350, 145));
}

emplacement_t *init_arrow(emplacement_t *emplacement)
{
    if (!(emplacement->next = malloc(sizeof(emplacement_t))))
        return (NULL);
    emplacement->next->prev = emplacement;
    emplacement = emplacement->next;
    if (!(emplacement->texture = \
        sfTexture_createFromFile("sprites/game/arrow.png", NULL)))
        return (NULL);
    if (!(emplacement->sprite = sfSprite_create()))
        return (NULL);
    emplacement->pos = init_vec2f(0, 140);
    emplacement->color = init_color(0, 0, 0, 255);
    emplacement->next = NULL;
    for (; emplacement->prev; emplacement = emplacement->prev);
    return (emplacement);
}

emplacement_t *init_emplacement(emplacement_t *emplacement)
{
    emplacement->prev = NULL;
    for (int i = 0; i < 10; i++) {
        emplacement->color = init_color(100, 100, 0, 100);
        if (!(emplacement->rect = sfRectangleShape_create()))
            return (NULL);
        emplacement->pos = init_pos_rect(i);
        emplacement->size = init_size_rect(i);
        sfRectangleShape_setPosition(emplacement->rect, emplacement->pos);
        sfRectangleShape_setSize(emplacement->rect, emplacement->size);
        sfRectangleShape_setFillColor(emplacement->rect, emplacement->color);
        if (i == 9)
            break;
        if (!(emplacement->next = malloc(sizeof(emplacement_t))))
            return (NULL);
        emplacement->next->prev = emplacement;
        emplacement = emplacement->next;
    }
    if (!(emplacement = init_arrow(emplacement)))
        return (NULL);
    return (emplacement);
}