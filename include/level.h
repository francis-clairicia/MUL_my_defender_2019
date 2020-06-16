/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** level.h
*/

#ifndef DEFEND_LEVEL_H_
#define DEFEND_LEVEL_H_

#include "struct.h"
#include "config.h"
#include "slime.h"
#include "tower.h"
#include "mylist.h"

typedef struct money_bar
{
    obj_t *bar;
    int amount;
} money_t;

typedef struct grid
{
    char **db;
    sfVector2f **pos;
    sfVector2f size;
    sfVector2f *checkpoints;
    sfVector2i highlighted_base;
    int nb_checkpoints;
    char way;
    char no_way;
    char slime_start;
    char cake_pos;
    char tower;
} grid_t;

typedef struct level
{
    obj_t *background;
    sfMusic *music;
    grid_t grid;
    sfBool show_grid;
    sfBool show_tower_area;
    list_t *slimes;
    sfClock *new_mob;
    list_t *towers;
    obj_t *cake;
    obj_t *lifebar;
    money_t *money;
} level_t;

enum LEVELS
{
    LEVEL_1
};

level_t *init_level(char const *level_folder);
void destroy_level(level_t *level);
void destroy_slimes_list(list_t **list);
void destroy_towers_list(list_t **list);
void draw_level(level_t *level, sfRenderWindow *window);
void draw_tower_bases(grid_t grid, sfRenderWindow *window);
list_t *get_tower_bases(grid_t grid, list_t *towers);

sfVector2f get_case_position(grid_t grid, char start);
void get_all_case_checkpoints(grid_t *grid);

slime_t *init_slime(int type, grid_t grid);
void destroy_slime(slime_t *slime);
obj_t *init_cake(grid_t grid);
obj_t *init_lifebar(obj_t *cake);
int count_life(obj_t *cake, obj_t *lifebar, slime_t *slime, grid_t grid);

money_t *init_money_struct(char const *money_bar_filepath);
void destroy_money_struct(money_t *money);
void draw_money_amount(money_t *money, sfRenderWindow *window);

int event_tower_panel(tower_panel_t *panel, money_t *money, sfEvent event);

typedef struct level_config
{
    char const *file;
    void (*treatment)(level_t *, char const *);
} level_config_t;

typedef struct config_set
{
    char const *variable;
    void (*function)(level_t *, char const *);
} config_set_t;

void load_settings(level_t *level, char const *settings_path);
void set_background(level_t *level, char const *path);
void set_music(level_t *level, char const *path);

void load_grid(level_t *level, char const *grid_txt);
void setup_grid(level_t *level, char const *grid_path);
void set_way_char(level_t *level, char const *chararcter);
void set_no_way_char(level_t *level, char const *chararcter);
void set_slime_start(level_t *level, char const *chararcter);
void set_cake(level_t *level, char const *character);
void set_tower(level_t *level, char const *character);
void set_grid_case_width(level_t *level, char const *width);
void set_grid_case_height(level_t *level, char const *height);
void load_grid_positions(level_t *level);

#endif