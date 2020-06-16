/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init.c
*/

#include "defend.h"

static void set_positions(menu_t *menu)
{
    int i = 0;
    int x = 831;
    int y = 300;
    int height = 0;
    int offset = 50;

    for (i = 0; i < menu->nb_buttons; i += 1) {
        set_pos_img_button(menu->buttons[i], init_vector2f(x, y));
        height = menu->buttons[i]->invisible->rect.height;
        y += height + offset;
    }
}

static image_button_t *init_menu_button(char const *filepath)
{
    sfIntRect def = {0, 0, 258, 128};
    sfIntRect hover = {259, 0, 258, 128};
    sfIntRect active = {518, 0, 258, 128};
    image_button_t *button = create_img_button(filepath, def);
    char const *hover_s = SOUND_FOLDER "hover_button.ogg";
    char const *clicked_s = SOUND_FOLDER "clicked_button.ogg";

    button->rect[BUTTON_HOVER] = hover;
    button->rect[BUTTON_ACTIVE] = active;
    set_button_sound(button->invisible, S_HOVER, hover_s);
    set_button_sound(button->invisible, S_CLICKED, clicked_s);
    return (button);
}

void init_menu(menu_t *menu)
{
    menu->background = create_object(IMG_FOLDER "menu.png", NULL);
    menu->buttons[PLAY_BUTTON] = init_menu_button(IMG_FOLDER "play_b.png");
    menu->buttons[HELP_BUTTON] = init_menu_button(IMG_FOLDER "help_b.png");
    menu->buttons[QUIT_BUTTON] = init_menu_button(IMG_FOLDER "quit_b.png");
    menu->nb_buttons = sizeof(menu->buttons) / sizeof(menu->buttons[0]);
    set_positions(menu);
    menu->music = sfMusic_createFromFile(SOUND_FOLDER "Menu_music.ogg");
    sfMusic_setLoop(menu->music, sfTrue);
}

void destroy_menu(menu_t *menu)
{
    int i = 0;

    destroy_object(menu->background);
    for (i = 0; i < menu->nb_buttons; i += 1)
        destroy_img_button(menu->buttons[i]);
    sfMusic_destroy(menu->music);
}