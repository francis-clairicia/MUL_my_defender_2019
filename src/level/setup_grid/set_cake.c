/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_cake.c
*/

#include "level.h"

void set_cake(level_t *level, char const *character)
{
    level->grid.cake_pos = *character;
}