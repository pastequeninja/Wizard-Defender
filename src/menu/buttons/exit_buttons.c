/*
** EPITECH PROJECT, 2019
** exit buttons
** File description:
** my_defender
*/

#include "my_defender.h"

void mouse_pass_on_exit(sfRenderWindow *window, menu_button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    for (; button->type != MENU_BUTTON_EXIT; button = button->next);
    if (mouse_pos.x >= 1806 && mouse_pos.x <= 1878 && \
        mouse_pos.y >= 135 && mouse_pos.y <= 205) {
        button->texture = \
        sfTexture_createFromFile("sprites/menu/exit_2.png", NULL);
    } else
        button->texture = \
        sfTexture_createFromFile("sprites/menu/exit.png", NULL);
}
