/*
** EPITECH PROJECT, 2019
** events music
** File description:
** MY_DEFENDER
*/

#include "my_defender.h"

void change_volume(music_s_t *music, \
sfVector2i mouse_pos, sfRenderWindow *window)
{
    music->pos_star.x = mouse_pos.x;
    if (music->pos_star.x <= 730)
        music->pos_star.x = 730;
    if (music->pos_star.x >= 830)
        music->pos_star.x = 830;
    sfSprite_setPosition(music->sprite_star, music->pos_star);
    sfSprite_setTexture(music->sprite_star, music->texture_star, sfFalse);
    sfRenderWindow_drawSprite(window, music->sprite_star, NULL);
}

void cut_music(sfRenderWindow *window, scene_t **scene, \
music_s_t *music, sfEvent event)
{
    int change_sprite = 0;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (event.mouseButton.type == sfEvtMouseButtonPressed && \
        (mouse_pos.x >= 1120 && mouse_pos.x <= 1300) && \
        (mouse_pos.y >= 430 && mouse_pos.y <= 600) && \
        music->music_play == false) {
        sfMusic_play((*scene)->menu_background->music);
        music->music_play = true;
        change_sprite = 1;
    }
    if (event.mouseButton.type == sfEvtMouseButtonPressed && \
        (mouse_pos.x >= 1120 && mouse_pos.x <= 1300) && (mouse_pos.y >= 430 && \
        mouse_pos.y <= 600) && change_sprite != 1) {
        sfMusic_pause((*scene)->menu_background->music);
        music->music_play = false;
    }
}

void event_settings(sfRenderWindow *window, scene_t **scene, music_s_t *music)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.mouseButton.type == sfEvtMouseButtonPressed && \
            (mouse_pos.x <= 120 || mouse_pos.x > 1700) && \
            (*scene)->type == SETTINGS)
            (*scene)->type = MENU;
        cut_music(window, scene, music, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (mouse_pos.x >= music->pos_star.x + 20 && \
            mouse_pos.x <= music->pos_star.x + 100 && \
            mouse_pos.y >= music->pos_star.y + 20 && \
            mouse_pos.y <= music->pos_star.y + 100 && \
            event.mouseButton.type == sfEvtMouseButtonPressed) {
            change_volume(music, mouse_pos, window);
        }
    }
}
