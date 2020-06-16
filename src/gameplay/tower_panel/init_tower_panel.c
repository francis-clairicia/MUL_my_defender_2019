/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_tower_panel.c
*/

#include "defend.h"

static void set_origin_to_midleft(obj_t *tower)
{
    sfFloatRect local_rect = sfSprite_getLocalBounds(tower->sprite);
    sfVector2f origin = {0, local_rect.height / 2};

    sfSprite_setOrigin(tower->sprite, origin);
}

static void setup_towers(sfRectangleShape *shape, obj_t **towers, int nb_tower)
{
    sfFloatRect frame = sfRectangleShape_getGlobalBounds(shape);
    int offset = 30;
    int x = frame.left + (offset / 2);
    int centery = frame.top + frame.height / 2;
    int i = 0;

    for (i = 0; i < nb_tower; i += 1) {
        set_obj_width(towers[i], (frame.width / nb_tower) - offset);
        set_origin_to_midleft(towers[i]);
        sfSprite_setPosition(towers[i]->sprite, init_vector2f(x, centery));
        x += sfSprite_getGlobalBounds(towers[i]->sprite).width;
        x += offset;
    }
}

static void setup_dashboard(sfRectangleShape *dashboard)
{
    sfVector2f panel_size = init_vector2f(600, 300);

    sfRectangleShape_setSize(dashboard, panel_size);
    sfRectangleShape_setOrigin(dashboard, panel_size);
    sfRectangleShape_setPosition(dashboard, init_vector2f(1900, 1020));
    sfRectangleShape_setFillColor(dashboard, sfColor_fromRGB(33, 170, 217));
    sfRectangleShape_setOutlineThickness(dashboard, 4);
    sfRectangleShape_setOutlineColor(dashboard, sfBlack);
}

static void set_costs(int *costs)
{
    costs[BASIC_TOWER] = 200;
    costs[ICE_TOWER] = 400;
    costs[FIRE_TOWER] = 600;
    costs[SNIPER_TOWER] = 800;
}

tower_panel_t init_tower_panel(void)
{
    tower_panel_t panel;
    obj_t *basic = create_object(IMG_FOLDER "basic_turret.png", NULL);
    obj_t *fire = create_object(IMG_FOLDER "fire_turret.png", NULL);
    obj_t *ice = create_object(IMG_FOLDER "ice_turret.png", NULL);
    obj_t *sniper = create_object(IMG_FOLDER "sniper_turret.png", NULL);

    panel.dashboard = sfRectangleShape_create();
    setup_dashboard(panel.dashboard);
    panel.towers[BASIC_TOWER] = basic;
    panel.towers[FIRE_TOWER] = fire;
    panel.towers[ICE_TOWER] = ice;
    panel.towers[SNIPER_TOWER] = sniper;
    panel.nb_towers = sizeof(panel.towers) / sizeof(panel.towers[0]);
    setup_towers(panel.dashboard, panel.towers, panel.nb_towers);
    set_costs(panel.costs);
    panel.selected_tower = NULL;
    panel.selected_type = -1;
    return (panel);
}