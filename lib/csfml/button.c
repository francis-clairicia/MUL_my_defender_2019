/*
** EPITECH PROJECT, 2020
** init_button
** File description:
** function related to buttons
*/

#include "include/struct.h"

int is_button_is_clicked(float x, float y, sfVector2f pos, sfVector2f size)
{
    int min_x = pos.x;
    int max_x = pos.x + size.x;
    int min_y = pos.y;
    int max_y = pos.y + size.y;

    if ((x > min_x && x < max_x) && (y > min_y && y < max_y)) {
        return (1);
    } else {
        return (0);
    }
}

sfRectangleShape *init_rect_shape(sfVector2f pos, sfVector2f size, sfColor col)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, col);
    return (rectangle);
}

void init_button(button_t *button)
{
    button->rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
}