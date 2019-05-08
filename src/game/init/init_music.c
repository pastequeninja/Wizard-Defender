/*
** EPITECH PROJECT, 2019
** init_musci
** File description:
** my_defender
*/

#include "my_defender.h"

music_t *init_music(music_t *music)
{
    if (!(music = malloc(sizeof(music_t))))
        return (NULL);
    if (!(music->music_money = sfMusic_createFromFile("musics/money.ogg")))
        return (NULL);
    return (music);
}