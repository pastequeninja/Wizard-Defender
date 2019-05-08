/*
** EPITECH PROJECT, 2019
** proto_game
** File description:
** my_defender
*/

#ifndef PROTOS_GAME_H
#define PROTOS_GAME_H

#include "my_defender.h"

// GLOBAL FUNCTIONS //

sfRenderWindow *create_window(unsigned int width, unsigned int height,
unsigned int fps);
int launch_game(void);
sfVector2f init_vec2f(float x, float y);
sfIntRect init_intrect(int left, int top, int width, int height);

// INITALIZATION SCENE_T //

scene_t *init_scene_game(scene_t *);
background_t *init_background(background_t *);
game_object_t *init_game_object(game_object_t *);
game_object_t *sort_game_object(game_object_t *);
button_t *init_button_playpause(button_t *);
button_t *init_button_setting(button_t *);
text_t *init_texts(text_t *texts);
button_t *init_button_tower(button_t *);
sfColor init_color(int r, int g, int b, int a);
music_t *init_music(music_t *);
emplacement_t *init_emplacement(emplacement_t *);
scene_t *init_rocket(scene_t *);
game_object_t *fill_game_object(game_object_t *, int, float);
scene_object_t *re_init_enemy(scene_object_t *);
button_t *init_fungus(button_t *);
heart_t *init_heart(void);
scene_t *init_end(scene_t *);
scene_object_t *init_end_obj(void);
button_t *init_end_button(void);
scene_t *re_init_new_game(scene_t *);
game_object_t *return_game_object(game_object_t *);
game_object_t *fill_game_object_tr(game_object_t *);
game_object_t *first_init_game_object_tr(game_object_t *);
scene_t *init_game_sett(scene_t *);
button_t *init_button_game_sett(void);

// DISPLAY SCENE_T //

int display_scene_game(sfRenderWindow *, scene_t **);
void display_game_object(sfRenderWindow *, game_object_t *);
void display_background(sfRenderWindow *, background_t *);
void display_towers(sfRenderWindow *, game_object_t *);
void display_emplacement(sfRenderWindow *, scene_object_t *);
scene_object_t *display_rocket(sfRenderWindow *, scene_object_t *);
int display_texts(sfRenderWindow *, text_t *, float);
void continue_to_display(sfRenderWindow *, rocket_t *);
void display_heart(sfRenderWindow *, heart_t *, int);
void change_scene_for_end(scene_t *);
int display_end(sfRenderWindow *, scene_t **);
int display_background_end(sfRenderWindow *, scene_t *);
void display_scene_object_for_end(sfRenderWindow *, scene_object_t *);
void display_button(sfRenderWindow *, button_t *);
int display_game_sett(sfRenderWindow *, scene_t **);
void display_text_end(sfRenderWindow *, wave_t *, int);

// MOVE GAME_OBJECT //

void move_character(game_object_t *);
void first_walk(game_object_t *, int, int);

// EVENT AND BUTTON_T //

void button_is_clicked(scene_t **, sfMouseButtonEvent);
scene_t *change_button_play(scene_t *);
void keyspace_is_pressed(scene_t *);
scene_t *next_scene(scene_t *);
void analyse_events(sfRenderWindow *, scene_t **);
scene_t *move_temporary_sprite(scene_t *);
void put_tower_or_not(scene_t *);
scene_t *button_tower_press(scene_t *);
void display_tower_move(sfRenderWindow *, tower_move_t *);
int check_if_touch_the_tower(game_object_t *, tower_move_t *);
scene_t *change_speed(scene_t *);
int tower_touch_smth(scene_t *, tower_move_t *);
scene_t *events_end(sfRenderWindow *, scene_t *);
scene_t *retry_game(scene_t *);
scene_t *return_to_home(scene_t *);
scene_t *button_clicked_end(sfRenderWindow *, scene_t *);
int check_if_clicked(button_t *, sfVector2f);
scene_t *return_the_game(scene_t *);
scene_t *retry_game_sett(scene_t *);
scene_t *return_to_the_menu(scene_t *);
void events_game_sett(sfRenderWindow *, scene_t **);

// DESTROY ALL //

game_object_t *delete_enemy(game_object_t *);
scene_object_t *destroy_enemy(scene_object_t *);
void destroy_for_new_game(scene_t *);

#endif