/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** invisible_button_event.c
*/

#include "include/struct.h"

static int mouse_on_button(invisible_button_t *button, float x, float y)
{
    int min_x = button->rect.left;
    int max_x = button->rect.left + button->rect.width;
    int min_y = button->rect.top;
    int max_y = button->rect.top + button->rect.height;

    return ((x > min_x && x < max_x) && (y > min_y && y < max_y));
}

static int click_down(invisible_button_t *button, sfMouseButtonEvent event)
{
    if (event.button != sfMouseLeft)
        return (0);
    if (mouse_on_button(button, event.x, event.y)) {
        if (button->state == BUTTON_HOVER)
            button->state = BUTTON_ACTIVE;
    }
    return (0);
}

static int click_up(invisible_button_t *button, sfMouseButtonEvent event)
{
    int state = 0;

    if (event.button != sfMouseLeft)
        return (0);
    if (mouse_on_button(button, event.x, event.y)) {
        if (button->state == BUTTON_ACTIVE) {
            button->state = BUTTON_HOVER;
            state = 1;
        }
    } else {
        button->state = BUTTON_NORMAL;
    }
    if (state == 1 && button->sounds[S_CLICKED] != NULL) {
        sfMusic_setPlayingOffset(button->sounds[S_CLICKED], (sfTime){0});
        sfMusic_play(button->sounds[S_CLICKED]);
    }
    return (state);
}

static int move(invisible_button_t *button, sfMouseMoveEvent event)
{
    int former_state = button->state;

    if (mouse_on_button(button, event.x, event.y)) {
        if (button->state == BUTTON_NORMAL)
            button->state = BUTTON_HOVER;
    } else {
        button->state = BUTTON_NORMAL;
    }
    if (button->state == BUTTON_HOVER && former_state == BUTTON_NORMAL
    && button->sounds[S_HOVER] != NULL) {
        sfMusic_setPlayingOffset(button->sounds[S_HOVER], (sfTime){0});
        sfMusic_play(button->sounds[S_HOVER]);
    }
    return (0);
}

int is_button_clicked(invisible_button_t *button, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (click_down(button, event.mouseButton));
    if (event.type == sfEvtMouseButtonReleased)
        return (click_up(button, event.mouseButton));
    if (event.type == sfEvtMouseMoved)
        return (move(button, event.mouseMove));
    return (0);
}