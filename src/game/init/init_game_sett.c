/*
** EPITECH PROJECT, 2019
** inti_game_sett
** File description:
** my_deefender
*/

#include "my_defender.h"

background_t *init_bg_sett(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (!bg)
        return (NULL);
    if (!(bg->texture = \
        sfTexture_createFromFile("sprites/intro/intro.png", NULL)))
        return (NULL);
    if (!(bg->sprite = sfSprite_create()))
        return (NULL);
    bg->pos = init_vec2f(0, 0);
    return (bg);
}

game_object_t *init_go_sett(void)
{
    game_object_t *go = malloc(sizeof(game_object_t));

    if (!go)
        return (NULL);
    go->next = NULL;
    go->prev = NULL;
    if (!(go->texture = \
        sfTexture_createFromFile("sprites/game/board.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(500, 300);
    return (go);
}

scene_object_t *init_background_sett(void)
{
    scene_object_t *sc = malloc(sizeof(scene_object_t));

    if (!sc)
        return (NULL);
    if (!(sc->background = init_bg_sett()))
        return (NULL);
    if (!(sc->game_object = init_go_sett()))
        return (NULL);
    return (sc);
}

scene_t *init_game_sett(scene_t *scene)
{
    if (!(scene->next = malloc(sizeof(scene_t))))
        return (NULL);
    scene->next->prev = scene;
    scene = scene->next;
    scene->type = SETT;
    scene->button = init_button_game_sett();
    scene->objs = init_background_sett();
    return (scene);
}