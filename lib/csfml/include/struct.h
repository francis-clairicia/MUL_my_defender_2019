/*
** EPITECH PROJECT, 2019
** prototypes of csfml library
** File description:
** proto
*/

#ifndef HEADER_CSFML_H_
#define HEADER_CSFML_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio/Music.h>
#include <stdlib.h>
#include <time.h>

typedef struct text_s {
    sfText *object;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct button_s {
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfRectangleShape *rect;
    text_t text;
} button_t;

typedef struct game_object_s {
    char *filepath;
    sfIntRect area;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f size;
    float speed;
} obj_t;

typedef struct invisible_button
{
    sfMusic *sounds[2];
    sfFloatRect rect;
    int state;
} invisible_button_t;

typedef struct image_button
{
    obj_t *object;
    invisible_button_t *invisible;
    sfIntRect rect[3];
} image_button_t;

enum BUTTON_STATE
{
    BUTTON_NORMAL,
    BUTTON_HOVER,
    BUTTON_ACTIVE,
};

enum SOUND_STATE
{
    S_HOVER,
    S_CLICKED
};

/* init_window.c */
sfRenderWindow *create_window(int width, int height, int bits, char *title);

/* init_texture_and_sprite */
obj_t *create_object(char const *filepath, sfIntRect *default_area);
void destroy_object(obj_t *obj);
void set_object_area(obj_t *obj, sfIntRect area);
void draw_object(obj_t *obj, sfRenderWindow *window);

/* scale_object.c */
void set_obj_width(obj_t *obj, int width);
void set_obj_height(obj_t *obj, int height);
void set_obj_size(obj_t *obj, int width, int height);

/* button.c */
int is_button_is_clicked(float x, float y, sfVector2f pos, sfVector2f size);
sfRectangleShape *init_rect_shape(sfVector2f pos, sfVector2f size,
    sfColor col);
void init_button(button_t *button);

/* invisible_button */
invisible_button_t *create_button(sfFloatRect *rect);
void destroy_button(invisible_button_t *button);
void set_button_sound(invisible_button_t *button,
    enum SOUND_STATE sound_state, char const *sound_path);
void set_pos_img_button(image_button_t *button, sfVector2f pos);
void move_img_button(image_button_t *button, sfVector2f offset);
int is_button_clicked(invisible_button_t *button, sfEvent event);

/* img_button */
image_button_t *create_img_button(char const *filepath, sfIntRect default_rect);
void destroy_img_button(image_button_t *button);
void draw_img_button(image_button_t *button, sfRenderWindow *window);
int is_button_img_clicked(image_button_t *button, sfEvent event);

/* init_text */
void change_text_color(sfText *text, sfColor color);
text_t init_text(char *message, char *font_path, sfVector2f pos, int size);
void destroy_text(text_t text);
void draw_text(sfRenderWindow *window, text_t text);

/* init_objects.c */
sfVector2f init_vector2f(int x, int y);
sfIntRect init_rect(int left, int top, int widht, int height);
sfColor init_color(int red, int green, int blue, int alpha);

/* usefull_function.c */
void increment_pos(float *pos, float offset, int max_value, int reset);
void decrement_pos(float *pos, float offset, int max_value, int reset);
int random_value(int modulo);

/* clock.c */

int elapsed_time(float milliseconds, sfClock *clock);

#endif /* !PROTO_H_ */
