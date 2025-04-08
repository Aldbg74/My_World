/*
** EPITECH PROJECT, 2025
** G-ING-200-LYN-2-1-myworld-alexis.drago-beltran
** File description:
** main_window
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
/*
resources_t *resources_create(void)
{
    resources_t *resources = (resources_t *)malloc(sizeof(resources_t));
    sfTexture *backgroundTexture = SFTCF("src/params/background2.jpg", NULL);
    sfTexture *sprite1Texture = SFTCF("src/params/up.png", NULL);
    sfTexture *sprite2Texture = SFTCF("src/params/down.png", NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfSprite *backgroundSprite = sfSprite_create();
    sfSprite *sprite1 = sfSprite_create();
    sfSprite_setPosition(sprite1, (sfVector2f){30, 50});
    sfSprite_setPosition(sprite2, (sfVector2f){30, 200});
    sfSprite_setTexture(sprite1, sprite1Texture, sfTrue);
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    resources->sprites = NULL;
    resources->spriteCount = 0;
    sfSprite_setTexture(sprite2, sprite2Texture, sfTrue);
    resources->sprites = (sfSprite **)malloc(3 * sizeof(sfSprite *));
    resources->sprites[0] = backgroundSprite;
    resources->sprites[1] = sprite1;
    resources->sprites[2] = sprite2;
    resources->spriteCount = 3;
    return resources;
}*/

sfSprite *create_sprite(sfVector2f position, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

resources_t *resources_create(void)
{
    resources_t *resources = malloc(sizeof(resources_t));
    sfTexture *backgroundTexture = SFTCF("src/params/background2.jpg", NULL);
    sfTexture *sprite1Texture = SFTCF("src/params/up.png", NULL);
    sfTexture *sprite2Texture = SFTCF("src/params/down.png", NULL);

    resources->sprites = malloc(3 * sizeof(sfSprite *));
    resources->sprites[BG_SPRITE] =
            create_sprite((sfVector2f){0, 0}, backgroundTexture);
    resources->sprites[SPRITE_UP] =
            create_sprite((sfVector2f){30, 50}, sprite1Texture);
    resources->sprites[SPRITE_DOWN] =
            create_sprite((sfVector2f){30, 200}, sprite2Texture);
    resources->spriteCount = 3;
    return resources;
}

void resources_destroy(resources_t *resources)
{
    for (size_t i = 0; i < resources->spriteCount; i++) {
        SFTD((sfTexture *)SFFGT(resources->sprites[i]));
        sfSprite_destroy(resources->sprites[i]);
    }
    free(resources->sprites);
    free(resources);
}

context_t *context_create(void)
{
    context_t *ctx = (context_t *)malloc(sizeof(context_t));
    sfVideoMode window_mode = {1900, 1080, 32};

    ctx->window = SFRWC(window_mode, "My_World", sfResize | sfClose, NULL);
    ctx->clock = sfClock_create();
    ctx->resources = resources_create();
    return ctx;
}

static void context_destroy(context_t *ctx)
{
    if (ctx == NULL)
        return;
    sfRenderWindow_destroy(ctx->window);
    sfClock_destroy(ctx->clock);
    resources_destroy(ctx->resources);
    free(ctx);
}

static void draw_window_2(context_t *ctx)
{
    MapData_t data;

    init_3d_map(&data);
    create_2d_map(&data);
    for (size_t i = 0; i < ctx->resources->spriteCount; i++) {
        SFRWDS(ctx->window, ctx->resources->sprites[i], NULL);
    }
    draw_2d_map(ctx->window, &data);
    sfRenderWindow_display(ctx->window);
}

static void handle_events_2(context_t *ctx, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(ctx->window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(ctx->window);
    }
}

static void can_use_clic_main(context_t *ctx, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            input_left();
        }
        if (event.mouseButton.button == sfMouseRight) {
            input_right(ctx, event);
        }
        if (event.mouseButton.button == sfMouseMiddle) {
            input_middle(ctx, event);
        }
    }
}

int do_menu_window_2(void)
{
    context_t *ctx = context_create();
    sfEvent event;
    sfTime elapsed;
    float delta_time;

    if (ctx == NULL)
        return 84;
    while (sfRenderWindow_isOpen(ctx->window)) {
        elapsed = sfClock_restart(ctx->clock);
        delta_time = sfTime_asSeconds(elapsed);
        handle_events_2(ctx, &event);
        draw_window_2(ctx);
    }
    context_destroy(ctx);
    return 0;
}
