/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** invisible_button.c
*/

#include "include/struct.h"

invisible_button_t *create_button(sfFloatRect *rect)
{
    invisible_button_t *button = malloc(sizeof(*button));

    if (button == NULL)
        return (NULL);
    button->sounds[S_HOVER] = NULL;
    button->sounds[S_CLICKED] = NULL;
    if (rect != NULL)
        button->rect = *rect;
    else
        button->rect = (sfFloatRect){0, 0, 0, 0};
    button->state = BUTTON_NORMAL;
    return (button);
}

void destroy_button(invisible_button_t *button)
{
    int i = 0;

    if (button == NULL)
        return;
    for (i = 0; i < 2; i += 1) {
        if (button->sounds[i] != NULL)
            sfMusic_destroy(button->sounds[i]);
    }
    free(button);
}

void set_button_sound(invisible_button_t *button,
    enum SOUND_STATE sound_state, char const *sound_path)
{
    if (button != NULL)
        button->sounds[sound_state] = sfMusic_createFromFile(sound_path);
}