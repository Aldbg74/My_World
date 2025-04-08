/*
** EPITECH PROJECT, 2024
** bsmy_world
** File description:
** map.c
*/

#include "my_world.h"

void draw_2d_map(sfRenderWindow *window, MapData_t *data)
{
    sfVertexArray *quad;
    sfVector2f points[4];
    sfRenderStates states = sfRenderStates_default();

    for (int i = 0; i < MAP_SIZE - 1; i++) {
        for (int j = 0; j < MAP_SIZE - 1; j++) {
            states.texture = chose_texture(data, i, j);
            points[0] = data->map[i][j];
            points[1] = data->map[i][j + 1];
            points[2] = data->map[i + 1][j + 1];
            points[3] = data->map[i + 1][j];
            quad = create_tile(points);
            sfRenderWindow_drawVertexArray(window, quad, &states);
            sfVertexArray_destroy(quad);
        }
    }
}

void create_2d_map(MapData_t *data)
{
    data->map = malloc(sizeof(sfVector2f *) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++) {
        data->map[i] = malloc(sizeof(sfVector2f) * MAP_SIZE);
        for (int j = 0; j < MAP_SIZE; j++) {
            data->map[i][j] = project_iso_point(j * TILE_SIZE, i * TILE_SIZE,
                data->d_map[i][j] * 10);
            data->map[i][j].x += WINDOW_WIDTH / 2;
            data->map[i][j].y += WINDOW_HEIGHT / 4;
        }
    }
}

void init_3d_map(MapData_t *data)
{
    srand(time(NULL));
    data->d_map = malloc(sizeof(int *) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++) {
        data->d_map[i] = malloc(sizeof(int) * MAP_SIZE);
        for (int j = 0; j < MAP_SIZE; j++)
            data->d_map[i][j] = rand() % 4;
    }
}

sfVertexArray *create_tile(sfVector2f *points)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex vertices[4] = {
        {.position = points[0], .color = sfWhite, .texCoords = {0, 0}},
        {.position = points[1], .color = sfWhite, .texCoords = {TILE_SIZE, 0}},
        {.position = points[2], .color = sfWhite, .texCoords =
            {TILE_SIZE, TILE_SIZE}},
        {.position = points[3], .color = sfWhite, .texCoords = {0, TILE_SIZE}}
    };

    for (int i = 0; i < 4; i++)
        sfVertexArray_append(quad, vertices[i]);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return quad;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f d_point;
    float angle = 30 * PI / 180;

    d_point.x = (x - y) * cos(angle);
    d_point.y = (x + y) * sin(angle) - z;
    return d_point;
}
