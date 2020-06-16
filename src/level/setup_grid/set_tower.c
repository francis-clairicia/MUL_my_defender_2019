/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_tower.c
*/

#include "level.h"

void set_tower(level_t *level, char const *character)
{
    level->grid.tower = *character;
}