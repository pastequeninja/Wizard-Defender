/*
** EPITECH PROJECT, 2019
** launch_game
** File description:
** defedner
*/

#include "my_defender.h"

scene_t *fill_all_scene(void)
{
    scene_t *scene = fill_scene();

    if (!scene)
        return (NULL);
    if (!(scene->next = malloc(sizeof(scene_t))))
        return (NULL);
    scene->next->prev = scene;
    scene = scene->next;
    if (!(scene = init_scene_game(scene)))
        return (NULL);
    if (!(scene = init_end(scene)))
        return (NULL);
    if (!(scene = init_game_sett(scene)))
        return (NULL);
    scene->next = NULL;
    for (; scene->prev; scene = scene->prev);
    return (scene);
}

int scene_managing(sfRenderWindow *window, scene_t **scene, sfClock *clock)
{
    if ((*scene)->type == RULES)
        return (display_rules(window, scene));
    if ((*scene)->type == INTRO)
        return (display_intro(window, scene, clock));
    if ((*scene)->type == MENU) {
        display_menu(window, scene, clock);
        return (SUCCESS);
    }
    if ((*scene)->type == GAME)
        return (display_scene_game(window, scene));
    if ((*scene)->type == SETTINGS)
        return (display_settings(window, scene));
    if ((*scene)->type == END)
        return (display_end(window, scene));
    if ((*scene)->type == SETT)
        return (display_game_sett(window, scene));
    return (SUCCESS);
}

int launch_game(void)
{
    sfRenderWindow *window = create_window(1920, 1020, 60);
    sfClock *clock = sfClock_create();
    scene_t *scene = fill_all_scene();

    if (!scene)
        return (FAILURE_EXIT);
    sfMusic_play(scene->menu_background->music);
    while (sfRenderWindow_isOpen(window)) {
        if (scene_managing(window, &scene, clock) == FAILURE)
            return (FAILURE_EXIT);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_close(window);
    return (SUCCESS_EXIT);
}
