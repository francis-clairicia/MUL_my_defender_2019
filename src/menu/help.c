/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** help.c
*/

#include "defend.h"

static sfRectangleShape *create_frame(int width, int height)
{
    sfRectangleShape *frame = sfRectangleShape_create();

    sfRectangleShape_setSize(frame, (sfVector2f){width, height});
    sfRectangleShape_setOrigin(frame, (sfVector2f){width / 2, height / 2});
    sfRectangleShape_setFillColor(frame, sfColor_fromRGB(33, 170, 217));
    sfRectangleShape_setOutlineThickness(frame, 4);
    sfRectangleShape_setOutlineColor(frame, sfBlack);
    return (frame);
}

static int check_event(tool_t *tools, int state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(tools->window);
            return (NO_SCENE);
        }
        if (is_button_img_clicked(tools->menu.buttons[QUIT_BUTTON], event))
            return (MENU);
    }
    return (state);
}

static void draw_screen(tool_t *tools, sfRectangleShape *frame, text_t text)
{
    draw_object(tools->menu.background, tools->window);
    sfRenderWindow_drawRectangleShape(tools->window, frame, NULL);
    sfRenderWindow_drawText(tools->window, text.object, NULL);
    draw_img_button(tools->menu.buttons[QUIT_BUTTON], tools->window);
    draw_object(tools->cursor, tools->window);
}

int help_loop(tool_t *tools, int state)
{
    sfRectangleShape *frame = create_frame(960, 540);
    sfVector2f pos = {960, 540};
    char *message = "Coming soon";
    text_t text = init_text(message, FONT_FOLDER "afterglow.ttf", pos, 100);

    sfRectangleShape_setPosition(frame, (sfVector2f){960, 540});
    set_text_origin_to_middle(text, sfTrue, sfTrue);
    while (state == HELP) {
        sfRenderWindow_clear(tools->window, sfBlack);
        cursor_move(tools);
        draw_screen(tools, frame, text);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state);
    }
    sfRectangleShape_destroy(frame);
    destroy_text(text);
    return (state);
}