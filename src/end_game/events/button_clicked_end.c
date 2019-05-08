/*
** EPITECH PROJECT, 2019
** button_clicke_end
** File description:
** my_defendefr
*/

#include "my_defender.h"

scene_t *button_clicked_end(sfRenderWindow *window, scene_t *scene)
{
    button_t *button = scene->button;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = init_vec2f(tmp.x, tmp.y);

    for (; button; button = button->next) {
        if (check_if_clicked(button, pos) == SUCCESS)
            scene = button->callback(scene);
    }
    return (scene);
}