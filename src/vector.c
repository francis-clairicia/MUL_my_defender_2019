/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** vector.c
*/

#include "vector.h"

sfVector2f vector(sfVector2f point_a, sfVector2f point_b)
{
    sfVector2f v;

    v.x = point_b.x - point_a.x;
    v.y = point_b.y - point_a.y;
    return (v);
}

float vector_norm(sfVector2f vector)
{
    return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
}

float cross_product(sfVector2f u, sfVector2f v)
{
    return ((u.x * v.y) - (u.y * v.x));
}

float dot_product(sfVector2f u, sfVector2f v)
{
    return ((u.x * v.x) + (u.y * v.y));
}

float angle_formed_by_vector(sfVector2f u, sfVector2f v)
{
    return (acos(dot_product(u, v) / (vector_norm(u) * vector_norm(v))));
}