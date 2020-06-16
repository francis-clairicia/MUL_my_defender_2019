/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_default_tower.c
*/

#include "tower.h"

void draw_tower_default(tower_t *tower, sfRenderWindow *window)
{
    draw_object(tower->object, window);
    draw_projectiles(tower->projectiles, window);
}