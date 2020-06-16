/*
** EPITECH PROJECT, 2020
** game_action
** File description:
** action realised during a game
*/

#include <stdlib.h>
#include "defend.h"

static void new_slime(level_t *level, config_t *config)
{
    grid_t grid = level->grid;
    slime_t *slime = NULL;

    srand(rand());
    if (elapsed_time(1000, level->new_mob)) {
        slime = init_slime(rand() % 5, grid);
        sfMusic_setVolume(slime->sound, config->sound_volume),
        my_append_to_list(&level->slimes, (long)slime);
    }
}

static int check_slime_attack(level_t *lvl, slime_t *slime, int node_index)
{
    int ret = 0;

    if (slime->hp == 0) {
        lvl->money->amount += slime->stats.gold;
        destroy_slime(slime);
        my_delete_node(&lvl->slimes, node_index, 0);
        return (1);
    }
    ret = count_life(lvl->cake, lvl->lifebar, slime, lvl->grid);
    if (ret != 0) {
        destroy_slime(slime);
        my_delete_node(&lvl->slimes, node_index, 0);
    }
    return (ret);
}

int game_actions(game_t *game)
{
    level_t *lvl = game->levels[game->actual_lvl];
    list_t *node = lvl->slimes;
    slime_t *slime = NULL;
    int ret = 0;
    int node_index = 0;

    new_slime(lvl, game->option.config);
    event_towers(lvl->towers, lvl->slimes);
    while ((node = my_node(lvl->slimes, node_index)) != NULL) {
        slime = (slime_t *)(node->data);
        if (elapsed_time(100, slime->object->clock) == 1) {
            anim_slime(slime, lvl->grid.checkpoints, lvl->grid.nb_checkpoints);
            ret = check_slime_attack(lvl, slime, node_index);
        }
        if (ret == 2)
            return (GAME_OVER);
        if (ret == 0)
            node_index += 1;
    }
    return (GAME);
}