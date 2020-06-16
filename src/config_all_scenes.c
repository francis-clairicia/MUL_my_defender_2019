/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** config_all_scenes.c
*/

#include "defend.h"

static void set_volume(sfMusic **musics, int nb, int volume)
{
    int i = 0;

    for (i = 0; i < nb; i += 1)
        sfMusic_setVolume(musics[i], volume);
}

static void set_slime_sound(list_t *slime_list, int volume)
{
    list_t *node = NULL;
    slime_t *slime = NULL;

    for (node = slime_list; node != NULL; node = node->next) {
        slime = (slime_t *)(node->data);
        set_volume(&slime->sound, 1, volume);
    }
}

void config_all_scenes(tool_t *tools)
{
    config_t *config = tools->game.option.config;
    int music = config->music_volume;
    int sound = config->sound_volume;
    int i = 0;

    set_volume(&tools->menu.music, 1, music);
    for (i = 0; i < tools->game.nb_levels; i += 1) {
        set_volume(&tools->game.levels[i]->music, 1, music);
        set_slime_sound(tools->game.levels[i]->slimes, sound);
    }
    for (i = 0; i < tools->menu.nb_buttons; i += 1)
        set_volume(tools->menu.buttons[i]->invisible->sounds, 2, sound);
    for (i = 0; i < tools->game.option.nb_b; i += 1)
        set_volume(tools->game.option.pause_buttons[i]->sounds, 2, sound);
}