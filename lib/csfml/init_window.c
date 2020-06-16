/*
** EPITECH PROJECT, 2020
** init_window
** File description:
** initialization windows
*/

#include "include/struct.h"

sfRenderWindow *create_window(int width, int height, int bits, char *title)
{
    sfVideoMode video = {width, height, bits};

    return (sfRenderWindow_create(video, title, sfDefaultStyle, NULL));
}