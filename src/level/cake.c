/*
** EPITECH PROJECT, 2020
** cake
** File description:
** init_cake to defend and game over condition
*/

#include "defend.h"

obj_t *init_cake(grid_t grid)
{
    sfIntRect area = init_rect(0, 0, 197, 112);
    obj_t *cake = create_object(IMG_FOLDER "cake.png", &area);
    sfVector2f origin = {cake->area.width / 2, cake->area.height / 2};
    sfVector2f pos = grid.checkpoints[grid.nb_checkpoints - 1];

    sfSprite_setOrigin(cake->sprite, origin);
    sfSprite_setPosition(cake->sprite, pos);
    cake->size = init_vector2f(791, 112);
    return (cake);
}

obj_t *init_lifebar(obj_t *cake)
{
    sfVector2f cake_pos = sfSprite_getPosition(cake->sprite);
    sfIntRect area = init_rect(0, 0, 255, 73);
    obj_t *lifebar = create_object(IMG_FOLDER "life.png", &area);
    sfVector2f pos = init_vector2f(cake_pos.x, cake_pos.y - 100);
    sfVector2f origin = {lifebar->area.width / 2, lifebar->area.height / 2};

    sfSprite_setOrigin(lifebar->sprite, origin);
    sfSprite_setPosition(lifebar->sprite, pos);
    lifebar->size = init_vector2f(255, 369);
    return (lifebar);
}

int count_life(obj_t *cake, obj_t *lifebar, slime_t *slime, grid_t grid)
{
    if (slime->progress == grid.nb_checkpoints) {
        if (slime->type == GOLDY_SLIME)
            return (1);
        lifebar->area.top += 74;
        if (lifebar->area.top >= 148)
            cake->area.left += 198;
        if (lifebar->area.top >= lifebar->size.y)
            return (2);
        sfSprite_setTextureRect(lifebar->sprite, lifebar->area);
        sfSprite_setTextureRect(cake->sprite, cake->area);
        return (1);
    }
    return (0);
}