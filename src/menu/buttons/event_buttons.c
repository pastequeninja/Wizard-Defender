/*
** EPITECH PROJECT, 2019
** event button
** File description:
** My_defender
*/

#include "my_defender.h"

menu_button_t *fill_wizard_blow(menu_button_t *button)
{
    for (;button->prev != NULL; button = button->prev);
    for (;button->type != MENU_BUTTON_START; button = button->next);
    button->texture = sfTexture_createFromFile("sprites/menu/hey.png", NULL);
    button->rect.top = 0;
    button->rect.left = 0;
    button->rect.width = 512;
    button->rect.height = 512;
    button->pos.y = 250;
    button->pos.x = 700;
    button->sprite = sfSprite_create();
    return (button);
}

int wizard_blow(scene_t **scene, sfRenderWindow *window, sfClock *clock)
{
    menu_button_t *button = (*scene)->menu_background->button;

    if (button->blow == 2) {
        button->blow = 1;
        button = fill_wizard_blow(button);
    }
    if (sfClock_getElapsedTime(clock).microseconds > 82000) {
        button->pos.x -= 10;
        button->rect.left += 500;
        sfClock_restart(clock);
    }
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    if (button->rect.left >= 4000)
        return (BLOW);
    return (NOT_FINISH);
}

void change_scene(scene_t **scene, sfEvent event, sfVector2i mouse_pos)
{
    if (event.mouseButton.type == sfEvtMouseButtonPressed &&            \
        mouse_pos.x >= 1806 && mouse_pos.x <= 1878 &&                   \
        mouse_pos.y >= 50 && mouse_pos.y <= 110 && (*scene)->type == MENU)
        (*scene)->type = SETTINGS;
    if (event.mouseButton.type == sfEvtMouseButtonPressed &&            \
        mouse_pos.x >= 20 && mouse_pos.x <= 70 &&                       \
        mouse_pos.y >= 40 && mouse_pos.y <= 90)
        (*scene)->type = RULES;
}

void event_pressed(sfRenderWindow *window, \
menu_button_t *button, scene_t **scene)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.mouseButton.type == sfEvtMouseButtonPressed &&        \
            mouse_pos.x >= 800 && mouse_pos.x <= 1150 &&                \
            mouse_pos.y >= 300 && mouse_pos.y <= 650)
            button->blow = 2;
        if (mouse_pos.x >= 1806 && mouse_pos.x <= 1878 &&               \
            mouse_pos.y >= 135 && mouse_pos.y <= 205 &&                 \
            event.mouseButton.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(window);
        change_scene(scene, event, mouse_pos);
        mouse_pass_on_exit(window, button);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void change_play_button(sfRenderWindow *window, menu_button_t *button,
scene_t **scene)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    change_idle_play_button(mouse_pos, button, window);
    change_idle_help_button(mouse_pos, button, window);
    change_idle_setting_button(mouse_pos, button, window);
    event_pressed(window, button, scene);
}
