/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-myls-alexis.drago-beltran
** File description:
** my_strdup.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}

/*
char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    my_putstr(str);
    return str;
}
*/
