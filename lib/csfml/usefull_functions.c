/*
** EPITECH PROJECT, 2020
** usefull_functions
** File description:
** usefull functions
*/

#include "include/struct.h"

void increment_pos(float *pos, float offset, int max_value, int reset)
{
    *pos += offset;
    if (*pos > max_value) {
        *pos = reset;
    }
}

void decrement_pos(float *pos, float offset, int max_value, int reset)
{
    *pos -= offset;
    if (*pos < max_value) {
        *pos = reset;
    }
}

int random_value(int modulo)
{
    int nb = 0;

    srand(0);
    nb = rand() % modulo;
    return (nb);
}
