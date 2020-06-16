/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_level.c
*/

#include <dirent.h>
#include "defend.h"
#include "my.h"

static const level_config_t level_config[] = {
    {"level_settings.conf", &load_settings},
    {"grid.txt", &load_grid},
    {"grid.conf", &setup_grid},
    {NULL, NULL}
};

static void set_default_values(level_t *level)
{
    level->background = NULL;
    level->music = NULL;
    level->grid.db = NULL;
    level->grid.pos = NULL;
    level->grid.checkpoints = NULL;
    level->grid.size = (sfVector2f){0, 0};
    level->grid.highlighted_base = (sfVector2i){-1, -1};
    level->show_grid = sfFalse;
    level->show_tower_area = sfFalse;
    level->slimes = NULL;
    level->towers = NULL;
}

static void setup_level(level_t *level)
{
    load_grid_positions(level);
    get_all_case_checkpoints(&level->grid);
    if (level->music != NULL)
        sfMusic_setLoop(level->music, sfTrue);
    level->cake = init_cake(level->grid);
    level->lifebar = init_lifebar(level->cake);
    level->new_mob = sfClock_create();
    level->money = init_money_struct(IMG_FOLDER "money.png");
}

static void field_level(level_t *level, char const *path, char const *name)
{
    char *file = NULL;
    int i = 0;

    for (i = 0; level_config[i].file != NULL; i += 1) {
        if (my_strcmp(level_config[i].file, name) == 0) {
            file = join_path(path, name);
            level_config[i].treatment(level, file);
            free(file);
            return;
        }
    }
}

level_t *init_level(char const *level_folder)
{
    level_t *level = NULL;
    struct dirent *ent;
    DIR *folder = opendir(level_folder);

    if (folder == NULL)
        return (NULL);
    level = malloc(sizeof(*level));
    set_default_values(level);
    while ((ent = readdir(folder)) != NULL)
        field_level(level, level_folder, ent->d_name);
    closedir(folder);
    setup_level(level);
    return (level);
}