/*
** EPITECH PROJECT, 2019
** setting
** File description:
** MY_DEFENDER
*/

#include "my_defender.h"

sett_t *set_position(sett_t *setting, const char *str, float a, float b)
{
    setting->texture = sfTexture_createFromFile(str, NULL);
    setting->pos.y = a;
    setting->pos.x = b;
    sfSprite_setTexture(setting->sprite, setting->texture, sfFalse);
    sfSprite_setPosition(setting->sprite, setting->pos);
    return (setting);
}

sett_t *fill_scene_setting(sett_t *setting, int i)
{
    setting->sprite = sfSprite_create();
    if (i == 0) {
        setting->type = BACKGROUND;
        setting = set_position(setting, "sprites/menu/fond.jpg", -190, 0);
    }
    if (i == 1) {
        setting->type = FILTER;
        setting = set_position(setting, "sprites/menu/fond_test.png", -20, 0);
    }
    if (i == 2) {
        setting->type = WINDOW;
        setting = set_position(setting, \
        "sprites/menu/setting_menu.png", 70, 360);
    }
    if (i == 3) {
        setting->type = MUSIC;
        setting->music = fill_musics();
    }
    return (setting);
}

sett_t *fill_settings(sett_t *setting)
{
    int i = 0;

    setting = malloc(sizeof(sett_t));
    if (setting == NULL)
        return NULL;
    setting->prev = NULL;
    while (i < 4) {
        setting = fill_scene_setting(setting, i);
        if (i == 3)
            break;
        i++;
        setting->next = malloc(sizeof(sett_t));
        setting->next->prev = setting;
        setting = setting->next;
    }
    setting->next = NULL;
    for (;setting->prev != NULL; setting = setting->prev);
    return (setting);
}
