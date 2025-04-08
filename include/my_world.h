/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-alexis.drago-beltran
** File description:
** my_hunter.h
*/

#ifndef MY_WORLD_
    #define MY_WORLD_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <stdlib.h>
    #define SFTCF sfTexture_createFromFile
    #define SFRWC sfRenderWindow_create
    #define DW draw_window
    #define SFFR sfFloatRect
    #define SFTD sfTexture_destroy
    #define SFFGT sfSprite_getTexture
    #define SFRWDS sfRenderWindow_drawSprite
    #define SSSP sfSprite_setPosition
    #define MAP_X 6
    #define MAP_Y 6
    #define PI 3.14159265358979323846
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define MAP_SIZE 20
    #define TILE_SIZE 30

typedef struct window {
    sfVideoMode mode;
    sfWindow *window;
} window_mode_t;

typedef struct texture {
    sfTexture* texture;
    sfSprite* sprite;
} texture_data_t;

typedef struct {
    sfText *start;
    sfText *exit;
    sfFont *font;
} menu_t;

typedef struct resources_s {
    sfSprite **sprites;
    size_t spriteCount;
} resources_t;

typedef struct context_s {
    sfRenderWindow* window;
    sfClock* clock;
    resources_t *resources;
} context_t;

typedef enum {
    BG_SPRITE = 0,
    SPRITE_UP,
    SPRITE_DOWN
} slist_t;

typedef struct {
    sfVector2f **map;
    int **d_map;
} MapData_t;

int help_radar(void);
sfMusic *play_music(void);
sfSprite *create_play(sfRenderWindow *window, float x, float y);
sfSprite *create_quit(sfRenderWindow *window, float x, float y);
int do_menu_window_2(void);
sfSprite *create_quit_ip(sfRenderWindow *window, float x, float y);
sfSprite *create_up(sfRenderWindow *window, float x, float y);
sfSprite *create_down(sfRenderWindow *window, float x, float y);
void draw_map(sfRenderWindow *window);
void init_3d_map(MapData_t *data);
void create_2d_map(MapData_t *data);
void draw_2d_map(sfRenderWindow *window, MapData_t *data);
void destroy_textures(sfTexture **textures);
sfTexture **create_textures(void);
sfVertexArray *create_tile(sfVector2f *points);
sfVector2f project_iso_point(int x, int y, int z);
sfTexture *chose_texture(MapData_t *data, int i, int j);
int input_left(void);
int input_middle(context_t *ctx, sfEvent event);
int input_right(context_t *ctx, sfEvent event);

#endif
