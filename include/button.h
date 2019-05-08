/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** header
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "my_defender.h"

enum button_e {
    BUTTON_MENU = 1,
    BUTTON_PLAY_PAUSE,
    BUTTON_TOWER_ONE,
    BUTTON_TOWER_TWO,
    BUTTON_TOWER_THREE,
    BUTTON_TOWER_FOUR,
    BUTTON_FUNGUS
};

enum button {
    MENU_BUTTON_START = 1,
    MENU_BUTTON_SETTING,
    MENU_BUTTON_EXIT,
    MENU_BUTTON_HELP,
    GAME_BUTTON_SETTING,
    GAME_BUTTON_PAUSE,
    GAME_BUTTON_EXIT
};

typedef struct button_s {
    enum button_e type;
    int activate;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    struct scene_s *(*callback)(struct scene_s *);
    struct button_s *next;
    struct button_s *prev;
} button_t;

typedef struct menu_button_s {
    enum button type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int blow;
    sfIntRect rect;
    sfMusic *music;
    struct menu_button_s *next;
    struct menu_button_s *prev;
} menu_button_t;

#endif
