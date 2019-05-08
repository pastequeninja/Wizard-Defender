/*
** EPITECH PROJECT, 2019
** display_end
** File description:
** my_defender
*/

#include "my_defender.h"

void display_character(sfRenderWindow *window, game_object_t *ch)
{
    if (sfClock_getElapsedTime(ch->clock).microseconds > ch->time) {
        ch->rect.left += 512;
        sfClock_restart(ch->clock);
    }
    if (ch->rect.left == 4096)
        ch->rect.left = 0;
    sfSprite_setTexture(ch->sprite, ch->texture, sfFalse);
    sfSprite_setTextureRect(ch->sprite, ch->rect);
    sfSprite_setPosition(ch->sprite, ch->pos);
    sfRenderWindow_drawSprite(window, ch->sprite, NULL);
}

void display_board(sfRenderWindow *window, game_object_t *ob)
{
    sfSprite_setTexture(ob->sprite, ob->texture, sfFalse);
    sfSprite_setTextureRect(ob->sprite, ob->rect);
    sfSprite_setPosition(ob->sprite, ob->pos);
    sfRenderWindow_drawSprite(window, ob->sprite, NULL);
}

void display_button_end(sfRenderWindow *window, button_t *button)
{
    for (; button; button = button->next) {
        sfSprite_setTexture(button->sprite, button->texture, sfFalse);
        sfSprite_setTextureRect(button->sprite, button->rect);
        sfSprite_setPosition(button->sprite, button->pos);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    }
}

void display_medal(sfRenderWindow *window, game_object_t *obj, int wave)
{
    for (; obj->next; obj = obj->next);
    if (wave >= 15)
        obj->rect = init_intrect(0, 0, 400 / 3, 246);
    if (wave < 15 && wave >= 10)
        obj->rect = init_intrect(400 / 3, 0, 400 / 3, 246);
    if (wave < 10 && wave >= 5)
        obj->rect = init_intrect(400 / 3 * 2, 0, 400 / 3, 246);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

int display_end(sfRenderWindow *window, scene_t **scene)
{
    if (display_background_end(window, (*scene)->prev) == FAILURE)
        return (FAILURE);
    display_board(window, (*scene)->objs->game_object);
    display_character(window, (*scene)->objs->game_object->next);
    display_button_end(window, (*scene)->button);
    if ((*scene)->prev->texts->wave->nb == 16)
	(*scene)->prev->texts->wave->nb = 15;
    if ((*scene)->prev->texts->wave->nb >= 5)
        display_medal(window, (*scene)->objs->game_object, \
        (*scene)->prev->texts->wave->nb);
    display_text_end(window, (*scene)->texts->wave, \
    (*scene)->prev->texts->wave->nb);
    (*scene) = events_end(window, (*scene));
    return (SUCCESS);
}
