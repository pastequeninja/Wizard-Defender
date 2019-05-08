/*
** EPITECH PROJECT, 2019
** analyse_events
** File description:
** my_runner
*/

#include "my_defender.h"

void analyse_events(sfRenderWindow *window, scene_t **scene)
{
    sfEvent event;

    sfMusic_setLoop((*scene)->prev->menu_background->music, sfTrue);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            button_is_clicked(scene, event.mouseButton);
        if (event.type == sfEvtMouseButtonReleased)
            put_tower_or_not((*scene));
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            keyspace_is_pressed((*scene));
    }
}