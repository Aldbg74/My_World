/*
** EPITECH PROJECT, 2024
** bsmy_world
** File description:
** textures.c
*/

#include "my_world.h"

void destroy_textures(sfTexture **textures)
{
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(textures[i]);
    free(textures);
}

sfTexture *chose_texture(MapData_t *data, int i, int j)
{
    sfTexture *texture;

    if (data->d_map[i][j] == 0)
        texture = sfTexture_createFromFile("src/params/blue.png", NULL);
    if (data->d_map[i][j] == 1)
        texture = sfTexture_createFromFile("src/params/green.png", NULL);
    if (data->d_map[i][j] == 2)
        texture = sfTexture_createFromFile("src/params/grey.jpg", NULL);
    if (data->d_map[i][j] == 3)
        texture = sfTexture_createFromFile("src/params/white.png", NULL);
    return texture;
}
