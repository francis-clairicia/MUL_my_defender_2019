/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** event_towers.c
*/

#include "tower.h"

void event_towers(list_t *towers, list_t *slimes)
{
    list_t *node = NULL;
    tower_t *tower = NULL;

    for (node = towers; node != NULL; node = node->next) {
        tower = (tower_t *)(node->data);
        tower->attack_enemy(tower, slimes);
    }
}