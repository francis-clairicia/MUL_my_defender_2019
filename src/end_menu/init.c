/*
** EPITECH PROJECT, 2020
** init_end_menu
** File description:
** create_end_menu.c
*/

#include "defend.h"

static void set_button_positions(image_button_t **buttons)
{
    sfVector2f replay = init_vector2f(1300, 200);
    sfVector2f menu = init_vector2f(200, 800);
    sfVector2f quit = init_vector2f(1300, 800);

    set_pos_img_button(buttons[0], replay);
    set_pos_img_button(buttons[1], menu);
    set_pos_img_button(buttons[2], quit);
}

static void create_text(menu_t *end)
{
    sfFloatRect replay = sfSprite_getGlobalBounds(end->buttons[0]->
        object->sprite);
    sfFloatRect menu = sfSprite_getGlobalBounds(end->buttons[1]->
        object->sprite);
    sfFloatRect quit = sfSprite_getGlobalBounds(end->buttons[2]->
        object->sprite);
    sfVector2f replay_txt = init_vector2f(replay.left + replay.width / 2,
        replay.top + replay.height / 2);
    sfVector2f menu_txt = init_vector2f(menu.left + menu.width / 2,
        menu.top + menu.height / 2);
    sfVector2f quit_txt = init_vector2f(quit.left + quit.width / 2,
        quit.top + quit.height / 2);

    end->txt[0] = init_text("Play again", FONT_FOLDER "afterglow.ttf",
        replay_txt, 40);
    end->txt[1] = init_text("Menu", FONT_FOLDER "afterglow.ttf", menu_txt, 40);
    end->txt[2] = init_text("QUIT", FONT_FOLDER "afterglow.ttf", quit_txt, 40);
    set_text_origin_to_middle(end->txt[0], 1, 1);
    set_text_origin_to_middle(end->txt[1], 1, 1);
    set_text_origin_to_middle(end->txt[2], 1, 1);
}

static image_button_t *init_end_button(char const *filepath)
{
    sfIntRect def = {0, 0, 251, 64};
    sfIntRect hover = {0, 0, 251, 64};
    sfIntRect active = {0, 0, 251, 64};
    image_button_t *button = create_img_button(filepath, def);
    char const *hover_s = SOUND_FOLDER "hover_button.ogg";
    char const *clicked_s = SOUND_FOLDER "clicked_button.ogg";

    button->rect[BUTTON_HOVER] = hover;
    button->rect[BUTTON_ACTIVE] = active;
    set_button_sound(button->invisible, S_HOVER, hover_s);
    set_button_sound(button->invisible, S_CLICKED, clicked_s);
    return (button);
}

void init_end_menu(menu_t *end)
{
    end->background = create_object(IMG_FOLDER "game_over_green.png", NULL);
    end->buttons[0] = init_end_button(IMG_FOLDER "btn_green.png");
    end->buttons[1] = init_end_button(IMG_FOLDER "btn_green.png");
    end->buttons[2] = init_end_button(IMG_FOLDER "btn_green.png");
    end->nb_buttons = sizeof(end->buttons) / sizeof(end->buttons[0]);
    set_button_positions(end->buttons);
    create_text(end);
    end->music = sfMusic_createFromFile(SOUND_FOLDER "Select.ogg");
    sfMusic_setLoop(end->music, sfTrue);
}

void destroy_end_menu(menu_t *end)
{
    int i = 0;

    destroy_object(end->background);
    for (i = 0; i < end->nb_buttons; i += 1) {
        destroy_img_button(end->buttons[i]);
        destroy_text(end->txt[i]);
    }
    sfMusic_destroy(end->music);
}