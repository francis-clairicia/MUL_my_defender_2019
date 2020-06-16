/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** event.c
*/

#include "defend.h"

static void move_tower_event(tower_panel_t *panel, level_t *level)
{
    sfVector2f tower_pos = sfSprite_getPosition(panel->selected_tower->sprite);
    list_t *empty_places = get_tower_bases(level->grid, level->towers);
    sfIntRect base = init_rect(0, 0, level->grid.size.x, level->grid.size.y);
    list_t *node = NULL;
    sfVector2i *pos = NULL;

    level->grid.highlighted_base = (sfVector2i){-1, -1};
    for (node = empty_places; node != NULL; node = node->next) {
        pos = (sfVector2i *)(node->data);
        base.left = level->grid.pos[pos->y][pos->x].x;
        base.top = level->grid.pos[pos->y][pos->x].y;
        if (sfIntRect_contains(&base, tower_pos.x, tower_pos.y))
            level->grid.highlighted_base = *pos;
    }
    my_free_list(&empty_places, 1);
}

static void drop_tower_event(tower_panel_t *panel, level_t *level)
{
    sfVector2i grid_pos = level->grid.highlighted_base;
    sfVector2f pos;
    tower_t *tower = NULL;

    level->grid.highlighted_base = (sfVector2i){-1, -1};
    if (grid_pos.x >= 0 && grid_pos.y >= 0) {
        pos = level->grid.pos[grid_pos.y][grid_pos.x];
        pos.x += level->grid.size.x / 2;
        pos.y += level->grid.size.y / 2;
        tower = create_tower(panel->selected_type, pos, level->grid.size);
        tower->grid_pos = grid_pos;
        my_append_to_list(&level->towers, (long)tower);
        level->money->amount -= panel->costs[panel->selected_type];
    }
}

void game_event(tool_t *tools, sfEvent event)
{
    level_t *level = tools->game.levels[tools->game.actual_lvl];
    int panel_event = 0;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyF12)
            level->show_grid = !(level->show_grid);
        if (event.key.code == sfKeySpace)
            level->show_tower_area = !(level->show_tower_area);
    }
    panel_event = event_tower_panel(&tools->game.panel, level->money, event);
    if (panel_event == MOVE_EVENT)
        move_tower_event(&tools->game.panel, level);
    else if (panel_event == DROP_EVENT)
        drop_tower_event(&tools->game.panel, level);
}