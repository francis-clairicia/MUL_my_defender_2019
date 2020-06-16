/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** config.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "defend.h"
#include "my.h"

static void set_config(config_t *config, char const *line_file)
{
    char **line = my_str_to_word_array(line_file, "=");

    if (my_array_len(line) == 2) {
        if (my_strcmp(line[0], "music") == 0 && my_str_isnum(line[1]))
            config->music_volume = my_getnbr(line[1]);
        else if (my_strcmp(line[0], "sound") == 0 && my_str_isnum(line[1]))
            config->sound_volume = my_getnbr(line[1]);
    }
    my_free_array(line);
}

config_t *load_config(void)
{
    config_t *config = malloc(sizeof(*config));
    char *line = NULL;
    int fd = open(CONFIG_FILE, O_RDONLY);

    if (fd < 0) {
        config->music_volume = DEFAULT_MUSIC_VOLUME;
        config->sound_volume = DEFAULT_SOUND_VOLUME;
        save_config(config);
    } else {
        while (get_next_line(&line, fd))
            set_config(config, line);
        close(fd);
    }
    return (config);
}

void save_config(config_t *config)
{
    int fd = open(CONFIG_FILE, O_CREAT | O_WRONLY | O_TRUNC);
    char *music = my_nbr_to_str(config->music_volume);
    char *sound = my_nbr_to_str(config->sound_volume);

    if (fd > 0 && music != NULL && sound != NULL) {
        my_putstr_fd(fd, "music=");
        my_putstr_fd(fd, music);
        my_putstr_fd(fd, "\nsound=");
        my_putstr_fd(fd, sound);
        close(fd);
    }
    free(music);
    free(sound);
}