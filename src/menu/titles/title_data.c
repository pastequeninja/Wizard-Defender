/*
** EPITECH PROJECT, 2019
** title data
** File description:
** My_defender
*/

#include "my_defender.h"

void set_title(title_t *title, char *str, unsigned int x)
{
    sfText_setString(title->text, str);
    sfText_setFont(title->text, title->font);
    sfText_setCharacterSize(title->text, x);
    sfText_setPosition(title->text, title->pos);
}

title_t *fill_title_data(title_t *title, char *str)
{
    if ((title = malloc(sizeof(title_t))) == NULL)
        return NULL;
    title->font = sfFont_createFromFile(str);
    title->text = sfText_create();
    if (my_strcmp(str, "fonts/2.ttf") == 0) {
        title->pos.x = 420;
        title->pos.y = 800;
        set_title(title, "DEFENDER", 100);
    }
    else {
        title->pos.x = 575;
        title->pos.y = 90;
        set_title(title, "WIZARD", 120);
    }
    return (title);
}

title_t *fill_title(title_t *title)
{
    title = fill_title_data(title, "fonts/2.ttf");
    title->prev = NULL;
    title->next = fill_title_data(title->next, "fonts/1.ttf");
    title->next->prev = title;
    title->next->next = NULL;
    return (title);
}
