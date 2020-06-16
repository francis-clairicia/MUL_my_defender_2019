/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** fire.c
*/

#include "defend.h"

static void draw_fire_tower(tower_t *tower, sfRenderWindow *window)
{
    fire_tower_t *special = tower->special;

    sfCircleShape_setTexture(special->attack_area, special->attack_texture, 1);
    sfRenderWindow_drawCircleShape(window, special->attack_area, NULL);
    draw_object(tower->object, window);
}

void create_fire_tower(tower_t *tower)
{
    char const filepath[] = IMG_FOLDER "fire_tur_att.png";
    fire_tower_t *fire_tower = malloc(sizeof(fire_tower_t));
    sfVector2f pos = sfCircleShape_getPosition(tower->area);

    if (fire_tower == NULL)
        return;
    fire_tower->attack_area = sfCircleShape_create();
    sfCircleShape_setPosition(fire_tower->attack_area, pos);
    fire_tower->attack_texture = sfTexture_createFromFile(filepath, NULL);
    fire_tower->propagation_clock = sfClock_create();
    fire_tower->attacking = sfTrue;
    fire_tower->slimes_on_area = NULL;
    tower->draw = &draw_fire_tower;
    tower->attack_enemy = &attack_fire_tower;
    tower->special = fire_tower;
}

void destroy_fire_tower(void *ptr)
{
    fire_tower_t *tower = ptr;

    if (ptr == NULL)
        return;
    sfCircleShape_destroy(tower->attack_area);
    sfClock_destroy(tower->propagation_clock);
    sfTexture_destroy(tower->attack_texture);
    my_free_list(&tower->slimes_on_area, 0);
}