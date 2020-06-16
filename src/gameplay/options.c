/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** options.c
*/

#include "defend.h"

static const sfFloatRect options_button_rect[] = {
    {330, 168, 155, 120},
    {622, 168, 155, 120},
    {330, 318, 155, 120},
    {622, 318, 155, 120},
    {155, 627, 155, 120},
    {572, 627, 155, 120},
    {292, 753, 133, 145},
    {463, 753, 133, 145}
};

void init_options(opt_t *options)
{
    int nb = 8;
    int i = 0;
    sfFloatRect rect;
    char const *hover_s = SOUND_FOLDER "hover_button.ogg";
    char const *clicked_s = SOUND_FOLDER "clicked_button.ogg";

    options->pause = create_object(IMG_FOLDER "options.png", NULL);
    options->nb_b = nb;
    options->pause_buttons = malloc(sizeof(invisible_button_t *) * nb);
    for (i = 0; i < nb; i += 1) {
        rect = options_button_rect[i];
        rect.top += sfSprite_getGlobalBounds(options->pause->sprite).top;
        rect.left += sfSprite_getGlobalBounds(options->pause->sprite).left;
        options->pause_buttons[i] = create_button(&rect);
        set_button_sound(options->pause_buttons[i], S_HOVER, hover_s);
        set_button_sound(options->pause_buttons[i], S_CLICKED, clicked_s);
    }
    options->config = load_config();
}

void destroy_options(opt_t *options)
{
    int i = 0;

    destroy_object(options->pause);
    for (i = 0; i < options->nb_b; i += 1)
        destroy_button(options->pause_buttons[i]);
    free(options->pause_buttons);
    free(options->config);
}