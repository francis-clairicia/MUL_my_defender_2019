/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** attack_slime.c
*/

#include "level.h"
#include "vector.h"
#include <stdio.h>

static sfBool projectile_on_area(sfCircleShape *area, projectile_t *p)
{
    sfVector2f pos = sfCircleShape_getPosition(p->bullet);
    sfVector2f area_center = sfCircleShape_getPosition(area);
    float radius = sfCircleShape_getRadius(area);

    return (vector_norm(vector(area_center, pos)) <= radius);
}

static slime_t *projectile_hit_slime(projectile_t *p, list_t *slimes)
{
    sfVector2f pos = sfCircleShape_getPosition(p->bullet);
    slime_t *slime = NULL;
    list_t *node = NULL;
    sfFloatRect slime_rect;

    for (node = slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        slime_rect = sfSprite_getGlobalBounds(slime->object->sprite);
        if (sfFloatRect_contains(&slime_rect, pos.x, pos.y))
            return (slime);
    }
    return (NULL);
}

void check_slime_collision(tower_t *tower, list_t *slimes)
{
    slime_t *slime = NULL;
    projectile_t *projectile = NULL;
    list_t *node = tower->projectiles;
    int node_index = 0;

    while (node != NULL) {
        projectile = (projectile_t *)(node->data);
        slime = projectile_hit_slime(projectile, slimes);
        if (hit_slime(slime, tower->damage)
        || !projectile_on_area(tower->area, projectile)) {
            destroy_projectile(projectile);
            my_delete_node(&tower->projectiles, node_index, 0);
        } else
            node_index += 1;
        node = my_node(tower->projectiles, node_index);
    }
}