/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** load_settings.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "level.h"
#include "my.h"

static const config_set_t configs[] = {
    {"map_path", &set_background},
    {"music", &set_music},
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

void load_settings(level_t *level, char const *settings_path)
{
    char *buffer = NULL;
    int fd = open(settings_path, O_RDONLY);

    while (get_next_line(&buffer, fd))
        buffer_treatment(level, buffer);
    close(fd);
}