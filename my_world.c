/*
** EPITECH PROJECT, 2024
** My_New_Hunter
** File description:
** south_park_hunter.c
*/

#include "my.h"
#include "my_world.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>

static void draw_window(sfRenderWindow *window, sfSprite *sprite,
    sfSprite *create_play, sfSprite *create_quit)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, create_play, NULL);
    sfRenderWindow_drawSprite(window, create_quit, NULL);
    sfRenderWindow_display(window);
}

static void handle_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

static sfSprite *create_sprite(texture_data_t *texture_data)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_data->texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.9, 0.9});
    return sprite;
}

void can_use_clic(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    SFFR bounds_play = sfSprite_getGlobalBounds(create_play(window, 50, 200));
    SFFR bounds_quit = sfSprite_getGlobalBounds(create_quit(window, 50, 700));
    sfVector2f mouse_pos_f = {mouse_pos.x, mouse_pos.y};

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&bounds_play, mouse_pos_f.x, mouse_pos_f.y)) {
            sfRenderWindow_close(window);
            do_menu_window_2();
        }
        if (sfFloatRect_contains(&bounds_quit, mouse_pos_f.x, mouse_pos_f.y)) {
            sfRenderWindow_close(window);
        }
    }
}

int do_menu_window(void)
{
    sfVideoMode window_mode = {1900, 1080, 32};
    texture_data_t texture_data;
    sfRenderWindow *window =
            sfRenderWindow_create
            (window_mode, "My_World", sfResize | sfClose, NULL);
    sfEvent event;
    sfSprite *sprite;

    texture_data.texture = SFTCF("src/params/background.jpg", NULL);
    sprite = create_sprite(&texture_data);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &event);
        DW(window, sprite, create_play
        (window, 50, 200), create_quit(window, 50, 700));
        can_use_clic(window, event);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture_data.texture);
    sfRenderWindow_destroy(window);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        help_radar();
        return 0;
    }
    do_menu_window();
    return 0;
}
