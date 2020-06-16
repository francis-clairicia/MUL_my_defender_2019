/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_event.c
*/

#include "include/struct.h"
#include <stdio.h>

int is_button_img_clicked(image_button_t *button, sfEvent event)
{
    return (is_button_clicked(button->invisible, event));
}