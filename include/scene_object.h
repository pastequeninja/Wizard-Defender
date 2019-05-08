/*
** EPITECH PROJECT, 2019
** scene_object
** File description:
** header
*/

#ifndef scene_object_H
#define scene_object_H

#include "my_defender.h"

enum character_e {
    CHARACTER_1,
    CHARACTER_2,
    CHARACTER_3
};

enum tower_e {
    NO_TOWER = 0,
    TOWER_ONE,
    TOWER_TWO,
    TOWER_THREE,
    TOWER_FOUR
};

enum direction_e {
    FIRST_HORIZONTAL_RIGHT = 1,
    FIRST_DIAGONAL_RIGHT_DOWN,
    FIRST_VERTICAL_DOWN,
    FIRST_DIAGONAL_LEFT_DOWN,
    FIRST_HORIZONTAL_LEFT,
    SECOND_DIAGONAL_LEFT_DOWN,
    SECOND_VERTICAL_DOWN,
    SECOND_DIAGONAL_RIGHT_DOWN,
    SECOND_HORIZONTAL_RIGHT,
    FIRST_DIAGONAL_RIGHT_UP,
    FIRST_VERTICAL_UP,
    FIRST_DIAGONAL_LEFT_UP,
    SECOND_HORIZONTAL_LEFT,
    SECOND_DIAGONAL_LEFT_UP,
    SECOND_VERTICAL_UP,
    SECOND_DIAGONAL_RIGHT_UP,
    THIRD_HORIZONTAL_RIGHT,
    THIRD_DIAGONAL_RIGHT_DOWN,
    THIRD_VERTICAL_DOWN,
    THIRD_DIAGONAL_LEFT_DOWN,
    THIRD_HORIZONTAL_LEFT,
    THIRD_DIAGONAL_LEFT_UP,
    THIRD_VERTICAL_UP,
    FOURTH_DIAGONAL_LEFT_UP,
    FOURTH_HORIZONTAL_LEFT,
    FOURTH_DIAGONAL_LEFT_DOWN,
    FOURTH_VERTICAL_DOWN,
    FOURTH_DIAGONAL_RIGHT_DOWN,
    FOURTH_HORIZONTAL_RIGHT,
    FIFTH_DIAGONAL_RIGHT_DOWN,
    FIFTH_VERTICAL_DOWN
};

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} background_t;

typedef struct game_object_s {
    enum direction_e direction;
    enum character_e character;
    enum tower_e tower;
    int time;
    int display;
    int diff_for_direction;
    int life;
    int pos_in_list;
    float speed_x;
    float speed_y;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    sfText *text;
    sfFont *font;
    sfColor color;
    sfVector2f pos_life;
    struct game_object_s *next;
    struct game_object_s *prev;
} game_object_t;

typedef struct tower_move_s {
    enum tower_e type;
    int price;
    sfMusic *music;
    sfColor color;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f size;
    sfCircleShape *circle;
} tower_move_t;

typedef struct emplacement_s {
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfSprite *sprite;
    struct emplacement_s *next;
    struct emplacement_s *prev;
} emplacement_t;

typedef struct rocket_s {
    struct game_object_s *tower;
    struct game_object_s *enemy;
    bool display;
    bool pause;
    bool calcul_y;
    bool malloc;
    float a;
    float b;
    float speed;
    int damage;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f start;
    sfVector2f end;
    sfClock *clock;
    struct rocket_s *next;
    struct rocket_s *prev;
} rocket_t;

typedef struct heart_s {
    bool display;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    struct heart_s *next;
    struct heart_s *prev;
} heart_t;

typedef struct scene_object_s {
    int nb_character;
    int nb_malloc;
    bool pause;
    float speed;
    int life;
    struct background_s *background;
    struct game_object_s *game_object;
    struct tower_move_s *tower_move;
    struct emplacement_s *emplacement;
    struct rocket_s *rocket;
    struct heart_s *heart;
} scene_object_t;

#endif
