/*
** EPITECH PROJECT, 2020
** init_text
** File description:
** initialization of sfText
*/

#include "include/struct.h"

void change_text_color(sfText *text, sfColor color)
{
    sfText_setColor(text, color);
}

text_t init_text(char *message, char *font_path, sfVector2f pos, int size)
{
    text_t text_struct;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_path);

    sfText_setString(text, message);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    text_struct.object = text;
    text_struct.font = font;
    return (text_struct);
}

void destroy_text(text_t text)
{
    sfText_destroy(text.object);
    sfFont_destroy(text.font);
}