/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** slime_on_area.c
*/

#include "slime.h"
#include "vector.h"

sfBool slime_is_on_area(sfCircleShape *area, slime_t *slime)
{
    sfVector2f slime_pos = sfSprite_getPosition(slime->object->sprite);
    sfVector2f area_center = sfCircleShape_getPosition(area);
    float radius = sfCircleShape_getRadius(area);

    return (vector_norm(vector(area_center, slime_pos)) <= radius);
}