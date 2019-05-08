/*
** EPITECH PROJECT, 2019
** display_scene_game
** File description:
** defender
*/

#include "my_defender.h"

void display_arrow(sfRenderWindow *window, emplacement_t *emplacement)
{
    static int i = 20;
    static int mult = 2;

    if (i == -1)
        return;
    for (; emplacement->next; emplacement = emplacement->next);
    i += mult;
    if (i == 246)
        mult = -2;
    emplacement->color = init_color(255, 255, 255, i);
    sfSprite_setTexture(emplacement->sprite, emplacement->texture, sfFalse);
    sfSprite_setPosition(emplacement->sprite, emplacement->pos);
    sfSprite_setColor(emplacement->sprite, emplacement->color);
    sfRenderWindow_drawSprite(window, emplacement->sprite, NULL);
    if (i == 0)
        i = -1;
}

void display_scene_object(sfRenderWindow *window, scene_object_t *objs)
{
    game_object_t *game_object = objs->game_object;

    display_background(window, objs->background);
    if (objs->tower_move)
        display_emplacement(window, objs);
    display_arrow(window, objs->emplacement);
    for (; game_object->prev; game_object = game_object->prev);
    game_object = sort_game_object(game_object);
    for (; game_object; game_object = game_object->next) {
        if (game_object->tower == NO_TOWER)
            display_game_object(window, game_object);
        else
            display_towers(window, game_object);
    }
    if (objs->rocket)
        objs = display_rocket(window, objs);
    objs = destroy_enemy(objs);
    if (objs->tower_move)
        display_tower_move(window, objs->tower_move);
    display_heart(window, objs->heart, objs->life);
}

void display_button(sfRenderWindow *window, button_t *button)
{
    for (; button; button = button->next) {
        sfSprite_setPosition(button->sprite, button->pos);
        sfSprite_setTextureRect(button->sprite, button->rect);
        sfSprite_setTexture(button->sprite, button->texture, sfFalse);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    }
}

int display_scene_game(sfRenderWindow *window, scene_t **scene)
{
    scene_object_t *scene_object = (*scene)->objs;

    display_scene_object(window, (*scene)->objs);
    display_button(window, (*scene)->button);
    (*scene)->texts->nb_enemies->nb = (*scene)->objs->nb_character;
    if (display_texts(window, (*scene)->texts, scene_object->speed) == FAILURE)
        return (FAILURE);
    if ((*scene)->objs->life == 0) {
        (*scene) = (*scene)->next;
        return (SUCCESS);
    }
    if ((*scene)->objs->nb_character == 0) {
        if (((*scene)->texts->wave->nb++) == 15 || (*scene)->objs->life == 0) {
            (*scene) = (*scene)->next;
            return (SUCCESS);
        }
        if (!((*scene)->objs = re_init_enemy(scene_object)))
            return (FAILURE);
    }
    analyse_events(window, scene);
    return (SUCCESS);
}