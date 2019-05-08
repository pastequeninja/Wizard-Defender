/*
** EPITECH PROJECT, 2019
** init_texts
** File description:
** my_defender
*/

#include "my_defender.h"

money_t *init_money(void)
{
    money_t *money = malloc(sizeof(money_t));

    if (!money)
        return (NULL);
    money->display = true;
    money->nb = 10;
    if (!(money->font = sfFont_createFromFile("fonts/k.otf")))
        return (NULL);
    if (!(money->text = sfText_create()))
        return (NULL);
    money->pos = init_vec2f(1750, 520);
    money->color = init_color(255, 200, 100, 255);
    sfText_setFont(money->text, money->font);
    sfText_setCharacterSize(money->text, 65);
    sfText_setPosition(money->text, money->pos);
    return (money);
}

wave_t *init_wave(void)
{
    wave_t *wave = malloc(sizeof(wave_t));

    if (!wave)
        return (NULL);
    wave->nb = 1;
    if (!(wave->str = my_strdup("Wave ")))
        return (NULL);
    if (!(wave->font = sfFont_createFromFile("fonts/AlphaRope.ttf")))
        return (NULL);
    if (!(wave->text = sfText_create()))
        return (NULL);
    wave->pos = init_vec2f(1680, 220);
    wave->color = init_color(255, 255, 255, 255);
    sfText_setFont(wave->text, wave->font);
    sfText_setCharacterSize(wave->text, 45);
    sfText_setPosition(wave->text, wave->pos);
    return (wave);
}

nb_enemies_t *init_nb_enemies(void)
{
    nb_enemies_t *nb_enemies = malloc(sizeof(nb_enemies_t));

    if (!nb_enemies)
        return (NULL);
    nb_enemies->nb = 3;
    return (nb_enemies);
}

text_t *init_texts(text_t *texts)
{
    if (!(texts->money = init_money()))
        return (NULL);
    if (!(texts->wave = init_wave()))
        return (NULL);
    if (!(texts->nb_enemies = init_nb_enemies()))
        return (NULL);
    return (texts);
}