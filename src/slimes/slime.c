/*
** EPITECH PROJECT, 2020
** slime
** File description:
** creation and management of slimes
*/

#include "defend.h"
#include "my.h"

static const slime_stat_t slime_stats[] = {
    {"basic_slime.png", 100, 20, 20},
    {"angry_slime.png", 200, 25, 50},
    {"speedy_slime.png", 150, 60, 70},
    {"tanky_slime.png", 600, 10, 100},
    {"goldy_slime.png", 500, 35, 300}
};

slime_t *init_slime(int type, grid_t grid)
{
    sfIntRect area = init_rect(0, 0, 65, 64);
    char *path = join_path(IMG_FOLDER, slime_stats[type].filename);
    slime_t *slime = malloc(sizeof(*slime));
    sfVector2f pos = {0, 0};
    sfVector2f origin = {area.width / 2, area.height / 2};

    slime->type = type;
    slime->object = create_object(path, &area);
    free(path);
    sfSprite_setOrigin(slime->object->sprite, origin);
    pos = grid.checkpoints[0];
    sfSprite_setPosition(slime->object->sprite, pos);
    slime->object->size = init_vector2f(455, 64);
    slime->object->clock = sfClock_create();
    slime->stats = slime_stats[type];
    slime->hp = slime->stats.max_hp;
    slime->progress = 1;
    slime->speed_factor = 1;
    slime->sound = sfMusic_createFromFile(SOUND_FOLDER "slime_splat.wav");
    return (slime);
}

void destroy_slime(slime_t *slime)
{
    destroy_object(slime->object);
    sfMusic_destroy(slime->sound);
    free(slime);
}

void anim_slime(slime_t *slime, sfVector2f *checkpoint, int max)
{
    obj_t *slime_obj = slime->object;

    slime_obj->area.left += slime_obj->area.width;
    if (slime_obj->area.left > 260) {
        move_slime(slime, checkpoint, max);
    }
    if (slime_obj->area.left >= slime_obj->size.x) {
        slime_obj->area.left = 0;
        sfMusic_stop(slime->sound);
        sfMusic_play(slime->sound);
    }
    sfSprite_setTextureRect(slime_obj->sprite, slime_obj->area);
}