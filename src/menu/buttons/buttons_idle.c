/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** idel button -> change
*/

#include "my_defender.h"

void pass_click_on_play(sfRenderWindow *window, menu_button_t *button, \
char *str)
{
    button->texture = sfTexture_createFromFile(str, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}

void change_idle_play_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window)
{
    for (;button->prev != NULL; button = button->prev);
    for (;button->type != MENU_BUTTON_START; button = button->next);
    if (mouse_pos.x >= 800 && mouse_pos.x <= 1150 && \
        mouse_pos.y >= 300 && mouse_pos.y <= 650)
        pass_click_on_play(window, button, "sprites/menu/play_idle.png");
    else
        pass_click_on_play(window, button, "sprites/menu/play.png");
}

void change_idle_help_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window)
{
    for (;button->prev != NULL; button = button->prev);
    for (;button->type != MENU_BUTTON_HELP; button = button->next);
    if (mouse_pos.x >= 20 && mouse_pos.x <= 70 &&    \
        mouse_pos.y >= 40 && mouse_pos.y <= 90)
        pass_click_on_play(window, button, "sprites/menu/help_2.png");
    else
        pass_click_on_play(window, button, "sprites/menu/help.png");
}

void change_idle_setting_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window)
{
    for (;button->prev != NULL; button = button->prev);
    for (;button->type != MENU_BUTTON_SETTING; button = button->next);
    if (mouse_pos.x >= 1806 && mouse_pos.x <= 1878 &&   \
        mouse_pos.y >= 50 && mouse_pos.y <= 110)
        pass_click_on_play(window, button, "sprites/menu/setting_2.png");
    else
        pass_click_on_play(window, button, "sprites/menu/setting.png");

}
