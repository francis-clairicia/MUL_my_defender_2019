/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** hit_slime.c
*/

#include "slime.h"

sfBool hit_slime(slime_t *slime, int damages)
{
    if (slime != NULL) {
        slime->hp -= damages;
        if (slime->hp < 0)
            slime->hp = 0;
        return (sfTrue);
    }
    return (sfFalse);
}