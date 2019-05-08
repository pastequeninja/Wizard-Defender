/*
** EPITECH PROJECT, 2019
** init_vec
** File description:
** defened
*/

#include "my_defender.h"

sfVector2f init_vec2f(float x, float y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

sfIntRect init_intrect(int top, int left, int width, int height)
{
    sfIntRect rect = {top, left, width, height};

    return (rect);
}
