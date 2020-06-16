/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_grid_case_size.c
*/

#include "level.h"
#include "my.h"

void set_grid_case_width(level_t *level, char const *width)
{
    level->grid.size.x = my_getnbr(width);
}

void set_grid_case_height(level_t *level, char const *height)
{
    level->grid.size.y = my_getnbr(height);
}