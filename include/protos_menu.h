/*
** EPITECH PROJECT, 2019
** protomenu
** File description:
** my_defender
*/

#ifndef PROTOS_MENU_H
#define PROTOS_MENU_H

#include "my_defender.h"

int display_rules(sfRenderWindow *window, scene_t **scene);
void change_idle_setting_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window);
void change_idle_help_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window);
void pass_click_on_play(sfRenderWindow *window, menu_button_t *button, \
char *str);
void change_idle_play_button(sfVector2i mouse_pos, \
menu_button_t *button, sfRenderWindow *window);
intro_t *access_bubble(intro_t *intro);
intro_t *access_bombs(intro_t *intro);
intro_t *access_green_wizard(intro_t *intro);
intro_t *access_background(intro_t *intro);
intro_t *access_space_event(intro_t *intro);
void draw_space_event(sfRenderWindow *window, intro_t *intro, sfClock *clock);
void events_spaces(sfRenderWindow *window, scene_t **scene);
int display_intro(sfRenderWindow *window, scene_t **scene, sfClock *clock);
intro_text_t *fill_space_event(intro_text_t *space);
intro_text_t *fill_bubble_event(intro_text_t *bubble);
intro_text_t *fill_smoke(intro_text_t *smoke);
intro_text_t *fill_bombs(intro_text_t *bomb);
void set_display(sfSprite *sprite, sfTexture *texture, \
sfRenderWindow *window, sfVector2f pos);
void bombs_falls(intro_t *intro, sfRenderWindow *window);
music_s_t *initialize_tittle_music(music_s_t *music);
music_s_t *initialize_sprites_music(music_s_t *music);
music_s_t *initialize_sprite_cut_music(music_s_t *music);
music_s_t *fill_musics(void);
void event_settings(sfRenderWindow *window, scene_t **scene, music_s_t *music);
void cut_music(sfRenderWindow *window, scene_t **scene, \
music_s_t *music, sfEvent event);
void change_volume(music_s_t *music, \
sfVector2i mouse_pos, sfRenderWindow *window);
intro_t *set_intro_position(intro_t *intro, const char *str, float a, float b);
intro_t *fill_intro_data1(intro_t *intro, int i);
intro_t *fill_intro_data2(intro_t *intro, int i);
intro_t *fill_intro_data(intro_t *intro, int i);
intro_t *fill_intro(intro_t *intro);
intro_t *access_green_wizard(intro_t *intro);
void display_normal_wizards(intro_t *intro, sfRenderWindow *window);
void display_intro_wizards(intro_t *intro, sfRenderWindow *window);
int display_intro(sfRenderWindow *window, scene_t **scene, sfClock *clock);
sett_t *fill_settings(sett_t *);
sett_t *fill_scene_setting(sett_t *setting, int i);
sett_t *set_position(sett_t *setting, const char *str, float a, float b);
void draw_background(sfRenderWindow *window, sett_t *settings);
void draw_background(sfRenderWindow *window, sett_t *settings);
int display_settings(sfRenderWindow *window, scene_t **scene);
sfRenderWindow *create_window(unsigned int, unsigned int, unsigned int);
int start_game(scene_t *scene);
int launch_game(void);
void display_wizards(sfRenderWindow *, menu_background_t *, sfClock *, float);
void place_button(sfRenderWindow *window, menu_button_t *button);
void display_menu(sfRenderWindow *window, scene_t **scene, \
sfClock *clock);
wizard_t *fill_wizards_data(wizard_t *wizard, char *str, int x, int y);
wizard_t *fill_wizards(wizard_t *wizards);
void exit_game(sfRenderWindow *window, sfEvent event, menu_button_t *button);
void mouse_pass_on_exit(sfRenderWindow *window, menu_button_t *button);
void pass_click_on_play(sfRenderWindow *window, menu_button_t *button, \
char *str);
menu_button_t *fill_wizard_blow(menu_button_t *button);
int wizard_blow(scene_t **scene, sfRenderWindow *window, sfClock *clock);
void change_play_button(sfRenderWindow *, menu_button_t *, scene_t **);
menu_button_t *buttons_data(menu_button_t *button, char *str, float a, float);
menu_button_t *logo_buttons(menu_button_t *button, int i);
menu_button_t *fill_button(menu_button_t *button);
void set_title(title_t *title, char *str, unsigned int x);
title_t *fill_title_data(title_t *title, char *str);
title_t *fill_title(title_t *title);
scene_t *fill_scene(void);
scene_t *fill_menu(scene_t *scene);
menu_background_t *menu_animations(menu_background_t *menu);

#endif
