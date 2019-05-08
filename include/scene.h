/*
** EPITECH PROJECT, 2019
** scene
** File description:
** header
*/

#ifndef SCENE_H
#define SCENE_H

#include "my_defender.h"

enum sprite
{
    BACK,
    WIZARD1,
    BUBLE,
    SPACE,
    ATTACK,
    EXPLOSION,
    SMOKE
};
enum scenes
{
    MENU = 1,
    GAME,
    INTRO,
    RULES,
    SETTINGS,
    END,
    SETT
};

enum setting {
    BACKGROUND,
    WINDOW,
    MUSIC,
    FILTER
};

typedef struct title_s {
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    struct title_s *next;
    struct title_s *prev;
} title_t;

typedef struct wizard_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    struct wizard_s *next;
    struct wizard_s *prev;
} wizard_t;

typedef struct menu_background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfMusic *music;
    struct wizard_s *wizards;
    struct title_s *titles;
    struct menu_button_s *button;
    struct menu_background_s *next;
    struct menu_background_s *prev;
} menu_background_t;

typedef struct music_s_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos_ast;
    sfVector2f pos_star;
    sfVector2f pos_font;
    sfIntRect rect;
    sfSprite *sprite_ast;
    sfTexture *texture_ast;
    sfSprite *sprite_star;
    sfTexture *texture_star;
    bool music_play;
    struct music_s_s *next;
    struct music_s_s *prev;
} music_s_t;

typedef struct sett_s {
    enum setting type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    struct music_s_s *music;
    struct sett_s *next;
    struct sett_s *prev;
} sett_t;

typedef struct intro_text_s {
    sfSprite *sprite_1;
    sfTexture *texture_1;
    sfVector2f pos;
    sfSprite *sprite_3;
    sfTexture *texture_3;
    sfVector2f pos_3;
    sfVector2f pos_2;
    sfSprite *sprite_2;
    sfTexture *texture_2;
    sfClock *clock;
}intro_text_t;

typedef struct intro_s {
    enum sprite type;
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    int user_click;
    sfClock *clock;
    struct intro_text_s *space;
    struct intro_s *next;
    struct intro_s *prev;
}intro_t;

typedef struct rules_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
}rules_t;

typedef struct scene_s {
    enum scenes type;
    struct rules_s *rules;
    struct menu_button_s *menu_button;
    struct menu_background_s *menu_background;
    struct intro_s *intro;
    struct sett_s *setting;
    struct scene_object_s *objs;
    struct button_s *button;
    struct text_s *texts;
    struct music_s *music;
    struct scene_s *next;
    struct scene_s *prev;
} scene_t;

#endif
