/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** destroy_tower_panel.c
*/

#include "tower.h"

void destroy_tower_panel(tower_panel_t panel)
{
    int i = 0;

    for (i = 0; i < panel.nb_towers; i += 1)
        destroy_object(panel.towers[i]);
    sfRectangleShape_destroy(panel.dashboard);
}