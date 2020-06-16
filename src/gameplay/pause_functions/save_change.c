/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** save_change.c
*/

#include "defend.h"

enum SCENE save_changes(tool_t *tools)
{
    save_config(tools->game.option.config);
    return (GAME);
}

enum SCENE cancel_changes(tool_t *tools)
{
    free(tools->game.option.config);
    tools->game.option.config = load_config();
    config_all_scenes(tools);
    return (GAME);
}