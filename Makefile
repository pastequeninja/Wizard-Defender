##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my defender
##

NAME	=	my_defender

SRC	=	src

MENU	=	src/menu

GAME	=	src/game

GAME_INIT	=	src/game/init

GAME_DISPLAY	=	src/game/display

GAME_EVENTS	=	src/game/events

GAME_DESTROY	=	src/game/destroy

MENU_BUTTONS	=	src/menu/buttons

MENU_TITLES	=	src/menu/titles

MENU_WIZARDS	=	src/menu/wizards

SETTINGS	=	src/settings

SETTINGS_INIT	=	src/settings/init

END_INIT	=	src/end_game/init

END_DISPLAY	=	src/end_game/display

END_EVENTS	=	src/end_game/events

END_DESTROY	=	src/end_game/destroy

INTRO		=	src/intro

INTRO_INIT	=	src/intro/init

SRCS	=	$(SRC)/create_window.c				\
		$(SRC)/launch_game.c				\
		$(MENU)/display.c				\
		$(MENU)/fill_menu.c				\
		$(SETTINGS)/draw.c				\
		$(SETTINGS)/events_music.c			\
		$(SETTINGS_INIT)/init_data.c			\
		$(SETTINGS_INIT)/init_settings.c		\
		$(INTRO)/wizard.c				\
		$(INTRO)/bombs.c				\
		$(INTRO)/access/access_ll.c			\
		$(INTRO)/display.c				\
		$(INTRO_INIT)/fill_intro_data.c			\
		$(INTRO_INIT)/fill_data.c			\
		$(MENU_BUTTONS)/event_buttons.c			\
		$(MENU_BUTTONS)/initialize_buttons.c		\
		$(MENU_BUTTONS)/exit_buttons.c			\
		$(MENU_BUTTONS)/buttons_idle.c			\
		$(MENU_TITLES)/title_data.c			\
		$(MENU_WIZARDS)/initialize_wizards.c		\
		$(GAME_DESTROY)/destroy_an_enemy.c		\
		$(GAME_DISPLAY)/change_direction_character.c	\
		$(GAME_DISPLAY)/display_emplacement.c		\
		$(GAME_DISPLAY)/display_game_object.c		\
		$(GAME_DISPLAY)/display_rocket.c		\
		$(GAME_DISPLAY)/display_scene_game.c		\
		$(GAME_DISPLAY)/display_texts.c			\
		$(GAME_DISPLAY)/display_towers.c		\
		$(GAME_DISPLAY)/move_game_object.c		\
		$(GAME_DISPLAY)/sort_walk.c			\
		$(GAME_DISPLAY)/trajectory_shoot.c		\
		$(GAME_DISPLAY)/display_heart.c			\
		$(GAME_DISPLAY)/display_game_sett.c		\
		$(GAME_EVENTS)/analyse_events.c			\
		$(GAME_EVENTS)/button_is_clicked.c		\
		$(GAME_EVENTS)/button_tower_press.c		\
		$(GAME_EVENTS)/function_callback.c		\
		$(GAME_EVENTS)/keyboard_is_pressed.c		\
		$(GAME_EVENTS)/put_tower_or_not.c		\
		$(GAME_EVENTS)/touch_other_tower.c		\
		$(GAME_EVENTS)/change_speed.c			\
		$(GAME_EVENTS)/function_callback_sett.c		\
		$(GAME_EVENTS)/events_game_sett.c		\
		$(GAME_INIT)/init_button_game.c			\
		$(GAME_INIT)/init_button_tower.c		\
		$(GAME_INIT)/init_color.c			\
		$(GAME_INIT)/init_emplacement.c			\
		$(GAME_INIT)/init_game_object.c			\
		$(GAME_INIT)/init_music.c			\
		$(GAME_INIT)/init_rocket.c			\
		$(GAME_INIT)/init_scene_game.c			\
		$(GAME_INIT)/init_texts.c			\
		$(GAME_INIT)/init_vec2f.c			\
		$(GAME_INIT)/re_init_scene_object.c		\
		$(GAME_INIT)/init_button_fungus.c		\
		$(GAME_INIT)/init_heart.c			\
		$(GAME_INIT)/init_game_object_trash.c		\
		$(GAME_INIT)/init_button_game_sett.c		\
		$(GAME_INIT)/init_game_sett.c			\
		$(END_INIT)/init_end_obj.c			\
		$(END_INIT)/init_end.c				\
		$(END_INIT)/init_end_button.c			\
		$(END_DISPLAY)/display_end.c			\
		$(END_DISPLAY)/display_background_end.c		\
		$(END_DISPLAY)/display_scene_object_for_end.c	\
		$(END_DISPLAY)/display_text_end.c		\
		$(END_EVENTS)/events_end.c			\
		$(END_EVENTS)/events_button_home.c		\
		$(END_EVENTS)/events_button_retry.c		\
		$(END_EVENTS)/button_clicked_end.c		\
		$(END_DESTROY)/destroy_for_new_game.c		\
		$(END_INIT)/re_init_new_game.c			\
		$(SRC)/main.c

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib/my

MY	=	-lmy

CFLAGS	=	-I./include -W -Wall -Wextra

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C lib/my --no-print-directory
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)

clean:
	$(MAKE) clean -C lib/my --no-print-directory
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C lib/my --no-print-directory
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -O0

debug: re
