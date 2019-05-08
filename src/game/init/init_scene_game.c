/*
** EPITECH PROJECT, 2019
** init_game_scene
** File description:
** defender
*/

#include "my_defender.h"

scene_object_t *init_var_so(scene_object_t *objs)
{
    objs->nb_character = 3;
    objs->nb_malloc = 3;
    objs->tower_move = NULL;
    objs->rocket = NULL;
    objs->pause = false;
    objs->speed = 1;
    objs->life = 3;
    return (objs);
}

scene_object_t *init_scene_object(scene_object_t *objs)
{
    if (!(objs->background = malloc(sizeof(background_t))))
        return (NULL);
    if (!(objs->background = init_background(objs->background)))
        return (NULL);
    if (!(objs->game_object = malloc(sizeof(game_object_t))))
        return (NULL);
    if (!(objs->game_object = init_game_object(objs->game_object)))
        return (NULL);
    if (!(objs->emplacement = malloc(sizeof(emplacement_t))))
        return (NULL);
    if (!(objs->emplacement = init_emplacement(objs->emplacement)))
        return (NULL);
    if (!(objs->heart = init_heart()))
        return (NULL);
    objs = init_var_so(objs);
    return (objs);
}

button_t *init_button(button_t *button)
{
    button->prev = NULL;
    if (!(button = init_button_setting(button)))
        return (NULL);
    if (!(button->next = malloc(sizeof(button_t))))
        return (NULL);
    button->next->prev = button;
    button = button->next;
    if (!(button = init_button_playpause(button)))
        return (NULL);
    if (!(button = init_button_tower(button)))
        return (NULL);
    if (!(button = init_fungus(button)))
        return (NULL);
    for (; button->prev; button = button->prev);
    return (button);
}

scene_t *init_scene_game(scene_t *scene)
{
    scene->type = GAME;
    if (!(scene->objs = malloc(sizeof(scene_object_t))))
        return (NULL);
    if (!(scene->objs = init_scene_object(scene->objs)))
        return (NULL);
    if (!(scene->button = malloc(sizeof(button_t))))
        return (NULL);
    if (!(scene->button = init_button(scene->button)))
        return (NULL);
    if (!(scene->texts = malloc(sizeof(text_t))))
        return (NULL);
    if (!(scene->texts = init_texts(scene->texts)))
        return (NULL);
    if (!(scene->music = init_music(scene->music)))
        return (NULL);
    return (scene);
}
