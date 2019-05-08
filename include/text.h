/*
** EPITECH PROJECT, 2019
** text.h
** File description:
** struct
*/

#ifndef TEXT_H
#define TEXT_H

#include "my_defender.h"

enum type {
    MONEY,
    PRICE_TOWER_ONE,
    PRICE_TOWER_TWO,
    PRICE_TOWER_THREE,
    PRICE_TOWER_FOUR
};

typedef struct money_s {
    int display;
    int nb;
    char *str;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    sfColor color;
} money_t;

typedef struct wave_s {
    int nb;
    char *str;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    sfColor color;
} wave_t;

typedef struct nb_enemies_s {
    int nb;
    char *str;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    sfColor color;
} nb_enemies_t;

typedef struct next_wave_s {
    bool pause;
    float time;
    float nb;
    char *str;
    sfClock *clock;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
} next_wave_t;

typedef struct text_s {
    struct money_s *money;
    struct wave_s *wave;
    struct nb_enemies_s *nb_enemies;
    struct next_wave_s *next_wave;
} text_t;

#endif