/*
** EPITECH PROJECT, 2019
** init my elements
** File description:
** My_defender
*/

#include "my_defender.h"

music_s_t *initialize_tittle_music(music_s_t *music)
{
    music->font = sfFont_createFromFile("fonts/test_2.ttf");
    if (music->font == NULL)
        return NULL;
    music->text = sfText_create();
    music->pos_font.x = 885;
    music->pos_font.y = 300;
    sfText_setString(music->text, "MUSIC");
    sfText_setFont(music->text, music->font);
    sfText_setCharacterSize(music->text, 70);
    sfText_setPosition(music->text, music->pos_font);
    music->music_play = true;

    return (music);
}

music_s_t *initialize_sprites_music(music_s_t *music)
{
    music->sprite_star = sfSprite_create();
    music->sprite_ast = sfSprite_create();
    music->texture_ast = sfTexture_createFromFile(\
    "sprites/menu/baguette.png", NULL);
    music->texture_star = sfTexture_createFromFile(\
    "sprites/menu/etoile.png", NULL);
    music->pos_ast.y = 490;
    music->pos_ast.x = 650;
    music->pos_star.y = 420;
    music->pos_star.x = 830;
    sfSprite_setTexture(music->sprite_star, \
    music->texture_star, sfFalse);
    sfSprite_setTexture(music->sprite_ast, \
    music->texture_ast, sfFalse);
    sfSprite_setPosition(music->sprite_star, music->pos_star);
    sfSprite_setPosition(music->sprite_ast, music->pos_ast);
    return (music);
}

music_s_t *initialize_sprite_cut_music(music_s_t *music)
{
    music->sprite_star = sfSprite_create();
    music->sprite_ast = sfSprite_create();
    music->texture_ast = sfTexture_createFromFile(\
    "sprites/menu/musique.png", NULL);
    music->texture_star = sfTexture_createFromFile(\
    "sprites/menu/croix.png", NULL);
    music->pos_ast.y = 430;
    music->pos_ast.x = 1120;
    music->pos_star.y = 430;
    music->pos_star.x = 1120;
    sfSprite_setTexture(music->sprite_star, music->texture_star, sfFalse);
    sfSprite_setTexture(music->sprite_ast, music->texture_ast, sfFalse);
    sfSprite_setPosition(music->sprite_star, music->pos_star);
    sfSprite_setPosition(music->sprite_ast, music->pos_ast);
    music->music_play = true;

    return (music);
}

music_s_t *fill_musics(void)
{
    music_s_t *music;

    if ((music = malloc(sizeof(music_s_t))) == NULL)
        return NULL;
    music = initialize_tittle_music(music);
    music = initialize_sprites_music(music);
    music->prev = NULL;
    if ((music->next = malloc(sizeof(music_s_t))) == NULL)
        return NULL;
    music->next->prev = music;
    music->next = initialize_sprite_cut_music(music->next);
    music->next->next = NULL;
    return (music);
}
