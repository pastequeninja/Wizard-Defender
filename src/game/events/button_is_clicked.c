/*
** EPITECH PROJECT, 2019
** button_is_clicked
** File description:
** defedner
*/

#include "my_defender.h"

int check_if_clicked(button_t *button, sfVector2f tmp)
{
    if (tmp.x > button->pos.x && tmp.x < button->pos.x + button->size.x) {
        if (tmp.y > button->pos.y && tmp.y < button->pos.y + button->size.y)
            return (SUCCESS);
    }
    return (FAILURE);
}

void button_is_clicked(scene_t **scene, sfMouseButtonEvent mouse)
{
    int check = -1;
    button_t *button = (*scene)->button;
    tower_move_t *tower_move = (*scene)->objs->tower_move;
    sfVector2f click = init_vec2f(mouse.x, mouse.y);

    if (tower_move)
        (*scene)->objs->tower_move->pos = init_vec2f(mouse.x, mouse.y);
    for (; button; button = button->next) {
        check = check_if_clicked(button, click);
        if (check == SUCCESS && !tower_move) {
            button->activate = true;
            (*scene) = button->callback((*scene));
            button->activate = false;
            return;
        }
    }
}