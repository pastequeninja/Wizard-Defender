/*
** EPITECH PROJECT, 2019
** display
** File description:
** MY_DEFENDER
*/

#include "my_defender.h"

void draw_music_elements(sfRenderWindow *window, music_s_t *music)
{
    for (;music->prev != NULL; music = music->prev);
    sfRenderWindow_drawSprite(window, music->sprite_ast, NULL);
    sfRenderWindow_drawSprite(window, music->sprite_star, NULL);
    sfRenderWindow_drawSprite(window, music->next->sprite_ast, NULL);
    if (music->music_play == false || music->next->music_play == false) {
        sfRenderWindow_drawSprite(window, music->next->sprite_star, NULL);
    }
}

int display_settings(sfRenderWindow *window, scene_t **scene)
{
    sett_t *settings;

    for (;(*scene)->prev != NULL; (*scene) = (*scene)->prev);
    settings = (*scene)->setting;
    for (;settings->prev != NULL; settings = settings->prev);
    while (settings->type != MUSIC) {
        sfRenderWindow_drawSprite(window, settings->sprite, NULL);
        settings = settings->next;
    }
    event_settings(window, scene, settings->music);
    sfRenderWindow_drawText(window, settings->music->text, NULL);
    draw_music_elements(window, settings->music);
    return 0;
}
