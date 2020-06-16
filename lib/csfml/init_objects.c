/*
** EPITECH PROJECT, 2019
** init_object
** File description:
** fucntions currently used
*/

#include "include/struct.h"

sfVector2f init_vector2f(int x, int y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

sfIntRect init_rect(int left, int top, int widht, int height)
{
    sfIntRect rect = {left, top, widht, height};

    return (rect);
}

sfColor init_color(int red, int green, int blue, int alpha)
{
    sfColor color = sfColor_fromRGBA(red, green, blue, alpha);

    return (color);
}
