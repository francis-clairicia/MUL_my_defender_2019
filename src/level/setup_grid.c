/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** setup_grid.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "level.h"
#include "my.h"

static const config_set_t configs[] = {
    {"way", &set_way_char},
    {"no_way", &set_no_way_char},
    {"slime_start", &set_slime_start},
    {"cake", &set_cake},
    {"tower", &set_tower},
    {"case_width", &set_grid_case_width},
    {"case_height", &set_grid_case_height},
    {NULL, NULL}
};

static void buffer_treatment(level_t *level, char const *buffer)
{
    int i = 0;
    char **line = my_str_to_word_array(buffer, "=");

    for (i = 0; configs[i].variable != NULL; i += 1) {
        if (my_strcmp(configs[i].variable, line[0]) == 0)
            configs[i].function(level, line[1]);
    }
    my_free_array(line);
}

void setup_grid(level_t *level, char const *grid_path)
{
    char *buffer = NULL;
    int fd = open(grid_path, O_RDONLY);

    while (get_next_line(&buffer, fd))
        buffer_treatment(level, buffer);
    close(fd);
}