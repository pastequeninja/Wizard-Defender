/*
** EPITECH PROJECT, 2019
** init_color
** File description:
** my_defender
*/

#include "my_defender.h"

sfColor init_color(int r, int g, int b, int a)
{
    sfColor color = {r, g, b, a};

    return (color);
}