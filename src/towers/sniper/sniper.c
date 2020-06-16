/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sniper.c
*/

#include "tower.h"

static void draw_sniper_tower(tower_t *tower, sfRenderWindow *window)
{
    sniper_tower_t *special = tower->special;
    list_t *node = NULL;

    draw_tower_default(tower, window);
    for (node = special->aims; node != NULL; node = node->next)
        draw_object((obj_t *)(node->data), window);
}

void create_sniper_tower(tower_t *tower)
{
    sniper_tower_t *sniper = malloc(sizeof(*sniper));

    if (sniper == NULL)
        return;
    sniper->aimed_slimes = NULL;
    sniper->aims = NULL;
    sniper->waiting_clock = sfClock_create();
    sniper->attacking = sfFalse;
    tower->special = sniper;
    tower->draw = &draw_sniper_tower;
    tower->attack_enemy = &attack_sniper_tower;
}

void destroy_sniper_fields(sniper_tower_t *tower)
{
    list_t *node = NULL;

    for (node = tower->aims; node != NULL; node = node->next)
        destroy_object((obj_t *)(node->data));
    my_free_list(&tower->aims, sfFalse);
    my_free_list(&tower->aimed_slimes, sfFalse);
}

void destroy_sniper_tower(void *ptr)
{
    sniper_tower_t *tower = ptr;

    if (ptr == NULL)
        return;
    sfClock_destroy(tower->waiting_clock);
    destroy_sniper_fields(tower);
    free(tower);
}