/*
** EPITECH PROJECT, 2019
** acces to my elements
** File description:
** My_defender
*/

#include "my_defender.h"

intro_t *access_bubble(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != BUBLE; intro = intro->next);
    return (intro);
}

intro_t *access_bombs(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != EXPLOSION; intro = intro->next);
    return (intro);
}

intro_t *access_green_wizard(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != WIZARD1; intro = intro->next);
    return (intro);
}

intro_t *access_background(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != BACK; intro = intro->next);
    return (intro);
}

intro_t *access_space_event(intro_t *intro)
{
    for (; intro->prev != NULL; intro = intro->prev);
    for (; intro->type != SPACE; intro = intro->next);
    return (intro);
}
