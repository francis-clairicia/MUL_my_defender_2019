/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_slimes.c
*/

#include "level.h"

static void init_hp_bar(sfRectangleShape *hp_bar[])
{
    hp_bar[0] = sfRectangleShape_create();
    hp_bar[1] = sfRectangleShape_create();
    hp_bar[2] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(hp_bar[0], sfBlack);
    sfRectangleShape_setFillColor(hp_bar[1], sfGreen);
    sfRectangleShape_setFillColor(hp_bar[2], sfTransparent);
    sfRectangleShape_setOutlineColor(hp_bar[2], sfColor_fromRGB(128, 128, 128));
    sfRectangleShape_setOutlineThickness(hp_bar[2], 3);
}

static void setup_hp_bar(slime_t *slime, sfRectangleShape *hp_bar[])
{
    int hp = slime->hp;
    int max_hp = slime->stats.max_hp;
    sfFloatRect rect = sfSprite_getGlobalBounds(slime->object->sprite);
    sfVector2f max_hp_size = {rect.width, 5};
    sfVector2f hp_size = {max_hp_size.x * hp / max_hp, max_hp_size.y};
    sfVector2f pos = {rect.left, rect.top - max_hp_size.y - 5};

    sfRectangleShape_setSize(hp_bar[0], max_hp_size);
    sfRectangleShape_setSize(hp_bar[1], hp_size);
    sfRectangleShape_setSize(hp_bar[2], max_hp_size);
    sfRectangleShape_setPosition(hp_bar[0], pos);
    sfRectangleShape_setPosition(hp_bar[1], pos);
    sfRectangleShape_setPosition(hp_bar[2], pos);
}

void draw_slimes(list_t *start, sfRenderWindow *window)
{
    list_t *actual = start;
    slime_t *slime = NULL;
    sfRectangleShape *hp_bar[3];
    int i = 0;

    init_hp_bar(hp_bar);
    while (actual != NULL) {
        slime = (slime_t *)actual->data;
        setup_hp_bar(slime, hp_bar);
        draw_object(slime->object, window);
        for (i = 0; i < 3; i += 1)
            sfRenderWindow_drawRectangleShape(window, hp_bar[i], NULL);
        actual = actual->next;
    }
    for (i = 0; i < 3; i += 1)
        sfRectangleShape_destroy(hp_bar[i]);
}