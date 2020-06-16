/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_text_origin.c
*/

#include "defend.h"

void set_text_origin_to_middle(text_t text, sfBool x, sfBool y)
{
    sfFloatRect rect = sfText_getLocalBounds(text.object);
    sfVector2f origin = {rect.width / 2, rect.height * 4 / 5};

    if (!x)
        origin.x = 0;
    if (!y)
        origin.y = 0;
    sfText_setOrigin(text.object, origin);
}