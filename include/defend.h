/*
** EPITECH PROJECT, 2020
** defend
** File description:
** struct of my defender
*/

#ifndef DEFEND_H_
#define DEFEND_H_

#include "menu.h"
#include "game.h"

typedef struct tool_s
{
    sfRenderWindow *window;
    obj_t *cursor;
    menu_t menu;
    game_t game;
    menu_t end_menu;
} tool_t;

enum SCENE
{
    PAUSE = -3,
    HELP = -2,
    NO_SCENE = -1,
    MENU,
    GAME,
    GAME_OVER
};

#define IMG_FOLDER "resources/img/"
#define SOUND_FOLDER "resources/audio/"
#define FONT_FOLDER "resources/font/"
#define CONFIG_FILE "settings.conf"
#define DEFAULT_MUSIC_VOLUME 50
#define DEFAULT_SOUND_VOLUME 50

void config_all_scenes(tool_t *tools);

typedef int (*gameloop_t)(tool_t *, int);

int menu_loop(tool_t *tools, int state);
int help_loop(tool_t *tools, int state);

void init_cursor(obj_t *cursor);
void cursor_move(tool_t *tools);

int game_loop(tool_t *tools, int state);
void draw_options(tool_t *tools);
int game_actions(game_t *game);
void game_event(tool_t *tools, sfEvent event);

int end_menu_loop(tool_t *tools, int state);

void start_game(tool_t *tools);
void end_game(tool_t *tools);

/* Pause functions */
typedef enum SCENE (*pause_function_t)(tool_t *);
enum SCENE music_volume_up(tool_t *tools);
enum SCENE music_volume_down(tool_t *tools);
enum SCENE sound_volume_up(tool_t *tools);
enum SCENE sound_volume_down(tool_t *tools);
enum SCENE return_to_menu(tool_t *tools);
enum SCENE quit_window(tool_t *tools);
enum SCENE save_changes(tool_t *tools);
enum SCENE cancel_changes(tool_t *tools);

void set_text_origin_to_middle(text_t text, sfBool x, sfBool y);

#endif /* !DEFEND_H_ */
