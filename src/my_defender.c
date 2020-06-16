/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tower defense in csfml
*/

#include "defend.h"

static const gameloop_t scenes_loop[] = {
    &menu_loop,
    &game_loop,
    &end_menu_loop
};

tool_t init_window(void)
{
    tool_t tools;

    tools.window = create_window(1920, 1080, 32, "my_defender");
    tools.cursor = create_object(IMG_FOLDER "player_cursor.png", NULL);
    init_cursor(tools.cursor);
    init_menu(&tools.menu);
    init_game(&tools.game);
    init_options(&tools.game.option);
    init_end_menu(&tools.end_menu);
    config_all_scenes(&tools);
    return (tools);
}

void destroy_window(tool_t tools)
{
    sfRenderWindow_destroy(tools.window);
    destroy_object(tools.cursor);
    destroy_menu(&tools.menu);
    destroy_game(&tools.game);
    destroy_end_menu(&tools.end_menu);
}

int my_defender(void)
{
    tool_t tools = init_window();
    enum SCENE state = MENU;

    sfRenderWindow_setFramerateLimit(tools.window, 60);
    sfRenderWindow_setMouseCursorVisible(tools.window, sfFalse);
    while (sfRenderWindow_isOpen(tools.window)) {
        state = scenes_loop[state](&tools, state);
        if (state == NO_SCENE)
            sfRenderWindow_close(tools.window);
    }
    destroy_window(tools);
    return (0);
}