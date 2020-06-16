/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_tower_bases.c
*/

#include "defend.h"
#include "my.h"

static sfRectangleShape *create_tower_base(sfVector2f size)
{
    sfRectangleShape *base = sfRectangleShape_create();

    if (base == NULL)
        return (NULL);
    sfRectangleShape_setSize(base, size);
    sfRectangleShape_setOutlineThickness(base, 4);
    sfRectangleShape_setOutlineColor(base, sfColor_fromRGB(100, 100, 100));
    return (base);
}

static void draw_base(sfRectangleShape *base, grid_t grid,
    sfVector2f coords, sfRenderWindow *window)
{
    int row = coords.y;
    int col = coords.x;

    if (grid.db[row][col] == grid.tower) {
        sfRectangleShape_setPosition(base, grid.pos[row][col]);
        sfRectangleShape_setFillColor(base, sfBlack);
        if (col == grid.highlighted_base.x && row == grid.highlighted_base.y)
            sfRectangleShape_setFillColor(base, sfYellow);
        sfRenderWindow_drawRectangleShape(window, base, NULL);
    }
}

void draw_tower_bases(grid_t grid, sfRenderWindow *window)
{
    int row = 0;
    int col = 0;
    int nb_rows = my_array_len(grid.db);
    int nb_cols = 0;
    sfRectangleShape *base = create_tower_base(grid.size);

    for (row = 0; row < nb_rows; row += 1) {
        nb_cols = my_strlen(grid.db[row]);
        for (col = 0; col < nb_cols; col += 1) {
            draw_base(base, grid, init_vector2f(col, row), window);
        }
    }
    sfRectangleShape_destroy(base);
}