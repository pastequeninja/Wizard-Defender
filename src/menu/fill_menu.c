/*
** EPITECH PROJECT, 2019
** MY_DEFENDER
** File description:
** fill all data on menu
*/

#include "my_defender.h"

menu_background_t *menu_animations(menu_background_t *menu)
{
    if ((menu = malloc(sizeof(menu_background_t))) == NULL)
        return NULL;
    if ((menu->wizards = malloc(sizeof(wizard_t))) == NULL)
        return NULL;
    if ((menu->button = malloc(sizeof(menu_button_t))) == NULL)
        return NULL;
    menu->wizards = fill_wizards(menu->wizards);
    menu->titles = fill_title(menu->titles);
    menu->button = fill_button(menu->button);
    menu->music = sfMusic_createFromFile("musics/menu.ogg");
    return (menu);
}

scene_t *fill_menu(scene_t *scene)
{
    scene->menu_background = menu_animations(scene->menu_background);
    if (scene == NULL)
        return NULL;
    scene->menu_background->texture = sfTexture_createFromFile(\
    "sprites/menu/fond.jpg", NULL);
    scene->menu_background->sprite = sfSprite_create();
    scene->menu_background->pos.x = 0;
    scene->menu_background->pos.y = -190;
    sfSprite_setPosition(scene->menu_background->sprite, \
    scene->menu_background->pos);
    sfSprite_setTexture(scene->menu_background->sprite, \
    scene->menu_background->texture, sfFalse);
    return (scene);
}

rules_t *fill_rules(rules_t *rules)
{
    if ((rules = malloc(sizeof(rules_t))) == NULL)
        return NULL;
    rules->texture = sfTexture_createFromFile(\
    "sprites/?/fond.png", NULL);
    rules->sprite = sfSprite_create();
    rules->pos.x = 0;
    rules->pos.y = -190;
    sfSprite_setPosition(rules->sprite, rules->pos);
    sfSprite_setTexture(rules->sprite, rules->texture, sfFalse);
    return (rules);
}

scene_t *fill_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->type = INTRO;
    scene->prev = NULL;
    scene = fill_menu(scene);
    scene->setting = fill_settings(scene->setting);
    scene->intro = fill_intro(scene->intro);
    scene->rules = fill_rules(scene->rules);
    scene->next = NULL;
    return (scene);
}
