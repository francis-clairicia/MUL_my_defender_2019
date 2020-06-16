/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scale_object.c
*/

#include "include/struct.h"

void set_obj_width(obj_t *obj, int width)
{
    sfSprite *sprite = obj->sprite;
    sfFloatRect local_rect = sfSprite_getLocalBounds(sprite);
    sfVector2f scale;

    scale.x = width / local_rect.width;
    scale.y = scale.x;
    sfSprite_setScale(sprite, scale);
}

void set_obj_height(obj_t *obj, int height)
{
    sfSprite *sprite = obj->sprite;
    sfFloatRect local_rect = sfSprite_getLocalBounds(sprite);
    sfVector2f scale;

    scale.y = height / local_rect.height;
    scale.x = scale.y;
    sfSprite_setScale(sprite, scale);
}

void set_obj_size(obj_t *obj, int width, int height)
{
    sfSprite *sprite = obj->sprite;
    sfFloatRect local_rect = sfSprite_getLocalBounds(sprite);
    sfVector2f scale;

    scale.x = width / local_rect.width;
    scale.y = height / local_rect.height;
    sfSprite_setScale(sprite, scale);
}