/*
** EPITECH PROJECT, 2020
** loop
** File description:
** loop of the end menu
*/

#include "defend.h"

static int check_event(tool_t *tools, int state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (is_button_img_clicked(tools->end_menu.buttons[QUIT_BUTTON], event)
        || event.type == sfEvtClosed)
            return (NO_SCENE);
        if (is_button_img_clicked(tools->end_menu.buttons[PLAY_BUTTON], event))
            return (GAME);
        if (is_button_img_clicked(tools->end_menu.buttons[HELP_BUTTON], event))
            return (MENU);
    }
    return (state);
}

static void draw_screen(tool_t *tools)
{
    int i = 0;

    draw_object(tools->end_menu.background, tools->window);
    for (i = 0; i < tools->end_menu.nb_buttons; i += 1) {
        draw_img_button(tools->end_menu.buttons[i], tools->window);
        draw_text(tools->window, tools->end_menu.txt[i]);
    }
    draw_object(tools->cursor, tools->window);
}

int end_menu_loop(tool_t *tools, int state)
{
    sfMusic_play(tools->end_menu.music);
    while (state == GAME_OVER) {
        sfRenderWindow_clear(tools->window, init_color(50, 50, 50, 255));
        cursor_move(tools);
        draw_screen(tools);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state);
    }
    sfMusic_stop(tools->end_menu.music);
    return (state);
}