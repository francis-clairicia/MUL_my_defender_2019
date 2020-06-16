/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower.c
*/

#include "defend.h"

static const struct tower_stats tower_stats[] = {
    [BASIC_TOWER] = {IMG_FOLDER "basic_turret.png", 250, 30, 200},
    [FIRE_TOWER] = {IMG_FOLDER "fire_turret.png", 300, 80, 800},
    [ICE_TOWER] = {IMG_FOLDER "ice_turret.png", 310, 0, 0},
    [SNIPER_TOWER] = {IMG_FOLDER "sniper_turret.png", 500, 150, 2000},
};

static const special_tower_creation_t special_creation[] = {
    [BASIC_TOWER] = NULL,
    [FIRE_TOWER] = &create_fire_tower,
    [ICE_TOWER] = &create_ice_tower,
    [SNIPER_TOWER] = &create_sniper_tower,
};

static const special_tower_destroyer_t special_destroyer[] = {
    [BASIC_TOWER] = NULL,
    [FIRE_TOWER] = &destroy_fire_tower,
    [ICE_TOWER] = &destroy_ice_tower,
    [SNIPER_TOWER] = &destroy_sniper_tower,
};

static void set_default_values(tower_t *tower, int type)
{
    tower->clock = sfClock_create();
    tower->damage = tower_stats[type].damage;
    tower->shot_time = tower_stats[type].shot_time;
    tower->type = type;
    tower->projectiles = NULL;
    tower->special = NULL;
    tower->draw = &draw_tower_default;
    tower->attack_enemy = &attack_tower_default;
    if (special_creation[type] != NULL)
        special_creation[type](tower);
}

static void setup_area(sfCircleShape *area, float radius, sfVector2f pos)
{
    sfCircleShape_setRadius(area, radius);
    sfCircleShape_setOrigin(area, init_vector2f(radius, radius));
    sfCircleShape_setPosition(area, pos);
    sfCircleShape_setFillColor(area, sfTransparent);
    sfCircleShape_setOutlineThickness(area, 3);
}

static void setup_tower(obj_t *tower, sfVector2f pos, sfVector2f size)
{
    sfFloatRect rect = sfSprite_getLocalBounds(tower->sprite);
    sfVector2f origin = init_vector2f(rect.width / 2, rect.height / 2);

    sfSprite_setOrigin(tower->sprite, origin);
    sfSprite_setPosition(tower->sprite, pos);
    size.x /= rect.width;
    size.y /= rect.height;
    sfSprite_setScale(tower->sprite, size);
}

tower_t *create_tower(enum TOWER_TYPE type, sfVector2f pos, sfVector2f size)
{
    tower_t *tower = malloc(sizeof(*tower));

    if (tower == NULL)
        return (NULL);
    tower->object = create_object(tower_stats[type].filename, NULL);
    setup_tower(tower->object, pos, size);
    tower->area = sfCircleShape_create();
    setup_area(tower->area, tower_stats[type].radius, pos);
    set_default_values(tower, type);
    return (tower);
}

void destroy_tower(tower_t *tower)
{
    list_t *node = NULL;

    destroy_object(tower->object);
    sfCircleShape_destroy(tower->area);
    for (node = tower->projectiles; node != NULL; node = node->next)
        destroy_projectile((projectile_t *)(node->data));
    my_free_list(&tower->projectiles, 0);
    if (tower->clock != NULL)
        sfClock_destroy(tower->clock);
    if (special_destroyer[tower->type] != NULL)
        special_destroyer[tower->type](tower->special);
    free(tower);
}