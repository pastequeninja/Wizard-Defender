/*
** EPITECH PROJECT, 2019
** event_ends
** File description:
** my_defender
*/

#include "my_defender.h"

scene_t *events_end(sfRenderWindow *window, scene_t *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            scene = button_clicked_end(window, scene);
    }
    return (scene);
}