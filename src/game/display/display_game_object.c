/*
** EPITECH PROJECT, 2019
** display_scene_object
** File description:
** my_defender
*/

#include "my_defender.h"

void display_tower_move(sfRenderWindow *window, tower_move_t *tower_move)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = init_vec2f(tmp.x - 200, tmp.y - 200);

    tower_move->pos = init_vec2f(tmp.x - tower_move->size.x / 2,
    tmp.y - tower_move->size.y / 2);
    sfCircleShape_setPosition(tower_move->circle, pos);
    sfSprite_setPosition(tower_move->sprite, tower_move->pos);
    sfSprite_setTextureRect(tower_move->sprite, tower_move->rect);
    sfSprite_setTexture(tower_move->sprite, tower_move->texture, sfFalse);
    sfRenderWindow_drawCircleShape(window, tower_move->circle, NULL);
    sfRenderWindow_drawSprite(window, tower_move->sprite, NULL);
}

void display_background(sfRenderWindow *window, background_t *background)
{
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}

void display_game_object(sfRenderWindow *window, game_object_t *game_object)
{
    if (game_object->display == true)
        move_character(game_object);
    game_object->pos_life = init_vec2f(game_object->pos.x + 47,
    game_object->pos.y + 10);
    sfText_setString(game_object->text, nbr_to_str(game_object->life));
    sfText_setPosition(game_object->text, game_object->pos_life);
    sfRenderWindow_drawText(window, game_object->text, NULL);
    sfSprite_setPosition(game_object->sprite, game_object->pos);
    sfSprite_setTextureRect(game_object->sprite, game_object->rect);
    sfSprite_setTexture(game_object->sprite, game_object->texture, sfFalse);
    sfRenderWindow_drawSprite(window, game_object->sprite, NULL);
}