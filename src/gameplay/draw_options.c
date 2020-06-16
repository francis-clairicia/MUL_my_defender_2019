/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_options.c
*/

#include "defend.h"
#include "my.h"

void draw_options(tool_t *tools)
{
    config_t *config = tools->game.option.config;
    char *music = my_nbr_to_str(config->music_volume);
    char *sound = my_nbr_to_str(config->sound_volume);
    char *font = FONT_FOLDER "afterglow.ttf";
    text_t text_music = init_text(music, font, (sfVector2f){550, 220}, 50);
    text_t text_sound = init_text(sound, font, (sfVector2f){550, 375}, 50);

    change_text_color(text_music.object, sfBlack);
    change_text_color(text_sound.object, sfBlack);
    set_text_origin_to_middle(text_music, sfTrue, sfTrue);
    set_text_origin_to_middle(text_sound, sfTrue, sfTrue);
    draw_object(tools->game.option.pause, tools->window);
    draw_text(tools->window, text_music);
    draw_text(tools->window, text_sound);
    free(music);
    free(sound);
    destroy_text(text_music);
    destroy_text(text_sound);
}