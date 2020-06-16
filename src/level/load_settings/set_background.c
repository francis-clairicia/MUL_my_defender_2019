/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set_background.c
*/

#include "defend.h"
#include "my.h"

void set_background(level_t *level, char const *filename)
{
    char *path = join_path(IMG_FOLDER, filename);

    level->background = create_object(path, NULL);
    free(path);
}