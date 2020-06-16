/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** money.c
*/

#include "level.h"
#include "my.h"

money_t *init_money_struct(char const *money_bar_filepath)
{
    money_t *money = malloc(sizeof(*money));
    sfVector2f origin;

    if (money == NULL)
        return (NULL);
    money->amount = 0;
    money->bar = create_object(money_bar_filepath, NULL);
    if (money->bar == NULL) {
        free(money);
        return (NULL);
    }
    origin.x = money->bar->area.width;
    origin.y = 0;
    sfSprite_setOrigin(money->bar->sprite, origin);
    return (money);
}

void destroy_money_struct(money_t *money)
{
    if (money == NULL)
        return;
    destroy_object(money->bar);
    free(money);
}