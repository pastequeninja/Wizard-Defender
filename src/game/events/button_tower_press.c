/*
** EPITECH PROJECT, 2019
** utton_tower_pres
** File description:
** my_defender
*/

#include "my_defender.h"

tower_move_t *init_texture_for_tower_move_next(button_t *button,
tower_move_t *tower)
{
    if (button->type == BUTTON_TOWER_THREE) {
        if (!(tower->texture = \
            sfTexture_createFromFile("sprites/game/tow_3.png", NULL)))
            return (NULL);
        tower->type = TOWER_THREE;
        tower->price = 60;
    }
    if (button->type == BUTTON_TOWER_FOUR) {
        if (!(tower->texture = \
            sfTexture_createFromFile("sprites/game/tow_4.png", NULL)))
            return (NULL);
        tower->type = TOWER_FOUR;
        tower->price = 100;
    }
    return (tower);
}

tower_move_t *init_texture_for_tower_move(button_t *button,
tower_move_t *tower)
{
    if (button->type == BUTTON_TOWER_ONE) {
        if (!(tower->texture = \
            sfTexture_createFromFile("sprites/game/tow_1.png", NULL)))
            return (NULL);
        tower->type = TOWER_ONE;
        tower->price = 20;
    }
    if (button->type == BUTTON_TOWER_TWO) {
        if (!(tower->texture = \
            sfTexture_createFromFile("sprites/game/tow_2.png", NULL)))
            return (NULL);
        tower->type = TOWER_TWO;
        tower->price = 40;
    }
    return (init_texture_for_tower_move_next(button, tower));
}

scene_t *button_tower_press(scene_t *scene)
{
    button_t *button = scene->button;
    tower_move_t *tower_move = scene->objs->tower_move;

    for (; button->activate == false; button = button->next);
    if (!(tower_move = malloc(sizeof(tower_move_t))))
        return (NULL);
    if (!(tower_move = init_texture_for_tower_move(button, tower_move)))
        return (NULL);
    tower_move->sprite = sfSprite_create();
    tower_move->size = init_vec2f(button->size.x, button->size.y);
    tower_move->rect = init_intrect(0, 0, button->size.x, button->size.y);
    tower_move->color = init_color(100, 100, 100, 100);
    tower_move->circle = sfCircleShape_create();
    tower_move->pos = init_vec2f(-500, 0);
    if (!(tower_move->music = sfMusic_createFromFile("musics/money.ogg")))
        return (NULL);
    sfCircleShape_setRadius(tower_move->circle, 200);
    sfCircleShape_setFillColor(tower_move->circle, tower_move->color);
    scene->objs->tower_move = tower_move;
    return (scene);
}