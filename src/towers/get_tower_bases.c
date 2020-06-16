/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** get_tower_bases.c
*/

#include "level.h"

static int valid_box(grid_t grid, int x, int y, list_t *towers)
{
    list_t *node = NULL;
    tower_t *tower = NULL;

    if (grid.db[y][x] != grid.tower)
        return (0);
    for (node = towers; node != NULL; node = node->next) {
        tower = (tower_t *)(node->data);
        if (x == tower->grid_pos.x && y == tower->grid_pos.y)
            return (0);
    }
    return (1);
}

list_t *get_tower_bases(grid_t grid, list_t *towers)
{
    list_t *empty_places = NULL;
    sfVector2i *pos = NULL;
    int x = -1;
    int y = 0;

    while (grid.db[y] != NULL) {
        x += 1;
        if (valid_box(grid, x, y, towers)) {
            pos = malloc(sizeof(*pos));
            pos->x = x;
            pos->y = y;
            my_append_to_list(&empty_places, (long)pos);
        } else if (grid.db[y][x] == '\0') {
            x = -1;
            y += 1;
        }
    }
    return (empty_places);
}