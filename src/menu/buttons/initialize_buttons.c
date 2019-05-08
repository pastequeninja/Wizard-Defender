/*
** EPITECH PROJECT, 2019
** initialize buttons
** File description:
** My_defender
*/

#include "my_defender.h"

menu_button_t *buttons_data(menu_button_t *button, char *str, float a, float b)
{
    button->texture = sfTexture_createFromFile(str, NULL);
    button->pos.y = a;
    button->pos.x = b;
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    return (button);
}

menu_button_t *logo_buttons(menu_button_t *button, int i)
{
    button->sprite = sfSprite_create();
    if (i == 0) {
        button->type = MENU_BUTTON_START;
        button->music = sfMusic_createFromFile("musics/blow.ogg");
        button = buttons_data(button, "sprites/menu/play.png", 300, 800);
    }
    if (i == 1) {
        button->type = MENU_BUTTON_SETTING;
        button = buttons_data(button, "sprites/menu/setting.png", 50, 1800);
    }
    if (i == 2) {
        button->type = MENU_BUTTON_EXIT;
        button = buttons_data(button, "sprites/menu/exit.png", 135, 1806);
    }
    if (i == 3) {
        button->type = MENU_BUTTON_HELP;
        button = buttons_data(button, "sprites/menu/help.png", 40, 20);
    }
    return (button);
}

menu_button_t *fill_button(menu_button_t *button)
{
    int i = 0;

    button->prev = NULL;
    while (i < 4) {
        button = logo_buttons(button, i);
        button->blow = 0;
        if (i == 3)
            break;
        i++;
        button->next = malloc(sizeof(menu_button_t));
        button->next->prev = button;
        button = button->next;
    }
    button->next = NULL;
    for (;button->prev != NULL; button = button->prev);
    return (button);
}
