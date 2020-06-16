/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button.c
*/

#include "include/struct.h"

image_button_t *create_img_button(char const *filepath, sfIntRect default_rect)
{
    image_button_t *button = malloc(sizeof(image_button_t));
    sfFloatRect button_rect;

    if (button == NULL)
        return (NULL);
    button->object = create_object(filepath, &default_rect);
    button_rect = sfSprite_getGlobalBounds(button->object->sprite);
    button->invisible = create_button(&button_rect);
    button->rect[BUTTON_NORMAL] = default_rect;
    button->rect[BUTTON_HOVER] = default_rect;
    button->rect[BUTTON_ACTIVE] = default_rect;
    return (button);
}

void destroy_img_button(image_button_t *button)
{
    int i = 0;

    if (button == NULL)
        return;
    destroy_object(button->object);
    destroy_button(button->invisible);
    free(button);
}
