/*
** EPITECH PROJECT, 2019
** eve
** File description:
** my_defendr
*/

#include "my_defender.h"

void check_button_sett(sfRenderWindow *window, scene_t **scene)
{
    button_t *button = (*scene)->button;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = init_vec2f(tmp.x, tmp.y);

    if (tmp.x > 1300 && tmp.x < 1360 && tmp.y > 350 && tmp.y < 410) {
        sfRenderWindow_close(window);
        return;
    }
    for (; button; button = button->next) {
        if (check_if_clicked(button, pos) == SUCCESS)
            (*scene) = button->callback((*scene));
    }
}

void events_game_sett(sfRenderWindow *window, scene_t **scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            check_button_sett(window, scene);
    }
}