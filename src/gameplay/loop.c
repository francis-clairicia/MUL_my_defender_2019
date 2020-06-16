/*
** EPITECH PROJECT, 2020
** loop
** File description:
** loop for the game
*/

#include "defend.h"

static const pause_function_t pause_functions[] = {
    &music_volume_down,
    &music_volume_up,
    &sound_volume_down,
    &sound_volume_up,
    &quit_window,
    &return_to_menu,
    &save_changes,
    &cancel_changes
};

static int change_state(tool_t *tools, int state)
{
    level_t *level = tools->game.levels[tools->game.actual_lvl];

    if (state == PAUSE) {
        cancel_changes(tools);
        sfClock_restart(level->new_mob);
    }
    return ((state == PAUSE) ? GAME : PAUSE);
}

static void menu_pause(tool_t *tools, sfEvent event, int *state)
{
    opt_t *options = &tools->game.option;
    int index = 0;

    while (index < options->nb_b) {
        if (is_button_clicked(options->pause_buttons[index], event))
            *state = pause_functions[index](tools);
        index += 1;
    }
}

static int check_event(tool_t *tools, int state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (event.type == sfEvtClosed)
            return (NO_SCENE);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (change_state(tools, state));
        if (state == PAUSE)
            menu_pause(tools, event, &state);
        else
            game_event(tools, event);
    }
    return (state);
}

static void draw_screen(tool_t *tools, int state)
{
    draw_level(tools->game.levels[tools->game.actual_lvl], tools->window);
    draw_tower_panel(tools->game.panel, tools->window);
    if (state == PAUSE)
        draw_options(tools);
    draw_object(tools->cursor, tools->window);
}

int game_loop(tool_t *tools, int state)
{
    start_game(tools);
    while (state == GAME || state == PAUSE) {
        sfRenderWindow_clear(tools->window, sfBlack);
        cursor_move(tools);
        if (state == GAME)
            state = game_actions(&tools->game);
        draw_screen(tools, state);
        sfRenderWindow_display(tools->window);
        if (state == GAME || state == PAUSE)
            state = check_event(tools, state);
    }
    end_game(tools);
    return (state);
}