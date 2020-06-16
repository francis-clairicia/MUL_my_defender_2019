/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game.h
*/

#ifndef DEFEND_GAME_H_
#define DEFEND_GAME_H_

#include "level.h"

typedef struct config
{
    int music_volume;
    int sound_volume;
} config_t;

typedef struct option
{
    obj_t *pause;
    invisible_button_t **pause_buttons;
    config_t *config;
    int nb_b;
} opt_t;

typedef struct game
{
    int nb_levels;
    level_t **levels;
    int actual_lvl;
    opt_t option;
    tower_panel_t panel;
} game_t;

void init_game(game_t *game);
void destroy_game(game_t *game);

void init_options(opt_t *options);
void destroy_options(opt_t *options);

config_t *load_config(void);
void save_config(config_t *config);

#endif