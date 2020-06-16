/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_text.c
*/

#include "include/struct.h"

void draw_text(sfRenderWindow *window, text_t text)
{
    sfRenderWindow_drawText(window, text.object, NULL);
}