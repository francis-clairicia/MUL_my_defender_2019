/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_money.c
*/

#include "defend.h"
#include "my.h"

static void draw_amount(money_t *money, sfRenderWindow *window)
{
    char *amount = my_nbr_to_str(money->amount);
    text_t text_amount;
    sfFloatRect bar_area = sfSprite_getGlobalBounds(money->bar->sprite);
    sfVector2f pos;

    pos.x = bar_area.left + (bar_area.width * 2 / 5);
    pos.y = bar_area.top + (bar_area.height * 11 / 24);
    text_amount = init_text(amount, FONT_FOLDER "afterglow.ttf", pos, 25);
    set_text_origin_to_middle(text_amount, sfFalse, sfTrue);
    change_text_color(text_amount.object, sfYellow);
    draw_text(window, text_amount);
    destroy_text(text_amount);
    free(amount);
}

void draw_money_amount(money_t *money, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f bar_pos = init_vector2f(window_size.x, 0);

    if (money == NULL)
        return;
    sfSprite_setPosition(money->bar->sprite, bar_pos);
    draw_object(money->bar, window);
    draw_amount(money, window);
}