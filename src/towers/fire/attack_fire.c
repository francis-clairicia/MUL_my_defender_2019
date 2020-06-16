/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** attack_fire.c
*/

#include "level.h"

static float grow_propagation_area(sfCircleShape *area, int offset, float max)
{
    float radius = sfCircleShape_getRadius(area) + offset;

    if (radius < 0)
        radius = 0;
    else if (radius > max)
        radius = max;
    sfCircleShape_setRadius(area, radius);
    sfCircleShape_setOrigin(area, init_vector2f(radius, radius));
    return (radius);
}

static sfBool slime_already_on_area(list_t *slimes, slime_t *slime)
{
    list_t *node = NULL;
    slime_t *slime_node = NULL;

    for (node = slimes; node != NULL; node = node->next) {
        slime_node = (slime_t *)(node->data);
        if (slime_node == slime)
            return (sfTrue);
    }
    return (sfFalse);
}

static void attack_the_slimes(tower_t *tower, list_t *slimes, float radius)
{
    float max_radius = sfCircleShape_getRadius(tower->area);
    fire_tower_t *special = tower->special;
    list_t *node = NULL;
    slime_t *slime = NULL;

    for (node = slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        if (slime_already_on_area(special->slimes_on_area, slime))
            continue;
        if (!slime_is_on_area(special->attack_area, slime))
            continue;
        hit_slime(slime, tower->damage);
        my_append_to_list(&special->slimes_on_area, (long)slime);
    }
    if (radius == max_radius) {
        special->attacking = sfFalse;
    } else if (radius == 0) {
        special->attacking = sfTrue;
        sfClock_restart(tower->clock);
        my_free_list(&special->slimes_on_area, sfFalse);
    }
}

static void area_grow(tower_t *tower, int offset, list_t *slimes)
{
    int speed = 5;
    int grow = speed * offset;
    float max = sfCircleShape_getRadius(tower->area);
    fire_tower_t *special = tower->special;
    float radius = grow_propagation_area(special->attack_area, grow, max);

    attack_the_slimes(tower, slimes, radius);
}

void attack_fire_tower(tower_t *tower, list_t *slimes)
{
    fire_tower_t *special = tower->special;
    float radius = sfCircleShape_getRadius(special->attack_area);

    if (radius == 0 && !elapsed_time(tower->shot_time, tower->clock))
        return;
    if (!elapsed_time(10, special->propagation_clock))
        return;
    if (special->attacking)
        area_grow(tower, 1, slimes);
    else
        area_grow(tower, -1, slimes);
}