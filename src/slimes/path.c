/*
** EPITECH PROJECT, 2020
** path
** File description:
** functions linked to slime movement
*/

#include "defend.h"

static void less_pos(float *pos, float point, int speed, float *verif)
{
    int n = 0;

    while (n <= speed) {
        *pos -= 1;
        if (*pos == point) {
            *verif = 1;
            return;
        }
        n += 1;
    }
}

static void plus_pos(float *pos, float point, int speed, float *verif)
{
    int n = 0;

    while (n <= speed) {
        *pos += 1;
        if (*pos == point) {
            *verif = 1;
            return;
        }
        n += 1;
    }
}

static void verif_coord(sfVector2f *pos, sfVector2f *verif, sfVector2f point,
    int speed)
{
    if (pos->x > point.x) {
        less_pos(&pos->x, point.x, speed, &verif->x);
    } else if (pos->x < point.x) {
        plus_pos(&pos->x, point.x, speed, &verif->x);
    } else {
        verif->x = 1;
    }
    if (pos->y > point.y) {
        less_pos(&pos->y, point.y, speed, &verif->y);
    } else if (pos->y < point.y) {
        plus_pos(&pos->y, point.y, speed, &verif->y);
    } else {
        verif->y = 1;
    }
}

void move_slime(slime_t *slime, sfVector2f *checkpoints, int max)
{
    sfVector2f verif = {0, 0};
    sfVector2f slime_pos = sfSprite_getPosition(slime->object->sprite);
    sfVector2f checkpoint = checkpoints[slime->progress];
    float speed = slime->stats.speed * slime->speed_factor;

    if (slime->progress == max)
        return;
    verif_coord(&slime_pos, &verif, checkpoint, speed);
    if (verif.x == 1 && verif.y == 1)
        slime->progress += 1;
    sfSprite_setPosition(slime->object->sprite, slime_pos);
    slime->speed_factor = 1;
}