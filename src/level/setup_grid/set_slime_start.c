/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_slime_start.c
*/

#include "level.h"

void set_slime_start(level_t *level, char const *character)
{
    level->grid.slime_start = *character;
}