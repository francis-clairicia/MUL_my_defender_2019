/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_music.c
*/

#include "defend.h"
#include "my.h"

void set_music(level_t *level, char const *filename)
{
    char *path = join_path(SOUND_FOLDER, filename);

    level->music = sfMusic_createFromFile(path);
    free(path);
}