/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** event_tower_panel.c
*/

#include "level.h"

static void on_tower_select(obj_t *tower, sfMouseButtonEvent event)
{
    sfFloatRect rect;
    sfVector2f origin;
    sfVector2f pos = init_vector2f(event.x, event.y);

    rect = sfSprite_getLocalBounds(tower->sprite);
    origin = init_vector2f(rect.width / 2, rect.height / 2);
    sfSprite_setOrigin(tower->sprite, origin);
    sfSprite_setPosition(tower->sprite, pos);
    sfSprite_setColor(tower->sprite, init_color(255, 255, 255, 120));
}

static int select_tower(tower_panel_t *panel, money_t *money,
    sfMouseButtonEvent event)
{
    obj_t *tower = NULL;
    sfFloatRect panel_tower_rect;
    int i = 0;

    for (i = 0; i < panel->nb_towers; i += 1) {
        tower = panel->towers[i];
        panel_tower_rect = sfSprite_getGlobalBounds(tower->sprite);
        if (!sfFloatRect_contains(&panel_tower_rect, event.x, event.y))
            continue;
        if (panel->costs[i] <= money->amount) {
            tower = create_object(tower->filepath, NULL);
            on_tower_select(tower, event);
            panel->selected_tower = tower;
            panel->selected_type = i;
        }
    }
    return (NO_EVENT);
}

static int drop_tower(tower_panel_t *panel)
{
    if (panel->selected_tower != NULL) {
        destroy_object(panel->selected_tower);
        panel->selected_tower = NULL;
    }
    return (DROP_EVENT);
}

static int move_tower(tower_panel_t *panel, sfMouseMoveEvent event)
{
    sfVector2f mouse_pos = {event.x, event.y};

    if (panel->selected_tower == NULL)
        return (NO_EVENT);
    sfSprite_setPosition(panel->selected_tower->sprite, mouse_pos);
    return (MOVE_EVENT);
}

int event_tower_panel(tower_panel_t *panel, money_t *money, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (select_tower(panel, money, event.mouseButton));
    if (event.type == sfEvtMouseMoved)
        return (move_tower(panel, event.mouseMove));
    if (event.type == sfEvtMouseButtonReleased)
        return (drop_tower(panel));
    return (NO_EVENT);
}