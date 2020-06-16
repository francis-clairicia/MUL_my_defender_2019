/*
** EPITECH PROJECT, 2020
** init
** File description:
** initialisation of teh game
*/

#include "defend.h"

static const char *levels_path[] = {
    "levels/level_1"
};

void init_game(game_t *game)
{
    int i = 0;

    game->nb_levels = sizeof(levels_path) / sizeof(levels_path[0]);
    game->levels = malloc(sizeof(level_t) * game->nb_levels);
    for (i = 0; i < game->nb_levels; i += 1)
        game->levels[i] = init_level(levels_path[i]);
    game->actual_lvl = LEVEL_1;
    game->panel = init_tower_panel();
}

void destroy_game(game_t *game)
{
    int i = 0;

    for (i = 0; i < game->nb_levels; i += 1)
        destroy_level(game->levels[i]);
    free(game->levels);
    destroy_options(&(game->option));
    destroy_tower_panel(game->panel);
}