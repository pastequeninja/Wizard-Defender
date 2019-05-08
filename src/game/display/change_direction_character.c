/*
** EPITECH PROJECT, 2019
** change direction characeter
** File description:
** my_defender
*/

#include "my_defender.h"

void change_direction(game_object_t *walk, float speed_x, float speed_y,
int rect)
{
    walk->speed_x = speed_x;
    walk->speed_y = speed_y;
    walk->rect.top += rect;
    walk->direction++;
}

void fourth_walk(game_object_t *walk, int tmp_x)
{
    if (tmp_x > 910 && walk->direction == FOURTH_DIAGONAL_RIGHT_DOWN)
        change_direction(walk, walk->speed_x * 2, 0, -104);
    if (tmp_x > 1480 && walk->direction == FOURTH_HORIZONTAL_RIGHT)
        change_direction(walk, walk->speed_x / 2, walk->speed_x / 2, 104);
    if (tmp_x > 1483 && walk->direction == FIFTH_DIAGONAL_RIGHT_DOWN)
        change_direction(walk, 0, walk->speed_y * 2, 104);
}

void third_walk(game_object_t *walk, int tmp_x, int tmp_y)
{
    if (tmp_y > 565 && walk->direction == THIRD_VERTICAL_DOWN)
        change_direction(walk, -walk->speed_y / 2, walk->speed_y / 2, 104);
    if (tmp_x < 1480 && walk->direction == THIRD_DIAGONAL_LEFT_DOWN)
        change_direction(walk, walk->speed_x * 2, 0, 104);
    if (tmp_x < 1171 && walk->direction == THIRD_HORIZONTAL_LEFT)
        change_direction(walk, walk->speed_x / 2, walk->speed_x / 2, 104);
    if (tmp_x < 1168 && walk->direction == THIRD_DIAGONAL_LEFT_UP)
        change_direction(walk, 0, walk->speed_y * 2, 104);
    if (tmp_y < 254 && walk->direction == THIRD_VERTICAL_UP)
        change_direction(walk, walk->speed_y / 2, walk->speed_y / 2, -104);
    if (tmp_x < 1165 && walk->direction == FOURTH_DIAGONAL_LEFT_UP)
        change_direction(walk, walk->speed_x * 2, 0, -104);
    if (tmp_x < 910 && walk->direction == FOURTH_HORIZONTAL_LEFT)
        change_direction(walk, walk->speed_x / 2, -walk->speed_x / 2, -104);
    if (tmp_x < 907 && walk->direction == FOURTH_DIAGONAL_LEFT_DOWN)
        change_direction(walk, 0, walk->speed_y * 2, -104);
    if (tmp_y > 822 && walk->direction == FOURTH_VERTICAL_DOWN)
        change_direction(walk, walk->speed_y / 2, walk->speed_y / 2, -104);
    fourth_walk(walk, tmp_x);
}

void second_walk(game_object_t *walk, int tmp_x, int tmp_y)
{
    if (tmp_x > 651 && walk->direction == FIRST_DIAGONAL_RIGHT_UP)
        change_direction(walk, 0, walk->speed_y * 2, -104);
    if (tmp_y < 450 && walk->direction == FIRST_VERTICAL_UP)
        change_direction(walk, walk->speed_y / 2, walk->speed_y / 2, -104);
    if (tmp_x < 648 && walk->direction == FIRST_DIAGONAL_LEFT_UP)
        change_direction(walk, walk->speed_x * 2, 0, -104);
    if (tmp_x < 529 && walk->direction == SECOND_HORIZONTAL_LEFT)
        change_direction(walk, walk->speed_x / 2, walk->speed_x / 2, 104);
    if (tmp_x < 526 && walk->direction == SECOND_DIAGONAL_LEFT_UP)
        change_direction(walk, 0, walk->speed_x * 2, 104);
    if (tmp_y < 63 && walk->direction == SECOND_VERTICAL_UP)
        change_direction(walk, -walk->speed_y / 2, walk->speed_y / 2, 104);
    if (tmp_x > 529 && walk->direction == SECOND_DIAGONAL_RIGHT_UP)
        change_direction(walk, walk->speed_x * 2, 0, -728);
    if (tmp_x > 1480 && walk->direction == THIRD_HORIZONTAL_RIGHT)
        change_direction(walk, walk->speed_x / 2, walk->speed_x / 2, 104);
    if (tmp_x > 1483 && walk->direction == THIRD_DIAGONAL_RIGHT_DOWN)
        change_direction(walk, 0, walk->speed_x * 2, 104);
    third_walk(walk, tmp_x, tmp_y);
}

void first_walk(game_object_t *walk, int tmp_x, int tmp_y)
{
    if (tmp_x > 266 && walk->direction == FIRST_HORIZONTAL_RIGHT)
        change_direction(walk, walk->speed_x / 2, walk->speed_x / 2, 104);
    if (tmp_x > 269 && walk->direction == FIRST_DIAGONAL_RIGHT_DOWN)
        change_direction(walk, 0, walk->speed_y * 2, 104);
    if (tmp_y > 446 && walk->direction == FIRST_VERTICAL_DOWN)
        change_direction(walk, -walk->speed_y / 2, walk->speed_y / 2, 104);
    if (tmp_x < 266 && walk->direction == FIRST_DIAGONAL_LEFT_DOWN)
        change_direction(walk, walk->speed_x * 2, 0, 104);
    if (tmp_x < 80 && walk->direction == FIRST_HORIZONTAL_LEFT)
        change_direction(walk, walk->speed_x / 2, -walk->speed_x / 2, -104);
    if (tmp_x < 77 && walk->direction == SECOND_DIAGONAL_LEFT_DOWN)
        change_direction(walk, 0, walk->speed_y * 2, -104);
    if (tmp_y > 760 && walk->direction == SECOND_VERTICAL_DOWN)
        change_direction(walk, walk->speed_y / 2, walk->speed_y / 2, -104);
    if (tmp_x > 80 && walk->direction == SECOND_DIAGONAL_RIGHT_DOWN)
        change_direction(walk, walk->speed_y * 2, 0, -104);
    if (tmp_x > 648 && walk->direction == SECOND_HORIZONTAL_RIGHT)
        change_direction(walk, walk->speed_x / 2, -walk->speed_x / 2, 728);
    second_walk(walk, tmp_x, tmp_y);
}