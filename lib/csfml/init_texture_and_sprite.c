/*
** EPITECH PROJECT, 2020
** init_tecture_and_sprite
** File description:
** initialization of sprite
*/

#include "include/struct.h"

static char *my_strdup(char const *str)
{
    char *new_str = NULL;
    int str_len = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (str_len = 0; str[str_len] != '\0'; str_len += 1);
    new_str = malloc(sizeof(char) * (str_len + 1));
    if (new_str != NULL) {
        for (i = 0; i <= str_len; i += 1)
            new_str[i] = str[i];
    }
    return (new_str);
}

obj_t *create_object(char const *filepath, sfIntRect *default_area)
{
    obj_t *obj = malloc(sizeof(*obj));

    if (obj == NULL)
        return (NULL);
    obj->texture = sfTexture_createFromFile(filepath, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->area = sfSprite_getTextureRect(obj->sprite);
    if (default_area != NULL)
        set_object_area(obj, *default_area);
    obj->clock = NULL;
    obj->size = (sfVector2f){0, 0};
    obj->speed = 0;
    obj->filepath = my_strdup(filepath);
    return (obj);
}

void destroy_object(obj_t *obj)
{
    if (obj == NULL)
        return;
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    if (obj->clock != NULL)
        sfClock_destroy(obj->clock);
    if (obj->filepath != NULL)
        free(obj->filepath);
    free(obj);
}

void set_object_area(obj_t *obj, sfIntRect area)
{
    sfSprite_setTextureRect(obj->sprite, area);
    obj->area = area;
}

void draw_object(obj_t *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}