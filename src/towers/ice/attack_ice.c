/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** attack_ice.c
*/

#include "level.h"

void attack_ice_tower(tower_t *tower, list_t *slimes)
{
    ice_tower_t *special = tower->special;
    list_t *node = NULL;
    slime_t *slime = NULL;
    sfBool status = sfFalse;
    sfColor color[2] = {sfTransparent, sfColor_fromRGBA(0, 255, 255, 100)};

    for (node = slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        if (slime_is_on_area(tower->area, slime)) {
            status = sfTrue;
            slime->speed_factor = special->slow_factor;
        }
    }
    sfCircleShape_setFillColor(tower->area, color[status]);
}