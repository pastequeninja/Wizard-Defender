/*
** EPITECH PROJECT, 2019
** init gameobject
** File description:
** defender
*/

#include "my_defender.h"

background_t *init_background(struct background_s *background)
{
    if (!(background->texture = \
        sfTexture_createFromFile("sprites/game/game.jpg", NULL)))
        return (NULL);
    background->sprite = sfSprite_create();
    background->pos = init_vec2f(0, 0);
    return (background);
}

game_object_t *init_life(game_object_t *game_object)
{
    if (!(game_object->font = sfFont_createFromFile("fonts/font.ttf")))
        return (NULL);
    game_object->text = sfText_create();
    if (game_object->character == CHARACTER_3)
        game_object->life = 1200;
    else if (game_object->character == CHARACTER_2)
        game_object->life = 500;
    else if (game_object->character == CHARACTER_1)
        game_object->life = 170;
    game_object->color = sfRed;
    sfText_setFont(game_object->text, game_object->font);
    sfText_setColor(game_object->text, game_object->color);
    sfText_setCharacterSize(game_object->text, 15);
    return (game_object);
}

game_object_t *first_init_game_object(game_object_t *game_object)
{
    game_object = first_init_game_object_tr(game_object);
    game_object->speed_y = 0;
    game_object->display = true;
    game_object->clock = sfClock_create();
    game_object->tower = NO_TOWER;
    if (!(game_object->texture = \
        sfTexture_createFromFile("sprites/game/walk.png", NULL)))
        return (NULL);
    return (game_object);
}

game_object_t *fill_game_object(game_object_t *game_object, int nb, float f)
{
    float i = 52 / f;
    static float tmp = 0;
    static int a = 0;
    int pos = -(rand() % (nb * 66)) - 204;

    tmp += i;
    game_object->diff_for_direction = (tmp > 26) ? tmp - 26 : -tmp + 10;
    if (!(first_init_game_object(game_object)))
        return (NULL);
    game_object->sprite = sfSprite_create();
    game_object->pos = init_vec2f(pos, 100 + tmp);
    game_object->size = init_vec2f(104, 104);
    game_object = fill_game_object_tr(game_object);
    if (!(game_object = init_life(game_object)))
        return (NULL);
    if ((a++) == nb - 1) {
        tmp = 0;
        a = 0;
    }
    return (game_object);
}

game_object_t *init_game_object(game_object_t *game_object)
{
    game_object->prev = NULL;
    for (int i = 0; i < 3; i++) {
        game_object->pos_in_list = i;
        if (i % 9 == 0 && i != 0)
            game_object->character = CHARACTER_3;
        else if (i % 6 == 0 && i != 0)
            game_object->character = CHARACTER_2;
        else
            game_object->character = CHARACTER_1;
        if (!(game_object = fill_game_object(game_object, 3, 3)))
            return (NULL);
        if (i == 2)
            break;
        if (!(game_object->next = malloc(sizeof(game_object_t))))
            return (NULL);
        game_object->next->prev = game_object;
        game_object = game_object->next;
    }
    return (return_game_object(game_object));
}