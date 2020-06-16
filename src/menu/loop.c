/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** loop.c
*/

#include "defend.h"

static int check_event(tool_t *tools, int state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (is_button_img_clicked(tools->menu.buttons[QUIT_BUTTON], event)
        || event.type == sfEvtClosed)
            return (NO_SCENE);
        if (is_button_img_clicked(tools->menu.buttons[PLAY_BUTTON], event))
            return (GAME);
        if (is_button_img_clicked(tools->menu.buttons[HELP_BUTTON], event))
            return (help_loop(tools, HELP));
    }
    return (state);
}

static void draw_screen(tool_t *tools)
{
    int i = 0;

    draw_object(tools->menu.background, tools->window);
    for (i = 0; i < tools->menu.nb_buttons; i += 1)
        draw_img_button(tools->menu.buttons[i], tools->window);
    draw_object(tools->cursor, tools->window);
}

int menu_loop(tool_t *tools, int state)
{
    sfMusic_play(tools->menu.music);
    while (state == MENU) {
        sfRenderWindow_clear(tools->window, sfBlack);
        cursor_move(tools);
        draw_screen(tools);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state);
    }
    sfMusic_stop(tools->menu.music);
    return (state);
}