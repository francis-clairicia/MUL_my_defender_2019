/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** cursor.c
*/

#include "defend.h"

void init_cursor(obj_t *cursor)
{
    sfFloatRect rect = sfSprite_getLocalBounds(cursor->sprite);
    float middle_x = rect.width / 2;
    float middle_y = rect.height / 2;

    sfSprite_setOrigin(cursor->sprite, (sfVector2f){middle_x, middle_y});
}

void cursor_move(tool_t *tools)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(tools->window);
    sfVector2f cursor_pos = {mouse_pos.x, mouse_pos.y};

    sfSprite_setPosition(tools->cursor->sprite, cursor_pos);
}