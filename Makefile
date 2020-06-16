##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN				=	src/main.c										\
						src/my_defender.c								\
						src/cursor.c									\
						src/config_all_scenes.c							\
						src/set_text_origin.c							\
						src/vector.c

MENU				=	src/menu/init.c									\
						src/menu/loop.c									\
						src/menu/help.c

GAMEPLAY			=	src/gameplay/init.c								\
						src/gameplay/loop.c								\
						src/gameplay/event.c							\
						src/gameplay/options.c							\
						src/gameplay/draw_options.c						\
						src/gameplay/config.c							\
						src/gameplay/level_setup.c						\
						src/gameplay/pause_functions/music_volume.c		\
						src/gameplay/pause_functions/sound_volume.c		\
						src/gameplay/pause_functions/quit_window.c		\
						src/gameplay/pause_functions/return_to_menu.c	\
						src/gameplay/pause_functions/save_change.c		\
						src/gameplay/tower_panel/init_tower_panel.c		\
						src/gameplay/tower_panel/destroy_tower_panel.c	\
						src/gameplay/tower_panel/draw_tower_panel.c		\
						src/gameplay/tower_panel/event_tower_panel.c

END_MENU 			= 	src/end_menu/init.c 							\
						src/end_menu/loop.c 							\

LEVEL				=	src/level/init_level.c							\
						src/level/destroy_level.c						\
						src/level/draw_levels.c							\
						src/level/load_settings.c						\
						src/level/load_settings/set_background.c		\
						src/level/load_settings/set_music.c				\
						src/level/load_grid.c							\
						src/level/load_grid_positions.c					\
						src/level/setup_grid.c							\
						src/level/setup_grid/set_way_char.c				\
						src/level/setup_grid/set_slime_start.c			\
						src/level/setup_grid/set_cake.c					\
						src/level/setup_grid/set_tower.c				\
						src/level/setup_grid/set_grid_case_size.c		\
						src/level/game_actions.c						\
						src/level/cake.c								\
						src/level/money.c								\
						src/level/draw_money.c

SLIMES				=	src/slimes/slime.c								\
						src/slimes/path.c								\
						src/slimes/draw_slimes.c						\
						src/slimes/slime_on_area.c						\
						src/slimes/hit_slime.c

TOWERS				=	src/towers/tower.c								\
						src/towers/draw_tower_bases.c					\
						src/towers/draw_towers.c						\
						src/towers/event_towers.c						\
						src/towers/projectiles.c						\
						src/towers/get_tower_bases.c					\
						src/towers/attack_default_tower.c				\
						src/towers/attack_slime.c						\
						src/towers/draw_default_tower.c					\
						src/towers/fire/fire.c							\
						src/towers/fire/attack_fire.c					\
						src/towers/ice/ice.c							\
						src/towers/ice/attack_ice.c						\
						src/towers/sniper/sniper.c						\
						src/towers/sniper/attack_sniper.c

SRC					=	$(MAIN) $(MENU) $(GAMEPLAY) $(LEVEL) $(SLIMES) $(TOWERS) $(END_MENU)

CFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

override LDFLAGS	=	-L./lib

override LDLIBS		+=	-lmy -lcsfml

OBJ					=	$(SRC:.c=.o)

NAME				=	my_defender

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LDLIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

-lmy:
	$(MAKE) -s -C ./lib/my

-lcsfml:
	$(MAKE) -s -C ./lib/csfml

debug:	CFLAGS += -g
debug:	$(LDLIBS)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

clean:
	$(RM) $(OBJ)
	$(RM) unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all -lmy -lcsfml debug clean fclean re
