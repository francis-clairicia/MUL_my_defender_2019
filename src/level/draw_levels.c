/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_level_struct.c
*/

#include "level.h"
#include "my.h"

static sfRectangleShape *create_box(sfVector2f size)
{
    sfRectangleShape *box = sfRectangleShape_create();

    if (box == NULL)
        return (NULL);
    sfRectangleShape_setSize(box, size);
    sfRectangleShape_setOutlineThickness(box, 2);
    sfRectangleShape_setOutlineColor(box, sfColor_fromRGB(0, 25, 150));
    return (box);
}

static void setup_box(sfRectangleShape *box, grid_t grid, int row, int col)
{
    sfRectangleShape_setPosition(box, grid.pos[row][col]);
    sfRectangleShape_setFillColor(box, sfColor_fromRGBA(255, 125, 0, 100));
    if (grid.db[row][col] == grid.way)
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(0, 255, 0, 100));
    if (grid.db[row][col] == grid.no_way)
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(255, 0, 0, 100));
    if (grid.db[row][col] == grid.slime_start)
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(255, 255, 0, 100));
    if (grid.db[row][col] == grid.cake_pos)
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(255, 0, 255, 100));
    if (grid.db[row][col] == grid.tower)
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(31, 133, 222, 100));
}

static void draw_grid(grid_t grid, sfRenderWindow *window)
{
    int row = 0;
    int col = 0;
    int nb_rows = my_array_len(grid.db);
    int nb_cols = 0;
    sfRectangleShape *box = create_box(grid.size);

    if (box == NULL)
        return;
    for (row = 0; row < nb_rows; row += 1) {
        nb_cols = my_strlen(grid.db[row]);
        for (col = 0; col < nb_cols; col += 1) {
            setup_box(box, grid, row, col);
            sfRenderWindow_drawRectangleShape(window, box, NULL);
        }
    }
    sfRectangleShape_destroy(box);
}

void draw_level(level_t *level, sfRenderWindow *window)
{
    draw_object(level->background, window);
    draw_tower_bases(level->grid, window);
    draw_object(level->cake, window);
    draw_object(level->lifebar, window);
    draw_slimes(level->slimes, window);
    draw_towers(level->towers, window, level->show_tower_area);
    draw_money_amount(level->money, window);
    if (level->show_grid)
        draw_grid(level->grid, window);
}