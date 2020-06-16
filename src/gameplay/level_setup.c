/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** level_setup.c
*/

#include "defend.h"

void start_game(tool_t *tools)
{
    level_t *level = tools->game.levels[tools->game.actual_lvl];

    sfMusic_play(level->music);
    sfClock_restart(level->new_mob);
    set_object_area(level->cake, init_rect(0, 0, 197, 112));
    set_object_area(level->lifebar, init_rect(0, 0, 255, 73));
    level->money->amount = 1000;
}

void end_game(tool_t *tools)
{
    level_t *level = tools->game.levels[tools->game.actual_lvl];

    sfMusic_stop(level->music);
    destroy_slimes_list(&level->slimes);
    destroy_towers_list(&level->towers);
}