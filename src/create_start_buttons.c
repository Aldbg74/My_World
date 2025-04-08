/*
** EPITECH PROJECT, 2025
** G-ING-200-LYN-2-1-myworld-alexis.drago-beltran
** File description:
** create_start_buttons
*/

#include "my.h"
#include "my_world.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

sfSprite *create_play(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/Start.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_quit(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/quit.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_quit_ip(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/quit.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_up(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/up.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}

sfSprite *create_down(sfRenderWindow *window, float x, float y)
{
    sfTexture *texture =
            sfTexture_createFromFile("src/params/down.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    return sprite;
}
