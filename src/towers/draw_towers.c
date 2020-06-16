/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_towers.c
*/

#include "tower.h"

void draw_towers(list_t *towers, sfRenderWindow *window, sfBool show_area)
{
    list_t *node = NULL;
    tower_t *tower = NULL;

    for (node = towers; node != NULL; node = node->next) {
        tower = (tower_t *)(node->data);
        if (show_area)
            sfCircleShape_setOutlineColor(tower->area, sfBlack);
        else
            sfCircleShape_setOutlineColor(tower->area, sfTransparent);
        sfRenderWindow_drawCircleShape(window, tower->area, NULL);
        tower->draw(tower, window);
    }
}