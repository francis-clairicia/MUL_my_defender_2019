/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** destroy_level.c
*/

#include <stdio.h>
#include "level.h"
#include "my.h"

void destroy_slimes_list(list_t **list)
{
    list_t *node = NULL;
    slime_t *slime = NULL;

    for (node = *list; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        destroy_slime(slime);
    }
    my_free_list(list, 0);
}

void destroy_towers_list(list_t **list)
{
    list_t *node = NULL;
    tower_t *tower = NULL;

    for (node = *list; node != NULL; node = node->next) {
        tower = (tower_t *)(node->data);
        destroy_tower(tower);
    }
    my_free_list(list, 0);
}

static void destroy_grid_pos(sfVector2f **positions, int nb_rows)
{
    int i = 0;

    if (positions == NULL)
        return;
    for (i = 0; i < nb_rows; i += 1)
        free(positions[i]);
    free(positions);
}

void destroy_level(level_t *level)
{
    destroy_object(level->background);
    if (level->music != NULL)
        sfMusic_destroy(level->music);
    if (level->new_mob != NULL)
        sfClock_destroy(level->new_mob);
    destroy_object(level->cake);
    destroy_object(level->lifebar);
    destroy_money_struct(level->money);
    destroy_grid_pos(level->grid.pos, my_array_len(level->grid.db));
    my_free_array(level->grid.db);
    if (level->grid.checkpoints)
        free(level->grid.checkpoints);
    destroy_slimes_list(&level->slimes);
    destroy_towers_list(&level->towers);
    free(level);
}