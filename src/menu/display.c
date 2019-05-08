/*
** EPITECH PROJECT, 2019
** display all
** File description:
** My_defender
*/

#include "my_defender.h"

void display_wizards(sfRenderWindow *window, menu_background_t *menu, \
sfClock *clock, float v)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000) {
        menu->wizards->rect.left += 250;
        sfClock_restart(clock);
    }
    if (menu->wizards->rect.left >= 1980)
        menu->wizards->rect.left = 0;
    if (menu->wizards->pos.x >= 1900) {
        menu->wizards->pos.x = -90;
    }
    menu->wizards->pos.x += v;
    sfMusic_setLoop(menu->music, sfTrue);
    sfSprite_setPosition(menu->wizards->sprite, menu->wizards->pos);
    sfSprite_setTextureRect(menu->wizards->sprite, menu->wizards->rect);
    sfSprite_setTexture(menu->wizards->sprite, menu->wizards->texture, \
    sfFalse);
    sfRenderWindow_drawSprite(window, menu->wizards->sprite, NULL);
}

int display_rules(sfRenderWindow *window, scene_t **scene)
{
    sfEvent event;

    sfRenderWindow_drawSprite(window, (*scene)->rules->sprite, NULL);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.mouseButton.type == sfEvtMouseButtonPressed)
            (*scene)->type = MENU;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return SUCCESS;
}

void place_button(sfRenderWindow *window, menu_button_t *button)
{
    while (button != NULL) {
        sfSprite_setPosition(button->sprite, button->pos);
        sfSprite_setTexture(button->sprite, button->texture, sfFalse);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
        button = button->next;
    }
}

sfMusic *find_music_blow(menu_button_t *button)
{
    for (;button->prev != NULL; button = button->prev);
    for (;button->type != MENU_BUTTON_START; button = button->next);

    return (button->music);
}

void display_menu(sfRenderWindow *window, scene_t **scene, \
sfClock *clock)
{
    wizard_t *wizard = (*scene)->menu_background->wizards;
    title_t *title = (*scene)->menu_background->titles;
    int interrupt_menu = 0;

    for (;wizard->prev != NULL; wizard = wizard->prev);
    sfRenderWindow_drawSprite(window, (*scene)->menu_background->sprite, NULL);
    display_wizards(window, (*scene)->menu_background, clock, 5);
    sfRenderWindow_drawText(window, title->text, NULL);
    sfRenderWindow_drawText(window, title->next->text, NULL);
    place_button(window, (*scene)->menu_background->button);
    if ((*scene)->menu_background->button->blow == 2 || \
        (*scene)->menu_background->button->blow == 1) {
        sfMusic_play(find_music_blow((*scene)->menu_background->button));
        interrupt_menu = wizard_blow(scene, window, clock);
    } else
        change_play_button(window, (*scene)->menu_background->button, scene);
    if (interrupt_menu == BLOW) {
        (*scene)->menu_background->button->blow = 0;
        (*scene)->menu_background->button->pos = init_vec2f(800, 300);
        (*scene) = (*scene)->next;
    }
}
