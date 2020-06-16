/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_tower_panel.c
*/

#include "defend.h"
#include "my.h"

static void set_origin_to_midleft(obj_t *obj)
{
    sfFloatRect local_rect = sfSprite_getLocalBounds(obj->sprite);
    sfVector2f origin = {0, local_rect.height / 2};

    sfSprite_setOrigin(obj->sprite, origin);
}


static void draw_tower(obj_t *tower, int cost, sfRenderWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(tower->sprite);
    sfVector2f pos = {rect.left + rect.width / 2, rect.top + rect.height + 5};
    char *str_cost = my_nbr_to_str(cost);
    text_t text = init_text(str_cost, FONT_FOLDER "afterglow.ttf", pos, 30);
    obj_t *gold = create_object(IMG_FOLDER "goldCoin1.png", NULL);
    sfFloatRect text_rect = sfText_getGlobalBounds(text.object);

    pos.x = text_rect.left + text_rect.width / 2;
    pos.y = text_rect.top + text_rect.height / 2;
    set_obj_height(gold, text_rect.height * 2);
    set_origin_to_midleft(gold);
    sfSprite_setPosition(gold->sprite, pos);
    set_text_origin_to_middle(text, sfTrue, sfFalse);
    change_text_color(text.object, sfYellow);
    draw_object(tower, window);
    draw_text(window, text);
    draw_object(gold, window);
    destroy_text(text);
    destroy_object(gold);
    free(str_cost);
}

void draw_tower_panel(tower_panel_t panel, sfRenderWindow *window)
{
    int i = 0;

    sfRenderWindow_drawRectangleShape(window, panel.dashboard, NULL);
    for (i = 0; i < panel.nb_towers; i += 1)
        draw_tower(panel.towers[i], panel.costs[i], window);
    if (panel.selected_tower != NULL)
        draw_object(panel.selected_tower, window);
}