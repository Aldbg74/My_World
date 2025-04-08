/*
** EPITECH PROJECT, 2025
** G-ING-200-LYN-2-1-myworld-alexis.drago-beltran
** File description:
** mouse_imput
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

// Mouse imput is not in use in the final project //

void rotate_view(context_t *ctx, sfVector2i currentMousePosition)
{
    sfBool RightButtonPressed = sfFalse;
    sfVector2i initialMousePosition;
    float deltaX = (float)(currentMousePosition.x - initialMousePosition.x);
    sfView *view = (sfView *)sfRenderWindow_getView(ctx->window);

    sfView_rotate(view, deltaX * 0.1f);
    sfRenderWindow_setView(ctx->window, view);
    initialMousePosition = currentMousePosition;
}

int input_right(context_t *ctx, sfEvent event)
{
    sfBool RightButtonPressed = sfFalse;
    sfVector2i initialMousePosition;
    sfVector2i currentMousePosition =
            sfMouse_getPositionRenderWindow(ctx->window);

    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseRight) {
        RightButtonPressed = sfTrue;
        initialMousePosition = sfMouse_getPositionRenderWindow(ctx->window);
    } else if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseRight) {
        RightButtonPressed = sfFalse;
    }
    if (RightButtonPressed &&
    event.type == sfEvtMouseMoved) {
        rotate_view(ctx, currentMousePosition);
    }
    return 0;
}

int input_left(void)
{
    return 0;
}

void move_xy(context_t *ctx, sfVector2i currentMousePosition)
{
    sfView *view = (sfView *)sfRenderWindow_getView(ctx->window);
    static sfVector2i initialMousePosition;
    sfVector2f viewCenter = sfView_getCenter(view);
    float deltaX = (float)(currentMousePosition.x - initialMousePosition.x);
    float deltaY = (float)(currentMousePosition.y - initialMousePosition.y);
    sfVector2f newCenter = {viewCenter.x - deltaX, viewCenter.y - deltaY};

    sfView_setCenter(view, newCenter);
    sfRenderWindow_setView(ctx->window, view);
    initialMousePosition = currentMousePosition;
}

int input_middle(context_t *ctx, sfEvent event)
{
    static sfBool MiddleButtonPressed = sfFalse;
    static sfVector2i initialMousePosition;
    sfVector2i currentMousePosition =
            sfMouse_getPositionRenderWindow(ctx->window);

    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseMiddle) {
        MiddleButtonPressed = sfTrue;
        initialMousePosition =
                sfMouse_getPositionRenderWindow(ctx->window);
    } else if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseMiddle) {
        MiddleButtonPressed = sfFalse;
    }
    if (MiddleButtonPressed && event.type == sfEvtMouseMoved) {
        rotate_view(ctx, currentMousePosition);
    }
    return 0;
}
