/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_move.c
*/

#include "include/struct.h"

void set_pos_img_button(image_button_t *button, sfVector2f pos)
{
    sfSprite *sprite = button->object->sprite;

    sfSprite_setPosition(sprite, pos);
    button->invisible->rect = sfSprite_getGlobalBounds(sprite);
}

void move_img_button(image_button_t *button, sfVector2f offset)
{
    sfSprite *sprite = button->object->sprite;

    sfSprite_move(sprite, offset);
    button->invisible->rect = sfSprite_getGlobalBounds(sprite);
}