/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** ice.c
*/

#include "tower.h"

static void draw_ice_tower(tower_t *tower, sfRenderWindow *window)
{
    draw_object(tower->object, window);
}

void create_ice_tower(tower_t *tower)
{
    ice_tower_t *ice_tower = malloc(sizeof(*ice_tower));

    if (ice_tower == NULL)
        return;
    ice_tower->slow_factor = 0.5;
    tower->special = ice_tower;
    tower->draw = &draw_ice_tower;
    tower->attack_enemy = &attack_ice_tower;
}

void destroy_ice_tower(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}