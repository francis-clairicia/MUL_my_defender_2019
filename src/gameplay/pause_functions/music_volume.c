/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** music_volume.c
*/

#include "defend.h"

static void music_volume(tool_t *tools, int volume_offset)
{
    int volume = tools->game.option.config->music_volume + volume_offset;

    if (volume > 100)
        volume = 100;
    else if (volume < 0)
        volume = 0;
    tools->game.option.config->music_volume = volume;
    config_all_scenes(tools);
}

enum SCENE music_volume_up(tool_t *tools)
{
    music_volume(tools, 5);
    return (PAUSE);
}

enum SCENE music_volume_down(tool_t *tools)
{
    music_volume(tools, -5);
    return (PAUSE);
}