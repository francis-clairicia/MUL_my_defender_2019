/*
** EPITECH PROJECT, 2020
** slime
** File description:
** slime header
*/

#ifndef SLIME_H_
#define SLIME_H_

#include "struct.h"
#include "mylist.h"

enum SLIME_TYPE
{
    BASIC_SLIME,
    ANGRY_SLIME,
    SPEEDY_SLIME,
    TANKY_SLIME,
    GOLDY_SLIME
};

typedef struct slime_stats
{
    char const *filename;
    int max_hp;
    int speed;
    int gold;
} slime_stat_t;

typedef struct slime_s {
    obj_t *object;
    int progress;
    enum SLIME_TYPE type;
    slime_stat_t stats;
    int hp;
    float speed_factor;
    sfMusic *sound;
} slime_t;

void move_slime(slime_t *slime, sfVector2f *checkpoints, int max);
void anim_slime(slime_t *slime, sfVector2f *checkpoint, int max);
void draw_slimes(list_t *start, sfRenderWindow *window);
sfBool slime_is_on_area(sfCircleShape *area, slime_t *slime);
sfBool hit_slime(slime_t *slime, int damages);
void aim_slime(sfCircleShape *area, slime_t *slime, list_t **projectiles,
    int speed);

#endif /* !SLIME_H_ */
