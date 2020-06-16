/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** projectiles.c
*/

#include "tower.h"
#include "vector.h"

projectile_t *create_projectile(float radius, float speed,
    sfVector2f direction, sfVector2f pos)
{
    projectile_t *projectile = malloc(sizeof(*projectile));

    projectile->bullet = sfCircleShape_create();
    sfCircleShape_setRadius(projectile->bullet, radius);
    sfCircleShape_setFillColor(projectile->bullet, sfBlack);
    sfCircleShape_setOrigin(projectile->bullet, init_vector2f(radius, radius));
    sfCircleShape_setPosition(projectile->bullet, pos);
    projectile->direction = direction;
    projectile->speed = speed;
    projectile->clock = sfClock_create();
    return (projectile);
}

void destroy_projectile(projectile_t *projectile)
{
    sfCircleShape_destroy(projectile->bullet);
    sfClock_destroy(projectile->clock);
    free(projectile);
}

void draw_projectiles(list_t *projectiles, sfRenderWindow *window)
{
    list_t *node = NULL;
    projectile_t *projectile = NULL;

    for (node = projectiles; node != NULL; node = node->next) {
        projectile = (projectile_t *)(node->data);
        if (elapsed_time(10, projectile->clock))
            sfRenderWindow_drawCircleShape(window, projectile->bullet, NULL);
    }
}

void move_projectiles(list_t *projectiles)
{
    list_t *node = NULL;
    projectile_t *projectile = NULL;
    sfVector2f offset;

    for (node = projectiles; node != NULL; node = node->next) {
        projectile = (projectile_t *)(node->data);
        offset.x = projectile->direction.x * projectile->speed;
        offset.y = projectile->direction.y * projectile->speed;
        sfCircleShape_move(projectile->bullet, offset);
    }
}