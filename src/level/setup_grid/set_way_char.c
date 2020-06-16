/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_way_char.c
*/

#include "level.h"

void set_way_char(level_t *level, char const *character)
{
    level->grid.way = *character;
}

void set_no_way_char(level_t *level, char const *character)
{
    level->grid.no_way = *character;
}