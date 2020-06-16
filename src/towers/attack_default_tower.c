/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** default_tower.c
*/

#include "level.h"
#include "vector.h"

void aim_slime(sfCircleShape *area, slime_t *slime, list_t **projectiles,
    int speed)
{
    sfVector2f axis = {1, 0};
    sfVector2f slime_pos = sfSprite_getPosition(slime->object->sprite);
    sfVector2f center = sfCircleShape_getPosition(area);
    float angle = angle_formed_by_vector(vector(center, slime_pos), axis);
    sfVector2f direction;
    projectile_t *projectile = NULL;

    if (slime_pos.y < center.y)
        angle = -angle;
    direction.x = cos(angle);
    direction.y = sin(angle);
    projectile = create_projectile(5, speed, direction, center);
    my_append_to_list(projectiles, (long)projectile);
}

void attack_tower_default(tower_t *tower, list_t *slimes)
{
    slime_t *slime = NULL;
    list_t *node = NULL;

    move_projectiles(tower->projectiles);
    check_slime_collision(tower, slimes);
    if (!elapsed_time(tower->shot_time, tower->clock))
        return;
    for (node = slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        if (slime_is_on_area(tower->area, slime)) {
            aim_slime(tower->area, slime, &tower->projectiles, 25);
            break;
        }
    }
}