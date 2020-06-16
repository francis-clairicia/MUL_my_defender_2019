/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_draw.c
*/

#include "include/struct.h"

void draw_img_button(image_button_t *button, sfRenderWindow *window)
{
    enum BUTTON_STATE state = button->invisible->state;

    set_object_area(button->object, button->rect[state]);
    draw_object(button->object, window);
}