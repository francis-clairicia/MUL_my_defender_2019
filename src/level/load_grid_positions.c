/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** load_grid_positions.c
*/

#include "level.h"
#include "my.h"

sfVector2f get_case_position(grid_t grid, char start)
{
    int x = 0;
    int y = 0;
    sfVector2f square;

    while (grid.db[y] != NULL && grid.db[y][x] != start) {
        x += 1;
        if (grid.db[y][x] == '\0') {
            x = 0;
            y += 1;
        }
    }
    if (grid.db[y] == NULL || grid.db[y][x] != start)
        return ((sfVector2f){-1, -1});
    square.x = grid.pos[y][x].x + grid.size.x / 2;
    square.y = grid.pos[y][x].y + grid.size.y / 2;
    return (square);
}

void get_all_case_checkpoints(grid_t *grid)
{
    char max = '0';
    sfVector2f ret = {0, 0};
    int index = 0;

    while (ret.x != -1 && max <= '9') {
        ret = get_case_position(*grid, max);
        max += 1;
    }
    max -= 48;
    grid->checkpoints = malloc(sizeof(sfVector2f) * (max));
    while (index < max - 1 && index <= 9) {
        grid->checkpoints[index] = get_case_position(*grid, index + 48);
        index += 1;
    }
    grid->checkpoints[index] = get_case_position(*grid, grid->cake_pos);
    grid->nb_checkpoints = max;
}

void load_grid_positions(level_t *level)
{
    int row = 0;
    int col = 0;
    int nb_rows = my_array_len(level->grid.db);
    int nb_cols = 0;

    level->grid.pos = malloc(sizeof(sfVector2f *) * nb_rows);
    for (row = 0; row < nb_rows; row += 1) {
        nb_cols = my_strlen(level->grid.db[row]);
        level->grid.pos[row] = malloc(sizeof(sfVector2f) * nb_cols);
        for (col = 0; col < nb_cols; col += 1) {
            level->grid.pos[row][col].x = col * level->grid.size.x;
            level->grid.pos[row][col].y = row * level->grid.size.y;
        }
    }
}