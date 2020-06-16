/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** attack_sniper.c
*/

#include "defend.h"

static void shot_all_slimes(tower_t *tower)
{
    sniper_tower_t *special = tower->special;
    list_t *node = NULL;
    slime_t *slime = NULL;

    for (node = special->aimed_slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        aim_slime(tower->area, slime, &tower->projectiles, 60);
    }
    destroy_sniper_fields(special);
    sfClock_restart(tower->clock);
    special->attacking = sfFalse;
}

static void add_to_aim_list(sniper_tower_t *tower, slime_t *slime)
{
    obj_t *aim = create_object(IMG_FOLDER "sniper_turret_aim.png", NULL);
    sfFloatRect aim_rect = sfSprite_getLocalBounds(aim->sprite);
    sfVector2f aim_origin = {aim_rect.width / 2, aim_rect.height / 2};
    sfFloatRect slime_rect = sfSprite_getGlobalBounds(slime->object->sprite);
    sfVector2f slime_pos = sfSprite_getPosition(slime->object->sprite);

    sfSprite_setOrigin(aim->sprite, aim_origin);
    sfSprite_setPosition(aim->sprite, slime_pos);
    set_obj_width(aim, slime_rect.width);
    my_append_to_list(&tower->aimed_slimes, (long)slime);
    my_append_to_list(&tower->aims, (long)aim);
}

static void aim_incoming_slimes(tower_t *tower, list_t *slimes)
{
    sniper_tower_t *special = tower->special;
    list_t *node = NULL;
    slime_t *slime = NULL;

    destroy_sniper_fields(special);
    for (node = slimes; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        if (slime_is_on_area(tower->area, slime))
            add_to_aim_list(special, slime);
    }
}

void attack_sniper_tower(tower_t *tower, list_t *slimes)
{
    sniper_tower_t *special = tower->special;

    move_projectiles(tower->projectiles);
    check_slime_collision(tower, slimes);
    if (!(special->attacking) && !elapsed_time(tower->shot_time, tower->clock))
        return;
    if (!(special->attacking)) {
        sfClock_restart(special->waiting_clock);
        special->attacking = sfTrue;
    }
    if (elapsed_time(2000, special->waiting_clock))
        shot_all_slimes(tower);
    else
        aim_incoming_slimes(tower, slimes);
}