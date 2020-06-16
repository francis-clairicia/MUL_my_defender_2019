/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** vector.h
*/

#ifndef HEADER_VECTOR_CALC
#define HEADER_VECTOR_CALC

#include <math.h>
#include <SFML/System/Vector2.h>

sfVector2f vector(sfVector2f point_a, sfVector2f point_b);
float vector_norm(sfVector2f vector);
float dot_product(sfVector2f u, sfVector2f v);
float cross_product(sfVector2f u, sfVector2f v);
float angle_formed_by_vector(sfVector2f u, sfVector2f v);

#endif