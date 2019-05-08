/*
** EPITECH PROJECT, 2018
** create window
** File description:
** bootstrap
*/

#include "my_defender.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height,
unsigned int fps)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "My defender",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return (window);
}
