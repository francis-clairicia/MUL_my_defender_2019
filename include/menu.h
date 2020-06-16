/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu.h
*/

#ifndef DEFEND_MENU_H_
#define DEFEND_MENU_H_

#include "struct.h"

typedef struct menu
{
    obj_t *background;
    image_button_t *buttons[3];
    text_t txt[3];
    int nb_buttons;
    sfMusic *music;
} menu_t;

enum MENU_BUTTONS
{
    PLAY_BUTTON,
    HELP_BUTTON,
    QUIT_BUTTON
};

void init_menu(menu_t *menu);
void init_end_menu(menu_t *end);
void destroy_menu(menu_t *menu);
void destroy_end_menu(menu_t *end);

#endif