/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** tower.h
*/

#ifndef HEADER_TOWER_STRUCT
#define HEADER_TOWER_STRUCT

#include "struct.h"
#include "mylist.h"

enum TOWER_TYPE
{
    BASIC_TOWER,
    ICE_TOWER,
    FIRE_TOWER,
    SNIPER_TOWER
};

enum PANEL_EVENT
{
    NO_EVENT,
    MOVE_EVENT,
    DROP_EVENT
};

struct tower_stats
{
    char const *filename;
    float radius;
    int damage;
    float shot_time;
};

typedef struct projectile
{
    sfCircleShape *bullet;
    sfVector2f direction;
    sfClock *clock;
    float speed;
} projectile_t;

typedef struct tower
{
    obj_t *object;
    sfVector2i grid_pos;
    sfCircleShape *area;
    enum TOWER_TYPE type;
    int damage;
    sfClock *clock;
    float shot_time;
    list_t *projectiles;
    void (*attack_enemy)(struct tower *, list_t *);
    void (*draw)(struct tower *, sfRenderWindow *);
    void *special;
} tower_t;

typedef struct fire_tower
{
    sfClock *propagation_clock;
    sfTexture *attack_texture;
    sfCircleShape *attack_area;
    sfBool attacking;
    list_t *slimes_on_area;
} fire_tower_t;

typedef struct ice_tower
{
    float slow_factor;
} ice_tower_t;

typedef struct sniper_tower
{
    sfClock *waiting_clock;
    sfBool attacking;
    list_t *aims;
    list_t *aimed_slimes;
} sniper_tower_t;

typedef struct tower_panel
{
    sfRectangleShape *dashboard;
    obj_t *towers[4];
    int costs[4];
    obj_t *selected_tower;
    int selected_type;
    int nb_towers;
} tower_panel_t;

typedef void (*special_tower_creation_t)(tower_t *);
typedef void (*special_tower_destroyer_t)(void *);

tower_panel_t init_tower_panel(void);
void destroy_tower_panel(tower_panel_t panel);
void draw_tower_panel(tower_panel_t panel, sfRenderWindow *window);

projectile_t *create_projectile(float radius, float speed,
    sfVector2f direction, sfVector2f pos);
void destroy_projectile(projectile_t *projectile);
void draw_projectiles(list_t *projectiles, sfRenderWindow *window);
void move_projectiles(list_t *projectiles);

tower_t *create_tower(enum TOWER_TYPE type, sfVector2f pos, sfVector2f size);
void destroy_tower(tower_t *tower);
void draw_towers(list_t *towers, sfRenderWindow *window, sfBool show_area);
void event_towers(list_t *towers, list_t *slimes);
void check_slime_collision(tower_t *tower, list_t *slimes);

void draw_tower_default(tower_t *tower, sfRenderWindow *window);
void attack_tower_default(tower_t *tower, list_t *slimes);

void create_fire_tower(tower_t *tower);
void destroy_fire_tower(void *ptr);
void attack_fire_tower(tower_t *tower, list_t *slimes);

void create_ice_tower(tower_t *tower);
void destroy_ice_tower(void *ptr);
void attack_ice_tower(tower_t *tower, list_t *slimes);

void create_sniper_tower(tower_t *tower);
void destroy_sniper_tower(void *ptr);
void destroy_sniper_fields(sniper_tower_t *tower);
void attack_sniper_tower(tower_t *tower, list_t *slimes);

#endif